/*************************************************************************
	> File Name: 6.struct.union.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年10月06日 星期六 09时39分55秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#pragma pack(1)
using namespace std;

struct person {
    char name[20];
    int age;
    char gender;
    float height;
};

struct test {
    char a;
    char b;
    int c;
    double e;
};

struct Number {
    int type; //0->int or 1->double;
    union {
        int num1;
        float num2;
    }N;
};

void print (Number *n) {
    switch (n->type) {
        case 0: printf("%d\n", n->N.num1); break;
        case 1: printf("%f\n", n->N.num2); break;
    }
    return;
}

void set(Number *n, float num) {
    n->type = 1;
    n->N.num2 = num;
}

void set(Number *n, int num) {
    n->type = 0;
    n->N.num1 = num;
}

int main() {
    srand(time(0));
    struct test a;
    printf("sizeof(person) : %d\n", sizeof(struct person));
    printf("%p %p %p %p\n", &a.a, &a.b, &a.c);
    Number arr[100];
    #define MAX_N 20
    for (int i = 0; i < MAX_N; i++) {
        int op = rand() % 2;
        switch (op) {
            case 0: {
                int value = rand() % 100;
                set(arr + i, value);
            } break;
            case 1: {
                float value = (1.0 * (rand() % 10000) / 10000) * 100;
                set(arr + i, value);
            } break;
        }
    }
    for (int i = 0; i < MAX_N; i++) {
        print(arr + i);
    }
    arr[0].N.num2 = 1.0; //float存储形式有关
    printf("arr[0].N.num1 = %d\n", arr[0].N.num1);
    printf("arr[0].N.num1 = %x\n", arr[0].N.num1);
    
    return 0;
}
