/*************************************************************************
	> File Name: server.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月29日 星期六 09时59分31秒
 ************************************************************************/

#include <stdio.h>
#include "head.h"
#include "common.c"

#define MAX_N 1024

void *recv_func () {
    int sockfd, socket_listen, port;
    port = 6789;
    socket_listen = bind_socket(port);
    while (1) {
        struct sockaddr_in destaddr;
        socklen_t len;
        if ((sockfd = accept(socket_listen, (struct sockaddr *)&destaddr, &len)) < 0) {
            perror("accept error");
            exit(0);
        }
        //printf("connect\n");
        char str[MAX_N];
        int a;
        memset(str, 0, sizeof(str));
        while ((a = recv(sockfd, str, MAX_N, 0)) > 0) {
            printf("%s", str);
            memset(str, 0, sizeof(str));
        }
        close(sockfd);
    }
}

int main() {
    pthread_t send_t;
    if (pthread_create(&send_t, NULL, recv_func, NULL)) {
        perror("pthread_create error");
        exit(0);
    }

    int sockfd, socket_listen, port;
    port = 8899;
    socket_listen = bind_socket(port);
    while (1) {
        struct sockaddr_in destaddr;
        socklen_t len;
        if ((sockfd = accept(socket_listen, (struct sockaddr *)&destaddr, &len)) < 0) {
            perror("accept error");
            exit(0);
        }
        //printf("connect\n");
        char str[MAX_N];
        while (1) {
            scanf("%[^\n]s", str);
            if (strlen(str) == 0 || strcmp(str, "byebye") == 0) {
                if (strlen(str)) send(sockfd, str, strlen(str), 0);
                getchar();
                break;
            }
            getchar();
            strcat(str, "\n");
            send(sockfd, str, strlen(str), 0);
            memset(str, 0, sizeof(str));
        }
        close(sockfd);
    }
    pthread_join(send_t, NULL);
    return 0;
}
