/*************************************************************************
	> File Name: master_fresh.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月19日 星期三 14时22分12秒
 ************************************************************************/

#include "head.h"
#include "master.h"
#include "common.c"

#define INS 5
#define PATH_N 50
#define MAX_N 1024
#define MAX_P 10


typedef struct Node {
    char *ip; 
    struct Node *next;
} Node, *LinkedList;

struct mypara {
    const char *s;
    int num;
};

//全局变量
int queue[INS + 1] = {0}; //初始化队列
LinkedList linkedlist[INS + 1];
static pthread_mutex_t mutex[INS + 1];
static pthread_mutex_t alt_mut;
Node insert(LinkedList head, Node *node, int index);
void output(LinkedList head, int num);

void init_pthread () {
    for (int i = 0; i < INS; i++) {
        mutex[i] = PTHREAD_MUTEX_INITIALIZER;
    }
    alt_mut = PTHREAD_MUTEX_INITIALIZER;
    return ;
}

Node *init_node (char *ip) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ip = (char *)malloc(sizeof(char) * PATH_N);
    strcpy(p->ip, ip);
    p->next = NULL;
    return p;
}

void init_linkedlist () {
    char *prename = (char *)malloc(sizeof(char) * PATH_N);
    char *ip = (char *)malloc(sizeof(char) * PATH_N);
    get_conf_value("./piheadlthd.conf", "prename", prename);
    for (int i = 50; i <= 55; i++) {
        sprintf(ip, "%s.%d", prename, i);
        printf("%s\n", ip);
        int min = min_queue();
        Node *p, ret;
        p = init_node(ip);
        ret = insert(linkedlist[min], p, queue[min]);
        queue[min]++;
        linkedlist[min] = ret.next;
        output(linkedlist[min], min);
        memset(ip, 0, sizeof(ip));
    }
    free(ip);
    free(prename);
    return ;
}

Node insert (LinkedList head, Node *node, int index) {
    Node *p, ret;
    p = &ret;
    ret.next = head;
    while (p->next && index) {
        p = p->next;
        index--;
    }
    if (index == 0) {
        node->next = p->next;
        p->next = node;
    }
    return ret;
}

