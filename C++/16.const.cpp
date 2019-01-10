/*************************************************************************
	> File Name: 16.const.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月03日 星期四 20时40分43秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Test {
    private:
        int j;
        int i;
        const int m;
    public:
    Test(int v) : m(10) {
        this->i = v;
        this->j = 5;
    }
    void print() const {
        cout << "hello ";
        return ;
    }
    int getI() const {
        cout << "const ";
        print();
        return this->i;
    }
    int getI() {
        cout << "no const ";
        return this->i;
    }
    int getJ() {
        return this->j;
    }
    int getM() {
        return this->m;
    }
    //改变一个const(只读变量的值)，使用const_cast取地址改变
    void setM(int v) {
        int *p = const_cast<int *>(&m);
        *p = v;
        return ;
    }
};

int main() {
    const Test t(1);
    cout << t.getI() << endl;
    Test t2(1);
    cout << t2.getM() << endl;
    t2.setM(100);
    cout << t2.getM() << endl;
    return 0;
}
