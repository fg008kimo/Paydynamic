/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/18              Cody Chan
CheckEntityBalAcct				   2015/06/25		   Cody Chan
Add return entity_type into hContext		   2015/06/25		   Dirk Wong
Add cost, credit limit check			   2015/06/30		   Cody Chan
Add Checking for dst_data			   2015/07/07 		   Cody Chan
Add Checking for override data			   2015/07/09 		   Cody Chan
Add addtional cost to nature_txn_amt		   2015/07/21		   Cody Chan
Remove Txn Country				   2015/07/21		   Cody Chan
Special Handle for txn: EPA (Set Default Nature)   2015/07/29              Virginia Yun
Add Checking for txn amt aginst the total bal amt  2015/08/04		   Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmmByUsCOM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

int CheckAmt(char* csCcy,char* csAmt,double *dAmt);
int GetSrcNatureId(hash_t* hContext,const hash_t *hReq);

void TxnMmmByUsCOM(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK,i,iBalCnt = 0, j, iTidCnt;
	char	*csTxnCcy;
	char	*csTxnAmt;
	char	*csPtr;
	char	*csEntityType;
	char	*csTxnCode;
	char	csTag[PD_TAG_LEN +1];
	hash_t	*hTmpData;
	double	dTmp;

	double	dTxnAmt;
	int	iFxCnt = 0;
DEBUGLOG(("Authorize()\n"));


	hTmpData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTmpData,0);


	GetField_CString(hContext,"txn_code",&csTxnCode);
DEBUGLOG(("Authorize txn_code = [%s]\n",csTxnCode));

	if (GetField_CString(hRequest,"rs_type",&csPtr)) {
DEBUGLOG(("Authorize rs_type = [%s]\n",csPtr));
		PutField_Char(hContext,"rs_type",csPtr[0]);
	}
/* check txn amt */
	if (GetField_CString(hRequest,"txn_amt",&csTxnAmt)) {
		if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
                	DBObjPtr = CreateObj(DBPtr,"DBCurrency","FindCurrency");
                       	if ((unsigned long)(DBObjPtr)(csTxnCcy) == FOUND) {
DEBUGLOG(("Authorize() DBCurrency->FindCurrency [%s]success\n",csTxnCcy));
/* net ccy */
                      		PutField_CString(hContext,"net_ccy",csTxnCcy);
                                PutField_CString(hContext,"txn_ccy",csTxnCcy);
                        }
                        else{
                       		iRet = INT_INVALID_CURRENCY_CODE;
                                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Currency code invalid [%s]\n",csTxnCcy));
ERRLOG("TxnMmmByUsCOM:Authorize() Currency code invalid\n");
                        }
            	}
               	else{
               		iRet = INT_CURRENCY_CODE_NOT_FOUND;
                      	PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Currency code not found\n"));
ERRLOG(("TxnMmmByUsCOM:Authorize() Currency code not found\n"));
		}
		if (iRet == PD_OK ) {
			iRet =  CheckAmt(csTxnCcy,csTxnAmt,&dTxnAmt);
			if (iRet != PD_OK)
               			PutField_Int(hContext,"internal_error",iRet);
			else  {
               			PutField_Double(hContext,"txn_amt",dTxnAmt);
               			PutField_Double(hContext,"net_amt",dTxnAmt);
			}
		}
	}

/* check entity id if exist */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest,"txn_data.entity_id",&csPtr)) {
DEBUGLOG(("Authorize() entity id from Request = [%s]\n",csPtr));
                	BOObjPtr = CreateObj(BOPtr,"BOMMSEntity","GetEntityId");
                       	iRet = (unsigned long)(BOObjPtr)(csPtr,hTmpData);

			if (iRet != PD_OK) {
				iRet = INT_MMS_ENTITY_ID_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() entity id [%s] record not found\n",csPtr));
ERRLOG("TxnMmmByUsCOM:Authorize() entity id [%s] record not found\n",csPtr);
			}
			else {
				PutField_CString(hContext,"entity_id",csPtr);
				if (GetField_CString(hTmpData,"entity_type",&csEntityType))
					PutField_CString(hContext,"entity_type",csEntityType);
			}

			if (iRet == PD_OK ) {
				if (GetField_CString(hRequest,"txn_ccy",&csPtr)) {
                			BOObjPtr = CreateObj(BOPtr,"BOMMSEntityBalAcct","CheckEntityBalAcct");
                			iRet = (unsigned long)((BOObjPtr)(hContext,hRequest));
DEBUGLOG(("TxnMmmByUsCOM: iRet = [%d] return from BOMMSEntityBalAcct:CheckEntityBalAcct\n",iRet));
				}
			}
		}
	}

