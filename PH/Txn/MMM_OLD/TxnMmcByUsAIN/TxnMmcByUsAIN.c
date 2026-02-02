/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/03/07              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUsAIN.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnMmcByUsAIN(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;
	char	*csTmp = NULL;

	char	*csTxnId = NULL;
	char	*csOrgTxnId = NULL;
	char	*csOrgDtlTxnId = NULL;
	char	*csProcessType = NULL;
	char	*csProcessCode = NULL;
	char	*csTxnDesc = NULL;
	char	*csTxnCode = NULL;
	char	*csTxnDate = NULL;

	int	iTmp=0;
	int	iGroup = PD_FALSE;
	int	iMultiSrc = PD_FALSE;
	int	iInsertHD = PD_FALSE;
	double	dTmp;
	char	csTag[PD_TAG_LEN+1];
	char	cAutoRevStatus;

	hash_t  *hTxn;
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

	hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

        csTxnDesc = (char*) malloc (PD_DESC_LEN + 1);
        csProcessCode = (char*) malloc (PD_PROCESS_CODE_LEN + 1);
        csProcessType = (char*) malloc (PD_PROCESS_TYPE_LEN + 1);


/* user */
        if(GetField_CString(hContext,"add_user",&csTmp)){
		PutField_CString(hTxn,"add_user",csTmp);
		PutField_CString(hTxn,"update_user",csTmp);
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
        }

/*multi_src*/
	if(GetField_Int(hContext,"multi_src",&iMultiSrc)){
DEBUGLOG(("Authorize::multi_src= [%d]\n",iMultiSrc));
        }

/*group*/
	if(GetField_Int(hContext,"group",&iGroup)){
DEBUGLOG(("Authorize::group= [%d]\n",iGroup));
        }

/*org_txnid*/
	if(GetField_CString(hRequest,"org_txnid", &csOrgTxnId)){
		PutField_CString(hTxn,"prev_txn_seq",csOrgTxnId);
DEBUGLOG(("Authorize::org_txnid= [%s]\n",csOrgTxnId));
	}


/*org_dtl_txnid*/
	if(GetField_CString(hRequest,"org_dtl_txnid", &csOrgDtlTxnId)){
		//PutField_CString(hTxn,"prev_dtl_txn_seq",csOrgDtlTxnId);
DEBUGLOG(("Authorize::org_dtl_txnid= [%s]\n",csOrgDtlTxnId));
	}

	if(GetField_CString(hContext,"src_party_type",&csTmp)){
		PutField_CString(hTxn,"src_party_type",csTmp);
		PutField_CString(hTxn,"mms_from_type",csTmp);
DEBUGLOG(("Authorize::src_party_type= [%s]\n",csTmp));
	}

	if(GetField_CString(hContext,"dst_party_type",&csTmp)){
		PutField_CString(hTxn,"dst_party_type",csTmp);
		PutField_CString(hTxn,"mms_to_type",csTmp);
DEBUGLOG(("Authorize::dst_party_type= [%s]\n",csTmp));
	}

/*new txn seq*/
	if(GetField_CString(hContext,"new_txn_seq",&csTxnId)){
		PutField_CString(hTxn,"txn_seq",csTxnId);
DEBUGLOG(("Authorize::new_txn_seq= [%s]\n",csTxnId));
	}

	if(GetField_Int(hContext,"batch_id",&iTmp)){
DEBUGLOG(("Authorize::batch_id= [%d]\n",iTmp));
		PutField_Int(hTxn, "batch_id", iTmp);
        }

	if(GetField_Int(hRequest,"carry_forward_ind",&iTmp)){
DEBUGLOG(("Authorize::carry_forward_ind= [%d]\n",iTmp));
		PutField_Int(hTxn, "carry_forward_ind", iTmp);
        }
	if(GetField_CString(hRequest,"party_type",&csTmp)){
		PutField_CString(hTxn,"party_type",csTmp);

		if(!strcmp(csTmp,PD_MMS_PARTY_PSP)){
			sprintf(csTag,"psp_id");
		}
		else if(!strcmp(csTmp,PD_MMS_PARTY_MERCH)){
			sprintf(csTag,"merchant_id");
		}
		else if(!strcmp(csTmp,PD_MMS_PARTY_MB)){
			sprintf(csTag,"mb_id");
		}
		else if(!strcmp(csTmp,PD_MMS_PARTY_BANK)){
			sprintf(csTag,"bank_id");
		}
		else if(!strcmp(csTmp,PD_MMS_PARTY_STL_BK)){
			sprintf(csTag,"stl_bank_id");
		}
DEBUGLOG(("Authorize::party_type= [%s]\n",csTmp));
	}
	if(GetField_CString(hRequest,csTag,&csTmp)){
		PutField_CString(hTxn,csTag,csTmp);
DEBUGLOG(("Authorize::[%s]= [%s]\n",csTag, csTmp));
	}
	if(GetField_CString(hRequest,"node_id",&csTmp)){
		PutField_CString(hTxn,"mmc_node_id",csTmp);
		PutField_CString(hTxn,"node_id",csTmp);
		PutField_CString(hTxn,"party_node_id",csTmp);
DEBUGLOG(("Authorize::node_id= [%s]\n",csTmp));
	}
	if(GetField_CString(hRequest,"service",&csTmp)){
		PutField_CString(hTxn,"service_code",csTmp);
DEBUGLOG(("Authorize::service= [%s]\n",csTmp));
	}
	if(GetField_Double(hRequest,"txn_amt",&dTmp)){
		PutField_Double(hTxn,"txn_amt",dTmp);
DEBUGLOG(("Authorize::txnamt= [%lf]\n",dTmp));
	}
	if(GetField_CString(hRequest,"txn_ccy",&csTmp)){
		PutField_CString(hTxn,"txn_ccy",csTmp);
DEBUGLOG(("Authorize::ccy= [%s]\n",csTmp));
	}
	if(GetField_Double(hRequest,"adjustment",&dTmp)){
		PutField_Double(hTxn,"adjustment",dTmp);
DEBUGLOG(("Authorize::adjustment= [%lf]\n",dTmp));
	}
	if(GetField_Double(hRequest,"exchange_rate",&dTmp)){
		PutField_Double(hTxn,"exchange_rate",dTmp);
DEBUGLOG(("Authorize::ex rate= [%lf]\n",dTmp));
	}
	if(GetField_Double(hRequest,"processing_cost",&dTmp)){
		PutField_Double(hTxn,"processing_cost",dTmp);
DEBUGLOG(("Authorize::processing cost= [%lf]\n",dTmp));
	}
	if(GetField_Double(hRequest,"bank_charge",&dTmp)){
		PutField_Double(hTxn,"bank_charge",dTmp);
DEBUGLOG(("Authorize::bank charge= [%lf]\n",dTmp));
	}
	if(GetField_Double(hRequest,"bank_charge_refund",&dTmp)){
		PutField_Double(hTxn,"bank_charge_refund",dTmp);
DEBUGLOG(("Authorize::bank charge refund= [%lf]\n",dTmp));
	}
	if(GetField_CString(hRequest,"txndate",&csTxnDate)){
DEBUGLOG(("Authorize::txndate= [%s]\n",csTxnDate));
	}
	if(GetField_CString(hRequest,"filling_num",&csTmp)){
		PutField_CString(hTxn,"filing_number",csTmp);
DEBUGLOG(("Authorize::filling num= [%s]\n",csTmp));
	}

	PutField_CString(hTxn,"init_channel",PD_CHANNEL_MMC);
	PutField_CString(hTxn,"dc_type",PD_DR);
	PutField_Char(hTxn,"isd_ind",PD_SOURCE);

	if(GetField_CString(hContext,"PHDATE",&csTmp)){
		PutField_CString(hTxn,"host_posting_date",csTmp);
		PutField_CString(hTxn,"tm_date",csTmp);
		PutField_CString(hTxn,"local_tm_date",csTmp);

		char csDateTime[PD_DATETIME_LEN+1];
		strcpy(csDateTime,getdatetime());
		PutField_CString(hTxn,"transmission_datetime",csDateTime);
		PutField_CString(hTxn,"tm_time",&csDateTime[PD_DATE_LEN]);
		PutField_CString(hTxn,"local_tm_time",&csDateTime[PD_DATE_LEN]);
	}

	if(iRet==PD_OK){
		if(GetField_CString(hContext,"txn_code",&csTmp)){
			PutField_CString(hTxn,"txn_code",csTmp);
		}
/////If Multiple src -> new header. Before insert new header, check first.
		if(iMultiSrc){
DEBUGLOG(("Authorize::Call DBMmsTransaction:GetMmsTxnHeader\n"));
			DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","GetMmsTxnHeader");
			if ((unsigned long)(*DBObjPtr)(csTxnId,rRecordSet) != PD_OK) {
				iInsertHD = PD_TRUE;
			}
		}

		if(iInsertHD){
			PutField_Char(hTxn,"status",PD_PROCESSING);
DEBUGLOG(("Authorize::Call DBMmsTransaction:AddHeader\n"));
			DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","AddHeader");
			if ((unsigned long)(*DBObjPtr)(hTxn) != PD_OK) {
DEBUGLOG(("DBMmsTransaction:AddHeader Failed!!!\n"));
				iRet = INT_ERR;
			}
		}

	}

//////Insert Detail
	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBMmsTransaction:AddDetail\n"));
		PutField_Char(hTxn,"status",PD_PROCESSING);
		PutField_CString(hTxn,"transmission_datetime",csTxnDate);

		if(!strcmp(csTxnId,csOrgTxnId)){
			PutField_CString(hTxn,"prev_dtl_txn_seq",csOrgDtlTxnId);
		}
		DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","AddDetail");
		iRet = (unsigned long) ((*DBObjPtr)(hTxn));
DEBUGLOG(("DBMmsTransaction:AddDetail iRet[%d]\n",iRet));
		if(iRet==PD_OK){
			PutField_CString(hTxn,"host_ref",csTxnId);

			if(GetField_CString(hTxn,"dtl_txn_seq",&csTmp)){
				PutField_CString(hContext,"dtl_txn_seq",csTmp);
				PutField_CString(hTxn, "host_dtl_ref", csTmp);
DEBUGLOG(("DBMmsTransaction:AddDetail dtl_txn_seq[%s]\n",csTmp));
			}
		}
	}



	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call BOMmsTask:NewTask\n"));
		BOObjPtr = CreateObj(BOPtr,"BOMmsTask","NewTask");
		if((unsigned long) ((*BOObjPtr)(hContext, hTxn, hResponse)) != PD_OK){
			iRet = INT_ERR;

			if(GetField_Char(hResponse, "auto_reverse", &cAutoRevStatus)){
				iRet = PD_MMS_AUTO_REV;
DEBUGLOG(("Authorize::auto_reverse [%c]\n", cAutoRevStatus));
			}
		}
		if(GetField_CString(hContext,"sub_txn_code",&csTxnCode)){
DEBUGLOG(("Authorize::sub_txn_code = [%s]\n", csTxnCode));
			PutField_CString(hTxn,"sub_txn_code",csTxnCode);
		}
	}

	if (iRet == PD_OK) {
		if (GetField_Int(hResponse, "response_code", &iTmp)) {
DEBUGLOG(("Authorize::get return code [%d]\n", iTmp));
			if (iTmp != 0) {
				iRet = iTmp;
				PutField_Int(hContext,"internal_error",INT_INVALID_TXN);
			}
		}
	}

	if(iRet==PD_OK){
			DBObjPtr = CreateObj(DBPtr,"DBMmsTxnCode","FindProcessCode");
			if (!(*DBObjPtr)(csTxnCode,
					csTxnDesc,
					csProcessType,
					csProcessCode)) {
				iRet = INT_INVALID_TXN;
				PutField_Int(hContext,"internal_error",INT_INVALID_TXN);
DEBUGLOG(("Authorize:Can't Find ProcessCode\n"));
			}
			else {
				PutField_CString(hTxn,"sub_process_code",csProcessCode);
				PutField_CString(hTxn,"sub_process_type",csProcessType);
DEBUGLOG(("Authorize:ProcessType = [%s]\n",csProcessType));
DEBUGLOG(("Authorize:ProcessCode = [%s]\n",csProcessCode));
			}

	}

