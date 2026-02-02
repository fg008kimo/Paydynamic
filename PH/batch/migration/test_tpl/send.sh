#!/bin/ksh

mer_id='K000000001'
mer_key='9zfYgBtKA8MZNT2715DtrsoFZeuWfYUgqt8qORyQiVfL918Ttm9cHO5qk0YcrxFCEFJ4ulJAgNkwm3f860DSzRy1NrgySw9Lp3gUHe8h3YVUDjdHu06QKMnMrrGdfvHK'
process_type='0200'
process_code='200002'
verno='1'
enctype='1'
service_code='VNC'
lang='GB'
success_url="https://abc.abc.com/"
failure_url="https://abc.abc.com/"
success_s2s_url="https://abc.abc.com/"
failure_s2s_url="https://abc.abc.com/"
country='CN';
mer_ref=${PPID}$(date +%Y%m%d%H%M%s);
mer_txn_date=$(date +%Y%m%d%H%M%S);
ccy='CNY'
txn_amt='100'
txn_amt=$1
authdata=${txn_amt}${ccy}${mer_ref}${mer_id}${mer_txn_date}${mer_key}
#print "$authdata\n"

signature=$(echo $authdata |md5sum | awk 'BEGIN{FS=" "} {print $1}')
#echo $signature

POSTDATA="process_type=${process_type}&"
POSTDATA=${POSTDATA}"process_code=${process_code}&"
POSTDATA=${POSTDATA}"mer_id=${mer_id}&"
POSTDATA=${POSTDATA}"success_url=${success_url}&"
POSTDATA=${POSTDATA}"failure_url=${failure_url}&"
POSTDATA=${POSTDATA}"success_s2s_url=${success_s2s_url}&"
POSTDATA=${POSTDATA}"failure_s2s_url=${failure_s2s_url}&"
POSTDATA=${POSTDATA}"verno=${verno}&"
POSTDATA=${POSTDATA}"service_code=${service_code}&"
POSTDATA=${POSTDATA}"lang=${lang}&"
POSTDATA=${POSTDATA}"ccy=${ccy}&"
POSTDATA=${POSTDATA}"mer_txn_date=${mer_txn_date}&"
POSTDATA=${POSTDATA}"txn_amt=${txn_amt}&"
POSTDATA=${POSTDATA}"mer_ref=${mer_ref}&"
POSTDATA=${POSTDATA}"enctype=${enctype}&"
POSTDATA=${POSTDATA}"country=${country}&"
POSTDATA=${POSTDATA}"signature=${signature}"


echo $POSTDATA
