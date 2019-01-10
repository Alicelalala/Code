#### Problem 1

### Multiples of 3 and 5

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

### 3的倍数和5的倍数

如果我们列出10以内所有3或5的倍数，我们将得到3、5、6和9，这些数的和是23。

求1000以内所有3或5的倍数的和。

```c
#include <stdio.h>
//这道题目很简单，这里给出两种解答方法
int method1 () {
    int sum = 0;
    for (int i = 3; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}
//利用等差数列前n项和的性质
int method2 () {
    int ans1 = (3 + 999) * 333 / 2;
    int ans2 = (5 + 995) * (995 / 5) / 2;
    int ans3 = (15 + 990) * (990 / 15) / 2;
    int sum = ans1 + ans2 - ans3;
    return sum;
}

int main() {
    printf("%d\n", method1());
    printf("%d\n", method2());
    return 0;
}

```

```
//答案：233168
```

