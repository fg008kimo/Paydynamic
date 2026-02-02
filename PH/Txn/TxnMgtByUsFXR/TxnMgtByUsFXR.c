/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/09/16              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsFXR.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


#define	PD_DETAIL_TAG "dt"
char cDebug;
OBJPTR(DB);
OBJPTR(BO);


void TxnMgtByUsFXR(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csTxnType;
	char	*csFromCcy;
	char	*csToCcy;
	char	*csInterCcy;
	char	*csTxnCountry;
	char	*csServiceCode;
	char	*csMerchantId;
	char	*csTmp;
	char	*csDateTime;
	char	*csShortName;
	char	*csTxnDesc;
	double	dAmt = 0.0;
	hash_t	*hRec;
	char    csTag[PD_TAG_LEN +1];

	int	iTxnTypeCnt = 0;
	int	iFromCcyCnt = 0;
	int	iToCcyCnt = 0;
	int	iCnt = 0;
	int	iType = 0;
	int	iFrom = 0;
	int	iTo = 0;
	int	iSkip = PD_FALSE;

	char	cExParty;

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

DEBUGLOG(("Authorize\n"));


	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id = [%s]\n",csMerchantId));
                PutField_CString(hContext,"merchant_id",csMerchantId);
	}
        else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
                iRet=INT_MERCHANT_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }
	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
