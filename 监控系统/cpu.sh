#!/bin/bash
Date=`date "+%Y-%m-%d__%H:%M:%S"`
Load=`uptime | awk '{print $10 $11 $12}'`
time1=`echo $[$(date +%s%N)/1000000]`
CPU=`cat /proc/stat | head -n 1`
idle1=`echo $CPU | awk '{print $5}'`
Total1=`echo $CPU | xargs -n1 | grep -v "cpu" | echo $[$(tr "\n" "+")0]`
#echo $Total1 
while :
do
    time2=`echo $[$(date +%s%N)/1000000]`
    time=$[ $time2 - $time1 ]
    #echo $time
    if [[ $time -ge 500 ]];then
        CPU2=`cat /proc/stat | head -n 1`
        idle2=`echo $CPU2 | awk '{print $5}'`
        Total2=`echo $CPU2 | xargs -n1 | grep -v "cpu" | echo $[ $( tr "\n" "+" ) 0  ]`
        #echo $Total2 
        break;
    fi
done
CPUusage=$[ $Total2 - $Total1 ]
CPUidle=$[ $idle2 - $idle1 ]
CPUuper=`echo "scale=2;($CPUidle * 10000) / $CPUusage"| bc`
CPUpercent=`echo "scale=2; (10000 - $CPUuper) / 100" | bc`
#Temp=`sensors | grep "Package" | awk '{print $4}' | tr -d -c '0-9.'`
Temp=`cat /sys/class/thermal/thermal_zone0/temp | cut -c -2`
Alert=`echo $Temp | awk '{if($1<=50){print "normal"}else if($1<=70){print "note";}else{print "warning";}}'`
echo $Date $Load $CPUpercent $Temp°C $Alert 
#>> /home/caohaiyan/shell/txt.log

