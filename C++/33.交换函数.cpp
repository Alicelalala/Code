/*************************************************************************
	> File Name: 33.交换函数.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月16日 星期三 15时58分33秒
 ************************************************************************/

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#define SWAP(type, a, b) { \
    type (temp) = (a); \
    (a) = (b); \
    (b) = (temp); \
}

void my_swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void my_swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void my_swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

//函数模板，简洁，安全
template <typename T>
void my_swap1(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

class Test {
    public:
    Test(const Test &t) {

    }
    Test() {
        
    }
};

template <typename T>
void my_sort(T *a, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; ++j) {
            if (a[i] > a[j]) {
                my_swap(a[i], a[j]);
            }
        }
    }
}

template <typename T>
void print(T *a, int len) {
    for (int i = 0; i < len; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    string s1 = "wrf", s2= "cxh";
    int a = 10, b = 20;
    double c = 3.1, d = 4.5;
    SWAP(int, a, b);
    SWAP(double, c, d);
    SWAP(string, s1, s2);
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
    cout << s1 << " " << s2 << endl;
    my_swap(a, b);
    my_swap(c, d);
    my_swap(s1, s2);
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
    cout << s1 << " " << s2 << endl;
    my_swap1(s1, s2);
    cout << s1 << " " << s2 << endl;
    Test t1, t2;
    my_swap1(t1, t2);
    
    int aa[5] = {3, 2, 1, 4, 6};
    double bb[5] = {3.1, 4.1, 1.7, 4.3, 0.2};
    string ss[5] = {"c", "java", "c++", "python", "c#"};
    my_sort(aa, 5);
    print(aa, 5); //print<int>(aa, 5);//显示指定参数类型
    my_sort(bb, 5);
    print(bb, 5);
    my_sort(ss, 5);
    print(ss, 5);
    return 0;
}
