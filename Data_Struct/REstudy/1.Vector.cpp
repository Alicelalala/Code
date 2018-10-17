/*************************************************************************
	> File Name: 1.Vector.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月12日 星期五 11时59分25秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define DEBUGS_ARG(a, b) #a[0] ? a + 0 : b;
#define init(a) __init(DEBUGS_ARG(a, 10))

typedef struct Vector {
    int *data;
    int length, size;
} Vector;

Vector *__init (int n) {
    Vector *p = (Vector *)malloc(sizeof(Vector));
    p->data = (int *)malloc(sizeof(int) * n);
    p->length = 0;
    p->size = n;
    return p;
}

int expand (Vector *v) {
    printf("[%p] expanding \n", v->data);
    int *p = (int *)realloc(v->data, sizeof(int) * 2 * v->size);
    if (p == NULL) return 0;
    v->data = p;
    v->size *= 2;
    printf("[%p] expand vector success, the new size : %d\n", v->data, v->size);
}

int insert (Vector *v, int value, int ind) {
    if (v->length == v->size) {
        if (expand(v) == 0) {
            return 0;
        }
    }
    if (ind < 0 || ind > v->length) return 0;
    for (int i = v->length - 1; i >= ind; i--) {
        v->data[i + 1] = v->data[i];
    }
    v->data[ind] = value;
    v->length += 1;
    return 0;
}

int erase (Vector *v, int ind) {
    if (ind < 0 || ind >= v->length) return 0;
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
}

void output (Vector *v) {
    printf("Vector = [");
    for (int i = 0; i < v->length; i++) {
        printf("%d ", v->data[i]);
    }
    printf("]\n");
}

void clear(Vector *v) {
    if (v == NULL) return;
    free(v->data);
    free(v);
}

int main() {
    Vector *v = __init(5);
    #define MAX_OP 39
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 5, value, ind;
        switch (op) {
            case 0 :
            case 1 :
            case 2 :
            case 3 : {
                ind = rand() % (v->length + 3) - 1;
                value = rand() % 100;
                printf("[%d] insert(%d, %d) to Vector\n", insert(v, value, ind), value, ind);
                output(v);
            } break;
            case 4 : {
                ind = rand() % (v->length + 3) - 1;
                printf("[%d], erase(%d) from Vector\n", erase(v, ind), ind);
                output(v);
            }
        }
    }
    
    clear(v);
    return 0;
}

