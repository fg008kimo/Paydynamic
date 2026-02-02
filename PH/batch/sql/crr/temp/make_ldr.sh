#!/bin/sh

if [ -z "$1" ]; then
echo 'usage:<filename>'
exit 1
fi

tmp=tmp.txt
ldr=TMP_CRR_CARRY_OLD_BALANCE_DATA_TABLE.ldr
cp "$1" $tmp
sed -i 's/ -   //g' $tmp
sed -i 's/^/ /g' $tmp
sed -i 's/ |/|/g' $tmp
sed -i 's/| /|/g' $tmp
sed -i 's/(\([0-9,.]\+\))/\1/g' $tmp
sed -i 's/#DIV\/0!//g' $tmp
cut -d "|" -f 1-11 $tmp > $ldr
rm $tmp
