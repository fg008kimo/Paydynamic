#!/bin/ksh

#Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
#of an authorized representative of Partnerdelight.

#Change Description                                 Change Date             Change By
#-------------------------------                    ------------            --------------
#Init Version                                       2015/07/02              Virginia Yun

#. /usr/local/profile/setenv
. ${HOME}/.setenv

if [[ $# == 1 ]]
then
        in_filename=$1
else
        echo "Usage: $0 <filename>"
        exit 0 
fi

# grep in production
# grep "process_type=0200&process_code=200202&" OlnMsg.c.<date>* |grep "mer_id=M3000008" > wtt_core_0X_2015XXXX_M3000008.log
# grep "process_type=0200&process_code=200202&" OlnMsg.c.<date>* |grep "mer_id=M3000001" > wtt_core_0X_2015XXXX_M3000001.log


tmp_filename=${in_filename}.tmp
out_filename=${in_filename}.converted
final_filename=${in_filename}.final

echo ""
echo "[`date +%d-%b-%Y\ %T`] START FILE: [${in_filename}]"

#awk -F".log:" '{print $2}' ${in_filename}  |sort > ${tmp_filename}
############## need to maual remove some unused record 

awk -F"DATA = " '{print $2}' ${in_filename} > ${out_filename}

echo "[`date +%d-%b-%Y\ %T`] CONVERT FILE: [${out_filename}]"

echo "[`date +%d-%b-%Y\ %T`] In Processing....."

deposit_req_fallback.exec -s ${out_filename} -d ${final_filename}

echo "[`date +%d-%b-%Y\ %T`] END"

echo ""
