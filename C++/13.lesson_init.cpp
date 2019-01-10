/*************************************************************************
	> File Name: 13.lesson_init.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月03日 星期四 18时11分58秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

class Value {
    private:
        int i;
    public:
    Value(int v) : i(v) {
        cout << "Value :: i = " << i << endl;
    }
};

class Test {
    private:
        const int i;
        int a;
        Value vv;
    public:
    //Test(int v);
    Test(int v) : i(v), vv(1) {
        cout << "i = " << i << endl;
    }
    Test(int v1, int v2);
    int getI() {
        return i;
    }
};
/*
Test::Test(int v) : i(v) {
        i = v;
        cout << "i = " << i << endl;
}*/
Test::Test(int v1, int v2) : i(v1), a(v2), vv(1) {
    cout << "i = " << i << endl;
    cout << "a = " << a << endl;
}

int main() {
    Test t(10);
    Test t2(10, 100);
    cout << "t.i = " << t.getI() << endl;
    return 0;
}
