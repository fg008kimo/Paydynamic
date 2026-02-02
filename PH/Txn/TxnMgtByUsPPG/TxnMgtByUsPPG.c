/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/06/01              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsPPG.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"



char cDebug;
OBJPTR(BO);
OBJPTR(DB);

void TxnMgtByUsPPG(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csTmp;
	//char	*csBatchId = strdup("");
	unsigned long	lFileId= 0l;
	double	dTmp;
	int	i=0;
	int	iCnt=0;
	int	iTmp=0;
	char	csTag[PD_TAG_LEN+1];
	char	csFileId[PD_TXN_SEQ_LEN+1];

	hash_t  *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn, 0);


DEBUGLOG(("Authorize\n"));
	PutField_CString(hContext,"new_txn_code",PD_PAYOUT_GENERATE);

	if(GetField_CString(hContext,"txn_seq",&csTmp)){
		PutField_CString(hTxn,"txn_seq",csTmp);
DEBUGLOG(("Authorize: txn_id [%s]\n",csTmp));
	}

	if(GetField_CString(hRequest,"psp_id",&csTmp)){
		PutField_CString(hTxn,"file_pid",csTmp);
DEBUGLOG(("Authorize: psp_id [%s]\n",csTmp));
	}

	if(GetField_CString(hRequest,"file_date",&csTmp)){
		PutField_CString(hTxn,"file_date",csTmp);
DEBUGLOG(("Authorize: file_date [%s]\n",csTmp));
	}

	if(GetField_CString(hRequest,"filename",&csTmp)){
		PutField_CString(hTxn,"filename",csTmp);
DEBUGLOG(("Authorize: filename [%s]\n",csTmp));
	}

	if(GetField_Int(hRequest,"txn_count",&iCnt)){
		PutField_Int(hTxn,"txn_cnt",iCnt);
DEBUGLOG(("Authorize: txn_count [%d]\n",iCnt));
	}

	if(GetField_Double(hRequest,"total_txn_amt",&dTmp)){
		PutField_Double(hTxn,"txn_amt",dTmp);
DEBUGLOG(("Authorize: total_txn_amt [%d]\n",dTmp));
	}

	if(GetField_CString(hRequest,"merchant_fee_ccy",&csTmp)){
		PutField_CString(hTxn,"merchant_fee_ccy",csTmp);
DEBUGLOG(("Authorize: merchant_fee_ccy [%s]\n",csTmp));
	}

	if(GetField_Double(hRequest,"merchant_fee",&dTmp)){
		PutField_Double(hTxn,"merchant_fee",dTmp);
DEBUGLOG(("Authorize: merchant_fee [%d]\n",dTmp));
	}

	if(GetField_CString(hRequest,"member_fee_ccy",&csTmp)){
		PutField_CString(hTxn,"member_fee_ccy",csTmp);
DEBUGLOG(("Authorize: member_fee_ccy [%s]\n",csTmp));
	}

	if(GetField_Double(hRequest,"member_fee",&dTmp)){
		PutField_Double(hTxn,"member_fee",dTmp);
DEBUGLOG(("Authorize: member_fee [%d]\n",dTmp));
	}

	if(GetField_CString(hRequest,"add_user",&csTmp)){
		PutField_CString(hTxn,"add_user",csTmp);
DEBUGLOG(("Authorize: add_user [%s]\n",csTmp));
	}
	PutField_Int(hTxn,"seq_num",1);
	PutField_Int(hTxn,"status",PD_PAYOUTFILE_GENERATED);

	//Generate FileId
DEBUGLOG(("CreatePayoutFileDetail::DBPayoutGeneratedFileHD:GetNextFileId\n"));
	DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedFileHD","GetNextFileId");
	if((unsigned long) ((*DBObjPtr)(&lFileId))!=PD_OK){
		iRet = INT_ERR;
DEBUGLOG(("CreatePayoutFileDetail::DBPayoutGeneratedFileHD:GetNextFileId Failed\n"));
	}
	else{
		sprintf(csFileId,"%ld",lFileId);
		PutField_CString(hTxn,"file_id",csFileId);
	}	


	
	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBPayoutGeneratedFileHD:Add\n"));
		DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedFileHD","Add");
		if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBPayoutGeneratedFileHD:Add Failed\n"));
ERRLOG("TxnMgtByUsPPG::Authorize::DBPayoutGeneratedFileHD:Add Failed\n");
			iRet = PD_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}
	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBPayoutGeneratedFileHD:Update\n"));
		DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedFileHD","Update");
		if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBPayoutGeneratedFileHD:Update Failed\n"));
ERRLOG("TxnMgtByUsPPG::Authorize::DBPayoutGeneratedFileHD:Update Failed\n");
			iRet = PD_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}


	if(iRet==PD_OK){
		for (i=0;i<iCnt;i++){
			sprintf(csTag,"batch_id_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"batch_id",csTmp);
			}
			sprintf(csTag,"txn_id_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"txn_id",csTmp);
				PutField_CString(hTxn,"gen_txn_id",csTmp);
			}
			sprintf(csTag,"seq_num_%d",i);
			if(GetField_Int(hRequest,csTag,&iTmp)){
				PutField_Int(hTxn,"seq_num",iTmp);
			}
			sprintf(csTag,"merchant_ref_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"merchant_ref",csTmp);
			}
			sprintf(csTag,"country_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"country",csTmp);
			}
			sprintf(csTag,"identity_id_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"identity_id",csTmp);
			}
			sprintf(csTag,"account_num_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"account_num",csTmp);
			}
			sprintf(csTag,"account_name_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"account_name",csTmp);
			}
			sprintf(csTag,"bank_name_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"bank_name",csTmp);
			}
			sprintf(csTag,"bank_code_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"bank_code",csTmp);
			}
			sprintf(csTag,"branch_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"branch",csTmp);
			}
			sprintf(csTag,"phone_num_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"phone_num",csTmp);
			}
			sprintf(csTag,"province_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"province",csTmp);
			}
			sprintf(csTag,"city_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"city",csTmp);
			}
			sprintf(csTag,"payout_currency_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"payout_ccy",csTmp);
			}
			sprintf(csTag,"payout_amount_%d",i);
			if(GetField_Double(hRequest,csTag,&dTmp)){
				PutField_Double(hTxn,"payout_amount",dTmp);
			}
			sprintf(csTag,"request_currency_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"request_ccy",csTmp);
			}
			sprintf(csTag,"request_amount_%d",i);
			if(GetField_Double(hRequest,csTag,&dTmp)){
				PutField_Double(hTxn,"request_amount",dTmp);
			}
			
			PutField_Int(hTxn,"status",PAYOUT_MASTER_TRANSACTION_GENERATED);
DEBUGLOG(("Authorize::Call DBPayoutGeneratedFileDT:Add\n"));
			DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedFileDT","Add");
			if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBPayoutGeneratedFileDT:Add Failed\n"));
ERRLOG("TxnMgtByUsPPG::Authorize::DBPayoutGeneratedFileDT:Add Failed\n");
				iRet = PD_ERR;
				PutField_Int(hContext,"internal_error",iRet);
				break;
			}
			
		}
	}

	
DEBUGLOG(("TxnMgtByUsPPG Normal Exit() iRet = [%d]\n",iRet));

	//FREE_ME(csBatchId);
	FREE_ME(hTxn);
        return iRet;
}
