/*************************************************************************
	> File Name: 36.leet.28.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月13日 星期日 18时55分26秒
 ************************************************************************/

#include <stdio.h>

int strStr(char *haystack, char *needle) {
    int len = 0;
    int pos[256] = {0};
    memset(pos, -1, sizeof(pos));
    for (; needle[len]; len++) pos[needle[len]] = len;
    int i = 0, len2 = strlen(haystack);
    while (i + len < len2) {
        int j = 0;
        while (needle[j] && needle[j] == haystack[i + j]) ++j;
        if (needle[j] == 0) return i;
        i += (len - pos[haystack[i + len]]);
    }
    return 
}

//36
bool isValidSudoku(char **board, int boardRowSize, int boardColSize) {
    int row[9] = {0}, col[9] = {0}, gong[9] = {0};
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            int val;
            if ((val == board[i][j] - '0') == -2) continue;
            int ind = i / 3 * 3 + j / 3;
            if (row[i] & (1 << val)) return false;
            if (col[j] & (1 << val)) return false;
            if (gang[ind] & (1 << val)) return false;
            row[i] |= (1 << val);
            col[j] |= (1 << val);
            gong[ind] |= (1 << val);
        }
    }
    return true;
}

//58
int lengthOfLastWord(char *s) {
    int len = strlen(s);
    int i = len - 1, ans = 0;
    while (str[i] == ' ') --i;
    while (i)
}
//125
//
bool is_valid (char c) {
    return (c <= 'Z' && c >= 'A') || (c >= 'a' && c <= 'z') 
    || (c >= '0' && c <= '9');
}

bool isPalindrome(char *s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        while (i < j && is_valid(s[i])) ++i;
        while (i < j  && !is_valid(s[i])) --j
        if (s[i] <= 'Z' && s[i] >= 'A') s[i] += 32;
        if (s[j] <= 'Z' && s[j] >= 'A') s[j] += 32;
        if (s[i] != s[j]) return false;
        ++i;
        --j;
    }
}

//165
//两个数组一一映射

//242
bool is () {
    int len1 = 0, len2 = 0;
    int cnt1[128] = {0};
    int cnt2[128] = {0};
    for (int len = 0; s[len]; ++len) cnt1[s[len]] += 1;
    for (int len = 0; s[len]; ++len) cnt2[s[len]] += 1;
    return (memcmp(cnt1, cnt2, sizeof(int) * 128) == 0); 
}
//290
//hash表映射

//245 两个指针，一个从前一个从后， 扫到交换

//283

//387
//
