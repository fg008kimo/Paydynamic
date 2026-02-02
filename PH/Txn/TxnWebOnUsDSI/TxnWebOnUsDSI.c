/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/05/16              [GOD]
Change Calling Order				   2013/02/25		   [GOD]
for difference ccy case, precal exrate/dstamt	   2013/08/21		   [MSN]
Support VMobile Service New Phase
	update PostTxn				   2017/11/23              [WMC]
Revised PostTxn for PRD255			   2020/03/27		   [MSN]
Revised PostTxn for PRD290			   2020/11/18		   [WMC]
PRD304 Add Customer & PID Counters      	   2021/03/16              [ANC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUsDSI.h"
#include "myrecordset.h"

static char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnWebOnUsDSI(char    cdebug)
{
        cDebug = cdebug;
}

int     PostTxn(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse);
int     AddTxnLog(hash_t *hContext,
                const hash_t* hRequest);
int     UpdateTxnLog(const hash_t* hRequest);

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char*	csTmp = NULL;
	char*	csTxnCcy;
	char*	csMerchantId;
	char*	csServiceCode;
	char*	csDstCcy;
	double	dTmp;

	//hash_t	*hRec;
	hash_t	*hTxn;
	hTxn = (hash_t*) malloc(sizeof(hash_t));
	hash_init(hTxn, 0);

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));

DEBUGLOG(("TxnWebOnUsDSI: Authroize()\n"));

// fe_url
	if (GetField_CString(hResponse,"fe_url",&csTmp)) {
DEBUGLOG(("Authroize: fe_url = [%s]\n",csTmp));
		PutField_CString(hResponse,"redirect_url",csTmp);
	}

	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
		PutField_CString(hTxn,"txn_ccy",csTxnCcy);
		PutField_CString(hTxn,"src_ccy",csTxnCcy);
DEBUGLOG(("Authroize: txn_ccy = [%s]\n",csTxnCcy));
	}

	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
		PutField_CString(hTxn,"merchant_id",csMerchantId);
