/*************************************************************************
	> File Name: 6.new.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月01日 星期二 18时11分00秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
namespace my_lib {
    int i = 10;
    namespace my_lib1 {
        int i = 100;
    }
}
using namespace my_lib;
using my_lib::i;

int main() {
    /*
     type *name = new type; //申请
     delete name; //收回
     //单个变量的初始化
     type *name = new type(value);
     delete name;
     //申请一堆连续的空间
     type *name = new type[length];
     delete[] name;
     */
    int *p = new int(100);
    cout << *p << endl;
    int *pl = new int[10];
    for (int i = 0; i < 10; i++) {
        pl[i] = i + 1;
    }
    for (int i = 0; i < 10; ++i) {
        cout << i << ":" << pl[i] << endl;
    }
    delete[p];
    delete[] pl;
    return 0;
}
