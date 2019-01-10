/*************************************************************************
	> File Name: 19.继承.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月08日 星期二 19时26分26秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class Mem {
    public:
    Mem() {
        cout << "Mem" << endl;
    }
    ~Mem() {
        cout << "~Mem" << endl;
    }
};
class Disk {
    public:
    Disk() {
        cout << "Disk" << endl;
    }
    ~Disk() {
        cout << "~Disk" << endl;
    }

};
class CPU {
    public:
    CPU() {
        cout << "cpu" << endl;
    }
    ~CPU() {
        cout << "~cpu" << endl;
    }
};
//组合关系
//当前类的对象作为另一个类的属性
class Computer {
    private:
        Mem m;
        Disk d;
        CPU c;
    public:
    Computer() {
        cout << "Computer" << endl;
    }
    void PowerOn() {
        cout << "Power on" << endl;
    }
    ~Computer() {
        cout << "~Computer" << endl;
    }
};

int main() {
    Computer p;
    return 0;
}
