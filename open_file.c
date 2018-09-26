/*************************************************************************
	> File Name: open_file.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月25日 星期二 19时26分00秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1024
int main() {
    /*int a[10] = {0};
    FILE *fp = fopen("~/Code/3.my_print.c", "r");
    if (fp == NULL) {
        printf("NULL\n");
        return 0;
    }
    char data[500];
    int num_read = fread(data, 1, 500, fp);
        printf("%s\n", data);
    fclose(fp);
    
    return 0;*/
    char file_name[500];  
    memset( file_name,0, sizeof(file_name)   );
    printf("Please Input File Name On Server:   "); 
    scanf("%s", file_name); 
           

    FILE *fp;
    char buffer[2018];
    fp = fopen(file_name, "r");
    while(!feof(fp) ) {
    fread(buffer, 5, 1, fp);
    printf("%s", buffer);
    memset(buffer, 0, sizeof(buffer));
    }
    fclose(fp);
    return 0;
}
