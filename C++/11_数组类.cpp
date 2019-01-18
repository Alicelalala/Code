/*************************************************************************
	> File Name: 11_数组类.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月18日 星期五 19时05分18秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Array {
    private:
        int m_len;
        int *data;
    public:
    Array(int len = 0) {
        data = new int[len];
        for (int i = 0; i < len; ++i) {
            data[i] = 0;
        }
        m_len = len;
    }
    Array &operator = (const Array &obj) {
        if (this != &obj) {
            int *p = new int[obj.m_len];
            if (p) {
                for (int i = 0; i < obj.m_len; ++i) {
                    p[i] = obj.data[i];
                }
                m_len = obj.m_len;
                delete[] data;
                data = p;
            }
        }
        return *this;
    }
    void set(int index, int value) {
        if (index >= 0 && index < m_len) {
            data[index] = value;
        }
    }
    int get(int index) {
        if (index >= 0 && index < m_len) {
            return data[index];
        }
    }
};

int main() {
    Array a1(5);
    for (int i = 0; i < 5; ++i) {
        a1.set(i, i + 1);
    }
    for (int i = 0; i < 5; ++i) {
        cout << a1.get(i) << " ";
    }
    cout << endl;
    Array a2(10);
    for (int i = 0; i < 10; ++i) {
        a2.set(i, i + 1);
    }
    for (int i = 0; i < 10; ++i) {
        cout << a2.get(i) << " ";
    }
    cout << endl;
    
    return 0;
}
