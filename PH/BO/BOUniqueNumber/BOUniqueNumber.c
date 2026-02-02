/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/09/24              LokMan Chow

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
#include "BOUniqueNumber.h"
#include <math.h>
#include <time.h>
#include <sys/time.h>

char cDebug;

double GenerateUniqueNumber(const double dAmt,
			    hash_t* hTxn);

void BOUniqueNumber(char cdebug)
{
	cDebug = cdebug;
}

OBJPTR(DB);
OBJPTR(BO);

int GetUniqueAmt(hash_t *hContext,
		const hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iRule = PD_NOT_FOUND;
	int	iDecimal = 0;
	double	dUniqueAmt = 0.0;
	double	dAmt = 0.0;
	char*	csTmp;
	char*	csTxnCcy;
	//char*	csBankCode;
	//char*	csBankAcctNum;
	char*	csTxnCode;
	char*	csChannel;
	char	csPartyType[PD_OFL_PARTY_LEN+1];
	char*	csPartyId;
	char	cGroup;
	int	iApplyMerchUniqueNum = PD_FALSE;
	int	iApplyPspUniqueNum = PD_FALSE;
	char	csTag[PD_TAG_LEN+1];

	hash_t*	hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);

	if(GetField_CString(hContext,"org_channel_code",&csChannel)){
		PutField_CString(hTxn,"channel_code",csChannel);
DEBUGLOG(("GetUniqueAmt: channel_code = [%s]\n",csChannel));
	}
	else{
		if(GetField_CString(hContext,"channel_code",&csChannel)){
			PutField_CString(hTxn,"channel_code",csChannel);
DEBUGLOG(("GetUniqueAmt: channel_code = [%s]\n",csChannel));
		}
		else{
			iRet = INT_ERR;
DEBUGLOG(("GetUniqueAmt: channel_code not found\n"));
		}
	}

	if(GetField_CString(hContext,"org_txn_code",&csTxnCode)){
		PutField_CString(hTxn,"txn_code",csTxnCode);
DEBUGLOG(("GetUniqueAmt: txn_code = [%s]\n",csTxnCode));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetUniqueAmt: txn_code not found\n"));
	}

	if(GetField_Double(hContext,"org_txn_amt",&dAmt)){
DEBUGLOG(("GetUniqueAmt: txn_amt = [%lf]\n",dAmt));
	}
	else{
DEBUGLOG(("GetUniqueAmt: txn amt not found\n"));
	}

	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBChannelTxnMap","IsApplyUniqueNum");
		if((unsigned long)(*DBObjPtr)(csChannel,csTxnCode,&iApplyMerchUniqueNum,&iApplyPspUniqueNum)!=PD_OK){
DEBUGLOG(("GetUniqueAmt: DBChannelTxnMap:IsApplyUniqueNum Failed!!!!!\n"));
		}
	}

	if(!iApplyMerchUniqueNum && !iApplyPspUniqueNum){
		dUniqueAmt = dAmt;
	}
	else{
		if(iApplyMerchUniqueNum){
			cGroup = PD_TYPE_MERCHANT;
			sprintf(csTag,"merchant_id");
			sprintf(csPartyType,PD_OFL_PARTY_MERCHANT);
		}
		else{
			cGroup = PD_TYPE_PSP;
			sprintf(csTag,"baid");
			sprintf(csPartyType,PD_OFL_PARTY_BAID);
		}

		PutField_Char(hTxn,"group",cGroup);
		if(GetField_CString(hContext,csTag,&csPartyId)){
			PutField_CString(hTxn,csTag,csPartyId);
DEBUGLOG(("GetUniqueAmt: [%s] = [%s]\n",csTag,csPartyId));
		}
		else{
DEBUGLOG(("GetUniqueAmt: [%s] not found\n",csTag));
		}

		if(!strcmp(csTxnCode,PD_OFFSYS_PAYOUT_GEN_TXN_CODE)){
			if(GetField_CString(hContext,"baid",&csTmp)){
				PutField_CString(hTxn,"payout_baid",csTmp);
			}
		}

		if(GetField_CString(hContext,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("GetUniqueAmt: txn_ccy = [%s]\n",csTxnCcy));
			DBObjPtr = CreateObj(DBPtr,"DBCurrency","IsSupportDecimal");
			if ((unsigned long)((DBObjPtr)(csTxnCcy))==PD_TRUE){
DEBUGLOG(("GetUniqueAmt: [%s] support decimal\n",csTxnCcy));
				iDecimal = PD_DECIMAL_LEN;
			}
	
		}
		else{
DEBUGLOG(("GetUniqueAmt: txn ccy not found\n"));
		}
	
		PutField_Int(hTxn,"decimal",iDecimal);

		DBObjPtr = CreateObj(DBPtr,"DBOLRuleUniqueNumber","GetOLRuleUniqueNumber");
		iRule = (unsigned long)(*DBObjPtr)(csTxnCode,csPartyType,csPartyId,hTxn);
		if(iRule == PD_ERR){
			iRet = INT_ERR;
DEBUGLOG(("GetUniqueAmt: GetOLRuleUniqueNumber Failed!!!!!\n"));
		}
		else if(iRule == PD_FOUND){
			dUniqueAmt = GenerateUniqueNumber(dAmt,hTxn);
		}
		else if(iRule == PD_NOT_FOUND){
			dUniqueAmt = dAmt;
DEBUGLOG(("GetUniqueAmt: GetOLRuleUniqueNumber No Rule Found, Use Original Amount\n"));
		}
	}

	if(iRet==PD_OK && dUniqueAmt>0.0){
		PutField_Double(hResponse,"display_amt",dUniqueAmt);
DEBUGLOG(("GetUniqueAmt: final unique amount= [%lf]\n",dUniqueAmt));
	}

	if(dUniqueAmt<=0.0){
		iRet = INT_ERR;
DEBUGLOG(("GetUniqueAmt: GetOLRuleUniqueNumber Failed!!!!!\n"));
	}

	FREE_ME(hTxn);
