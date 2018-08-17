/*************************************************************************
	> File Name: ol39.c
	> Author: 
	> Mail: 
	> Created Time: 2018年06月05日 星期二 16时47分05秒
 ************************************************************************/

#include <stdio.h> 

int num[1000 + 5]  = {0};

int gcd(int n, int m) {
    if (!m) return n;
    return gcd(m, n % m);
}

void all_Int_R_Triandles() {
    int a, b, c;
    int perimeter, temp;
    for (int i = 1; i < 50; i++) {
        for (int j = i + 1; ; j++) {
            if (gcd(i, j) != 1) continue;
            a = 2 * i * j;
            b = j * j - i * i;
            c = j * j + i * i;
            perimeter = a + b + c;
            temp = perimeter;
            if (perimeter > 1000) break;
            while (perimeter <= 1000) {
                num[perimeter]++;
                perimeter += temp;
            }
        }
    }
    return;
}

int main() {
    all_Int_R_Triandles();
    int p;
    int max = 0;
    for (int i = 1; i <= 1000; i++) {
        if (num[i] > max) {
            p = i;
            max = num[i];
        }
    }
    printf("%d\n%d\n", p, max);
    return 0;
}