DEBUGLOG(("Authroize: merchant_id = [%s]\n",csMerchantId));
	}

	if(GetField_CString(hRequest,"service_code",&csServiceCode)){
		PutField_CString(hTxn,"service_code",csServiceCode);
DEBUGLOG(("Authroize: service_code = [%s]\n",csServiceCode));
	}

	DBObjPtr = CreateObj(DBPtr,"DBRuleLB","GetDstCcyWithoutRule");
	if((unsigned long)(DBObjPtr)(csMerchantId,csServiceCode,hTxn)==PD_OK){
		if (GetField_CString(hTxn,"psp_ccy",&csDstCcy)) {
			PutField_CString(hTxn,"dst_txn_ccy",csDstCcy);
			PutField_CString(hTxn,"dst_ccy",csDstCcy);
DEBUGLOG(("Authroize: Get Psp ccy [%s]\n",csDstCcy));
		}
	}

	if(strcmp(csTxnCcy,csDstCcy)){
DEBUGLOG(("Authroize: src and dst ccy are different, do precal...\n"));
                char cExParty;
                double dExRate;
                double dMarkupRate;
                double dMarkupAmt;
                char* csMarkupCcy;
                double dInterRate;
                char* csInterCcy;
                double dDstAmt;
                double dDstTxnFee;
                double dNetAmt;
                double dTxnFee;

		if(GetField_CString(hContext,"txn_seq",&csTmp)){
			PutField_CString(hTxn,"txn_seq",csTmp);
DEBUGLOG(("Authroize: txn_seq = [%s]\n",csTmp));
		}
		if(GetField_CString(hContext,"txn_code",&csTmp)){
			PutField_CString(hTxn,"txn_code",csTmp);
DEBUGLOG(("Authroize: txn_code = [%s]\n",csTmp));
		}

		if(GetField_CString(hContext,"channel_code",&csTmp)){
			PutField_CString(hTxn,"channel_code",csTmp);
DEBUGLOG(("Authroize: channel_code = [%s]\n",csTmp));
		}

		if (GetField_CString(hRequest,"txn_country",&csTmp)) {
			PutField_CString(hTxn,"txn_country",csTmp);
DEBUGLOG(("Authroize: txn_country = [%s]\n",csTmp));
		}

		if(GetField_CString(hContext,"merchant_client_id",&csTmp)){
			PutField_CString(hTxn,"merchant_client_id",csTmp);
DEBUGLOG(("Authroize: merchant_client_id = [%s]\n",csTmp));
		}

		if(GetField_CString(hContext,"selected_pay_method",&csTmp)){
			PutField_CString(hTxn,"selected_pay_method",csTmp);
DEBUGLOG(("Authroize: selected_pay_method = [%s]\n",csTmp));
		}

		if(GetField_Double(hContext,"txn_amt",&dTmp)){
			PutField_Double(hTxn,"txn_amt",dTmp);
DEBUGLOG(("Authroize: txn_amt = [%lf]\n",dTmp));
		}

		PutField_Int(hTxn,"get_info_only",PD_TRUE);
		BOObjPtr = CreateObj(BOPtr,"BOExchange","GetExchangeInfo");
		iRet = (unsigned long)(*BOObjPtr)(hTxn,hTxn);
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo = [%d]\n",iRet));

		if(iRet == PD_OK){
                        BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
                        iRet = (unsigned long)(*BOObjPtr)(hTxn,hTxn);
DEBUGLOG(("Authorize() GetTxnFee result = [%d]\n",iRet));
                }

		if(iRet==PD_OK){
                        if(GetField_Char(hTxn,"ex_party",&cExParty)){
DEBUGLOG(("ex_party = [%c]\n",cExParty));
                        }
                        if(GetField_Double(hTxn,"ex_rate",&dExRate)){
DEBUGLOG(("ex_rate = [%lf]\n",dExRate));
                        }
                        if(GetField_Double(hTxn,"markup_rate",&dMarkupRate)){
DEBUGLOG(("markup_rate = [%lf]\n",dMarkupRate));
                        }
                        if(GetField_Double(hTxn,"markup_amt",&dMarkupAmt)){
DEBUGLOG(("markup_amt = [%lf]\n",dMarkupAmt));
                        }
                        if(GetField_CString(hTxn,"markup_ccy",&csMarkupCcy)){
DEBUGLOG(("markup_ccy = [%s]\n",csMarkupCcy));
                        }
                        if(GetField_Double(hTxn,"inter_rate",&dInterRate)){
DEBUGLOG(("inter_rate = [%lf]\n",dInterRate));
                        }
                        if(GetField_CString(hTxn,"inter_ccy",&csInterCcy)){
DEBUGLOG(("inter_ccy = [%s]\n",csInterCcy));
                        }
                        if(GetField_CString(hTxn,"dst_txn_ccy",&csDstCcy)){
DEBUGLOG(("dst_txn_ccy = [%s]\n",csDstCcy));
                        }
                        if(GetField_Double(hTxn,"dst_net_amt",&dDstAmt)){
DEBUGLOG(("dst_net_amt = [%lf]\n",dDstAmt));
			}
			if(GetField_Double(hTxn,"dst_txn_fee",&dDstTxnFee)){
				PutField_Double(hTxn,"dst_fee",dDstTxnFee);
DEBUGLOG(("dst_txn_fee = [%lf]\n",dDstTxnFee));
                        }
                        if(GetField_Double(hTxn,"net_amt",&dNetAmt)){
				PutField_Double(hTxn,"src_net_amt",dNetAmt);
DEBUGLOG(("net_amt = [%lf]\n",dNetAmt));
                        }
                        if(GetField_Double(hTxn,"src_txn_fee",&dTxnFee)){
				PutField_Double(hTxn,"src_fee",dTxnFee);
DEBUGLOG(("src_txn_fee = [%lf]\n",dTxnFee));
			}

			DBObjPtr = CreateObj(DBPtr,"DBTmpCalAmount","Add");
			if((unsigned long)(DBObjPtr)(hTxn)==PD_OK){
DEBUGLOG(("Authorize() DBTmpCalAmount:Add success\n"));
			}
			else{
DEBUGLOG(("Authorize() DBTmpCalAmount:Add failed!!!\n"));
ERRLOG("TxnWebOnUsDSI: Authorize() DBTmpCalAmount:Add failed!!!\n");
			}
		}

	}
	


	iRet = AddTxnLog(hContext,hRequest);


	FREE_ME(hTxn);
	FREE_ME(rRecordSet);
	//FREE_ME(csTmp);
	

DEBUGLOG(("Normal exit iret = [%d]\n",iRet));	
	return iRet;
}

