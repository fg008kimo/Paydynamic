#/bin/ksh

echo "" > $2
cat $1 |while read arg1
do
	echo "cd $arg1 && touch *.pc &&  make all && cd .."  >> $2
done
chmod +x $2
