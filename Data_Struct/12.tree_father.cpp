/*************************************************************************
	> File Name: 11.tree_father.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月23日 星期二 19时39分14秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

#define MAX_N 1000
#define MAX_K 20 

struct Edge {
    int v, n;
} g[MAX_N << 1];

int head[MAX_N + 5] = {0}, cnt = 0;

inline void add (int a, int b) {
    g[++cnt].v = b;
    g[cnt].n = head[a];
    head[a] = cnt;
    return ;
}

//gass[i][j] ->　ｉ点往上走２^j步，所能到达的祖先节点的编号
int gas[MAX_N][MAX_K], dep[MAX_N];

void dfs (int u, int father) {
    gas[u][0] = father;
    dep[u] = dep[father] + 1;
    for (int i = 1; i < MAX_K; i++) {
        gas[u][i] = gas[gas[u][i - 1]][i - 1];
    }
    for (int i = head[u]; i; i = g[i].n) {
        if (g[i].v == father) continue;
        dfs(g[i].v, u);
    }
    return ;
}

int lca (int a, int b) {
    if (dep[b] < dep[a]) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int l = dep[b] - dep[a];
    for (int i = 0; i < MAX_K; i++) {
        if ((l & (1 << i))) b = gas[b][i];
    }
    if (a == b) return a;
    for (int i = MAX_K - 1; i >= 0; i--) { //往上跳任意层
        if (gas[a][i] != gas[b][i]) a = gas[a][i], b= gas[b][i];
    }
    return gas[a][0];
}

int main() {
    int n, m, a, b, c;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    int num;
    while (scanf("%d%d%d", &a, &b, &c) != EOF) {
        /*if (loc(a, b) == loc(a, c)) {
            
        } else if (loc(a, b) == loc(b, c)) {
            
        } else {
            
        }*/
        printf("%d %d\n", lca(a, b), dep[a] + dep[b] + dep[c] - lca(a, b) - lca(a, c) - lca(b, c));
    }
    return 0;
}
