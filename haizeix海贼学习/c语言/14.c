/*************************************************************************
	> File Name: 14.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月11日 星期三 19时43分15秒
 ************************************************************************/

#include<stdio.h>
int main() {
    char a[] = "hello world haizei";
    char b[20] = {0};
    int offset = 0;

    while (sscanf(a + offset, "%s", b) != EOF) {
        int read = printf("%s\n", b);
        offset += read;
        
    }

    return 0;
}
