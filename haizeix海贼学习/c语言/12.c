/*************************************************************************
	> File Name: 12.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月09日 星期一 18时32分54秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int low = 0;
    int high = 6;
    int mid = (low + high) / 2;
    int a[] = {2, 4, 5, 6, 7, 8};
    int x = 0;


    while(low <= high) {
        if (a[mid] == x) {
            printf("%d", mid + 1);
        }

        if(a[mid] < x) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }

        mid = (low + high) / 2;

    }

    return 0;
}
