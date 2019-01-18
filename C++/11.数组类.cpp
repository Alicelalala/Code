/*************************************************************************
	> File Name: 11.数组类.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月01日 星期二 20时14分45秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Arry {
    private:
    int *arr;
    int len;
    public:
    Arry(int ans) {
        len = ans;
        arr = new int[len];
    }
    int getlength() {
        return len;
    }
    int getvalue(int index) {
        return arr[index];
    }
    void alter(int index, int value) {
        if (index < 0 || index >= len) return ;
        arr[index] = value;
    }
};

int main() {
    Arry arr1(10);
    cout << arr1.getlength() << endl;
    arr1.alter(0, 5);
    cout << arr1.getvalue(0) << endl;
    return 0;
}
