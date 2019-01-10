# [Problem 6](https://projecteuler.net/problem=6)

------

## **Sum square difference**

The sum of the squares of the first ten natural numbers is,

12 + 22 + … + 102 = 385

The square of the sum of the first ten natural numbers is,

(1 + 2 + … + 10)2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

------

## **平方的和与和的平方之差**

前十个自然数的平方的和是

12 + 22 + … + 102 = 385

前十个自然数的和的平方是

(1 + 2 + … + 10)2 = 552 = 3025

因此前十个自然数的平方的和与和的平方之差是 3025 − 385 = 2640。

求前一百个自然数的平方的和与和的平方之差。

 

```c
#include <stdio.h>
//int类型最大值约10^10
int main() {
    int sum1 = 0, sum2 = 0, n = 100;
    do {
        sum1 += n;
        sum2 += n * n;
    } while (--n);
    printf("%d\n", sum1 * sum1 - sum2); 
    return 0;
}
```

