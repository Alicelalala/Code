/*************************************************************************
	> File Name: 26.多继承.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月16日 星期三 09时12分38秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class People {
    private:
        string name;
        int age;
    public:
    People(string s1, int v1) : name(s1), age(v1){
        
    }
}

class Teacher : virtual public People {
    public:
    Teacher(string s1, int v1) : People(s1, v1) {

    }
};

class Student : virtual public People {
    public:
    Student(string s1, int v1) : People(s1, v2) {

    }
}
class Doctor : public Teacher, public Student {
    public:
    Doctor(string s1, int v1) : People(s1, v2) {

    }
}

