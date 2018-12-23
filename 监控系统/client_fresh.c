/*************************************************************************
	> File Name: client.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月20日 星期二 11时14分34秒
 ************************************************************************/

#include "head.h"
#include "common.c"
#define INS 6
#define PATH_N 50
#define MAX_P 10
#define MAX_N 1024

static pthread_mutex_t mutex[INS + 1];
static pthread_mutex_t alt_mut;

struct mypara {   //每个线程的信息
    char *s;
    int num;
};

void init_pthread () {
    for (int i = 0; i < INS; i++) {
        mutex[i] = PTHREAD_MUTEX_INITIALIZER;
    }
    alt_mut = PTHREAD_MUTEX_INITIALIZER;
    return ;
}

int get_filename (int bit, char *filename, const char *tail) {
    int stime;
    switch (bit) {
        case 100: {
            sprintf(filename, "/home/caohaiyan/shell/cpu%s", tail); 
            stime = 5;
        } break;
        case 101: {
            sprintf(filename, "/home/caohaiyan/shell/mem%s", tail);
            stime = 5;
        } break;
        case 102: {
            sprintf(filename, "/home/caohaiyan/shell/disk%s", tail);
            stime = 60;
        } break;
        case 103: {
            sprintf(filename, "/home/caohaiyan/shell/sysinfo%s", tail);
            stime = 60;
        } break;
        case 104: {
            sprintf(filename, "/home/caohaiyan/shell/user%s", tail);
            stime = 60;
        } break;
        case 105: {
            sprintf(filename, "/home/caohaiyan/shell/proc%s", tail);
            stime = 30;
        } break;
        default : {
            printf("bit error\n");
            return -1;
        }
    }
    return stime;
}

void *alt_func (void *argv) {
    char *host = (char *)malloc(sizeof(char) * PATH_N);
    char *alt_port = (char *)malloc(sizeof(char) * PATH_N);
    get_conf_value("./piheadlthd.conf", "master", host);
    get_conf_value("./piheadlthd.conf", "alt_port", alt_port);
    int port = atoi(alt_port);
    int sockfd;
    char filename[PATH_N], command[PATH_N];
    strcpy(filename, "/home/caohaiyan/shell/warning.log");
    strcpy(command, "bash ~/shell/alter.sh");
    char *buffer = (char *)malloc(sizeof(char) * MAX_N);
    while (1) {
        FILE *fp = popen(command, "r");
        pclose(fp);
        FILE *fr = fopen(filename, "r");
        if (fr == NULL) {
            sleep(5);
            continue;
        }
        fclose(fr);
        sockfd = connect_socket(port, host);
        if (sockfd < 0) {
            printf("connect!!\n");
            close(sockfd);
            exit(0);
        }
        FILE *fd = fopen(filename, "r");
        while (!feof(fd)) {
            fread(buffer, 4, 1, fd);
            printf("%s", buffer);
            send(sockfd, buffer, strlen(buffer), 0);
            memset(buffer, 0, sizeof(buffer));
        }
        fclose(fd);
        if (remove(filename) != 0) {
            perror("remove error\n");
        }
        close(sockfd);
    }
    return NULL;
}

void *func (void *argv) {
    struct mypara *para;
    para = (struct mypara *) argv;
    int stime;
    char *filename = (char *)malloc(sizeof(char) * PATH_N);
    stime = get_filename(para->num + 100, filename, ".sh");
    char *command = (char *)malloc(sizeof(char) * PATH_N);
    sprintf(command, "bash %s", filename);
    char *buffer = (char *)malloc(sizeof(char) * MAX_N);
    while (1) {
        pthread_mutex_lock(&mutex[para->num]);
        FILE *fp = popen(command, "r");
        pclose(fp);
        pthread_mutex_unlock(&mutex[para->num]);
        sleep(stime);
    }
    free(filename);
    return NULL;
}

