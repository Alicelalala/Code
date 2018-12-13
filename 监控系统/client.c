/*************************************************************************
	> File Name: client.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月20日 星期二 11时14分34秒
 ************************************************************************/

#include "head.h"
#include "common.c"
#define INS 5

struct mypara {   //每个线程的信息
    const char *s;
    int num;
};


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

int get_message_filename (int bit, char *filename) {
            switch (bit) {
                case 100: {
                    sprintf(filename, "cat /home/caohaiyan/shell/cpu.log");
                } break;
                case 101: {
                    sprintf(filename, "cat /home/caohaiyan/shell/mem.log");
                } break;
                case 102: {
                    sprintf(filename, "cat /home/caohaiyan/shell/disk.log");
                } break;
                case 103: {
                    sprintf(filename, "cat /home/caohaiyan/shell/sysinfo.log");
                } break;
                case 104: {
                    sprintf(filename, "cat /home/caohaiyan/shell/user.log");
                } break;
                case 105: {
                    sprintf(filename, "cat /home/caohaiyan/shell/proc.log");
                } break;
                default : {
                    printf("bit error\n");
                    return 0;
                }
            }
    return 1;
}

int getfilename (char **bashFileName, int id) {

    int n = 0, stime;
    switch (id) {
        case 0: {
            sprintf(bashFileName[n++], "bash ~/shell/cpu.sh");
            sprintf(bashFileName[n++], "bash ~/shell/mem.sh");
            stime = 5;
        } break;
        case 1: {
            sprintf(bashFileName[n++], "bash ~/shell/disk.sh");
            sprintf(bashFileName[n++], "bash ~/shell/sysinfo.sh");
            sprintf(bashFileName[n++], "bash ~/shell/user.sh");
            stime = 60;
        } break;
        case 2: {
            sprintf(bashFileName[n++], "bash ~/shell/proc.sh");
            stime = 30;
        } break;
        default : {
            printf("para->num error\n");
            return 0;
        }
    }
    return stime;
}
/*
void *func (void *argv) {
    struct mypara *para;
    para = (struct mypara *) argv;
    char **bashFileName = (char **)malloc(sizeof(char *) * (INS + 1));
    for (int i = 0; i < 3; i++) {
        bashFileName[i] = (char *)malloc(sizeof(char) * 30);
    }
    //sprintf(bashFileName[0], "hjkkkkk");
    printf("para->num %d\n", para->num);
    int n = 0, stime;
    stime = getfilename(bashFileName, para->num);
    switch(para->num) {
        case 0: n = 2; break;
        case 1: n = 3; break;
        case 2: n = 1; break;
    }

    FILE *fp;
    #define MAX_N 200
    char *buffer = (char *)malloc(sizeof(char) * 200);
    while (1) {
        printf("para ====== %d  \n", para->num);
        for (int i = 0; i < n; i++) {
            printf("%s\n", bashFileName[i]);
            fp = popen(bashFileName[i], "r");
            pclose(fp);
        }
        sleep(stime);
    }
    return NULL;
}
*/
int main(int argc, char *argv[]) {
    //pthread_t t[INS + 1];
    //struct mypara para[INS + 1];

    int port = atoi(argv[2]);
    char *host = argv[1];
    int sockfd, sock_listen;
    sockfd = connect_sockfd(port, host);

    if (sockfd < 0) {
        printf("connect!!\n");
        close(sockfd);
        exit(0);
    }
    close(sockfd);
/*
    for (int i = 0; i < 3; i++) {
        para[i].s = "Monitoring data";
        para[i].num = i;
        if (pthread_create(&t[i], NULL, func, (void *)&para[i]) == -1) {
            printf("error\n");
            exit(1);
        }
    }
  */  
    port = 9999;
    sock_listen = create_socket(port);
    if (sock_listen < 0) exit(0);
    
    int bit, a;
    bit = 100;
    int sock_data_listen, sockfd_data;
    int port_data = 9988;
    sock_data_listen = create_socket(port_data);
    if (sock_data_listen < 0) exit(0);
    
    while (1) {
        struct sockaddr_in master_addr;
        socklen_t len = sizeof(master_addr);
        if ((sockfd = accept(sock_listen, (struct sockaddr *)&master_addr, &len)) < 0) {
            perror("accept() error!\n");
            break;
        }
        FILE *fp;
        char *filename = (char *)malloc(sizeof(char) * 100);

        send(sockfd, &bit, 4, 0);
        while ((a = recv(sockfd, &bit, 4, 0)) > 0) {
            fp = NULL;
            get_message_filename(bit, filename);
            if ((sockfd_data = accept(sock_data_listen, (struct sockaddr *)&master_addr, &len)) < 0) {
                perror("accept() error!\n");
                break;
            }
            #define MAX_N 200
            char *buffer = (char *)malloc(sizeof(char) * MAX_N);
            memset(buffer, 0, sizeof(buffer));
            fp = popen(filename, "r");
            while (!feof(fp)) {
                fread(buffer, 4, 1, fp);
                printf("%s", buffer);
                send(sockfd_data, buffer, strlen(buffer), 0);
                memset(buffer, 0, sizeof(buffer));
            }
            pclose(fp);
            close(sockfd_data);
            bit += 1;
            if (bit == 106) break;
            send(sockfd, &bit, 4, 0); //发送文件标识符
        }
        close(sock_data_listen);
        close(sockfd);
    }
    close(sock_listen);
    //pthread_join(t[0], NULL);
    //pthread_join(t[1], NULL);
    //pthread_join(t[2], NULL);
    return 0;
}

