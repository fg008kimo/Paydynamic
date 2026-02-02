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


#SRC_FILE_PATH=${HOME}/tmp/oln/test_fallback
SRC_FILE_PATH=/nfs/PROD_LOG/${in_date}/offline


#TMP_RESULT_FILE_2=ALL_DRU_${in_date}.result.tmp2
#RESULT_FILE=ALL_DRU_${in_date}.result

#cat /dev/null > ${RESULT_FILE}

#TARGET_FILE=ALL_${in_date}.log
#cat /dev/null > ${TARGET_FILE}

CORE=(CORE21 CORE22)

TMP_ALL_REQ_FILE_1=ALL_REQ.tmp.1
cat /dev/null > ${TMP_ALL_REQ_FILE_1}

TMP_ALL_RPY_FILE_1=ALL_RPY.tmp.1
cat /dev/null > ${TMP_ALL_RPY_FILE_1}

for j in "${CORE[@]}"
do

	find ${SRC_FILE_PATH}/${j} -name OmtMsg.c.${in_date}*log|
	(
		while read full_filename
		do
	                filename=${full_filename##*/}
			#echo ${full_filename} ${filename}

			tmp_pid=`echo ${filename}|awk -F"." '{print $4}'`
			#echo $tmp_pid


			TMP_REQ_FILE_1=TMP_REQ_${j}_${tmp_pid}.tmp1
			TMP_RPY_FILE_1=TMP_RPY_${j}_${tmp_pid}.tmp1

		
			grep -e "<PH><tc>DRE</tc>" ${full_filename} > ${TMP_REQ_FILE_1}
			cat ${TMP_REQ_FILE_1} >> ${TMP_ALL_REQ_FILE_1}

			grep -e "<PH><reply_tc>DRE</reply_tc>" ${full_filename} > ${TMP_RPY_FILE_1}
			cat ${TMP_RPY_FILE_1} >> ${TMP_ALL_RPY_FILE_1}

			rm  ${TMP_REQ_FILE_1}
			rm  ${TMP_RPY_FILE_1}
		done
	)
done

TMP_ALL_REQ_FILE_2=ALL_REQ.tmp.2
TMP_ALL_RPY_FILE_2=ALL_RPY.tmp.2
cat /dev/null > ${TMP_ALL_REQ_FILE_2}
cat /dev/null > ${TMP_ALL_RPY_FILE_2}

TMP_ALL_REQ_FILE_3=ALL_REQ.tmp.3
TMP_ALL_RPY_FILE_3=ALL_RPY.tmp.3
cat /dev/null > ${TMP_ALL_REQ_FILE_3}
cat /dev/null > ${TMP_ALL_RPY_FILE_3}

sort ${TMP_ALL_REQ_FILE_1} > ${TMP_ALL_REQ_FILE_2}
sed -e 's/\!\[CDATA//g; s/\[//g; s/\]//g; s/<cust_deposit_datetime></<cust_deposit_datetime>/g; s/><\/cust_deposit_datetime>/<\/cust_deposit_datetime>/g; s/<acct_num></<acct_num>/g; s/><\/acct_num>/<\/acct_num>/g; s/<deposit_bank></<deposit_bank>/g; s/><\/deposit_bank>/<\/deposit_bank>/g; s/<deposit_ref></<deposit_ref>/g; s/><\/deposit_ref>/<\/deposit_ref>/g;' ${TMP_ALL_REQ_FILE_2} > ${TMP_ALL_REQ_FILE_3}
rm ${TMP_ALL_REQ_FILE_1}
rm ${TMP_ALL_REQ_FILE_2}


sort ${TMP_ALL_RPY_FILE_1} > ${TMP_ALL_RPY_FILE_2}
sed -e 's/\!\[CDATA//g; s/\[//g; s/\]//g' ${TMP_ALL_RPY_FILE_2} > ${TMP_ALL_RPY_FILE_3}
rm ${TMP_ALL_RPY_FILE_1}
rm ${TMP_ALL_RPY_FILE_2}

LINE_CNT_REQ=`wc -l ${TMP_ALL_REQ_FILE_3}|awk -F" " '{print $1}'`
LINE_CNT_RPY=`wc -l ${TMP_ALL_RPY_FILE_3}|awk -F" " '{print $1}'`

#echo $LINE_CNT_REQ $LINE_CNT_RPY

if [ $LINE_CNT_REQ != $LINE_CNT_RPY ]
then
	echo "No. of Record Not Match"
	exit 0
else 
	echo "Line Check OK"
fi

TMP_ALL_REQ_FILE_4=ALL_REQ.tmp.4
TMP_ALL_RPY_FILE_4=ALL_RPY.tmp.4
cat /dev/null > ${TMP_ALL_REQ_FILE_4}
cat /dev/null > ${TMP_ALL_RPY_FILE_4}

awk '{printf "<rec_no>%s</rec_no>%s\n",NR,$0}' ${TMP_ALL_REQ_FILE_3} > ${TMP_ALL_REQ_FILE_4}
awk '{printf "<rec_no>%s</rec_no>%s\n",NR,$0}' ${TMP_ALL_RPY_FILE_3} > ${TMP_ALL_RPY_FILE_4}

rm ${TMP_ALL_REQ_FILE_3}
rm ${TMP_ALL_RPY_FILE_3}

TMP_ALL_REQ_FILE_5=ALL_REQ.tmp.5
TMP_ALL_RPY_FILE_5=ALL_RPY.tmp.5
cat /dev/null > ${TMP_ALL_REQ_FILE_5}
cat /dev/null > ${TMP_ALL_RPY_FILE_5}


while read line           
do           
	rec_no=`echo $line|awk -F"<rec_no>|</rec_no>" '{print $2}'`
	rec_time=`echo $line|awk -F"</rec_no>| " '{print $2}'`
	req_txn_id=`echo $line|awk -F"<txnid>|</txnid>" '{print $2}'`
	deposit_amt=`echo $line|awk -F"<deposit_amt>|</deposit_amt>" '{print $2}'`
	cust_deposit_datetime=`echo $line|awk -F"<cust_deposit_datetime>|</cust_deposit_datetime>" '{print $2}'`
	bank_code=`echo $line|awk -F"<bank_code>|</bank_code>" '{print $2}'`
	acct_num=`echo $line|awk -F"<acct_num>|</acct_num>" '{print $2}'`
	deposit_bank=`echo $line|awk -F"<deposit_bank>|</deposit_bank>" '{print $2}'`
	deposit_ref=`echo $line|awk -F"<deposit_ref>|</deposit_ref>" '{print $2}'`

	echo "${in_date},${rec_no},${rec_time},${req_txn_id},${deposit_amt},${cust_deposit_datetime},${bank_code},${acct_num},${deposit_ref},${deposit_bank}" >> ${TMP_ALL_REQ_FILE_5}
done < ${TMP_ALL_REQ_FILE_4}


while read line           
do           
	rec_no=`echo $line|awk -F"<rec_no>|</rec_no>" '{print $2}'`
	ret=`echo $line|awk -F"<ret>|</ret>" '{print $2}'`
	rpy_txn_id=`echo $line|awk -F"<txnid>|</txnid>" '{print $2}'`

	echo "${in_date},${rec_no},${rpy_txn_id},${ret}" >> ${TMP_ALL_RPY_FILE_5}

done < ${TMP_ALL_RPY_FILE_4}

rm ${TMP_ALL_REQ_FILE_4}
rm ${TMP_ALL_RPY_FILE_4}

