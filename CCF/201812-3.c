/*************************************************************************
	> File Name: 201812-3.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月17日 星期四 12时03分38秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *preip, *suffix;
    struct Node *next;
} Node;

Node *getNewNode(char *pre, char *suf) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->preip = (char *)malloc(sizeof(char) * 50);
    strcpy(node->preip, pre);
    node->suffix = (char *)malloc(sizeof(char) * 50);
    strcpy(node->suffix, suf);
    node->next = NULL;
    return node;
}

int ip_cmp(Node *node, Node *new_node) {
    int n = 3;
    int i = 0, j = 0, x1, x2;
    while (n--) {
        x1 = 0, x2 = 0;
        while (node->preip[i]) {
            if (node->preip[i] == '.') {i++; break;}
            x1 += x1 * 10 + node->preip[i++] - '0';
        }
        while (new_node->preip[j]) {
            if (new_node->preip[j] == '.') {j++; break;}
            x2 += x2 * 10 + new_node->preip[j++] - '0';
        }
        if (x1 > x2) return 1;
        else if (x1 < x2) return -1;
    }
    i = j = x1 = x2 = 0;
    while (node->suffix[i]) {
        x1 += x1 * 10 + node->suffix[i++] - '0';
    }
    while (new_node->suffix[j]) {
        x2 += x2 * 10 + new_node->suffix[j++] - '0';
    }
    if (x1 > x2) return 1;
    else if (x1 < x2) return -1;
    return 0;
}

Node *insert(Node *head, Node *node) {
    if (head == NULL) {
        head = node;
        return head;
    }
    Node *p, *q, ret;
    ret.next = head;
    p = &ret;
    q = p->next;
    while (q && (ip_cmp(q, node)) < 0) {
        p = p->next;
        q = q->next;
    }
    node->next = q;
    p->next = node;
    head = ret.next;
    return head;
}


Node *getStdIP(char *str) {
    char *suffix = (char *)malloc(sizeof(char) * 50);
    char *preip = (char *)malloc(sizeof(char) * 50);
    int pot = 0, virgule = 0, i, k = 0, l = 0;
    for (i = 0; str[i] && str[i] != '/'; i++) {
        if (str[i] == '.') pot++;
        preip[k++] = str[i];
    }
    while (str[i]) {
        if (str[i] == '/') {i++; virgule++; continue;}
        suffix[l++] = str[i++];
    }
    //标准型
    if (pot == 3 && virgule == 1) {
        Node *new_node = getNewNode(preip, suffix);
        return new_node;
    }
    //省略后缀型
    if (virgule == 1) {
        switch (pot) {
            case 0: {strcat(preip, ".0.0.0"); break;}
            case 1: {strcat(preip, ".0.0"); break;}
            case 2: {strcat(preip, ".0"); break;}
            default : break;
        }
        Node *new_node = getNewNode(preip, suffix);
        return new_node;
    }
    //省略长度型
    switch (pot) {
        case 0: {
            strcat(preip, ".0.0.0");
            suffix = "8";
        } break;
        case 1: {
            strcat(str, ".0.0");
            suffix = "16";
        } break;
        case 2: {
            strcat(str, ".0");
            suffix = "24";
        } break;
        case 3: {
            suffix = "32";
        } break;
        default : break;
    }
    Node *new_node = getNewNode(preip, suffix);
    return new_node;
}

int getAtoi(char *str) {
    int x = 0;
    for (int i = 0; str[i]; i++) {
        x += x * 10 + str[i] - '0';
    }
    return x;
}

Node *merge_subset(Node *head) {
    if (head == NULL || head->next == NULL) return head;
    Node *p = head;
    Node *q = head->next;
    int pre_len = 0;
    while (q) {
        pre_len = getAtoi(p->suffix);

    }
}

void output(Node *head) {
    Node *p = head;
    while (p) {
        printf("%s/%s\n", p->preip, p->suffix);
        p = p->next;
    }
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    char ip[50];
    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%s", ip);
        Node *node = getStdIP(ip);
        head = insert(head, node);
    }
    output(head);
    return 0;
}


