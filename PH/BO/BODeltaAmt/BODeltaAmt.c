/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/03/19              David Wong
Add FilterAvailablePsp				   2013/04/11		   LokMan Chow

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
#include "BODeltaAmt.h"
#include <math.h>

char cDebug;

void BODeltaAmt(char cdebug)
{
	cDebug = cdebug;
}

OBJPTR(DB);
OBJPTR(BO);

int GetMerchantSupportDeltaAmt(const char *csMerchantID,
				const char *csCountry,
				const char *csCcy,
				const char *csServiceCode)
{
	int iRet = PD_FALSE;
	int iTmp;

	hash_t *hRec;
	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec,0);

	DBObjPtr = CreateObj(DBPtr,"DBMerchantBalAcct","CheckMerchantBalAcct");
	if ((unsigned long)((*DBObjPtr)(csMerchantID,
					csCountry,
					csCcy,
					csServiceCode,
					hRec)) == PD_FOUND) {
		if (GetField_Int(hRec,"support_delta_amt",&iTmp)) {
DEBUGLOG(("GetMerchantSupportDeltaAmt:CheckMerchantBalAcct support_delta_amt = [%d]\n",iTmp));
			if (iTmp == 1) {
				iRet = PD_TRUE;
			}
		}
		else {
DEBUGLOG(("GetMerchantSupportDeltaAmt:CheckMerchantBalAcct support_delta_amt not found!\n"));
ERRLOG("BODeltaAmt:GetMerchantSupportDeltaAmt:CheckMerchantBalAcct support_delta_amt not found!\n");
		}
	}
	else {
DEBUGLOG(("GetMerchantSupportDeltaAmt:CheckMerchantBalAcct not found!\n"));
ERRLOG("BODeltaAmt:GetMerchantSupportDeltaAmt:CheckMerchantBalAcct not found!\n");
	}

	FREE_ME(hRec);

	return iRet;
}


int FilterAvailablePsp( const hash_t *hContext,
			const hash_t *hInList,
			hash_t *hOutList,
			double dTxnAmt)
{
	int	iRet = PD_OK;
	int	iRemove;
	char*	csPspId;
	char	csTag[PD_TAG_LEN+1];
	double	delta_amt = 0.0;
	double	dDeltaAmtLow = 0.0;
	double	dDeltaAmtUp = 0.0;
	int	iPspCnt = 0;
	int	iTmp = 0;
	int	i = 0;
	int	iCnt = 0;

	delta_amt = abs(dTxnAmt - round(dTxnAmt / 100.0) * 100);

	if(GetField_Int(hInList,"psp_id_cnt",&iPspCnt)){
DEBUGLOG(("FilterAvailablePsp: psp id cnt = [%d]\n",iPspCnt));
	}

	if(!GetField_Double(hContext,"delta_amt_low",&dDeltaAmtLow))
		dDeltaAmtLow = PD_DELTA_AMT_BOUNDARY_1;
DEBUGLOG(("FilterAvailablePsp:  delta amount range (low) = [%lf]\n", dDeltaAmtLow));

	if(!GetField_Double(hContext,"delta_amt_up",&dDeltaAmtUp))
		dDeltaAmtUp = PD_DELTA_AMT_BOUNDARY_2;
DEBUGLOG(("FilterAvailablePsp:  delta amount range (up) = [%lf]\n", dDeltaAmtUp));


	for(i = 0; i< iPspCnt; i++){
		sprintf(csTag,"psp_id_%d",i);
		if(GetField_CString(hInList,csTag,&csPspId)){
DEBUGLOG(("FilterAvailablePsp: Check [%03d][%s]\n",i,csPspId));
			hash_t *myHash;
			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);
			iRemove = PD_FALSE;

			DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
			if ((unsigned long)((*DBObjPtr)(csPspId,myHash)) != PD_OK) {
DEBUGLOG(("FilterAvailablePsp:GetPspDetail for [%s] not found!\n",csPspId));
				iRemove = PD_TRUE;
			}
			else {
				if (dTxnAmt >= 100 &&
				    //delta_amt >= dDeltaAmtLow &&
				    delta_amt < dDeltaAmtUp){
					if (GetField_Int(myHash,"rej_small_delta_amt",&iTmp)) {
						if (iTmp == PD_TRUE) {
DEBUGLOG(("FilterAvailablePsp:  [%s] reject small delta amount [%lf]\n",csPspId,delta_amt));
							iRemove = PD_TRUE;
						}
					}
				}
			}

			if (iRemove == PD_FALSE){
				sprintf(csTag,"psp_id_%d",iCnt);
				PutField_CString(hOutList,csTag,csPspId);
				iCnt ++;
				PutField_Int(hOutList,"psp_id_cnt",iCnt);
//DEBUGLOG(("FilterAvailablePsp: available psp [%s]\n",csPspId));
			}	

			FREE_ME(myHash);
		}
	}

