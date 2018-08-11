#include <stdio.h>
int main() {
        freopen("/dev/null","w",stderr);
        char str[1000];
        while(scanf("%[^\n]s",str) != EOF) {
                getchar();
                printf("%d", fprintf(stdout,"%s",str));
        }
        return 0;
}
