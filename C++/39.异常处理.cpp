/*************************************************************************
	> File Name: 39.异常处理.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月18日 星期五 15时09分51秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void func(int i) {
    if (i < 10) {
        throw -1;
    } else if (i < 20) {
        throw -2;
    } else if (i < 30) {
        throw -3;
    }
    return ;
}

void myfunc(int i) {
    try {
        func(i);
    } catch (int i) {
        switch(i) {
            case -1 : {
                throw "Run Error";
                break;
            }
            case -2 : {
                throw "Parameter Error";
                break;
            }
            case -3 : {
                throw "Segment fault";
                break;
            }
        }
    }
}

int main() {
    int i;
    cin >> i;
    try {
        myfunc(i);
    } catch (const char *s) {
        cout << "exception information is " << s << endl;
    }
    return 0;
}
