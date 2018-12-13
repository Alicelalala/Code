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

#define SERVPORT 9876
#define BACKLOG 10
#define MAXDATASIZE 1000

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
    int server_listen, sockfd;
    server_listen = create_socket(SERVPORT);

        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        if ((sockfd = accept(server_listen, (struct sockaddr *)&client_addr, &len)) < 0) {
            perror("accept error!\n");
            exit(0);
        }
        printf("accept success\n");
    #define MAX_N 1000
        int a;
        char *buffer = (char *)malloc(sizeof(char) * MAX_N);
        FILE *fp;
        char *filename = (char *)malloc(sizeof(char) * 20);
        int recvbytes;
    while (1) {
        printf("++++\n");
        if ((recvbytes = recv(sockfd, buffer, MAX_N, 0)) == -1) {
            perror("recv");
            exit(1);
        }
        printf("---\n");
            //buffer[3] = '\0';
        printf("%s", buffer);
            if (strcmp(buffer, "100")) {
                sprintf(filename, "%d.cpu.log", 1);
                fp = fopen(filename, "w");
            } else if (strcmp(buffer, "101")) {
                fclose(fp);
                sprintf(filename, "%d.mem.log", 1);
                fp = fopen(filename, "w");
            } else if (strcmp(buffer, "102")) {
                fclose(fp);
                sprintf(filename, "%d.disk.log", 1);
                fp = fopen(filename, "w");
            } else {
                fwrite(buffer, strlen(buffer), 1, fp);
                fflush(stdout);
                memset(buffer, 0, sizeof(buffer));
            }
//        printf("received a connection : %s\n", buf);
//        memset(buf, 0, sizeof(buf));
    }
    fclose(fp);
    close(sockfd);
    close(server_listen);
    return 0;
}
