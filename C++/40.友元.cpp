/*************************************************************************
	> File Name: 40.友元.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月18日 星期五 16时07分01秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Test {
    private:
        int i;
    public:
    Test(int v = 0) {
        i = v;
    }
    friend int get(Test &t);
};

int get(Test &t) {
    return t.i;
}

class C {
    private:
        int c;
    public:
    C(int v = 0) {
        c = v;
    }
    friend class B;
};

class B {
    private:
        int b;
    public:
    B(int v = 0) {
        b = v;
    } 
    int getC(B &c1) {
        return c1.c;
    }
    friend class A;
};

class A {
    public:
    int getB(B &b) {
        return b.b
    }
};

int main() {
    Test t(10);
    cout << get(t) << endl;
    C c(10);
    B b(5);
    A a;
    cout << a.getB(b) << endl;
    return 0;
}

