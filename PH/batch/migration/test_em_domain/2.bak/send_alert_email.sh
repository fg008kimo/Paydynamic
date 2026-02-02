#!/bin/sh

. /home/php3dev/.setenv

FROM_EMAIL="no-reply@n-servicing.com"

current_time=`date +%Y%m%d.%S%N`
tmp_file=$LOGPATH/mgt/send_alert-$current_time.log
cp -p $2 $tmp_file

${EMAIL_TEMPLATE}/$1 |cat - $tmp_file | /usr/sbin/sendmail -t -f${FROM_EMAIL} &
