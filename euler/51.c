/*************************************************************************
	> File Name: 51.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月16日 星期四 10时56分57秒
 ************************************************************************/

#include<stdio.h>

#define MAX 1000000

int prime[MAX + 5] = {0};
int ans[MAX + 5] = {0};

void initprime() {
    prime[0] = prime[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) ans[++ans[0]] = i;
        for (int j = 1; j <= ans[0]; j++) {
            if (i * ans[j] > MAX) break;
            prime[i * ans[j]] = 1;
            if (i % ans[j] == 0) break;
        }
    }
}

int get_num(int *b) {
    int temp = 0;
    for (int i = 5; i >= 0; i--) {
        temp = temp * 10 + b[i];
    }
    return temp;
}
int main() {
    initprime();
    int b[6];
    int num = 0;
    int temp;
    /*for (int i = 0; i < 5; i++) {
        b[i] = 0;
        while (b[i] < 10) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 5; k++) {
                    if (i == k) continue;
                    b[k] = j;
                }
                temp = get_num(b);
                if (!prime[temp]) {
                    num++;
                }
            }
            if (num == 8) {
                printf("%d\n", temp);
            }
            num = 0;
            b[i]++;
        }
        //printf("一位");
    }
    //固定两位
    //printf("固定");
    for (int i = 0; i < 5; i++) {
        b[i] = 0;
      //  printf("%d\t", i);
        for (int j = 0; j < 5; j++) {
            if (j == i) continue;
            while (b[i] < 10) {
                b[j] = 0;
                while (b[j] < 10) {
                    for (int k = 0; k < 10; k++) {
                        for (int f = 0; f < 5; f++) {
                            if (f == i || f == j) continue;
                            b[f] = k;
                        }
                        temp = get_num(b);
                        if (!prime[temp]) {
                            num++;
//                            printf("%d\t%d\t\t\t", num, temp);
                        }
                    }
                    if (num == 8) {
                        printf("%d\n", temp);
                    }
                    b[j]++;
                    num = 0;
                }
                b[i]++;
            }
        }
    }
//三位
for (int i = 0; i < 5; i++) {
    b[i] = 0;
    //printf("%d\n", i);
    for (int j = 0; j < 5; j++) {
        if (j == i) continue;
        b[j] = 0;
        for (int k = 0; k < 5; k++) {
            if (k == i || k == j) continue;
            b[k] = 0; b[i] = 0;
            while (b[i] < 10) {
                b[j] = 0;
                while (b[j] < 10) {
                    b[k] = 0;
                    while (b[k] < 10) {
                        for (int f = 0; f < 10; f++) {
                            for (int g = 0; g < 5; g++) {
                                if (g == i || g == j || g == k) continue;
                                b[g] = f;
                            }
                            temp = get_num(b);
                          //  printf("%d\t", temp);
                            if (!prime[temp]) {
                                num++;
                                //printf("%d\t%d\t\t", num, temp);
                            }
                        }
                        if (num == 8) {
                            printf("%d\n", temp);
                        }
                        b[k]++;
                        num = 0;
                    }
                    b[j]++;
                }
                b[i]++;
            }
        }
    }
}
b[0] = b[1] = b[2] = b[3] = b[4] = 0;
while (b[4] < 10) {
    while (b[3] < 10) {
        while (b[2] < 10) {
            while (b[1] < 10) {
                while (b[0] < 10) {
                    temp = get_num(b);
                    if (!prime[temp]) {
                        num++;
                        printf("%d\t%d\t\t", num, temp);
                    }
                    b[0]++;
                }
                if (num == 8) {
                    printf("%d\n", temp);
                }
                b[0] = 0;
                num = 0;
                b[1]++;
            }
            b[1] = 0;
            b[2]++;
        }
        b[2] = 0;
        b[3]++;
    }
    b[3] = 0;
    b[4]++;
}*/
for (int i = 1; i < 10; i+=2) {
    b[0] = i;
    for (int j = 1; j < 6; j++) {
        for (int k = 1; k < 6; k++) {
            if (k == j) continue;
            b[j] = b[k] = 0;
            while (b[j] < 10) {
                while (b[k] < 10) {
                      for (int f = 0; f < 10; f++) {
                          for (int g = 1; g < 6; g++) {
                              if (g == j || g == k) continue;
                              b[g] = f;
                          }
                      temp = get_num(b);
                   //       printf("%d\t", temp);
                      if (!prime[temp]) {
                         num++;
                      }
                    }
                    if (num == 8) {
                        printf("%d\n", temp);
                    }
                    num = 0;
                    b[k]++;
                }
                b[k] = 0;
                b[j]++;
            }
        }
    }
}
    return 0;
}
