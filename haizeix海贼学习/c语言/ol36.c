/*************************************************************************
	> File Name: ol36.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月02日 星期三 15时47分40秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX 1000000

int Double_base(int n) {
    int temp = n;
    int a[20] = {0};
    int num = 0;
    while (temp) {
        a[num++] = temp % 2;
        temp /= 2;
    }
    for (int i = 0; i < num; i++) {
        if (a[i] != a[num - i -1]) return 0;
    }
    return n;

}

int rev(int n) {
    int digits = floor(log10(n));
    int value = pow(10, digits); 
    int temp = n;
    int sum = 0;
    while (temp) {
        sum += temp % 10 * value;
        value /= 10;
        temp /= 10;
    }
    return sum;
}

int main() {
    int sum = 0;
    for (int i = 1;  i < 10; i++) {
        if (Double_base(i)) {
            sum += i;
        }
        int temp = i * 10 + i;
        if (Double_base(temp)) {
            sum += temp;
        }
    }
    for (int i = 10; i < 100; i++) {
        int temp = i * 10 + i / 10;
        if (Double_base(temp)) {
            sum += temp;
        }
        temp = i * 100 + rev(i);
        if (Double_base(temp)) {
            sum += temp;
        }
    }
    for (int i = 100; i < 1000; i++) {
        int temp = i * 100 + rev(i / 10);
        if (Double_base(temp)) {
            sum += temp;
        }
        temp = i * 1000 + rev(i);
        if (Double_base(temp)) {
            sum += temp;
        }
    }
    printf ("%d\n", sum);
    return 0;
}

