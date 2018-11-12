/*************************************************************************
	> File Name: recv_response.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月19日 星期五 15时35分06秒
 ************************************************************************/

#include <stdio.h>

/*定义recv(SOCKET s, char *buf, int len, int flags)
 * s:接收套接字描述符
 * buf:指明一个缓冲区，该缓冲区用来存放recv函数接收到的数据
 * len：buf的长度
 * 如果recv函数copy时出错，返回SOCKET_ERROR;如果recv函数在等待协议接收数据时网络中断了，返回0；正常返回copy的字节数::wq
 */
int recv_response (int sockfd) {
    int req, nbytes;
    nbytes = recv(sockfd, &req, 1, 0)
    if (nbytes < 0){
        perror("recv error!");
        exit(1);
    } else if (nbytes == 0) {
        perror("SOCKET error!");
        exit(1);
    }
    return req;
}

