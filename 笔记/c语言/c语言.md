# c语言

### 分支预测

```c
#define likely(x) __builtin_expect(!!(x), 1) //gcc内置函数，帮助编译器分之优化
#define unlikely(x) __builtin_expect(!!(x), 0) 

int main() {
    if (unlikely(x == 3)) {  //告诉编译器这个分支非常不可能为真，所以先判断else的情况
        
    }
}
```

### 函数

1. c语言函数的一种定义（少用）（仅在gcc编译环境下可使用）

```c
int is_prime(x)
int x;
{
    for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)  return 0;
	}
	return 1;
}
```

2.递归

```
：一种编程技巧
```

3.gcd(a, b)

```
//证明gcd(a, b) = gcd(b, a%b)
gcd(a, b) = c;
a = x * c
b = y * c
gcd(x, y) = 1;
a % b = a - k * b = (x - y * k) * c
b = y * c
if gcd(y, x-y*k) = b
y = mb
x - y*k = nb
x = y*k + nb = mb*k + nb
so gcd(x, y) != 1
so gcd(y, x-y*k) = 1;
so gcd(a, b) = gcd(b, a%b) = c;
而且因为gcd(x, y) = 1;
所以c是最大公约数
```

4.变参函数

```
//可变参数
int max_int (int a, ...);
va_list //a往后参数列表
va_start //a后面第一个参数位置
va_arg //
va_end
```

![1537443065455](/tmp/1537443065455.png)

