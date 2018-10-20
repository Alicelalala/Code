#!/bin/bash 

rm -rf dl_pi.log dl_pi1.log
rm -rf pi.txt pi.log
grep -EIHron '[0-9a-zA-Z]+' './' 2>/dev/null | awk -F: -v hname=$(hostname) 'BEGIN{
len1=0;
len2=0;
len3=0;
templen=0;
str1=$0;
str2=$0;
str3=$0;
tempstr=$0;
}
{
if (length($3) > len1) {
    len1=length($3);
    str1=$0;
}
if (len1>len2) {
    templen=len2;
    len2=len1;
    len1=templen;
    tempstr=str2;
    str1=str2;
    str2=tempstr;
}
if (len2>len3) {
    templen=len3;
    len3=len2;
    len2=templen;
    tempstr=str3;
    str3=str2;
    str2=tempstr;
}
}
END{
printf("%d:%s:%s\n%d:%s:%s\n%d:%s:%s\n", len1,hname,str1,len2,hname,str2,len3,hname,str3);
}
'
