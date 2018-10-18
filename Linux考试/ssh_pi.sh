#!/bin/bash

rm -rf pi?.log
for i in `seq 0 8`; do 
    ssh caohaiyan@192.168.1.4$i rm -rf 作业1.sh
    scp 作业1.sh caohaiyan@192.168.1.4$i:.
    ssh caohaiyan@192.168.1.4$i bash 作业1.sh>./pi$i.log
    scp caohaiyan@192.168.1.4$i:./pi$i.log /home/caohaiyan/Code/Linux考试 
done
