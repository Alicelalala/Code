/*************************************************************************
	> File Name: 18.revTest.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月08日 星期二 18时17分03秒
 ************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class Test {
    private:
        int i;
    public:
        Test(int v) {
        Test() {
            Test(100);//临时对象，仅在这一行有用
            i = 0;
            cout <<"Test() i = " << i << endl;
        }
        Test(const Test &t) {
            i = t;
            cout << "Test(const Test &t) : i " << i << endl;
        }
        void printI() {
            cout << "i = " << i << endl;
        }
};
void func1(Test t) {
    return ;
}
int func2() {
    return 100 //Test(100);
}

//应尽量避免临时对象
int main() {
    //Test t;
    //t.printI(); //t输出随机值
    //Test t = Test(100);
    //t.printI();
    //Test t1 = func2();
    //t1.printI();
    Test t2[3] = {Test(1), Test(2), Test(3)};
    Test t3[3] = {1, 2, 3};
    return 0;
}
