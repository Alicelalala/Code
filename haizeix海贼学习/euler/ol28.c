/*************************************************************************
	> File Name: ol28.c
	> Author: 
	> Mail: 
	> Created Time: 2018年06月05日 星期二 09时53分30秒
 ************************************************************************/

#include <stdio.h>
int main() {
    int sum = 1;
    for (int i = 3; i <= 1001; i += 2) {
        int temp = 4 * i * i - 6 * i + 6;
        sum += temp;
    }
    printf("%d", sum) ;
    return 0;
}
