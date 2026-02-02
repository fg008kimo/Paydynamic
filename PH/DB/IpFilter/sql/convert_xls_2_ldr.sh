if [ $# == 1 ];then
	xls2txt $1 > tmp.txt
	sed -i "s/\t/|/g" tmp.txt
	awk  '/^[1-9]/ {print}' tmp.txt > IP_FILTER_DATA_TABLE.ldr
	sed -i "s/^/ /g" IP_FILTER_DATA_TABLE.ldr
	rm tmp.txt
	sqlldr $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID control=IP_FILTER_DATA_TABLE.ctl

else
	echo "usage: convert_xls_2_csv.sh [xls_name]"
	echo "xls should contain columns: ip_start, ip_end and ip_location"
	echo "xls will then be converted to .ldr and appended to ip_filter table by .ctl"
fi
