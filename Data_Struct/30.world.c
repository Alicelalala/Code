/*************************************************************************
	> File Name: 31.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月06日 星期日 16时49分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct DATNode {
    int base, check;
} DATNode;
DATNode trie[500];

void dfs(int ind, int k, char *str) {
    if (trie[ind].check < 0) {
        printf("%s\n", str);
    }
    for (int i = 0; i < 26; i++) {
        int check = abs(trie[trie[ind].base + i].check);
        if (check - ind == 0 && trie[ind].base + i != check) {
            str[k] = 'a' + i;
            str[k + 1] = '\0';
            dfs(trie[ind].base + i, k + 1, str);
        }
    }
    return ;
}

int main() {
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) != EOF) {
        trie[a].base = b;
        trie[a].check = c;
    }
    char str[100];
    dfs(1, 0, str);
}