/* check cost  */
	if (iRet == PD_OK) {
		double	dCostRate = 0.0;
		double	dCostFlatRate = 0.0;
		double	dCostAmt = 0.0;
		double	dClRate = 0.0;
		double	dClFlatRate = 0.0;
		double	dClAmt = 0.0;
		char	cCostCal = ' ';
	
		if (GetField_CString(hRequest,"txn_data.cost_cal",&csPtr)) {
DEBUGLOG(("Authorize() txn_data.cost_cal = [%s]\n",csPtr));
			cCostCal = csPtr[0];
			PutField_Char(hContext,"cost_cal",cCostCal);

/* cost rate */
			if (GetField_CString(hRequest,"txn_data.cost_rate",&csPtr)) {
				dCostRate = string2double((const unsigned char*)csPtr);
DEBUGLOG(("Authorize() txn_data.cost_rate = [%s][%lf]\n",csPtr,dCostRate));
			}
/* cost flat rate */
			if (GetField_CString(hRequest,"txn_data.cost_frate",&csPtr)) {
				dCostFlatRate = string2double((const unsigned char*)csPtr);
DEBUGLOG(("Authorize() txn_data.cost_flat_rate = [%s][%lf]\n",csPtr,dCostFlatRate));
			}
/* cost amt */
			if (GetField_CString(hRequest,"txn_data.cost_amt",&csPtr)) {
				dCostAmt = string2double((const unsigned char*)csPtr);
DEBUGLOG(("Authorize() txn_data.cost_amt = [%s][%lf]\n",csPtr,dCostAmt));
				if (cCostCal == PD_MMS_COST_CAL_NET) {
					if (GetField_Double(hContext,"txn_amt",&dTmp)) {
DEBUGLOG(("Authorize() override txn_amt = [%lf[\n",dTmp - dCostAmt));
						PutField_Double(hContext,"override_txn_amt", dTmp - dCostAmt);
					}
				}
			}
/* cl_rate */
			if (GetField_CString(hRequest,"txn_data.cl_rate",&csPtr)) {
				dClRate = string2double((const unsigned char*)csPtr);
DEBUGLOG(("Authorize() txn_data.cl_rate = [%s][%lf]\n",csPtr,dClRate));
			}
/* cl_flat_rate */
			if (GetField_CString(hRequest,"txn_data.cl_frate",&csPtr)) {
				dClFlatRate = string2double((const unsigned char*)csPtr);
DEBUGLOG(("Authorize() txn_data.cl_flat_rate = [%s][%lf]\n",csPtr,dClFlatRate));
			}
/* cl_amt */
			if (GetField_CString(hRequest,"txn_data.cl_amt",&csPtr)) {
				dClAmt = string2double((const unsigned char*)csPtr);
DEBUGLOG(("Authorize() txn_data.cl_amt = [%s][%lf]\n",csPtr,dClAmt));
			}
		}

		PutField_Double(hContext,"cost_rate",dCostRate);
		PutField_Double(hContext,"cost_flat_rate",dCostFlatRate);
		PutField_Double(hContext,"cost_amt",dCostAmt);
		PutField_Double(hContext,"cl_rate",dClRate);
		PutField_Double(hContext,"cl_flat_rate",dClFlatRate);
		PutField_Double(hContext,"cl_amt",dClAmt);

	}
