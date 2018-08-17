#!/bin/bash 

function getdir(){
    for file in `ls $1`
    do 
        cur_dir=$1"/"$file
        if [[ -d $cur_dir ]]
        then
            getdir $cur_dir
        elif [[ -f $cur_dir ]] 
        then
            filesize=`ls -l $cur_dir | awk '{print $5}'`
            maxsize=$((1024*1024))
            if [[ $filesize -gt $maxsize ]]; then
                continue
            else 
 #               echo $cur_dir
                get_length $cur_dir
            fi
        else
            continue
        fi 
    done
}
max_len=0
max_dir=""
max_string=""
function get_length(){
    filename=$1
    echo $filename
    string_file=$(cat $filename)
    for line in $string_file
    do
        len=${#line}
        if [[ $len -gt $max_len ]]; then
            max_len=$len
            max_dir=$1
            max_string=$line
        fi 
    done
    #echo $max_len
    #echo $max_dir
}

#var=$(cat /home/caohaiyan/haizeix海贼学习/c语言/1.c)
#echo $var
read -p "请输入路径：" a
getdir $a
echo $max_len
echo $max_dir
echo $max_string
