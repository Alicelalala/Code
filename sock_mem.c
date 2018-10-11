/*************************************************************************
	> File Name: socket_1.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月23日 星期日 16时43分25秒
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

#define MAX_SIZE 2000
#define FILE_SIZE 500
#define MAX_FILE 512
/*
int socket_create(char *host, char *port) {
    int sock_client;
    struct sockaddr_in dest_addr;
    if ((sock_client = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Socket");
            return -1;
            
    }
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(port);
        dest_addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sock_client, (struct sockaddr * ) & dest_addr, sizeof(dest_addr))) {
            perror("Connect");
            return -1;
            
    }
    return sock_client;
}
*/
int main(int argc, char *argv[]) {
    int sock_client, sockfd;
    char buffer[MAX_SIZE];
    struct sockaddr_in dest_addr;
    int port = atoi(argv[2]);
    int port2 = atoi(argv[2] + 1);
    char *host = argv[1];
    
    if ((sock_client = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket");
        return -1;
    }
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sock_client, (struct sockaddr * ) & dest_addr, sizeof(dest_addr))) {
        perror("Connect");
        return -1;
    }
    
    while (1) {
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Socket");
            return -1;    
        }
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(port2);
        dest_addr.sin_addr.s_addr = inet_addr(host);
        for (int i = 0; i < 3; i++) {
        if (connect(sockfd, (struct sockaddr *) &dest_addr, sizeof(dest_addr))) {
            perror("Connect");
            return -1;
        }
            FILE *fp;
            char str[5];
            switch(i) {
                case 0:
                fp = popen("~/shell/cpu.sh", "r");
                strcpy(str, "100");
                break;
                case 1:
                fp = popen("~/shell/memtwo.sh", "r");
                strcpy(str, "101");
                break;
                case 2:
                fp = popen("~/shell/disk.sh", "r");
                strcpy(str, "102");
                break;
                default :
                printf("Error");
                break;
            }
            send(sockfd, str, strlen(str), 0);
            while (!feof(fp)) {
                fread(buffer, 5, 1, fp);
                send(sockfd, buffer, strlen(buffer), 0);
                memset(buffer, 0, sizeof(buffer));
            }
            fclose(fp);
            close(sockfd);
        }
    }

    close(sock_client);
    return 0;
}
