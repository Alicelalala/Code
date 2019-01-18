/*************************************************************************
	> File Name: 31.test.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月16日 星期三 14时49分59秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class BaseA {
    public:
    virtual void funcA() {
        cout << "BaseA::funcA" << endl;
    }
};
class BaseB {
    public:
    virtual void funcB() {
        cout << "BaseB::funcB" << endl;
    }
};
class Derived : public BaseA, public BaseB {
    
};


int main() {
    cout << sizeof(Derived) << endl;
    Derived d;
    BaseA *p1 = &d;
    BaseB *p2 = &d;
    p1->funcA();
    p2->funcB();
    BaseB *pb = (BaseB *) p1;//强转不成功
    pb->funcB();
    BaseB *pbb = dynamic_cast<BaseB *> (p1); //强转(继承、虚函数)
    pbb->funcB();
    return 0;
}
