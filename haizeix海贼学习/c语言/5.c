#include <stdio.h>
int main() {
        int n;
        int i;
        int y = 1;
        scanf("%d", &n);
        for(i = 1; i <= n; i++) {
                y *= i;
        }
        printf("%d", y);
        
        printf("%d", dg(n));
        return 0; 
}
int dg(int n) {
        if(n == 1) {
                return 1;
        }
        return dg(n - 1)*n;
}

