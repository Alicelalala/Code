/*************************************************************************
	> File Name: 36_Valid_Sudoku.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月02日 星期三 15时05分18秒
 ************************************************************************/

 #include <stdio.h>
 #include <string.h>

int row[9][10] = {0};
int col[9][10] = {0};
int box[9][10] = {0};

bool isValidSudoku(char **board, int boardRowSize, int boardColSize) {
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (board[i][j] != '.') {
                row[i][board[i][j]] = 1;
                col[j][board[i][j]] = 1;
                box[j / 3 + i / 3 * 3][board[i][j]] = 1;
            }
        }
    }
    int bit[9][9], k, last;
    for (int i = 0; i < boardRowSize; i++) {
        k = 1;
        for (int j = 0; j < boardColSize; ) {
            last = k;
            if (board[i][j] == '.') {
                while (k <= 9 && (row[i][k] || col[j][k] || box[j / 3 + i / 3 * 3][k]))  k++;
                if (k == 10) {
                    j -= 1;
                    k = last;
                    row[i][k]= 0;
                    col[j][k] = 0;
                    box[j / 3 + i / 3 * 3][k] = 0;
                } else { 
                    bit[i][j] = k;
                    row[i][k] = 1;
                    col[j][k] = 1;
                    box[j / 3 + i / 3 * 3][k] = 1;
                }
            }
        } 
    }
}

 int main() {
     char m[9][9];
     strcpy(m[0], "53..7....");
     strcpy(m[1], "6..195...");
     strcpy(m[2], ".98....6.");
     strcpy(m[3], "8...6...3");
     strcpy(m[4], "4..8.3..1");
     strcpy(m[5], "7...2...6");
     strcpy(m[6], ".6....28.");
     strcpy(m[7], "...419..5");
     strcpy(m[8], "....8..79");

 }
