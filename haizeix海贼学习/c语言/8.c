#include <stdio.h>

int main() {
            int n;
            int k;
            int j;
            int numbers[1000001];
            int m;
            int i;
            int f;
            int low;
            int high;
            int mid;

            // 反复读入数字和查找数字的数量
            while (scanf("%d%d", &n, &k) != EOF) {
                            
                            // 读入给定的数字
                for (i = 0; i < n; i++) {
                    scanf("%d", &numbers[i]);
                  }
                for (j = 0; j < k; j++) {
                   // 读入待查找的数字，
                      scanf("%d", m);

                     // 请在下面完成查找读入数字的功能
                                                low = 0;
                                                high = n - 1;
                                                f = 1;
                                                
                                                while (low <= high) {
                                                                        mid = (low + high) / 2;
                                                                        if (numbers[mid] == m) {
                                                                                                    f = 0;
                                                                                                    if (j == k - 1) {
                                                                                                                                    printf("%d", mid + 1);
                                                                                                                                }
                                                                                                    else {
                                                                                                                                    printf("%d ", mid + 1);
                                                                                                                                }
                                                                                                 return;
                                                                                                }
                                                                        else if (numbers[mid] < m) {
                                                                                                    low = mid + 1;
                                                                                                }
                                                                        else {
                                                                                                    high = mid - 1;
                                                                                                }
                                                                    }
                                                
                                                if (f == 1) {
                                                                        if (j == k - 1) {
                                                                                                        printf("0");
                                                                                                    }
                                                                            else {
                                                                                                            printf("0 ");
                                                                                                        }
                                                                    }
                                            }

                        }
    return 0;
    }