/* check nature group if exist */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest,"txn_data.bal_cnt",&csPtr)) {
DEBUGLOG(("Authorize() [%s] = [%s]\n","txn_data.bal_cnt",csPtr));
			if (!is_numeric(csPtr)) {
				iRet = INT_INVALID_COUNT;
DEBUGLOG(("Authorize() Invalid [%s] = [%s]\n","txn_data.bal_cnt",csPtr));
ERRLOG("TxnMmmByUsCOM:Authorize() Invalid Count [%s] = [%s]\n","txn_data.bal_cnt",csPtr);
			}
			else {
				iBalCnt = ctos((const unsigned char*)csPtr,(strlen(csPtr)));
				PutField_Int(hContext,"bal_cnt", iBalCnt);
			}

			if (iRet == PD_OK) {

/* skip check if it is balance account */
				if (strcmp(csTxnCode,PD_TXN_CODE_MMS_BALACE_ACCOUNT) &&
				    strcmp(csTxnCode, PD_TXN_CODE_MMS_DEFAULT_NID)) {
					iRet = GetSrcNatureId(hContext,hRequest);
DEBUGLOG(("Authorize()  iRet = [%d] from GetSrcNatureId\n",iRet));
					if (iRet != PD_OK) {
						iRet = INT_MMS_NATURE_ID_NOT_FOUND;
               					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()  Nature ID not found\n"));
ERRLOG("TxnMmmByUsCOM:Authorize()  Nature ID not found\n");
					}
				}
				else {
DEBUGLOG(("Authorize() GetSrcNatureId Skip\n"));
				}
			}
			if (iRet == PD_OK) {
				for (i = 1 ; i <= iBalCnt; i++) {
					sprintf(csTag,"txn_data.bal.%d.sel_type",i);
DEBUGLOG(("TxnMmmByUsCOM:Authorize() sel_type from message = [%s]\n",csTag));
					if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("TxnMmmByUsCOM:Authorize() sel_type from message = [%s]\n",csPtr));
                		       		if (csPtr[0] != PD_MMS_SELECT_BAL && csPtr[0] != PD_MMS_SELECT_TXN ) {
                             				iRet = INT_MMS_INVALID_SELECT_TYPE;
                                			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()  invalid select_type\n"));
ERRLOG("TxnMmmByUsCOM:Authorize()  invalid select_type\n");
                        			}
						else {
							sprintf(csTag,"bal.%d.sel_type",i);
DEBUGLOG(("TxnMmmByUsCOM:Authorize() [%s] = [%s]\n",csTag,csPtr));
                                			PutField_Char(hContext,csTag,csPtr[0]);
						}
						if (iRet == PD_OK && csPtr[0] == PD_MMS_SELECT_TXN) {
							sprintf(csTag,"txn_data.bal.%d.tid_cnt",i);
							if (GetField_CString(hRequest,csTag,&csPtr)) {
								iTidCnt = ctos((const unsigned char*)csPtr,strlen(csPtr));
DEBUGLOG(("Authorize() %s = [%d]\n",csTag,iTidCnt));
								sprintf(csTag,"bal.%d.tid_cnt",i);
								PutField_Int(hContext,csTag,iTidCnt);
								for (j = 1; j <= iTidCnt; j++) {
									sprintf(csTag,"txn_data.bal.%d.tid.%d.txn_id",i,j);
									if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("Authorize() %s = [%s]\n",csTag,csPtr));
										sprintf(csTag,"bal.%d.tid.%d.txn_id",i,j);
										PutField_CString(hContext,csTag,csPtr);
									}
								}
							}
							else {
DEBUGLOG(("Authorize()  %s not found\n",csTag));
ERRLOG("TxnMmmByUsCOM:Authorize() %s not found\n",csTag);
								iRet = PD_ERR;
							}
						}
                			}
				}
			}
		}
	}

/* check fx pool if exist */
	if (iRet == PD_OK) {
		double	dFXpoolAmt = 0.0;
		double	dAffectFXAmt = 0.0;
		double	dNonAffectFXAmt = 0.0;

		if (GetField_CString(hRequest,"txn_data.aff_fx_amt",&csPtr)) {
			dAffectFXAmt = string2double((const unsigned char*)csPtr);
DEBUGLOG(("Authorize() txn_data.aff_fx_amt = [%s][%lf]\n",csPtr,dAffectFXAmt));
		}

		if (GetField_CString(hRequest,"txn_data.non_aff_fx_amt",&csPtr)) {
			dNonAffectFXAmt = string2double((const unsigned char*)csPtr);
DEBUGLOG(("Authorize() txn_data.non_aff_fx_amt= [%s][%lf]\n",csPtr,dNonAffectFXAmt));
		}
		PutField_Double(hContext,"aff_fx_amt",dAffectFXAmt);
		PutField_Double(hContext,"non_aff_fx_amt",dNonAffectFXAmt);


		if (GetField_CString(hRequest,"txn_data.fx_cnt",&csPtr)) {
DEBUGLOG(("Authorize() [%s] = [%s]\n","txn_data.fx_cnt",csPtr));
			if (!is_numeric(csPtr)) {
				iRet = INT_INVALID_COUNT;
DEBUGLOG(("Authorize() Invalid [%s] = [%s]\n","txn_data.fx_cnt",csPtr));
ERRLOG("TxnMmmByUsCOM:Authorize() Invalid Count [%s] = [%s]\n","txn_data.fx_cnt",csPtr);
			}
			else {
				iFxCnt = ctos((const unsigned char*)csPtr,(strlen(csPtr)));
				PutField_Int(hContext,"fx_cnt", iFxCnt);
DEBUGLOG(("Authorize() iFxCnt = [%d]\n",iFxCnt));
			}

			if (iRet == PD_OK) {
				double	dTotalFxAmt = 0.0;
				for (i = 1 ; i <= iFxCnt; i++) {
					dFXpoolAmt = 0.0;

					sprintf(csTag,"fx.%d.acr_ind",i);
					PutField_Int(hContext,csTag,PD_TRUE);

					sprintf(csTag,"txn_data.fx.%d.occy",i);
					if (GetField_CString(hRequest,csTag,&csPtr)) {
						sprintf(csTag,"fx.%d.occy",i);
						PutField_CString(hContext,csTag,csPtr);
DEBUGLOG(("TxnMmmByUsCOM:Authorize() [%s] from message = [%s]\n",csTag,csPtr));
					}
					sprintf(csTag,"txn_data.fx.%d.ccy",i);
					if (GetField_CString(hRequest,csTag,&csPtr)) {
						sprintf(csTag,"fx.%d.ccy",i);
						PutField_CString(hContext,csTag,csPtr);
DEBUGLOG(("TxnMmmByUsCOM:Authorize() [%s] from message = [%s]\n",csTag,csPtr));
					}
					sprintf(csTag,"txn_data.fx.%d.amt",i);
					if (GetField_CString(hRequest,csTag,&csPtr)) {
						sprintf(csTag,"fx.%d.amt",i);
						dFXpoolAmt = string2double((const unsigned char*)csPtr);
						PutField_Double(hContext,csTag,dFXpoolAmt);
DEBUGLOG(("TxnMmmByUsCOM:Authorize() [%s] from message = [%lf]\n",csTag,dFXpoolAmt));
					}
					dTotalFxAmt += dFXpoolAmt;
				}

				if (dTotalFxAmt !=  dAffectFXAmt) {
DEBUGLOG(("TxnMmmByUsCOM:Authorize() FX amt [%lf] != Affect FX Amt [%lf]\n",dTotalFxAmt,dAffectFXAmt));
ERRLOG("TxnMmmByUsCOM:Authorize() FX amt [%lf] != Affect FX Amt [%lf]\n",dTotalFxAmt,dAffectFXAmt);
					iRet = INT_MMS_INVALID_AMT;
					PutField_Int(hContext,"internal_error",iRet);
				}
				else {
					i++;
					if (dNonAffectFXAmt > 0.0) {
						sprintf(csTag,"fx.%d.occy",i);
						PutField_CString(hContext,csTag,PD_CCY_UNKNOWN);

						sprintf(csTag,"fx.%d.ccy",i);
						PutField_CString(hContext,csTag,csTxnCcy);

						sprintf(csTag,"fx.%d.amt",i);
						PutField_Double(hContext,csTag,dNonAffectFXAmt);

						sprintf(csTag,"fx.%d.acr_ind",i);
						PutField_Int(hContext,csTag,PD_FALSE);
DEBUGLOG(("TxnMmmByUsCOM:Authorize() [%s] = [%d]\n",csTag,PD_TRUE));

						PutField_Int(hContext,"fx_cnt", iFxCnt);
					}
				}
			}
		}
	}