int     AddTxnLog(hash_t *hContext,
                const hash_t* hRequest)
{
        int iRet = PD_OK;
        hash_t  *hPspDetail;
        char*   csTmp;
//        double  dTmp;

        hPspDetail = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hPspDetail,0);

        PutField_CString(hPspDetail,"add_user",PD_UPDATE_USER);
/* txn_seq  */
        if (GetField_CString(hContext,"txn_seq",&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_seq = [%s]\n",csTmp));
                PutField_CString(hPspDetail,"txn_seq",csTmp);
        }
/* psp id */
        if (GetField_CString(hContext,"psp_id",&csTmp)) {
DEBUGLOG(("AddTxnLog:: psp_id = [%s]\n",csTmp));
                PutField_CString(hPspDetail,"psp_id",csTmp);
        }

/* txn amt*/
/*
        if (GetField_Double(hContext,"psp_txn_amt",&dTmp)) {
DEBUGLOG(("AddTxnLog:: txn_amt = [%f]\n",dTmp));
                PutField_Double(hPspDetail,"txn_amt",dTmp);
        }
*/
/* txn_ccy*/
/*
       if (GetField_CString(hRequest,"txn_ccy",&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_ccy = [%s]\n",csTmp));
                PutField_CString(hPspDetail,"txn_ccy",csTmp);
       }
*/

/* txn_desc */
       if (GetField_CString(hContext,"txn_desc",&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_desc = [%s]\n",csTmp));
                PutField_CString(hPspDetail,"desc",csTmp);
        }
        DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
        iRet = (unsigned long)(*DBObjPtr)(hPspDetail);

        hash_destroy(hPspDetail);
        FREE_ME(hPspDetail);

        return iRet;
};

int     UpdateTxnLog(const hash_t* hRequest)
{
        int iRet = PD_OK;
        hash_t  *hCon;
        char*   csTmp;

        hCon = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hCon,0);

        PutField_CString(hCon,"add_user",PD_UPDATE_USER);

/* txn_seq  */
        if (GetField_CString(hRequest,"txn_seq",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: txn_seq = [%s]\n",csTmp));
                PutField_CString(hCon,"txn_seq",csTmp);
        }

/* bank_code  */
        if (GetField_CString(hRequest,"bank_code",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: bank_code = [%s]\n",csTmp));
                PutField_CString(hCon,"bank_code",csTmp);
        }

        DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
        iRet = (unsigned long)(*DBObjPtr)(hCon);

        hash_destroy(hCon);
        FREE_ME(hCon);

        return iRet;
};



int     PostTxn(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
	int 	iRet = PD_OK;
	double	dPaidAmt = 0.0;
	double 	dDstNetAmt = 0.0;
	char*	csTxnSeq = NULL;
	char*	csCustomerTag = NULL;
	char*	csCustomerGroup = NULL;
	double	dPspCost = 0.0;
	char*	csPspId = NULL;
		
DEBUGLOG(("PostTxn() Start\n"));

/* txn_seq */
     	if (GetField_CString(hContext,"org_txn_seq",&csTxnSeq)) {
DEBUGLOG((" txn_seq = [%s]\n",csTxnSeq));
      	}

/* org_dst_net_amt */
        if (GetField_Double(hContext,"org_dst_net_amt",&dDstNetAmt)) {
DEBUGLOG((" org_dst_net_amt = [%f]\n",dDstNetAmt));
        }

/* paid_amt */
        if (GetField_Double(hContext,"paid_amt",&dPaidAmt)) {
DEBUGLOG((" paid_amt = [%f]\n",dPaidAmt));
        } else {
		dPaidAmt = dDstNetAmt;
	}

	if (dPaidAmt == dDstNetAmt) {
/* Call BOPspPaidAmount(UpdateAmtDetails), only return PD_OK */
DEBUGLOG(("Call BOPspPaidAmount::UpdateAmtDetails()\n"));
		BOObjPtr = CreateObj(BOPtr,"BOPspPaidAmount","UpdateAmtDetails");
        	iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("UpdateAmtDetails result = [%d]\n",iRet));
	} else {
/* Call BOPspPaidAmount(UpdateAmtDetailsByPaidAmt), only return PD_OK */
DEBUGLOG(("Call BOPspPaidAmount::UpdateAmtDetailsByPaidAmt()\n"));
                BOObjPtr = CreateObj(BOPtr,"BOPspPaidAmount","UpdateAmtDetailsByPaidAmt");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("UpdateAmtDetailsByPaidAmt result = [%d]\n",iRet));
	}

/* precal psp cost if rule defined, only return PD_OK */
	if (iRet == PD_OK) {
		PutField_Char(hContext,"txn_type",PD_TYPE_DEPOSIT);
DEBUGLOG(("Call BOPsp::CalPspCosts()\n"));
                BOObjPtr = CreateObj(BOPtr,"BOPsp","CalPspCosts");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);

		if(GetField_Double(hContext, "precal_fee", &dPspCost)){
DEBUGLOG(("CalPspCosts cost = [%lf]\n", dPspCost));
		}
		else{
			if(GetField_Double(hRequest, "service_fee", &dPspCost)){
				PutField_Double(hContext, "precal_fee", dPspCost);
DEBUGLOG(("no rule defined, use the cost returned by PSP = [%lf]\n", dPspCost));
			}
		}
	}

