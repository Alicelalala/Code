#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include <time.h>

#define TEST_TIME(func) { \
    int begin = clock(); \
    func; \
    int end = clock(); \
    printf("%s costs time is \033[1;32m%lfms\033[0m\n", #func, (end - begin) * 1.0 / CLOCKS_PER_SEC * 1000); \
}

int **lcsLength (char x[], char y[], int **b) {
	int m = strlen(x);
	int n = strlen(y);
	int **c = (int **)malloc(sizeof(int *) * (m + 1));
    for (int i = 0; i <= m; i++) {
        c[i] = (int *)malloc(sizeof(int) * (n + 1));
    }
    for (int i = 0; i <= m; i++) c[i][0] = 0;
    for (int j = 0; j <= n; j++) c[0][j] = 0;
    for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			} else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			} else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;
			}
		}
	}
	return c;
}

void lcsPrintf (int i, int j, char x[], int **b) {
	if (i == 0 || j == 0) return ;
	if (b[i][j] == 1) {
		lcsPrintf(i - 1, j - 1, x, b);
		printf(" \033[1;32m%c\033[0m", x[i - 1]);
	} else if (b[i][j] == 2) {
		lcsPrintf(i - 1, j, x, b);
	} else {
		lcsPrintf(i, j - 1, x, b);
	}
}

void getStr (char *str, int len) {
    int flag, i;
    srand(time(0));
    for (i = 0; i < len; i++) {
        flag = rand() % 3;
        switch (flag) {
            case 0: {
                str[i] = rand() % 26 + 'a';
            } break;
            case 1: {
                str[i] = rand() % 26 + 'A';
            } break;
            case 2: {
                str[i] = rand() % 10 + '0';
            } break;
        }
        printf("%c", str[i]);
    }
    str[i] = '\0'; //必须手动添加一个结束字符，否则可能出现段错误
    printf("\n");
    return ;
}

int main() {
    int n1, n2;
    printf("Please input the length of str1 : ");
    scanf("%d", &n1);
    char buff1[n1] = {0};
    //printf("----------------------------------\n");
    getStr(buff1, n1);
    printf("----------------------------------------------------------\n");
    printf("Please input the length of str2 : ");
    scanf("%d", &n2);
    char buff2[n2] = {0};
    //printf("----------------------------------\n");
    getStr(buff2, n2);
    int **b = (int **)malloc(sizeof(int *) * (n1 + 1));
    for (int i = 0; i <= n1; i++) {
        b[i] = (int *)calloc(n2 + 1, sizeof(int));
    }
    printf("----------------------------------------------------------\n");
	TEST_TIME(lcsLength(buff1, buff2, b));
    printf("The longest common subsequence is : {");
    int begin = clock();
	lcsPrintf(strlen(buff1), strlen(buff2), buff1, b);
    int end = clock();
    printf(" }\n");
    printf("lcsPrintf(strlen(buff1), strlen(buff2), buff1, b) costs tim e is \033[1;32m%lfms\033[0m\n", (end - begin) * 1.0 / CLOCKS_PER_SEC * 1000);
	return 0;
} 
