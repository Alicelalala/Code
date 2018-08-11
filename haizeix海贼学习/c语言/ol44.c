/*************************************************************************
	> File Name: ol44.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月29日 星期日 11时13分40秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

#define MAX 100000000
int64_t ans[MAX + 5] = {0};



int getValue(int n) {
    return (n * (n * 3 - 1)) / 2;
}

int isPentagonal(int64_t x) {
    int min = 0, max = x, mid;
    while (min <= max) {
        int temp;
        mid = (min + max) / 2;
        if ((temp = getValue(mid)) == x) break;
        if (x < temp) {
            max = mid - 1;
        }   else {
                min = mid + 1;
            }
        }
        if (min > max) return 0;
        return mid;
    
}

int64_t main() {
    int64_t minD = 10000000;
    int64_t p1, p2;
    if (int mid = isPentagonal(5)) printf("%d", mid);
    return 0;
    for (int64_t i = 1;i < 3000 ; ++i) {
        p1 = getValue(i);
        p2 = getValue(i - 1);
        if (p1 - p2 >= minD) break;
        for (int64_t j = i - 1; j > 0; --j) {
            p2 = getValue(j);
            if (ans[p1 + p2] || ans[p1 - p2]) continue;
            if (!isPentagonal(p1 + p2)) {
                ans[p1 + p2] = 1;
            } else if (!isPentagonal(p1 - p2)) {
                ans[p1 - p2] = 1;
            } else {
                minD = p1 - p2;
            }
         }
    }



    printf("%ld\n", minD);
    return 0;
}
 
