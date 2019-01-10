### leetcode

```c
//24
//交换链表两个节点的位置，需要三个指针
ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        struct ListNode *p = head, *q = head->next, *k = head->next->next;
        head = head->next;
        while (1) {
            q->next = p;
            p->next = k;7u
            if (k && k->next) p->next = k->next;
            p = k;
            if (p == NULL || p->next == NULL) break;
            q = p->next;
            k = q->next;
        }
        return head;
```



```c
//202
//数据结构逻辑思想
//９９９９９９９９９　＝　９　×　８１　＝　７２９所以这个规律产生的数一定在729内
//一个数字的下一个数字固定的，像链表一样的，用追击可以确定是否有循环

int get_next (int x) {
    int ret = 0;
    while (x) {
        ret += (x % 10) * (x % 10);
        x /= 10;
    }
    return ret;
}
bool isHappy(int n) { 
    int p = n, q = get_next(get_next(n));
    while (q != 1) {
        p = get_next(p);
        q = get_next(get_next(q));
        if (p == q) return 0;
    }
    return 1;
}
```

```c
//203	
struct ListNode ret, *p = &ret, *q;
	ret.next = head;
while (p->next) {
    if (p->next->val == val) {
		q = p->next;
        p->next = q->next;
        free(q);
    } else {
        p = p->next;
    }
    return ret.next;
}
```

```
//206
	struct ListNode ret, *p = &head,, *q;
	ret.next = NULL;
	while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
	}
	return ret.next;
```

```
//234
	struct ListNode 
```

```
//237
struct ListNode *q = node->next;
node->val = node->next->val;
node->next = nodde->next->next;
free(q);
return ;

```

