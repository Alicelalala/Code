/*************************************************************************
	> File Name: 2.AddTwoNum.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月04日 星期五 17时57分37秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode ret;
    p = &ret;
    p->val = 0;
    p->next = NULL;
    while (l1 && l2) {
        int num = (p->val + l1->val + l2->val);
        if(l1->next == NULL && l2->next == NULL && num < 10) {
            p->val = num;
            p->next = NULL; 
            p = &ret;
            return p;
        }
        struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = num / 10;
        q->next = NULL;
        p->val = num % 10;
        p->next = q;
        p = p->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1) {
        int num = p->val + l1->val;
        if (l1->next == NULL && num < 10) {
            p->val = num;
            break;
        }
        struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = num / 10;
        q->next = NULL;
        p->val = num % 10;
        p->next = q;
        p = p->next;
        l1 = l1->next;
    }
    while (l2) {
        int num = p->val + l2->val;
        if (l2->next == NULL && num < 10) {
            p->val = num;
            break;
        }
        struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = num / 10;
        q->next = NULL;
        p->val = num % 10;
        p->next = q;
        p = p->next;
        l2 = l2->next;
    }
    p = &ret;
    return p;
}

struct ListNode* initNode (int val) {
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->val = val;
    l1->next = NULL;
    return l1;
}

int main() {
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = initNode(4);
    l1->next->next = initNode(3);
    l2->val = 5;
    l2->next = initNode(6);
    l2->next->next = initNode(4);
    l = addTwoNumbers(l1, l2);
    while (l) {
        printf("%d->", l->val);
        l = l->next;
    }
    printf("\n");
    return 0;
}