Node *delete_node (LinkedList head, int index) {
    if (head == NULL) return head;
    Node *current_node = head;
    int count = 0;
    if (index == 0) {
        head = head->next;
        free(current_node);
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

void clear (LinkedList head) {
    Node *p, *q;
    p = head;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    return ;
}

void output (LinkedList head, int num) {
    Node *p = head;
    char logfile[PATH_N];
    sprintf(logfile, "./queue.log/%d.log", num);
    FILE *fp = fopen(logfile, "w");
    //printf("output\n");
    while (p) {
        printf("output %s\n", p->ip);
        fprintf(fp, "%s", p->ip);
        if (p->next) {
            fprintf(fp, "%s", " ");
        }
        p = p->next;
    }
    fclose(fp);
    return ;
}

int min_queue () {
    int *min = queue;
    int ans = 0;
    for (int i = 0; i < INS; i++) {
        if (*(queue + i) < *min) {
            min = queue + i;
            ans = i;
        }
    }
    return ans;
}

int check_weight (char *ip) {
    for (int i = 0; i < INS; i++) {
        Node *p = linkedlist[i];
        while (p) {
            if (strcmp(p->ip, ip) == 0) return 1;
            p = p->next;
        }
    }
    return 0;
}

int get_filename (int bit, char *ipLogName, char *filename) {
    switch (bit) {
        case 100: {
            sprintf(filename, "%s/cpu.log", ipLogName);
        }break;
        case 101: {
            sprintf(filename, "%s/mem.log", ipLogName);
        }break;
        case 102: {
            sprintf(filename, "%s/disk.log", ipLogName);
        }break;
        case 103: {
            sprintf(filename, "%s/sysinfo.log", ipLogName);
        }break;
        case 104: {
            sprintf(filename, "%s/user.log", ipLogName);
        }break;
        case 105: {
            sprintf(filename, "%s/proc.log", ipLogName);
        }break;
        default : {
            printf("bit error!\n");
            break;
        }
    }
    return 0;
}

int write_message (char *filename, char *ip) {
    int sockfd_data;
    char *client_data_port = (char *)malloc(sizeof(char) * MAX_P);
    get_conf_value("./piheadlthd.conf", "client_data_port", client_data_port);
    int port = atoi(client_data_port);

    sockfd_data = connect_socket(port, ip);
    if (sockfd_data < 0) {
        printf("IP %s data connect error\n", ip);
        close(sockfd_data);
        //exit(1); //exit(0)正常退出,exit(1)错误退出
        return -1;
    }
    char *buffer = (char *)malloc(sizeof(char) * MAX_N);
    FILE *fp = fopen(filename, "a+");
    int a;
    printf("%s\n", filename);
    while ((a = recv(sockfd_data, buffer, MAX_N, 0)) > 0) {
        fwrite(buffer, a, 1, fp);
        //printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    fclose(fp);
    if (a == 0) {
        printf("IP%s closed\n", ip);
    } else if (a < 0) {
        perror("recv error\n");
    }
    close(sockfd_data);
    return 0;
}

char* ip_log_dir (char *ip) {
    char *ip_log_path = (char *)malloc(sizeof(char) * PATH_N);
    sprintf(ip_log_path, "./log/IP%sLog", ip);
    if (access(ip_log_path, 0) == -1) {
        char *command = (char *)malloc(sizeof(char) * PATH_N);
        sprintf(command, "mkdir %s", ip_log_path);
        FILE *fp = popen(command, "r");
        pclose(fp);
        free(command);
    }
    return ip_log_path;
}

void *alt_func (void *argv) {
    int alter_listen, sockfd;
    struct sockaddr_in alter_addr;
    int port = 7999;
    alter_listen = bind_socket(port);
    while (1) {
        printf("alter_addr\n");
        socklen_t len = sizeof(alter_addr);
        if ((sockfd = accept(alter_listen, (struct sockaddr *)&alter_addr, &len)) < 0) {
            perror("accept error!\n");
            break;
        }
        int a;
        char *buffer = (char *)malloc(sizeof(char) * MAX_N);
        memset(buffer, 0, sizeof(buffer));
        FILE *fp = fopen("./log/warning.log", "a+");
        while ((a = recv(sockfd, buffer, MAX_N, 0)) > 0) {
            fwrite(buffer, a, 1, fp);
            printf("%s", buffer);
            memset(buffer, 0, sizeof(buffer));
        }
        fclose(fp);
        if (a == 0) {
            printf("IP%s closed\n", inet_ntoa(alter_addr.sin_addr));
        } else if (a < 0) {
            perror("recv error\n");
        }
        close(sockfd);
    }
    close(alter_listen);
    return NULL;
}

void *func (void *argv) {
    struct mypara *para;
    para = (struct mypara *) argv;
    time_t wait = 5;
    //sleep(10);
    while (1) {
        //sleep(5);
        //printf("=====\n");
        if (!queue[para->num]) {
            sleep(wait);
            continue;
        }
        /*
         *master主动连接客户端，如果客户端没有开启，就删除节点，
         *在就处理客户端发来的数据
        */
        int sockfd, port, count = 0;
        char *client_long_port = (char *)malloc(sizeof(char) * MAX_P);
        get_conf_value("./piheadlthd.conf", "client_long_port", client_long_port);
        port = atoi(client_long_port);
        pthread_mutex_lock(&mutex[para->num]);
        Node *p = linkedlist[para->num];
        Node *q = linkedlist[para->num];
        while (q) {
            //sleep(5);
            sockfd = connect_socket(port, q->ip);
            if (sockfd < 0) {
                printf("delete IP %s\n", q->ip);
                q = q->next;
                p = delete_node(p, count);
                queue[para->num]--;
                close(sockfd);
                continue;
            }
            count++;
            printf("connect IP %s\n", q->ip);
            char *ip_log_path = ip_log_dir(q->ip); //该主机文件夹路径
            int bit = 100, req = 100, a;
            send(sockfd, &bit, 4, 0); //发送请求标识符
            while ((a = recv(sockfd, &req, 4, 0)) > 0) {
                printf("%d\n", req);
                if (req == 404) {
                    printf("404 文件无法打开或不存在\n");
                    if (bit == 105) break;
                    bit++;
                    send(sockfd, &bit, 4, 0);
                    continue;
                }
                char *filename = (char *)malloc(sizeof(char) * PATH_N);
                get_filename(bit, ip_log_path, filename);//日志文件
                sleep(5);
                //数据连接，文件传输
                int wrlen = write_message(filename, q->ip);
                free(filename);
                if (wrlen == -1) break;
                if (bit == 105) break;
                bit++;
                send(sockfd, &bit, 4, 0);
            }
            close(sockfd);
            printf("下一个节点\n");
            q = q->next;
        }
        linkedlist[para->num] = p;
        output(linkedlist[para->num], para->num);
        pthread_mutex_unlock(&mutex[para->num]);
    }
    return NULL;
}

int main () {
    pthread_t t[INS + 1];
    pthread_t alt_t;
    struct mypara para[INS + 1];
    init_linkedlist();
    init_pthread();
    
    //master端对于警告信息实时处理的线程
    if (pthread_create(&alt_t, NULL, alt_func, NULL)) {
        perror("pthread_create error\n");
        exit(1);
    }

    //创建5个线程去处理五个队列里的机器（IP）
    for (int i = 0; i < INS; i++) {
        para[i].s = "Hello world!";
        para[i].num = i;
        if (pthread_create(&t[i], NULL, func, (void *)&para[i]) == -1) {
            perror("pthread_create error\n");
            exit(1);
        }
    }
    
    //创建master端监听
    int master_listen, sockfd, port;
    char *heart_port = (char *)malloc(sizeof(char) * PATH_N);
    get_conf_value("./piheadlthd.conf", "client_port", heart_port);
    port = atoi(heart_port);
    free(heart_port);
    master_listen = bind_socket(port);

    while (1) {
        struct sockaddr_in dest_addr;
        socklen_t len = sizeof(dest_addr);
        if ((sockfd = accept(master_listen, (struct sockaddr *)&dest_addr, &len)) < 0 ) {
            perror("accept error!\n");
            exit(0);
        }
        char *ip = inet_ntoa(dest_addr.sin_addr);
        if (check_weight(ip)) continue; //查重
        Node *p = init_node(ip);
        Node ret;
        int min = min_queue();
        pthread_mutex_lock(&mutex[min]);
        ret = insert(linkedlist[min], p, queue[min]);
        output(linkedlist[min], min);
        printf("insert %s\n", ip);
        queue[min]++;
        linkedlist[min] = ret.next;
        pthread_mutex_unlock(&mutex[min]);
        close(sockfd);
    }
    //需要等待子进程结束，否则主线程会先结束，整个进程结束
    pthread_join(alt_t, NULL);
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    pthread_join(t[2], NULL);
    pthread_join(t[3], NULL);
    pthread_join(t[4], NULL);
    for (int i = 0; i < INS; i++)
        output(linkedlist[i], i);
    close(master_listen);
    return 0;
}

