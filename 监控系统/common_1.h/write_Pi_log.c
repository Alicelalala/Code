/*************************************************************************
	> File Name: write_Pi_log.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月01日 星期一 09时33分13秒
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int write_pi_log (char *Pihealthlog, const char *format, ...) {
    va_list arg;
    int done;
    FILE *fp = fopen(Pihealthlog, "a+");

    va_start(arg, format);

    time_t time_log = time(NULL);
    struct tm* tm_log = localtime(&time_log);
    fprintf(fp, "%04d-%02d-%02d %02d:%02d:%02d ", tm_log->tm_year + 1900, tm_log->tm_mon + 1, tm_log->tm_mday, tm_log->tm_hour, tm_log->tm_min, tm_log->tm_sec);

    done = vfprintf(fp, format, arg);
    va_end(arg);

    fflush(fp);
    fclose(fp);
    return done;
}

int main() {
    char *filename = (char *)malloc(1024);
    char *format = (char *)malloc(1024);
    char *host = (char *)malloc(1024);
    scanf("%s%s", filename, format);
    strcpy(host, "192.168.1.137");
    write_pi_log(filename, format, host);
    printf("%s", format);
    free(filename);
    free(format);
    free(host);
    return 0;
}
