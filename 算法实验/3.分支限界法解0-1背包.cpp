/*************************************************************************
	> File Name: 3.分支限界法解0-1背包.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月05日 星期一 13时51分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define swap(a, b) { \
    __typeof(a) __temp = a; a = b; b = __temp; \
}

typedef struct DataNode {
    double w, v;
    double arg;
} DataNode;

typedef struct HeapNode {
    double up, profit, weight;
    int level;
} HeapNode;

typedef struct Heap {
    HeapNode *data;
    int size;
} Heap;

void initDataNode (DataNode *p, double w, double v) {
    p->w = w;
    p->v = v;
    p->arg = w / v;
}
/*
void heapUpdate (DataNode *p, int pos, int n) {
    int ind = pos;
    int l = pos << 1, r = pos << 1 | 1;
    if (l <= n && p[l].arg > p[ind].arg) ind = l;
    if (r <= n && p[r].arg > p[ind].arg) ind = r;
   // if (ind != pos) {
       // swap()
   // }
}

void heapSort (DataNode *arr, int n) {
    DataNode *p = arr - 1; //让p[1] = arr[0];
    for (int i = n >> 1; i >= 1; i--) {
        update(p, i, n);
    }
}*/

void mergeSort (DataNode *arr, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && arr[l].arg < arr[r].arg) {
            swap(arr[l], arr[r]);
        }
        return ;
    }
    int mid = (r + l) >> 1;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    DataNode *temp = (DataNode *)malloc(sizeof(DataNode) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || p1 <= mid && arr[p1].arg <= arr[p2].arg) {
            temp[k++] = arr[p1++];
        } else {
            temp[k++] = arr[p2++];
        }
    }
    memcpy(arr + l, temp, sizeof(DataNode) * (r - l + 1));
    free(temp);
    return ;
}

Heap *init (int max_len) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->data = (HeapNode *)malloc(sizeof(HeapNode) * max_len);
    heap->size = 0;
    return heap;
}

//void heapPush ()

void outputDataNode (DataNode *p, int len) {
    for (int i = 0; i < len; i++) {
        printf("w = %lf; v = %lf; arg = %lf\n", p[i].w, p[i].v, p[i].arg);
    }
}

void test () {

}

int main() {
    srand(time(0));
    #define MAX_W 100
    #define MAX_V 100
    double w, v;
    DataNode *datanode = (DataNode *)malloc(sizeof(10));
    for (int i = 0; i < 10; i++) {
        w = rand() / (double)(RAND_MAX) / MAX_V + 1;
        v = rand() / (double)(RAND_MAX) / MAX_V;
        initDataNode(&datanode[i], w, v);
    }
    outputDataNode(datanode, 10);
   // mergeSort(datanode, 0, 9);
   // outputDataNode(datanode, 10);

    return 0;
}
