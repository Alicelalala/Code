/*************************************************************************
	> File Name: ol31.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月21日 星期五 16时01分16秒
 ************************************************************************/

#include <stdio.h>

int num[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int dnum[205] = {0};

int main() {
    dnum[0] = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j <= 200 - num[i]; j++) {
            dnum[j + num[i]] += dnum[j];
        }
    }
    printf("%d", dnum[200]);
}
