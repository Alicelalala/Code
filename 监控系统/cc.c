/*************************************************************************
	> File Name: cc.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月13日 星期四 18时45分23秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_message_filename (int bit, char *filename) {
            switch (bit) {
                case 100: {
                    sprintf(filename, "/home/caohaiyan/shell/cpu.log");
                } break;
                case 101: {
                    sprintf(filename, "/home/caohaiyan/shell/mem.log");
                } break;
                case 102: {
                    sprintf(filename, "/home/caohaiyan/shell/disk.log");
                } break;
                case 103: {
                    sprintf(filename, "/home/caohaiyan/shell/sysinfo.log");
                } break;
                case 104: {
                    sprintf(filename, "/home/caohaiyan/shell/user.log");
                } break;
                case 105: {
                    sprintf(filename, "/home/caohaiyan/shell/proc.log");
                } break;
                default : {
                    printf("bit error\n");
                    return 0;
                }
            }
    return 1;
}

int main() {
    int bit;
    char *filename = (char *)malloc(sizeof(char) * 100);
    //memset(filename, 0, sizeof(filename));
    bit = 100;
        get_message_filename(bit, filename);
        #define MAX_N 200
        char *buffer = (char *)malloc(sizeof(char) * MAX_N);
        memset(buffer, 0, sizeof(buffer));
        printf("%s\n", filename);
        FILE *fr;
        fr = fopen("./0.log", "r");
        if (fr == NULL) printf("fopen error\n");
        while (!feof(fr)) {
            fread(buffer, 4, 1, fr);
            printf("%s", buffer);
            memset(buffer, 0, sizeof(buffer));
        }
        fclose(fr);
            fr = NULL;
    free(buffer);
    free(fr);
    free(filename);

    return 0;
}
