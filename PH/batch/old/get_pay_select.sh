#!/bin/ksh

#Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
#of an authorized representative of Partnerdelight.

#Change Description                                 Change Date             Change By
#-------------------------------                    ------------            --------------
#Init Version                                       2010/12/15              LokMan Chow


report_path=${REPORT_DATA}/pay_selection_files/

if [[ $# == 2 ]]
then
	amount=$1
	mode=$2
else
	if [[ $# == 1 ]]
	then
		amount=$1
		mode="NORMAL"
	else
		amount=0
		mode="NORMAL"
	fi
fi


eval get_pay_select.exec -o ${report_path} -a $amount -m $mode

if [[ $? == 0 ]]
then
	echo "Success"
else
	echo "Failed"
fi
