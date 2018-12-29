/*************************************************************************
	> File Name: client.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月29日 星期六 11时10分01秒
 ************************************************************************/

#include <stdio.h>
#include "head.h"
#include "common.c"

#define PATH_N 50
#define MAX_N 1024

void *send_func () {
    int sockfd;
    char host[PATH_N];
    get_conf_value("./piheadlthd.conf", "master", host);
    char serPort[PATH_N];
    get_conf_value("./piheadlthd.conf", "sendPort", serPort);
    int port = atoi(serPort);
    while (1) {
        sockfd = connect_socket(port, host);
        if (sockfd < 0) {
            printf("sockfd < 0\n");
            close(sockfd);
            continue;
        }
        char buffer[MAX_N];
        int a;
        while(1){
            scanf("%[^\n]s", buffer);
            if (strlen(buffer) == 0 || strcmp(buffer, "bye") == 0) {
                if (strlen(buffer) == 0) {
                    getchar();
                    break;
                }
                close(sockfd);
                return NULL;
            }
            getchar();
            strcat(buffer, "\n");
            send(sockfd, buffer, strlen(buffer), 0);
            memset(buffer, 0, sizeof(buffer));
        }
        close(sockfd);
    }
    return NULL;
}

int main() {
    pthread_t recv_t;
    if (pthread_create(&recv_t, NULL, send_func, NULL)) {
        perror("pthread_create error");
        exit(0);
    }
    
    int sockfd;
    char host[PATH_N];
    get_conf_value("./piheadlthd.conf", "master", host);
    char serPort[PATH_N];
    get_conf_value("./piheadlthd.conf", "recvPort", serPort);
    int port = atoi(serPort);
    while (1) {
        sockfd = connect_socket(port, host);
        if (sockfd < 0) {
            printf("sockfd < 0\n");
            close(sockfd);
            continue;
        }
        char buffer[MAX_N];
        int a;
        while ((a = recv(sockfd, buffer, MAX_N, 0)) > 0) {
            if (strcmp(buffer, "byebye") == 0) {
                printf("%s\n", buffer);
                close(sockfd);
                return 0;
            }
            printf("%s", buffer);
            memset(buffer, 0, sizeof(buffer));
        }
        close(sockfd);
    }

    pthread_join(recv_t, NULL);
    return 0;
}
