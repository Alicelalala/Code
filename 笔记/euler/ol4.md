# [Problem 4](https://projecteuler.net/problem=4)

------

## **Largest palindrome product**

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

------

## **最大回文乘积**

回文数就是从前往后和从后往前读都一样的数。由两个2位数相乘得到的最大回文乘积是 9009 = 91 × 99。

找出由两个3位数相乘得到的最大回文乘积。

------



```c
#include<stdio.h>
#include <stdlib.h>
#include <inttypes.h>

//整数翻转，判读是否是回文数
int check(int32_t n) {
    int32_t m = n;
    int32_t a = 0;
    while (m) {
        a = a * 10 + m % 10;
        m /= 10;
    }
    return a == n;
}

int main() {
    int32_t max;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            if (check(i * j) && (i * j) > max) {
                max = i * j;
            }
        }
    }
    printf("%"PRId32"\n", max);
}

```

```
//答案：906609
```



