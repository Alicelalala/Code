/*************************************************************************
	> File Name: 1809-2买菜.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月14日 星期五 11时10分23秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 2000

#define min(a, b) (a) > (b) ? (b) : (a)
#define max(a, b) (a) >= (b) ? (a) : (b)
typedef struct Data {
    int s, e;
} Data;

int main() {
    Data *dataH = (Data *)malloc(sizeof(Data) * MAX_N);
    Data *dataW = (Data *)malloc(sizeof(Data) * MAX_N);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &dataH[i].s, &dataH[i].e);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &dataW[i].s, &dataW[i].e);
    }
    int i = 0, j = 0;
    int sumT = 0;
    while (i < n && j < n) {
        if (dataH[i].s >= dataW[j].e) {
            j++;
            continue;
        } else if (dataH[i].e <= dataW[j].s) {
            i++;
            continue;
        }
        int emin = min(dataH[i].e, dataW[j].e);
        int smax = max(dataH[i].s, dataW[j].s);
        sumT += emin - smax;
        if (dataH[i].e >= dataW[j].e) {
            j++;
        } else {
            i++;
        }
    }
    printf("%d\n", sumT);
    return 0;
}
