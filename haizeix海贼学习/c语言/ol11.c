/*************************************************************************
	> File Name: ol11.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月26日 星期四 19时39分45秒
 ************************************************************************/

#include <stdio.h>

int grid[20][20];
int direct[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

int main() {

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    printf("\n-------------------------\n");

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            printf("%3d", grid[i][j]);
        }
        printf("\n");
    }
    
    int x = 0, y = 0;
    int MAX_num = 0;

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            for (int k = 0; k < 4; ++k) {
                int p = 1;
                for (int f = 0; f < 4; ++f) {
                    x = i + direct[k][0] * f;
                    y = j + direct[k][1] * f;
                    if (x < 0 || x >= 20) break;
                    if (y < 0 || y >= 20) break;
                    p *= grid[x][y];
                }
                MAX_num = p > MAX_num ? p : MAX_num;
            }
        }
    }

    printf("%d", MAX_num);

    return 0;
}

