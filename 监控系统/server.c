/*************************************************************************
	> File Name: server.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月25日 星期二 12时00分31秒
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

#define SERVPORT 9999
#define BACKLOG 10
#define MAXDATASIZE 1000

int main() {
    struct sockaddr_in server_sockaddr, client_sockaddr;
    int sin_size, recvbytes;
    int sockfd, client_fd;
    char buf[MAXDATASIZE];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket");
        exit(1);
    }

    printf("Socket success!, sockfd = %d\n", sockfd);

    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(SERVPORT);
    server_sockaddr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_sockaddr.sin_zero), 8);

    if ((bind(sockfd, (struct sockaddr *) & server_sockaddr, sizeof(struct sockaddr))) == -1) {
        perror("bind");
        exit(1);
    }

    printf("bind success!\n");

    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("listening ...\n");

    if ((client_fd = accept(sockfd, (struct sockaddr *) & client_sockaddr, &sin_size)) == -1) {
        perror("accept");
        exit(1);
    }

    printf("accept success!\n");
    while (1) {
        if ((recvbytes = recv(client_fd, buf, MAXDATASIZE, 0)) == -1) {
            perror("recv");
            exit(1);
        }
        //send(client_fd, buf, recvbytes, 0);
        printf("received a connection : %s\n", buf);
        memset(buf, 0, sizeof(buf));
    }
    close(sockfd);
    return 0;
}
