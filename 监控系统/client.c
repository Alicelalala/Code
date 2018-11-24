/*************************************************************************
	> File Name: client.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月20日 星期二 11时14分34秒
 ************************************************************************/

#include "head.h"

int connect_sockfd (int port, char *host) {
    int sockfd;
    struct sockaddr_in dest_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() error!\n");
        return -1;
    }
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr))) {
        perror("connect() error!\n");
        return -1;
    }
    return sockfd;
}

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

int main(int argc, char *argv[]) {
    int port = atoi(argv[2]);
    char *host = argv[1];
    int sockfd, sock_listen;
    sockfd = connect_sockfd(port, host);
    if (sockfd < 0) {
        printf("connect!!\n");
    }
    printf("传输一点东西\n");
    //sleep(5);
    //if (sockfd < 0) exit(0);
    close(sockfd);
    
    port = 9999;
    sock_listen = create_socket(port);
    //sleep(5);
    if (sock_listen < 0) exit(0);
    
    while (1) {
        struct sockaddr_in master_addr;
        socklen_t len = sizeof(master_addr);
        if ((sockfd = accept(sock_listen, (struct sockaddr *)&master_addr, &len)) < 0) {
            perror("accept() error!\n");
            break;
        }
        printf("再传输一点东西\n");
        close(sockfd);
    }
    close(sock_listen);
    return 0;
}