/* check for recv txn */
	if (iRet == PD_OK) {
		int	iTxnCnt = 0;
		if (GetField_CString(hRequest,"txn_data.txn_cnt",&csPtr)) {
DEBUGLOG(("Authorize() txn_data.txn_cnt = [%s]\n",csPtr));
			iTxnCnt = ctos((const unsigned char*)csPtr,(strlen(csPtr)));
			PutField_Int(hContext,"txn_cnt", iTxnCnt);

			for (i = 1 ; i <= iTxnCnt; i++) {
				sprintf(csTag,"txn_data.tid.%d.txn_id",i);
				if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("Authorize() %s = [%s]\n",csTag,csPtr));
					sprintf(csTag,"tid.%d.txn_id",i);
					PutField_CString(hContext,csTag, csPtr);
				}
			}
		}
		
	}
/* check override data  */
	if (iRet == PD_OK) {
/* override cost_rate */
                if (GetField_CString(hRequest,"over.cost_rate",&csPtr)) {
			dTmp = string2double((const unsigned char*)csPtr);
DEBUGLOG(("Authorize() Override cost_rate = [%s] [%lf]\n",csPtr,dTmp));
			PutField_Double(hContext,"cost_rate",dTmp);
		}
/* override cost_flat_rate */
                if (GetField_CString(hRequest,"over.cost_frate",&csPtr)) {
			dTmp = string2double((const unsigned char*)csPtr);
DEBUGLOG(("Authorize() Override cost_flat_rate = [%s] [%lf]\n",csPtr,dTmp));
			PutField_Double(hContext,"cost_flat_rate",dTmp);
		}

/* override cost */
                if (GetField_CString(hRequest,"over.cost",&csPtr)) {
			dTmp = string2double((const unsigned char*)csPtr);
DEBUGLOG(("Authorize() Override cost_amt = [%s] [%lf]\n",csPtr,dTmp));
			PutField_Double(hContext,"cost_amt",dTmp);
		}
/* override fx_rate */
                if (GetField_CString(hRequest,"over.fx_rate",&csPtr)) {
			dTmp = string2double((const unsigned char*)csPtr);
DEBUGLOG(("Authorize() Override fx_rate = [%s] [%lf]\n",csPtr,dTmp));
			PutField_Double(hContext,"fx_rate",dTmp);
		}


	}

