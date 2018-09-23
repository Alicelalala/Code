/*************************************************************************
	> File Name: socket.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月23日 星期日 16时16分40秒
 ************************************************************************/

#include <stdio.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
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

#define PORT 8731 //端口号
#define BACKLOG 5

int main() {
    int sockfd, new_fd; //socket句柄和建立连接后的句柄
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    //their_addr = 192.168.1.40;
    int sin_size;

    sockfd = socket(AF_INET, SOCK_STREAM, 0); //建立socket
    if (sockfd == -1) {
        printf("socket failed:%d\n", errno);
        return -1;
    }
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(PORT); 
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY); //本机IP
    bzero(&(my_addr.sin_zero), 8);
    if (bind(sockfd, (struct sockaddr*) & my_addr, sizeof(struct sockaddr)) < 0) {
        printf("bind error");
        return -1;
    }
    listen(sockfd, BACKLOG);
    while(1) { 
        sin_size = sizeof(struct sockaddr_in);
        new_fd = accept(sockfd, (struct sockaddr*) & their_addr, &sin_size);
        if (new_fd == -1) {
            printf("receive failed");
        } else {
            printf("receive succuss");
            send(new_fd, "Hello World!", 12, 0);
        }
    }
    return 0;
}

