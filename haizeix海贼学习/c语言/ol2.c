/*************************************************************************
	> File Name: ol2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月25日 星期三 23时14分22秒
 ************************************************************************/

 #include <stdio.h>
 
 #define MAX 4000000

 int main() {
     unsigned long long sum = 2;
     int fib[MAX + 5] = {0};
     fib[0] = 1;
     fib[1] = 1;
     fib[2] = 2;
     fib[3] = 3;
     
     for (int n = 3; ; n++) {
         fib[n] = fib[n - 2] + fib[n - 1];
         if (fib[n] > MAX) break;
         if (fib[n] % 2 == 0) {
             sum += fib[n];
         }
     }

     printf("%lld", sum);
 }
