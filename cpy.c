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

int socket_create(int port) {
    int sockfd;
    int yes = 1;
    struct sockaddr_in sock_addr;

    struct linger m_sLinger;
    //m_sLinger.l_onoff = 1;
    //m_sLinger.l_linger = 0;
     
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
    return sockfd;
}

int main(int argc, char *argv[]) {
    int a = 0;
    int server_listen, sockfd, port, pid;
    if (argc != 2) {
        printf("Usage: ./tcp_server port\n");
        exit(0);
    }

    port = atoi(argv[1]);

    if ((server_listen = socket_create(port)) < 0) {
        printf("Error creating server_listen socket");
        exit(1);
    }

    printf("listening...\n");

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
            char *buffer = (char *)malloc(sizeof(char *) MAX_SIZE);
           /* char str[5];
            while ((a = recv(sockfd, buffer, MAX_SIZE, 0)) > 0) {
                if (str[n] == "101") {
                FILE *fw = fopen("cpu.log", "w");
                if (strcmp(buffer, "100") == 0) {
                    printf("%s\n", buffer);
                    memset(buffer, 0, sizeof(buffer));
                    continue;
                }
                    printf("%s", buffer);
                    fwrite(buffer, strlen(buffer), 1, fw);
                    fflush(stdout);
                    memset(buffer, 0, sizeof(buffer));
                    char str[5];
                    strcpy(str, "100");
                    send(sockfd, str, strlen(str), 0);

                fclose(fw);
                }
                close(sockfd);
                exit(0);
            }}*/
            FILE *fw = fopen("cpu.log", "w");
            FILE *fmem = fopen("mem.log", "w");
            FILE *fdisk = fopen("disk.log", "w");
            int flag = -1;
            while ((a = recv(sockfd, buffer, MAX_SIZE, 0)) > 0) {
                if (strcmp(buffer, "100") == 0) {
                    flag = 0;
                    printf("%s\n", buffer);
                    continue;
                }
                if (strcmp(buffer, "101") == 0) {
                    printf("%s\n", buffer);
                    flag = 1;
                    continue;
                }
                if (strcmp(buffer, "102") == 0) {
                    printf("%s\n"), buffer;
                    flag = 2;
                    continue;
                }
                printf("%d\n", flag);
                if (flag == 0) {
                printf("%s", buffer);
                fwrite(buffer, strlen(buffer), 1, fw);
                fflush(stdout);
                memset(buffer, 0, sizeof(buffer));
                char str[3];
                memset(str, 0, sizeof(str));
                strcpy(str, "100");
                send(sockfd, str, strlen(str), 0);
                }
                if (flag== 1) {
                    printf("%s", buffer);
                    fwrite(buffer, strlen(buffer), 1, fmem);
                    fflush(stdout);
                    memset(buffer, 0, sizeof(buffer));
                    fclose(fmem);
                    /*char str[3];
                    memset(str, 0, sizeof(str));
                    strcpy(str, "101");
                    send(sockfd, str, strlen(str), 0);*/
                }
                if (flag == 2) {
                    printf("%s", buffer);
                    fwrite(buffer, strlen(buffer), 1, fdisk);
                    fflush(stdout);
                    memset(buffer, 0, sizeof(buffer));
                    fclose(fdisk);
                }
                /*
            printf("\n");
            char str[3];
            memset(str, 0, sizeof(str));
            strcpy(str, "100");
            send(sockfd, str, strlen(str), 0);
            fclose(fw);
            }*/
            }
            close(sockfd);
            exit(0);
        }
        
        close(sockfd);
    }
    return 0;
}
