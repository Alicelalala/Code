/*************************************************************************
	> File Name: 7.classTest.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月01日 星期二 18时34分04秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class Test {
    private:
        int i;
        int j;
    public:
        int a;
        int getI() {
            return i;
        }
        int getJ() {
            return j;
        }
        int getA() {
            return a;
        }
        void setI(int value) {
            i = value;
            return;
        }
};

int main() {
    Test t;
    Test *t1 = new Test;
    t.a = 5;
    t1->a = 10;
    cout << t.a << " " << t1->a << endl;
    return 0;
}
