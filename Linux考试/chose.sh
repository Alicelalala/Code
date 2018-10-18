#!/bin/bash

filter() {
    a=(rmvb png img jpg jpeg gif md avi zip tar gz 7z)
    suffix=`echo $1 | awk -F. '{print $NF}'`
    echo ${a[*]} | grep "$suffix" >/dev/null 
    if [[ $? -eq 0 ]]; then
        return 1
    fi 
    return 0
}

for i in `ls`; do
    file $i | grep "exec" >/dev/null 
    if [[ $? -eq 1 ]]; then 
        filter $i
        if [[ $? -eq 0 ]]; then 
            echo $i
        fi 
    fi 
done

for i in `seq 1 10`; do 
    scp piLong.sh pi@pi$i:.
    ssh pi@pi$i "bash piLong.sh > ./out.log"
    scp pi@pi$i:./out.log ./pi@i.out
done
