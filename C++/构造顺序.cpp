/*************************************************************************
	> File Name: 构造顺序.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月03日 星期四 19时40分03秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Test {
    private:
        int i;
        Value v1;
    public:
    Test(int v) : v1(1), i(v) {
        cout << "i = " << i << endl;
    }
}
