#include "head.h"
#include "get_conf_value.c"
#define INS 5

typedef struct Node {
    struct sockaddr_in addr; // 地址结构体
    struct Node *next;
} Node, *LinkedList;

struct mypara {   //每个线程的信息
    const char *s;
    int num;
};

int queue[INS + 1] = {0}; //初始化队列
LinkedList linkedlist[INS + 5]; 
FILE *log1[INS + 1]; 
int flag[INS + 1] = {1};
static pthread_mutex_t mutex_add = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mutex[INS + 1] = PTHREAD_MUTEX_INITIALIZER;

void *func(void *);  //函数声明
int find_min(int N, int *arr);
Node insert (LinkedList head, Node *node, int index);

Node *init_node (int port, char *IP) {
    struct sockaddr_in init_addr;
    init_addr.sin_family = AF_INET;
    init_addr.sin_port = htons(port);
    init_addr.sin_addr.s_addr = inet_addr(IP);
    Node *p = (Node *)malloc(sizeof(Node));
    p->addr = init_addr;
    p->next = NULL;
    return p;
}

void init () {
    char *buffer = (char *)malloc(sizeof(char) * 20);
    char *port_buf = (char *)malloc(sizeof(char) * 5);
    char *temp = (char *)malloc(sizeof(char) * 20);
    get_conf_value("./piheadlthd.conf", "prename", buffer);
    get_conf_value("./piheadlthd.conf", "client_port", port_buf);
    int port = atoi(port_buf);

    for (int i = 50; i <= 55; i++) {
        sprintf(temp, "%s.%d", buffer, i);
        printf("%s\n", temp);
        //平均分配到队列
	    int min = find_min(INS, queue);
        Node *p, ret;
        p = init_node(port, temp);
        ret = insert(linkedlist[min], p, queue[min]);
        queue[min]++;
        linkedlist[min] = ret.next;
        memset(temp, 0, sizeof(temp));
    }
    free(temp);
    free(buffer);
    free(port_buf);
    return ;
}

Node insert (LinkedList head, Node *node, int index) {
    Node *p, ret;
    p = &ret;
    ret.next = head;
    while (p->next && index) {
        p = p->next;
        --index;
    }
    if (index == 0) {
        node->next = p->next;
        p->next = node;
    }
    return ret;
}

int check_weight (LinkedList head, Node *node) {
    Node *p = head;
    while (p) {
        printf("%s %s\n", inet_ntoa(p->addr.sin_addr), inet_ntoa(node->addr.sin_addr));
        if (p->addr.sin_addr.s_addr == node->addr.sin_addr.s_addr) return 1;
        p = p->next;
    }
    return 0;
}

Node *delete_node (LinkedList head, int index) {
    if (head == NULL) return head;
    Node *current_node = head;
    int count = 0;
    if (index == 0) {
        head = head->next;
        free(current_node);
        //printf("%s\n", inet_ntoa(head->addr.sin_addr));
        return head;
    }
    while (current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1 && current_node->next != NULL) {
        Node *delete_node = current_node->next;
        current_node->next = delete_node->next;
        free(delete_node);
    }
    return head;
}

void output(LinkedList head, int num) {
    Node *p = head;
    char logfile[20];
    sprintf(logfile, "%d.log", num);
    log1[num] = fopen(logfile, "w");
    while (p) {
        printf("%s", inet_ntoa(p->addr.sin_addr));
        fprintf(log1[num], "%s", inet_ntoa(p->addr.sin_addr));
        if (p->next) {
            printf(" ");
            fprintf(log1[num], "%s", " ");
        }
        p = p->next;
    }
    fclose(log1[num]);
    printf("\n");
}

void clear(LinkedList head) {
    Node *p, *q;
    p = head;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    return ;
}

int find_min(int N, int *arr) {
    int *min = arr;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (*(arr + i) < *min) {
            min = arr + i;
            ans = i;
        }
    }
    return ans;
}

int connect_socket (struct sockaddr_in dest_addr) {
    int port = 9999;
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() error!\n");
        return -1;
    }
    dest_addr.sin_port = htons(port);
    int flags;
    if (flags = fcntl(STDIN_FILENO, F_GETFL, 0) < 0) {
        perror("funtl\n");
        return -1;
    }
    flags |= O_NONBLOCK;
    if (fcntl(STDIN_FILENO, F_SETFL, flags) < 0) {
        perror("fcntl\n");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        perror("connect() error\n");
        return -1;
    }
    return sockfd;
}

