# [Problem 3](https://projecteuler.net/problem=3)

------

## **Largest prime factor**

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

------

## **最大质因数**

13195的所有质因数为5、7、13和29。

600851475143最大的质因数是多少？

 ```c
//-9223372036854775808~9223372036854775807(10^19)  int64的范围
#include<stdio.h>
#include <inttypes.h>

#define NUM 600851475143

int64_t main() {
    int64_t max_prime;
    int64_t num = NUM;
    for (int64_t i = 2; i * i < NUM; i++) {
        while (num % i == 0) {
            num /= i;
            max_prime = i;
        }
    }
    if (num != 1) max_prime = num;
    printf("%"PRId64"\n", max_prime);
    return 0;
}

 ```

