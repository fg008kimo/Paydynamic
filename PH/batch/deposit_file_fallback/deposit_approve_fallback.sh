#!/bin/ksh

#Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
#of an authorized representative of Partnerdelight.

#Change Description                                 Change Date             Change By
#-------------------------------                    ------------            --------------
#Init Version                                       2015/07/03              Virginia Yun

#. /usr/local/profile/setenv
. ${HOME}/.setenv

if [[ $# == 1 ]]
then
        in_date=$1
else
        echo "Usage: $0 <date>"
        exit 0 
fi

SRC_FILE_PATH=${HOME}/tmp/oln/test_fallback

TMP_RESULT_FILE_1=ALL_DRA_${in_date}.result.tmp1
TMP_RESULT_FILE_2=ALL_DRA_${in_date}.result.tmp2

RESULT_FILE=ALL_DRA_${in_date}.result

cat /dev/null > ${RESULT_FILE}


find ${SRC_FILE_PATH} -name Txn*DRA*${in_date}*log|
(
	while read full_filename
	do
		filename=${full_filename##*/}
		#echo ${full_filename} ${filename}

		tmp_pid=`echo ${filename}|awk -F"." '{print $4}'`
		#echo $tmp_pid

		TMP_FILE_RESULT=DRA_${in_date}_${tmp_pid}.result

                grep -e "Authorize() Rescue Boat Result "  ${full_filename} > ${TMP_FILE_RESULT}

		cat ${TMP_FILE_RESULT} >> ${TMP_RESULT_FILE_1}

	done
)

#echo ${TMP_RESULT_FILE_1} 
#echo ${TMP_RESULT_FILE_2}

sort ${TMP_RESULT_FILE_1} |uniq > ${TMP_RESULT_FILE_2}

echo "DateTime,FileId,MechantID,Action,Party" > ${RESULT_FILE}

cat ${TMP_RESULT_FILE_2} |awk -F" |Rescue Boat Result " '{print $1","$5}' >> ${RESULT_FILE}

rm ${TMP_RESULT_FILE_1}
rm ${TMP_RESULT_FILE_2}



