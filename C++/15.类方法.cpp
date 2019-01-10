/*************************************************************************
	> File Name: 15.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月03日 星期四 19时49分16秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class Test {
    private:
        int m;
        static int cnt; //static 静态成员变量, 类似于全局变量用法
    public:
    Test() : m(5) {
        cnt++;
    }
    static int getCnt() {
        return cnt;
    }
    ~Test() {
        cnt -= 1;
    }
    Test *getP() {
        return this;
    }
    int getM() {
        return this->m;
    }
};

int Test::cnt = 0; //static初始化在类外面

int main() {
    cout << Test::getCnt() << endl;
    Test t1;
    cout << "getM() " << t1.getM() << endl;
    Test t2;
    Test t3;
    cout << t1.getCnt() << endl;
    cout << t2.getCnt() << endl;
    cout << t3.getCnt() << endl;
    Test *p = new Test();
    cout << Test::getCnt() << endl;
    delete p;
    cout << Test::getCnt() << endl;
    return 0;
}
