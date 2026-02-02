/*
PDProTech (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/01/04              [GOD]
Add Override value ratio and Priority from pool    2012/02/01		   [GOD]
Mapping
CheckScheduler more than one rule		   2012/02/13		   [MSN]
Remove PSP detail's ratio and Priority             2012/12/19		   [GOD]
Random Select PSP if the Priority is the Same
Add Criteria Priority
when pickpsp check the business type 
and bank also					   2013/01/17		   [MSN]
bug fix for select Pool if bank is disabled        2013/03/04		   [GOD]
Check psp limit before bank selection		   2013/03/20		   [STP]
filter psp by checking small delta amount	   
check ip is restricted or not		 	   2013/04/11		   [MSN]
also support TWV case				   2013/05/06		   [MSN]
fix for multiple segment New scheme		   2015/02/27		   [MSN]

Support Card type option			   2016/10/20		   [MSN]
Function Added:
	1. GetTxnPsp_Card
	2. ProcessScheme
	3. FindPotentialPool
	4. FindPoolDetail
	5. PickPspFromPool
	6. FindPoolPspDetail
Add PID Group Checking for NBG		   	   2017/10/13		   [WMC] 
Support VMobile Payment for New Phase
	update GetTxnPsp
        update GetTxnPsp_Card                 	   2017/11/23              [WMC]
Add PSP Restrict IP Region Checking in		   2021/01/18		   [WMC]
	FindPoolPspDetail
Add PSP Customer Txn Threshold Checking in         2021/03/23		   [MIC]
	FindPoolPspDetail
Handle multiple IPs				   2021/06/04		   [WCS]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "myrecordset.h"
#include "internal.h"
#include "common.h"
#include "BOTxnLb.h"
#include <math.h>

static char    cDebug;

OBJPTR(DB);
OBJPTR(BO);
void BOTxnLb(char    cdebug)
{
        cDebug = cdebug;
}

int CheckAmountTier(double dMinTxnAmt, double dMaxTxnAmt, double dTxnAmt);
int CheckScheduler(int iId,const char* csDateTime);
int GetPool(int iId,recordset_t* rRs);
int CheckPools(double dTxnAmt,
		const char* csServiceCode,
                const char* csTxnCountry,
                const char* csTxnCcy,
                const char* csPayMethod,
		const char* csBankCode,
		hash_t*	hPsp,
		recordset_t *,
		char*,
		const char* csOrgDateTime);

int CheckPoolLimit(int iId,
		const char* csServiceCode,
		const char* csTxnCountry,
		const char* csTxnCcy,
		const char* csPayMethod,
		double	dTxnAmt,
		double dLimit,
		double *dCurr,
		double *dTotalCurr,
		double *dReqCurr,
		double *dTotalReqCurr);
int PickPsp(hash_t* hPsp,
		int iId,
		const char* csBankCode,
		const char* csPayMethod,
		const char* csServiceCode,
		const char* csTxnCountry,
		const char* csTxnCcy,
		char*	csSelectedPspId,
		double	dTxnAmt,
		const char* csOrgDateTime);

int CheckPspLimit(const char* csId,
		const char* csServiceCode,
		const char* csTxnCountry,
		const char* csTxnCcy,
		const char* csPayMethod,
		double dTxnAmt,
		double dLimit,
		double *dCurr,
		double *dTotalCurr,
		double *dReqCurr,
		double *dTotalReqCurr);

int ProcessScheme(hash_t *hIn, hash_t *hOut);
int FindPotentialPool(hash_t *hIn,recordset_t* rRs);
int FindPoolDetail(hash_t *hIn, hash_t *hOut);
int PickPspFromPool(hash_t *hIn, hash_t *hOut);
int FindPoolPspDetail(hash_t *hIn, hash_t *hOut);

int GetTxnPsp(hash_t *hContext,
                const hash_t* hRequest)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	cPtr;
	char	*csOrgTxnSeq;
	char	*csMerchantId;
	char	*csServiceCode;
	char	*csTxnCountry;
	char	*csTxnCcy;
	char	*csPspCcy; 
	char	*csPayMethod;
	char	*csOrgDateTime;
	char	*csBankCode;
	char	*csCustomerGroup = NULL;
	char	*csSchemeGroup;
	char	csSelectedPspId[PD_PSP_ID_LEN +1];
	char	csTag[PD_TAG_LEN +1];
	double	dTxnAmt = 0.0;
	double	dPspAmt = 0.0;
	double	dTmp= 0.0;
	int	iChk = 0;
	int	iBackUpByOverFlow = PD_TRUE;
	int	iCustSegEnabled = PD_FALSE;
	double	dDefSmallAmt = 50.0;
	int	iPhase = 0;
	
	hash_t	*hReq, *hRec;
	hash_t	*hPsp, *hTmpPsp;
	hash_t	*hTxn;
	recordset_t     *rRecordSet;
	recordset_t     *rRs;


DEBUGLOG(("GetTxnPsp()\n"));
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
       	recordset_init(rRecordSet,0);	

	rRs = (recordset_t*) malloc (sizeof(recordset_t));
       	recordset_init(rRs,0);	
 
	hReq = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hReq,0);

	hPsp = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hPsp,0);
	hTmpPsp = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTmpPsp,0);


/* channel Code */
	if (GetField_CString(hContext,"channel_code",&csPtr)) {
DEBUGLOG(("GetTxnPsp() Channel Code = [%s]\n",csPtr));
		PutField_CString(hReq,"channel_code",csPtr);
	}
	else {
DEBUGLOG(("GetTxnPsp() channel Code is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp() channel Code is missing!!!\n");
		iRet = PD_ERR;
	}

/* service code  */
	if (GetField_CString(hRequest,"service_code",&csServiceCode)) {
DEBUGLOG(("GetTxnPsp() service_code = [%s]\n",csServiceCode));
		PutField_CString(hReq,"service_code",csServiceCode);
	}
	else if (GetField_CString(hContext,"org_service_code",&csServiceCode)) {
DEBUGLOG(("GetTxnPsp() service_code = [%s]\n",csServiceCode));
		PutField_CString(hReq,"service_code",csServiceCode);
	}
	else {
DEBUGLOG(("GetTxnPsp() service_code is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp() service_code is missing!!!\n");
		iRet = PD_ERR;
	}

/* payment_method  */
	if (GetField_CString(hContext,"selected_pay_method",&csPayMethod)) {
DEBUGLOG(("GetTxnPsp() selected_pay_method  = [%s]\n",csPayMethod));
		PutField_CString(hReq,"pay_method",csPayMethod);
	}
	else {
DEBUGLOG(("GetTxnPsp() selected_pay_method  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp() selected_pay_method is missing!!!\n");
	}

/* txn_country  */
	if (GetField_CString(hRequest,"txn_country",&csTxnCountry)) {
DEBUGLOG(("GetTxnPsp() txn_country  = [%s]\n",csTxnCountry));
		PutField_CString(hReq,"txn_country",csTxnCountry);
	}
	else if (GetField_CString(hContext,"org_txn_country",&csTxnCountry)) {
DEBUGLOG(("GetTxnPsp() txn_country  = [%s]\n",csTxnCountry));
		PutField_CString(hReq,"txn_country",csTxnCountry);
	}
	else {
DEBUGLOG(("GetTxnPsp() txn_country  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp() txn_country  is missing!!!\n");
		iRet = PD_ERR;
	}

/* txn_ccy  */
	if (GetField_CString(hRequest,"txn_ccy",&csTxnCcy)) {
DEBUGLOG(("GetTxnPsp() txn_ccy  = [%s]\n",csTxnCcy));
		PutField_CString(hReq,"txn_ccy",csTxnCcy);
	}
	else if (GetField_CString(hContext,"org_txn_ccy",&csTxnCcy)) {
DEBUGLOG(("GetTxnPsp() txn_ccy  = [%s]\n",csTxnCcy));
		PutField_CString(hReq,"txn_ccy",csTxnCcy);
	}
	else {
DEBUGLOG(("GetTxnPsp() txn_ccy  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp() txn_ccy  is missing!!!\n");
		iRet = PD_ERR;
	}

/* merchant_id  */
	if (GetField_CString(hRequest,"merchant_id",&csMerchantId)) {
DEBUGLOG(("GetTxnPsp() merchant_id  = [%s]\n",csMerchantId));
		PutField_CString(hReq,"merchant_id",csMerchantId);
	}
	else if (GetField_CString(hContext,"org_merchant_id",&csMerchantId)) {
DEBUGLOG(("GetTxnPsp() merchant_id  = [%s]\n",csMerchantId));
		PutField_CString(hReq,"merchant_id",csMerchantId);
	}
	else {
DEBUGLOG(("GetTxnPsp() merchant_id  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp() merchant_id  is missing!!!\n");
		iRet = PD_ERR;
	}

/* merchant_clinet_id  */
	if (GetField_CString(hRequest,"client_id",&csPtr)) {
DEBUGLOG(("GetTxnPsp() client_id  = [%s]\n",csPtr));
		PutField_CString(hReq,"client_id",csPtr);
	}
	else if (GetField_CString(hContext,"org_client_id",&csPtr)) {
DEBUGLOG(("GetTxnPsp() client_id  = [%s]\n",csPtr));
		PutField_CString(hReq,"client_id",csPtr);
	}
	else {
DEBUGLOG(("GetTxnPsp() merchant_client_id  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp() merchant_client_id  is missing!!!\n");
		iRet = PD_ERR;
	}

/* business_type */
	if (GetField_Char(hContext,"org_merchant_type",&cPtr)) {
DEBUGLOG(("GetTxnPsp() merchant_type  = [%c]\n",cPtr));
		PutField_Char(hReq,"business_type",cPtr);
	}
	else {
DEBUGLOG(("GetTxnPsp() merchant_type  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp() merchant_type  is missing!!!\n");
		iRet = PD_ERR;
	}
/* customer_tag */
	//if (GetField_CString(hContext,"customer_tag",&csPtr)) {
	if (GetField_CString(hContext,"customer_group",&csCustomerGroup)) {
DEBUGLOG(("GetTxnPsp() customer_group (tag)  = [%s]\n",csCustomerGroup));
		PutField_CString(hReq,"customer_tag",csCustomerGroup);

		DBObjPtr = CreateObj(DBPtr,"DBCustomerGroup","isBackUpByOverflow");
		iBackUpByOverFlow = (unsigned long)(DBObjPtr)(csCustomerGroup);
	}

	if(GetField_Int(hContext,"cust_seg_enabled",&iCustSegEnabled)){
DEBUGLOG(("GetTxnPsp() customer_segment_enabled  = [%d]\n",iCustSegEnabled));
	}

/* txn_amt */
	if (GetField_Double(hRequest,"txn_amt",&dTxnAmt)) {
		dPspAmt = dTxnAmt;
DEBUGLOG(("GetTxnPsp() txn_amt  = [%f]\n",dTxnAmt));
	}
	else if (GetField_Double(hContext,"org_txn_amt",&dTxnAmt)) {
		dPspAmt = dTxnAmt;
DEBUGLOG(("GetTxnPsp() txn_amt  = [%f]\n",dTxnAmt));
	}
	else {
DEBUGLOG(("GetTxnPsp() txn_amt  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp() txn_amt  is missing!!!\n");
		iRet = PD_ERR;
	}

	char*   csValueTmp;
	csValueTmp = (char*) malloc (128);
	DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
	if ((unsigned long)(DBObjPtr)("LB_SMALL_AMT",csValueTmp) == FOUND) {
		sscanf(csValueTmp, "%lf",&dDefSmallAmt);
DEBUGLOG(("SystemParameter::Define Load Balance Small Amount = [%lf]\n",dDefSmallAmt));
	}
	FREE_ME(csValueTmp);

/* psp amt*////for difference currency
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);
	DBObjPtr = CreateObj(DBPtr,"DBRuleLB","GetDstCcyWithoutRule");
	if((unsigned long)(DBObjPtr)(csMerchantId,csServiceCode,hTxn)==PD_OK){
		if (GetField_CString(hTxn,"psp_ccy",&csPspCcy)) {
DEBUGLOG(("BOTxnLb() Get Psp ccy [%s]\n",csPspCcy));
		}
	}
	if(strcmp(csTxnCcy,csPspCcy) &&
           GetField_CString(hContext,"from_txn_seq",&csOrgTxnSeq)){
		DBObjPtr = CreateObj(DBPtr,"DBTmpCalAmount","GetTmpCalAmount");
                if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq,hContext) == PD_FOUND) {
                        if(GetField_Double(hContext,"dst_net_amt",&dTmp)){
                                dPspAmt = dTmp;
				PutField_Double(hContext,"dst_txn_amt",dPspAmt);
DEBUGLOG(("Authorize() GetTmpCalAmount Found psp_amt [%lf]\n",dPspAmt));
                        }
                }
	}


/* org_local_tm_datetime  */
	if (GetField_CString(hContext,"org_local_tm_datetime",&csOrgDateTime)) {
DEBUGLOG(("GetTxnPsp() org_local_tm_datetime  = [%s]\n",csOrgDateTime));
	}
	else {
DEBUGLOG(("GetTxnPsp() org_local_tm_datetime  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp() org_local_tm_datetime  is missing!!!\n");
		iRet = PD_ERR;
	}

/* bank_code  */
	//if (GetField_CString(hRequest,"bank_code",&csBankCode)) {
	if (GetField_CString(hContext,"bank_code",&csBankCode)) {
		iChk=PD_TRUE;
DEBUGLOG(("GetTxnPsp() bank_code  = [%s]\n",csBankCode));

		//if mobile service, check phase
                if(!strcmp(csServiceCode,PD_MOBILE_SERVICE)){
                        DBObjPtr = CreateObj(DBPtr,"DBCustomerGroupMerchant","GetMerchantPhase");
                        iPhase = (unsigned long)(DBObjPtr)(csMerchantId);
DEBUGLOG(("GetTxnPsp() GetMerchantPhase: phase = [%d]\n",iPhase));
                }

		//if mobile service, check if override customer_tag is needed (Phase 0)
		if((!strcmp(csServiceCode,PD_MOBILE_SERVICE)) && (iPhase<1)){
			//can be found in mob_bank_map?
			DBObjPtr = CreateObj(DBPtr,"DBMobBankMap","GetMobileSegment");
			if ((unsigned long)(DBObjPtr)(csMerchantId,
						csBankCode,
						hTxn) == PD_FOUND) {
				if(GetField_CString(hTxn,"mob_segment",&csPtr)){

					if(csCustomerGroup==NULL){
						//get temp group from txn_detail
						if (GetField_CString(hContext,"temp_customer_group",&csCustomerGroup)) {
							if(strcmp(csPtr,csCustomerGroup)){
								PutField_CString(hReq,"customer_tag",csPtr);
DEBUGLOG(("GetTxnPsp() Customer Group[%s] not match with the selected bank option[%s]. Search by [%s]\n",csCustomerGroup,csPtr,csPtr));
							}
							else{
								PutField_CString(hReq,"customer_tag",csCustomerGroup);
							}
						}
						else{
							PutField_CString(hReq,"customer_tag",csPtr);
DEBUGLOG(("GetTxnPsp() Temp Customer Group not found. Search by [%s]\n",csPtr));
						}
					}
					else{
						if(strcmp(csPtr,csCustomerGroup)){
							PutField_CString(hReq,"customer_tag",csPtr);
DEBUGLOG(("GetTxnPsp() Customer Group[%s] not match with the selected bank option[%s]. Search by [%s]\n",csCustomerGroup,csPtr,csPtr));
						}
					}

				}
			}
			else{ //override by def group
				DBObjPtr = CreateObj(DBPtr,"DBMobBankSelection","GetDefSegment");
				if ((unsigned long)(DBObjPtr)(csMerchantId,
							hTxn) == PD_FOUND) {
					if(GetField_CString(hTxn,"def_segment",&csPtr)){
						PutField_CString(hReq,"customer_tag",csPtr);
DEBUGLOG(("GetTxnPsp() Customer Group[%s] not related to the selected bank[%s]. Search by Default[%s]\n",csCustomerGroup,csBankCode,csPtr));
					}
				}
			}
		}
	}
	else {
		DBObjPtr = CreateObj(DBPtr,"DBService","IsSelectBank");
		iChk= (unsigned long)(DBObjPtr)(csServiceCode);
		if(iChk==PD_TRUE){
DEBUGLOG(("GetTxnPsp() bank_code  is missing!!!\n"));
ERRLOG("BOTxnLB::GetTxnPsp() bank_code  is missing!!!\n");
			iRet = PD_ERR;
		}
	}

	if(iRet ==PD_OK){
		if(iChk==PD_TRUE){
/* check available psp first */
DEBUGLOG(("GetTxnPsp() Call BOBank:GetAvailablePspByBank\n"));
			BOObjPtr = CreateObj(BOPtr,"BOBank","GetAvailablePspByBank");
        		if ((unsigned long)(*BOObjPtr)(csBankCode,csTxnCountry,csOrgDateTime,hTmpPsp) == PD_OK) {
        		        int     iPtr = 0;
				if (GetField_Int(hTmpPsp,"psp_id_cnt",&iPtr)) {
DEBUGLOG(("GetTxnPsp() psp id cnt = [%d]\n",iPtr));
				}
				if (iPtr == 0 ) {
DEBUGLOG(("GetTxnPsp() no aval psp for this bank [%s]\n",csBankCode));
        	                	iRet = INT_PSP_NOT_AVAILABLE;
				}
			}
			else {
DEBUGLOG(("GetTxnPsp() no aval psp for this bank [%s]\n",csBankCode));
                		iRet = INT_PSP_NOT_AVAILABLE;
			}
		}
		else{
/*get available psp by pay method*/
			int iCnt = 0;
			double dLimit = 0.0;
			recordset_init(rRecordSet,0);
			DBObjPtr = CreateObj(DBPtr,"DBServicePayMethod","GetPayMethodInfo");
			if ((unsigned long)(DBObjPtr)(csServiceCode,rRecordSet) == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);
				while(hRec){
					sprintf(csTag,"psp_id_%d",iCnt);
					if (GetField_CString(hRec,"psp_id",&csPtr)) {
						DBObjPtr = CreateObj(DBPtr,"DBRulePspLbPsp","GetPsp");
						if((unsigned long)(*DBObjPtr)(csPtr,hRec)==PD_OK){
							dLimit = 0.0;
							GetField_Double(hRec,"psp_limit",&dLimit);
							if(dLimit>0.0){
								PutField_CString(hTmpPsp,csTag,csPtr);
								iCnt++;
								PutField_Int(hTmpPsp,"psp_id_cnt",iCnt);
							}
						}
DEBUGLOG(("GetTxnPsp() Find Psp by PayMethod[%s]\n",csPtr));
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
		}
	}
//////filter psp by checking small delta amount
	if(iRet == PD_OK){
DEBUGLOG(("GetTxnPsp() Call BODeltaAmt:FilterAvailablePsp\n"));
		BOObjPtr = CreateObj(BOPtr,"BODeltaAmt","FilterAvailablePsp");
		if ((unsigned long)(*BOObjPtr)(hContext,hTmpPsp,hPsp,dPspAmt)==PD_OK){
			int     iPtr = 0;
			if (GetField_Int(hPsp,"psp_id_cnt",&iPtr)) {
DEBUGLOG(("GetTxnPsp() psp id cnt = [%d]\n",iPtr));
			}
			if (iPtr == 0 ) {
DEBUGLOG(("GetTxnPsp() no aval psp for amount [%lf]\n",dTxnAmt));
                        	iRet = INT_PSP_NOT_AVAILABLE;
			}
		}
	}

	PutField_Int(hReq,"restricted_ip",PD_FALSE);
	if(iRet == PD_OK){
//////Check if the service have included restricted IP rule(s)
		DBObjPtr = CreateObj(DBPtr,"DBRuleLB","HaveDefineRuleByService");
                if ((unsigned long)(DBObjPtr)(csServiceCode) == PD_FOUND) {
DEBUGLOG(("GetTxnPsp() check if deposit request is come from special region\n"));
/////check if deposit request is come from special region
			if(GetField_CString(hRequest,"ip_addr", &csPtr)){
DEBUGLOG(("GetTxnPsp() check ip_addr [%s]\n",csPtr));
				DBObjPtr = CreateObj(DBPtr,"DBIpFilter","GetIpFilter");
				if ((unsigned long)((*DBObjPtr)(csPtr)) == PD_FOUND) {
					PutField_Int(hReq,"restricted_ip",PD_TRUE);
DEBUGLOG(("GetTxnPsp() restricted ip [%s]\n",csPtr));
				}
			}
		}
		else{
DEBUGLOG(("GetTxnPsp() ignore restricted ip checking\n"));
		}
	}

	if (iRet == PD_OK) {
		//int	iTxnAmountTierId = 0;
		int	iCriteriaPoolId = 0;
		int	iSchedulerId = 0;
		int	iPriority = 0;
		int	iCnt = 0;
		int	iGcnt = 0;

		double	dMinTxnAmt = 0.0;
		double	dMaxTxnAmt = 0.0;

		recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBRuleLB","MatchCriteria");	
		if ((unsigned long)(*DBObjPtr)(hReq,rRecordSet) == PD_FOUND) {
			hRec = RecordSet_GetFirst(rRecordSet);
                	while (hRec) {
/*txn amount tier */
/*
				if (GetField_Int(hRec,"amount_tier_id",&iTxnAmountTierId)) {
DEBUGLOG(("GetTxnPsp() [%02d] amount_tier_id = [%d]\n",iCnt,iTxnAmountTierId));
				}
*/

				if (GetField_Double(hRec, "min_txn_amount", &dMinTxnAmt)) {
DEBUGLOG(("GetTxnPsp() [%02d] min_txn_amount = [%lf]\n",iCnt,dMinTxnAmt));
				}

				if (GetField_Double(hRec, "max_txn_amount", &dMaxTxnAmt)) {
					if(dMaxTxnAmt<=dDefSmallAmt && dMaxTxnAmt>0.0){
						PutField_Int(hRec,"small_amount_scheme",PD_TRUE);
					}
					else{
						PutField_Int(hRec,"small_amount_scheme",PD_FALSE);
					}
DEBUGLOG(("GetTxnPsp() [%02d] max_txn_amount = [%lf]\n",iCnt,dMaxTxnAmt));
				}

/*criteria_pool id */
				if (GetField_Int(hRec,"criteria_pool_id",&iCriteriaPoolId)) {
DEBUGLOG(("GetTxnPsp() [%02d] criteria_pool_id = [%d]\n",iCnt,iCriteriaPoolId));
				}
/*scheduler id */
				if (GetField_Int(hRec,"scheduler_id",&iSchedulerId)) {
DEBUGLOG(("GetTxnPsp() [%02d] scheduler_id = [%d]\n",iCnt,iSchedulerId));
				}
/* priority */
				if (GetField_Int(hRec,"priority",&iPriority)) {
DEBUGLOG(("GetTxnPsp() [%02d] priority = [%d]\n",iCnt,iPriority));
				}

				//if (CheckAmountTier(iTxnAmountTierId,dTxnAmt) == PD_OK)  
				if (CheckAmountTier(dMinTxnAmt, dMaxTxnAmt, dTxnAmt) == PD_OK)  
				{
DEBUGLOG(("GEtTxnPsp() [%02d] passed CheckAmount Tier\n",iCnt));
					if (CheckScheduler(iSchedulerId,csOrgDateTime) == PD_OK)  {
DEBUGLOG(("GEtTxnPsp() [%02d] this looks good\n",iCnt));
						iGcnt++;
						RecordSet_Add(rRs,hRec);
					}
					else {
DEBUGLOG(("GEtTxnPsp() [%02d] failed CheckScheduler Tier\n",iCnt));
					}
				}
				else {
DEBUGLOG(("GEtTxnPsp() [%02d] failed CheckAmount Tier\n",iCnt));
				}

				hRec = RecordSet_GetNext(rRecordSet);
				iCnt++;
			}
		}

		if (iGcnt == 0) {
DEBUGLOG(("BOTxnLb:GetTxnPsp LoadBalancer could not find any rule!!!\n"));
ERRLOG("FATAL ERROR:BOTxnLb:GetTxnPsp LoadBalancer could not find any rule!!!\n");
			iRet = INT_NO_LB_RECORD;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	if (iRet == PD_OK) {
DEBUGLOG(("GetTxnPsp next level\n"));
		int iCnt = 0;
		int iCriteriaPoolId;
		int iSmallAmount = PD_FALSE;
		int iCheckNextScheme = PD_FALSE;
		int iNeedBreak = PD_TRUE;
		char *csTmpGroup;
		hash_t	*hRec;

		recordset_t	*rPools;

		rPools = (recordset_t*) malloc (sizeof(recordset_t));

		hRec = RecordSet_GetFirst(rRs);
		iRet = PD_ERR;
                while (hRec && iRet != PD_OK) {
        		recordset_init(rPools,0);
			if (GetField_Int(hRec,"criteria_pool_id",&iCriteriaPoolId)) {
DEBUGLOG(("GetTxnPsp() [%02d] criteria_pool_id = [%d]\n",iCnt,iCriteriaPoolId));
				
				if(iCheckNextScheme){
					iNeedBreak = PD_TRUE;
					if(GetField_CString(hRec,"out_customer_tag",&csTmpGroup)){
						if(!strcmp(csTmpGroup,csCustomerGroup)){
							iNeedBreak = PD_FALSE;
						}
					}
					if(iNeedBreak){
DEBUGLOG(("GetTxnPsp() The [%s]Scheme(s) not available, Skip others schemes!!!\n",csSchemeGroup));
						hRec = RecordSet_GetNext(rRs);
						continue;
					}
				}

				iRet =  GetPool(iCriteriaPoolId,rPools);
				if (iRet == PD_OK) {
					iRet = CheckPools(dPspAmt,
							csServiceCode,
							csTxnCountry,
							csPspCcy,//csTxnCcy,
							csPayMethod,
							csBankCode,
							hPsp,
							rPools,
							csSelectedPspId,
							csOrgDateTime);
				}
				if(iRet!= PD_OK && iCustSegEnabled){
					iSmallAmount = PD_FALSE;
					if(GetField_Int(hRec,"small_amount_scheme",&iSmallAmount)){
						if(iSmallAmount){
DEBUGLOG(("GetTxnPsp() The Small Amount Scheme not available, Skip others schemes!!!\n"));
							break;
						}
					}

					if(GetField_CString(hRec,"out_customer_tag",&csSchemeGroup)){
						if(!iBackUpByOverFlow && !strcmp(csSchemeGroup,csCustomerGroup)){
							iCheckNextScheme = PD_TRUE;
//DEBUGLOG(("GetTxnPsp() The [%s]Scheme not available, Skip others schemes!!!\n",csSchemeGroup));
							//break;
						}
					}
				}
			}
			RecordSet_Destroy(rPools);
			hRec = RecordSet_GetNext(rRs);
		}
       		FREE_ME(rPools);
		if (iRet == PD_OK) {
DEBUGLOG(("GetTxnPsp PSP ID [%s] will be appiled for this txn\n",csSelectedPspId));
			PutField_CString(hContext,"psp_id",csSelectedPspId);

		}
	}

	hash_destroy(hTmpPsp);
        FREE_ME(hTmpPsp);
	hash_destroy(hPsp);
        FREE_ME(hPsp);
	FREE_ME(hTxn);

	hash_destroy(hReq);
        FREE_ME(hReq);

	RecordSet_Destroy(rRs);
       	FREE_ME(rRs);

	RecordSet_Destroy(rRecordSet);
       	FREE_ME(rRecordSet);

DEBUGLOG(("GetTxnPsp() exit iRet = [%d]\n",iRet));
	return iRet;
}

int CheckAmountTier(double dMinTxnAmt, double dMaxTxnAmt, double dTxnAmt)
{
        int             iRet = PD_ERR;

        //double  dMaxVal = 0;
        //double  dMinVal = 0;
        //char    *csDesc;

DEBUGLOG(("CheckAmountTier()\n"));
DEBUGLOG(("CheckAmountTier() min_txn_amt = [%lf] max_txn_amt = [%lf] and Txn Amt = [%f]\n",dMinTxnAmt, dMaxTxnAmt, dTxnAmt));

	if (dTxnAmt >= dMinTxnAmt && (dTxnAmt <= dMaxTxnAmt || dMaxTxnAmt == 0.0)) { 
DEBUGLOG(("CheckAmountTier() min_txn_amt [%lf] max_txn_amt [%lf]  will be applied\n",dMinTxnAmt, dMaxTxnAmt ));
                        iRet = PD_OK;
        }
	else {
DEBUGLOG(("CheckAmountTier() min_txn_amt [%lf] max_txn_amt [%lf] will be filter out!!!\n",dMinTxnAmt, dMaxTxnAmt));
        }

DEBUGLOG(("CheckAmountTier exit iRet = [%d]\n",iRet));
        return  iRet;
}


int CheckScheduler(int iId,const char* csTxnDateTime)
{
	int	iRet = PD_ERR;
	recordset_t     *rRecordSet;
	hash_t	*hRec;
	char	cMode;
	char	*csStartDateTime;
	char	*csEndDateTime;
	char	*csStartTime;
	char	*csEndTime;
	char	csTime[PD_TIME_LEN +1];
	int	iDayOfWeek;
	int	iDay;
DEBUGLOG(("CheckSchedulerId()\n"));
DEBUGLOG(("CheckSchedulerId() id = [%d] txn datetime = [%s]\n",iId,csTxnDateTime));
	iDayOfWeek = day_of_week((const unsigned char*)csTxnDateTime);
	memcpy(csTime,&csTxnDateTime[PD_DATE_LEN],PD_TIME_LEN);
	csTime[PD_TIME_LEN] = '\0';
DEBUGLOG(("CheckSchedulerId() txn datetime = [%s] txn time = [%s]\n",csTxnDateTime,csTime));
	

DEBUGLOG(("CheckSchedulerId() day of week = [%d]\n",iDayOfWeek));

	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	DBObjPtr = CreateObj(DBPtr,"DBRuleSchedulerHeader","GetIdDetail");	
	if ((unsigned long)(*DBObjPtr)(iId,rRecordSet) == PD_FOUND) {
		iRet = PD_ERR;
		hRec = RecordSet_GetFirst(rRecordSet);
		while(hRec && (iRet==PD_ERR)){
			if (GetField_Char(hRec,"schedule_mode",&cMode)) {
DEBUGLOG(("CheckSchedulerId() schedule_mode = [%c]\n",cMode));
			}
			if (cMode == PD_SCHEDULER_ONCE || cMode == PD_SCHEDULER_MIX ) {
				if (GetField_CString(hRec,"start_datetime",&csStartDateTime)) {
DEBUGLOG(("CheckSchedulerId() start_datetime = [%s]\n",csStartDateTime));
					if (memcmp(csTxnDateTime,csStartDateTime,PD_DATETIME_LEN) >= 0) {
						if (GetField_CString(hRec,"end_datetime",&csEndDateTime)) {
DEBUGLOG(("CheckSchedulerId() end_datetime = [%s]\n",csEndDateTime));
							if (memcmp(csTxnDateTime,csEndDateTime,PD_DATETIME_LEN) > 0) {
DEBUGLOG(("CheckSchedulerId() id [%d] [%s] had expired\n",iId,csEndDateTime));
								iRet = PD_ERR;
							}
							else
								iRet = PD_OK;
						}
						else
							iRet = PD_OK;
					}
					else {
DEBUGLOG(("CheckSchedulerId() id [%d] [%s] not yet in range\n",iId,csStartDateTime));
						iRet = PD_ERR;
					}
				}
			}

			if ((cMode == PD_SCHEDULER_RECURR && iRet == PD_ERR) ||
			    (cMode == PD_SCHEDULER_MIX && iRet == PD_OK)) {
				if (GetField_Int(hRec,"day",&iDay)) {
DEBUGLOG(("CheckSchedulerId() iDay = [%d]\n",iDay));
					if (iDay != 7 && iDay != iDayOfWeek)  {
						iRet = PD_ERR;
DEBUGLOG(("CheckSchedulerId() not today!!!\n"));
					}
					else {
						if (GetField_CString(hRec,"start_time",&csStartTime)) {
DEBUGLOG(("CheckSchedulerId() start_time = [%s]\n",csStartTime));
                                			if (memcmp(csTime,csStartTime,PD_TIME_LEN) >= 0) {
                                        			if (GetField_CString(hRec,"end_time",&csEndTime)) {
DEBUGLOG(("CheckSchedulerId() end_datetime = [%s]\n",csEndTime));
                                                			if (memcmp(csTime,csEndTime,PD_TIME_LEN) > 0) {
DEBUGLOG(("CheckSchedulerId() id [%d] [%s] had expired\n",iId,csEndTime));
                                                        			iRet = PD_ERR;
                                                			}
									else
										iRet=PD_OK;
                                        			}
								else
									iRet=PD_OK;
                                			}
                                			else {
DEBUGLOG(("CheckSchedulerId() id [%d] [%s] not yet in range\n",iId,csStartDateTime));
                                        			iRet = PD_ERR;
                                			}
						}
					}
				}
				else {
DEBUGLOG(("CheckSchedulerId() can't get day tag!!!\n"));
					iRet = PD_ERR;
				}
			}
			hRec = RecordSet_GetNext(rRecordSet);
		}//end while
	}

	RecordSet_Destroy(rRecordSet);
       	FREE_ME(rRecordSet);
DEBUGLOG(("CheckSchedulerId exit iRet = [%d]\n",iRet));
	return	iRet;
}


int GetPool(int iId,recordset_t* rRs)
{
	int	iRet = PD_OK;
	char	*csPtr;
	double 	dPtr;
	int	iPtr;

	hash_t	*hRec;
        recordset_t     *rRecordSet;

	hash_t	*hRsp;

DEBUGLOG(("GetPool()\n"));
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	DBObjPtr = CreateObj(DBPtr,"DBRulePspLbPools","GetDetailById");	
	if ((unsigned long)(*DBObjPtr)(iId,rRecordSet) == PD_FOUND) {
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			hRsp = (hash_t*) malloc (sizeof(hash_t));
			hash_init(hRsp,0);
/* pool_id */
			if (GetField_Int(hRec,"pool_id",&iPtr)) {
//DEBUGLOG(("GetPool() pool_id = [%d]\n",iPtr));
				PutField_Int(hRsp,"pool_id",iPtr);
			}
/* desc */
			if (GetField_CString(hRec,"desc",&csPtr)) {
//DEBUGLOG(("GetPool() desc = [%s]\n",csPtr));
				PutField_CString(hRsp,"desc",csPtr);
			}

/* pool limit */
			if (GetField_Double(hRec,"pool_limit",&dPtr)) {
//DEBUGLOG(("GetPool() pool limt = [%f]\n",dPtr));
				PutField_Double(hRsp,"pool_limit",dPtr);
			}
/* ratio */
			if (GetField_Int(hRec,"ratio",&iPtr)) {
//DEBUGLOG(("GetPool() ratio = [%d]\n",iPtr));
				PutField_Int(hRsp,"ratio",iPtr);
			}
/* priority */
			if (GetField_Int(hRec,"priority",&iPtr)) {
//DEBUGLOG(("GetPool() priority = [%d]\n",iPtr));
				PutField_Int(hRsp,"priority",iPtr);
			}

			RecordSet_Add(rRs,hRsp);
			hRec = RecordSet_GetNext(rRecordSet);
		}
	}

	RecordSet_Destroy(rRecordSet);
       	FREE_ME(rRecordSet);

DEBUGLOG(("GetPool() exit iRet = [%d]\n",iRet));
	return	iRet;
}
	
int CheckPools(double dTxnAmt,
		const char* csServiceCode,
                const char* csTxnCountry,
                const char* csTxnCcy,
                const char* csPayMethod,
		const char* csBankCode,
		hash_t*	hPsp,
		recordset_t *rRs,
		char*	csSelectedPspId,
		const char* csOrgDateTime)
{
	int	iRet = PD_OK;
	hash_t	*hCurrPool;
	hash_t	*hRec;
	double	dPoolLimit = 0.0;

	double	dCurr = 0.0;
	double	dTotalCurr = 0.0;
	double	dReqCurr = 0.0;
	double	dTotalReqCurr = 0.0;

	int	iPoolId;
	int	iTotalRatio = 0;
	double	dTotalVol = 0.0;
	int	iRatio;
	int	iPriority;
	int	iPrePriority;
	int	iTmp;
	double	dTmp;
	
	int	iRand = 0;
	int	iWaitRand = 0;
	int	iCheck = PD_FALSE;
	int	iFinal = PD_FALSE;
	int	iPoolList[PD_TMP_BUF_LEN]; //max 256 pools
	int	iWaitingList[PD_TMP_BUF_LEN]; //max 256 pools
	int	iTestList[PD_TMP_BUF_LEN]; //max 256 pools
	char	csTag[PD_TAG_LEN+1];
	recordset_t     *rPools;

        rPools = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rPools,0);


DEBUGLOG(("CheckPools()\n"));
	hCurrPool = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hCurrPool,0);

	hRec = RecordSet_GetFirst(rRs);

        rPools = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rPools,0);

	while (hRec) {
		dPoolLimit  = 0.0;
		dCurr  = 0.0;
		dReqCurr  = 0.0;
		iRatio = 0;
		iPriority = 0;
		iCheck = PD_OK;

		if (GetField_Int(hRec,"pool_id",&iPoolId)) {
DEBUGLOG(("CheckPools pool id = [%d]\n",iPoolId));
		}
		else {
DEBUGLOG(("CheckPools pool id is missing!!!\n"));
		}
		
/* check if any ava psp in this pool */
		DBObjPtr = CreateObj(DBPtr,"DBRuleLB","FindAvalPspForPool");      
        	if ((unsigned long)(*DBObjPtr)(iPoolId,hPsp) != PD_OK) {
DEBUGLOG(("CheckPools can't find any aval psp for this pool [%d]\n",iPoolId));
			iCheck = INT_PSP_NOT_AVAILABLE;
		}
		else {
/* check psp with schudler */
		}	
		

		if (iCheck== PD_OK) {
/* check if its psp still has quota */
			if (GetField_Double(hRec,"pool_limit",&dPoolLimit)) {
DEBUGLOG(("CheckPools pool limit = [%f] for pool [%d]\n",dPoolLimit,iPoolId));
			}
			DBObjPtr = CreateObj(DBPtr,"DBRuleLB","FindAvalPsp");      
        		if ((unsigned long)(*DBObjPtr)(iPoolId,csServiceCode,csTxnCountry,dTxnAmt) != PD_OK) {
DEBUGLOG(("CheckPools none of aval psp for this pool [%d] has quota to handle txn amt [%f]\n",iPoolId,dTxnAmt));
				iCheck = INT_PSP_NOT_AVAILABLE;
			}
		}



		if (iCheck == PD_OK ) {
			if (GetField_Int(hRec,"ratio",&iRatio)) {
DEBUGLOG(("CheckPools ratio = [%d]\n",iRatio));
			}

			if (GetField_Int(hRec,"priority",&iPriority)) {
DEBUGLOG(("CheckPools priority = [%d]\n",iPriority));
			}

/*
DEBUGLOG(("CheckPools ------------------------------------------\n"));
DEBUGLOG(("CheckPools ServiceCode = [%s]\n",csServiceCode));
DEBUGLOG(("CheckPools TxnCountry = [%s]\n",csTxnCountry));
DEBUGLOG(("CheckPools TxnCcy = [%s]\n",csTxnCcy));
DEBUGLOG(("CheckPools PayMethod = [%s]\n",csPayMethod));
DEBUGLOG(("CheckPools ------------------------------------------\n"));
*/
			if (dPoolLimit != 0.0 ) {
DEBUGLOG(("CheckPools call checkpoolimit\n"));
				iCheck = CheckPoolLimit(iPoolId,
       	        					csServiceCode,
       	        					csTxnCountry,
       	        					csTxnCcy,
       	        					csPayMethod,
							dTxnAmt,
       	        					dPoolLimit,
							&dCurr,
							&dTotalCurr,
							&dReqCurr,
							&dTotalReqCurr);
			}
			else {
/* Get Curr Pool Hit */
				DBObjPtr = CreateObj(DBPtr,"DBRulePspLbPools","GetPspPoolsTotal");      
       		 		iCheck = (unsigned long)(*DBObjPtr)(iPoolId,csServiceCode,csTxnCountry,csTxnCcy,csPayMethod,&dCurr,&dTotalCurr,&dReqCurr,&dTotalReqCurr);
DEBUGLOG(("CheckPools iRet = [%d] from GetPspPoolsTotal\n",iRet));
			}
			if (iCheck == PD_OK) {
/* check aval psp limit under this pool */
			}

			if (iCheck == PD_OK) {
DEBUGLOG(("CheckPools pool id [%d] is good Pool Curr = [%f] Req Curr = [%f]\n",iPoolId,dCurr,dReqCurr));
				RecordSet_Add(rPools,hRec);	
				PutField_Double(hRec,"pool_curr",dCurr);
				PutField_Double(hRec,"pool_req_curr",dReqCurr);
				iFinal=PD_TRUE;

				sprintf(csTag,"pool_total_vol_for_p%d",iPriority);
				dTmp = 0.0;
				GetField_Double(hCurrPool,csTag,&dTmp);
				PutField_Double(hCurrPool,csTag,dTmp+dReqCurr);

				sprintf(csTag,"pool_total_ratio_for_p%d",iPriority);
				iTmp = 0;
				GetField_Int(hCurrPool,csTag,&iTmp);
				PutField_Int(hCurrPool,csTag,iTmp+iRatio);

				if(iPriority!=iPrePriority){
					iTmp = 0;
					GetField_Int(hCurrPool,"num_of_priority",&iTmp);
					PutField_Int(hCurrPool,"num_of_priority",iTmp+1);
					sprintf(csTag,"priority_%d",iTmp);
					PutField_Int(hCurrPool,csTag,iPriority);
DEBUGLOG(("CheckPools Number of Priority[%d] is now[%d]\n",iPriority,iTmp+1));

					iTmp = 0;
					sprintf(csTag,"priority_%d_cnt",iPriority);
					GetField_Int(hCurrPool,csTag,&iTmp);
					PutField_Int(hCurrPool,csTag,iTmp+1);
DEBUGLOG(("CheckPools pool id [%d] is the [%d]th in Priority[%d]\n",iPoolId,iTmp+1,iPriority));

					iPrePriority = iPriority;
				}
				else{
					iTmp = 0;
					sprintf(csTag,"priority_%d_cnt",iPriority);
					GetField_Int(hCurrPool,csTag,&iTmp);
					PutField_Int(hCurrPool,csTag,iTmp+1);
DEBUGLOG(("CheckPools pool id [%d] is the [%d]th in Priority[%d]\n",iPoolId,iTmp+1,iPriority));
				}

			}
		}

		if (iCheck == PD_OK) {
			iTotalRatio += iRatio;
//			dTotalVol += dCurr; /* approval amount */
			dTotalVol += dReqCurr; /* request txn amount */
DEBUGLOG(("CheckPools total ratio now =  [%d] total Vol = [%lf]\n",iTotalRatio,dTotalVol));
		}
		hRec = RecordSet_GetNext(rRs);
	}
	if(!iFinal){
		iRet=iCheck;
	}

	if (iTotalRatio > 0) {
DEBUGLOG(("CheckPools ------------let see which pool will fit\n"));
		int    	iFinalPoolId;
	        int    	iFinalPriority = 0;	
	        int    	iRatioForPriority= 0;	
	        //int    	iPrePriority = -1;	
		//int	iCnt=0;
		int	i=0;
		int	iSelected=0;
		int	iCheckPoint=PD_FALSE;
		int	iEndLoop=PD_FALSE;
		//int	iNumOfPriority = 0;
		int	iPriorityCnt= 0;
		int	iTmpPriorityCnt= 0;
		double 	dFinalVolRatio = 0;
		double 	dFinalPoolRatio = 0;
		double 	dTmpVolRatio = 0.0;
		double 	dPoolRatio = 0.0;
		double 	dTotalVolForPriority = 0.0;
		int	iIgnore = PD_FALSE;
		hRec = RecordSet_GetFirst(rPools);
		while (hRec && !iEndLoop) {
			iIgnore = PD_FALSE;
			if (GetField_Int(hRec,"pool_id",&iPoolId)) {
DEBUGLOG(("CheckPools ------------pool id = [%d]\n",iPoolId));
			}
			if (GetField_Double(hRec,"pool_limit",&dPoolLimit)) {
DEBUGLOG(("CheckPools ------------pool limit = [%f] for pool [%d]\n",dPoolLimit,iPoolId));
			}
			if (GetField_Int(hRec,"ratio",&iRatio)) {
DEBUGLOG(("CheckPools ------------ratio = [%d]\n",iRatio));
                	}
                	if (GetField_Int(hRec,"priority",&iPriority)) {
DEBUGLOG(("CheckPools ------------priority = [%d]\n",iPriority));
                	}
                	if (GetField_Double(hRec,"pool_curr",&dCurr)) {
DEBUGLOG(("CheckPools ------------pool_curr = [%f]\n",dCurr));
                	}
                	if (GetField_Double(hRec,"pool_req_curr",&dReqCurr)) {
DEBUGLOG(("CheckPools ------------pool_req_curr = [%f]\n",dReqCurr));
                	}

			iTmpPriorityCnt = 0;
			sprintf(csTag,"tmp_priority_%d_cnt",iPriority);
			GetField_Int(hCurrPool,csTag,&iTmpPriorityCnt);
DEBUGLOG(("CheckPools ------------ [%d] ------------\n",iTmpPriorityCnt));

			sprintf(csTag,"%d_pool_id_%d",iPriority,iTmpPriorityCnt);
			PutField_Int(hCurrPool,csTag,iPoolId);
			sprintf(csTag,"%d_ratio_%d",iPriority,iTmpPriorityCnt);
			PutField_Int(hCurrPool,csTag,iRatio);
			sprintf(csTag,"%d_pool_req_curr_%d",iPriority,iTmpPriorityCnt);
			PutField_Double(hCurrPool,csTag,dReqCurr);

			iTmpPriorityCnt++;
			sprintf(csTag,"tmp_priority_%d_cnt",iPriority);
			PutField_Int(hCurrPool,csTag,iTmpPriorityCnt);
			
			iPriorityCnt = 0;
			sprintf(csTag,"priority_%d_cnt",iPriority);
			GetField_Int(hCurrPool,csTag,&iPriorityCnt);
			
			if(iPriorityCnt == iTmpPriorityCnt){
				iCheckPoint = PD_TRUE;
			}

			if(iCheckPoint){
DEBUGLOG(("CheckPools Check with Priority[%d], total[%d]\n",iPriority,iPriorityCnt));
				for(i = 0; i < iPriorityCnt; i++){
					sprintf(csTag,"%d_pool_id_%d",iPriority,i);
					GetField_Int(hCurrPool,csTag,&iPoolId);
					sprintf(csTag,"%d_ratio_%d",iPriority,i);
					GetField_Int(hCurrPool,csTag,&iRatio);
					sprintf(csTag,"%d_pool_req_curr_%d",iPriority,i);
					GetField_Double(hCurrPool,csTag,&dReqCurr);
DEBUGLOG(("CheckPools Check[%d]: pool id[%d], ratio[%d], pool_req_curr[%lf]\n",i,iPoolId,iRatio,dReqCurr));

					sprintf(csTag,"pool_total_ratio_for_p%d",iPriority);
					iRatioForPriority = 0;
					GetField_Int(hCurrPool,csTag,&iRatioForPriority);

					sprintf(csTag,"pool_total_vol_for_p%d",iPriority);
					dTotalVolForPriority = 0;
					GetField_Double(hCurrPool,csTag,&dTotalVolForPriority);

					if (iRatio > 0 && iRatioForPriority > 0) {
						dPoolRatio = (double)iRatio/(double)iRatioForPriority;
DEBUGLOG(("CheckPools [%d]Pool Ratio = [%f]\n",i,dPoolRatio));

						if(dReqCurr==0.0 || dTotalVolForPriority == 0.0)
							dTmpVolRatio = 0.0;
						else
							dTmpVolRatio = dReqCurr/dTotalVolForPriority; /* request amount */
						
						if (i == 0) {
							iFinalPoolId = iPoolId;
							iFinalPriority = iPriority;
							dFinalVolRatio = dTmpVolRatio;
							dFinalPoolRatio = dPoolRatio;
						}
DEBUGLOG(("CheckPools tmp vol ratio = [%f] = [%f / %f]\n",dTmpVolRatio,dReqCurr,dTotalVolForPriority));

/* if the pool was never hit */
						if (dReqCurr == 0.0 ) {
							/* if both pools are never hit */
							if (dFinalVolRatio == 0.0) {
/* insert into random pool list */
								iFinalPoolId = iPoolId;
								iPoolList[iRand] = iPoolId;
								iRand++;
								iSelected ++;
DEBUGLOG(("CheckPools Pool[%d]:insert into random pool list\n",iPoolId));
							}
							/* take the lowest */
							else {
								iFinalPoolId = iPoolId;
								iFinalPriority = iPriority;
								dFinalVolRatio = 0.0;
								dFinalPoolRatio = dPoolRatio;
								iSelected ++;
								iRand = 0;
								iWaitRand = 0;
							}
						}
						else{
/* if exceed the current ratio */
							if (dTmpVolRatio >= dPoolRatio){
DEBUGLOG(("CheckPools exceed Ratio\n"));
								if(iFinalPoolId == iPoolId){
DEBUGLOG(("CheckPools remove the first selected pool\n"));
									dFinalVolRatio = 99999;
									iFinalPoolId = 0;
								}
DEBUGLOG(("CheckPools put to waiting list [%d]\n",iPoolId));
								iWaitingList[iWaitRand] = iPoolId;
								iWaitRand++;
								iIgnore = PD_TRUE;
							}
							else if(dTmpVolRatio < dPoolRatio){
								if(dFinalVolRatio > dTmpVolRatio){
									iFinalPoolId = iPoolId;
									iFinalPriority = iPriority;
									dFinalVolRatio = dTmpVolRatio;
									dFinalPoolRatio = dPoolRatio;
									iRand = 0;
									iWaitRand = 0;
									iSelected ++;
DEBUGLOG(("CheckPools with lower ratio, select pool[%d]\n",iPoolId));
								}
								else if(dFinalVolRatio == dTmpVolRatio){
									iFinalPoolId = iPoolId;
									iPoolList[iRand] = iPoolId;
									iRand++;
									iSelected ++;
DEBUGLOG(("CheckPools same priority and ratio, insert into the random list[%d]\n",iRand));
								}
								else{
									iIgnore = PD_TRUE;
								}
							}
						}
					}
					else{
						iIgnore = PD_TRUE;
					}
					if(iIgnore != PD_TRUE){
DEBUGLOG(("CheckPools ++ pool id [%d] Priority [%d] Vol Ratio [%f] Pool Ratio [%f]\n",iFinalPoolId,iFinalPriority,dFinalVolRatio,dFinalPoolRatio));
					}
				}//end for loop
				int iRandIndex=0;
				int iTestRand =0;

				if(iWaitRand>0){
					iTestRand = iWaitRand;
					for(i=0; i<iWaitRand; i++){
						iTestList[i]=iWaitingList[i];
					}
				}
				if(iRand>0){
					iTestRand = iRand;
					for(i=0; i<iRand; i++){
						iTestList[i]=iPoolList[i];
					}
				}

				//if(!iSelected){
					iRet = PD_ERR;
					int     iPoolTmpList[PD_TMP_BUF_LEN];
					//int 	iTested = 0;
					while (iRet != PD_OK) {
						i = 0;
						int j;
//check list
						if(iTestRand>0){
							iRandIndex = rand() % iTestRand;
DEBUGLOG(("CheckPools PoolList Idx = [%d] [%d]\n",iRandIndex,iTestList[iRandIndex]));
							iFinalPoolId = iTestList[iRandIndex];

							/* prepare for reselect from the list */
							for (j = 0; j < iTestRand; j++ ) {
								if (i ==  iRandIndex)
									continue;
								else {
									iPoolTmpList[i]  = iTestList[j];
									i++;
								}
							}
						}
DEBUGLOG(("CheckPools +++ call PickPsp\n"));
						iRet = PickPsp(hPsp,iFinalPoolId,csBankCode,csPayMethod,csServiceCode,csTxnCountry,csTxnCcy,csSelectedPspId,dTxnAmt,csOrgDateTime);
						iTestRand = i;
DEBUGLOG(("CheckPools +++ call PickPsp iRet = [%d]\n",iRet));
						/* prepare for reselect from the list */
						if (iRet != PD_OK) {
							if (iTestRand == 0 )
								break;
							for (j = 0; j < iTestRand; j++ ) {
								iTestList[j]  = iPoolTmpList[j];
							}
						}
					}
					if(iRet==PD_OK) iEndLoop = PD_TRUE;
				//}
				
				iCheckPoint = PD_FALSE;
			}////end of check
			
			hRec = RecordSet_GetNext(rPools);
		}
	}
	else {
DEBUGLOG(("CheckPools no pool will fit .....\n"));
ERRLOG("FATAL ERROR BOTxnLb: CheckPools no pool will fit .....\n");
		iRet = INT_EXCEED_LIMIT_PSP_AMT;
	}


	hash_destroy(hCurrPool);
        FREE_ME(hCurrPool);


	RecordSet_Destroy(rPools);
       	FREE_ME(rPools);
DEBUGLOG(("CheckPools() exit iRet = [%d]\n",iRet));
	return	iRet;
}

int CheckPoolLimit(int iId,
		const char* csServiceCode,
		const char* csTxnCountry,
		const char* csTxnCcy,
		const char* csPayMethod,
		double dTxnAmt,
		double dLimit,
		double *dPoolCurr,
		double *dTotalPoolCurr,
		double *dPoolReqCurr,
		double *dTotalPoolReqCurr)
{
	int iRet = PD_ERR;
DEBUGLOG(("CheckPoolLimit()\n"));

/*
DEBUGLOG(("CheckPoolLimit ------------------------------------------\n"));
DEBUGLOG(("CheckPoolLimits ServiceCode = [%s]\n",csServiceCode));
DEBUGLOG(("CheckPoolLimits TxnCountry = [%s]\n",csTxnCountry));
DEBUGLOG(("CheckPoolLimits TxnCcy = [%s]\n",csTxnCcy));
DEBUGLOG(("CheckPoolLimits PayMethod = [%s]\n",csPayMethod));
DEBUGLOG(("CheckPoolLimits ------------------------------------------\n"));
*/
	DBObjPtr = CreateObj(DBPtr,"DBRulePspLbPools","GetPspPoolsTotal");	
	/*iRet = (unsigned long)(*DBObjPtr)(iId,csServiceCode,csTxnCountry,csTxnCcy,csPayMethod,dPoolCurr,dTotalPoolCurr,&dPoolReqCurr,&dTotalPoolReqCurr);*/

	iRet = (unsigned long)(*DBObjPtr)(iId,csServiceCode,csTxnCountry,csTxnCcy,csPayMethod,
						dPoolCurr,dTotalPoolCurr,dPoolReqCurr,dTotalPoolReqCurr);

	if (iRet == PD_OK) {
//DEBUGLOG(("Rule limit = [%f] current hit = [%f]\n",dLimit,*dPoolCurr));
DEBUGLOG(("Rule limit = [%f] current hit = [%f] PoolReqCurr = [%f]\n",dLimit,*dPoolCurr,*dTotalPoolReqCurr));

		//if (*dTotalPoolCurr == 0.0) {
//DEBUGLOG(("CheckPoolLimit() Not Yet Exceed Limit since no txn had been made for this pool [%d]+++\n",iId));
		//}
		//else
		if (*dTotalPoolCurr + dTxnAmt > dLimit) {
DEBUGLOG(("CheckPoolLimit() Exceed Limit [%f + %f] > [%f]*****\n",*dTotalPoolCurr,dTxnAmt,dLimit));
			iRet = INT_EXCEED_LIMIT_PSP_AMT;
		}
		else {
DEBUGLOG(("CheckPoolLimit() Not Yet Exceed Limit (%f + %f <= %f+++\n",*dTotalPoolCurr,dTxnAmt,dLimit));
		}
	}
DEBUGLOG(("CheckPoolLimit() exit iRet = [%d]\n",iRet));
	return iRet;
}
	
int PickPsp(hash_t* hPsp,
		int iId,
		const char* csBankCode,
		const char* csPayMethod,
		const char* csServiceCode,
		const char* csTxnCountry,
		const char* csTxnCcy,
		char*	csSelectedPspId,
		double	dTxnAmt,
		const char* csOrgDateTime)
{
	int	iRet = PD_OK;
	char	*csPspId;
	double	dLimit;
	double	dPspCurr;
	double	dTotalPspCurr;
	double	dPspReqCurr;
	double	dTotalPspReqCurr;
	double	dTotalVol = 0.0;
	int	iTotalRatio = 0;
	int	iRatio;
	int	iPriority;
	int	iTmp = 0;
	double	dTmp;

	int	iRand = 0;
	int	iWaitRand = 0;
	int	iExceedRatioRand = 0;
	int	iRecord = 0;
	int	iSelected= 0;
	int	iFinal = PD_FALSE;
	int	iCheck = PD_FALSE;
	char	csPspList[PD_TMP_BUF_LEN ][PD_PSP_ID_LEN +1]; //max 256 psp
	char	csWaitingList[PD_TMP_BUF_LEN ][PD_PSP_ID_LEN +1]; //max 256 psp
	char	csExceedRatioWaitingList[PD_TMP_BUF_LEN ][PD_PSP_ID_LEN +1]; //max 256 psp
	char	csTag[PD_TAG_LEN+1];
	recordset_t     *rPsp,*rAvalPsp;
	hash_t		*hRec;


DEBUGLOG(("PickPsp()\n"));
DEBUGLOG(("PickPsp() Pool id = [%d] country = [%s] pay method = [%s] service code = [%s]\n",iId,csTxnCountry,csPayMethod,csServiceCode));
        rPsp = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rPsp,0);

        rAvalPsp = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rAvalPsp,0);

	DBObjPtr = CreateObj(DBPtr,"DBRuleLB","GetAvalPspsByPool");	
	if ((*DBObjPtr)(hPsp,iId,rPsp) == PD_OK) {
		hRec = RecordSet_GetFirst(rPsp);
		while(hRec) {
			iRatio = 0.0;
			dLimit = 0.0;
			dPspCurr = 0.0;
			dTotalPspCurr = 0.0;
			dPspReqCurr = 0.0;
			dTotalPspReqCurr = 0.0;
			if (GetField_CString(hRec,"psp_id",&csPspId)) {
DEBUGLOG(("PickPsp psp id  = [%s]\n",csPspId));
				DBObjPtr = CreateObj(DBPtr,"DBRulePspLbPsp","GetPsp");	
				iRet = (unsigned long)(*DBObjPtr)(csPspId,hRec);
				if (iRet != PD_OK) 
					break;
				if (GetField_Double(hRec,"psp_limit",&dLimit )) {
DEBUGLOG(("PickPsp limit for [%s]  = [%f]\n",csPspId,dLimit));
				}
				if (GetField_Int(hRec,"pool_psp_ratio",&iRatio)) {
DEBUGLOG(("PickPsp ratio for [%s]  = [%d] from Pool Mapping\n",csPspId,iRatio));
				}
				else{
					iRatio = 0;
				}
				if (GetField_Int(hRec,"pool_psp_priority",&iPriority)) {
DEBUGLOG(("PickPsp priority for [%s]  = [%d] from Pool Mapping\n",csPspId,iPriority));
				}
				else 
					iPriority = 0;


/* don't use psp level's ratio and priority
				if (iRatio == 0) { //if don't override by the pool mapping
					if (GetField_Int(hRec,"psp_ratio",&iRatio )) {
DEBUGLOG(("PickPsp ratio for [%s]  = [%d]\n",csPspId,iRatio));
					}
				}
*/

				if (dLimit != 0.0) {
					iCheck = CheckPspLimit(csPspId,
								csServiceCode,
								csTxnCountry,
								csTxnCcy,
								csPayMethod,
								dTxnAmt,
								dLimit,
								&dPspCurr,
								&dTotalPspCurr,
								&dPspReqCurr,
								&dTotalPspReqCurr);	
				}
				else {
/* Get Curr Pool Hit */
                        		DBObjPtr = CreateObj(DBPtr,"DBRulePspLbPsp","GetPspLimit");
                        		iCheck = (unsigned long)(*DBObjPtr)(csPspId,csServiceCode,csTxnCountry,csTxnCcy,csPayMethod,&dPspCurr,&dTotalPspCurr,&dPspReqCurr,&dTotalPspReqCurr);
					iCheck = INT_EXCEED_LIMIT_PSP_AMT;
				}

				if (iCheck== PD_OK) {
DEBUGLOG(("PickPsp psp id [%s] is good psp Curr = [%f]\n",csPspId,dPspCurr));
                                        PutField_Double(hRec,"psp_curr",dPspCurr);
                                        PutField_Double(hRec,"psp_req_curr",dPspReqCurr);

					sprintf(csTag,"total_ratio_for_p%d",iPriority);
					iTmp = 0;
					GetField_Int(hPsp,csTag,&iTmp);
					PutField_Int(hPsp,csTag,iTmp+iRatio);

					sprintf(csTag,"total_vol_for_p%d",iPriority);
					dTmp = 0.0;
					GetField_Double(hPsp,csTag,&dTmp);
					PutField_Double(hPsp,csTag,dTmp+dPspReqCurr);

                                        RecordSet_Add(rAvalPsp,hRec);
					iFinal = PD_TRUE;
                                }
			}
                       	iTotalRatio += iRatio;
                     //  	dTotalVol += dPspCurr; /* approval amount */
                       	dTotalVol += dPspReqCurr; /* request amount */
DEBUGLOG(("CheckPools total ratio now =  [%d] total Vol = [%lf]\n",iTotalRatio,dTotalVol));
			hRec = RecordSet_GetNext(rPsp);
		}
	}
	else {
DEBUGLOG(("PickPsp Not record return from!!!\n"));
	}

	if(!iFinal){
		iRet = iCheck;
	}

	if (iTotalRatio >0 ) {
DEBUGLOG(("PickPsp ------------let see which psp will fit\n"));
                int    	iRatioForPriority = 0;
                int    	iTmpPriority = 0;
                int    	iFinalPriority = 0;
		int    	iPriority = 0;
		double	dTotalVolForPriority = 0.0;
                double 	dFinalVolRatio = 0;
                double 	dFinalPspRatio = 0;
                double 	dTmpVolRatio = 0.0;
                double 	dPspRatio = 0.0;
		int	iCnt = 0;
		int	iIgnore = PD_FALSE;
                hRec = RecordSet_GetFirst(rAvalPsp);
                while (hRec) {
			iIgnore = PD_FALSE;
			iRecord++;
                        if (GetField_CString(hRec,"psp_id",&csPspId)) {
DEBUGLOG(("PickPsp ------------psp id = [%s]\n",csPspId));
                        }
                        if (GetField_Double(hRec,"psp_limit",&dLimit)) {
DEBUGLOG(("PickPsp ------------pool limit = [%f] for psp [%s]\n",dLimit,csPspId));
                        }

			if (GetField_Int(hRec,"pool_psp_ratio",&iRatio)) {
DEBUGLOG(("PickPsp ------------ratio from pool mapping = [%d]\n",iRatio));
			} else {
				iRatio = 0;
			}

/* don't use psp level of ratio 
			if (iRatio == 0) { // if not override by pool mapping
                        	if (GetField_Int(hRec,"psp_ratio",&iRatio)) {
DEBUGLOG(("PickPsp ------------ratio = [%d]\n",iRatio));
                        	}
			}
*/

                        if (GetField_Int(hRec,"pool_psp_priority",&iPriority)) {
DEBUGLOG(("PickPsp ------------priority = [%d] from pool mapping\n",iPriority));
			}
			else 
				iPriority = 0;
/* don't use psp level of priority 
			if (iPriority == 0) { // if not override by pool mapping
                        	if (GetField_Int(hRec,"psp_priority",&iPriority)) {
DEBUGLOG(("PickPsp ------------priority = [%d]\n",iPriority));
                        	}
			}
*/
			sprintf(csTag,"total_ratio_for_p%d",iPriority);
			iRatioForPriority = 0;
			GetField_Int(hPsp,csTag,&iRatioForPriority);

			sprintf(csTag,"total_vol_for_p%d",iPriority);
			dTotalVolForPriority = 0.0;
			GetField_Double(hPsp,csTag,&dTotalVolForPriority);

                        if (GetField_Double(hRec,"psp_curr",&dPspCurr)) {
DEBUGLOG(("PickPsp ------------psp_curr = [%f]\n",dPspCurr));
                        }
                        if (GetField_Double(hRec,"psp_req_curr",&dPspReqCurr)) {
DEBUGLOG(("PickPsp ------------psp_req_curr = [%f]\n",dPspReqCurr));
                        }

                        if (iRatio > 0 && iRatioForPriority > 0) {
                                //dPspRatio = (double)iRatio/(double)iTotalRatio;
                                dPspRatio = (double)iRatio/(double)iRatioForPriority;
DEBUGLOG(("PickPsp ------------psp Ratio = [%f]\n",dPspRatio));
				//if (dPspCurr == 0.0 )
				if (dPspReqCurr == 0.0 || dTotalVolForPriority == 0.0)
                                        dTmpVolRatio = 0.0;
                                else
                                        dTmpVolRatio = dPspReqCurr/dTotalVolForPriority; /* Request Amount*/
                                        //dTmpVolRatio = dPspReqCurr/dTotalVol; /* Request Amount*/
                                        //dTmpVolRatio = dPspCurr/dTotalVol; /* approval amount */

				if (iCnt == 0) {
					strcpy(csSelectedPspId,csPspId);
                                	iFinalPriority = iPriority;
                                	dFinalVolRatio = dTmpVolRatio;
                                	dFinalPspRatio = dPspRatio;
                                	iTmpPriority = iPriority;
				}
				iCnt++;

DEBUGLOG(("PickPsp ------------tmp vol ratio = [%f]\n",dTmpVolRatio));

/* if the psp was never hit */
                                //if (dPspCurr == 0.0 ) { /* approval amount */
                                if (dPspReqCurr == 0.0 ) {
                                /* if both psp are never hit */
DEBUGLOG((" pspreqcurr == 0.0 \n"));
                                        if (dFinalVolRatio == 0.0) {
DEBUGLOG((" finalvolratio == 0.0 \n"));
                                                if (iPriority > iFinalPriority)  {
DEBUGLOG((" Priority [%d] > FinalPriorty [%d] \n",iPriority,iFinalPriority));
							strcpy(csSelectedPspId,csPspId);
                                                        iFinalPriority = iPriority;
                                                        dFinalVolRatio = 0.0;
                                			dFinalPspRatio = dPspRatio;
							iRand = 0;
							iSelected ++;
                                                }
/* if both are the same */
						else if (iPriority == iFinalPriority) {
DEBUGLOG((" insert into the random list[%d]\n",iRand));						
							strcpy(csSelectedPspId,csPspId);
							strcpy(csPspList[iRand],csPspId);
							iSelected ++;
							iRand++;
						}
						else{
							iIgnore = PD_TRUE;
						}
                                        }
                                /* take the lowest */
                                        else {
						if(iPriority >= iTmpPriority){
DEBUGLOG((" higher/same priority with previous PSP, take the current one\n"));
							strcpy(csSelectedPspId,csPspId);
                                                	iFinalPriority = iPriority;
                                                	dFinalVolRatio = 0.0;
                                			dFinalPspRatio = dPspRatio;
							iRand = 0;
							iSelected ++;
						}
						else{
							iIgnore = PD_TRUE;
						}
                                        }
                                }
				else{
/* if exceed the current ratio */
					if (dTmpVolRatio >= dPspRatio && iPriority >= iTmpPriority) {
DEBUGLOG(("PickPsp exceed Ratio\n"));
						if(!strcmp(csSelectedPspId,csPspId)){
DEBUGLOG(("PickPsp remove the first selected psp\n"));
							dFinalVolRatio = 99999;
							csSelectedPspId[0]='\0';
						}
						if(dTmpVolRatio > dPspRatio){
DEBUGLOG(("PickPsp put to exceed ratio waiting list [%s]\n",csPspId));
							strcpy(csExceedRatioWaitingList[iExceedRatioRand],csPspId);
							iExceedRatioRand++;
						}
						else if(dTmpVolRatio == dPspRatio){
DEBUGLOG(("PickPsp dTmpVolRatio = psp ratio [%f], put to waiting list\n", dTmpVolRatio));
							strcpy(csWaitingList[iWaitRand],csPspId);
							iWaitRand++;
						}

						hRec = RecordSet_GetNext(rAvalPsp);
						continue;
					}
					else if(dTmpVolRatio < dPspRatio && iPriority >= iTmpPriority){

						if (iPriority > iTmpPriority) {
DEBUGLOG((" iPriority[%d] > iTmpPriority[%d] \n",iPriority,iTmpPriority));
							strcpy(csSelectedPspId,csPspId);
                                	        	iFinalPriority = iPriority;
                                	        	dFinalVolRatio = dTmpVolRatio;
                                			dFinalPspRatio = dPspRatio;
							iRand = 0;
							iSelected ++;

DEBUGLOG(("PickPsp new dFinalVolRatio = [%f]\n",dFinalVolRatio));
DEBUGLOG(("PickPsp new dFinalPspRatio = [%f]\n",dFinalPspRatio));
						}
						else if (iTmpPriority == iPriority) {
DEBUGLOG((" iPriority[%d] = iTmpPriority[%d] \n",iPriority,iTmpPriority));
                                		        if (dFinalVolRatio > dTmpVolRatio) {
								strcpy(csSelectedPspId,csPspId);
								iFinalPriority = iPriority;
								dFinalVolRatio = dTmpVolRatio;
								dFinalPspRatio = dPspRatio;
DEBUGLOG(("PickPsp new dFinalVolRatio = [%f]\n",dFinalVolRatio));
DEBUGLOG(("PickPsp new dFinalPspRatio = [%f]\n",dFinalPspRatio));
								iRand = 0;
								iSelected ++;
							}
                                	        	else if (dFinalVolRatio == dTmpVolRatio) {
								strcpy(csSelectedPspId,csPspId);
								strcpy(csPspList[iRand],csPspId);
								iRand++;
								iSelected ++;
DEBUGLOG((" same priority and ratio, insert into the random list[%d]\n",iRand));						
							}
							else{
								iIgnore = PD_TRUE;
							}
						}
						else{
							iIgnore = PD_TRUE;
						}
					}
				}
                        }
			else{
				iIgnore = PD_TRUE;
			}
			if(iIgnore!=PD_TRUE){
				iTmpPriority  = iPriority;
DEBUGLOG(("PickPsp +++ psp id [%s] Priority [%d] Ratio [%f]\n",csSelectedPspId,iFinalPriority,dFinalVolRatio));
			}
                        hRec = RecordSet_GetNext(rAvalPsp);
                }
	}
	if(!iRecord){
		iRet = INT_PSP_NOT_AVAILABLE;
DEBUGLOG(("PickPsp +++ no psp available!!!!!\n"));
ERRLOG("BOTxnLb: PickPsp +++ no psp available!!!!!\n");
	}
	if(!iSelected){
		if(iWaitRand>0){
//Random Select PSP
			int iRandIndex = rand() % iWaitRand; 
DEBUGLOG(("PickPsp idx = [%d] [%s] from total of [%d]\n",iRandIndex,csWaitingList[iRandIndex],iWaitRand));
			strcpy(csSelectedPspId,csWaitingList[iRandIndex]);
		}
		else{
			if(iExceedRatioRand>0){
				int iRandIndex = rand() % iExceedRatioRand;
DEBUGLOG(("PickPsp idx = [%d] [%s] from total of [%d]\n",iRandIndex,csExceedRatioWaitingList[iRandIndex],iExceedRatioRand));
				strcpy(csSelectedPspId,csExceedRatioWaitingList[iRandIndex]);
			}
			else{
				iRet = INT_PSP_NOT_AVAILABLE;
DEBUGLOG(("PickPsp +++ no psp available!!!!!\n"));
ERRLOG("BOTxnLb: PickPsp +++ no psp available!!!!!\n");
			}
		}
	}

	RecordSet_Destroy(rAvalPsp);
       	FREE_ME(rAvalPsp);

	RecordSet_Destroy(rPsp);
       	FREE_ME(rPsp);

	if (iRand >0 ) {
//Random Select PSP
		int iRandIndex = rand() % iRand; 
DEBUGLOG(("PickPsp idx = [%d] [%s] from total of [%d]\n",iRandIndex,csPspList[iRandIndex],iRand));
		strcpy(csSelectedPspId,csPspList[iRandIndex]);
	}
DEBUGLOG(("PickPsp() exit iRet = [%d] [%s]\n",iRet,csSelectedPspId));
	return iRet;
}


int CheckPspLimit(const char* csId,
                const char* csServiceCode,
                const char* csTxnCountry,
                const char* csTxnCcy,
                const char* csPayMethod,
                double dTxnAmt,
                double dLimit,
                double *dPoolCurr,
                double *dTotalPoolCurr,
                double *dPoolReqCurr,
                double *dTotalPoolReqCurr)
{
        int iRet = PD_ERR;
DEBUGLOG(("CheckPspLimit()\n"));

/*
DEBUGLOG(("CheckPspLimit ------------------------------------------\n"));
DEBUGLOG(("CheckPspLimit ServiceCode = [%s]\n",csServiceCode));
DEBUGLOG(("CheckPspLimit TxnCountry = [%s]\n",csTxnCountry));
DEBUGLOG(("CheckPspLimit TxnCcy = [%s]\n",csTxnCcy));
DEBUGLOG(("CheckPspLimit PayMethod = [%s]\n",csPayMethod));
DEBUGLOG(("CheckPspLimit ------------------------------------------\n"));
*/

        DBObjPtr = CreateObj(DBPtr,"DBRulePspLbPsp","GetPspLimit");
        iRet = (unsigned long)(*DBObjPtr)(csId,csServiceCode,csTxnCountry,csTxnCcy,csPayMethod,dPoolCurr,dTotalPoolCurr,dPoolReqCurr,dTotalPoolReqCurr);

        if (iRet == PD_OK) {
DEBUGLOG(("Rule limit = [%f] current hit = [%f]\n",dLimit,*dPoolCurr));

                //if (*dTotalPoolCurr == 0.0) {
//DEBUGLOG(("CheckPspLimit() Not Yet Exceed Limit since no txn had been made for this psp [%s]+++\n",csId));
//                }
//                else
		if (newround(*dTotalPoolCurr + dTxnAmt,PD_DECIMAL_LEN) > dLimit) {
DEBUGLOG(("CheckPspLimit() Exceed Limit [%f] + [%f]> [%f]+++\n",*dTotalPoolCurr,dTxnAmt,dLimit));
                        iRet = INT_EXCEED_LIMIT_PSP_AMT;
                }
                else {
DEBUGLOG(("CheckPspLimit() Not Yet Exceed Limit (%f + %f <= %f [%s]+++\n",*dTotalPoolCurr,dTxnAmt,dLimit,csId));
                }
        }
DEBUGLOG(("ChecPspLimit() exit iRet = [%d]\n",iRet));
        return iRet;
}


int CheckAllPossiblePspLimit(hash_t* hContext,
				const hash_t* hRequest)
{
	int	iRet = PD_OK;
	int	iCnt = 0;
	int	avaCnt = 0;
	char*	csTmp;

	char*	csMerchantId;
	char*	csTxnCcy;
	double	dTxnAmt;

	double	dPspLimit = -1.0;
	double	dPspRemainingLimit = -1.0;
	char*	csPspCcy;
	double	dConvertAmt = -1.0;

	recordset_t	*rRecordSet;

	if (GetField_CString(hRequest, "merchant_id", &csMerchantId)) { 
DEBUGLOG(("CheckAllPossiblePspLimit() merchant_id = [%s]\n",csMerchantId)); 
	} else {
		iRet = PD_ERR;
DEBUGLOG(("CheckAllPossiblePspLimit() merchant_id missing!!!\n")); 
	}

	if (GetField_CString(hRequest, "txn_ccy", &csTxnCcy)) { 
DEBUGLOG(("CheckAllPossiblePspLimit() txn_ccy = [%s]\n",csTxnCcy)); 
	} else {
		iRet = PD_ERR;
DEBUGLOG(("CheckAllPossiblePspLimit() txn_ccy missing!!!\n")); 
	}

	if (GetField_Double(hContext, "org_txn_amt", &dTxnAmt)) { 
DEBUGLOG(("CheckAllPossiblePspLimit() txn_amt = [%lf]\n",dTxnAmt)); 
	} else {
		iRet = PD_ERR;
DEBUGLOG(("CheckAllPossiblePspLimit() txn_amt missing!!!\n")); 
	}

        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	hash_t	*hRec;

DEBUGLOG(("CheckAllPossiblePspLimit Call GetAllPspByMerch ()\n")); 
	DBObjPtr = CreateObj(DBPtr,"DBRuleLB","GetAllPspByMerch");
	iRet = (unsigned long)(*DBObjPtr)(csMerchantId,rRecordSet);
	if(iRet == PD_OK){
		hRec = RecordSet_GetFirst(rRecordSet);
		while(hRec){

			dPspLimit = -1.0;
			dPspRemainingLimit = -1.0;
			dConvertAmt = -1.0;

			if (GetField_CString(hRec, "psp_name", &csTmp)) { 
DEBUGLOG(("GetAllPspByMerch() [%02d] psp_name = [%s]\n",iCnt,csTmp)); 
			}

			if (GetField_CString(hRec, "psp_id", &csTmp)) { 
//DEBUGLOG(("GetAllPspByMerch() [%02d] psp_id = [%s]\n",iCnt,csTmp)); 
			}

			if (GetField_CString(hRec, "psp_ccy", &csPspCcy)) { 
//DEBUGLOG(("GetAllPspByMerch() [%02d] currency_id = [%s]\n",iCnt,csPspCcy)); 
			} else {
DEBUGLOG(("GetAllPspByMerch() [%02d] currency_id missing!!!\n",iCnt)); 
			}

			if (GetField_Double(hRec, "psp_limit", &dPspLimit)) { 
//DEBUGLOG(("GetAllPspByMerch() [%02d] limit = [%lf]\n",iCnt,dPspLimit)); 
			} else {
DEBUGLOG(("GetAllPspByMerch() [%02d] limit missing!!!\n",iCnt)); 
			}

			if (GetField_Double(hRec, "psp_remaining_limit", &dPspRemainingLimit)) { 
DEBUGLOG(("GetAllPspByMerch() [%02d] remaining_limit = [%lf]\n",iCnt,dPspRemainingLimit)); 
			} else {
DEBUGLOG(("GetAllPspByMerch() [%02d] remaining_limit missing!!!\n",iCnt)); 
			}

			if (dPspRemainingLimit > 0.0){
				if (strcmp(csPspCcy, csTxnCcy)){
					PutField_CString(hContext,"dst_txn_ccy",csPspCcy);
					PutField_Int(hContext,"get_info_only",PD_TRUE);
DEBUGLOG(("CheckAllPossiblePspLimit Call GetExchangeInfo()\n")); 
					BOObjPtr = CreateObj(BOPtr,"BOExchange","GetExchangeInfo");
					iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
					if(iRet != PD_OK || !GetField_Double(hContext, "dst_txn_amt", &dConvertAmt)){
						dConvertAmt = -1.0;
DEBUGLOG(("CheckAllPossiblePspLimit Call GetExchangeInfo() Fail!!!\n")); 
					}
				} else {
					dConvertAmt = dTxnAmt;
				}

DEBUGLOG(("CheckAllPossiblePspLimit amount [%lf] in ccy [%s]\n",dConvertAmt,csPspCcy)); 
				if (iRet == PD_OK) {
					if (dPspRemainingLimit >= dConvertAmt && dConvertAmt > 0.0){
						avaCnt++;
						break;
					} else {
DEBUGLOG(("CheckAllPossiblePspLimit exceed limit!\n"));
					}
				}
			}

			iCnt++;
			hRec = RecordSet_GetNext(rRecordSet);
		}	
	} else {
DEBUGLOG(("CheckAllPossiblePspLimit Call GetAllPspByMerch () Fail!!!\n")); 
	}

	RecordSet_Destroy(rRecordSet);
	
	if(iRet == PD_OK){
		if(avaCnt == 0){
			iRet = INT_EXCEED_LIMIT_PSP_AMT;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}
//DEBUGLOG(("CheckAllPossiblePspLimit Psp cnt = [%d/%d]\n",avaCnt,iCnt));
DEBUGLOG(("CheckAllPossiblePspLimit iRet = [%d]\n",iRet));
	return iRet;
}


int CheckEffectiveScheduler(int iId,const char* csTxnDateTime)
{
	int	iRet = PD_ERR;
	recordset_t     *rRecordSet;
	hash_t	*hRec;
	//char	cMode;
	char	*csStartDateTime;
	char	*csEndDateTime;
	//char	csTime[PD_TIME_LEN +1];
	int	iDayOfWeek;
	//int	iDay;
DEBUGLOG(("CheckEffectiveScheduler()\n"));
DEBUGLOG(("CheckEffectiveScheduler() id = [%d] txn datetime = [%s]\n",iId,csTxnDateTime));
	iDayOfWeek = day_of_week((const unsigned char*)csTxnDateTime);
	//memcpy(csTime,&csTxnDateTime[PD_DATE_LEN],PD_TIME_LEN);
	//csTime[PD_TIME_LEN] = '\0';
//DEBUGLOG(("CheckEffectiveScheduler() txn datetime = [%s] txn time = [%s]\n",csTxnDateTime,csTime));
DEBUGLOG(("CheckEffectiveScheduler() day of week = [%d]\n",iDayOfWeek));

	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	DBObjPtr = CreateObj(DBPtr,"DBRuleSchedulerHeader","GetIdDetail");	
	if ((unsigned long)(*DBObjPtr)(iId,rRecordSet) == PD_FOUND) {
		iRet = PD_ERR;
		hRec = RecordSet_GetFirst(rRecordSet);
		while(hRec && (iRet==PD_ERR)){
			if (GetField_CString(hRec,"effect_datetime",&csStartDateTime)) {
DEBUGLOG(("CheckEffectiveScheduler() effect_datetime = [%s]\n",csStartDateTime));
				if (memcmp(csTxnDateTime,csStartDateTime,PD_DATETIME_LEN) >= 0) {
					if (GetField_CString(hRec,"end_datetime",&csEndDateTime)) {
DEBUGLOG(("CheckEffectiveScheduler() end_datetime = [%s]\n",csEndDateTime));
						if (memcmp(csTxnDateTime,csEndDateTime,PD_DATETIME_LEN) < 0) {
							iRet = PD_OK;
						}
					}
					else
						iRet = PD_OK;
				}
				else {
DEBUGLOG(("CheckEffectiveScheduler() id [%d] [%s] not effective now\n",iId,csStartDateTime));
				}
			}
			hRec = RecordSet_GetNext(rRecordSet);
		}//end while
	}

	RecordSet_Destroy(rRecordSet);
       	FREE_ME(rRecordSet);
DEBUGLOG(("CheckEffectiveScheduler exit iRet = [%d]\n",iRet));
	return	iRet;
}








int GetTxnPsp_Card(hash_t *hContext,
                const hash_t* hRequest)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	cPtr;
	char	*csOrgTxnSeq;
	char	*csMerchantId;
	char	*csServiceCode;
	char	*csChannelCode;
	char	*csTxnCountry;
	char	*csTxnCcy;
	char	*csPspCcy; 
	char	*csPayMethod;
	char	*csOrgDateTime;
	char	*csBankCode;
	char	*csCustomerGroup = NULL;
	double	dTxnAmt = 0.0;
	double	dPspAmt = 0.0;
	double	dTmp= 0.0;
	int	iChk = 0;
	int	iSARIP = PD_FALSE;
	int	iCustSegEnabled = PD_FALSE;
	double	dDefSmallAmt = 50.0;
	char	cCardType;
	int	iTmp = 0;
	int	iPhase = 0;
	
	hash_t	*hReq, *hRec;
	hash_t	*hPsp;
	hash_t	*hTxn;
	recordset_t     *rRecordSet;

DEBUGLOG(("GetTxnPsp_Card()\n"));
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
       	recordset_init(rRecordSet,0);	

 
	hReq = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hReq,0);

	hPsp = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hPsp,0);

//card type
	if(GetField_Char(hContext,"card_type",&cCardType)){
		PutField_Char(hReq,"card_type",cCardType);
DEBUGLOG(("GetTxnPsp_Card() Card Type = [%c]\n",cCardType));
	}
	else {
DEBUGLOG(("GetTxnPsp_Card() card_type is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp_Card() card_type is missing!!!\n");
		iRet = PD_ERR;
	}

/* channel Code */
	if (GetField_CString(hContext,"channel_code",&csChannelCode)) {
DEBUGLOG(("GetTxnPsp_Card() Channel Code = [%s]\n",csChannelCode));
		PutField_CString(hReq,"channel_code",csChannelCode);
	}
	else {
DEBUGLOG(("GetTxnPsp_Card() channel Code is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp_Card() channel Code is missing!!!\n");
		iRet = PD_ERR;
	}

/* service code  */
	if (GetField_CString(hRequest,"service_code",&csServiceCode)) {
DEBUGLOG(("GetTxnPsp_Card() service_code = [%s]\n",csServiceCode));
		PutField_CString(hReq,"service_code",csServiceCode);
	}
	else if (GetField_CString(hContext,"org_service_code",&csServiceCode)) {
DEBUGLOG(("GetTxnPsp_Card() service_code = [%s]\n",csServiceCode));
		PutField_CString(hReq,"service_code",csServiceCode);
	}
	else {
DEBUGLOG(("GetTxnPsp_Card() service_code is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp_Card() service_code is missing!!!\n");
		iRet = PD_ERR;
	}

/* payment_method  */
	if (GetField_CString(hContext,"selected_pay_method",&csPayMethod)) {
DEBUGLOG(("GetTxnPsp_Card() selected_pay_method  = [%s]\n",csPayMethod));
		PutField_CString(hReq,"pay_method",csPayMethod);
	}
	else {
DEBUGLOG(("GetTxnPsp_Card() selected_pay_method  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp_Card() selected_pay_method is missing!!!\n");
	}

/* txn_country  */
	if (GetField_CString(hRequest,"txn_country",&csTxnCountry)) {
DEBUGLOG(("GetTxnPsp_Card() txn_country  = [%s]\n",csTxnCountry));
		PutField_CString(hReq,"txn_country",csTxnCountry);
	}
	else if (GetField_CString(hContext,"org_txn_country",&csTxnCountry)) {
DEBUGLOG(("GetTxnPsp_Card() txn_country  = [%s]\n",csTxnCountry));
		PutField_CString(hReq,"txn_country",csTxnCountry);
	}
	else {
DEBUGLOG(("GetTxnPsp_Card() txn_country  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp_Card() txn_country  is missing!!!\n");
		iRet = PD_ERR;
	}

/* txn_ccy  */
	if (GetField_CString(hRequest,"txn_ccy",&csTxnCcy)) {
DEBUGLOG(("GetTxnPsp_Card() txn_ccy  = [%s]\n",csTxnCcy));
		PutField_CString(hReq,"txn_ccy",csTxnCcy);
	}
	else if (GetField_CString(hContext,"org_txn_ccy",&csTxnCcy)) {
DEBUGLOG(("GetTxnPsp_Card() txn_ccy  = [%s]\n",csTxnCcy));
		PutField_CString(hReq,"txn_ccy",csTxnCcy);
	}
	else {
DEBUGLOG(("GetTxnPsp_Card() txn_ccy  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp_Card() txn_ccy  is missing!!!\n");
		iRet = PD_ERR;
	}

/* merchant_id  */
	if (GetField_CString(hRequest,"merchant_id",&csMerchantId)) {
DEBUGLOG(("GetTxnPsp_Card() merchant_id  = [%s]\n",csMerchantId));
		PutField_CString(hReq,"merchant_id",csMerchantId);
	}
	else if (GetField_CString(hContext,"org_merchant_id",&csMerchantId)) {
DEBUGLOG(("GetTxnPsp_Card() merchant_id  = [%s]\n",csMerchantId));
		PutField_CString(hReq,"merchant_id",csMerchantId);
	}
	else {
DEBUGLOG(("GetTxnPsp_Card() merchant_id  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp_Card() merchant_id  is missing!!!\n");
		iRet = PD_ERR;
	}

/* merchant_clinet_id  */
	if (GetField_CString(hRequest,"client_id",&csPtr)) {
DEBUGLOG(("GetTxnPsp_Card() client_id  = [%s]\n",csPtr));
		PutField_CString(hReq,"client_id",csPtr);
	}
	else if (GetField_CString(hContext,"org_client_id",&csPtr)) {
DEBUGLOG(("GetTxnPsp_Card() client_id  = [%s]\n",csPtr));
		PutField_CString(hReq,"client_id",csPtr);
	}
	else {
DEBUGLOG(("GetTxnPsp_Card() merchant_client_id  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp_Card() merchant_client_id  is missing!!!\n");
		iRet = PD_ERR;
	}

/* business_type */
	if (GetField_Char(hContext,"org_merchant_type",&cPtr)) {
DEBUGLOG(("GetTxnPsp_Card() merchant_type  = [%c]\n",cPtr));
		PutField_Char(hReq,"business_type",cPtr);
	}
	else {
DEBUGLOG(("GetTxnPsp_Card() merchant_type  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp_Card() merchant_type  is missing!!!\n");
		iRet = PD_ERR;
	}

	if(GetField_Int(hContext,"cust_seg_enabled",&iCustSegEnabled)){
DEBUGLOG(("GetTxnPsp_Card() customer_segment_enabled  = [%d]\n",iCustSegEnabled));
	}

	if(iCustSegEnabled){
/* customer_segment */
		if (GetField_CString(hContext,"customer_group",&csCustomerGroup)) {
DEBUGLOG(("GetTxnPsp_Card() customer_group (tag)  = [%s]\n",csCustomerGroup));
			PutField_CString(hReq,"customer_segment",csCustomerGroup);
		}
	}

/* txn_amt */
	if (GetField_Double(hRequest,"txn_amt",&dTxnAmt)) {
		dPspAmt = dTxnAmt;
		PutField_Double(hReq,"txn_amt",dTxnAmt);
		PutField_Double(hReq,"psp_amt",dTxnAmt);
DEBUGLOG(("GetTxnPsp_Card() txn_amt  = [%f]\n",dTxnAmt));
	}
	else if (GetField_Double(hContext,"org_txn_amt",&dTxnAmt)) {
		dPspAmt = dTxnAmt;
		PutField_Double(hReq,"txn_amt",dTxnAmt);
		PutField_Double(hReq,"psp_amt",dTxnAmt);
DEBUGLOG(("GetTxnPsp_Card() txn_amt  = [%f]\n",dTxnAmt));
	}
	else {
DEBUGLOG(("GetTxnPsp_Card() txn_amt  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp_Card() txn_amt  is missing!!!\n");
		iRet = PD_ERR;
	}


	/* org_encrypted_txn_seq */
	if (GetField_CString(hRequest,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("GetTxnPsp_Card() from txn seq = [%s]\n",csOrgTxnSeq));
		PutField_CString(hReq,"from_txn_seq",csOrgTxnSeq);
	}
	else if (GetField_CString(hRequest,"org_encrypted_txn_seq",&csPtr)) {
DEBUGLOG(("GetTxnPsp_Card() org_encrypted_txn_seq = [%s]\n",csPtr));
		BOObjPtr = CreateObj(BOPtr,"BOSecurity","Decrypt3DESTxnSeq");
		char* csTmpBuf;
		csTmpBuf = (char*) malloc (PD_EN_TXN_SEQ_LEN +1);
		(BOObjPtr)(csPtr,csTmpBuf);
		csOrgTxnSeq = strdup(csTmpBuf);
DEBUGLOG(("GetTxnPsp_Card() org_txn_seq = [%s]\n",csOrgTxnSeq));
		PutField_CString(hReq,"from_txn_seq",csOrgTxnSeq);
		FREE_ME(csTmpBuf);
	}
	else {
DEBUGLOG(("GetTxnPsp_Card() org_encrypted_txn_seq  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp_Card() org_encrypted_txn_seq  is missing!!!\n");
		iRet = PD_ERR;
	}




	char*   csValueTmp;
	csValueTmp = (char*) malloc (128);
	DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
	if ((unsigned long)(DBObjPtr)("LB_SMALL_AMT",csValueTmp) == FOUND) {
		sscanf(csValueTmp, "%lf",&dDefSmallAmt);
DEBUGLOG(("SystemParameter::Define Load Balance Small Amount = [%lf]\n",dDefSmallAmt));
	}
	FREE_ME(csValueTmp);

/* psp amt*////for difference currency
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);
	DBObjPtr = CreateObj(DBPtr,"DBRuleLB","GetDstCcyWithoutRule");
	if((unsigned long)(DBObjPtr)(csMerchantId,csServiceCode,hTxn)==PD_OK){
		if (GetField_CString(hTxn,"psp_ccy",&csPspCcy)) {
DEBUGLOG(("BOTxnLb() Get Psp ccy [%s]\n",csPspCcy));
		}
	}
	if(strcmp(csTxnCcy,csPspCcy) &&
           GetField_CString(hContext,"from_txn_seq",&csOrgTxnSeq)){
		DBObjPtr = CreateObj(DBPtr,"DBTmpCalAmount","GetTmpCalAmount");
                if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq,hContext) == PD_FOUND) {
                        if(GetField_Double(hContext,"dst_net_amt",&dTmp)){
                                dPspAmt = dTmp;
				PutField_Double(hContext,"dst_txn_amt",dPspAmt);
				PutField_Double(hReq,"psp_amt",dPspAmt);
DEBUGLOG(("Authorize() GetTmpCalAmount Found psp_amt [%lf]\n",dPspAmt));
                        }
                }
	}


/* org_local_tm_datetime  */
	if (GetField_CString(hContext,"org_local_tm_datetime",&csOrgDateTime)) {
DEBUGLOG(("GetTxnPsp_Card() org_local_tm_datetime  = [%s]\n",csOrgDateTime));
	}
	else {
DEBUGLOG(("GetTxnPsp_Card() org_local_tm_datetime  is missing!!!\n"));
ERRLOG("BOTxnLb::GetTxnPsp_Card() org_local_tm_datetime  is missing!!!\n");
		iRet = PD_ERR;
	}


/* "restricted_ip" default FALSE*/
	PutField_Int(hReq,"restricted_ip",PD_FALSE);

        if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBRuleLB","HaveDefineSmallAmtRule");
		if ((unsigned long)(DBObjPtr)(csChannelCode,
					csMerchantId,
					csServiceCode,
					csTxnCountry,
					csTxnCcy,
					cCardType,
					dTxnAmt) == PD_FOUND) {
			iSARIP = PD_TRUE;
		}

		if(GetField_CString(hRequest,"ip_addr", &csPtr)){
			PutField_CString(hReq,"ip_addr",csPtr);
			DBObjPtr = CreateObj(DBPtr,"DBIpFilter","GetIpFilter");
			if ((unsigned long)((*DBObjPtr)(csPtr)) == PD_FOUND) {
				DBObjPtr = CreateObj(DBPtr,"DBRuleLB","HaveDefineRestrictedIPRule");
				if ((unsigned long)(DBObjPtr)(csChannelCode,
							csMerchantId,
							csServiceCode,
							csTxnCountry,
							csTxnCcy,
							cCardType) == PD_FOUND) {

					iSARIP = PD_TRUE;
					PutField_Int(hReq,"restricted_ip",PD_TRUE);
				}
			}
		}
        }



/* bank_code  */
	if (GetField_CString(hContext,"bank_code",&csBankCode)) {
		iChk=PD_TRUE;
		PutField_CString(hReq,"bank_code",csBankCode);
DEBUGLOG(("GetTxnPsp_Card() bank_code  = [%s]\n",csBankCode));

		//if mobile service, check phase
		if(!strcmp(csServiceCode,PD_MOBILE_SERVICE)){
			DBObjPtr = CreateObj(DBPtr,"DBCustomerGroupMerchant","GetMerchantPhase");
                	iPhase = (unsigned long)(DBObjPtr)(csMerchantId);
DEBUGLOG(("GetTxnPsp_Card() GetMerchantPhase: phase = [%d]\n",iPhase));
		}

		//if mobile service, check if override customer_segment is needed (Phase 0)
		if((!strcmp(csServiceCode,PD_MOBILE_SERVICE)) && (iPhase<1)){
			//can be found in mob_bank_map?
			DBObjPtr = CreateObj(DBPtr,"DBMobBankMap","GetMobileSegment");
			if ((unsigned long)(DBObjPtr)(csMerchantId,
						csBankCode,
						hTxn) == PD_FOUND) {
				if(GetField_CString(hTxn,"mob_segment",&csPtr)){

					if(csCustomerGroup==NULL){
						//get temp group from txn_detail
						if (GetField_CString(hContext,"temp_customer_group",&csCustomerGroup)) {
							if(strcmp(csPtr,csCustomerGroup)){
								PutField_CString(hReq,"customer_segment",csPtr);
DEBUGLOG(("GetTxnPsp_Card() Customer Group[%s] not match with the selected bank option[%s]. Search by [%s]\n",csCustomerGroup,csPtr,csPtr));
							} else {
								PutField_CString(hReq,"customer_segment",csPtr);
							}
						}
						else{
							PutField_CString(hReq,"customer_segment",csPtr);
DEBUGLOG(("GetTxnPsp_Card() Temp Customer Group not found. Search by [%s]\n",csPtr));
						}
					}
					else{
						if(strcmp(csPtr,csCustomerGroup)){
							PutField_CString(hReq,"customer_segment",csPtr);
DEBUGLOG(("GetTxnPsp_Card() Customer Group[%s] not match with the selected bank option[%s]. Search by [%s]\n",csCustomerGroup,csPtr,csPtr));
						}
					}

				}
			}
			else{ //override by def group
				DBObjPtr = CreateObj(DBPtr,"DBMobBankSelection","GetDefSegment");
				if ((unsigned long)(DBObjPtr)(csMerchantId,
							hTxn) == PD_FOUND) {
					if(GetField_CString(hTxn,"def_segment",&csPtr)){
						PutField_CString(hReq,"customer_segment",csPtr);
DEBUGLOG(("GetTxnPsp_Card() Customer Group[%s] not related to the selected bank[%s]. Search by Default[%s]\n",csCustomerGroup,csBankCode,csPtr));
					}
				}
			}
		}
	}
	else {
		DBObjPtr = CreateObj(DBPtr,"DBService","IsSelectBank");
		iChk= (unsigned long)(DBObjPtr)(csServiceCode);
		if(iChk==PD_TRUE){
DEBUGLOG(("GetTxnPsp_Card() bank_code  is missing!!!\n"));
ERRLOG("BOTxnLB::GetTxnPsp_Card() bank_code  is missing!!!\n");
			iRet = PD_ERR;
		}
	}

	if(iRet ==PD_OK){
		if(iChk==PD_TRUE){

			//mobile service, new customer segment (>Phase 0)
                	if((!strcmp(csServiceCode,PD_MOBILE_SERVICE)) && (iPhase>0) && (iCustSegEnabled)){
				//For New Customer Segment Merchant (>Phase 0)
				PutField_Int(hReq,"sarip",iSARIP);
                               	PutField_CString(hReq,"match_mode",PD_MODE_MOBILE_SEGMENT_NEW);
			}
			else{
				if(iSARIP && iCustSegEnabled){
					//(For Customer segment) small amt/restricted IP 
					PutField_CString(hReq,"match_mode",PD_MODE_SARIP);
				}
				else{
					if(iCustSegEnabled){
						//For Customer segment Merchant
						PutField_CString(hReq,"match_mode",PD_MODE_SEGMENT_MERCH);
					}
					else{
						//For all other merchants
						PutField_CString(hReq,"match_mode",PD_MODE_OTHER_MERCH);
					}
				}
			}

			DBObjPtr = CreateObj(DBPtr,"DBRuleLB","MatchCriteria_Mode");
			if ((unsigned long)(*DBObjPtr)(hReq,rRecordSet) == PD_FOUND) {
				int iCnt = 0;
				int iLoop= PD_TRUE;
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec && iLoop) {
					if (GetField_Int(hRec,"criteria_pool_id",&iTmp)) {
						PutField_Int(hReq,"criteria_pool_id",iTmp);
DEBUGLOG(("GetTxnPsp_Card() [%02d] criteria_pool_id = [%d]\n",iCnt,iTmp));
					}

					if (GetField_Int(hRec,"priority",&iTmp)) {
DEBUGLOG(("GetTxnPsp_Card() [%02d] priority = [%d]\n",iCnt,iTmp));
					}

					iChk = ProcessScheme(hReq, hPsp);
					if(iChk == PD_OK){
						iLoop = PD_FALSE;
					}

					iCnt ++;
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}

			if(GetField_CString(hPsp,"psp_id",&csPtr)){
				PutField_CString(hContext,"psp_id",csPtr);
			}
			else{
				iRet = INT_PSP_NOT_AVAILABLE;
DEBUGLOG(("GetTxnPsp_Card() No Available PID\n",iRet));
			}

		}
		else{
			//when iChk = PD_FALSE;
		}
	}


	hash_destroy(hPsp);
        FREE_ME(hPsp);
	hash_destroy(hTxn);
	FREE_ME(hTxn);
	hash_destroy(hReq);
        FREE_ME(hReq);


	RecordSet_Destroy(rRecordSet);
       	FREE_ME(rRecordSet);

DEBUGLOG(("GetTxnPsp_Card() exit iRet = [%d]\n",iRet));
	return iRet;

}



int	ProcessScheme(hash_t *hIn, hash_t *hOut)
{
	int iRet = INT_PSP_NOT_AVAILABLE;
	int iCnt = 0;
	int iChk = PD_ERR;
	int iLoop= PD_TRUE;
	int iId = 0;
	int iPoolId = 0;

	GetField_Int(hIn,"criteria_pool_id",&iId);
DEBUGLOG(("ProcessScheme()------[%d]------\n",iId));

	hash_t *hPool;
	hPool = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hPool,0);

	hash_t *hRec;
	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);


	//Filter out the potential pool with bank code and pool limit is enough for the incomming deposit
	if(FindPotentialPool(hIn,rRecordSet) == PD_OK){
		iLoop= PD_TRUE;
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec && iLoop) {

			if (GetField_Int(hRec,"pool_id",&iPoolId)) {
DEBUGLOG(("ProcessScheme() FindPotentialPool:[%02d] pool id = [%d]\n",iCnt,iPoolId));
			}
			
			if(FindPoolDetail(hRec,hPool)!=PD_OK){
				iLoop = PD_FALSE;
				iChk = INT_ERR;
				iCnt = 0;
			}
			else{
				iChk = PD_OK;
				iCnt ++;
			}
			
			hRec = RecordSet_GetNext(rRecordSet);
		}

	}
	else{
DEBUGLOG(("ProcessScheme() No Pool Found!!!\n"));
	}



	if(iChk == PD_OK){
		iChk = INT_PSP_NOT_AVAILABLE;
		int iNumOfPri = 0;
		int iPriority = -1;
		int iRatio = 0;
		int iTotalRatio = 0;
		int iPriCnt = 0;
		int i = 0;
		int j = 0;
		int jLoop = PD_FALSE;
		int iSelected = 0;
		int iFinalPoolId = -1;
		double dReqAmt = 0.0;
		double dTotalReqAmt = 0.0;
		double dRatioDiff = 0.0;
		double dFinalRatioDiff = 0.0;
		double dPoolRatio = 0.0;
		double dTmpVolRatio = 0.0;
		int iRandIndex=0;
		int iRand =0;
		int iWaitRand =0;
		//int iTestRand =0;
		int a = 0;
		int b = 0;
		int iPoolList[PD_TMP_BUF_LEN]; //max 256 pools
		int iPoolTmpList[PD_TMP_BUF_LEN]; //max 256 pools
		int iWaitingList[PD_TMP_BUF_LEN]; //max 256 pools
		//int iTestList[PD_TMP_BUF_LEN]; //max 256 pools
		char csTag[PD_TAG_LEN+1];

		GetField_Int(hPool,"num_of_priority",&iNumOfPri);

DEBUGLOG(("------------let see which pool will fit------------\n"));
		//loop with different priority
		while(i<iNumOfPri && iLoop){

			iPriority = -1;
			iPriCnt = 0;
			iTotalRatio = 0;
			dTotalReqAmt = 0.0;
			iSelected = 0;
			dFinalRatioDiff = 1.0;

			sprintf(csTag,"priority_%d", i);
			if(GetField_Int(hPool,csTag,&iPriority)){
				sprintf(csTag,"priority_%d_cnt",iPriority);
				GetField_Int(hPool,csTag,&iPriCnt);

				sprintf(csTag,"pool_total_ratio_for_p%d",iPriority);
				GetField_Int(hPool,csTag,&iTotalRatio);

				sprintf(csTag,"pool_total_vol_for_p%d",iPriority);
				GetField_Double(hPool,csTag,&dTotalReqAmt);
DEBUGLOG(("------------Check [%d]Pool in Priority[%d] (total ratio:%d, total req_amt:%lf)------------\n",iPriCnt,iPriority,iTotalRatio,dTotalReqAmt));
			}

			if(iPriCnt > 0 && iTotalRatio > 0){
				jLoop = PD_TRUE;
				j = 0;
			}

			//loop pools in same priority
			while(j<iPriCnt && jLoop){
				iRatio = 0;
				dReqAmt = 0.0;
				dRatioDiff = 0.0;

				sprintf(csTag,"%d_ratio_%d",iPriority,j);
				GetField_Int(hPool,csTag,&iRatio);

				sprintf(csTag,"%d_req_amt_%d",iPriority,j);
				GetField_Double(hPool,csTag,&dReqAmt);

				sprintf(csTag,"%d_pool_id_%d", iPriority,j);
				GetField_Int(hPool,csTag,&iPoolId);

				if(iRatio > 0){

					dPoolRatio = (double)iRatio/(double)iTotalRatio;

					if(dReqAmt == 0.0 || dTotalReqAmt == 0.0)
						dTmpVolRatio = 0.0;
					else
						dTmpVolRatio = dReqAmt/dTotalReqAmt;

					dRatioDiff = newround((dTmpVolRatio - dPoolRatio)/dPoolRatio, PD_DECIMAL_LEN*2);

DEBUGLOG((">>>Priority[%d]: [%d]th pool id[%d] (ratio:%d (%.4f), req_amt:%.2f (%.4f), ratio diff:%.4f, prev ratio diff:%.4f)<<<\n",iPriority,j+1,iPoolId,iRatio,dPoolRatio,dReqAmt,dTmpVolRatio,dRatioDiff,dFinalRatioDiff));

					if(dTmpVolRatio < dPoolRatio){
						if(dRatioDiff < dFinalRatioDiff){
DEBUGLOG(("Pool[%d] selected.  The current ratio[%.2f] is more far away from the pool ratio[%.2f]\n",iPoolId,dTmpVolRatio,dPoolRatio));
							dFinalRatioDiff = dRatioDiff;

							if(iSelected>0){
								iPoolList[iRand] = iFinalPoolId;
								iRand++;
							}

							iFinalPoolId = iPoolId;
							iSelected++;
						}
						else if(dRatioDiff == dFinalRatioDiff){
DEBUGLOG(("Pool[%d] having same priority and ratio with other pool(s), insert into the random list[%d]\n",iRand));
							iPoolList[iRand] = iPoolId;
							iRand++;
						}
					}

					if(dTmpVolRatio >= dPoolRatio){
DEBUGLOG(("Pool[%d] put to waiting list\n",iPoolId));
						iWaitingList[iWaitRand] = iPoolId;
						iWaitRand++;
					}
				}

				j++;

			} //end of iPriCnt loop

			int iPickPsp = PD_FALSE;
			iRandIndex=0;
			b = 0;

			while (iChk != PD_OK) {
				iPickPsp = PD_FALSE;
				a = 0;

				if(iSelected>0){
					PutField_Int(hIn,"pool_id",iFinalPoolId);
					iPickPsp = PD_TRUE;
				}
				else if(iRand>0){
					iPickPsp = PD_TRUE;
					iRandIndex = rand() % iRand;
					iFinalPoolId = iPoolList[iRandIndex];
					PutField_Int(hIn,"pool_id",iFinalPoolId);
DEBUGLOG(("PoolList Idx = [%d]: Pool[%d] is selected\n",iRandIndex,iFinalPoolId));

					// prepare for re-selection from the list
					for (b = 0; b < iRand; b++ ) {
						if (b ==  iRandIndex)
							continue;
						else {
							iPoolTmpList[a]  = iPoolList[b];
							a++;
						}
					}
					iRand = a;
				}
				else if(iWaitRand>0){
					iPickPsp = PD_TRUE;
					iRandIndex = rand() % iWaitRand;
					iFinalPoolId = iWaitingList[iRandIndex];
					PutField_Int(hIn,"pool_id",iFinalPoolId);
DEBUGLOG(("WaitingList Idx = [%d]: Pool[%d] is selected\n",iRandIndex,iFinalPoolId));

					// prepare for re-selection from the list
					for (b = 0; b < iWaitRand; b++ ) {
						if (b ==  iRandIndex)
							continue;
						else {
							iPoolTmpList[a]  = iWaitingList[b];
							a++;
						}
					}
					iWaitRand = a;
				}



				if(iPickPsp){
DEBUGLOG(("+++ call PickPspFromPool[%d] +++\n",iFinalPoolId));
					iChk = PickPspFromPool(hIn, hOut);
DEBUGLOG(("+++ PickPspFromPool() iRet = [%d] +++\n",iChk));

					if (iChk != PD_OK) {
						if(iSelected>0){
							iSelected = 0;
						}
						else if(iRand>0){ 
							for (b = 0; b < iRand; b++ ) {
								iPoolList[b]  = iPoolTmpList[b];
							}
						}
						else if(iWaitRand>0){ 
							for (b = 0; b < iWaitRand; b++ ) {
								iPoolList[b]  = iPoolTmpList[b];
							}
						}
					}
					else{
						iLoop = PD_FALSE;
					}

				}
				else{
					break;
				}

			}//while loop(iChk != PD_OK)

			i++;

		}//end of iNumOfPri loop

	}

	iRet = iChk;

       	FREE_ME(hPool);
	RecordSet_Destroy(rRecordSet);
       	FREE_ME(rRecordSet);

DEBUGLOG(("ProcessScheme() iRet = [%d]\n",iRet));
	return iRet;
}



int FindPotentialPool(hash_t *hIn,recordset_t* rRs)
{
	int	iRet = PD_OK;
	char	*csPtr;
	double 	dPtr;
	int	iPtr;

	hash_t	*hRec;
        recordset_t     *rRecordSet;

	hash_t	*hRsp;

DEBUGLOG(("FindPotentialPool()\n"));
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	DBObjPtr = CreateObj(DBPtr,"DBRuleLB","FindPotentialPool");	
	if ((unsigned long)(*DBObjPtr)(hIn,rRecordSet) == PD_FOUND) {
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			hRsp = (hash_t*) malloc (sizeof(hash_t));
			hash_init(hRsp,0);

			if (GetField_Int(hIn,"criteria_pool_id",&iPtr)) {
				PutField_Int(hRsp,"criteria_pool_id",iPtr);
			}
/* pool_id */
			if (GetField_Int(hRec,"pool_id",&iPtr)) {
				PutField_Int(hRsp,"pool_id",iPtr);
			}
/* desc */
			if (GetField_CString(hRec,"desc",&csPtr)) {
				PutField_CString(hRsp,"desc",csPtr);
			}

/* pool limit */
			if (GetField_Double(hRec,"pool_limit",&dPtr)) {
				PutField_Double(hRsp,"pool_limit",dPtr);
			}
/* ratio */
			if (GetField_Int(hRec,"ratio",&iPtr)) {
				PutField_Int(hRsp,"ratio",iPtr);
			}
/* priority */
			if (GetField_Int(hRec,"priority",&iPtr)) {
				PutField_Int(hRsp,"priority",iPtr);
			}

			RecordSet_Add(rRs,hRsp);
			hRec = RecordSet_GetNext(rRecordSet);
		}
	}
	else{
		iRet = PD_ERR;
	}

	RecordSet_Destroy(rRecordSet);
       	FREE_ME(rRecordSet);

DEBUGLOG(("FindPotentialPool() exit iRet = [%d]\n",iRet));
	return	iRet;
}



int FindPoolDetail(hash_t *hIn, hash_t *hOut)
{
	int	iRet = PD_OK;
	int	iTmp = 0;
	double	dTmp = 0.0;
	double 	dReqAmt = 0.0;
	int	iPoolId = 0;
	int	iRatio = 0;
	int	iPriority = 0;
	int	iPrevPriority = -1;
	int	iPriCnt = 0;
	char    csTag[PD_TAG_LEN+1];

	hash_t *hRec;
	hRec = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hRec,0);

DEBUGLOG(("FindPoolDetail()\n"));

	DBObjPtr = CreateObj(DBPtr,"DBRuleLB","FindPoolDetail");	
	if ((unsigned long)(*DBObjPtr)(hIn,hRec) == PD_FOUND) {
		if (GetField_Int(hRec,"pool_id",&iPoolId)) {
DEBUGLOG(("FindPoolDetail pool_id = [%d]\n",iPoolId));
		}
		if (GetField_Int(hRec,"ratio",&iRatio)) {
DEBUGLOG(("FindPoolDetail pool_ratio = [%d]\n",iRatio));
		}
		if (GetField_Int(hRec,"priority",&iPriority)) {
DEBUGLOG(("FindPoolDetail pool_priority = [%d]\n",iPriority));
		}

		if (GetField_Double(hRec,"req_amt",&dReqAmt)) {
DEBUGLOG(("FindPoolDetail Requested Amt = [%lf]\n",dReqAmt));
		}

		sprintf(csTag,"pool_total_vol_for_p%d",iPriority);
		dTmp = 0.0;
		GetField_Double(hOut,csTag,&dTmp);
		PutField_Double(hOut,csTag,dTmp+dReqAmt);

		sprintf(csTag,"pool_total_ratio_for_p%d",iPriority);
		iTmp = 0;
		GetField_Int(hOut,csTag,&iTmp);
		PutField_Int(hOut,csTag,iTmp+iRatio);

		sprintf(csTag,"prev_priority");
		GetField_Int(hOut,csTag,&iPrevPriority);
		if(iPrevPriority == iPriority){
			iTmp = 0;
			sprintf(csTag,"priority_%d_cnt",iPriority);
			GetField_Int(hOut,csTag,&iTmp);
			iPriCnt = iTmp + 1;
			PutField_Int(hOut,csTag,iPriCnt);
DEBUGLOG(("pool id [%d] is the [%d]th in Priority[%d]\n",iPoolId,iPriCnt,iPriority));
		}
		else{
			iTmp = 0;
			GetField_Int(hOut,"num_of_priority",&iTmp);
			PutField_Int(hOut,"num_of_priority",iTmp+1);
			sprintf(csTag,"priority_%d",iTmp);
			PutField_Int(hOut,csTag,iPriority);
DEBUGLOG(("Number of Priority[%d] is now[%d]\n",iPriority,iTmp+1));

			iTmp = 0;
			sprintf(csTag,"priority_%d_cnt",iPriority);
			GetField_Int(hOut,csTag,&iTmp);
			iPriCnt = iTmp + 1;
			PutField_Int(hOut,csTag,iPriCnt);
DEBUGLOG(("pool id [%d] is the [%d]th in Priority[%d]\n",iPoolId,iPriCnt,iPriority));

			sprintf(csTag,"prev_priority");
			PutField_Int(hOut,csTag,iPriority);

		}

		sprintf(csTag,"%d_pool_id_%d",iPriority,iPriCnt-1);
		PutField_Int(hOut,csTag,iPoolId);

		sprintf(csTag,"%d_ratio_%d",iPriority,iPriCnt-1);
		PutField_Int(hOut,csTag,iRatio);

		sprintf(csTag,"%d_req_amt_%d",iPriority,iPriCnt-1);
		PutField_Double(hOut,csTag,dReqAmt);

	}
	else{
		iRet = PD_ERR;
	}

	FREE_ME(hRec);
DEBUGLOG(("FindPoolDetail() exit iRet = [%d]\n",iRet));
	return	iRet;
}





int PickPspFromPool(hash_t *hIn, hash_t *hOut)
{
	int	iRet = INT_PSP_NOT_AVAILABLE;

DEBUGLOG(("PickPspFromPool Start\n"));
	hash_t *hPsp;
	hPsp = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hPsp,0);

	//Filter out the potential PID with bank code and PID limit is enough for the incomming deposit
	if(FindPoolPspDetail(hIn,hPsp)==PD_OK){

		int iChk = INT_PSP_NOT_AVAILABLE;
		int iNumOfPri = 0;
		int iPriority = -1;
		int iRatio = 0;
		int iTotalRatio = 0;
		int iPriCnt = 0;
		int i = 0;
		int j = 0;
		int iLoop = PD_TRUE;
		int jLoop = PD_FALSE;
		int iSelected = 0;
		double dReqAmt = 0.0;
		double dTotalReqAmt = 0.0;
		double dRatioDiff = 0.0;
		double dFinalRatioDiff = 0.0;
		double dPspRatio = 0.0;
		double dTmpVolRatio = 0.0;
		int iRandIndex=0;
		int iRand =0;
		int iWaitRand =0;
		int iTestRand =0;
		int a = 0;
		int b = 0;
		char csPspList[PD_TMP_BUF_LEN][PD_PSP_ID_LEN +1]; //max 256 psp
		char csWaitingList[PD_TMP_BUF_LEN][PD_PSP_ID_LEN +1]; //max 256 psp
		char csTestList[PD_TMP_BUF_LEN][PD_PSP_ID_LEN +1]; //max 256 psp
		char csTag[PD_TAG_LEN+1];
		char *csPspId = NULL;
		char csSelectedPspId[PD_PSP_ID_LEN+1];

		GetField_Int(hPsp,"num_of_priority",&iNumOfPri);

DEBUGLOG(("------------let see which PID will fit------------\n"));
		//loop with different priority
		while(i<iNumOfPri && iLoop){

			iPriority = -1;
			iPriCnt = 0;
			iTotalRatio = 0;
			dTotalReqAmt = 0.0;
			iSelected = 0;
			dFinalRatioDiff = 1.0;

			sprintf(csTag,"priority_%d", i);
			if(GetField_Int(hPsp,csTag,&iPriority)){
				sprintf(csTag,"priority_%d_cnt",iPriority);
				GetField_Int(hPsp,csTag,&iPriCnt);

				sprintf(csTag,"total_ratio_for_p%d",iPriority);
				GetField_Int(hPsp,csTag,&iTotalRatio);

				sprintf(csTag,"total_vol_for_p%d",iPriority);
				GetField_Double(hPsp,csTag,&dTotalReqAmt);
DEBUGLOG(("------------Check PID(s) in Priority[%d] (total ratio:%d, total req_amt:%lf)------------\n",iPriority,iTotalRatio,dTotalReqAmt));
			}

			if(iPriCnt > 0 && iTotalRatio > 0){
				jLoop = PD_TRUE;
				j = 0;
			}

			//loop pools in same priority
			while(j<iPriCnt && jLoop){
				iRatio = 0;
				dReqAmt = 0.0;
				dRatioDiff = 0.0;

				sprintf(csTag,"%d_ratio_%d",iPriority,j);
				GetField_Int(hPsp,csTag,&iRatio);

				sprintf(csTag,"%d_req_amt_%d",iPriority,j);
				GetField_Double(hPsp,csTag,&dReqAmt);

				sprintf(csTag,"%d_psp_id_%d", iPriority,j);

				if(GetField_CString(hPsp,csTag,&csPspId) && (iRatio > 0)){

					dPspRatio = (double)iRatio/(double)iTotalRatio;

					if(dReqAmt == 0.0 || dTotalReqAmt == 0.0)
						dTmpVolRatio = 0.0;
					else
						dTmpVolRatio = dReqAmt/dTotalReqAmt;

					dRatioDiff = newround((dTmpVolRatio - dPspRatio)/dPspRatio, PD_DECIMAL_LEN*2);

DEBUGLOG((">>>Priority[%d]: [%d]th PID[%s] (ratio:%d (%.4f), req_amt:%.2f (%.4f), ratio diff:%.4f, prev ratio diff:%.4f)<<<\n",iPriority,j+1,csPspId,iRatio,dPspRatio,dReqAmt,dTmpVolRatio,dRatioDiff,dFinalRatioDiff));
					if(dTmpVolRatio < dPspRatio){
						if(dRatioDiff < dFinalRatioDiff){
DEBUGLOG(("PID[%s] selected.  The current ratio[%.2f] is more far away from the PID ratio[%.2f]\n",csPspId,dTmpVolRatio,dPspRatio));
							dFinalRatioDiff = dRatioDiff;
							//iFinalPoolId = iPoolId;
							strcpy(csSelectedPspId,csPspId);
							iSelected++;
							iWaitRand = 0;
							iRand = 0;
						}
						else if(dRatioDiff >= dFinalRatioDiff){
							if(iSelected == 0){
DEBUGLOG(("PID[%d] having same priority and ratio with other PID(s), insert into the random list[%d]\n",iRand));
								//iPoolList[iRand] = iPoolId;
								strcpy(csPspList[iRand],csPspId);
								iRand++;
								iWaitRand = 0;
							}
						}
					}

					if(dTmpVolRatio >= dPspRatio){
						if(iSelected == 0){
DEBUGLOG(("PID[%s] put to waiting list\n",csPspId));
							//iWaitingList[iWaitRand] = iPoolId;
							strcpy(csWaitingList[iWaitRand],csPspId);
							iWaitRand++;
						}
					}
				}

				j++;

			} //end of iPriCnt loop


			iRandIndex=0;
			iTestRand =0;
			b = 0;

			if(iWaitRand>0){
DEBUGLOG(("Select PID from waiting list (total [%d])\n",iWaitRand));
				iTestRand = iWaitRand;
				for(a=0; a<iWaitRand; a++){
					//iTestList[a]=iWaitingList[a];
					strcpy(csTestList[a],csWaitingList[a]);
				}
			}
			if(iRand>0){
DEBUGLOG(("Select PID from random list (total [%d])\n",iRand));
				iTestRand = iRand;
				for(a=0; a<iRand; a++){
					//iTestList[a]=iPoolList[a];
					strcpy(csTestList[a],csPspList[a]);
				}
			}


			if(iTestRand>0){
				iRandIndex = rand() % iTestRand;
				//iFinalPoolId = iTestList[iRandIndex];
				strcpy(csSelectedPspId,csTestList[iRandIndex]);
DEBUGLOG(("PoolList Idx = [%d]: PID[%s] is selected\n",iRandIndex,csSelectedPspId));
				iLoop = PD_FALSE;
				iChk = PD_OK;
				PutField_CString(hOut,"psp_id",csSelectedPspId);
			}

			if(iSelected){
				iLoop = PD_FALSE;
				iChk = PD_OK;
				PutField_CString(hOut,"psp_id",csSelectedPspId);
DEBUGLOG(("PickPspFromPool: PID[%s] is selected!!!\n",csSelectedPspId));
			}

			i++;

		}//end of iNumOfPri loop

		iRet = iChk;
		
	}
	else{
DEBUGLOG(("PickPspFromPool: No Pool Found!!!\n"));
	}

	FREE_ME(hPsp);
DEBUGLOG(("PickPspFromPool Exit\n"));
	return iRet;
}


int FindPoolPspDetail(hash_t *hIn, hash_t *hOut)
{
	int	iRet = PD_OK;
	int	iChk = PD_ERR;
	char	*csChannel = NULL;
	char	*csBank = NULL;
	char	*csPspId = NULL;
	char	*csServiceCode = NULL;
	char	*csIpAddr = NULL;

	char	*csCustTag = NULL;
	char	*csOrgTxnSeq = NULL;
	char	*csOrgMerchantId = NULL;
	char	csCustomerGroup[PD_CUSTOMER_GROUP_CODE_LEN +1];

	int	iTmp = 0;
	double	dTmp = 0.0;
	double 	dReqAmt = 0.0;
	double 	dTxnAmt = 0.0;
	int	iPoolId = 0;
	int	iRejSmallDelta = PD_FALSE;
	int	iRatio = 0;
	int	iPriority = 0;
	int	iPrevPriority = -1;
	int	iPriCnt = 0;
	char    csTag[PD_TAG_LEN+1];

	hash_t	*hRec;
        recordset_t     *rRecordSet;

	hash_t *hTmp;
	hash_t *hTxnInfo;
	
	hTmp = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTmp, 0);
	
	hTxnInfo = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxnInfo, 0);


DEBUGLOG(("FindPoolPspDetail()\n"));
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	DBObjPtr = CreateObj(DBPtr,"DBRuleLB","FindPoolPspDetail");	
	if ((unsigned long)(*DBObjPtr)(hIn,rRecordSet) == PD_FOUND) {
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {

			if (GetField_Int(hRec,"pool_id",&iPoolId)) {
DEBUGLOG(("FindPoolPspDetail pool_id = [%d]\n",iPoolId));
			}
			if (GetField_CString(hRec,"psp_id",&csPspId)) {
DEBUGLOG(("FindPoolPspDetail psp_id = [%s]\n",csPspId));
			}
			if (GetField_Int(hRec,"psp_ratio",&iRatio)) {
DEBUGLOG(("FindPoolPspDetail psp_ratio = [%d]\n",iRatio));
			}
			if (GetField_Int(hRec,"psp_priority",&iPriority)) {
DEBUGLOG(("FindPoolPspDetail psp_priority = [%d]\n",iPriority));
			}
			if (GetField_Double(hRec,"req_amt",&dReqAmt)) {
DEBUGLOG(("FindPoolPspDetail Requested Amt = [%lf]\n",dReqAmt));
			}
			if (GetField_Int(hRec,"rej_delta_amt",&iRejSmallDelta)) {
DEBUGLOG(("FindPoolPspDetail Rej Small Delta = [%d]\n",iRejSmallDelta));
			}
			

			//check pid support small delta
			GetField_Double(hIn,"psp_amt",&dTxnAmt);
			if(iRejSmallDelta && dTxnAmt > 100.0){
				char*   csValueTmp;
				csValueTmp = (char*) malloc (128);

				double dDeltaAmtUp = 12.0;
				double delta_amt = abs(dTxnAmt - round(dTxnAmt / 100.0) * 100); 

				DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
				if ((unsigned long)(DBObjPtr)(PD_DELTA_AMT_UP,csValueTmp) == FOUND) {
					sscanf(csValueTmp, "%lf",&dDeltaAmtUp);
				}

DEBUGLOG(("Check Psp:Transaction delta amount [%lf] with delta amount (up) [%lf]\n",delta_amt,dDeltaAmtUp));
				if(delta_amt >= dDeltaAmtUp){
					iChk = PD_OK;
				}

				FREE_ME(csValueTmp);
			}
			else{
				iChk = PD_OK;
			}


			//check pid with outage
			if(iChk == PD_OK){
				GetField_CString(hIn,"channel_code",&csChannel); 
				GetField_CString(hIn,"bank_code",&csBank); 
				DBObjPtr = CreateObj(DBPtr,"DBRuleDisabledBank","CheckCurrDisableByPsp");
				if ((unsigned long)(DBObjPtr)(csChannel,csPspId,csBank,PD_TRUE,hIn)==PD_TRUE){
					iChk = PD_ERR;
DEBUGLOG(("Check Psp::Bank[%s] of PID[%s] is in outage period\n",csBank,csPspId));
				}
				else{
DEBUGLOG(("Check Psp::Bank[%s] of PID[%s] is available\n",csBank,csPspId));
				}
			}


			//check pid group
			if(iChk == PD_OK){
				GetField_CString(hIn,"service_code",&csServiceCode);
				DBObjPtr = CreateObj(DBPtr,"DBPidBankGroupMapping","CheckPidGroup");
                                if ((unsigned long)(DBObjPtr)(csPspId,csServiceCode)==PD_OK){
DEBUGLOG(("Check Psp::PID GROUP of PID[%s] is valid or skip checking\n",csPspId));
                                }
                                else{
                              		iChk = PD_ERR;
DEBUGLOG(("Check Psp::PID GROUP of PID[%s] is invalid\n",csPspId));
                                }
			}

			
			//check psp restrict ip region
			if(iChk == PD_OK){				
				GetField_CString(hIn,"ip_addr",&csIpAddr);
DEBUGLOG(("Check Psp::ip_addr = [%s]\n",csIpAddr));
				char *p;
				char csTmpIp[PD_IP_LEN + 1];
				p = strtok (csIpAddr, ",");
				while (p != NULL) {
					strcpy(csTmpIp, p);
					csTmpIp[strlen(p)]='\0';
					break;
				}
				sprintf(csIpAddr, "%s", csTmpIp);
DEBUGLOG(("Check Psp::ip_addr = [%s]\n",csIpAddr));

				BOObjPtr = CreateObj(BOPtr,"BOIpRegion","IsSupportPspIp");
                                if ((unsigned long)(BOObjPtr)(csPspId,csIpAddr)==PD_OK){
DEBUGLOG(("Check Psp::IP Region[%s] of PID[%s] is supported or skip checking\n",csIpAddr,csPspId));
                                }
                                else{
                                        iChk = PD_ERR;
DEBUGLOG(("Check Psp::IP Region[%s] of PID[%s] is not supported\n",csIpAddr,csPspId));
                                }
			}


			//check psp with customer transaction threshold
			if(iChk == PD_OK){
				GetField_CString(hIn,"from_txn_seq",&csOrgTxnSeq);
				PutField_Int(hTmp, "get_txn_header", PD_TRUE);
				PutField_Int(hTmp, "get_txn_detail", PD_TRUE);
				PutField_Int(hTmp, "get_txn_psp_detail", PD_FALSE);
				PutField_CString(hTmp, "txn_seq", csOrgTxnSeq);
				BOObjPtr = CreateObj(BOPtr, "BOTransaction", "GetTxnInfo");
				if ((BOObjPtr)(hTmp,hTxnInfo) == PD_OK){
					if (GetField_CString(hTxnInfo, "customer_tag", &csCustTag)){
DEBUGLOG(("FindPoolPspDetail:: customer_tag = [%s]\n", csCustTag));
					}

					if (GetField_CString(hTxnInfo, "merchant_id", &csOrgMerchantId)){
DEBUGLOG(("FindPoolPspDetail:: merchant_id = [%s]\n", csOrgMerchantId));
					}
					else{
DEBUGLOG(("FindPoolPspDetail:: merchant_id not found!!\n"));
ERRLOG("BOTxnLb::FindPoolPspDetail::BOTransaction.GetTxnInfo() merchant_id is missing\n");
						iChk = PD_ERR;
					}

					if(iChk == PD_OK){
						if(csCustTag != NULL){
							DBObjPtr = CreateObj(DBPtr,"DBCustomerGroupDetail","FindGroup");
							if ((unsigned long)(DBObjPtr)(csOrgMerchantId,csCustTag,&csCustomerGroup) == FOUND) {
DEBUGLOG(("FindPoolPspDetail:: call CustomerGroupDetail::FindGroup merchant_id[%s] cust_id[%s] Found!!\n", csOrgMerchantId, csCustTag));
								DBObjPtr = CreateObj(DBPtr,"DBCustomerPspCounters","ChkCustomerPspCounters");
								if ((unsigned long)(DBObjPtr)(csPspId, csCustTag) == PD_OK){
DEBUGLOG(("Check Psp::Customer tag[%s] of PID[%s] txn counter is within txn threshold\n",csCustTag,csPspId));
								}
								else{
DEBUGLOG(("Check Psp::Customer tag[%s] of PID[%s] txn counter is over txn threshold\n",csCustTag,csPspId));
									iChk = PD_ERR;
								}
							}
						}
					}
				}
				else{
DEBUGLOG(("FindPoolPspDetail::BOTransaction.GetTxnInfo() error\n"));
ERRLOG("BOTxnLb::FindPoolPspDetail::BOTransaction.GetTxnInfo() error\n");
					iChk = PD_ERR;
				}
			}



			if(iChk == PD_OK){

				sprintf(csTag,"total_vol_for_p%d",iPriority);
				dTmp = 0.0;
				GetField_Double(hOut,csTag,&dTmp);
				PutField_Double(hOut,csTag,dTmp+dReqAmt);

				sprintf(csTag,"total_ratio_for_p%d",iPriority);
				iTmp = 0;
				GetField_Int(hOut,csTag,&iTmp);
				PutField_Int(hOut,csTag,iTmp+iRatio);

				sprintf(csTag,"prev_priority");
				GetField_Int(hOut,csTag,&iPrevPriority);
				if(iPrevPriority == iPriority){
					iTmp = 0;
					sprintf(csTag,"priority_%d_cnt",iPriority);
					GetField_Int(hOut,csTag,&iTmp);
					iPriCnt = iTmp + 1;
					PutField_Int(hOut,csTag,iPriCnt);
DEBUGLOG(("psp id [%s] is the [%d]th in Priority[%d]\n",csPspId,iPriCnt,iPriority));
				}
				else{
					iTmp = 0;
					GetField_Int(hOut,"num_of_priority",&iTmp);
					PutField_Int(hOut,"num_of_priority",iTmp+1);
					sprintf(csTag,"priority_%d",iTmp);
					PutField_Int(hOut,csTag,iPriority);
DEBUGLOG(("Number of Priority is now[%d]\n",iTmp+1));

					iTmp = 0;
					sprintf(csTag,"priority_%d_cnt",iPriority);
					GetField_Int(hOut,csTag,&iTmp);
					iPriCnt = iTmp + 1;
					PutField_Int(hOut,csTag,iPriCnt);
DEBUGLOG(("psp id [%s] is the [%d]th in Priority[%d]\n",csPspId,iPriCnt,iPriority));

					sprintf(csTag,"prev_priority");
					PutField_Int(hOut,csTag,iPriority);

				}

				sprintf(csTag,"%d_psp_id_%d",iPriority,iPriCnt-1);
				PutField_CString(hOut,csTag,csPspId);

				sprintf(csTag,"%d_ratio_%d",iPriority,iPriCnt-1);
				PutField_Int(hOut,csTag,iRatio);

				sprintf(csTag,"%d_req_amt_%d",iPriority,iPriCnt-1);
				PutField_Double(hOut,csTag,dReqAmt);
			}


			hRec = RecordSet_GetNext(rRecordSet);
		}


	}
	else{
		iRet = PD_ERR;
	}


	hash_destroy(hTmp);
	FREE_ME(hTmp);
	hash_destroy(hTxnInfo);
	FREE_ME(hTxnInfo);

	RecordSet_Destroy(rRecordSet);
       	FREE_ME(rRecordSet);
DEBUGLOG(("FindPoolPspDetail exit iRet = [%d]\n",iRet));
	return iRet;
}