/* check recevie mode */
	if (iRet == PD_OK) {
		char	cRecvMode;
		if (GetField_CString(hRequest,"recv.r_type",&csPtr)) {
			cRecvMode = csPtr[0];
DEBUGLOG(("Authorize() r_type from Request = [%c]\n",cRecvMode));
			PutField_Char(hContext,"recv_type",cRecvMode);

			if (cRecvMode == PD_FULL_RECEIVE) {
/* amount handle type */
				if (GetField_CString(hRequest,"recv.a_r_type",&csPtr)) {
DEBUGLOG(("Authorize() a_r_type from Request = [%c]\n",csPtr[0]));
					PutField_Char(hContext,"all_handle_type",csPtr[0]);
				}
/* amount reason */
				if (GetField_CString(hRequest,"recv.amt_r",&csPtr)) {
DEBUGLOG(("Authorize() amt_r from Request = [%s]\n",csPtr));
					PutField_CString(hContext,"amt_reason",csPtr);
				}
/* amount */
				if (GetField_CString(hRequest,"recv.amt",&csPtr)) {
DEBUGLOG(("Authorize() amt from Request = [%s]\n",csPtr));
       					dTmp = string2double((const unsigned char*)csPtr);
					PutField_Double(hContext,"amt_diff",dTmp);
DEBUGLOG(("Authorize() amt_diff = [%lf]\n",dTmp));
					if (GetField_CString(hRequest,"recv.amt_ind",&csPtr)) {
						if (!strcmp(csPtr,PD_DR)) {
							dTxnAmt += dTmp;
DEBUGLOG(("Authorize() new txn amt [%lf] = [%lf] + [%lf]\n",dTxnAmt, dTxnAmt - dTmp,dTmp));
						}
						else {
							dTxnAmt -= dTmp;
DEBUGLOG(("Authorize() new txn amt [%lf] = [%lf] - [%lf]\n",dTxnAmt, dTxnAmt + dTmp,dTmp));
						}
						PutField_Double(hContext,"txn_amt",dTxnAmt);
						PutField_Double(hContext,"net_amt",dTxnAmt);
	
					}
					else {
DEBUGLOG(("Authorize()  amd indicator is missing\n"));
ERRLOG("Authorize()  amd indicator is missing\n");
						iRet = PD_ERR;
					}
				}
			}
		}
	}
/* checking for dst_data */
	/* check entity id if exist */
        if (iRet == PD_OK) {
		hash_t	*hDstContext;

		hDstContext = (hash_t*) malloc (sizeof(hash_t));
        	hash_init(hDstContext,0);
        	hash_init(hTmpData,0);

                if (GetField_CString(hRequest,"dst_data.entity_id",&csPtr)) {
DEBUGLOG(("Authorize() DST DATA entity id from Request = [%s]\n",csPtr));
                        BOObjPtr = CreateObj(BOPtr,"BOMMSEntity","GetEntityId");
                        iRet = (unsigned long)(BOObjPtr)(csPtr,hTmpData);

                        if (iRet != PD_OK) {
                                iRet = INT_MMS_ENTITY_ID_NOT_FOUND;
                                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() DST DATA entity id [%s] record not found\n",csPtr));
ERRLOG("TxnMmmByUsCOM:Authorize() DST DATA entity id [%s] record not found\n",csPtr);
                        }
                        else {
                                PutField_CString(hDstContext,"entity_id",csPtr);
                                PutField_CString(hContext,"dst.entity_id",csPtr);

                                if (GetField_CString(hTmpData,"entity_type",&csEntityType)) {
                                        PutField_CString(hDstContext,"entity_type",csEntityType);
                                        PutField_CString(hContext,"dst.entity_type",csEntityType);
				}
                        }

                        if (iRet == PD_OK ) {
				if (GetField_CString(hRequest,"dst_data.ccy",&csPtr)) {
DEBUGLOG(("TxnMmmByUsCOM:Authorize DST DATA txn_ccy = [%s]\n",csPtr));
					hash_t	*hDstRequest;
					hDstRequest = (hash_t*) malloc (sizeof(hash_t));
					hash_init(hDstRequest,0);

					PutField_CString(hDstRequest,"txn_ccy",csPtr);
					PutField_CString(hContext,"dst.txn_ccy",csPtr);

                                        BOObjPtr = CreateObj(BOPtr,"BOMMSEntityBalAcct","CheckEntityBalAcct");
                                        iRet = (unsigned long)((BOObjPtr)(hDstContext,hDstRequest));
DEBUGLOG(("TxnMmmByUsCOM:Authorize DST DATA  iRet = [%d] return from BOMMSEntityBalAcct:CheckEntityBalAcct\n",iRet));
					if (iRet != PD_OK) {
						PutField_Int(hContext,"internal_error",iRet);
					}
					FREE_ME(hDstRequest);
                                }
                        }

			if (iRet == PD_OK) {
/* cost rate */
                        	if (GetField_CString(hRequest,"dst_data.cost_rate",&csPtr)) 
                                	dTmp = string2double((const unsigned char*)csPtr);
				else 
					dTmp = 0.0;
DEBUGLOG(("Authorize() dst.cost_rate = [%s][%lf]\n",csPtr,dTmp));
				PutField_Double(hContext,"dst.provided_cost_rate",dTmp);
/* cost flat rate */
                        	if (GetField_CString(hRequest,"dst_data.cost_frate",&csPtr)) 
                                	dTmp = string2double((const unsigned char*)csPtr);
				else
					dTmp = 0.0;
DEBUGLOG(("Authorize() dst.cost_flat_rate = [%s][%lf]\n",csPtr,dTmp));
				PutField_Double(hContext,"dst.provided_cost_flat_rate",dTmp);
/* cost amt */
                        	if (GetField_CString(hRequest,"dst_data.cost",&csPtr)) 
                                	dTmp = string2double((const unsigned char*)csPtr);
				else 
					dTmp = 0.0;
DEBUGLOG(("Authorize() dst.cost_amt = [%s][%lf]\n",csPtr,dTmp));
				PutField_Double(hContext,"dst.provided_cost_amt",dTmp);
/* allow prepaid */
                        	if (GetField_CString(hRequest,"dst_data.allow_prepaid",&csPtr))  {
DEBUGLOG(("Authorize() dst.allow_prepaid = [%c]\n",csPtr[0]));
					PutField_Char(hContext,"dst.allow_prepaid",csPtr[0]);
				}
/* fx mode  */
                        	if (GetField_CString(hRequest,"dst_data.auto_fx_mode",&csPtr))  {
DEBUGLOG(("Authorize() dst.auto_fx_mode = [%c]\n",csPtr[0]));
					PutField_Char(hContext,"dst.auto_fx_mode",csPtr[0]);
				}

/* fx_rate */
                                if (GetField_CString(hRequest,"dst_data.fx_rate",&csPtr))
                                        dTmp = string2double((const unsigned char*)csPtr);
                                else
                                        dTmp = 0.0;
DEBUGLOG(("Authorize() provided_fx_rate = [%s][%lf]\n",csPtr,dTmp));
                                PutField_Double(hContext,"provided_fx_rate",dTmp);

/* fx_amt */
                                if (GetField_CString(hRequest,"dst_data.fx_amt",&csPtr))
                                        dTmp = string2double((const unsigned char*)csPtr);
                                else
                                        dTmp = 0.0;
DEBUGLOG(("Authorize() provided_fx_amt = [%s][%lf]\n",csPtr,dTmp));
                                PutField_Double(hContext,"provided_fx_amt",dTmp);
                                PutField_Double(hContext,"fx_amt",dTmp);

			}
                }
		else {
DEBUGLOG(("TxnMmmByUsCOM:Authorize DST DATA not dst_data found, skip\n"));
		}


		FREE_ME(hDstContext);
        }

	hash_destroy(hTmpData);
	FREE_ME(hTmpData);
