/*************************************************************************
	> File Name: 23.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月10日 星期四 19时02分43秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class A {
    public:
        int i;
    public:
    A(int v = 0) {
        i = v;
    }
    int add() {
        return i + 1;
    }
    int add(int a, int b, int c) {
        return i + a + b + c;
    }
    int getI() {
        cout << "A::i = " << i << endl;
        return i;
    }
    void say() {
        cout << "hello i'm a" << endl;
    }
};
class B : public A {
    public:
        int i;
    public:
    B(int v) : A(0) {
        i = v;
    }
    //子类add()会影藏所有父类名为add的函数
    int add(int a) {
        return i + a;
    }
    int add(int a, int b, int c) {
        return i + a + b + c;
    }
    int getI() {
        cout << "B::i = " << i << endl;
        return i;
    }
    void say() {
        cout << "hello i'm b" << endl;
    }
};

void how_to_say(A *p) {
    p->say();
    return ;
}

int main() {
    B b(3);
    A a(2);
    cout << b.add(4) << endl;
    cout << b.add(1, 2, 3) << endl;
    cout << b.i << endl;
    b.A::i = 4;
    cout << b.A::i << endl; //通过作用域分辨符
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    how_to_say(&a);
    how_to_say(&b);
    return 0;
}
