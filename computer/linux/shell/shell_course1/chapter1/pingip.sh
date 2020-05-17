#!/bin/bash
# 使用说明: bash pingip.sh ip.txt
check_ip()
{
for ip in `cat $1`:
do
	ping -c1 $ip -t200 &>/dev/null # 这里为了不显示多余的打印信息，直接将无用的信息输出到 /dev/null中。
	if [ $? -eq 0 ];
	then
		echo "$ip is ping down"
	else
		echo "$ip is ping up"
	fi
done	
}

ip_file=$1
if [ ! -e $ip_file ]
then
	echo "$ip_file does not exist or it is not a file"
else
	echo "$ip_file is a file"
	check_ip $ip_file
fi


