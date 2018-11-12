/*************************************************************************
	> File Name: 2.分支限界法解0-1背包.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月05日 星期一 22时49分21秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct BBnode {

};

typedef struct HeapNode {
    BBnode liveNode;
    double up;
    double profit; //节点所相应的价值
    double weight
    int level;
}

typedef struct Heap {
    HeapNode *data;
    int size;
}

void initHeapNode (HeapNode *h, BBnode liveNode, double up, double profit, double weight, int level) {
    h->liveNode = liveNode;
    h->up = up;
    h->profit = profit;
    h->weight = weight;
    h->level = level;
}

Heap *initHeap (int max_len) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->data = (HeapNode *)malloc(sizeof(HeapNode) * max_len);
    heap->size = 0;
}

void double bound (int i) {

}

int main() {
    srand(time(0));
    double w, v;
    for (int i = 0; i < 10; i++) {
        w = rand() / (double)((RAND_MAX) / 30);
        printf("%lf\n", w);
    }

    return 0;
}
