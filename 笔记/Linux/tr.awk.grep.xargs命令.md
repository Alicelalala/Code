[TOC]

# tr命令

**tr命令**可以对来自标准输入的字符进行替换、压缩和删除。它可以将一组字符变成另一组字符，经常用来编写优美的单行命令，作用很强大。

### 语法 

```
tr(选项)(参数)
```

### 选项 

```
-c或——complerment：取代所有不属于第一字符集的字符；
-d或——delete：删除所有属于第一字符集的字符；
-s或--squeeze-repeats：把连续重复的字符以单独一个字符表示；
-t或--truncate-set1：先删除第一字符集较第二字符集多出的字符。
```

### 参数 

- 字符集1：指定要转换或删除的原字符集。当执行转换操作时，必须使用参数“字符集2”指定转换的目标字符集。但执行删除操作时，不需要参数“字符集2”；
- 字符集2：指定要转换成的目标字符集。

### 实例 

将输入字符由大写转换为小写：

```
echo "HELLO WORLD" | tr 'A-Z' 'a-z'
hello world
```

空格变换行

```
echo "HELLO WORD" | tr ' ' '\n'
HELLO
WORLD
```

'A-Z' 和 'a-z'都是集合，集合是可以自己制定的，例如：'ABD-}'、'bB.,'、'a-de-h'、'a-c0-9'都属于集合，集合里可以使用'\n'、'\t'，可以可以使用其他ASCII字符。

使用tr删除字符：

```
echo "hello 123 world 456" | tr -d '0-9'
hello  world 
```

将制表符转换为空格：

```
cat text | tr '\t' ' '
```

字符集补集，从输入文本中将不在补集中的所有字符删除：

```
echo aa.,a 1 b#$bb 2 c*/cc 3 ddd 4 | tr -d -c '0-9 \n'
 1  2  3  4
```

此例中，补集中包含了数字0~9、空格和换行符\n，所以没有被删除，其他字符全部被删除了。

用tr压缩字符，可以压缩输入中重复的字符：

```
echo "thissss is      a text linnnnnnne." | tr -s ' sn'
this is a text line.
```

巧妙使用tr做数字相加操作：

```
echo 1 2 3 4 5 6 7 8 9 | xargs -n1 | echo $[ $(tr '\n' '+') 0 ]
```

删除Windows文件“造成”的'^M'字符：

```
cat file | tr -s "\r" "\n" > new_file
或
cat file | tr -d "\r" > new_file
```

**tr可以使用的字符类：**

```
[:alnum:]：字母和数字
[:alpha:]：字母
[:cntrl:]：控制（非打印）字符
[:digit:]：数字
[:graph:]：图形字符
[:lower:]：小写字母
[:print:]：可打印字符
[:punct:]：标点符号
[:space:]：空白字符
[:upper:]：大写字母
[:xdigit:]：十六进制字符
```

使用方式：

```
tr '[:lower:]' '[:upper:]'
```





# awk命令

