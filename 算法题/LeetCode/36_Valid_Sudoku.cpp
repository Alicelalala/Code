/*************************************************************************
	> File Name: 36_Valid_Sudoku.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月02日 星期三 15时05分18秒
 ************************************************************************/

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

#define false 0
#define true 1
int isValidSudoku(char **board, int boardRowSize, int boardColSize) {
    int row[9] = {0}, col[9] = {0}, gong[9] = {0};
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            int val = (board[i][j] - '0');
            if (val == -2) continue;
            int ind = i / 3 * 3 + j / 3;
            if (row[i] & (1 << val)) return false;
            if (col[j] & (1 << val)) return false;
            if (gong[ind] & (1 << val)) return false;
            row[i] |= (1 << val);
            col[j] |= (1 << val);
            gong[ind] |= (1 << val);
        }
    }
    return true;
}

 int main() {
    char **m = (char **)malloc(sizeof(char *) * 10);
     for (int i = 0; i < 10; i++) {
         m[i] = (char *)malloc(sizeof(char) * 10);
     }
    strcpy(m[0], "53..7....");
    strcpy(m[1], "6..195...");
    strcpy(m[2], ".98....6.");
    strcpy(m[3], "8...6...3");
    strcpy(m[4], "4..8.3..1");
    strcpy(m[5], "7...2...6");
    strcpy(m[6], ".6....28.");
    strcpy(m[7], "...419..5");
    strcpy(m[8], "....8..79");
    int a = 9;
    printf("%d\n", isValidSudoku(m, a, a));
}
