/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/10/03              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsPOG.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


char cDebug;
OBJPTR(DB);
OBJPTR(BO);


void TxnMgtByUsPOG(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csPreviewId;
        char    *csUser;
        char    *csReportDate;
        char    *csMerchantId;
        char    *csPayoutCcy;
        char    *csPspId;
        char    *csPspCountry;
	int	iOnlinePayout = PD_FALSE;
	char    csCmd[PD_TMP_BUF_LEN*2+1];
	int	iGenId = 0;
	double	dAmt = 0.0;
	int	iTmp = 0;

	hash_t  *hRec, *hBal;
	hBal= (hash_t*) malloc (sizeof(hash_t));
        hash_init(hBal,0);
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

DEBUGLOG(("Authorize\n"));

        if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));

		DBObjPtr = CreateObj(DBPtr,"DBRulePayoutOnlineMode","ChkRuleExistsByMerchant");
		if ((unsigned long)(DBObjPtr)(csMerchantId) == PD_FOUND){
			//PutField_Int(hContext,"online_payout",PD_TRUE);
			iOnlinePayout = PD_TRUE;
		}
        }

        if(GetField_CString(hRequest,"preview_id",&csPreviewId)){
		iGenId = atoi(csPreviewId);
DEBUGLOG(("Authorize::preview_id= [%s]\n",csPreviewId));
        }
	else{
		iRet = INT_ERR;
DEBUGLOG(("Authorize::preview_id is missing!!!!!!!!\n"));
ERRLOG("Authorize::preview_id is missing!!!!!!!!\n");
	}

        if(GetField_CString(hRequest,"report_date",&csReportDate)){
DEBUGLOG(("Authorize::report_date= [%s]\n",csReportDate));
        }

        if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
        }

	if(iRet==PD_OK){
		recordset_init(rRecordSet,0);
                if(!iOnlinePayout)
                        DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedTmp","GetExistingPsp");
                else
                        DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedTmp","GetExistingPspOnlineMode");
DEBUGLOG(("Authorize::Call DBPayoutGeneratedTmp:GetExistingPsp\n"));
                if((unsigned long) ((*DBObjPtr)(iGenId,rRecordSet))==PD_OK){
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while(hRec){
                                hash_init(hBal,0);
                                if(GetField_CString(hRec,"psp_id",&csPspId)){
                                        PutField_CString(hBal,"psp_id",csPspId);
DEBUGLOG(("GetExistingPsp psp_id [%s]\n",csPspId));
				}

				if(GetField_CString(hRec,"psp_ccy",&csPayoutCcy)){
DEBUGLOG(("GetExistingPsp psp_ccy [%s]\n",csPayoutCcy));
				}
				if(GetField_CString(hRec,"psp_country",&csPspCountry)){
DEBUGLOG(("GetExistingPsp psp_country [%s]\n",csPspCountry));
				}
				if(GetField_Int(hRec,"txn_count",&iTmp)){
					PutField_Int(hBal,"txn_cnt",iTmp);
DEBUGLOG(("GetExistingPsp txn_count [%d]\n",iTmp));
				}
				if(GetField_Double(hRec,"total_amt",&dAmt)){
DEBUGLOG(("GetExistingPsp total_amt [%lf]\n",dAmt));
				}
				double dBal = 0.0;
DEBUGLOG(("Authorize::Call DBPspBalance:GetAvalPspBalance\n"));
				DBObjPtr = CreateObj(DBPtr,"DBPspBalance","GetAvalPspBalance");
				if((unsigned long)(*DBObjPtr)(csPspId,
							csPayoutCcy,
							csPspCountry,
							&dBal)==PD_OK){
DEBUGLOG(("GetAvalPspBalance balance = [%lf]\n",dBal));
					PutField_Double(hBal,"org_psp_bal",dBal);
					double dAvalBal = 0.0;
DEBUGLOG(("Authorize::Call BOPsp:GetAvalPspBalanceForPO\n"));
					BOObjPtr = CreateObj(BOPtr,"BOPsp","GetAvalPspBalanceForPO");
					if((unsigned long)(*BOObjPtr)(hBal,hBal)==PD_OK){
						if(GetField_Double(hBal,"aval_psp_bal",&dAvalBal)){
DEBUGLOG(("GetAvalPspBalanceForPO aval psp balance = [%.2f]\n",dAvalBal));
							if(dAmt>dAvalBal){
								iRet = INT_INSUFFICIENT_FUND;
								PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("GetAvalPspBalanceForPO aval psp balance[%.2f] less than total generate amount[%lf]!!!!\n",dAvalBal,dAmt));
ERRLOG("TxnMgtByUsPOG:Authorize:GetAvalPspBalanceForPO aval psp balance[%.2f] less than total generate amount[%lf]!!!!\n",dAvalBal,dAmt);
								break;
							}
						}
					}
					else{
						iRet = INT_ERR;
DEBUGLOG(("GetAvalPspBalanceForPO find aval psp balance failed!!!!\n"));
ERRLOG("TxnMgtByUsPOG:Authorize::GetAvalPspBalanceForPO find aval psp balance failed!!!!\n");
						break;
					}
				}
				else{
					iRet = INT_ERR;
DEBUGLOG(("GetAvalPspBalance find balance failed!!!!\n"));
ERRLOG("TxnMgtByUsPOG:Authorize::GetAvalPspBalance find balance failed!!!!\n");
					break;
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::call payout_generate\n"));
		sprintf(csCmd,"payout_generate.exec -p %s -d %s -o %d -u %s &",csPreviewId,csReportDate,iOnlinePayout,csUser);
		system(csCmd);
	}

        if(iRet!=PD_OK){
                PutField_Int(hContext,"internal_error",iRet);
        }

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
        FREE_ME(hBal);
DEBUGLOG(("TxnMgtByUsPOG Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
