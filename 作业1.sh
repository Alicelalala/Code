#!/bin/bash 

function getdir(){
    for file in `ls -A $1`
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
                #echo $cur_dir
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
    #echo $filename
    string_file=$(cat $filename)
    for line in $string_file
    do
        len=${#line}
	if [[ $len -eq 372 ]] || [[ $len -eq 89 ]] ; then
		echo $1 $line
	elif [[ $len -gt $max_len ]]; then
            max_len=$len
            max_dir=$1
            max_string=$line
        fi 
    done
    #echo $max_len
    #echo $max_dir
}

#read -p "请输入初始路径：" a
getdir /home/caohaiyan
echo "最长字符串长度: " $max_len
echo "路径: " $max_dir
echo $max_string
