/*************************************************************************
	> File Name: ol24_game.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 15时54分28秒
 ************************************************************************/

#include <stdio.h>

int mult[12] = {0};
int num[10] = {0};

void init_mult() {
    mult[0] = 1;
    for (int i = 1; i < 10; i++) {
        mult[i] = i * mult[i - 1];
    }
}

int get_Lexper(int n, int k) {
    int ans = k / mult[n] + 1;
    int i = -1;
    while (ans) {
        i++;
        if (!num[i]) ans--;
    } 
    num[i] = 1;
    return i;
}
int main() {
    init_mult();
    int n, k;
    scanf("%d%d", &n, &k);
    k--;
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", get_Lexper(i, k));
        k = k % mult[i];
    }
    return 0;
}

