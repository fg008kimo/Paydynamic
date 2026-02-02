#!/bin/ksh

#Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
#of an authorized representative of Partnerdelight.

#Change Description                                 Change Date             Change By
#-------------------------------                    ------------            --------------
#Init Version                                       2015/07/05              David Wong

#. /usr/local/profile/setenv
. ${HOME}/.setenv

if [[ $# == 1 ]]
then
	in_date=$1
else
	echo "Usage: $0 <date>"
	exit 0 
fi

SRC_FILE_PATH=${HOME}/tmp/oln/

TMP_RESULT_FILE_1=ALL_OMM_${in_date}.result.tmp1

TMP_RESULT_FILE_2=ALL_OMM_${in_date}.result.tmp2

RESULT_FILE=ALL_OMM_${in_date}.result

cat /dev/null > ${RESULT_FILE}

find ${SRC_FILE_PATH} -name Txn*OMM*${in_date}*log|
(
	while read full_filename
	do
		filename=${full_filename##*/}

		tmp_pid=`echo ${filename}|awk -F"." '{print $4}'`

		TMP_RESULT_FILE=OMM_${in_date}_${tmp_pid}.result

                grep -e "Authorize() for fallback grep log " ${full_filename} > ${TMP_RESULT_FILE}

		cat ${TMP_RESULT_FILE} >> ${TMP_RESULT_FILE_1}

	done
)

sort -u ${TMP_RESULT_FILE_1} > ${TMP_RESULT_FILE_2}

cat ${TMP_RESULT_FILE_2} | awk -F" for fallback grep log " '{print $2}' >> ${RESULT_FILE}

rm ${TMP_RESULT_FILE_1}

rm ${TMP_RESULT_FILE_2}

