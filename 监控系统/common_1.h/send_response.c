/*************************************************************************
	> File Name: send_response.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月19日 星期五 15时28分07秒
 ************************************************************************/

#include <stdio.h>

/*定义 send(int s, const void * msg, int len, unsigned int flags)
 * s:已经建立好连接的socket
 * msg:指向欲连线的数据内容
 * len：数据长度
 * flag：一般为0
 * send成功返回实际传送出去的字符数，失败返回-1
*/

int send_response (int sockfd, int req) {
    if ((int nbytes = send(sockfd, &req, 1, 0)) < 0) {
        perror("send error!");
        exit(1);
    }
    return 0;
}
