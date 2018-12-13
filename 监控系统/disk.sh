#!/bin/bash

User=`whoami`
Date=`date "+%Y-%m-%d__%H:%M:%S"`
`df -m | grep -v "tmpfs" | tail -n +2 > txt`
Disksum=`cat txt | awk '{print $2}' | echo $[ $( tr "\n" "+"  ) 0   ]`
Diskused=`cat txt | awk '{print $3}' | echo $[ $( tr "\n" "+"  ) 0   ]`
Diskavailable=`cat txt | awk '{print $4}' | echo $[$(tr "\n" "+") 0]`
Diskpercent=`awk 'BEGIN{printf "%d\n",('$Diskused'/'$Disksum') * 100}'`
Part=`cat txt | awk '{print $6" " $2" " $4" "$5}'`
Part1=`echo $Part | awk -F % '{print $1}'`
Part2=`echo $Part | awk -F % '{print $2}'`
#Part3=`echo $Part | awk -F % '{print $3}'`
echo $Date 0 disk $Disksum $Diskavailable $Diskpercent% #>> /home/caohaiyan/shell/txt.log
echo $Date 1 $Part1%  #>> /home/caohaiyan/shell/txt.log 
echo $Date 1 $Part2%  #>> /home/caohaiyan/shell/txt.log 
#echo $Date 1 $Part3%  #>> /home/caohaiyan/shell/txt.log
