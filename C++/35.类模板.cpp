/*************************************************************************
	> File Name: 35.类模板.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月18日 星期五 11时35分41秒
 ************************************************************************/

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

template <int N>
void fun() {
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += i;
    }
    cout << sum << endl;
    return ;
}

template <typename T, int N>
class Test {
    private:
        T a[N];
    public:
    Test() {
        for (int i = 0; i < N; i++) {
            a[i] = i + 1;
        }
    }
    void print() {
        for (int i = 0; i < N; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
template <int N> 
class Test<string, t> {
    private:
        string a[N];
    public:
    Test() {
        for (int i = 0; i < N; i++) {
            a[i] = "wrf";
        }
    }
    void print() {
        for (int i = 0; i < N; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    fun<10>();
    Test<int, 10> t;
    t.print();
    return 0;
}
