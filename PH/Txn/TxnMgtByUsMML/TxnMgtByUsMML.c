/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/02/22              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsMML.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(DB);
OBJPTR(BO);
void TxnMgtByUsMML(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csTxnCode;
	char*	csTmp;
	char	cTmp;
	double	dTmp;
	int	iTmp;
	int	iInput = PD_TRUE;
	hash_t  *hTxn, *hPsp, *hEle;

	hTxn= (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);
	hEle= (hash_t*) malloc (sizeof(hash_t));
        hash_init(hEle,0);
	hPsp= (hash_t*) malloc (sizeof(hash_t));
        hash_init(hPsp,0);

DEBUGLOG(("TxnMgtByUsMML Authorize()\n"));

	if(GetField_CString(hContext,"txn_code",&csTxnCode)){
		PutField_CString(hTxn,"txn_code",csTxnCode);
DEBUGLOG(("TxnMgtByUsMML txn_code = [%s]\n",csTxnCode));
	}

	if(GetField_CString(hContext,"txn_desc",&csTmp)){
		PutField_CString(hPsp,"desc",csTmp);
DEBUGLOG(("TxnMgtByUsMML txn_desc = [%s]\n",csTmp));
	}

	if(GetField_CString(hContext,"channel_code",&csTmp)){
		PutField_CString(hTxn,"channel_code",csTmp);
DEBUGLOG(("TxnMgtByUsMML channel_code = [%s]\n",csTmp));
	}

	if(GetField_CString(hContext,"th_host_ref",&csTmp)){
		PutField_CString(hTxn,"remark",csTmp);
DEBUGLOG(("TxnMgtByUsMML host_ref= [%s]\n",csTmp));
	}

	if(GetField_CString(hContext,"txn_seq",&csTmp)){
		PutField_CString(hTxn,"txn_seq",csTmp);
		PutField_CString(hEle,"from_txn_seq",csTmp);
		PutField_CString(hPsp,"txn_seq",csTmp);
DEBUGLOG(("TxnMgtByUsMML txn_id = [%s]\n",csTmp));
	}

	if(GetField_CString(hRequest,"org_txn_seq",&csTmp)){
		PutField_CString(hTxn,"org_txn_seq",csTmp);
DEBUGLOG(("TxnMgtByUsMML org_txn_id = [%s]\n",csTmp));
	}

	if(GetField_CString(hContext,"PHDATE",&csTmp)){
		PutField_CString(hPsp,"txn_date",csTmp);
		PutField_CString(hTxn,"tm_date",csTmp);
		PutField_CString(hTxn,"local_tm_date",csTmp);
		PutField_CString(hTxn,"approval_date",csTmp);
		PutField_CString(hTxn,"host_posting_date",csTmp);
		PutField_CString(hTxn,"transmission_datetime",csTmp);
DEBUGLOG(("TxnMgtByUsMML approval_date = [%s]\n",csTmp));
	}

	if(GetField_Int(hContext,"internal_error",&iTmp)){
		char *csErr = strdup("");
		PutField_Int(hTxn,"internal_code",iTmp);
		sprintf(csErr,"%d",iTmp);
		PutField_CString(hTxn,"response_code",csErr);
DEBUGLOG(("TxnMgtByUsMML internal_error = [%s]\n",iTmp));
		FREE_ME(csErr);
	}
	else{
		PutField_Int(hTxn,"internal_code",0);
		PutField_CString(hTxn,"response_code","0");
	}

	PutField_Char(hTxn,"status",PD_COMPLETE);
	PutField_Char(hTxn,"ar_ind",PD_ACCEPT);
	PutField_CString(hTxn,"process_code",PD_PROCESS_CODE_DEF);
	PutField_CString(hTxn,"process_type",PD_PROCESS_TYPE_DEF);
	PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
	PutField_CString(hTxn,"update_user",PD_UPDATE_USER);
	PutField_CString(hPsp,"add_user",PD_UPDATE_USER);
	PutField_CString(hPsp,"update_user",PD_UPDATE_USER);

	if(GetField_Double(hRequest,"net_amt",&dTmp)){
		PutField_Double(hPsp,"txn_amt",dTmp);
		PutField_Double(hTxn,"txn_amt",dTmp);
		PutField_Double(hTxn,"net_amt",dTmp);
		PutField_Double(hEle,"org_txn_amt",dTmp);
DEBUGLOG(("TxnMgtByUsMML txn_amt = [%lf]\n",dTmp));
	}

	if(GetField_CString(hRequest,"txn_ccy",&csTmp)){
		PutField_CString(hEle,"org_txn_ccy",csTmp);
		PutField_CString(hTxn,"txn_ccy",csTmp);
		PutField_CString(hPsp,"txn_ccy",csTmp);
DEBUGLOG(("TxnMgtByUsMML txn_ccy = [%s]\n",csTmp));
	}
/*
	if(!strcmp(csTxnCode,PD_TRAN_FROM_PSP)||
	   !strcmp(csTxnCode,PD_TRAN_FROM_NERCH)){
		PutField_CString(hEle,"amount_type",PD_DR);
DEBUGLOG(("TxnMgtByUsMML amount_type = [%s]\n",PD_DR));
	}
*/
	if(GetField_Char(hRequest,"isd_ind",&cTmp)){
		if(cTmp==PD_SOURCE)
			PutField_CString(hEle,"amount_type",PD_DR);
DEBUGLOG(("TxnMgtByUsMML amount_type = [%s]\n",PD_DR));
	}

	if (GetField_CString(hRequest, "merchant_client_id", &csTmp)) {
		PutField_CString(hTxn,"client_id",csTmp);
DEBUGLOG(("TxnMgtByUsMML client_id = [%s]\n",csTmp));
	}

	if (GetField_CString(hRequest, "service_code", &csTmp)) {
		PutField_CString(hTxn,"service_code",csTmp);
DEBUGLOG(("TxnMgtByUsMML service_code = [%s]\n",csTmp));
	}


/*txn detail*/
	if(GetField_CString(hRequest,"merchant_id",&csTmp)){
		PutField_CString(hTxn,"merchant_id",csTmp);
		PutField_Char(hEle,"party_type",PD_TYPE_MERCHANT);
DEBUGLOG(("TxnMgtByUsMML merchant_id = [%s]\n",csTmp));
	}

	if(GetField_Double(hRequest,"current_bal",&dTmp)){
		PutField_Double(hTxn,"current_bal",dTmp);
DEBUGLOG(("TxnMgtByUsMML current_bal = [%lf]\n",dTmp));
	}

	if(GetField_Double(hRequest,"total_float",&dTmp)){
		PutField_Double(hTxn,"total_float",dTmp);
DEBUGLOG(("TxnMgtByUsMML total_float = [%lf]\n",dTmp));
	}

	if(GetField_Double(hRequest,"total_reserved_amount",&dTmp)){
		PutField_Double(hTxn,"total_reserved_amount",dTmp);
DEBUGLOG(("TxnMgtByUsMML total_reserved_amount = [%lf]\n",dTmp));
	}

	if(GetField_Double(hRequest,"total_hold",&dTmp)){
		PutField_Double(hTxn,"total_hold",dTmp);
DEBUGLOG(("TxnMgtByUsMML total_hold = [%lf]\n",dTmp));
	}

	if(GetField_Double(hRequest,"settlement_in_transit",&dTmp)){
		PutField_Double(hTxn,"settlement_in_transit",dTmp);
DEBUGLOG(("TxnMgtByUsMML settlement_in_transit = [%lf]\n",dTmp));
	}

	if(GetField_Double(hRequest,"merchant_open_bal",&dTmp)){
		PutField_Double(hTxn,"open_bal",dTmp);
DEBUGLOG(("TxnMgtByUsMML open_bal = [%lf]\n",dTmp));
	}

	if (GetField_CString(hRequest, "txn_country", &csTmp)) {
		PutField_CString(hTxn,"txn_country",csTmp);
DEBUGLOG(("TxnMgtByUsMML txn_country = [%s]\n",csTmp));
	}


/*txn psp detail*/
	if(GetField_CString(hRequest,"psp_id",&csTmp)){
		PutField_CString(hPsp,"psp_id",csTmp);
		PutField_Char(hEle,"party_type",PD_TYPE_PSP);
DEBUGLOG(("TxnMgtByUsMML psp_id = [%s]\n",csTmp));
	}

	if(GetField_Double(hRequest,"psp_balance",&dTmp)){
		PutField_Double(hPsp,"bal",dTmp);
DEBUGLOG(("TxnMgtByUsMML psp_balance = [%lf]\n",dTmp));
	}

	if(GetField_Double(hRequest,"psp_total_float",&dTmp)){
		PutField_Double(hPsp,"total_float",dTmp);
DEBUGLOG(("TxnMgtByUsMML psp_total_float = [%lf]\n",dTmp));
	}

	if(GetField_Double(hRequest,"psp_total_hold",&dTmp)){
		PutField_Double(hPsp,"total_hold",dTmp);
DEBUGLOG(("TxnMgtByUsMML psp_total_hold = [%lf]\n",dTmp));
	}

	if(GetField_Int(hRequest,"input_txn_elements",&iInput)){
DEBUGLOG(("TxnMgtByUsMML input_txn_elements = [%d]\n",iInput));
	}






	if(iRet == PD_OK){
DEBUGLOG(("TxnMgtByUsMML ::Call Add Header\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","Add");
		if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK)
			iRet = INT_ERR;
	}

	if(iRet == PD_OK){
DEBUGLOG(("TxnMgtByUsMML ::Call Update Header\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
		if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK)
			iRet = INT_ERR;
	}

	if(iRet==PD_OK){
DEBUGLOG(("TxnMgtByUsMML ::Call DBTransaction:AddDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
		if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK)
			iRet = INT_ERR;
	}

	if(iRet==PD_OK){
DEBUGLOG(("TxnMgtByUsMML ::Call DBTransaction:UpdateDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
		if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK)
			iRet = INT_ERR;
	}

	if(!strcmp(csTxnCode,PD_TRAN_TO_PSP)||
	   !strcmp(csTxnCode,PD_TRAN_FROM_PSP)||
	   !strcmp(csTxnCode,PD_REV_TRAN_FROM_PSP)||
	   !strcmp(csTxnCode,PD_REV_TRAN_TO_PSP)){

		if(iRet==PD_OK){
DEBUGLOG(("TxnMgtByUsMML ::Call DBTxnPspDetail:Add\n"));
			DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
			if((unsigned long) ((*DBObjPtr)(hPsp))!=PD_OK)
				iRet = INT_ERR;
		}

		if(iRet==PD_OK){
DEBUGLOG(("TxnMgtByUsMML ::Call DBTxnPspDetail:Update\n"));
			DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
			if((unsigned long) ((*DBObjPtr)(hPsp))!=PD_OK)
				iRet = INT_ERR;
		}
	}

	if((iRet==PD_OK) && (iInput==PD_TRUE)){
DEBUGLOG(("TxnMgtByUsMML:: Call BOTxnElements:AddTxnAmtElement\n"));
                 BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnAmtElement");
                 iRet = (unsigned long)(*BOObjPtr)(hEle);
DEBUGLOG(("TxnMgtByUsMML:: ret from AddTxnAmtElements = [%d]\n",iRet));
        }


	FREE_ME(hTxn);
	FREE_ME(hPsp);
DEBUGLOG(("TxnMgtByUsMML Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
