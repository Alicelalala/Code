#!/bin/bash

rm -rf pi?.log
for i in `seq 0 9`; do 
    ssh caohaiyan@192.168.1.4$i rm -rf dl_3.search.sh
    scp dl_3.search.sh caohaiyan@192.168.1.4$i:.
    ssh caohaiyan@192.168.1.4$i bash dl_3.search.sh>./pi$i.log
    scp caohaiyan@192.168.1.4$i:./pi$i.log /home/caohaiyan/Code/Linux考试 
done
