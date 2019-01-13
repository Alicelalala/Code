/*************************************************************************
	> File Name: 22.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月10日 星期四 18时19分42秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
//默认的构造方式，只可以掉父类无参的构造函数,或者带默认参数的构造函数
class Parent {
    public:
    Parent() {
        cout << "parent()" << endl;
    }
};
class Child : public Parent {
    public:
    Child() {
        cout << "child()" << endl;
    }
};
class A {
    public:
    A() {
        cout << "A()" << endl;
    }
};
class B : public A {
    public:
    B() {
        cout << "B()" << endl;
    }
};
class C {
    public:
    C() {
        cout << "C()" << endl;
    }
};
class D : public C {
    private:
        B b;
    public: 
    D() {
        cout << "D()" << endl;
    }
};

int main() {
    //Child c;
    D d;
    return 0;
}
