/*************************************************************************
	> File Name: 25.head.h
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月10日 星期四 20时25分34秒
 ************************************************************************/

typedef void demo;
demo* demo_init(int i, int j);
int getI(demo *pthis);
int getJ(demo *pthis);
int add(demo *pthis, int value);
void free_demo(demo *pthis);

