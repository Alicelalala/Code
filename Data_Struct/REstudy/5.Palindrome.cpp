/*************************************************************************
	> File Name: 5.Palindrome.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月13日 星期六 17时31分10秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkedList;

void output(LinkedList );

bool isPalindrome(Node *head) {
    Node *p = head, *q, *ret;
    ret = NULL;
    int ans = 0;
    while (p) {
        p = p->next;
        ans++;
    }
    ans /= 2;
    p = head;
    while (ans--) {
        p = p->next;
    }
    for (p; p; p = q) {
        q = p->next;
        p->next = ret;
        ret = p;
    }
    p = head;
    q = ret;
    output(p);
    while (p) {
        if (p->data != q->data) return 0;
        p = p->next;
        q = q->next;        
    }
        return 1;  
}
LinkedList insert(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
        printf("failed\n");
        return head;           
    }
        head = node;
        printf("success\n");
        return head;       
    }
        
    if (index == 0) {
        node -> next = head;
        head = node;
        printf("success\n");
        return head;   
    }
        
    Node *current_node = head;
    int count = 0;
    while (current_node -> next != NULL && count < index - 1) {
        current_node = current_node -> next;
        count++;       
    }
       
    if (count != index - 1) {
        printf("failed\n");
        return head;       
    }
    node -> next = current_node -> next;
    current_node -> next = node;
    printf("success\n");
    return head;
}

void output(LinkedList head) {
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d", current_node -> data);
        if (current_node -> next != NULL) {
            printf(" ");            
        }
        current_node = current_node -> next;      
    }
    printf("\n");
}

void clear(LinkedList head) {
    Node *current_node = head;
    while (current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node -> next;
        free(delete_node);    
    }
}

int main() {
    LinkedList linkedlist = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int p, q;
        scanf("%d", &q);
        Node *node = (Node *) malloc (sizeof(Node));
        node -> data = q;
        node -> next = NULL;
        linkedlist = insert(linkedlist, node, i);  
    }
    printf("%d", isPalindrome(linkedlist));
    //output(linkedlist);
    clear(linkedlist);
    return 0;
}

