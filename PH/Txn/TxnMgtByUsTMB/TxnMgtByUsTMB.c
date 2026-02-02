/*
PDProTech (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/07/21              [GOD]
Handle Manual Approval Date                        2012/03/28              [SWK]
Add batch_mode                                     2020/11/24              [ZBL]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsTMB.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

#define	PD_DETAIL_TAG	"dt"

static char cDebug;
OBJPTR(Channel);
OBJPTR(DB);
OBJPTR(Txn);

void TxnMgtByUsTMB(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	int	iCnt = 0,i;
	char	*csIP;
	char	*csUser;
	char	csTag[PD_TAG_LEN +1];
	char	*csPtr;
	//char	*csTxnSeq;
	char	*csPspTxnDate;  
	  
	hash_t	*hReq, *hRsp;
DEBUGLOG(("Authorize::()\n"));

	if (GetField_CString(hRequest,"ip_addr",&csIP)) {
DEBUGLOG(("Authorize::() ip_addr = [%s]\n",csIP));
	}

	if (GetField_CString(hRequest,"add_user",&csUser)) {
DEBUGLOG(("Authorize::() user = [%s]\n",csUser));
	}


/* txn ack log */
	char    csBatchTxnSeq[PD_TXN_SEQ_LEN +1];
        DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMgtTxnSeq");
	strcpy(csBatchTxnSeq,(*DBObjPtr)());
        PutField_CString(hContext,"batch_txn_seq",csBatchTxnSeq);
/* end txn ack log */

	if (GetField_Int(hContext,"total_cnt",&iCnt)) {
		PutField_Int(hResponse,"total_cnt",iCnt);
DEBUGLOG(("Authorize::() total_cnt = [%d]\n",iCnt));

		/* PRD290 PSP Actual Amount From Deposit Callback */
		PutField_Int(hContext, "batch_mode", PD_TRUE);
		/* End - PRD290 PSP Actual Amount From Deposit Callback */

		for (i = 0; i< iCnt; i++) {
			sprintf(csTag,"%s_txnid_%d",PD_DETAIL_TAG,i+1);
			if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n",csTag,csPtr));
        			hReq = (hash_t*) malloc (sizeof(hash_t));
        			hRsp = (hash_t*) malloc (sizeof(hash_t));
        			hash_init(hReq,0);
        			hash_init(hRsp,0);

				//DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextTxnSeq");
                		//csTxnSeq  = strdup((*DBObjPtr)());

				PutField_CString(hReq,"org_txn_seq",csPtr);
				PutField_CString(hReq,"ip_addr",csIP);
				PutField_CString(hReq,"add_user",csUser);

				if (GetField_CString(hRequest,  "psp_txn_date", &csPspTxnDate)) {
DEBUGLOG(("Authorize::() psp_txn_date = [%s]\n",csPspTxnDate));
					PutField_CString(hReq, "psp_txn_date", csPspTxnDate);
				}

				sprintf(csTag,"%s_tid_%d",PD_DETAIL_TAG,i+1);
				if(GetField_CString(hRequest,csTag,&csPtr)){
					 PutField_CString(hReq, "tid", csPtr);
				}

				TxnObjPtr = CreateObj(TxnPtr,"TxnMgtByUsTMA","Authorize");
                		iRet = (unsigned long)(*TxnObjPtr)(hContext,hReq,hRsp);

				sprintf(csTag,"ret_%d",i+1);
DEBUGLOG(("Authorize::() [%s] = [%d]\n",csTag,iRet));
				PutField_Int(hResponse,csTag,iRet);
				
        			FREE_ME(hReq);
        			FREE_ME(hRsp);
				//FREE_ME(csTxnSeq);
			}
		}
	}
	else {
		iRet = INT_FORMAT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}
DEBUGLOG(("TxnMgtByUsTMB Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
