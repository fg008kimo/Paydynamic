#!/bin/ksh

#Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
#of an authorized representative of Partnerdelight.

#Change Description                                 Change Date             Change By
#-------------------------------                    ------------            --------------
#Init Version                                       2010/10/28              Cody Chan


eod_date=$(get_control.exec "CTEODDATE")
report_file="$(get_currrptpath.exec)/TXN_DETAIL.xls"


x=${0##*/}
eval batch_status.exec $x

result=$?
if [[ $result == 0 ]]
then
        upd_job_status.exec $x "P"


        eval generate_txn_detail.exec -d ${eod_date} > ${report_file}


        if [[ $? == 0 ]]
        then
                echo "Success"
                upd_job_status.exec $x "C"
        else
                echo "Failed"
                upd_job_status.exec $x "F"
        fi
else
        result_code.sh $x $result
fi
