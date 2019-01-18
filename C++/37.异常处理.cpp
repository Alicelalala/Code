/*************************************************************************
	> File Name: 37.异常处理.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月18日 星期五 14时42分49秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    //严格匹配
    try {
        throw 1;
    } catch (char c) {
        cout << "catch(char c)" << c << endl;
    } catch (short s) {
        cout << "catch(short s)" << s << endl;
    } catch (double d) {
        cout << "catch(double d)" << d << endl;
    } catch (int i) {
        cout << "catch(int i)" << i << endl;
    } catch(...) {
        cout << "catch(...)" << endl;
    }
    cout << "finished" << endl;
    return 0;
}
