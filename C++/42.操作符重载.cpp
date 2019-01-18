/*************************************************************************
	> File Name: 42.操作符重载.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月18日 星期五 18时35分03秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Complex {
    private:
        int real;
        int imag;
    public:
        Complex();
        Complex(int r, int i);
        Complex(const Complex &obj);
        int getReal() const;
        int getImag() const;
};

Complex Complex::operator+(Complex )

int main() {
    Complex c1(1, 2);


    return 0;
}
