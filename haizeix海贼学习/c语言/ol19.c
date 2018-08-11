/*************************************************************************
	> File Name: ol19.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月01日 星期二 15时59分45秒
 ************************************************************************/

#include <stdio.h>

int date[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int sum_date = 365;
    int month_num = 0;
    int year;
    int month;

    for (int i = 1901; i <= 2000; ++i) {
            year = i;
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            date[2] = 29;
            printf("%d\n", year);
        }  else {
            date[2] = 28;
        }
        for (int j = 1; j <= 12; ++j) {
                month = j;
            if (sum_date % 7 == 6) {
                printf("%d/%d/1\n", year, month);
                month_num++;
            } 
            sum_date += date[month];
        }
    }
    printf("%d\n", month_num);
}

