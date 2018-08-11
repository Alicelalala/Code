/*************************mZ
	> Created Time: 2018年05月04日 星期五 11时55分32秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int a[10] = {0};

int isprime(int64_t n) {
    for (int64_t i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int get_value(int n, int *a) {
    int64_t temp = 0;
    for (int i = 1; i <= n; i++) {
        temp = temp * 10 + a[i];
    }   
    return temp;
}

void swap(int i , int j, int *a) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void init_pandigital(int n) {
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
}
int main() {
    int64_t Pan[10000];
    int num = 0;
    int q;
    for (int k = 8; k > 0; k--) {
        init_pandigital(k);
        for (int i = 1; i < k; i++) {
            for (int j = i + 1; j <= k; j++) {
                q = 0;
                swap(i, j, a);
                int64_t temp = get_value(k, a);
                if (isprime(temp)) {
                    q = 1;
                    Pan[num++] = temp;
                }
                swap(i, j, a);
            }
        }
        if (q) break;
    }
    for (int i = 0; i < num; i++) {
        printf("%"PRId64"\n", Pan[i]);
    }
    return 0;
}
