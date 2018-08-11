/*************************************************************************
	> File Name: ol5.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月26日 星期四 12时52分37秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    int temp;
    int num;
    int mul = 1;
    int prime_num[20][1] = {0};
    int prime[] = {2, 3, 5, 7, 11, 13, 17, 19};

    for (int i = 2; i <= 20; ++i) {
        temp = i;
        for (int j = 0; j < 8; ++j) {
            num = 0;
            while (temp % prime[j] == 0) {
                num++;
                temp /= prime[j];
            }
            if (prime_num[j][0] < num) {
                prime_num[j][0] = num;
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        mul *= pow(prime[i], prime_num[i][0]);
    }

    printf("%d", mul);

    return 0;
}

