#/bin/ksh

echo "" > $2
cat $1 |while read arg1
do
	echo "make -f $arg1 all"  >> $2
done
chmod +x $2
