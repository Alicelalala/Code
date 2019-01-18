/*************************************************************************
	> File Name: 27.多态.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月16日 星期三 09时30分27秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Parent {
    public:
    void say() {
        cout << "I'm Parent" << endll;
    }
};
void how_to_say(Parent *p) {
    p->say();
};

int main() {
    Parent *p;
    Child c;
    how_to_say(&p);
    how_to_say()
    return 0;
}
