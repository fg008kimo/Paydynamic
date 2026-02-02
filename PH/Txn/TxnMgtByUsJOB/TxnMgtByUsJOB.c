/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/02/01              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsJOB.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


char cDebug;
OBJPTR(DB);


void TxnMgtByUsJOB(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	int	iCutOff = PD_FALSE;
	int	iFloat = PD_FALSE;
	int	iAFPO = PD_FALSE;
	int	iReserve = PD_FALSE;
//	int	iExRate = PD_FALSE;
	int	iAllowExec = PD_FALSE;
	
	char    *csTmp;
	char    csCmd[PD_TMP_BUF_LEN*2 + 1];

DEBUGLOG(("Authorize\n"));

        if(GetField_CString(hRequest,"cutoff",&csTmp)){
		iCutOff = atoi(csTmp);
DEBUGLOG(("Authorize::CutOff = [%d]\n",iCutOff));
        }
/*
  	if(GetField_CString(hRequest,"ex_rate",&csTmp)){
		iExRate = atoi(csTmp);
DEBUGLOG(("Authorize::get ExRate= [%d]\n",iExRate));
        }
*/
        if(GetField_CString(hRequest,"float",&csTmp)){
		iFloat= atoi(csTmp);
DEBUGLOG(("Authorize::Handle Daily Float = [%d]\n",iFloat));
        }
        if(GetField_CString(hRequest,"reserve",&csTmp)){
		iReserve = atoi(csTmp);
DEBUGLOG(("Authorize::Release Reserve= [%d]\n",iReserve));
        }
        if(GetField_CString(hRequest,"afpo_float",&csTmp)){
		iAFPO = atoi(csTmp);
DEBUGLOG(("Authorize::To AFPO Float= [%d]\n",iAFPO));
        }


	char*   csValueTmp;
	csValueTmp = (char*) malloc (128);
	DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
	if ((unsigned long)(DBObjPtr)("CYC_TEST_JOB",csValueTmp) == FOUND) {
		if (!strcmp(csValueTmp,"Y")) {
			iAllowExec = PD_TRUE;
		}
		else{
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext,"internal_error",iRet);
		}
DEBUGLOG(("Authorize::Allow Use Web to do the Cycle Test Job  = [%s]\n",csValueTmp));
	}
	FREE_ME(csValueTmp);


	if(!iAllowExec){
		iCutOff	= PD_FALSE;
		iAFPO = PD_FALSE;
		iReserve = PD_FALSE;
		iFloat = PD_FALSE;
	}

	if(iCutOff){
		//ph_cutoff
		sprintf(csCmd,"/home/intuat/bin/batch/ph_cutoff.sh");
DEBUGLOG(("Authorize:: command = [%s]\n", csCmd));
		system(csCmd);
		
		//reset_txn_counter
		sprintf(csCmd,"/home/intuat/bin/batch/reset_txn_counter.sh");
DEBUGLOG(("Authorize:: command = [%s]\n", csCmd));
		system(csCmd);

		//handle_remain_reserved_amt
		sprintf(csCmd,"/home/intuat/bin/batch/handle_remain_reserved_amt.sh");
DEBUGLOG(("Authorize:: command = [%s]\n", csCmd));
		system(csCmd);

		//update_psp_txn_date
		sprintf(csCmd,"/home/intuat/bin/batch/update_psp_txn_date.sh");
DEBUGLOG(("Authorize:: command = [%s]\n", csCmd));
		system(csCmd);
	//}

	//if(iExRate){
		//getrate
		sprintf(csCmd,"/home/intuat/bin/batch/getrate.sh");
DEBUGLOG(("Authorize:: command = [%s]\n", csCmd));
		system(csCmd);
	}

	if(iFloat){
		//handle_daily_float
		sprintf(csCmd,"/home/intuat/bin/batch/handle_daily_float.sh");
DEBUGLOG(("Authorize:: command = [%s]\n", csCmd));
		system(csCmd);
	}

	if(iReserve){
		//handle_reserved
		sprintf(csCmd,"/home/intuat/bin/batch/handle_reserved.sh");
DEBUGLOG(("Authorize:: command = [%s]\n", csCmd));
		system(csCmd);
	}

	if(iAFPO){
		//handle_daily_float_2AFPO.sh N
		sprintf(csCmd,"/home/intuat/bin/batch/handle_daily_float_2AFPO.sh N");
DEBUGLOG(("Authorize:: command = [%s]\n", csCmd));
		system(csCmd);
	}


DEBUGLOG(("TxnMgtByUsJOB Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
