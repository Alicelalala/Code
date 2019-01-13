/*************************************************************************
	> File Name: 24.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月10日 星期四 20时02分12秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
class Test {
    private:
        int i;
        int j;
    public:
    Test(int v1 = 0, int v2 = 0) {
        i = v1;
        j = v2;
    }
    int getI() {
        return i;
    }
    int getJ() {
        return j;
    }
    int add(int value) {
        return i + j + value;
    }
    ~Test() {
        
    }
};
//class是一种特殊的struct，运行时退化成struct
class A {
    int a;
    int b;
    char c;
    double d;
    public:
    void print() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;
    }
};
struct B {
    int a;
    int b;
    char c;
    double d;
};
int main() {
    Test t(1, 3);
    cout << t.getI() << " " << t.getJ() << endl;
    cout << t.add(10) << endl;
    A a;
    B b;
    cout << sizeof(a) << " " << sizeof(b) << endl;
    a.print();
    B *p = reinterpret_cast<B *> (&a);
    p->a = 100;
    p->b = 1000;
    p->c = 'c';
    p->d = 3.2;
    a.print();
    return 0;
}
