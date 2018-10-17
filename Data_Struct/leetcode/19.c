/*************************************************************************
	> File Name: 19.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月14日 星期日 09时31分02秒
 ************************************************************************/

#include <stdio.h>


struct ListNode* removeNthfromEnd(struct ListNode* head, int n) {
    int len = 0;
    struct ListNode *p = head, ret, *q;
    ret.next = head;
    while (p) {
        p = p->next;
        len++;
    }
    p = &ret;
    len -= n;
    while (len--) {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return ret.next;
}

struct ListNode* removeNthfromEnd(struct ListNode* head, int n) {
    struct ListNode ret, *p = &ret, *q = head;
    ret.next = head;
    while (n--) {
        q = q->next;
    }
    while (q) {
        p = p->next;
        q = q->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return ret.next;
}

//83
struct ListNode *deleteDuplicates(struct ListNode *head) {
    struct ListNode *p = head, *q;
    while (p && p->next) {
        if (p->val == p->next->val) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
    return head;
}

