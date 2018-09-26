/*************************************************************************
	> File Name: server_1.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月26日 星期三 14时36分37秒
 ************************************************************************/

#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/file.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int a = 0;
    int server_listen, sockfd, port, pid;
    if (argc != 2) {
        printf("Usage: ./tcp_server port\n");
        exit(0);
    }

    port = atoi(argv[1]);

    struct sockaddr_in sock_addr;
    struct linger m_sLinger;
    m_sLinger.l_onoff = 1;
    m_sLinger.l_linger = 0;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() error");
        return -1;
    }

    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY); 

    setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (const char *) & m_sLinger, sizeof(struct linger));

    if ((bind(sockfd, (struct sockaddr *) &sock_addr, sizeof(struct sockaddr))) < 0) {
        close(sockfd);
        perror("bind() error\n");
        return -1;
    }

    if (listen(sockfd, 20) < 0) {
        close(sockfd);
        perror("listen() error");
        return -1;
    }

    printf("listening...\n");
    server_listen = sockfd;

    while(1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        if ((sockfd = accept(server_listen, (struct sockaddr *) &client_addr, &len)) < 0) {
            perror("accept");
            break;
        }

        struct sockaddr_in peer;
        socklen_t peer_len = sizeof(struct sockaddr_in);
        bzero(&peer, sizeof(struct sockaddr_in));
        getpeername(sockfd, (struct sockaddr *)&peer, &peer_len);
        char buff_peer[64] = {'\0'};
        inet_ntop(AF_INET, (void*)&peer.sin_addr, buff_peer, 63);
        printf("%s已连接:\n", buff_peer);

        if ((pid = fork()) < 0) {
            printf("Error forking child process");
        }
        if (pid == 0) {
            close(server_listen);
            char buffer[MAX_SIZE];
            while ((a = recv(sockfd, buffer, MAX_SIZE, 0)) > 0) {
                printf("%s", buffer);
                fflush(stdout);
                memset(buffer, 0, sizeof(buffer));
            }
            printf("\n");
            close(sockfd);
            exit(0);
        }
        close(sockfd);
    }
    return 0;
}
