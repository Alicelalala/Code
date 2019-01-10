# [Problem 5](https://projecteuler.net/problem=5)

------

## **Smallest multiple**

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

------

## **最小倍数**

2520是最小的能够被1到10整除的数。

最小的能够被1到20整除的正数是多少？



```c
#include<stdio.h>
#include <inttypes.h>
//辗转相处求最大公因子
int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a % b);
}
int main() {
    int64_t ans = 1;
    for (int i = 1; i <= 20; i++) {
        ans *= i / gcd(i, ans);
    }
    printf("%"PRId64"\n", ans);
    return 0;
}

```

