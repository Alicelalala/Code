#include<stdio.h>
int main() {
        int n = 1024;
        int i = 0, k = 0;
        int b[32] = {0};
        while(n) {
            b[i++] = n%2;
                n = n/2;
                k++;
        }
        for(i = 31; i >= 0; i--) {
                printf("%2d",b[i]);
                      }
        return 0;
}
