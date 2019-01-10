/*************************************************************************
	> File Name: 20.继承.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月08日 星期二 19时53分07秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class Father {
    private:
        int i;
    protected: // 可被儿子访问，不可在外界被其他对象访问
        int j;
    public:
    Father() {
        i = 100;
    }
    int get() {
        return i;
    }
    void say() {
        cout << "I'm Father." << endl;
    }
};
class Son : public Father {
    private:
        int age;
    public:
    int getAge() {
        return age;
    }
    int add(int v) {
        //age = v + i;//private i是父亲的私有属性，儿子也不能直接访问
        age = v + j;
        return age;
    }
    public:
    void say() {
        cout << "I'm Son" << endl;
    }
};
void how_to_say(Father *f) {
    f->say();
}
int main() {
    Father f;
    Son s;
    cout << s.getAge() << endl;
    cout << s.get() << endl;
    how_to_say(&f);
    how_to_say(&s);
    return 0;
}
