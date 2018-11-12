/*************************************************************************
	> File Name: 动态规划解0-1背包.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月03日 星期六 19时35分39秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 10000

typedef struct Node {
    int cnt;
    double w, v;
} Node;

Node *init(int max) {
    Node *node = (Node *)malloc(sizeof(Node) * max);
    node->cnt = 1;
    return node;
}

double knapsack (Node *node, double c, Node *p, int *head) {
    int n = node->cnt - 1;
    head[n + 1] = 0;
    p[0].w = 0; p[0].v = 0;
    int left = 0, right = 0, next = 1;
    head[n] = 1;
    for (int i = n; i >= 1; i--) {
        int k = left;
        for (int j = left; j <= right; j++) {
            if (p[j].w + node[i].w > c) break;
            double y = p[j].w + node[i].w, m = p[j].v + node[i].v;
            while (k <= right && p[k].w < y) {
                p[next].w = p[k].w;
                p[next++].v = p[k++].v;
            }
            if (k <= right && p[k].w == y) {
                if (m < p[k].v) m = p[k].v;
                k++;
            }
            if (m > p[next - 1].v) {
                p[next].w = y;
                p[next++].v = m;
            }
            while (k <= right && p[k].v <= p[next - 1].v) k++;
        }
        while (k <= right) {
            p[next].w = p[k].w;
            p[next++].v = p[k++].v;
        }
        left = right + 1;
        right = next - 1;
        head[i - 1] = next;
    }
    return p[next - 1].v;
}

void traceback (Node *node, Node *p, int *head, int *x) {
    int n = node->cnt;
    double j = p[head[0] - 1].w, m = p[head[0] - 1].v;
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
        for (int k = head[i + 1]; k <= head[i] - 1; k++) {
            if (p[k].w + node[i].w == j && p[k].v + node[i].v == m) {
                x[i] = 1;
                j = p[k].w;
                m = p[k].v;
                break;
            }
        }
    }
}

void output (Node *node, int *x) {
    for (int i = 1; i <= node->cnt; i++) {
        if (x[i]) {
            printf("w = %.0lf, v = %.0lf\n", node[i].w, node[i].v);
        }
    }
}

int main() { 
    srand(time(0)); //设置时间种子
    double n, c;
    printf("请输入物品数量和背包容量: ");
    scanf("%lf%lf", &n, &c);
    int num = (int) n + 1;
    Node *node = init(num);
    for (int i = 1; i <= n; i++) {
        node[i].w = (rand() % ((int) c + 2) + 1) * 1.0;
        node[i].v = (rand() % 1000 * + 1) * 1.0;
        //printf("%lf %lf\n", node[i].w, node[i].v);
        node->cnt++;
    }
    int head[num], x[num];
    Node *p = init(n);
    time_t begin = clock();
    double ans = knapsack(node, c, p, head);
    traceback(node, p, head, x);
    time_t end = clock();
    printf("装入背包的物品为:\n");
    output(node, x);
    printf("背包可能存放的最大价值为: \033[1;32m%lf\033[0m\n", ans);
    printf("动态规划解0-1问题消耗的时间为: \033[1;32m%lfms\033[0m\n", (end - begin) * 1.0 / CLOCKS_PER_SEC * 1000);
    return 0;
}
