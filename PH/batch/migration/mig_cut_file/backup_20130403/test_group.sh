ORACLE_USER=dbconv;
ORACLE_PASSWORD=dbconv;
ORACLE_SID=DBCONV;

BASE=`basename $0`
if [ $# != 1 ]
then
        echo "${BASE} <file_date>"
        exit 1
fi

FILE_DATE=$1
JOBNAME=`basename $0 .sh`


FILE_PATH=/home/php3dev/Doc/parallel_run/init_data/data_files/${FILE_DATE}
#FILE_PATH=/home/php3dev/src/batch/migration/mig_cut_file/${FILE_DATE}

HEADER_FILE_PREFIX=merchant_payout_hd
DETAIL_FILE_PREFIX=merchant_payout_detail

JOB_LOG=${JOBNAME}_group_${FILE_DATE}.log


echo "@${JOBNAME}.sql ${FILE_DATE}" |sqlplus -s $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID > ${JOB_LOG}

error_cnt=`cat ${JOB_LOG}|grep "ERR"|wc -l`
if [ ${error_cnt} -gt 0 ]
then
        echo "update_proc_status ERROR FOUND"
        exit 1;

fi

cat ${JOB_LOG}|while read arg1
do
	echo ${arg1}
	
	group_name=`echo ${arg1}|awk {'print $1'}`
	merch_username=`echo ${arg1}|awk {'print $2'}`

	echo ${group_name} 
        echo ${merch_username}


done
