/*************************************************************************
	> File Name: 17.struct.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月08日 星期二 18时10分45秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class A {
    //private:
    int a;
    int b;
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
};
struct B {
    //public:
    int a;
    int b;
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
};

int main() {
    A aa;
    B bb;
    bb.a = 10;
    bb.b = 100;
    cout << bb.getA() << endl;
    cout << bb.getB() << endl;
    return 0;
}
