/*************************************************************************
	> File Name: 36.异常处理.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月18日 星期五 14时24分58秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

double div(double a, double b) {
    const double x = 0.00000000001;
    double ret = 0.0;
    if (!((b > -x) && (b < x))) {
        ret = a / b;
    } else {
        throw 5;
    }
    return ret;
}

int main() {
    cout << div(1.0, 0.5) << endl;
    try {
        div(1.0, 0.0);
    } catch (int i) {
        cout << "b is zero !" << endl;
        cout << "catch(int i) : i = " << i << endl;
    }
    cout << "excption is dealed" << endl;
    return 0;
}
