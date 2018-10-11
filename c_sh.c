/*************************************************************************
	> File Name: c_sh.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月27日 星期四 18时37分40秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n = 0;
    while (n < 3) {
    FILE *fp = popen("~/shell/memt.sh", "r");
    char buffer[500];
    fgets(buffer, sizeof(buffer), fp);
    printf("%s", buffer);
    pclose(fp);
    n++;
    sleep(5);
    }
    return 0;
}
