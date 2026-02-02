/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/22              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsEFX.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

double  CalDstAmt(double dFromAmt,double dRate,const char* csDstCcy);

void TxnOmtByUsEFX(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csTxnCcy;
	//char	*csToCcy;
	char	*csSettleCcy;
	char	*csInterCcy;
	char	*csTxnCountry;
	char	*csServiceCode;
	char	*csMerchantId;
	char	*csTmp;
	//char    csBundledCcy[PD_CCY_ID_LEN+1];
	double	dAmt = 0.0;
	double	dTmp;
	double	dFee = 0.0;
	double	dSrcAmt = 0.0;
	double	dRealDstAmt = 0.0;
	//hash_t	*hRec;
	char    csTag[PD_TAG_LEN +1];
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

DEBUGLOG(("Authorize\n"));


	if(GetField_CString(hRequest,"ip_addr",&csTmp)){
DEBUGLOG(("Authorize::ip_addr= [%s]\n",csTmp));
	}

	PutField_CString(hContext,"update_user",PD_UPDATE_USER);

	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id = [%s]\n",csMerchantId));
                PutField_CString(hContext,"merchant_id",csMerchantId);
	}
        else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
                iRet=INT_MERCHANT_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::ccy= [%s]\n",csTxnCcy));
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"sett_ccy",&csSettleCcy)){
DEBUGLOG(("Authorize::settlement ccy= [%s]\n",csSettleCcy));
	}
	else{
DEBUGLOG(("Authorize::settlement ccy not found!!\n"));
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
DEBUGLOG(("Authorize::country= [%s]\n",csTxnCountry));
		PutField_CString(hRequest,"txn_country",csTxnCountry);
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

	if(GetField_Double(hContext,"txn_amt",&dAmt)){
		PutField_Double(hContext,"txn_amt",dAmt);
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dAmt));
        }       
        else{   
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
                iRet=INT_PAY_AMOUNT_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

	if(iRet==PD_OK){
///get merchant_client_id
                BOObjPtr = CreateObj(BOPtr,"BOOLMerchant","GetMerchantDetail");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("GetMerchantDetail\n"));
	}

	if(iRet == PD_OK){
		int iCnt = 1;
		PutField_Int(hResponse,"total_cnt",iCnt);
		///use [STR] to find markup fee///
		PutField_CString(hContext,"txn_code",PD_OL_SETTLEMENT_REQUEST);
		PutField_CString(hContext,"sub_txn_code",PD_ENQUIRE_FX);
		PutField_Int(hContext,"get_info_only",PD_TRUE);

		sprintf(csTag,"to_ccy_%d",iCnt);
		PutField_CString(hResponse,csTag,csSettleCcy);
		PutField_CString(hContext,"dst_txn_ccy",csSettleCcy);
DEBUGLOG(("GetAviCurrency::to_ccy = [%s]\n",csSettleCcy));

		double dExRate, dExAmt, dMarkupAmt;
		BOObjPtr = CreateObj(BOPtr,"BOExchange","GetExchangeInfo");
		if ((*BOObjPtr)(hContext,hRequest) == PD_OK) {
DEBUGLOG(("GetExternalExchangeRate Success\n"));
			if(GetField_CString(hContext,"markup_ccy",&csTmp)){
DEBUGLOG(("GetExchangeInfo::Markup Ccy=[%s]\n",csTmp));
			}
			if(GetField_Double(hContext,"markup_amt",&dMarkupAmt)){
DEBUGLOG(("GetExchangeInfo::Markup Amount=[%lf]\n",dMarkupAmt));
			}
			if(GetField_Double(hContext,"markup_rate",&dTmp)){
DEBUGLOG(("GetExchangeInfo::Markup rate=[%lf]\n",dTmp));
			}
			if(GetField_Double(hContext,"ex_rate",&dExRate)){
DEBUGLOG(("GetExchangeInfo::Exchange rate=[%lf]\n",dExRate));
			}
			if(GetField_CString(hContext,"inter_ccy",&csInterCcy)){
DEBUGLOG(("GetExchangeInfo::Inter Ccy=[%s]\n",csInterCcy));
			}
			else{
				GetField_CString(hContext,"dst_txn_ccy",&csInterCcy);
DEBUGLOG(("GetExchangeInfo::Inter Ccy (same with dest ccy)=[%s]\n",csInterCcy));
			}

			if(GetField_Double(hContext,"dst_txn_amt",&dExAmt)){
DEBUGLOG(("GetExchangeInfo::Destination Amount=[%lf]\n",dExAmt));

				sprintf(csTag,"rate_%d",iCnt);
				PutField_Double(hResponse,csTag,dExRate);

				sprintf(csTag,"dest_amt_%d",iCnt);
				PutField_Double(hResponse,csTag,dExAmt);

				sprintf(csTag,"mu_amt_%d",iCnt);
				PutField_Double(hResponse,csTag,dMarkupAmt);

				sprintf(csTag,"inter_ccy_%d",iCnt);
				PutField_CString(hResponse,csTag,csInterCcy);
			}

			BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
			if((unsigned long)(*BOObjPtr)(hContext,hRequest)==PD_OK){
				if(GetField_Double(hContext,"src_txn_fee",&dFee)){
DEBUGLOG(("GetTxnFee::settlement txn fee=[%f]\n",dFee));
				}
					//sprintf(csTag,"settle_fee_%d",iCnt);
					//PutField_Double(hResponse,csTag,dFee);
					//sprintf(csTag,"settle_fee_ccy_%d",iCnt);
					//PutField_CString(hResponse,csTag,csTxnCcy);

				if(GetField_Double(hContext,"net_amt",&dSrcAmt)){
DEBUGLOG(("GetTxnFee::settlement net amt=[%f]\n",dSrcAmt));
				}
				if(GetField_Double(hContext,"dst_txn_amt",&dTmp)){
					dRealDstAmt =  dTmp - CalDstAmt(dFee,dExRate,csSettleCcy);
					sprintf(csTag,"dest_amt_%d",iCnt);
					PutField_Double(hResponse,csTag,dRealDstAmt);
DEBUGLOG(("GetTxnFee::settlement dest net amt=[%f]\n",dRealDstAmt));
				}
			}
			sprintf(csTag,"settle_fee_%d",iCnt);
			PutField_Double(hResponse,csTag,dFee);
			sprintf(csTag,"settle_fee_ccy_%d",iCnt);
			PutField_CString(hResponse,csTag,csTxnCcy);

		}

		/*
		else{	
			DBObjPtr = CreateObj(DBPtr,"DBCurrency","FindAllCurrency");
			if((*DBObjPtr)(rRecordSet) == PD_OK){
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					sprintf(csTag,"to_ccy_%d",iCnt);
					if (GetField_CString(hRec,"to_ccy",&csToCcy)) {
						PutField_CString(hResponse,csTag,csToCcy);
						PutField_CString(hContext,"dst_txn_ccy",csToCcy);
DEBUGLOG(("GetAviCurrency::to_ccy = [%s]\n",csToCcy));

						double dExRate, dExAmt, dMarkupAmt;
						BOObjPtr = CreateObj(BOPtr,"BOExchange","GetExchangeInfo");
						if ((*BOObjPtr)(hContext,hRequest) == PD_OK) {
DEBUGLOG(("GetExternalExchangeRate Success\n"));
							if(GetField_CString(hContext,"markup_ccy",&csTmp)){
DEBUGLOG(("GetExchangeInfo::Markup Ccy=[%s]\n",csTmp));
							}
							if(GetField_Double(hContext,"markup_amt",&dMarkupAmt)){
DEBUGLOG(("GetExchangeInfo::Markup Amount=[%lf]\n",dMarkupAmt));
							}
							if(GetField_Double(hContext,"markup_rate",&dTmp)){
DEBUGLOG(("GetExchangeInfo::Markup rate=[%lf]\n",dTmp));
							}
							if(GetField_Double(hContext,"ex_rate",&dExRate)){
DEBUGLOG(("GetExchangeInfo::Exchange rate=[%lf]\n",dExRate));
							}

							if(GetField_Double(hContext,"dst_txn_amt",&dExAmt)){
DEBUGLOG(("GetExchangeInfo::Destination Amount=[%lf]\n",dExAmt));

								sprintf(csTag,"rate_%d",iCnt);
								PutField_Double(hResponse,csTag,dExRate);

								sprintf(csTag,"dest_amt_%d",iCnt);
								PutField_Double(hResponse,csTag,dExAmt);

								sprintf(csTag,"mu_amt_%d",iCnt);
								PutField_Double(hResponse,csTag,dMarkupAmt);
							}

							BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
							if((unsigned long)(*BOObjPtr)(hContext,hRequest)==PD_OK){
								if(GetField_Double(hContext,"src_txn_fee",&dFee)){
									//sprintf(csTag,"settle_fee_%d",iCnt);
									//PutField_Double(hResponse,csTag,dFee);
									//sprintf(csTag,"settle_fee_ccy_%d",iCnt);
									//PutField_CString(hResponse,csTag,csTxnCcy);
DEBUGLOG(("GetTxnFee::settlement txn fee=[%f]\n",dFee));
								}
								if(GetField_Double(hContext,"net_amt",&dSrcAmt)){
DEBUGLOG(("GetTxnFee::settlement net amt=[%f]\n",dSrcAmt));
								}
								if(GetField_Double(hContext,"dst_txn_amt",&dTmp)){
									dRealDstAmt =  dTmp - CalDstAmt(dFee,dExRate,csToCcy);
									sprintf(csTag,"dest_amt_%d",iCnt);
									PutField_Double(hResponse,csTag,dRealDstAmt);
DEBUGLOG(("GetTxnFee::settlement dest net amt=[%f]\n",dRealDstAmt));
								}
							}
							sprintf(csTag,"settle_fee_%d",iCnt);
							PutField_Double(hResponse,csTag,dFee);
							sprintf(csTag,"settle_fee_ccy_%d",iCnt);
							PutField_CString(hResponse,csTag,csTxnCcy);

						}

					}

					PutField_Int(hResponse,"total_cnt",iCnt);
					iCnt ++;
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
		}
		*/
		PutField_CString(hContext,"txn_code",PD_ENQUIRE_FX);

	}


	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
DEBUGLOG(("TxnOmtByUsEFX Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

double  CalDstAmt(double dFromAmt,double dRate,const char* csDstCcy)
{
        double  dTmp = 0.0;
        dTmp = dFromAmt * dRate;
DEBUGLOG(("CalDstAtm: from[%lf] * rate = [%lf] = [%lf] DST CCY = [%s] \n",dFromAmt,dRate,dTmp,csDstCcy));
        DBObjPtr = CreateObj(DBPtr,"DBCurrency","IsSupportDecimal");
        if ((unsigned long)((*DBObjPtr)(csDstCcy)) == PD_TRUE) {
DEBUGLOG(("CalDstAmt: Support Decimal\n"));
                dTmp =  newround(dTmp, PD_DECIMAL_LEN);
        }
        else {
DEBUGLOG(("CalDstAmt: Doesn't Support Decimal\n"));
                dTmp =  newround(dTmp, 0);
        }
        return dTmp;
}
