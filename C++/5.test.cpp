/*************************************************************************
	> File Name: 5.test.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年12月27日 星期四 19时57分31秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int f() {
    return 1;
}

int f(int a, int b) {
    return 2;
}

int f(int a, int b, int c) {
    return 3;
}

int main() {
    cout<<f() <<f(1,2) <<f(1,2,3)<<endl;
//    printf("%d, %d, %d\n", f(), f(1,2), f(1,2,3));
    return 0;
}
