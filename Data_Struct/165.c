/*************************************************************************
	> File Name: 165.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月02日 星期三 18时17分45秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int compareVersion(char *version1, char *version2) {
    if (strcmp(version1, version2) == 0) return 0;
    int i = 0, j = 0, temp1, temp2;
    int len1 = strlen(version1), len2 = strlen(version2);
    while (i < len1 && j < len2) {
        temp1 = temp2 = 0;
        while (i < len1 && version1[i] != '.') temp1 += temp1 * 10 + (version1[i++] - '0');
        while (j < len2 && version2[j] != '.') temp2 += temp2 * 10 + (version2[j++] - '0');
        if (temp1 > temp2) return 1;
        if (temp1 < temp2) return -1;
        if (i == len1 || j == len2) break;
        i++;
        j++;
    }

    if (i < len1) {
        while (i < len1 && (version1[i] == '.' || version1[i] == '0')) i++;
    }
    if (j < len2) {
        while (j < len2 && (version1[j] == '.' || version1[j] == '0')) j++;
    }
    if (i == len1 && j == len2) return 0;
    if (i == len1) return -1;
    return 1;
}

int main() {
    char str1[1024], str2[1024];
    scanf("%s%s", str1, str2);
    printf("%d\n", compareVersion(str1, str2));
}
