#include <stdio.h>
#include <stdarg.h>

int max_int(int num,...) {
        int temp;
        int ans = 0;
        int args;
        va_start(args,num);
        while(num--) {
                temp = va_arg(args,num);
                if(temp > ans) {
                        ans = temp;
                }
        }
                return ans;
                va_end;
}
int main() {
        max
       

