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
