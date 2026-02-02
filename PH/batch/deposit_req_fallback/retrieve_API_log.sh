#!/bin/ksh

#Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
#of an authorized representative of Partnerdelight.

#Change Description                                 Change Date             Change By
#-------------------------------                    ------------            --------------
#Init Version                                       2015/07/02              Virginia Yun

#. /usr/local/profile/setenv
. ${HOME}/.setenv

if [[ $# == 1 ]]
then
        in_date=$1
else
        echo "Usage: $0 <in_date>"
        exit 0 
fi

# grep in production
# grep "process_type=0200&process_code=200202&" OlnMsg.c.<date>* |grep "mer_id=M3000008" > wtt_core_0X_2015XXXX_M3000008.log
# grep "process_type=0200&process_code=200202&" OlnMsg.c.<date>* |grep "mer_id=M3000001" > wtt_core_0X_2015XXXX_M3000001.log

#SRC_FILE_PATH=${HOME}/tmp/oln/test_fallback
SRC_FILE_PATH=/nfs/PROD_LOG/${in_date}/offline

echo ${SRC_FILE_PATH}

MID=(M3000008 M3000001) 
CORE=(CORE01 CORE02)


for i in "${MID[@]}"
do
	TARGET_FILE=ALL_${in_date}_${i}.log
	cat /dev/null > ${TARGET_FILE}

	for j in "${CORE[@]}"
	do
 		echo "${SRC_FILE_PATH}" "$j" "$i"
	
		grep -e "process_type=0200" ${SRC_FILE_PATH}/${j}/OlnMsg.c.${in_date}*log|grep "process_code=200202" | grep ${i} > WTT_${j}_${in_date}_${i}.log

		cat WTT_${j}_${in_date}_${i}.log >> ${TARGET_FILE}
	done


done


#find ${SRC_FILE_PATH} -name OlnMsg.c.${in_date}*log |grep -v "\/oln\/"|
#(
#	while read full_filename
#	do
#                filename=${full_filename##*/}
#
#                tmp_pid=`echo ${filename}|awk -F"." '{print $4}'`
#
#                #echo ${full_filename} ${filename} ${tmp_pid}
#
#		tmp_core_string=`echo ${full_filename}|awk -F"CORE" '{print $2}'`
#		tmp_core=`echo ${tmp_core_string}|awk -F "/" '{print $1}'`
#		
#		#echo ${tmp_core}
#		
#		for i in "${MID[@]}"
#		do
#	                mkdir ${in_date}_apilog
#			DEST_FILE=${in_date}_apilog/wtt_core${tmp_core}_${tmp_core}_${in_date}_$i.log
#
#			grep "process_type=0200&process_code=200202&" ${full_filename}|grep $i >> ${DEST_FILE}
#		done
#        done
#)
