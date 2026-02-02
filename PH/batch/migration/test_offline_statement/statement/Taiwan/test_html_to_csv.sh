--- cut here ---
#!/bin/ksh

# table2text
#
# usage: table2text file-name
#
# Eliminates (almost) all HTML garbage from a file,
# keeping only the text contents of a <table>.
#
# It's not (yet) smart enough to eliminate the text
# of embedded style-sheets.

case $# in
1) file="$1";;
*) exit 1;;
esac

cat "$file" | \
sed -e "s,\~,,g" \
-e "s,<[Tt][Aa][Bb][Ll][Ee][^>]*>,\~TABLE\~,g" \
-e "s,</[Tt][Aa][Bb][Ll][Ee][^>]*>,\~/TABLE\~,g" \
-e "s,<[Tt][Rr][^>]*>,\~TR\~,g" \
-e "s,</[Tt][Rr][^>]*>,\~/TR\~,g" \
-e "s,<[Tt][Dd][^>]*>,\~TD\~,g" \
-e "s,</[Tt][Dd][^>]*>,\~/TD\~,g" \
-e "s,</*[^>]*>,,g" \
-e "s,\&nbsp;, ,g" \
-e "s, *$,," \
-e "s,^ *,," \
-e "s, *, ,g" | \
grep -v "^$" | \
while read instrg
do
outstrg=`echo "$instrg" | \
sed -e "s,\~/TABLE\~,,g" \
-e "s,\~/TR\~,\~,g" \
-e "s,\~/TD\~, ,g" \
-e "s,\~TABLE\~,\~,g" \
-e "s,\~TR\~,,g" \
-e "s,\~TD\~,,g"`
echo "$outstrg\c"
done | \
tr "~" "\012"

exit 0
--- cut here ---


