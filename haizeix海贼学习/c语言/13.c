/*************************************************************************
	> File Name: 13.c
	> Author: 
	> Mail: mZ	> Created Time: 2018年04月09日 星期一 18时56分49秒
 ************************************************************************/

#include<stdio.h>
int main(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        printf("%d = %s\n", i, argv[i]);
    }


    return 0;
}
