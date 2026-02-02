#!/bin/ksh

path=files/
filename=bank_stmt_"$1"_"$2"

if [ $# -lt 2 ]; then
	echo "usage: [deposit/payout/intermediate/pending_fund] [date]"
	exit 1
elif [ ! -e "${path}${filename}.xls" ]; then
	echo "${path}${filename}.xls not found"
	exit 1
fi

if [ "$1" == "deposit" ]; then
	nameRow=1
	codeRow=2
	firstRow=3
	secondRow=12
	format_type=TXN_CODE_DSI

elif [ "$1" == "payout" ]; then
	nameRow=1
	codeRow=2
	firstRow=3
	secondRow=17
	format_type=TXN_CODE_POA

elif [ "$1" == "intermediate" ]; then
	nameRow=1
	codeRow=2
	firstRow=3
	secondRow=16
	format_type=TXN_CODE_ITM

elif [ "$1" == "pending_fund" ]; then
        nameRow=1
        codeRow=2
        firstRow=3
        secondRow=0
        format_type=TXN_CODE_PDF
fi

xls2txt "${path}${filename}.xls" > "${filename}.txt"



# # #special
sed -i "
s/\(冲账\)\([^,]\+\)\(冲帐\)/\1,\2\3/g

/VUP\|VUI/s/从内部账号转入//g
s/现金\(现支\)(交易摘要)/\1/g
s/CGB has a separated cloumn to reflect Bank Charge//g

${firstRow}s/ABC (交易渠道)/ABC (交易摘要)/g
${firstRow},${secondRow}s/ECITIC (現金\/轉賬)/ECITIC (现金\/转账)/g
${firstRow},${secondRow}s/SPDB (交易類型)/SPDB (交易摘要)/g
" "${filename}.txt"



# # #change delimiter
sed -i "s/\t/|/g" "${filename}.txt"

# # #remove space
csSpace=(`printf "\xc2\xa0"` `printf "\xe3\x80\x80"`)
sed -i "
s/${csSpace[0]}/ /g
s/${csSpace[1]}/ /g
s/, \+/,/g
s/| \+/|/g
s/ \+,/,/g
s/ \+|/|/g
s/ \+$//g
" "${filename}.txt"

# # #remove empty keywords
sed -i "
s/,\+/,/g
s/|,/|/g
s/,|/|/g
s/,$//g
" "${filename}.txt"

# # #extract column name
sed -i "s/|[^|()]*(\([^|()]*\))/|\1/g" "${filename}.txt"



# # #read file
row_count=0
IFS=$'|'
while read -r row				# # #for each row
do

#echo "row_count = $row_count"
#echo "$row"

	if [ $row_count -eq $((nameRow-1)) ]; then					# # #row 1: bank name
		set -f -A bank_name $row

	elif [ $row_count -eq $((codeRow-1)) ]; then					# # #row 2: bank code
		set -f -A bank_code $row

	elif [ $row_count -eq $((firstRow-1)) ]; then					# # #row 3: column name
		set -f -A col_name1 $row

	elif [ $secondRow -gt 0 ] && [ $row_count -eq $((secondRow-1)) ]; then		# # #row 12/17/16: column name
		set -f -A col_name2 $row
	fi

	set -f -A cell $row

	format_txn_code=${cell[1]}

	if [[ "$format_txn_code" == *[A-Za-z0-9]* ]]	# # #txn code
	then

		col_count=0

		#for col_count in {0..19}
		while [ $col_count -lt 20 ]				# # #for each column
		do

#echo " col_count = $col_count"

			int_bank_code=${bank_code[col_count]}

			if [[ "$int_bank_code" == *[A-Za-z0-9]* ]]	# # #bank code
			then

#echo "txn_code: $format_txn_code bank_code: $int_bank_code"

				condition="[[ \$${bank_name[col_count]}_format_value == \"\" ]]"
				if eval $condition
				then
					eval ${bank_name[col_count]}_format_value=0
				fi

				condition="[[ \$${bank_name[col_count]}_${format_txn_code}_display_order == \"\" ]]"
				if eval $condition
				then
					eval ${bank_name[col_count]}_${format_txn_code}_display_order=0
				fi


				if [ $row_count -ge $secondRow ] && [ $row_count -le $((secondRow+3)) ] && 
									[ ! "${col_name2[col_count]}" == "" ] &&
									[ $secondRow -gt 0 ]
				then
					format_col_name=${col_name2[col_count]}

			# # #special
					if [ "${bank_name[col_count]}" == "CMBC" ]
					then
						if [ "$second_col_name" == "" ]
						then
							format_col_name="交易方式"
							second_col_name="摘要"
						else
							format_col_name=$second_col_name
							second_col_name=
						fi
					fi
			# # #

				else
					format_col_name=${col_name1[col_count]}
				fi

				TIFS=$IFS
				IFS=$','
				for format_template in ${cell[col_count]}		# # #keywords
				do
					(( ${bank_name[col_count]}_format_value+=1 ))
					(( ${bank_name[col_count]}_${format_txn_code}_display_order+=1 ))

					format_value=$(eval printf "%03d" $(eval printf "%s" "\$${bank_name[col_count]}_format_value"))
					display_order=$(eval printf "%d" $(eval printf "%s" "\$${bank_name[col_count]}_${format_txn_code}_display_order"))

eval echo "$int_bank_code\|$format_type\|$format_value\|$format_txn_code\|$format_template\|$format_col_name\|$display_order"


				# # #special
					if [ "$format_txn_code" == "OTC" ]
					then
						(( ${bank_name[col_count]}_format_value+=1 ))
						format_value=$(eval printf "%03d" $(eval printf "%s" "\$${bank_name[col_count]}_format_value"))

eval echo "$int_bank_code\|$format_type\|$format_value\|OTD\|$format_template\|$format_col_name\|$display_order"
					elif [ "$format_txn_code" == "OBP" ] && [ ! "$format_type" == "TXN_CODE_PDF" ]
					then
						(( ${bank_name[col_count]}_format_value+=1 ))
						format_value=$(eval printf "%03d" $(eval printf "%s" "\$${bank_name[col_count]}_format_value"))

eval echo "$int_bank_code\|$format_type\|$format_value\|SUP\|$format_template\|$format_col_name\|$display_order"
					fi
				# # #

				done
				IFS=$TIFS

			# # #special
				if [ ! "$second_col_name" == "" ]
				then
					(( col_count-=1 ))
				fi
			# # #

			fi
			(( col_count+=1 ))

		done
	fi
	(( row_count+=1 ))

done < "${filename}.txt" > "${filename}.tmp"

cat "${filename}.tmp"
cat "${filename}.tmp" | sort > "${filename}.txt"
rm "${filename}.tmp"

