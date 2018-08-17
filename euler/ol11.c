/*************************************************************************
	> File Name: ol11.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 16时09分29秒
 ************************************************************************/
#include<stdio.h>
#include <inttypes.h>

int main() {
    int direct[4][2] = {1,0,0,1,1,1,1,-1};
    int num[30][30] = {0};
    int64_t max = 0;
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            scanf("%d", &num[i][j]);
        }
    }

    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            for (int k = 0; k < 4; k++) {
                int64_t temp = 1;
                for (int f = 0; f < 4; f++) {
                    temp *= num[i + f * direct[k][0]][j + f * direct[k][1]];
                }
                if (temp > max) max = temp;
            }
        }
    }

    printf("%"PRId64"\n", max);
    return 0;

}
