/*************************************************************************
	> File Name: get_conf_value.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月30日 星期日 11时24分03秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_conf_value (char *pathname, char *key_name, char *value) {
    FILE *fp = NULL;
    char *line = NULL, *substr = NULL;
    size_t len = 0, tmplen = 0;
    ssize_t read;

    if (key_name == NULL || value == NULL) {
        printf("paramer is invaild!\n");
        exit(-1);
    }
    fp = fopen(pathname, "r");
    if (fp == NULL) {
        printf("Open config, file, error!\n");
        exit(-1);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        substr = strstr(line, key_name);
        if (substr == NULL) 
            continue;
        else {
            tmplen = strlen(key_name);
            if (line[tmplen] == '=') {
                strncpy(value, &line[tmplen + 1], (int)read - tmplen);
                tmplen = strlen(value);
                *(value + tmplen - 1) = '\0';
                break;
            }
            else {
                printf("Maybe there is something wrong with config file");
                continue;
            }
        }
    }
    if (substr == NULL) {
        printf("%s not found is config file!\n", key_name);
        fclose(fp);
        exit(-1);
    }
    printf("%s=%s\n", key_name, value);
    free(line);
    fclose(fp);
    return 0;
}

int main() {
    char pathname[100], key_name[100], value[100];
    scanf("%s%s", pathname, key_name);
    get_conf_value(pathname, key_name, value);
    printf("%s", value);
}
