# [Problem 7](https://projecteuler.net/problem=7)

------

## **10001st prime**

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

------

## **第10001个素数**

列出前6个素数，它们分别是2、3、5、7、11和13。我们可以看出，第6个素数是13。

第10,001个素数是多少？



```c
#include<stdio.h>

#define MAX 1000000

int prime[MAX + 5] = {0};
//线性筛代码
int main() {
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
           if (i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    printf("%d", prime[10001]);
    return 0;
}

```

