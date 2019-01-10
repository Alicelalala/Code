/*************************************************************************
	> File Name: 9.init.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月01日 星期二 19时22分18秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class Test {
    private:
        int a, b;
    public:
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
};
Test t1; //全局区初值本身是0
int main() {
    cout << t1.getA() << endl;
    Test t2; //栈区、堆区是初始值
    cout << t2.getA() << endl;
    Test *p = new Test();
    cout << p->getB() << endl;
    return 0;
}
