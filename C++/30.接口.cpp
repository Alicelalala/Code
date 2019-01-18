/*************************************************************************
	> File Name: 30.接口.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月16日 星期三 14时40分51秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Interface {
    public:
        virtual bool open() = 0;
        virtual void close() = 0;
        virtual bool send(char *buf, int len);
        virtual int receive(char *buf, int len);
};

