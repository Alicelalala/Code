/*************************************************************************
	> File Name: test___1.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月18日 星期日 17时45分22秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_conf_value.c"

void init (int len) {
    //Node *p = (Node *)malloc(sizeof(Node));
    char *buffer = (char *)malloc(sizeof(char) * 20);
    char *temp = (char *)malloc(sizeof(char) * 5);
    size_t n = strlen(buffer);
    get_conf_value("./piheadlthd.conf", "prename", buffer);
    for (int i = 50; i <= 100; i++) {
        sprintf(temp, "%s.%d", buffer, i);
        printf("%s\n", temp);
        //memset(buffer, 0, sizeof(buffer));
    }
}

int main() {
    init(5);
    return 0;
}
