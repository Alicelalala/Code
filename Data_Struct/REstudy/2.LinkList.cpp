/*************************************************************************
	> File Name: 2.LinkList.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月12日 星期五 14时50分07秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkList {
    LinkNode head;
    int length;
} LinkList;

LinkList *init () {
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->head.next = NULL;
    p->length = 0;
    return p;
}

LinkNode *getNewNode (int value) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = value;
    p->next = NULL;
}

int insert (LinkList *l, int value, int ind) {
    LinkNode *p = &(l->head);
    while (ind--) {
        p = p->next;
        if (p == NULL) return 0;
    }
    LinkNode *new_node = getNewNode(value);
    new_node->next = p->next;
    p->next = new_node;
    l->length += 1;
    return 1;
}

int erase (LinkList *l, int ind) {
    LinkNode *p = &(l->head);
    while (ind--) {
        p = p->next;
        if (p == NULL) return 0;
    }
    if (p->next == NULL) return 0;
    LinkNode *delete_node = p->next;
    p->next = delete_node->next;
    free(delete_node);
    l->length -= 1;
    return 1;
}

void output (LinkList *l) {
    printf(" [%d] ", l->length);
    LinkNode *p = l->head.next;
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
    return ;
}

void clear (LinkList *l) {
    if (l->head.next == NULL) return;
    LinkNode *p = l->head.next, *q;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    free(l);
    return;
}

int main() {
    LinkList *l = init();
    #define MAX_OP 30
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4, value, ind;
        switch (op) {
            case 0 :
            case 1 :
            case 2 : {
                ind = rand() % (l->length + 3);
                value = rand() % 100;
                printf("insert(%d, %d) to LinkList\n", value, ind);
                insert(l, value, ind);
                output(l);
            } break;
            case 3 : {
                if (l->length == 0) break;
                ind = rand() % (l->length);
                printf("erase(%d) from LinkList\n", ind);
                erase(l, ind);
                output(l);
            } break;
        }
    }
    clear(l);
    return 0;
}
