#!/bin/ksh

BASE=`basename $0`

EMAIL_TEMPLATE_PATH=${HOME}/email_template

#echo ${EMAIL_TEMPLATE_PATH}
cd ${EMAIL_TEMPLATE_PATH}

LIST=`ls *.sh`

for file_name1 in $LIST
do
	echo "Amend ${file_name1}"
	sed -i "s/@n-servicing.com/@corp.newco.local/g" ${file_name1}
done

echo ">>>> email_template done <<<<<"
echo ""

BIN_BATCH_PATH=${HOME}/bin/batch
BIN_BATCH_FILE=(send_alert_email.sh send_sys_email.sh send_warning_email.sh)

cd ${BIN_BATCH_PATH}

for file_name2 in ${BIN_BATCH_FILE[@]}
do
	
	if [ -e ${file_name2} ] 
	then
		echo "Amend ${file_name2}"
		sed -i "s/@n-servicing.com/@corp.newco.local/g" ${file_name2}
	else
		echo "!!!!!${file_name2} Not Exist"
	fi
done

echo ">>>> bin_batch done <<<<<"
echo ""