[AWK命令的用法](https://www.cnblogs.com/saneri/p/5484965.html)

awk是一种可以处理数据、产生格式化报表的语言，功能十分强大。
awk的工作方式是读取数据，将每一行数据视为一条记录（record）每笔记录以字段分隔符分成若干字段，然后输出各个字段的值.

2.awk常用的作用格式：
awk “样式” 文件： 把符合样式的数据行显示出来。
awk { 操作 } 文件： 对每一行都执行{}中的操作。
awk " 样式 { 操作 }" 文件： 对符合样式的数据行，执行{}中的操作.

3.用例：
awk的用法1：

```shell
awk ‘/La/' file #显示含La的行
```



awk的用法2:

```shell
awk -F ":" '{print $1,$2}' /etc/passwd 
#以“：”为分割，显示/etc/passwd每一行的第一和第二个字段。
```



awk的用法3：

```shell
awk '/La/{print $1,$2}' file 
#将含有La关键字的数据行的第一第二个字段显示出来，默认使用空格分割
```



awk的用法4：

```shell
awk -F : '/^r/{print $1}' /etc/passwd #显示以r开头的第一个字段
```



awk的用法5：

```shell
awk -F : '$3>=500{print $1, $3}' /etc/passwd 
#找出￥3这个字段的id大于等于500的行，并显示1,3列
```



awk的用法6：

```shell
awk -F : '$7~"bash"{print $1,$7}' /etc/passwd 
#匹配出$7是bash的行，如果真打印出来，不匹配用 !~
```



awk的用法7：

```shell
awk '{print $NF}' fille
#$NF打印最后一个字段 awk默认以空格分割
```



awk的用法8：

```shell
awk '{print $(NF-2)}' file
#表示从右向左打印第3个字段
```



awk扩展:

实例操作：
[root@localhost]# more awk.txt

NF的用法：

\1. $NF 来打印最后一个字段:

2. $(NF-2):表示从右向左打印每行第二个字段.　　

BEGIN{}区域指示用法：

1.OFS的作用是存储输出字段的分隔符

```shell
awk -F : 'BEGIN{OFS="+++"}/^www/{ print $1 , $2 , $3 , $4 ,$5 }' /etc/passwd  
#www+++x+++500+++500+++
```



2.FS也就是字段分隔符的用法：指定输入分隔符---读取文本时，所使用的字段分隔符.

3.RS表示记录分割符--输入文本信息所使用的换行符

从tomcat日志catalina.out中截取2014-10-13日，在07:00-15:00时间段的日志记录，并保存.

NR :表示打印当前正在处理的输入的行号

常用操作：

取得系统内存大小：

从catalina.out中截取2014-10-13日，在07:00-15:00时间段的日志记录，并保存.

过滤出nginx日志中状态码不是200的请求.

 

统计访问时间大于5mm的URL，并进行排序





# grep命令

**grep**（global search regular expression(RE) and print out the line，全面搜索正则表达式并把行打印出来）是一种强大的文本搜索工具，它能使用正则表达式搜索文本，并把匹配的行打印出来。

### 选项 

```
-a 不要忽略二进制数据。
-A<显示列数> 除了显示符合范本样式的那一行之外，并显示该行之后的内容。
-b 在显示符合范本样式的那一行之外，并显示该行之前的内容。
-c 计算符合范本样式的列数。
-C<显示列数>或-<显示列数>  除了显示符合范本样式的那一列之外，并显示该列之前后的内容。
-d<进行动作> 当指定要查找的是目录而非文件时，必须使用这项参数，否则grep命令将回报信息并停止动作。
-e<范本样式> 指定字符串作为查找文件内容的范本样式。
-E 将范本样式为延伸的普通表示法来使用，意味着使用能使用扩展正则表达式。
-f<范本文件> 指定范本文件，其内容有一个或多个范本样式，让grep查找符合范本条件的文件内容，格式为每一列的范本样式。
-F 将范本样式视为固定字符串的列表。
-G 将范本样式视为普通的表示法来使用。
-h 在显示符合范本样式的那一列之前，不标示该列所属的文件名称。
-H 在显示符合范本样式的那一列之前，标示该列的文件名称。
-i 忽略字符大小写的差别。
-l 列出文件内容符合指定的范本样式的文件名称。
-L 列出文件内容不符合指定的范本样式的文件名称。
-n 在显示符合范本样式的那一列之前，标示出该列的编号。
-q 不显示任何信息。
-R/-r 此参数的效果和指定“-d recurse”参数相同。
-s 不显示错误信息。
-v 反转查找。
-w 只显示全字符合的列。
-x 只显示全列符合的列。
-y 此参数效果跟“-i”相同。
-o 只输出文件中匹配到的部分。
```

## grep命令常见用法 

删除所有换行

```shell
grep -v "^$" file
```

在文件中搜索一个单词，命令会返回一个包含**“match_pattern”**的文本行：

```shell
grep match_pattern file_name
grep "match_pattern" file_name
```

在多个文件中查找：

```shell
grep "match_pattern" file_1 file_2 file_3 ...
```

输出除之外的所有行 **-v** 选项：

```shell
grep -v "match_pattern" file_name
```

标记匹配颜色 **--color=auto** 选项：

```shell
grep "match_pattern" file_name --color=auto
```

使用正则表达式 **-E** 选项：

```shell
grep -E "[1-9]+"
或
egrep "[1-9]+"
```

只输出文件中匹配到的部分 **-o** 选项：

```shell
echo this is a test line. | grep -o -E "[a-z]+\."
line.

echo this is a test line. | egrep -o "[a-z]+\."
line.
```

统计文件或者文本中包含匹配字符串的行数 **-c** 选项：

```shell
grep -c "text" file_name
```

输出包含匹配字符串的行数 **-n** 选项：

```shell
grep "text" -n file_name
或
cat file_name | grep "text" -n

#多个文件
grep "text" -n file_1 file_2
```

打印样式匹配所位于的字符或字节偏移：

```shell
echo gun is not unix | grep -b -o "not"
7:not

#一行中字符串的字符便宜是从该行的第一个字符开始计算，起始值为0。选项 -b -o 一般总是配合使用。
```

搜索多个文件并查找匹配文本在哪些文件中：

```shell
grep -l "text" file1 file2 file3...
```

### grep递归搜索文件 

在多级目录中对文本进行递归搜索：

```shell
grep "text" . -r -n
# .表示当前目录。
```

忽略匹配样式中的字符大小写：

```shell
echo "hello world" | grep -i "HELLO"
hello
```

选项 **-e** 制动多个匹配样式：

```shell
echo this is a text line | grep -e "is" -e "line" -o
is
line

#也可以使用-f选项来匹配多个样式，在样式文件中逐行写出需要匹配的字符。
cat patfile
aaa
bbb

echo aaa bbb ccc ddd eee | grep -f patfile -o
```

在grep搜索结果中包括或者排除指定文件：

```shell
#只在目录中所有的.php和.html文件中递归搜索字符"main()"
grep "main()" . -r --include *.{php,html}

#在搜索结果中排除所有README文件
grep "main()" . -r --exclude "README"

#在搜索结果中排除filelist文件列表里的文件
grep "main()" . -r --exclude-from filelist
```

使用0值字节后缀的grep与[xargs](http://man.linuxde.net/xargs)：

```shell
#测试文件：
echo "aaa" > file1
echo "bbb" > file2
echo "aaa" > file3

grep "aaa" file* -lZ | xargs -0 rm

#执行后会删除file1和file3，grep输出用-Z选项来指定以0值字节作为终结符文件名（\0），xargs -0 读取输入并用0值字节终结符分隔文件名，然后删除匹配文件，-Z通常和-l结合使用。
```

grep静默输出：

```shell
grep -q "test" filename

#不会输出任何信息，如果命令运行成功返回0，失败则返回非0值。一般用于条件测试。
```

打印出匹配文本之前或者之后的行：

```shell
#显示匹配某个结果之后的3行，使用 -A 选项：
seq 10 | grep "5" -A 3
5
6
7
8

#显示匹配某个结果之前的3行，使用 -B 选项：
seq 10 | grep "5" -B 3
2
3
4
5

#显示匹配某个结果的前三行和后三行，使用 -C 选项：
seq 10 | grep "5" -C 3
2
3
4
5
6
7
8

#如果匹配结果有多个，会用“--”作为各匹配结果之间的分隔符：
echo -e "a\nb\nc\na\nb\nc" | grep a -A 1
a
b
--
a
b
```





# xargs命令

**xargs命令**是给其他命令传递参数的一个过滤器，也是组合多个命令的一个工具。它擅长将标准输入数据转换成命令行参数，xargs能够处理管道或者stdin并将其转换成特定命令的命令参数。xargs也可以将单行或多行文本输入转换为其他格式，例如多行变单行，单行变多行。xargs的默认命令是[echo](http://man.linuxde.net/echo)，空格是默认定界符。这意味着通过管道传递给xargs的输入将会包含换行和空白，不过通过xargs的处理，换行和空白将被空格取代。xargs是构建单行命令的重要组件之一。

### xargs命令用法 

xargs用作替换工具，读取输入数据重新格式化后输出。

定义一个测试文件，内有多行文本数据：

```shell
cat test.txt

a b c d e f g
h i j k l m n
o p q
r s t
u v w x y z
```

多行输入单行输出：

```shell
cat test.txt | xargs

a b c d e f g h i j k l m n o p q r s t u v w x y z
```

**-n选项**多行输出：

```shell
cat test.txt | xargs -n3

a b c
d e f
g h i
j k l
m n o
p q r
s t u
v w x
y z
```

**-d选项**可以自定义一个定界符：

```shell
echo "nameXnameXnameXname" | xargs -dX

name name name name
```

结合**-n选项**使用：

```shell
echo "nameXnameXnameXname" | xargs -dX -n2

name name
name name
```

**读取stdin，将格式化后的参数传递给命令**

假设一个命令为 sk.sh 和一个保存参数的文件arg.txt：

```shell
#!/bin/bash
#sk.sh命令内容，打印出所有参数。

echo $*
```

arg.txt文件内容：

```shell
cat arg.txt

aaa
bbb
ccc
```

xargs的一个**选项-I**，使用-I指定一个替换字符串{}，这个字符串在xargs扩展时会被替换掉，当-I与xargs结合使用，每一个参数命令都会被执行一次：

```shell
cat arg.txt | xargs -I {} ./sk.sh -p {} -l

-p aaa -l
-p bbb -l
-p ccc -l
```

复制所有图片文件到 /data/images 目录下：

```shell
ls *.jpg | xargs -n1 -I cp {} /data/images
```

**xargs结合find使用**

用[rm](http://man.linuxde.net/rm) 删除太多的文件时候，可能得到一个错误信息：/bin/rm Argument list too long. 用xargs去避免这个问题：

```shell
find . -type f -name "*.log" -print0 | xargs -0 rm -f
```

xargs -0将\0作为定界符。

统计一个源代码目录中所有[php](http://man.linuxde.net/php)文件的行数：

```shell
find . -type f -name "*.php" -print0 | xargs -0 wc -l
```

查找所有的jpg 文件，并且压缩它们：

```shell
find . -type f -name "*.jpg" -print | xargs tar -czvf images.tar.gz
```

**xargs其他应用**

假如你有一个文件包含了很多你希望下载的URL，你能够使用xargs下载所有链接：

```shell
cat url-list.txt | xargs wget -c
```

### 子Shell（Subshells） 

运行一个shell脚本时会启动另一个命令解释器.，就好像你的命令是在命令行提示下被解释的一样，类似于批处理文件里的一系列命令。每个shell脚本有效地运行在父shell(parent shell)的一个子进程里。这个父shell是指在一个控制终端或在一个xterm窗口中给你命令指示符的进程。

```shell
cmd1 | ( cmd2; cmd3; cmd4 ) | cmd5
```

如果cmd2 是[cd](http://man.linuxde.net/cd) /，那么就会改变子Shell的工作目录，这种改变只是局限于子shell内部，cmd5则完全不知道工作目录发生的变化。子shell是嵌在圆括号()内部的命令序列，子Shell内部定义的变量为局部变量。

子shell可用于为一组命令设定临时的环境变量：

```shell
COMMAND1
COMMAND2
COMMAND3
(
  IFS=:
  PATH=/bin
  unset TERMINFO
  set -C
  shift 5
  COMMAND4
  COMMAND5
  exit 3 # 只是从子shell退出。
)
# 父shell不受影响，变量值没有更改。
COMMAND6
COMMAND7
```