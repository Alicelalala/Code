/*************************************************************************
	> File Name: 28.异常处理.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月18日 星期五 15时00分52秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    try {
        try {
            throw 'a';
        } catch (int i) {
            cout << "catch(int i)" << i << endl;
            throw i;
        } catch (...) {
            cout << "catch(...)" << endl;
            throw;
        }
    } catch (char c) { 
        cout << "information is : " << c << endl;
    } catch (...) {
        cout << "other exception" << endl;
    }
    cout << "done" << endl;
    return 0;
}
