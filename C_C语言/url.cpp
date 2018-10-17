/*************************************************************************
	> File Name: url.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年09月24日 星期一 13时27分06秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ctype.h>
using namespace std;

bool legal (char *s) {
    //如果不合法的URL地址返回false
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != '/' && s[i] != '.' && s[i] != '-' && s[i] != '_' && !(isalpha(s[i]) || isdigit(s[i]))) {
            return false;
        }
    }
    return true;
}

bool int_right (string s) {
    //判断一个字符串是全为数字  
    for (int i = 0; i < s.length(); i++)
        if (!isdigit(s[i]))
        return false;
    return true;
}

struct Rule {
    //规则
    vector<string>rule; //存储规则
    string name; //匹配的名字
    bool flag; //规则结尾是否有/,有则为true否则为false 
}r[105];

vector<string>url; //存储输入的url路径
vector<string>para; //存储参数

int n; //规则的个数

void init () {
    //初始化把规则和匹配名存储在向量中
    string tmp;
    char a[110]; //临时字符数组
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s", a); //读入URL规则
        int end = strlen(a);
        if (end > 0 && a[end - 1] == '/') {
            r[pos].flag = true;
        } else {
            r[pos].flag = false;
        }
        cin>>r[pos].name; //读入url匹配名
        char *sp = strtok(a, "/"); //以斜杠分割字符串
        while (sp) {
            r[pos].rule.push_back(sp);
            sp = strtok(NULL, "/");
        }
        pos++;
    }
}

bool postfix; //输入的URL地址的后缀是否有/

void match (char *a) {
    url.clear(); //清空存储URL的向量
    char *sp = strtok(a, "/"); //以/分割字符串，并存储在url向量中
    while (sp) {
        url.push_back(sp);
	    sp = strtok(NULL, "/");
    }
    //匹配 
    for (int i = 0; i < n; i++) {
        //匹配现有的n条规则
        int j, k; //k表示url的段编号
        para.clear(); //清空存储参数的向量
        bool flag = true;
        for (j = 0, k = 0; j < r[i].rule.size() && k < url.size(); j++, k++) {
            //每条规则被分成了r[i].rule.size()段
            string s = r[i].rule[j];
            //情况一
            if (s == "<int>") {
                if (!int_right(url[k])) {
                    //如果它不是数字串的话，匹配失败
                    flag = false;
                    break;
                } else {
                    string str = url[k];
                    for (int t = 0; t < str.length() && str[t] == '0'; t++) 
                    str.erase(t, 1);
                    if (str != "") 
                    para.push_back(str);
                }
            }
            //情况二
            else if (s == "<str>") 
                para.push_back(url[k]);
            //清况三
            else if (s == "<path>") {
                string tmp = url[k++];
                for (; k < url.size(); k++) {
                    tmp = tmp + "/" + url[k];
                }
                if (postfix) {
                    tmp += "/";
                }
                para.push_back(tmp);
            }
            //情况四
            else {
                if (s != url[k]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag && j >= r[i].rule.size() && k >= url.size() && r[i].flag == postfix) {
            cout<<r[i].name;
            for (int ii = 0; ii < para.size(); ii++) {
                cout<<" "<<para[ii];
            }
                cout<<endl;
                return;
        }
    }
    cout<<"404"<<endl;
}

int main() {
    int m;
    string s;
    cin>>n>>m;
    init(); //初始化存储n条url规则
    while (m--) {
        char a[110];
        scanf("%s", a); //读入url地址 
        int end = strlen(a);
        if (end > 0 && a[end - 1] == '/')  
            postfix = true;
        else 
            postfix = false;
        if (!legal(a)) {
            //如果不合法的url地址
            cout<<"404"<<endl;
            continue;
        }
        match(a);
    }
    return 0;
}




