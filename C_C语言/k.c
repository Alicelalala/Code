/*************************************************************************
	> File Name: k.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月20日 星期四 18时34分10秒
 ************************************************************************/

#include <stdio.h>
int is_prime(x)
int x;
{
    for (int i = 2; i * i <= x; i++) {
                if (x % i == 0)  return 0;
            
    }
        return 1;

}

int main() {
    for (int i = 2; i < 100; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
