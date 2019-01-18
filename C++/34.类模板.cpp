/*************************************************************************
	> File Name: 34.类模板.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月18日 星期五 09时36分08秒
 ************************************************************************/

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class A {
    private:
        int i;
    public:
    A(int v) {
        i = v;
    }
};
template <typename T>
class Test {
    private:
        T a;
    public:
    Test(T v) {
        a = v;
    }
    T get() {
        return a;
    }
    T add(T b) {
        T ret = a + b;
    }
    T sub(T b) {
        return a - b;
    }
};

int main() {
    Test<int> t(0);
    cout << t.get() << endl;
    cout << t.add(10) << endl;
    string s1 = "wrf";
    string s2 = "haizeix.com";
    Test<string> t1(s1);
    return 0;
}
