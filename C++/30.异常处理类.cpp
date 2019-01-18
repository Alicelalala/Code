/*************************************************************************
	> File Name: 30.异常处理类.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月18日 星期五 15时19分03秒
 ************************************************************************/

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Base {};
class Exception : public Base {
    private:
        int i;
        string info;
    public:
    Exception(int v1, string s1) {
        int v1;
        info = s1;
    }
    void what() {
        cout << "Exception id is " << v1 << endl;
        cout << "Exception information is " << info <<< endl
    }
};

void myfunc(int i) {

}

int main() {
    int i;
    cin >> i;
    try {
        myfunc(i);
    } catch (Exception &e) {
        cout << "Exception information is " << e << endl;
        e.what();
    } catch (Base &b) {
        cout << "Base Exception" << endl;
    } catch (...) {
        cout << "Other Exception" << endl;
    }
    cout << "done" << endl;
    return 0;
}