DEBUGLOG(("Authorize::country= [%s]\n",csTxnCountry));
		//PutField_CString(hRequest,"txn_country",csTxnCountry);
        }
        else{   
DEBUGLOG(("Authorize::country not found!!\n"));
                iRet=INT_TXN_COUNTRY_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

        if(GetField_CString(hRequest,"service_code",&csServiceCode)){
DEBUGLOG(("Authorize::sevice_code= [%s]\n",csServiceCode));
		PutField_CString(hRequest,"service_code",csServiceCode);
        }
        else{   
DEBUGLOG(("Authorize::service_code not found!!\n"));
                iRet=INT_SERVICE_CODE_MISSING;
                PutField_Int(hContext,"internal_error",iRet);
        }

	//datetime:   YYYYMMDDHH24MISS
	if(GetField_CString(hRequest,"datetime",&csDateTime)){
DEBUGLOG(("Authorize::datetime = [%s]\n",csDateTime));
                PutField_CString(hContext,"datetime",csDateTime);
                PutField_CString(hResponse,"datetime",csDateTime);
	}
        else{
DEBUGLOG(("Authorize::datetime not found!!\n"));
                iRet=INT_TRASMISSION_TIME_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

	dAmt = 10000.0;
	PutField_Double(hContext,"txn_amt",dAmt);

	if(GetField_Int(hContext,"total_cnt",&iTxnTypeCnt)){
DEBUGLOG(("Authorize:: txn_type_cnt = [%d]\n",iTxnTypeCnt));
	}
	/*
	if(GetField_CString(hRequest,"fr_ccy_cnt",&csTmp)){
		iFromCcyCnt = atoi(csTmp);
DEBUGLOG(("Authorize:: from_ccy_cnt = [%d]\n",iFromCcyCnt));
	}
	if(GetField_CString(hRequest,"to_ccy_cnt",&csTmp)){
		iToCcyCnt = atoi(csTmp);
DEBUGLOG(("Authorize:: to_ccy_cnt = [%d]\n",iToCcyCnt));
	}
	*/
	iFromCcyCnt = 1;
	iToCcyCnt = 1;


	if(iRet==PD_OK){
///get merchant_client_id
DEBUGLOG(("GetMerchantDetail\n"));
                BOObjPtr = CreateObj(BOPtr,"BOMerchant","GetMerchantDetail");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
		if(iRet==PD_OK){
			if (GetField_CString(hContext,"merchant_short_name",&csShortName)) {
				PutField_CString(hResponse,"short_name",csShortName);
DEBUGLOG(("GetMerchantDetail:: merchant_short_name = [%s]\n",csShortName));
			}
		}
	}

	if(iRet == PD_OK){
		//PutField_Int(hResponse,"total_cnt",iCnt);
		PutField_Int(hContext,"get_info_only",PD_TRUE);

		if(iTxnTypeCnt==0){
			//find all txn which apply ex markup
			recordset_init(rRecordSet,0);
			DBObjPtr = CreateObj(DBPtr,"DBChannelTxnMap","GetTxnCodeByApplyMode");
                        if((*DBObjPtr)(PD_APPLY_MARKUP,rRecordSet) == PD_OK){
                                hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					iTxnTypeCnt++;
					if (GetField_CString(hRec,"channel_code",&csTmp)) {
						sprintf(csTag,"%s_channel_%d",PD_DETAIL_TAG,iTxnTypeCnt);
						PutField_CString(hRequest,csTag,csTmp);
DEBUGLOG(("GetTxnCodeByApplyMode:: channel_code = [%s]\n",csTmp));
					}
                                        if (GetField_CString(hRec,"txn_code",&csTmp)) {
						sprintf(csTag,"%s_type_%d",PD_DETAIL_TAG,iTxnTypeCnt);
						PutField_CString(hRequest,csTag,csTmp);
DEBUGLOG(("GetTxnCodeByApplyMode:: txn_code = [%s]\n",csTmp));
					}
                                        if (GetField_CString(hRec,"txn_desc",&csTmp)) {
						sprintf(csTag,"%s_desc_%d",PD_DETAIL_TAG,iTxnTypeCnt);
						PutField_CString(hRequest,csTag,csTmp);
DEBUGLOG(("GetTxnCodeByApplyMode:: txn_desc = [%s]\n",csTmp));
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
		}
		if(iFromCcyCnt==0){
			/*recordset_init(rRecordSet,0);
			DBObjPtr = CreateObj(DBPtr,"DBCurrency","FindAllCurrency");
                        if((*DBObjPtr)(rRecordSet) == PD_OK){
                                hRec = RecordSet_GetFirst(rRecordSet);
                                while (hRec) {
                                        if (GetField_CString(hRec,"to_ccy",&csTmp)) {
						iFromCcyCnt++;
						sprintf(csTag,"%s_from_ccy_%d",PD_DETAIL_TAG,iFromCcyCnt);
						PutField_CString(hRequest,csTag,csTmp);
DEBUGLOG(("FindAllCurrency:: from_ccy_%d = [%s]\n",iFromCcyCnt,csTmp));
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			*/
			//if not selected, only display CNY
			iFromCcyCnt=1;
			//sprintf(csTag,"%s_fr_ccy_%d",PD_DETAIL_TAG,iFromCcyCnt);
			sprintf(csTag,"fr_ccy");
			PutField_CString(hRequest,csTag,PD_CCY_ISO_CNY);
DEBUGLOG(("Use Default Ccy:: from_ccy_%d = [%s]\n",iFromCcyCnt,PD_CCY_ISO_CNY));

		}
		if(iToCcyCnt==0){
			/*
			recordset_init(rRecordSet,0);
			DBObjPtr = CreateObj(DBPtr,"DBCurrency","FindAllCurrency");
                        if((*DBObjPtr)(rRecordSet) == PD_OK){
                                hRec = RecordSet_GetFirst(rRecordSet);
                                while (hRec) {
                                        if (GetField_CString(hRec,"to_ccy",&csTmp)) {
						iToCcyCnt++;
						sprintf(csTag,"%s_to_ccy_%d",PD_DETAIL_TAG,iToCcyCnt);
						PutField_CString(hRequest,csTag,csTmp);
DEBUGLOG(("FindAllCurrency:: to_ccy_%d = [%s]\n",iToCcyCnt,csTmp));
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}*/
			//if not selected, only display CNY
			iToCcyCnt=1;
			//sprintf(csTag,"%s_to_ccy_%d",PD_DETAIL_TAG,iToCcyCnt);
			sprintf(csTag,"to_ccy");
			PutField_CString(hRequest,csTag,PD_CCY_ISO_CNY);
DEBUGLOG(("Use Default Ccy:: to_ccy_%d = [%s]\n",iToCcyCnt,PD_CCY_ISO_CNY));
		}

		for(iType=1; iType<=iTxnTypeCnt; iType++){
			sprintf(csTag,"%s_channel_%d",PD_DETAIL_TAG,iType);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hContext,"channel_code",csTmp);
DEBUGLOG(("Authorize:: channel_code_%d = [%s]\n",iType,csTmp));
			}
			sprintf(csTag,"%s_type_%d",PD_DETAIL_TAG,iType);
			if(GetField_CString(hRequest,csTag,&csTxnType)){
				PutField_CString(hContext,"txn_code",csTxnType);
DEBUGLOG(("Authorize:: txn_type_%d = [%s]\n",iType,csTxnType));
			}
			sprintf(csTag,"%s_desc_%d",PD_DETAIL_TAG,iType);
			if(GetField_CString(hRequest,csTag,&csTxnDesc)){
DEBUGLOG(("Authorize:: txn_desc_%d = [%s]\n",iType,csTxnDesc));
			}

			for(iFrom=1; iFrom<=iFromCcyCnt; iFrom++){
				//sprintf(csTag,"%s_fr_ccy_%d",PD_DETAIL_TAG,iFrom);
				sprintf(csTag,"fr_ccy");
				if(GetField_CString(hRequest,csTag,&csFromCcy)){
					PutField_CString(hContext,"txn_ccy",csFromCcy);
					PutField_CString(hRequest,"txn_ccy",csFromCcy);
DEBUGLOG(("Authorize:: from_ccy_%d = [%s]\n",iFrom,csFromCcy));
				}

				for(iTo=1; iTo<=iToCcyCnt; iTo++){
					//sprintf(csTag,"%s_to_ccy_%d",PD_DETAIL_TAG,iTo);
					sprintf(csTag,"dst_txn_ccy");
					if(GetField_CString(hRequest,csTag,&csToCcy)){
						PutField_CString(hContext,"dst_txn_ccy",csToCcy);
DEBUGLOG(("Authorize:: to_ccy_%d = [%s]\n",iTo,csToCcy));
					}

					if((iFromCcyCnt+iToCcyCnt)>2){
						if(!strcmp(csFromCcy,csToCcy)){
							iSkip = PD_TRUE;
						}
					}

					if(iSkip == PD_FALSE){
						double	dExRate = 0.0;
						double	dExRateMU = 0.0;
						double	dMarkupRate = 0.0;
						double	dOrgExRate = 0.0;
						double	dInterRate = 0.0;
						double	dOrgIntExRate = 0.0;
						RemoveField_Double(hContext,"ex_int_rate");
						RemoveField_Double(hContext,"inter_rate");
						RemoveField_CString(hContext,"inter_ccy");

						BOObjPtr = CreateObj(BOPtr,"BOExchange","GetExchangeInfoByDate");
						if ((*BOObjPtr)(hContext,hRequest) == PD_OK) {
DEBUGLOG(("GetExchangeInfoByDate Success\n"));
							if(GetField_CString(hContext,"markup_ccy",&csTmp)){
DEBUGLOG(("GetExchangeInfoByDate::Markup Ccy=[%s]\n",csTmp));
							}
							if(GetField_Double(hContext,"markup_rate",&dMarkupRate)){
DEBUGLOG(("GetExchangeInfoByDate::Markup rate=[%lf]\n",dMarkupRate));
							}
							if(GetField_Double(hContext,"org_ex_rate",&dOrgExRate)){
DEBUGLOG(("GetExchangeInfoByDate::Exchange rate (OANDA)=[%lf]\n",dOrgExRate));
							}
							if(GetField_Double(hContext,"ex_int_rate",&dOrgIntExRate)){
DEBUGLOG(("GetExchangeInfoByDate::Exchange rate (OANDA+ACR)=[%lf]\n",dOrgIntExRate));
							}
							if(GetField_Double(hContext,"inter_rate",&dInterRate)){
DEBUGLOG(("GetExchangeInfoByDate::Inter rate=[%lf]\n",dInterRate));
							}
							if(GetField_CString(hContext,"inter_ccy",&csInterCcy)){
DEBUGLOG(("GetExchangeInfoByDate::Inter Ccy=[%s]\n",csInterCcy));
							}
							else{
								GetField_CString(hContext,"dst_txn_ccy",&csInterCcy);
DEBUGLOG(("GetExchangeInfoByDate::Inter Ccy (same with dest ccy)=[%s]\n",csInterCcy));
							}
							if(GetField_Double(hContext,"ex_rate",&dExRate)){
DEBUGLOG(("GetExchangeInfoByDate::Final Exchange rate=[%lf]\n",dExRate));
							}

							if(GetField_Double(hContext,"ex_rate_w_mu",&dExRateMU)){
DEBUGLOG(("GetExchangeInfoByDate::Final Exchange Rate (With Markup)=[%lf]\n",dExRateMU));
							}
							
							if(GetField_Char(hContext,"ex_party",&cExParty)){
DEBUGLOG(("GetExchangeInfoByDate::Final Exchange Rate Party=[%c]\n",cExParty));
							}

							iCnt ++;
							sprintf(csTag,"rate_%d",iCnt);
							PutField_Double(hResponse,csTag,dExRate);

							sprintf(csTag,"rate_w_mu_%d",iCnt);
							PutField_Double(hResponse,csTag,dExRateMU);

							sprintf(csTag,"ext_rate_%d",iCnt);
							PutField_Double(hResponse,csTag,dOrgExRate);

							sprintf(csTag,"ex_int_rate_%d",iCnt);
							PutField_Double(hResponse,csTag,dOrgIntExRate);

							sprintf(csTag,"mu_rate_%d",iCnt);
							PutField_Double(hResponse,csTag,dMarkupRate);
							
							sprintf(csTag,"ccy_%d",iCnt);
							PutField_CString(hResponse,csTag,csFromCcy);

							sprintf(csTag,"to_ccy_%d",iCnt);
							PutField_CString(hResponse,csTag,csToCcy);

							sprintf(csTag,"txn_type_%d",iCnt);
							PutField_CString(hResponse,csTag,csTxnDesc);

							if(dInterRate>0.0){
								sprintf(csTag,"inter_rate_%d",iCnt);
								PutField_Double(hResponse,csTag,dInterRate);

								sprintf(csTag,"inter_ccy_%d",iCnt);
								PutField_CString(hResponse,csTag,csInterCcy);
							}
							/*
							sprintf(csTag,"datetime_%d",iCnt);
							PutField_CString(hResponse,csTag,csDateTime);

							sprintf(csTag,"short_name_%d",iCnt);
							PutField_CString(hResponse,csTag,csShortName);
							*/
							PutField_Int(hResponse,"total_cnt",iCnt);
						}
					}
				}
			}
		}
		//PutField_CString(hContext,"txn_code",PD_ENQUIRE_FX);

	}


	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
DEBUGLOG(("TxnMgtByUsFXR Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
