#!/bin/bash

arch=$(uname -a)
phcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
vrcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
freeram=$(free -m | mawk '$1 == "Mem:" {print $2}')
usedram=$(free -m | mawk '$1 == "Mem:" {print $3}')
phram=$(free | mawk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
freedisk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | mawk '{ft += $2} END {print ft}')
useddisk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | mawk '{ut += $3} END {print ut}')
phdisk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | mawk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')
usedcpu=$(top -bn1 | grep '^%Cpu' | xargs | mawk '{printf("%.1f%%"), $2 + $4 + $10}')
lastboot=$(who -b | awk '{print $3 " " $4}')
lvm=$(lsblk | grep "lvm" | wc -l)
checklvm=$(if [ $lvmt -eq 0 ]; then echo no; else echo yes; fi)
tcpconex=$(cat /proc/net/sockstat{,6} | mawk '$1 == "TCP:" {print $3}')
userslog=$(users | wc -w)
ipv4=$(hostname -I)
mac=$(ip link show | mawk '$1 == "link/ether" {print $2}')
sudocommands=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall "
        #Architecture: $arch
        #CPU physical: $phcpu
        #vCPU: $vrcpu
        #Memory Usage: $usedram/${freeram}MB ($phram%)
        #Disk Usage: $useddisk/${freedisk}Gb ($phdisk%)
        #CPU load: $usedcpu
        #Last boot: $lastboot
        #LVM use: $checklvm
        #Connexions TCP: $tcpconex ESTABLISHED
        #User log: $userslog
        #Network: IP $ipv4 ($mac)
        #Sudo: $sudocommands cmd"
