/*************************************************************************
	> File Name: 21.继承方式.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月10日 星期四 18时05分11秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
//错误代码,工程里仅仅用public继承
class Parent {
    private:
        int a;
    public:
        int b;
    void set(int v1, int v2, int v3) {
        a = v1;
        b = v2;
        c = v3;
    }
    protected:
        int c;
};
class Child1 : public Parent {
    public:
    void print() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
    }
};
class Child2 : private Parent {
    public:
    void print() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
    }
};
class Child3 : protected Parent {
    public:
    void print() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
    }
};
class test1.cpp : public Child3 {
    coid set(int v) {
        b = v;
    }
}

int main() {
    
    return 0;
}

