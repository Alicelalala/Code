#include<stdio.h>
void f(int n, int *ans) {
        if(n == 1) {
                *ans = 1;
                return;
        }
        int temp;
        f(n-1, &temp);
        *ans = temp * n;
}



int main() {
   int n, ans;
        scanf("%d", &n);
        f(n, &ans);
        printf("%d != %d\n", n, ans);
        return 0;
}

