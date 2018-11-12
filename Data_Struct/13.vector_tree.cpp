/*************************************************************************
	> File Name: 13.vector_tree.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月25日 星期四 18时19分23秒
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    char *data;
    int length, size;
} Vector;

Vector *init (int len) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (char *)malloc(sizeof(char) * len);
    v->length = 0;
    v->size = len;
    return v;
}

int expand (Vector *v) {
    char *p = (char *)realloc(v->data, sizeof(char) * v->size * 2);
    if (p == NULL) return 0;
    v->data = p;
    v->size *= 2;
    return 1;
}

void insert (Vector *v, char a) {
    if (v->length >= v->size) {
        printf("expand\n");
        expand(v);
    }
    v->data[v->length] = a;
    v->length++;
}

void output (Vector *v) {
    for (int i = 0; i < v->length; i++) {
        printf("%c ", v->data[i]);
    }
    printf("\n");
}

void output_gyb (Vector *v, int pos) {
    if (pos > v->length) return ;
    printf("%c", v->data[pos - 1]);
    if (pos * 2 <= v->length) {
        printf("(");
    }
    output_gyb(v, pos * 2);
    if (pos * 2 + 1 <= v->length) {
        printf(",");
    }
    output_gyb(v, pos * 2 + 1);
    if (pos * 2 <= v->length) {
        printf(")");
    }
}

int main () {
    Vector *v = init(30);
    char a;
    while (scanf("%c", &a) != EOF) {
        if (a == '$') break;
         //printf("%c", a);
        if (a != ' ') {
         insert(v, a);
        }
    }
    output(v);
    printf("%d\n", v->length);
    output_gyb(v, 1);
    printf("\n");
    return 0;
}