/* Update TxnPspDetail */
	if (iRet == PD_OK) {

		hash_t *hPspDetail;
		hPspDetail= (hash_t*)  malloc (sizeof(hash_t));
       		hash_init(hPspDetail,0);

DEBUGLOG(("Call DBTxnPspDetail::Update()\n"));
		PutField_CString(hPspDetail, "txn_seq", csTxnSeq);
		if (dPspCost > 0.0) {
			PutField_Double(hPspDetail, "service_fee", dPspCost);
		}
		PutField_Double(hPspDetail, "paid_amount", dPaidAmt);
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
		iRet = (unsigned long)(*DBObjPtr)(hPspDetail);
DEBUGLOG(("Update result = [%d]\n",iRet));

		hash_destroy(hPspDetail);
                FREE_ME(hPspDetail);
	}


/* Update Stat */
	if (iRet == PD_OK) {
DEBUGLOG(("Call BOStat::UpdateDspStat\n"));
                BOObjPtr = CreateObj(BOPtr,"BOStat","UpdateDspStat");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("UpdateDspStat result = [%d]\n",iRet));
	}


	if (iRet == PD_OK) {
DEBUGLOG(("Call BOStat::UpdateDspMerchantStat()\n"));
                BOObjPtr = CreateObj(BOPtr,"BOStat","UpdateDspMerchantStat");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("UpdateDspMerchantStat result = [%d]\n",iRet));
	}

	if (iRet == PD_OK) {
/* Found customer_group,let's insert counter*/
		if (GetField_CString(hContext,"org_customer_group",&csCustomerGroup) &&
		    GetField_CString(hContext,"org_customer_tag",&csCustomerTag)){
DEBUGLOG(("Call BOStat::UpdateCustomerGroupCounter()\n"));
                		BOObjPtr = CreateObj(BOPtr,"BOStat","UpdateCustomerGroupCounter");
				iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("UpdateDspMerchantStat result = [%d]\n",iRet));
		}

	}

/* PRD304 Assign PID Based on PID Daily Threshold and Customer ID */
/* Update Customer PID Counters */
	if (iRet == PD_OK) {
		if (GetField_CString(hContext,"org_customer_tag",&csCustomerTag) &&
		    GetField_CString(hContext,"org_customer_group",&csCustomerGroup) &&
		    GetField_CString(hContext,"org_psp_id",&csPspId)){
			PutField_CString(hContext,"upd_category","CNT");
			PutField_Double(hContext,"upd_counter",1.0);
DEBUGLOG(("Call BOStat::UpdateCustomerPspCounter()\n"));
			BOObjPtr = CreateObj(BOPtr,"BOStat","UpdateCustomerPspCounter");
			iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("UpdateCustomerPspCounter result = [%d]\n",iRet));
		}
	}
/* End - PRD304 Assign PID Based on PID Daily Threshold and Customer ID */

/* update Balance at the end to shortend the row lock time */
	if (iRet == PD_OK) {
DEBUGLOG(("Call BOBalance::UpdateTxnAmount()\n"));
                BOObjPtr = CreateObj(BOPtr,"BOBalance","UpdateTxnAmount");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("UpdateTxnAmount result = [%d]\n",iRet));
	}

DEBUGLOG(("PostTxn() Normal exit iret = [%d]\n",iRet));	
	return iRet;
}
