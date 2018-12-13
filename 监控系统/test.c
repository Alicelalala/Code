/*************************************************************************
	> File Name: test.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月25日 星期日 20时37分39秒
 ************************************************************************/

#include <stdio.h>
#include "head.h"

int main() {
    #define MAX 10
    FILE *fp = popen("~/shell/mem.sh 0.24", "r");
    char *buffer = (char *)malloc(sizeof(char) * MAX);
    while (!feof(fp)) {
        fread(buffer, MAX, 1, fp);
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    pclose(fp);
    return 0;
}
