#!/bin/ksh

. $HOME/bin/batch/setenv.sh

cat diff_src.txt | while read LINE
do
	# Remove The Carriage Return From Origial File Name
	FILE_NAME=$(echo ${LINE##*/} | sed -e 's/\r//g')
	echo ${FILE_NAME} >> result_src.txt

	find $HOME/Doc -type f -name "*.txt" -exec grep -s "${FILE_NAME}" {} + >> result_src.txt
	echo "====================" >> result_src.txt
done
