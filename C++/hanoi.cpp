#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void hanta (int n, char *a, char *b, char *c) {
    if (n == 0) return ;
    hanta(n - 1, a, c, b);
    cout << *a << "-->" << *c << endl;
    hanta(n - 1, b, a, c);
}

int main () {
    int n;
    cin >> n;
    char a = 'A', b = 'B', c = 'C';
    hanta(n, &a, &b, &c);
    return 0;
}
