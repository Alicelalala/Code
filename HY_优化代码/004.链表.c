/*************************************************************************
	> File Name: 004.链表.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月15日 星期二 21时15分55秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkList {
    LinkNode head;
    int length;
} LinkList;

LinkList *init_linklist() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

LinkNode *getNewNode(int value) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = value;
    p->next = NULL;
    return p;
}

void insert_linklist(LinkList *l, int value, int ind) {
    if (ind < 0 || ind > l->length) return ;
    LinkNode *p = &(l->head);
    while (ind--) {
        p = p->next;
    }
    LinkNode *new_node = getNewNode(value);
    new_node->next = p->next;
    p->next = new_node;
    l->length += 1;
    return ;
}

void erase(LinkList *l, int ind) {
    if (ind < 0 || ind >= l->length) return ;
    LinkNode *p = &(l->head);
    while (ind--) {
        p = p->next;
    }
    LinkNode *delete_node = p->next;
    p->next = p->next->next;
    free(delete_node);
    l->length -= 1;
    return ;
}

void clear_linklist(LinkList *l) {
    if (l->head.next == NULL) return ;
    LinkNode *p = &(l->head), *q;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    free(l);
    return ;
}

void output_linklist(LinkList *l) {
    LinkNode *p = &(l->head);
    printf("[%d] ", l->length);
    p = p->next;
    while (p) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
    return ;
}

int main() {
    LinkList *l = init_linklist();
    for (int i = 0; i < 10; i++) {
        insert_linklist(l, i + 1, i);
    }
    erase(l, 5);
    output_linklist(l);
    clear_linklist(l);
    return 0;
}

