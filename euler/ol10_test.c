/*************************************************************************
	> File Name: ol10_test.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 15时42分29秒
 ************************************************************************/

#include<stdio.h>

#include <stdlib.h>

#include <inttypes.h>

 

 #define MAX_RANGE 2000000

  

  int32_t prime[MAX_RANGE + 5] = {0};

   

   int main() {
       
           int64_t sum = 0;

       for (int32_t i = 2; i <= MAX_RANGE; ++i) {
           
                   if (!prime[i]) { prime[++prime[0]] = i; sum += i;  }

           for (int32_t j = 1; j <= prime[0] && prime[j] * i <= MAX_RANGE; ++j) {
               
                           prime[i * prime[j]] = 1;

                           if (i % prime[j] == 0) break;

                       
           }

               
       }

           printf("%"PRId64"\n",sum);

           return 0;


   }
