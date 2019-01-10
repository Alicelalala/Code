/*************************************************************************
	> File Name: 21.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月08日 星期二 20时39分41秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using namespace::std;
class Object {
    protected:
        string m_name;
        string m_info;
    public:
    Object() {
        m_name = "Object";
        m_info = "";
    }
    string name() {
        return m_name;
    }
    string info() {
        return m_info;
    }
};
class Point : public Object {
    private:
        int m_x;
        int m_y;
    public:
    Point(int x, int y) {
        m_x = x;
        m_y = y;
        m_name = "Point";
        ostringstream s;
        s << "P(" << m_x << "," << m_y << "y)";
        m_info = s.str();
    }
    int x() {
        return m_x;
    }
    int y() {
        return m_y;
    }
};

class Line : public Object {
    private:
        Point m_p1;
        Point m_p2;
    public:
    Line(Point &p1, Point &p2) : m_p1(0, 0), m_p2(0, 0) {
        m_p1 = p1;
        m_p2 = p2;
        m_name = "Line";
        ostringstream s;
        s << "Line from " << m_p1.info() << " to " << m_p2.info();
        m_info = s.str();
    }
    Point begin() {
        return m_p1;
    }
    Point end() {
        return m_p2;
    }
};

int main() {
    Object o;
    cout << o.name() << endl;
    cout << o.info() << endl;
    Point p1(4, 5);
    Point p2(8, 9);
    cout << p1.name() << " " << p1.info() << endl;
    cout << p2.name() << " " << p2.info() << endl;
    Line l(p1, p2);
    cout << l.name() << " " << l.info() << endl;
    return  0;
}