//////Update Header & Detail
	PutField_Int(hTxn,"internal_code",PD_OK);
	PutField_CString(hTxn,"response_code","0");
	if(iRet==PD_OK)
		PutField_Char(hTxn,"status",PD_MMS_PENDING);
	else if(iRet==PD_MMS_AUTO_REV)
		PutField_Char(hTxn,"status",cAutoRevStatus);
	else{
		PutField_Char(hTxn,"status",PD_REJECT);
		PutField_Int(hTxn,"internal_code",iRet);
		char csResp[PD_RESPONSE_CODE_LEN+1];
		sprintf(csResp,"%d",iRet);
		PutField_CString(hTxn,"response_code",csResp);
	}

	int iTmpRet = PD_OK;
	if(iInsertHD){
DEBUGLOG(("Authorize::Call DBMmsTransaction:UpdateHeader\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","UpdateHeader");
		if ((unsigned long)(*DBObjPtr)(hTxn) != PD_OK) {
DEBUGLOG(("DBMmsTransaction:UpdateHeader Failed!!!\n"));
			iTmpRet = INT_ERR;
		}
	}

	if(iTmpRet==PD_OK){
		if(iRet==PD_OK)
			PutField_Char(hTxn,"status",PD_ACCEPT);

DEBUGLOG(("Authorize::Call DBMmsTransaction:UpdateDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","UpdateDetail");
		iTmpRet = (unsigned long) ((*DBObjPtr)(hTxn));
DEBUGLOG(("DBMmsTransaction:UpdateDetail iRet[%d]\n",iRet));

//Insert Related table
  
/*
		if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBMmsRelatedTxn:Add\n"));
			DBObjPtr = CreateObj(DBPtr,"DBMmsRelatedTxn","Add");
			iTmpRet = (unsigned long) ((*DBObjPtr)(hTxn));
DEBUGLOG(("DBMmsRelatedTxn:Add iRet[%d]\n",iRet));
		}
*/
	}

	if(iTmpRet!=PD_OK){
		iRet=iTmpRet;
	}
	
	FREE_ME(hTxn);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

	FREE_ME(csTxnDesc);
        FREE_ME(csProcessCode);
        FREE_ME(csProcessType);

DEBUGLOG(("TxnMmcByUsAIN Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
