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

TMP_RESULT_FILE_1=ALL_DRU_${in_date}.result.tmp1
TMP_DECLINE_FILE_1=ALL_DRU_${in_date}.decline.tmp1

TMP_RESULT_FILE_2=ALL_DRU_${in_date}.result.tmp2
TMP_DECLINE_FILE_2=ALL_DRU_${in_date}.decline.tmp2

RESULT_FILE=ALL_DRU_${in_date}.result
DECLINE_FILE=ALL_DRU_${in_date}.decline

cat /dev/null > ${RESULT_FILE}
cat /dev/null > ${DECLINE_FILE}

find ${SRC_FILE_PATH} -name Txn*DRU*${in_date}*log|
(
	while read full_filename
	do
		filename=${full_filename##*/}
		#echo ${full_filename} ${filename}

		tmp_pid=`echo ${filename}|awk -F"." '{print $4}'`
		#echo $tmp_pid

		TMP_FILE_RESULT=DRU_${in_date}_${tmp_pid}.result
		TMP_FILE_DECLINE=DRU_${in_date}_${tmp_pid}.decline

                grep -e "Authorize() Rescue Boat FileResult "  ${full_filename} > ${TMP_FILE_RESULT}
                grep -e "Authorize() Rescue Boat ErrorResult " ${full_filename} > ${TMP_FILE_DECLINE}

		cat ${TMP_FILE_RESULT} >> ${TMP_RESULT_FILE_1}
		cat ${TMP_FILE_DECLINE} >> ${TMP_DECLINE_FILE_1}

	done
)

sort ${TMP_RESULT_FILE_1} |uniq  > ${TMP_RESULT_FILE_2}
sort ${TMP_DECLINE_FILE_1} |uniq > ${TMP_DECLINE_FILE_2}

echo "DateTime,MerchantId,InFilePath,InFileName,Req. Party,Upload User,FileId,NewFileName,TotalCount,AcceptCount,AcceptAmt,Status,ErrorCnt" > ${RESULT_FILE}
echo "FileId,NewFileName,TotalErrorCnt,LineCnt,Desc,FileMsg" > ${DECLINE_FILE}


cat ${TMP_RESULT_FILE_2} |awk -F" |Rescue Boat FileResult " '{print $1","$5}' >> ${RESULT_FILE}
cat ${TMP_DECLINE_FILE_2} |awk -F"Rescue Boat ErrorResult " '{print $2}' >> ${DECLINE_FILE}

rm ${TMP_RESULT_FILE_1}
rm ${TMP_DECLINE_FILE_1}

rm ${TMP_RESULT_FILE_2}
rm ${TMP_DECLINE_FILE_2}



