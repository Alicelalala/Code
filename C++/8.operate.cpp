/*************************************************************************
	> File Name: 8.operate.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月01日 星期二 18时44分55秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class fourOperate {
    public:
    int x, y;
    int addop() {
        return x + y;
    }
    int desop() {
        return x - y;
    }
    int multop() {
        return x * y;
    }
    int chuop() {
        return x / y;
    }
};

int main() {
    fourOperate *test1 = new fourOperate();
    test1->x = 10;
    test1->y = 29;
    cout << test1->x << "+" << test1->y << "=" << test1->addop() << endl;
    cout << test1->x << "-" << test1->y << "=" << test1->desop() << endl;
    cout << test1->x << "*" << test1->y << "=" << test1->multop() << endl;
    cout << test1->x << "/" << test1->y << "=" << test1->chuop() << endl;
    return 0;
}
