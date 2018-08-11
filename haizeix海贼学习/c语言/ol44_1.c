/*************************************************************************
	> File Name: ol44_1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月29日 星期日 10时39分39秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int low = 1;
    int high;
    int x;
    int temp;
    scanf("%d", &x);
    if (x < 0) {
        high = 0 - x;
        temp = high;
    }
    high = x;
    temp = x;
    int mid = (low + high) / 2;
    while (low <= high) {
        mid = (low + high) / 2;
        if ( temp == mid * mid * mid) {
            if (temp < 0) {
                printf("%d", 0 - mid);
            }
            printf("%d", mid);
            break;
        } else if (temp < mid * mid * mid) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }


    return 0;
}
