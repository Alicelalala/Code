/*************************************************************************
	> File Name: ol26.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月26日 星期六 15时48分09秒
 ************************************************************************/

#include <stdio.h>

int get_circle_length(int d) {
    int first_come[1000] = {0};
    int y = 1, num = 1;
    do {
        first_come[y] = num++;
        y = y * 10 % d;
    }while (y && first_come[y] == 0);
    if (y == 0) return 0;
    return num - 1;
}
int main() {
    int max_len = 0, len, d;
    for (int i = 2; i < 1000; i++) {
        len = get_circle_length(i);
        if (len > max_len) {
            max_len = len;
            d = i;
        }
    }
    printf("%d", d);
    return 0;
}

