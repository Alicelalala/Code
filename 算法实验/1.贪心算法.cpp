#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define swap(a, b) { \
    __typeof(a) __temp = a; a = b; b = __temp; \
}

typedef struct Node {
	int s, e;
} Node;

void heap_update (Node *p, int pos, int n) {
    int ind = pos;
    int l = pos << 1;
    int r = pos << 1 | 1;
    if (l <= n && p[l].e > p[ind].e) ind = l;
    if (r <= n && p[r].e > p[ind].e) ind = r;
    if (ind != pos) {
        swap(p[ind], p[pos]);
        heap_update(p, ind, n);
    }
}

void heap_sort (Node *arr, int n) {
    Node *p = arr - 1; //让p[1] = arr[0]
    for (int i = n >> 1; i >= 1; i--) {
        heap_update(p, i, n);
    }
    for (int i = n; i > 1; i--) {
        swap(p[i], p[1]);
        heap_update(p, 1, i - 1);
    }
}

int greedySelector (Node *arr, int n, bool *a) {
    if (n == 0) return 0;
	a[0] = true;
	int j = 0;
	int count = 1;
    printf("(%4d,%4d) ", arr[0].s, arr[0].e);
	for (int i = 1; i < n; i++) {
		if (arr[i].s >= arr[j].e) {
			a[i] = true;
			j = i;
            count++;
            printf("(%4d,%4d) ", arr[i].s, arr[i].e);
            if (count % 6 == 0) {
                printf("\n");
            }
		}
		else a[i] = false;
	}
    printf("\n");
	return count;
}

void output (Node *p, int n) {
    for (int i = 0; i < n; i++) {
        if (i % 6 == 0 && i) {
            printf("\n");
        }
        printf("(%4d,%4d) ",p[i].s, p[i].e);
    }
    printf("\n");
}

int main() {
    srand(time(0));  
    //因为要测试不同数据量，所以我就用随机生成起止时间了，
    //实际中应该是依次输入起止时间。
	int n;
    printf("请输入活动总数: ");
	scanf("%d", &n);
	Node *node = (Node *)malloc(sizeof(Node) * (n + 5));
	for (int i = 0; i < n; i++) {
		node[i].s = rand() % (3 * n);
        node[i].e = rand() % (3 * n) + 1 + node[i].s; //结束时间大于开始时间
	}
    //printf("随机生成的起止时间为:\n");
    //output(node, n);
    printf("活动起止时间按结束时间排序后为:\n");
    time_t begin = clock();
	heap_sort(node, n);
    output(node, n);
    bool a[n];
    printf("被安排的活动起止时间为:\n");
    int num = greedySelector(node, n, a);
    time_t end = clock();
    printf("Time: \033[1;32m%lfms\033[0m\n", (end - begin) * 1.0 / CLOCKS_PER_SEC * 1000);
    printf("被安排的活动总数为: \033[1;32m%d\033[0m\n", num);
	return 0;
}
