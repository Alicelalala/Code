/*************************************************************************
	> File Name: 19.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月23日 星期一 22时56分19秒
 ************************************************************************/

#include <stdio.h>

int main() {
        int n;
        scanf("%d", &n);
        int one = 1;
        int two = 2;
        int i;
        int num;
    while (n >= 3) {
                
        for (i = 3; i <= n; ++i) {
                         num = one + two;
                         one = two;
                        two = num;
                     
        }
                printf("%d", num);
                return 0;
            
    }
        
        printf("%d", n);
            
            
        return 0;

}
