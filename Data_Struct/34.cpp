/*************************************************************************
	> File Name: 34.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2019年01月13日 星期日 18时08分20秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

void swap(int *a, int *b) {
    int *temp = a;
    *a = *b;
    *b = *temp;
    return ;
}

int main() {
    int n, val;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> val;
        val = (val < 0 || val > n ? 0 : val);
        arr.push_back(val);
    }
    for (int i = 0; i < n; i++) {
        while (arr[i] != i + 1) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            printf("%d\n", i+ 1);
            break;
        }
    }
    return 0;
}