DEBUGLOG(("FilterAvailablePsp: exit [%d]\n",iRet));
	return iRet;
}


/*
int GetAvailablePspByBank(const char *csBank,
		const char *csCountry,
		const char *csDateTime,
		double dTxnAmt,
		const char *csIpAddr,
		hash_t *hResponse)
{
	int	iRet = PD_OK;
	int	iRemove;
	int	iSchedulerId;
	int	iTmp;
	char*	csPspId;
	char*	csPtr;
	char	cTmp;
	double	delta_amt = 0.0;

	hash_t *hRec, *hDis;
	recordset_t *rRecordSet, *rDisabledSet;;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

	rDisabledSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rDisabledSet,0);

	delta_amt = abs(dTxnAmt - round(dTxnAmt / 100.0) * 100);

	if ((dTxnAmt >= 100) && (delta_amt < PD_DELTA_AMT_BOUNDARY_1)) {
		iRet = INT_ERR;
DEBUGLOG(("GetAvailablePspByBank - delta amount [%lf] too small!\n",delta_amt));
ERRLOG("BODeltaAmt:GetAvailablePspByBank - delta amount [%lf] too small!\n",delta_amt);
	}
	else {
		if (iRet == PD_OK) {
			DBObjPtr = CreateObj(DBPtr,"DBRuleDisabledBank","DisabledBankInfo");
			if ((unsigned long)(*DBObjPtr)(csBank,PD_TYPE_PSP,rDisabledSet) != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("GetAvailablePspByBank:DisabledBankInfo [%s] failed!\n",csBank));
ERRLOG("BODeltaAmt:GetAvailablePspByBank:DisabledBankInfo [%s] failed!\n",csBank);
			}
			else {
				hDis = RecordSet_GetFirst(rDisabledSet);
				while (hDis) {
					iRet = PD_OK;
					if (GetField_Int(hDis,"scheduler_id",&iSchedulerId)) {
DEBUGLOG(("GetAvailablePspByBank:DisabledBankInfo - scheduler_id = [%d]\n",iSchedulerId));
					}
					if (GetField_Char(hDis,"party_type",&cTmp)) {
DEBUGLOG(("GetAvailablePspByBank:DisabledBankInfo - party_type = [%c]\n",cTmp));
					}
					if (GetField_CString(hDis,"party_id",&csPtr)) {
DEBUGLOG(("GetAvailablePspByBank:DisabledBankInfo - party_id = [%s]\n",csPtr));
					}
					if (GetField_CString(hDis,"channel_code",&csPtr)) {
DEBUGLOG(("GetAvailablePspByBank:DisabledBankInfo - channel_code = [%s]\n",csPtr));
					}
					BOObjPtr = CreateObj(BOPtr,"BOTxnLb","CheckScheduler");
					if ((unsigned long)(*BOObjPtr)(iSchedulerId,csDateTime) != PD_OK) {
						RemoveField_CString(hDis,"party_id");
DEBUGLOG(("GetAvailablePspByBank:CheckScheduler scheduler_id [%d] not in the disabled period!\n",iSchedulerId));
					}
					hDis = RecordSet_GetNext(rDisabledSet);
				}
			}
		}

		if (iRet == PD_OK) {
			DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetDepositPspList");
			if ((unsigned long)((*DBObjPtr)(csCountry,csBank,rRecordSet)) != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("GetAvailablePspByBank:GetDepositPspList not found!\n"));
ERRLOG("BODeltaAmt:GetAvailablePspByBank:GetDepositPspList not found!\n");
			}
			else {
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if (GetField_CString(hRec,"psp_id",&csPspId)) {
						hash_t *myHash;
						myHash = (hash_t*) malloc (sizeof(hash_t));
						hash_init(myHash,0);
						iRemove = PD_FALSE;

						DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
						if ((unsigned long)((*DBObjPtr)(csPspId,myHash)) != PD_OK) {
DEBUGLOG(("GetAvailablePspByBank:GetPspDetail for [%s] not found!\n",csPspId));
							iRemove = PD_TRUE;
						}
						else {
							if (dTxnAmt >= 100) {
								// Assume support_delta_amt = 1
								if (GetField_Int(myHash,"support_delta_amt",&iTmp)) {
									if (iTmp == PD_FALSE) {
										iRemove = PD_TRUE;
									}
								}

								if (iRemove == PD_FALSE) {
									// Assume not special land location
									DBObjPtr = CreateObj(DBPtr,"DBIpFilter","GetIpFilter");
									if ((unsigned long)((*DBObjPtr)(csIpAddr)) == PD_FOUND) {
										if (delta_amt <= PD_DELTA_AMT_BOUNDARY_2) {
											DBObjPtr = CreateObj(DBPtr,"PspSmallAmt","GetAlternative");
											if ((unsigned long)((*DBObjPtr)(csPspId)) != PD_TRUE)
												iRemove = PD_TRUE;
										}
										else {
											DBObjPtr = CreateObj(DBPtr,"PspSmallAmt","GetAlternative");
											if ((unsigned long)((*DBObjPtr)(csPspId)) == PD_TRUE)
												iRemove = PD_TRUE;
										}
									} else {
										// Assume rej_small_delta_amt = 0
										if ((delta_amt >= PD_DELTA_AMT_BOUNDARY_1) && (delta_amt <= PD_DELTA_AMT_BOUNDARY_2)) {
											if (GetField_Int(myHash,"rej_small_delta_amt",&iTmp)) {
												if (iTmp == PD_TRUE) {
													iRemove = PD_TRUE;
												}
											}
										}
									}
								}
							}
						}

						if (iRemove == PD_TRUE)
							RemoveField_CString(hRec,"psp_id");

						FREE_ME(myHash);
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
		}
	}

	if (iRet == PD_OK) {
		hDis = RecordSet_GetFirst(rDisabledSet);
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec && (iRet==PD_OK)) {
			if (GetField_CString(hRec,"psp_id",&csPspId)) {
				while (hDis && (iRet==PD_OK)) {
					if (GetField_CString(hDis,"party_id",&csPtr)) {
						if (strcmp(csPspId,csPtr) < 0) {
							break;
						}
						else if (strcmp(csPspId,csPtr) == 0) {
							RemoveField_CString(hRec,"psp_id");
							hDis = RecordSet_GetNext(rDisabledSet);
							break;
						}
						else {
							hDis = RecordSet_GetNext(rDisabledSet);
						}

						if (hDis == NULL)
							iRet = PD_SKIP_OK;
					}
					else
						hDis = RecordSet_GetNext(rDisabledSet);
				}
			}
			hRec = RecordSet_GetNext(rRecordSet);
		}
	}

	if (iRet == PD_SKIP_OK)
		iRet = PD_OK;

	if (iRet == PD_OK) {
		char	csTag[PD_TAG_LEN+1];
		int	i = 0;
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			if (GetField_CString(hRec,"psp_id",&csPtr)) {
				sprintf(csTag,"psp_id_%d",i);
				PutField_CString(hResponse,csTag,csPtr);
DEBUGLOG(("GetAvailablePspByBank - [%s] = [%s]\n",csTag,csPtr));
				i++;
			}
			hRec = RecordSet_GetNext(rRecordSet);
		}
		PutField_Int(hResponse,"psp_id_cnt",i);
	}

	RecordSet_Destroy(rDisabledSet);
	FREE_ME(rDisabledSet);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

	return iRet;
}
*/
