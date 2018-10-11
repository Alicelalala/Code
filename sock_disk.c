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
    
    /*
    while (1) {
        char file_name[FILE_SIZE];  
        memset( file_name,0, sizeof(file_name)   );
        printf("Please Input File Name On Server:   "); 
        scanf("%s", file_name);        

        FILE *fp = fopen(file_name, "r");
        memset(buffer, 0, sizeof(buffer));
        while(!feof(fp) ) {
            fread(buffer, 5, 1, fp);
            send(sock_client, buffer, strlen(buffer), 0);
            memset(buffer, 0, sizeof(buffer));
        }

        fclose(fp);
        close(sock_client);
}*/
    while (1) {
        FILE *fdisk = popen("~/shell/disk.sh", "r");
        char buf[MAX_SIZE];
        char str[5];
        strcpy(str, "102");
        send(sock_client, str, strlen(str), 0);
        fgets(buf, sizeof(buf), fdisk);
        send(sock_client, buf, strlen(buf), 0);
        fclose(fdisk);
        sleep(5);
    }
    /*
    while (1) {
        FILE *fcpu = popen("~/shell/cpu.sh", "r");
        FILE *fmem = popen("~/shell/memt.sh", "r");
        FILE *fdisk = popen("~/shell/disk.sh", "r");
        char buf[MAX_SIZE];
        char str[5];
        strcpy(str, "100");
        send(sock_client, str, strlen(str), 0);
        fgets(buf, sizeof(buf), fcpu);
        send(sock_client, buf, strlen(buf), 0);
        memset(buf, 0, sizeof(buf));
        memset(str, 0, sizeof(str));
        strcpy(str, "101");
        send(sock_client, str, strlen(str), 0);
        fgets(buf, sizeof(buf), fmem);
        send(sock_client, buf, strlen(buf), 0);
        memset(buf, 0, sizeof(buf));
        memset(str, 0, sizeof(str));
        strcpy(str, "102");
        send(sock_client, str, strlen(str), 0);
        fgets(buf, sizeof(buf), fdisk);
        send(sock_client, buf, strlen(buf), 0);
        memset(buf, 0, sizeof(buf));
        memset(str, 0, sizeof(str));
        pclose(fcpu); pclose(fmem); pclose(fdisk);
        sleep(5);
    }*/

    /*while (1) {
        scanf("%[^\n]s", buffer);
        getchar();
        send(sock_client, buffer, strlen(buffer), 0);
    }*/

    close(sock_client);
    return 0;
}
