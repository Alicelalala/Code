/*************************************************************************
	> File Name: 14.xigou.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月03日 星期四 18时47分37秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class Value {
    private:
        int i;
    public:
    Value(int v) : i(v){
        cout << "Value()" << i << endl;
    }
};

class Test {
    private:
        Value v1;
        Value v2;
        int i;
    public:
    Test() : v1(1), v2(2){
        cout << "hello" << endl;
    }
    Test(int v) : v1(1), v2(2), i(v) {
        cout << "hello" << endl;
    }
    ~Test() {
        cout << "Byebye" << endl;
    }
    int getI() {
        return i;
    }
};

int main() {
    Test t;
    //Test *p = new Test;
    //delete p;
    Test *q = new Test(10);
    delete q;
    return 0;
}
