/*************************************************************************
	> File Name: define.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月23日 星期日 11时38分26秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

#define Q printf("%s %s\n", __DATE__, __TIME__)
#ifdef DEBUG
#define P printf("%s : %d\n", __func__, __LINE__)
#else
#define P
#endif
void testfunction() {
    P;
}

int main() {
    Q;
    P;
    testfunction();
    return 0;
}