DEBUGLOG(("TxnMmmByUsCOM Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

int CheckAmt(char* csCcy,char* csAmt,double *dTxnAmt)
{
	int	iRet = PD_OK;

	long	lTmp;
DEBUGLOG(("CheckAmt()\n"));
	if(strlen(csAmt)>(PD_DIGIT_LEN+PD_DECIMAL_LEN)){
       		iRet =  INT_INVALID_PAY_AMOUNT;
DEBUGLOG(("CheckAmt()txn_amt length too long[%s]\n",csAmt));
ERRLOG("TxnMmmByUsCOM::CheckAmt() txn_amt length too long\n");
       	}
        else{
DEBUGLOG(("CheckAmt amt in string = [%s]\n",csAmt));
       		*dTxnAmt = string2double((const unsigned char*)csAmt);
DEBUGLOG(("CheckAmt() txn_amt = [%f]\n",*dTxnAmt));
	}

/* if TWD */
        if (iRet==PD_OK) {
DEBUGLOG(("TxnMmmByUsCOM::CheckAmt() check is support decimal\n"));
		DBObjPtr = CreateObj(DBPtr,"DBCurrency","IsSupportDecimal");
               	if ((unsigned long)((DBObjPtr)(csCcy))!=PD_TRUE){
DEBUGLOG(("TxnMmmByUsCOM::CheckAmt() [%s] doesn't support decimal\n",csCcy));
			lTmp = (long) *dTxnAmt;
                       	if (*dTxnAmt > lTmp) {
                       		iRet = INT_UNSUPPORTED_PAY_AMOUNT;
ERRLOG("TxnMmmByUsCOM::CheckAmt() unsupported transaction amount [%f]\n",*dTxnAmt);
                  	}
              	}
       	}

DEBUGLOG(("CheckAmt() Normal Return iRet = [%d]\n",iRet));
	return 	iRet;
}

int GetSrcNatureId(hash_t* hContext,const hash_t* hReq)
{
	int	iRet = PD_OK;
	char	csTag[PD_TAG_LEN +1];
	char	*csTxnCcy;
	char	*csPtr;
	char	*csTxnCode;
	char	cCostCal = ' ';
	double	dCostAmt = 0.0;
	int	iBalCnt = 0,iNatureCnt = 0,i,j;
	double	dTmpAmt;
	double	dTotalAmt = 0.0;
	double	dTxnAmt = 0.0;
	double	dPercent = 0.0;
DEBUGLOG(("GetSrcNatureId ()\n"));

	if (GetField_Char(hContext,"cost_cal",&cCostCal)) {
DEBUGLOG(("GetSrcNatureId() cost_cal = [%c]\n",cCostCal));
	}

/* cost amt */
	if (GetField_Double(hContext,"cost_amt",&dCostAmt)) {
DEBUGLOG(("GetSrcNatureId() cost_amt = [%lf]\n",dCostAmt));
	}

/* txn_amt */
	if (GetField_Double(hContext,"txn_amt",&dTxnAmt)) {
DEBUGLOG(("GetSrcNatureId() txn_amt = [%lf]\n",dTxnAmt));
	}
	else {
DEBUGLOG(("GetSrcNatureId() txn_amt is missing\n"));
ERRLOG("GetSrcNatureId() txn_amt is missing\n");
		iRet = PD_ERR;
	}

	GetField_CString(hContext,"txn_code",&csTxnCode);
	GetField_CString(hContext,"txn_ccy",&csTxnCcy);
DEBUGLOG(("GetSrcNatureId() txn_ccy = [%s]\n",csTxnCcy));

	if (GetField_Int(hContext,"bal_cnt",&iBalCnt)) {
DEBUGLOG(("GetSrcNatureId() bal_cnt = [%d]\n",iBalCnt));
	}
	else {
DEBUGLOG(("GetSrcNatureId() bal_cnt not found\n"));
ERRLOG("GetSrcNatureId() bal_cnt not found\n");
		iRet = PD_ERR;
	}

	if (iRet == PD_OK) {
		double	dAffFxAmt = 0.0;
		double	dNonAffFxAmt = 0.0;
		for (i= 1; i <= iBalCnt; i++ ) {
			sprintf(csTag,"txn_data.bal.%d.nat_cnt",i);
			if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("GetSrcNatureId() [%s] = [%s]\n",csTag,csPtr));
				if (!is_numeric(csPtr))
					iRet = INT_INVALID_COUNT;
				else {
					iNatureCnt = ctos((const unsigned char*)csPtr,strlen(csPtr));
					sprintf(csTag,"bal.%d.nat_cnt",i);
DEBUGLOG(("GetSrcNatureId() [%s] = [%d]\n",csTag,iNatureCnt));
					PutField_Int(hContext,csTag,iNatureCnt);
				}
			}
/* skip check if default nature id API */
			if (strcmp(csTxnCode,PD_TXN_CODE_MMS_DEFAULT_NID)) {
				sprintf(csTag,"txn_data.bal.%d.amt",i);
				if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("GetSrcNatureId() [%s] = [%s]\n",csTag,csPtr));
					iRet =  CheckAmt(csTxnCcy,csPtr,&dTmpAmt);
					if (iRet != PD_OK)
               					PutField_Int(hContext,"internal_error",iRet);
					else  {
						sprintf(csTag,"bal.%d.amt",i);
DEBUGLOG(("GetSrcNatureId() [%s] = [%lf]\n",csTag,dTmpAmt));
               					PutField_Double(hContext,csTag,dTmpAmt);
						dTotalAmt += dTmpAmt;

						sprintf(csTag,"bal.%d.net_amt",i);
DEBUGLOG(("GetSrcNatureId() [%s] = [%lf]\n",csTag,dTmpAmt));
               					PutField_Double(hContext,csTag,dTmpAmt);
						sprintf(csTag,"bal.%d.percent",i);
						dPercent = newround((dTmpAmt / dTxnAmt),5);
               					PutField_Double(hContext,csTag,dPercent);
DEBUGLOG(("GetSrcNatureId() [%s] [%lf] of [%lf]\n",csTag,dPercent,dTxnAmt));
					}
				}
				else {
					iRet = INT_MMS_NATURE_AMT_NOT_FOUND;
				}
			}

/* aff fx amt */
			sprintf(csTag,"txn_data.bal.%d.aff_fx_amt",i);
			if (GetField_CString(hReq,csTag,&csPtr)) {
				dAffFxAmt = string2double((const unsigned char*)csPtr);
DEBUGLOG(("GetSrcNatureId() [%s] = [%s][%lf]\n",csTag,csPtr,dAffFxAmt));
			}
/* none aff fx amt */
			sprintf(csTag,"txn_data.bal.%d.non_aff_fx_amt",i);
			if (GetField_CString(hReq,csTag,&csPtr)) {
				dNonAffFxAmt = string2double((const unsigned char*)csPtr);
DEBUGLOG(("GetSrcNatureId() [%s] = [%s][%lf]\n",csTag,csPtr,dNonAffFxAmt));
			}
			sprintf(csTag,"bal.%d.aff_fx_amt",i);
			PutField_Double(hContext,csTag,dAffFxAmt);

			sprintf(csTag,"bal.%d.non_aff_fx_amt",i);
			PutField_Double(hContext,csTag,dNonAffFxAmt);
			
			
			if  (iRet == PD_OK) {
				for (j= 1; j <= iNatureCnt; j++ ) {
/* grp */
					sprintf(csTag,"txn_data.bal.%d.nat.%d.grp",i,j);
					if (GetField_CString(hReq,csTag,&csPtr)) {
//DEBUGLOG(("GetSrcNatureId() [%s] = [%s]\n",csTag,csPtr));
						sprintf(csTag,"bal.%d.nat.%d.grp",i,j);
DEBUGLOG(("GetSrcNatureId() [%s] = [%s]\n",csTag,csPtr));
						PutField_CString(hContext,csTag,csPtr);
					}
/* val */
					sprintf(csTag,"txn_data.bal.%d.nat.%d.val",i,j);
					if (GetField_CString(hReq,csTag,&csPtr)) {
//DEBUGLOG(("GetSrcNatureId() [%s] = [%s]\n",csTag,csPtr));
						sprintf(csTag,"bal.%d.nat.%d.val",i,j);
DEBUGLOG(("GetSrcNatureId() [%s] = [%s]\n",csTag,csPtr));
						PutField_CString(hContext,csTag,csPtr);
					}
				}
/* this call will return an new nature id if not found */
				BOObjPtr = CreateObj(BOPtr,"BOMMSEntityNature","FindEntityNatureId");
				iRet =	(unsigned long)(*BOObjPtr)(hContext);
				if (iRet != PD_OK) {
DEBUGLOG(("GetSrcNatureId() return from BOMMSEntityNature iRet = [%d] \n",iRet));
					break;
				}
			}
		}

	}

	if (iRet == PD_OK) {
		if (cCostCal == PD_MMS_COST_CAL_NET) {
			double 	dRemainingAmt = dCostAmt;
			double	dNatureTxnAmt = 0.0;
			for (i= 1; i <= iBalCnt; i++ ) {
				sprintf(csTag,"bal.%d.amt",i);
                                if (GetField_Double(hContext,csTag,&dNatureTxnAmt)) {	
DEBUGLOG(("GetSrcNatureId() [%s] = [%lf]\n",csTag,dNatureTxnAmt));
				}
				else {
DEBUGLOG(("GetSrcNatureId() [%s] not found\n",csTag));
ERRLOG("GetSrcNatureId() [%s] not found\n",csTag);
					iRet = PD_ERR;
					break;
				}
				sprintf(csTag,"bal.%d.percent",i);
                                if (GetField_Double(hContext,csTag,&dPercent)) {	
DEBUGLOG(("GetSrcNatureId() [%s] = [%lf]\n",csTag,dPercent));

					if (i == iBalCnt -1) {
						dTmpAmt = dRemainingAmt;
DEBUGLOG(("GetSrcNatureId() tmp amt  = [%lf] natureTxnAmt = [%lf]\n",dTmpAmt, dNatureTxnAmt));

						dNatureTxnAmt -=dTmpAmt;
DEBUGLOG(("GetSrcNatureId() new nature txn amt = [%lf] remaining amt = [%lf]\n",dTmpAmt,dRemainingAmt));
					}else {
						dTmpAmt = newround(dCostAmt * dPercent,PD_DECIMAL_LEN);
DEBUGLOG(("GetSrcNatureId() tmp amt  = [%lf]\n",dTmpAmt));
						dRemainingAmt -= dTmpAmt;
						dNatureTxnAmt -= dTmpAmt;
DEBUGLOG(("GetSrcNatureId() new nature txn amt = [%lf] remaining amt = [%lf]\n",dNatureTxnAmt,dRemainingAmt));
					}
					sprintf(csTag,"bal.%d.override_amt",i);
					PutField_Double(hContext,csTag,dNatureTxnAmt);
				}
				else {
DEBUGLOG(("GetSrcNatureId() [%s] not found\n",csTag));
ERRLOG("GetSrcNatureId() [%s] not found\n",csTag);
					iRet = PD_ERR;
					break;
				}
			}
		}
	}

	if (iRet == PD_OK) {
		if (dTxnAmt != dTotalAmt) {
DEBUGLOG(("GetSrcNatureId() txn_amt [%lf] != total nature txn amt [%lf]\n",dTxnAmt,dTotalAmt));
ERRLOG("GetSrcNatureId() txn_amt [%lf] != total nature txn amt [%lf]\n",dTxnAmt,dTotalAmt);
			iRet = INT_MMS_INVALID_AMT;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

DEBUGLOG(("GetSrcNatureId () Normal exit iRet = [%d]\n",iRet));
	return	iRet;
}

