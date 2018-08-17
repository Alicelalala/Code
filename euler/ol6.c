/*************************************************************************
	> File Name: ol6.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 11时59分25秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int sum = 0, num_sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i * i;
        num_sum += i;
    }
    num_sum *= num_sum;
    printf("%d\n", num_sum - sum);
    return 0;
}
