/*************************************************************************
	> File Name: write_Pi_log.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月30日 星期日 15时44分40秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define MAX_AIZE 1024

int write_Pi_log (char *PihealthLog, const char *format, ...) {
    FILE *fp = fopen(PihealthLog, "a");
    char buffer[MAX_AIZE];
    va_list arg;
    va_start(arg, format);
    for (int i = 0; format[i]; i++) {
        switch (format[i]) {
            case '%' : {
                i++;
                switch (format[i]) {
                    case 'd' : {
                        fprintf(fp, format, va_arg(arg, int));
                        //fwrite(stderr, strlen(stderr), 1, fp);
                        break;
                    }
                    case 's' : {
                        fprintf(fp, format, va_arg(arg, char*));
                        break;
                    }
                    default :break;
                }
                break;
            }
            default :break;
        }
    }
    return 0;
}

int main() {
    char filename[100], format[100];
    char buffer[100];
    strcpy(buffer, "axcdd");
    int ans = 100;
    scanf("%s%s", filename, format);
    write_Pi_log(filename, format, buffer);
    //write_Pi_log(filename, format, ans);
    return 0;
}

