/*************************************************************************
	> File Name: 12.拷贝构造函数.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月01日 星期二 20时50分24秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//浅拷贝同一地址
//深拷贝物理地址不同，逻辑地址相同
//手动实现一个拷贝构造函数，需要深拷贝
class Test {
    private:
        int a;
        int *p;
    public:
    Test() {
        p = new int(1);
    }
    Test(int value) {
        a = value;
        p = new int(1);
        cout << "Test(int) "  << a << endl;
    }
    Test(const Test &obj) {
        a = obj.a;
        p = new int;
        *p = *obj.p;
    }
};

int main() {
    Test t3;
    Test t1(t3);
    delete &t1;
    delete &t3;
}
