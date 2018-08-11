#include <stdio.h>

int main() {
            int matrix[3][3];
            int i;
            int j;
            for (i = 0; i < 3; i++) {
                            for (j = 0; j < 3; j++) {
                                                scanf("%d%d", &matrix[i][j]);
                                            }
                        }
            
            for (i = 0; i < 3; i++) {
                            for (j = 2; j >= 0; j--) {
                                                printf("%d", matrix[j][i]);
                                                if (j != 0) {
                                                                        printf(" ");
                                                                    }
                                            }
                            printf("\n");
                        }
            return 0;
}


