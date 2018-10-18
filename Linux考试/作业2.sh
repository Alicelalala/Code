#!/bin/bash 

OLDIFS=$IFS
IFS=$'\n'
a=(rmvb png img jpg jpeg gif md avi zip tar gz 7z o vim)
function getdir(){
    for file in `ls -A $1`
    do 
        suffix=`echo $file | awk -F. '{print $NF}'`
        echo ${a[*]} | grep "$suffix" >/dev/null 
        if [[ $? -ne 0 ]]; then 
            cur_dir=$1"/"$file
            if [[ -d $cur_dir ]]
            then
                getdir $cur_dir
            else
                #echo $cur_dir 
                file $cur_dir | grep "exec">/dev/null 
                if [[ $? -eq 0 ]]; then 
                    echo $cur_dir>/dev/null  
                else 
                    #echo $cur_dir
                    get_length $cur_dir
                fi 
            fi
        fi 
    done
}
max_len=(0 0 0)
function get_length(){
    string_file=$(cat $1)
    for line in $string_file
    do
        len=${#line}
	echo $line | grep [^0-9a-zA-Z]>/dev/null
	if [[ $? -ne 0 ]]; then
	    if [[ $len -gt ${max_len[0]} ]]; then
            	if [[ ${max_len[0]} -gt ${max_len[1]} ]]; then
                if [[ ${max_len[1]} -gt ${max_len[2]} ]]; then
                    max_len[2]=${max_len[1]}
                    max_string[2]=${max_string[1]}
                    max_dir[2]=${max_dir[1]}
                fi 
                max_len[1]=${max_len[0]}
                max_string[1]=${max_string[0]}
                max_dir[1]=${max_dir[0]}
            	elif [[ ${max_len[0]} -gt ${max_len[2]} ]]; then
                max_len[2]=${max_len[0]}
                max_string[2]=${max_string[0]}
                max_dir[2]=${max_dir[0]}
            	fi 
            	max_len[0]=$len
            	max_dir[0]=$1
            	max_string[0]=$line
        	elif [[ $len -gt ${max_len[1]} ]]; then 
            if [[ ${max_len[1]} -gt ${max_len[2]} ]]; then
                max_len[2]=${max_len[1]}
                max_string[2]=${max_string[1]}
                max_dir[2]=${max_dir[1]}
            fi 
            max_len[1]=$len
            max_dir[1]=$1
            max_string[1]=$line
            elif [[ $len -gt ${max_len[2]} ]]; then 
            max_len[2]=$len
            max_dir[2]=$1
            max_string[2]=$line
            fi 
	fi
    done
}

#read -p "请输入初始路径：" a
#getdir $a
getdir /home/caohaiyan 

for i in `seq 0 2`; do 
	max_line[$i]=`grep -n ${max_string[$i]} ${max_dir[$i]} | awk -F: '{print $1}'`
	echo -e ${max_len[$i]}":"${max_string[$i]}"\t""`hostname`"":"${max_dir[$i]}"\t""Line:"${max_line[$i]}
done 
IFS=$OLDIFS
