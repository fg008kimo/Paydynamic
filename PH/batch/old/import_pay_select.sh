#!/bin/ksh

#Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
#of an authorized representative of Partnerdelight.

#Change Description                                 Change Date             Change By
#-------------------------------                    ------------            --------------
#Init Version                                       2010/12/15              Cody Chan

prefix="pay"
postfix=".txt"

payout_dir=${REPORT_DATA}/pay_selection_files/import/
newdir=${REPORT_DATA}/pay_selection_files/import/old/

find ${payout_dir} -maxdepth 1 -type f -name  $prefix*$postfix  -print| sort |while read obj
do
	echo $obj
	import_pay_selection.exec -f $obj
	mv $obj $newdir > /dev/null 2>&1
done

