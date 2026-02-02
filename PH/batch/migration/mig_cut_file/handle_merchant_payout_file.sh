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

FILE_PATH=/home/php3dev/Doc/parallel_run/init_data/data_files/${FILE_DATE}
#FILE_PATH=/home/php3dev/src/batch/migration/mig_cut_file/${FILE_DATE}

HEADER_FILE_PREFIX=merchant_payout_hd
DETAIL_FILE_PREFIX=merchant_payout_detail

GRP001_EMAIL_LIST=(ec2tw@funds365.com)
GRP002_EMAIL_LIST=(vnetmobile@funds365.com)
GRP003_EMAIL_LIST=(ec2@funds365.com) 
GRP004_EMAIL_LIST=(vnetnew@funds365.com)

GRP010_EMAIL_LIST=(samlam@mpay.com.hk info@ironfx.com netbanx@fxpro.com T.constantinides@fxpro.com it@xemarkets.com bo@jfx.com treasury@thinkforex.com.au)

#GRPOTH_EMAIL_LIST=(info@ironfx.com samlam@mpay.com.hk)

FILE_TYPE_LIST=(D P)
for tmp_file_type in ${FILE_TYPE_LIST[@]}
do

	TARGET_HEADER_GRP001_FILE=${FILE_PATH}/${HEADER_FILE_PREFIX}${tmp_file_type}_GRP001_${FILE_DATE}.csv
	TARGET_DETAIL_GRP001_FILE=${FILE_PATH}/${DETAIL_FILE_PREFIX}${tmp_file_type}_GRP001_${FILE_DATE}.csv
	TARGET_HEADER_GRP002_FILE=${FILE_PATH}/${HEADER_FILE_PREFIX}${tmp_file_type}_GRP002_${FILE_DATE}.csv
	TARGET_DETAIL_GRP002_FILE=${FILE_PATH}/${DETAIL_FILE_PREFIX}${tmp_file_type}_GRP002_${FILE_DATE}.csv
	TARGET_HEADER_GRP003_FILE=${FILE_PATH}/${HEADER_FILE_PREFIX}${tmp_file_type}_GRP003_${FILE_DATE}.csv
	TARGET_DETAIL_GRP003_FILE=${FILE_PATH}/${DETAIL_FILE_PREFIX}${tmp_file_type}_GRP003_${FILE_DATE}.csv
	TARGET_HEADER_GRP004_FILE=${FILE_PATH}/${HEADER_FILE_PREFIX}${tmp_file_type}_GRP004_${FILE_DATE}.csv
	TARGET_DETAIL_GRP004_FILE=${FILE_PATH}/${DETAIL_FILE_PREFIX}${tmp_file_type}_GRP004_${FILE_DATE}.csv

	TARGET_HEADER_GRP010_FILE=${FILE_PATH}/${HEADER_FILE_PREFIX}${tmp_file_type}_GRP010_${FILE_DATE}.csv
	TARGET_DETAIL_GRP010_FILE=${FILE_PATH}/${DETAIL_FILE_PREFIX}${tmp_file_type}_GRP010_${FILE_DATE}.csv

	TARGET_HEADER_GRPOTH_FILE=${FILE_PATH}/${HEADER_FILE_PREFIX}${tmp_file_type}_GRPOTH_${FILE_DATE}.csv
	TARGET_DETAIL_GRPOTH_FILE=${FILE_PATH}/${DETAIL_FILE_PREFIX}${tmp_file_type}_GRPOTH_${FILE_DATE}.csv

	cat /dev/null > ${TARGET_HEADER_GRP001_FILE}
	cat /dev/null > ${TARGET_DETAIL_GRP001_FILE}
	cat /dev/null > ${TARGET_HEADER_GRP002_FILE}
	cat /dev/null > ${TARGET_DETAIL_GRP002_FILE}
	cat /dev/null > ${TARGET_HEADER_GRP003_FILE}
	cat /dev/null > ${TARGET_DETAIL_GRP003_FILE}
	cat /dev/null > ${TARGET_HEADER_GRP004_FILE}
	cat /dev/null > ${TARGET_DETAIL_GRP004_FILE}

	cat /dev/null > ${TARGET_HEADER_GRP010_FILE}
	cat /dev/null > ${TARGET_DETAIL_GRP010_FILE}

	cat /dev/null > ${TARGET_HEADER_GRPOTH_FILE}
	cat /dev/null > ${TARGET_DETAIL_GRPOTH_FILE}

	split_file=0
	header_line_cnt=`wc -w ${FILE_PATH}/${HEADER_FILE_PREFIX}${tmp_file_type}_${FILE_DATE}.csv|awk {'print $1'}`
	detail_line_cnt=`wc -w ${FILE_PATH}/${DETAIL_FILE_PREFIX}${tmp_file_type}_${FILE_DATE}.csv|awk {'print $1'}`

	if [ ${header_line_cnt} -gt 0 ] || [ ${detail_line_cnt} -gt 0 ]
	then
	        split_file=1
	fi

	if [ ${split_file} -eq 1 ]
	then
		echo "processing file_type:[${tmp_file_type}] date:[${FILE_DATE}]"
                cat ${FILE_PATH}/${HEADER_FILE_PREFIX}${tmp_file_type}_${FILE_DATE}.csv |while read arg1
		do
			#0:init
			type_flag=0

			chk_username=`echo ${arg1}|awk -F, {'print $3'}| sed 's/"//g'`
			file_id=`echo ${arg1}|awk -F, {'print $1'}`

			for tmp_username in ${GRP001_EMAIL_LIST[@]};do
				if [ "${chk_username}" == "${tmp_username}" ]; then
					type_flag=GRP001
				fi
			done

			for tmp_username in ${GRP002_EMAIL_LIST[@]};do
				if [ "${chk_username}" == "${tmp_username}" ]; then
					type_flag=GRP002
				fi
			done

			for tmp_username in ${GRP003_EMAIL_LIST[@]};do
				if [ "${chk_username}" == "${tmp_username}" ]; then
					type_flag=GRP003
				fi
			done

			for tmp_username in ${GRP004_EMAIL_LIST[@]};do
				if [ "${chk_username}" == "${tmp_username}" ]; then
					type_flag=GRP004
				fi
			done

			for tmp_username in ${GRP010_EMAIL_LIST[@]};do
				if [ "${chk_username}" == "${tmp_username}" ]; then
					type_flag=GRP010
				fi
			done

			if [ "${type_flag}" == "0" ]; then
				type_flag=GRPOTH
                        fi


			#for tmp_username in ${GRPOTH_EMAIL_LIST[@]};do
			#	if [ "${chk_username}" == "${tmp_username}" ]; then
			#		type_flag=GRPOTH
			#	fi
			#done
			
			echo "TYPE: ${type_flag} chk_username: ${chk_username} file_id: ${file_id}"

			if [ "${type_flag}" == "GRP001" ]; then
				echo ${arg1} >> ${TARGET_HEADER_GRP001_FILE}
				FINAL_DETAIL_FILE=${TARGET_DETAIL_GRP001_FILE}

			elif [ "${type_flag}" == "GRP002" ]; then
				echo ${arg1} >> ${TARGET_HEADER_GRP002_FILE}
				FINAL_DETAIL_FILE=${TARGET_DETAIL_GRP002_FILE}

			elif [ "${type_flag}" == "GRP003" ]; then
				echo ${arg1} >> ${TARGET_HEADER_GRP003_FILE}
				FINAL_DETAIL_FILE=${TARGET_DETAIL_GRP003_FILE}

			elif [ "${type_flag}" == "GRP004" ]; then
				echo ${arg1} >> ${TARGET_HEADER_GRP004_FILE}
				FINAL_DETAIL_FILE=${TARGET_DETAIL_GRP004_FILE}

			elif [ "${type_flag}" == "GRP010" ]; then
				echo ${arg1} >> ${TARGET_HEADER_GRP010_FILE}
				FINAL_DETAIL_FILE=${TARGET_DETAIL_GRP010_FILE}

			elif [ "${type_flag}" == "GRPOTH" ]; then
				echo ${arg1} >> ${TARGET_HEADER_GRPOTH_FILE}
				FINAL_DETAIL_FILE=${TARGET_DETAIL_GRPOTH_FILE}
			else 
				echo "ERROR: Undefined $chk_username"
				exit 1
			fi

			cat ${FILE_PATH}/${DETAIL_FILE_PREFIX}${tmp_file_type}_${FILE_DATE}.csv |while read dtl_arg1
		        do
				dtl_file_id=`echo ${dtl_arg1}|awk -F, {'print $3'}`

				if [ "${file_id}" == "${dtl_file_id}" ]
				then
					echo ${dtl_arg1} >> ${FINAL_DETAIL_FILE}
				fi
			done
		done
	fi
done
