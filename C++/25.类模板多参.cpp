/*************************************************************************
	> File Name: 25.类模板多参.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月18日 星期五 10时40分58秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template <typename T1, typename T2>
class Test {
    public:
    void add(T1 a, T2 b) {
        
    }
};

//部分特化(偏特化)
template <typename T>
class Test<T, T> {
    public:
    void add(T a, T b) {
        
    }
    void print() {
        cout << endl;
    }
};
//完全特化
template <>
class Test<int, int> {
    
};

template <typename T>
bool equal(T a, T b) {
    cout << "bool equal(T a, T )" << endl;
    return a == b;
}

template < >
bool equal<double> (double a, double b) {
    cout << "bool equal<double>(double a, double b)" << endl;
    const double x = 0.0000001;
    double ret = a - b;
    return ((ret > -x) && (ret < x));
}

int main() {
    Test<int, double> t;
    t.add(1, 3.9);
    int a = 1, b = 2;
    cout << equal(a, b) << endl;
    cout << equal(3.2,3.2) << endl;
    return 0;
}
