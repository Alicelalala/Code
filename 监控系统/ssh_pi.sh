#!/bin/bash

rm -rf pi?.log
for i in `seq 0 9`; do 
    ssh caohaiyan@192.168.1.4$i rm -rf client_ssh.c common.c head.h cpu.sh disk.sh mem.sh sysinfo.sh user.sh proc.sh
    scp client_ssh.c common.c head.h cpu.sh disk.sh mem.sh sysinfo.sh user.sh proc.sh caohaiyan@192.168.1.4$i:.
    ssh caohaiyan@192.168.1.4$i gcc client_ssh.c
    #ssh caohaiyan@192.168.1.4$i ./a.out 192.168.1.137 8732
    #scp caohaiyan@192.168.1.4$i:./pi$i.log /home/caohaiyan/Code/Linux考试 
done
