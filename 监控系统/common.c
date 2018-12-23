
int write_pi_log (char *Pihealthlog, const char *format, ...) {
    va_list arg;
    int done;
    FILE *fp = fopen(Pihealthlog, "a+");

    va_start(arg, format);

    time_t time_log = time(NULL);
    struct tm* tm_log = localtime(&time_log);
    fprintf(fp, "%04d-%02d-%02d %02d:%02d:%02d ", tm_log->tm_year + 1900, tm_log->tm_mon + 1, tm_log->tm_mday, tm_log->tm_hour, tm_log->tm_min, tm_log->tm_sec);

    done = vfprintf(fp, format, arg);
    va_end(arg);

    fflush(fp);
    fclose(fp);
    return done;
}

/*定义recv(SOCKET s, char *buf, int len, int flags)
 * s:接收套接字描述符
 * buf:指明一个缓冲区，该缓冲区用来存放recv函数接收到的数据
 * len：buf的长度
 * 如果recv函数copy时出错，返回SOCKET_ERROR;如果recv函数在等待协议接收数据时网络中断了，返回0；正常返回copy的字节数::wq
 */
int recv_response (int sockfd) {
    int req, nbytes;
    nbytes = recv(sockfd, &req, 1, 0);
    if (nbytes < 0){
        perror("recv error!");
        exit(1);
    } else if (nbytes == 0) {
        //printf("socket closed!\n");
        return 0;
    }
    return req;
}

/*定义 send(int s, const void * msg, int len, unsigned int flags)
 * s:已经建立好连接的socket
 * msg:指向欲连线的数据内容
 * len：数据长度
 * flag：一般为0
 * send成功返回实际传送出去的字符数，失败返回-1
*/

int send_response (int sockfd, int req) {
    int nbytes;
    if ((nbytes = send(sockfd, &req, 1, 0)) == -1) {
        perror("send error!");
        exit(1);
    }
    return 0;
}

int get_conf_value (const char *pathname, const char *key_name, char *value) {
    FILE *fp = NULL;
    char *line = NULL, *substr = NULL;
    size_t len = 0, tmplen = 0;
    ssize_t read;
    if (key_name == NULL || value == NULL) {
       // printf("paramer is invaild!\n");
        exit(-1);
    }
    fp = fopen(pathname, "r");
    if (fp == NULL) {
        //printf("Open config, file, error!\n");
        exit(-1);
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        substr = strstr(line, key_name);
        if (substr == NULL) 
            continue;
        else {
            tmplen = strlen(key_name);
            if (line[tmplen] == '=') {
                strncpy(value, &line[tmplen + 1], (int)read - tmplen);
                tmplen = strlen(value);
                *(value + tmplen - 1) = '\0';
                break;
            }
            else {
                //printf("Maybe there is something wrong with config file");
                continue;
            }
        }
    }
    if (substr == NULL) {
       // printf("%s not found is config file!\n", key_name);
        fclose(fp);
        exit(-1);
    }
    free(line);
    fclose(fp);
    return 0;
}

int connect_socket (int port, char *host) {
    int sockfd;
    struct sockaddr_in dest_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        //perror("socket() error\n");
        return -1;
    }
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr))) {
        //perror("connect() error");
        return -1;
    }
    return sockfd;
}

int bind_socket (int port) {
    int sockfd;
    struct sockaddr_in sock_addr;
    struct linger m_sLinger;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        //perror("socket() error!\n");
        return -1;
    }
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (const char *)&m_sLinger, sizeof(struct linger));
    if ((bind(sockfd, (struct sockaddr *)&sock_addr, sizeof(struct sockaddr))) < 0) {
        close(sockfd);
        //perror("bind() error!\n");
        return -1;
    }
    if (listen(sockfd, 20) < 0) {
        close(sockfd);
        //perror("listen() error!\n");
        return -1;
    }
    //printf("listening...\n");
    return sockfd;
}
