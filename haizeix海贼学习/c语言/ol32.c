/*************************************************************************
	> File Name: ol32.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月23日 星期一 20时12分52秒
 ************************************************************************/
#include <math.h>
#include <stdio.h> 


int num[10] = {0};

int digits(int x) {
    int ans = 1;
    while (x / 10)  {
        ans++;
        return digits(x / 10);
    }
    return ans;
}

int Pos(int x) {
    if (x < 10) {
        num[x] = 1;
        return 1;
    }
    else {
        if (x % 10 == 0) return 0;
        else if (num[x % 10]) return 0;
        else {
            num[x % 10] = 1;
            return Pos(x / 10);
        }
    }
}

int get_pan(int x, int y) {
    if (Pos(x) && Pos(y) && Pos(x * y))
    return x * y;
    else {
        return 0;
    }
    
}

int main() {

    int sum = 0;

    for (int i = 0; i < 100; i++) {
        for (int j = 100; ; j++) {
            if (digits(i * j) + digits(j) + digits(i) < 9) continue;
            else if (digits(i) + digits(j) + digits(i * j) > 9) break;
            else {
                sum += get_pan(i, j);
                
            }

        }
    }
    printf("%d", sum);
}

