/*************************************************************************
	> File Name: ol34.c
	> Author: 
	> Mail: 
	> Created Time: 2018年06月05日 星期二 16时12分59秒
 ************************************************************************/

#include <stdio.h>
#define MAX 5000000
int get_factorial(int n) {
    int mul = 1;
    while (n) {
        mul *= n;
        n--;
    }
    return mul;
}
int IS_Cur_Num(int n) {
    int sum = 0;
    int temp = n;
    while (n) {
        sum += get_factorial(n % 10);
        n /= 10;
    }
    return sum == temp;
}

int main() {
    int sum = 0;
    for (int i = 10; i < MAX; i++) {
        if (IS_Cur_Num(i)) {
            printf("%d\n", i);
            sum += i;
        }
    }

    printf("%d", sum);
    return 0;
}
