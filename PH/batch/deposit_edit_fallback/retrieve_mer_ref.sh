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

CORE=(CORE21 CORE22)

TMP_ALL_FILE_1=ALL_MER_REF.tmp.1
cat /dev/null > ${TMP_ALL_FILE_1}


for j in "${CORE[@]}"
do

	find ${SRC_FILE_PATH}/${j} -name TxnOmtByUsDRE.c.${in_date}*log|
	(
		while read full_filename
		do
	                filename=${full_filename##*/}
			filepath=`dirname ${full_filename}`

#echo ${full_filename} ${filename} ${filepath}

			tmp_pid=`echo ${filename}|awk -F"." '{print $4}'`
#echo $tmp_pid

#echo ${filepath}/OLTransaction.c.${in_date}.${tmp_pid}.log

			TMP_FILE_1=TMP_${j}_${tmp_pid}.tmp1
			grep -e "GetTxnHeader txn_id" -e "GetTxnHeader merchant_ref" ${filepath}/OLTransaction.c.${in_date}.${tmp_pid}.log > ${TMP_FILE_1}
			cat ${TMP_FILE_1} >> ${TMP_ALL_FILE_1}

			rm  ${TMP_FILE_1}
		done
	)
done

TMP_ALL_FILE_2=ALL_MER_REF.tmp.2
cat /dev/null > ${TMP_ALL_FILE_2}

awk -F"GetTxnHeader " '{print $2}' ${TMP_ALL_FILE_1} > ${TMP_ALL_FILE_2}
rm ${TMP_ALL_FILE_1}

TMP_ALL_FILE_3=ALL_MER_REF.tmp.3
cat /dev/null > ${TMP_ALL_FILE_3}

sed -e ':a;N;$!ba;s/\nfile_id//g; s/\nmerchant_ref = //g; s/\]\[/,/g; s/\[//g; s/\]//g; s/txn_id = //g; s/= /,/g;' ${TMP_ALL_FILE_2} > ${TMP_ALL_FILE_3}

rm ${TMP_ALL_FILE_2}



TMP_ALL_FILE_4=ALL_MER_REF.tmp.4
cat /dev/null > ${TMP_ALL_FILE_4}

awk '{print $0","}' ${TMP_ALL_FILE_3} > ${TMP_ALL_FILE_4}

rm ${TMP_ALL_FILE_3}


