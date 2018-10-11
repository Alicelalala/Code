/*************************************************************************
	> File Name: open_file.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月25日 星期二 19时26分00秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char file_name[500];  
    memset( file_name,0, sizeof(file_name)   );
    printf("Please Input File Name On Server:   "); 
    scanf("%s", file_name); 
      

    FILE *fp, *fw;
    char buffer[2018];
    fp = fopen(file_name, "r");
    fw = fopen("write", "w");
    while(!feof(fp)) {
        fread(buffer, 5, 1, fp);
        char str[2018];
        strcpy(str ,buffer);
      //  fputs(str, fw);
        fwrite(str, strlen(str), 1, fw);
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    fclose(fp);
    fclose(fw);

    fp = popen("~/shell/disk.sh", "r");
    while (!feof(fp)) {
        fread(buffer, 5, 1, fp);
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    return 0;
}
