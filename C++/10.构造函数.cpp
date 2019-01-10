/*************************************************************************
	> File Name: 10.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月01日 星期二 19时49分11秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class Test {
    private:
        int a;
    public:
    Test() {
        //a = 10;
        cout << "Test()" << a << endl;
    }
    Test(int value) {
        a = value;
        cout << "Test(int)" << a << endl;
    }
    int getA() {
        return a;
    }
};

int main() {
    Test t1(1);
    Test t2 = 100;
    Test t3;
    Test t5(); //理解成了声明一个函数
    Test t4[3] = {Test(), Test(2), Test(3)};
    return 0;
}