DEBUGLOG(("GetUniqueAmt: exit [%d]\n",iRet));
	return iRet;
}

double GenerateUniqueNumber(const double dAmt,
			    hash_t* hTxn)
{
	double	dGenerate = 0.0;
	double	dRangeEnd = 0.0;
	double	dStepSize = 0.0;
	double	dFromAmt = 0.0;
	double	dToAmt = 0.0;
	double	dExtendAmt = 0.0;
	double	dMaxRangeAmt = 0.0;
	char	cAutoExtend = PD_NO;
	char	cDirection = PD_OPR_DIR_PLUS;
	char	cGroup;
	int	iTimeInterval = 0;
	int	iDecimal = 0;
	int	iMaxAmountCnt = PD_TMP_BUF_LEN*8; //max 256*8 amount //can do tuning
	int	iMaxRandomCnt = PD_TMP_BUF_LEN*8; //max 256*8 amount //can do tuning
	double  dAmountList[iMaxAmountCnt];
	double  dRemainList[iMaxRandomCnt];
	double	dCheckAmt = 0.0;
	double	dHaveAmt = 0.0;
	int	iTmpCnt = 0;
	int	iAmtCnt = 0;
	double	dSkipFrom = 0.0;
	double	dSkipTo = 0.0;
	int	iLoop = PD_TRUE;
	int i = 0;
	int j = 0;
	int iRandIndex = 0;
	char*	csTxnCode;
	char*	csTmp;
	double	dOrgFromAmt=0.0;
	double	dOrgToAmt=0.0;
	double	dOrgExtendAmt=0.0;
	int	iRangeCount = 0;

	hash_t  *hRec;
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));

	if(GetField_CString(hTxn,"txn_code",&csTxnCode)){
DEBUGLOG(("GenerateUniqueNumber: txn_code = [%s]\n",csTxnCode));
	}

	if(GetField_CString(hTxn,"selected_party_type",&csTmp)){
DEBUGLOG(("GenerateUniqueNumber: selected_party_type = [%s]\n",csTmp));
	}

	if(GetField_CString(hTxn,"client_id",&csTmp)){
DEBUGLOG(("GenerateUniqueNumber: client_id = [%s]\n",csTmp));
	}

	if(GetField_CString(hTxn,"provider",&csTmp)){
DEBUGLOG(("GenerateUniqueNumber: provider = [%s]\n",csTmp));
	}

	if(GetField_Char(hTxn,"group",&cGroup)){
DEBUGLOG(("GenerateUniqueNumber: group = [%c]\n",cGroup));
	}
	if(GetField_Double(hTxn,"range_end",&dRangeEnd)){
DEBUGLOG(("GenerateUniqueNumber: range_end = [%lf]\n",dRangeEnd));
	}

	if(GetField_Double(hTxn,"step_size",&dStepSize)){
DEBUGLOG(("GenerateUniqueNumber: step_size = [%lf]\n",dStepSize));
	}

	if(GetField_Char(hTxn,"direction",&cDirection)){
DEBUGLOG(("GenerateUniqueNumber: operate direction = [%c]\n",cDirection));
	}
	
	if(GetField_Char(hTxn,"auto_extend",&cAutoExtend)){
DEBUGLOG(("GenerateUniqueNumber: auto_extend = [%c]\n",cAutoExtend));
	}

	if(GetField_Double(hTxn,"extend_amount",&dExtendAmt)){
DEBUGLOG(("GenerateUniqueNumber: extend_amount = [%lf]\n",dExtendAmt));
	}

	if(GetField_Double(hTxn,"max_range_amount",&dMaxRangeAmt)){
DEBUGLOG(("GenerateUniqueNumber: max_range_amount = [%lf]\n",dMaxRangeAmt));
	}


	if(GetField_Int(hTxn,"check_interval",&iTimeInterval)){
DEBUGLOG(("GenerateUniqueNumber: check_interval = [%d]\n",iTimeInterval));
	}

	if(GetField_Int(hTxn,"decimal",&iDecimal)){
DEBUGLOG(("GenerateUniqueNumber: decimal = [%d]\n",iDecimal));
	}

	//Initialize
	dOrgFromAmt = dAmt;
	dOrgToAmt = dAmt;
	dOrgExtendAmt = dRangeEnd + dStepSize;

	while(iLoop){
		if(cDirection == PD_OPR_DIR_PLUS){//Direction = '+'
			dFromAmt = newround(dOrgToAmt+dStepSize,iDecimal);
			dToAmt = newround(dOrgToAmt+dOrgExtendAmt,iDecimal);

		}
		else if(cDirection == PD_OPR_DIR_MINUS){//Direction = '-'
			dFromAmt = newround(dOrgFromAmt-dOrgExtendAmt,iDecimal);
			dToAmt = newround(dOrgFromAmt-dStepSize,iDecimal);
			if(dFromAmt<=0.0 || dToAmt<=0.0){
				//If either one of the boundary less than zero, use the '+' diretion instead
				//Logic can be change if necessary
				dFromAmt = newround(dOrgToAmt+dStepSize,iDecimal);
				dToAmt = newround(dOrgToAmt+dOrgExtendAmt,iDecimal);
			}
		}
		else{//Direction = 'B'
			dFromAmt = newround(dOrgFromAmt-dOrgExtendAmt,iDecimal);
			dToAmt = newround(dOrgToAmt+dOrgExtendAmt,iDecimal);
			if(dFromAmt<=0.0){
				//If the lower boundary less than zero, use the '+' diretion instead
				//Logic can be change if necessary
				dFromAmt = newround(dOrgToAmt+dStepSize,iDecimal);
			}
		}

		iTmpCnt = 0;
		iRangeCount = 0;
		for(dCheckAmt=dFromAmt; dCheckAmt<=dToAmt; dCheckAmt=newround(dCheckAmt+dStepSize,iDecimal)){
			long    lTmp;
			lTmp = (long) dCheckAmt;
			if(!((dCheckAmt>=dSkipFrom)&&(dCheckAmt<=dSkipTo))){
				if (dCheckAmt > lTmp) {//skip the amount without decimal places
					dAmountList[iTmpCnt] = dCheckAmt;
					iTmpCnt++;
				}
			}
			if (dCheckAmt > lTmp) {//skip the amount without decimal places
				iRangeCount ++;
			}
			if(iTmpCnt>=iMaxAmountCnt)
				break;
		}

		PutField_Double(hTxn,"from_amt",dFromAmt);
		PutField_Double(hTxn,"to_amt",dToAmt);
	
DEBUGLOG(("GenerateUniqueNumber: From Amount [%lf] <-> To Amount [%lf]. Total=[%d]. Can Use [%d] \n",dFromAmt,dToAmt,iRangeCount,iTmpCnt));

		iAmtCnt = 0;

		if(cGroup==PD_TYPE_PSP || !strcmp(csTxnCode,PD_OFFSYS_PAYOUT_GEN_TXN_CODE)){
			if(GetField_CString(hTxn,"payout_baid",&csTmp)){
				PutField_CString(hTxn,"baid",csTmp);
			}
			DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","CheckPspUniqueAmt");
		}
		else{
			DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","CheckUniqueAmt");
		}
		recordset_init(rRecordSet,0);
		if ((*DBObjPtr)(hTxn,rRecordSet) == PD_OK) {
			GetField_Int(hTxn,"count",&iAmtCnt);
DEBUGLOG(("GenerateUniqueNumber: Number of Amount Used = [%d]\n",iAmtCnt));

			if(iRangeCount<=iAmtCnt){
				//if(cAutoExtend==PD_YES && iExtend<iMaxExtend){
				if(cAutoExtend==PD_YES && (abs(dToAmt+dExtendAmt)<(dToAmt+dMaxRangeAmt)  && dMaxRangeAmt>0.0)){
					dSkipFrom = dFromAmt;
					dSkipTo = dToAmt;

					dOrgFromAmt = dFromAmt;
					dOrgToAmt = dToAmt;
					dOrgExtendAmt = dExtendAmt;
DEBUGLOG(("GenerateUniqueNumber: Extend the range amount now. org from_to[%f,%f], org_ext_amt[%f]\n",dOrgFromAmt,dOrgToAmt,dOrgExtendAmt));
				}
				else{
DEBUGLOG(("GenerateUniqueNumber: Find the most oldest amount within [%d] hours\n",iTimeInterval));
					if(cGroup==PD_TYPE_PSP || !strcmp(csTxnCode,PD_OFFSYS_PAYOUT_GEN_TXN_CODE)){
						DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","FindOldestPspUniqueAmt");
					}
					else{
						DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","FindOldestUniqueAmt");
					}
					if ((*DBObjPtr)(hTxn) == PD_OK){
						if(GetField_Double(hTxn,"oldest_amt",&dGenerate)){
DEBUGLOG(("GenerateUniqueNumber: The most oldest amount = [%lf]\n",dGenerate));
						}
					}
					iLoop = PD_FALSE;
				}
			}
			else{
DEBUGLOG(("GenerateUniqueNumber: get the avaliable amount\n"));
				i = 0;
				j = 0;
				iRandIndex = 0;
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec && (i<iTmpCnt) && (j<iMaxRandomCnt)) {
					if (GetField_Double(hRec,"have_amt",&dHaveAmt)){
						while((dAmountList[i]<dHaveAmt) && (i<iTmpCnt) && (j<iMaxRandomCnt)){
							dRemainList[j] = dAmountList[i];
							i++;
							j++;
						}
						if(dAmountList[i]==dHaveAmt){
							i++;
						}
					}

					hRec = RecordSet_GetNext(rRecordSet);
				}
DEBUGLOG(("GenerateUniqueNumber: Check point\n"));
				while((i<iTmpCnt)  && (j<iMaxRandomCnt)){
					dRemainList[j] = dAmountList[i];
					i++;
					j++;
				}
DEBUGLOG(("GenerateUniqueNumber: Random choose one amount from [%d] available amount\n",j));

				struct timeval  tv;
				gettimeofday(&tv, NULL);

				unsigned int time_msec = (tv.tv_sec)*1000 + (tv.tv_usec)/1000;
				srand(time_msec);

				iRandIndex = (int) ((double)j*rand()/(RAND_MAX+1.0));
DEBUGLOG(("GenerateUniqueNumber: iRandIndex = [%d]\n",iRandIndex));
				dGenerate = dRemainList[iRandIndex];
DEBUGLOG(("GenerateUniqueNumber: Use the [%d]th one: generated number = [%lf]\n",iRandIndex+1,dGenerate));
				iLoop = PD_FALSE;
			}
		}
		else{
			iLoop = PD_FALSE;
		}
	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
DEBUGLOG(("GenerateUniqueNumber: Exit\n"));
	return dGenerate;
}