void *heart_func (void *argv) {
    struct mypara *addr;
    addr = (struct mypara *) argv;
    int sockfd;
    while (1) {
        sockfd = connect_socket(addr->num, addr->s);
        if (sockfd < 0) {
            //perror("connect error");
            break;
            //close(sockfd);
            //exit(0);
        }
        close(sockfd);
        sleep(20);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t t[INS + 1];
    pthread_t alt_t;
    pthread_t heart_t;
    struct mypara para[INS + 1];
    struct mypara heart_para;
    init_pthread();
    if (pthread_create(&alt_t, NULL, alt_func, NULL) == -1) {
        printf("error\n");
        exit(1);
    }
    int port = atoi(argv[2]);
    char *host = argv[1];
    heart_para.s = host;
    heart_para.num = port;
    if (pthread_create(&heart_t, NULL, heart_func, (void *)&heart_para) == -1) {
        printf("error\n");
        exit(1);
    }
    int sockfd, sock_listen;
    //sockfd = connect_socket(port, host);
    //if (sockfd < 0) {
    //    perror("connect error");
    //    close(sockfd);
    //    exit(0);
    //}
    //close(sockfd);
    char initstr[PATH_N];
    sprintf(initstr, "Hello World!");
    for (int i = 0; i < INS; i++) {
        para[i].s = initstr;
        para[i].num = i;
        if (pthread_create(&t[i], NULL, func, (void *)&para[i]) == -1) {
            printf("error\n");
            exit(1);
        }
    }
    char *client_long_port = (char *)malloc(sizeof(char) * MAX_P);
    get_conf_value("./piheadlthd.conf", "client_long_port", client_long_port);
    port = atoi(client_long_port);
    sock_listen = bind_socket(port);
    if (sock_listen < 0) exit(0);
    
    int sock_data_listen, sockfd_data;
    char *client_data_port = (char *)malloc(sizeof(char) * MAX_P);
    get_conf_value("./piheadlthd.conf", "client_data_port", client_data_port);
    port = atoi(client_data_port);
    sock_data_listen = bind_socket(port);
    if (sock_data_listen < 0) exit(0);
    
    while (1) {
        struct sockaddr_in master_addr;
        socklen_t len = sizeof(master_addr);
        if ((sockfd = accept(sock_listen, (struct sockaddr *)&master_addr, &len)) < 0) {
            perror("accept() error!\n");
            break;
        }
        char *filename = (char *)malloc(sizeof(char) * PATH_N);
        int a, bit, req;
        while ((a = recv(sockfd, &bit, 4, 0)) > 0) {
            get_filename(bit, filename, ".log");
            pthread_mutex_lock(&mutex[bit - 100]);
            FILE *fp = fopen(filename, "r");
            if (fp == NULL) {
                printf("%s can not read\n", filename);
                pthread_mutex_unlock(&mutex[bit - 100]);
                bit = 404;
                send(sockfd, &bit, 4, 0);
                continue;
            }
            fclose(fp);
            fp = NULL;
            send(sockfd, &bit, 4, 0);
            printf("send %d open %s\n", bit, filename);
            if ((sockfd_data = accept(sock_data_listen, (struct sockaddr *)&master_addr, &len)) < 0) {
                perror("accept() error!\n");
                break;
            }
            char *buffer = (char *)malloc(sizeof(char) * MAX_N);
            char *command = (char *)malloc(sizeof(char) * MAX_N);
            sprintf(command, "cat %s", filename);
            FILE *fr = popen(command, "r");
            while (!feof(fr)) {
                fread(buffer, 4, 1, fr);
                //printf("%s", buffer);
                int len = send(sockfd_data, buffer, strlen(buffer), 0);
                if (len == -1) {
                    perror("send error\n");
                    exit(1);
                }
                memset(buffer, 0, sizeof(buffer));
            }
            pclose(fr);
            if (remove(filename) != 0) {
                perror("remove error\n");
            }
            memset(filename, 0, sizeof(filename));
            memset(command, 0, sizeof(command));
            pthread_mutex_unlock(&mutex[bit - 100]);
            close(sockfd_data);
        }
        close(sockfd);
    }
    close(sock_data_listen);
    close(sock_listen);
    pthread_join(alt_t, NULL);
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    pthread_join(t[2], NULL);
    return 0;
}

