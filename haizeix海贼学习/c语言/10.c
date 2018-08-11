#include <stdio.h>

int main() {
            int matrix[100][100];
            int m;
            int n;
            int i;
            int j;
            int k = 0;
            int num = 0;
            
            scanf("%d%d", &m, &n);
            for (i = 0; i < m; i++) {
                            for (j = 0; j < n; j++) {
                                                scanf("%d", &matrix[i][j]);
                                            }
                        }
            
            do {
                        for (j = k; j < n - k; j++) {
                                        num += 1;
                                        printf("%d", matrix[0][j]);
                                        if (num != n * m) {
                                                            printf(" ");
                                                        }
                                        else 
                                            break;
                                        }
                        
                        for (i = k + 1; i < m - k; i++) {
                                        num += 1;
                                        printf("%d", matrix[i][j - 1]);
                                        if (num != n * m) {
                                                            printf(" ");
                                                        }
                                        else 
                                            break;
                                    }
                        
                        for (j = n - 2 - k; j >= k; j--) {
                                        num += 1;
                                        printf("%d", matrix[i - 1][j]);
                                        if (num != n * m) {
                                                            printf(" ");
                                                        }
                                        else 
                                            break;
                                    }
                        
                        for(i = n - 2 - k; i >= 1 + k; i--) {
                                        num += 1;
                                        printf("%d", matrix[i][j]);
                                        if (num != n * m) {
                                                            printf(" ");
                                                        }
                                        else 
                                            break;
                                    }
                            k += 1;
                        }while (num < m * n);
    
        return 0;
}