int create_socket (int port) {
    int sockfd;
    struct sockaddr_in sock_addr;
    struct linger m_sLinger;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() error!\n");
        return -1;
    }

    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (const char *)&m_sLinger, sizeof(struct linger));
    if ((bind(sockfd, (struct sockaddr *)&sock_addr, sizeof(struct sockaddr))) < 0) {
        close(sockfd);
        perror("bind() error!\n");
        return -1;
    }
    if (listen(sockfd, 20) < 0) {
        close(sockfd);
        perror("listen() error!\n");
        return -1;
    }
    printf("listening...\n");
    return sockfd;
}

int main() {
    pthread_t t[INS + 1];
    struct mypara para[INS + 1];
    int temp; 
    init();

    int server_listen,sockfd, port, pid;
    char *client_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "client_port", client_port);
    port = atoi(client_port);
    server_listen = create_socket(port);

    for (int i = 0; i < INS; ++i) {
        para[i].s = "Hello world!";
        para[i].num = i;
        if (pthread_create(&t[i], NULL, func, (void *)&para[i]) == -1) {
            printf("error\n");
            exit(1);
        }
        printf("Current pthread id = %ld \n", t[i]);
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        if ((sockfd = accept(server_listen, (struct sockaddr *)&client_addr, &len)) < 0) {
            perror("accept error!\n");
            break;
        }
        
        
        int flag = 0, min;

        Node *p, ret;
        p = (Node *)malloc(sizeof(Node));
        p->addr = client_addr;
        p->next = NULL;
    
        for (int i = 0; i < INS; i++) {
            if (queue[i] == 0) continue;
            printf("i = %d\n", i);
            if (check_weight(linkedlist[i], p)) {
                flag = 1;
                min = i;
                break;
            }
        }
        
        if (flag == 0) {
            min = find_min(INS, queue);
            pthread_mutex_lock(&mutex[min]);
            ret = insert(linkedlist[min], p, queue[min]);
            printf("insert%d = %d %s\n", min, queue[min], inet_ntoa(p->addr.sin_addr));
            queue[min]++;
            linkedlist[min] = ret.next;      
            pthread_mutex_unlock(&mutex[min]);
        }
        //output(linkedlist[min], min);

     /*   if (pthread_kill(t[min], 0) == ESRCH) {
            para[min].s = "Hello world!";
            para[min].num = min;//用来标识线程
 //           sleep(5);
            
            if (pthread_create(&t[min],NULL, func, (void *)&para[min]) == -1) {
                printf("error\n");
                exit(1);
            }
            //printf("重建线程%d\n", min);
        }*/

        close(sockfd);
    }
    //需要等待子进程结束，否则主线程会先结束，整个进程结束
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    pthread_join(t[2], NULL);
    pthread_join(t[3], NULL);
    pthread_join(t[4], NULL);
    for (int i = 0; i < INS; ++i) {
        printf("%d ", queue[i]);
        printf(" ... ");
        output(linkedlist[i], i);
    }
    printf("\n");
    close(server_listen); 
    return 0;
}

void *func(void *argv) {
    struct mypara *para;
    para = (struct mypara *) argv;
    //printf("%s %d\n", para->s, para->num);
    int sockfd;
    //struct sockaddr_in dest_addr;
    while (1) {
    //if (queue[para->num] == 0) return NULL;
        if (queue[para->num] == 0) {
            sleep(5);
            continue;
        }

    pthread_mutex_lock(&mutex[para->num]);
    int count = 0;
    Node *p = linkedlist[para->num];
    Node *q = linkedlist[para->num];
    printf("queue[%d] = %d q = %s\n", para->num, queue[para->num], inet_ntoa(q->addr.sin_addr));
    while (q) {
        sockfd = connect_socket(q->addr);
        if (sockfd < 0) {
            printf("delete_node queue %d num :%d %s\n", para->num, count, inet_ntoa(q->addr.sin_addr));
            q = q->next;
            p = delete_node(p, count);
            queue[para->num]--;
            close(sockfd);
            continue;
        }
        count++;
        printf("connect%s\n", inet_ntoa(q->addr.sin_addr));
     
        q = q->next;
        close(sockfd);
    }

    linkedlist[para->num] = p;
    output(linkedlist[para->num], para->num);
    pthread_mutex_unlock(&mutex[para->num]);
    }
    return NULL;
}
