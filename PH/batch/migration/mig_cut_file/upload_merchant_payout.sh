ORACLE_USER=dbconv;
ORACLE_PASSWORD=dbconv;
ORACLE_SID=DBCONV;

BASE=`basename $0`
if [ $# != 2 ]
then
        echo "${BASE} <file_date> <type:GRP001/GRP002/GRP003/GRP004/GRP010/GRPOTH/ALL>"
        exit 1
fi

FILE_DATE=$1
RUN_TYPE=$2

FILE_PATH=/home/php3dev/Doc/parallel_run/init_data/data_files/${FILE_DATE}
#FILE_PATH=/home/php3dev/src/batch/migration/mig_cut_file/${FILE_DATE}

HEADER_FILE_PREFIX=merchant_payout_hd
DETAIL_FILE_PREFIX=merchant_payout_detail

FILE_TYPE_LIST=(D P)

if [ ${RUN_TYPE} == "GRP001" ]
then

	##### GRP001 #####
	for tmp_file_type in ${FILE_TYPE_LIST[@]}
	do
		FILE_SUFFIX=${tmp_file_type}_GRP001_${FILE_DATE}.csv
		
		echo "Process ${RUN_TYPE} [${tmp_file_type}]"

		mig_payout_upload.exec -h ${FILE_PATH}/${HEADER_FILE_PREFIX}${FILE_SUFFIX} -t ${FILE_PATH}/${DETAIL_FILE_PREFIX}${FILE_SUFFIX} -d ${FILE_DATE}
		if [ $? != 0 ]
		then
			echo "ERROR on pr_payout_upload GRP001 type : ${tmp_file_type}"
			exit 1
		fi
	done

elif [ ${RUN_TYPE} == "GRP002" ]
then
	##### GRP002 #####
	for tmp_file_type in ${FILE_TYPE_LIST[@]}
	do
		FILE_SUFFIX=${tmp_file_type}_GRP002_${FILE_DATE}.csv

		echo "Process ${RUN_TYPE} [${tmp_file_type}]"

		mig_payout_upload.exec -h ${FILE_PATH}/${HEADER_FILE_PREFIX}${FILE_SUFFIX} -t ${FILE_PATH}/${DETAIL_FILE_PREFIX}${FILE_SUFFIX} -d ${FILE_DATE}
		if [ $? != 0 ]
		then
			echo "ERROR on pr_payout_upload GRP002 type : ${tmp_file_type}"
			exit 1
		fi
	done

elif [ ${RUN_TYPE} == "GRP003" ]
then
	##### GRP003 #####
	for tmp_file_type in ${FILE_TYPE_LIST[@]}
	do
		FILE_SUFFIX=${tmp_file_type}_GRP003_${FILE_DATE}.csv

		echo "Process ${RUN_TYPE} [${tmp_file_type}]"

		mig_payout_upload.exec -h ${FILE_PATH}/${HEADER_FILE_PREFIX}${FILE_SUFFIX} -t ${FILE_PATH}/${DETAIL_FILE_PREFIX}${FILE_SUFFIX} -d ${FILE_DATE}
		if [ $? != 0 ]
		then
			echo "ERROR on pr_payout_upload GRP003 type : ${tmp_file_type}"
			exit 1
		fi
	done

elif [ ${RUN_TYPE} == "GRP004" ]
then
	##### GRP004 #####
	for tmp_file_type in ${FILE_TYPE_LIST[@]}
	do
		FILE_SUFFIX=${tmp_file_type}_GRP004_${FILE_DATE}.csv

		echo "Process ${RUN_TYPE} [${tmp_file_type}]"

		mig_payout_upload.exec -h ${FILE_PATH}/${HEADER_FILE_PREFIX}${FILE_SUFFIX} -t ${FILE_PATH}/${DETAIL_FILE_PREFIX}${FILE_SUFFIX} -d ${FILE_DATE}
		if [ $? != 0 ]
		then
			echo "ERROR on pr_payout_upload GRP004 type : ${tmp_file_type}"
			exit 1
		fi
	done

elif [ ${RUN_TYPE} == "GRP010" ]
then
	##### GRP010 #####
	for tmp_file_type in ${FILE_TYPE_LIST[@]}
	do
		FILE_SUFFIX=${tmp_file_type}_GRP010_${FILE_DATE}.csv

		echo "Process ${RUN_TYPE} [${tmp_file_type}]"

		mig_payout_upload.exec -h ${FILE_PATH}/${HEADER_FILE_PREFIX}${FILE_SUFFIX} -t ${FILE_PATH}/${DETAIL_FILE_PREFIX}${FILE_SUFFIX} -d ${FILE_DATE}
		if [ $? != 0 ]
		then
			echo "ERROR on pr_payout_upload GRP010 type : ${tmp_file_type}"
			exit 1
		fi
	done


elif [ ${RUN_TYPE} == "GRPOTH" ]
then
	##### GRPOTH #####
	for tmp_file_type in ${FILE_TYPE_LIST[@]}
	do
		FILE_SUFFIX=${tmp_file_type}_GRPOTH_${FILE_DATE}.csv

		echo "Process ${RUN_TYPE} [${tmp_file_type}]"

		mig_payout_upload.exec -h ${FILE_PATH}/${HEADER_FILE_PREFIX}${FILE_SUFFIX} -t ${FILE_PATH}/${DETAIL_FILE_PREFIX}${FILE_SUFFIX} -d ${FILE_DATE}
		if [ $? != 0 ]
		then
			echo "ERROR on pr_payout_upload GRPOTH type : ${tmp_file_type}"
			exit 1
		fi
	done

elif [ ${RUN_TYPE} == "ALL" ]
then
	##### ALL #####
	for tmp_file_type in ${FILE_TYPE_LIST[@]}
	do
		FILE_SUFFIX=${tmp_file_type}_${FILE_DATE}.csv

		echo "Process ${RUN_TYPE} [${tmp_file_type}]"

		mig_payout_upload.exec -h ${FILE_PATH}/${HEADER_FILE_PREFIX}${FILE_SUFFIX} -t ${FILE_PATH}/${DETAIL_FILE_PREFIX}${FILE_SUFFIX} -d ${FILE_DATE}
		if [ $? != 0 ]
		then
			echo "ERROR on pr_payout_upload type : ${tmp_file_type}"
			exit 1
		fi
	done
fi
