#!/bin/bash
Date=`date "+%Y-%m-%d_%H:%M:%S"`
Tatol=`free -m |grep "Mem" | awk '{print $2}'`
Used=`free -m | grep "Mem" | awk '{print $3}'`
Availabe=$[($Tatol-$Used)]
Percent=`awk 'BEGIN{printf"%d\n",('$Used'/'$Tatol')*100}'`
#echo $Percent
Sport=`awk 'BEGIN{printf"%.1f%%\n", (0.3*'$1'+0.7*('$Used'/'$Tatol'))*100}'`
echo $Date ${Tatol}M ${Availabe}M $Percent% $Sport 
#>> /home/caohaiyan/shell/txt.log

