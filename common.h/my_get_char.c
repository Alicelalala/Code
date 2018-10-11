/*************************************************************************
	> File Name: get_char.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月30日 星期日 10时12分42秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

void get_char (char *filename, char *name, char *buf) {
    FILE *fp = fopen(filename, "r");
    char line[MAX_SIZE];
    int n = 0;
    while (fgets(line, MAX_SIZE, fp) != NULL) {
        if (strstr(line, name) == NULL) continue;
        int loc = strlen(name);
        if (line[loc] != '=') continue;
        int len = strlen(line);
        strncpy(buf, line + loc + 1, len - loc - 1);
        buf[len - loc - 1] = '\0';
        break;
    }
    fclose(fp);
    
}

int main() {
    char filename[50], name[50];
    char buf[MAX_SIZE];
    scanf("%s%s", filename, name);
    get_char(filename, name, buf);
    printf("%s", buf);
    return 0;
}
