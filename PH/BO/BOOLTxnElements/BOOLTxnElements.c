/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/28              LokMan Chow
Add void support Merchant Settlement		   2016/05/13		   Dirk Wong
Modify AddTransferAvaPOElement			   2016/07/05		   Elvis Wong	
and VoidOrgTxnElements 
(change markup element party_type for "OMI")
Add VoidDynamicMerchantElements,
    AddDynamicMerchantElement			   2016/09/26		   Dirk Wong
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
#include "BOOLTxnElements.h"
#include "queue_utility.h"
#include "mq_db.h"

char    cDebug;

OBJPTR(DB);

void BOOLTxnElements(char    cdebug)
{
        cDebug = cdebug;
}

int     AddAvaForPOElement(hash_t* hContext);
int     AddAvaForPOFeeElement(hash_t* hContext);
int     AddPspTxnElement(hash_t* hRequest);
int     AddTxnAmtElement(hash_t* hContext)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
        double  dTmp;
	char	cTmp;
	char	*csTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"from_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddTxnAmtElement:: org_txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hContext,"org_txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddTxnAmtElement:: org_txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddTxnAmtElement:: org_txn_ccy is missing!!!, skip  AddTxnAmtElement\n"));
		FREE_ME(hRec);
		return iRet;
        }

        if (GetField_Double(hContext,"org_txn_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);
                DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                PutField_CString(hRec,"txn_element_type",PD_ELEMENT_TXN_AMT);

/* party type */
		if (GetField_Char(hContext, "party_type", &cTmp)) {
	                PutField_Char(hRec,"party_type",cTmp);
DEBUGLOG(("AddTxnAmtElement:: party_type = [%c]\n",cTmp));
		} else {
	                PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);
		}

/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);

/* amount type */
		if (GetField_CString(hContext, "amount_type", &csTmp)) {
	                PutField_CString(hRec,"amount_type",csTmp);
DEBUGLOG(("AddTxnAmtElement:: amount_type = [%s]\n",csTmp));
		} else {
	                PutField_CString(hRec,"amount_type",PD_CR);
		}

                iRet = (unsigned long)(*DBObjPtr)(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddTxnAmtElement:: iRet = [%d]\n",iRet));
        return  iRet;
}




int     AddTxnFeeElements(hash_t* hContext)
{
        int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
        char    *csOrgDstTxnCcy;
        double  dTmp;
	char	cTmp;
	char	*csTmp;
	

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"from_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddTxnFeeElements:: org_txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hContext,"src_txn_fee_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddTxnFeeElements:: src_txn_fee_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG(("AddTxnFeeElements:: src_txn_fee_ccy is missing!!!, skip AddTxnFeeElements\n"));
		FREE_ME(hRec);
		return iRet;
        }

        if (GetField_CString(hContext,"dst_txn_fee_ccy",&csOrgDstTxnCcy)) {
DEBUGLOG(("AddTxnFeeElements:: dst_txn_fee_ccy= [%s]\n",csOrgDstTxnCcy));
        }
/* merchant fee */
        if (GetField_Double(hContext,"src_txn_fee",&dTmp) && iRet == PD_OK) {

                if(dTmp>0){
DEBUGLOG(("AddTxnFeeElements:: src txn fee = [%lf]\n",dTmp));

                        hash_init(hRec,0);
                        DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                        PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                        PutField_CString(hRec,"txn_element_type",PD_ELEMENT_TXN_FEE);

/* party type */
			if (GetField_Char(hContext, "party_type", &cTmp)) {
	                        PutField_Char(hRec,"party_type",cTmp);
			} else {
	                        PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);
			}

/* txn_ccy */
                        PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* fee */
                        PutField_Double(hRec,"amount",dTmp);

/* user */              PutField_CString(hRec,"add_user",PD_UPDATE_USER);

/* amount type */
			if (GetField_CString(hContext, "amount_type", &csTmp)) {
	                        PutField_CString(hRec,"amount_type",csTmp);
			} else {
	                        PutField_CString(hRec,"amount_type",PD_DR);
			}

                        iRet = (unsigned long)(*DBObjPtr)(hRec);
                        hash_destroy(hRec);
                }
        }


/* customer fee */
        if (GetField_Double(hContext,"dst_txn_fee",&dTmp) && iRet == PD_OK) {
DEBUGLOG(("AddTxnFeeElements:: dst_txn_fee = [%lf]\n",dTmp));

                if(dTmp>0){
                        hash_init(hRec,0);
                        DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                        PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                        PutField_CString(hRec,"txn_element_type",PD_ELEMENT_TXN_FEE);


/* party type */
                        PutField_Char(hRec,"party_type",PD_TYPE_CUSTOMER);

/* txn_ccy */
                        PutField_CString(hRec,"ccy",csOrgDstTxnCcy);

/* fee */
                        PutField_Double(hRec,"amount",dTmp);
/* user */              PutField_CString(hRec,"add_user",PD_UPDATE_USER);
/* amount type */
			if (GetField_CString(hContext, "amount_type", &csTmp)) {
	                        PutField_CString(hRec,"amount_type",csTmp);
			} else {
                        	PutField_CString(hRec,"amount_type",PD_DR);
			}

                        iRet = (unsigned long)(*DBObjPtr)(hRec);
                        hash_destroy(hRec);
                }
        }


        FREE_ME(hRec);
DEBUGLOG(("AddFeeTxnChgLog:: iRet = [%d]\n",iRet));
        return  iRet;
}
int     AddReserveAmtElement(hash_t* hContext)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
	char	*csTmp;
        double  dTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddReserveAmt:: org_txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hContext,"org_txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddReserveAmt:: org_txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddReserveAmt:: org_txn_ccy is missing!!!, skip  AddTxnAmtElement\n"));
		FREE_ME(hRec);
		return iRet;
        }

        if (GetField_Double(hContext,"reserve_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);
                DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                PutField_CString(hRec,"txn_element_type",PD_ELEMENT_RES_AMT);

/* party type */
                PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);

/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);

/* amount type */
		if (GetField_CString(hContext, "amount_type", &csTmp)) {
                	PutField_CString(hRec,"amount_type",csTmp);
		}
		else {
DEBUGLOG(("AddReserAmt: count not find amount_type\n"));
		}

		if (dTmp > 0.0) {
                	iRet = (unsigned long)(*DBObjPtr)(hRec);
		}
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddReserveAmt:: iRet = [%d]\n",iRet));
        return  iRet;
}


int     AddMarkupAmtElement(hash_t* hContext)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
	char	*csDstTxnCcy;
        char    *csTmp;
        double  dTmp;
	char	cTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"from_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddMarkupAmtElement:: org_txn_seq = [%s]\n",csOrgTxnSeq));
        }
/*
	if(GetField_CString(hContext,"txn_code", &csTxnCode)){
DEBUGLOG(("AddMarkupAmtElement:: txn_code = [%s]\n",csTxnCode));
	}
*/
        if (GetField_CString(hContext,"dst_txn_ccy",&csDstTxnCcy)) {
DEBUGLOG(("AddMarkupAmtElement:: Dst_txn_ccy= [%s]\n",csDstTxnCcy));
        }
        else {
DEBUGLOG((" AddMarkupAmtElement:: Dst_txn_ccy is missing!!!, skip  AddTxnAmtElement\n"));
		FREE_ME(hRec);
		return iRet;
        }

        if (GetField_Double(hContext,"markup_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);
                DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                PutField_CString(hRec,"txn_element_type",PD_ELEMENT_MARKUP_AMT);

/* party type */
		if (GetField_Char(hContext, "org_party_type", &cTmp)) {
                	PutField_Char(hRec,"party_type",cTmp);
		} else {
                	PutField_Char(hRec,"party_type",PD_TYPE_CUSTOMER);
		}

/* txn_ccy */
                PutField_CString(hRec,"ccy",csDstTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/*markup rate*/
		if(GetField_Double(hContext,"markup_rate",&dTmp)){
                	PutField_Double(hRec,"rate",dTmp);
		}


/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);

		if (GetField_CString(hContext, "amount_type", &csTmp)) {
			PutField_CString(hRec,"amount_type",csTmp);
		} else {

			//if(!strcmp(csTxnCode))
			PutField_CString(hRec,"amount_type",PD_DR);
		}

                iRet = (unsigned long)(*DBObjPtr)(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddMarkupAmtElement:: iRet = [%d]\n",iRet));
        return  iRet;
}


int     AddMerchantFloatAmtElement(hash_t* hContext)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
        double  dTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddMerchantFloatAmtElement:: org_txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hContext,"org_txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddMerchantFloatAmtElement:: org_txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddMerchantFloatAmtElement:: org_txn_ccy is missing!!!, skip  AddTxnAmtElement\n"));
		FREE_ME(hRec);
		return iRet;
        }

        if (GetField_Double(hContext,"float_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);
                DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                PutField_CString(hRec,"txn_element_type",PD_ELEMENT_FLOAT_AMT);

/* party type */
                PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);

/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);


                iRet = (unsigned long)(*DBObjPtr)(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddMerchantFloatAmtElement:: iRet = [%d]\n",iRet));
        return  iRet;
}


int     AddDynamicMerchantElement(hash_t* hContext,char* csElementType)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
	char	*csTmp = NULL;
        double  dTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddDynamicMerchantElement:: org_txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hContext,"org_txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddDynamicMerchantElement:: org_txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddDynamicMerchantElement:: org_txn_ccy is missing!!!, skip  AddTxnAmtElement\n"));
		FREE_ME(hRec);
		return iRet;
        }

        if (GetField_Double(hContext,"txn_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);
                DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                PutField_CString(hRec,"txn_element_type",csElementType);

/* party type */
                PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);

/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/* amount type */
               	if (GetField_CString(hContext, "amount_type", &csTmp)) {
                   	PutField_CString(hRec,"amount_type",csTmp);
             	} else {
                     	PutField_CString(hRec,"amount_type",PD_CR);
             	}

/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);


                iRet = (unsigned long)(*DBObjPtr)(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddDynamicMerchantElement:: iRet = [%d]\n",iRet));
        return  iRet;
}


int VoidDynamicMerchantElements(const hash_t  *hContext, const hash_t *hRequest)
{
DEBUGLOG(("VoidOrgTxnElements()\n"));
	int iRet = PD_OK;

        char    *csTmp;
        char    *csCcy;
        char    *csTxnCode;
        char    *csTxnSeq;
        char    *csOrgTxnSeq;
	char	cType;
	double	dAmt = 0.0;
	double	dRate = 0.0;
	int	iReturnFee = PD_FALSE;
	int	iReleased = PD_FALSE;
	
	hash_t	*hRec, *hTxn;
        hTxn = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hTxn,0);
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);


        if (GetField_CString(hContext,"txn_seq",&csTxnSeq)) {
DEBUGLOG(("VoidOrgTxnElements:: txn_seq = [%s]\n",csTxnSeq));
        }

        if (GetField_CString(hContext,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("VoidOrgTxnElements:: org_txn_seq = [%s]\n",csOrgTxnSeq));
        }
	
	if (GetField_CString(hRequest,"org_txn_code",&csTxnCode)) {
DEBUGLOG(("VoidOrgTxnElements:: org_txn_code = [%s]\n",csTxnCode));
	}

        if (GetField_Int(hRequest,"return_mfee",&iReturnFee)) {
DEBUGLOG(("VoidOrgTxnElements:: return_merchantfee = [%d]\n",iReturnFee));
        }

        if (GetField_Int(hContext,"reserve_released",&iReleased)) {
DEBUGLOG(("VoidOrgTxnElements::reserve_released = [%d]\n",iReleased));
        }

DEBUGLOG(("VoidOrgTxnElements:: call DBOLTxnElements:GetAllFeeChgDetail\n"));
	DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","GetAllFeeChgDetail");
	if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
		hRec = RecordSet_GetFirst(rRecordSet);
		while(hRec && (iRet == PD_OK)){
			hash_init(hTxn,0);
			if(GetField_CString(hRec,"ccy",&csCcy)){
				PutField_CString(hTxn,"org_txn_ccy",csCcy);
			}
			if(GetField_Double(hRec,"amount",&dAmt)){
				PutField_Double(hTxn,"org_txn_amt",dAmt);
			}
			if(GetField_Double(hRec,"rate",&dRate)){
				PutField_Double(hTxn,"markup_rate",dRate);
			}
			if(GetField_Char(hRec,"party_type",&cType)){
				PutField_Char(hTxn,"party_type",cType);
			}
			if(GetField_CString(hRec,"amt_type",&csTmp)){
				if(!strcmp(csTmp,PD_CR))
					PutField_CString(hTxn,"amount_type",PD_DR);
				else
					PutField_CString(hTxn,"amount_type",PD_CR);
			}

			if(cType == PD_TYPE_MERCHANT) {
				if(GetField_CString(hRec,"txn_element_type",&csTmp)) {

					if(!strcmp(csTmp,PD_ELEMENT_TXN_FEE)){
						if(iReturnFee==PD_TRUE) {
DEBUGLOG(("VoidOrgTxnElements:: call AddTxnFeeElements\n"));
                                       			PutField_Double(hTxn,"src_txn_fee",dAmt);
                               	        	        PutField_CString(hTxn,"src_txn_fee_ccy",csCcy);

							PutField_CString(hTxn,"from_txn_seq",csTxnSeq);
							//iRet = AddAvaForPOElement(hTxn);
							iRet = AddTxnFeeElements(hTxn);
						}

					}
					else if(!strcmp(csTmp,PD_ELEMENT_MFLT_AMT)){
DEBUGLOG(("VoidOrgTxnElements:: call AddDynamicMerchantElement\n"));
						PutField_CString(hTxn,"org_txn_seq",csTxnSeq);
						PutField_Double(hTxn,"txn_amt",dAmt);
						iRet = AddDynamicMerchantElement(hTxn,PD_ELEMENT_MFLT_AMT);
					}
				
					else if(!strcmp(csTmp,PD_ELEMENT_MFIN_AMT)){
DEBUGLOG(("VoidOrgTxnElements:: call AddDynamicMerchantElement\n"));
						PutField_CString(hTxn,"org_txn_seq",csTxnSeq);
						PutField_Double(hTxn,"txn_amt",dAmt);
						iRet = AddDynamicMerchantElement(hTxn,PD_ELEMENT_MFIN_AMT);
					}
					
					else if(!strcmp(csTmp,PD_ELEMENT_MPOR_AMT)){
DEBUGLOG(("VoidOrgTxnElements:: call AddDynamicMerchantElement\n"));
						PutField_CString(hTxn,"org_txn_seq",csTxnSeq);
						PutField_Double(hTxn,"txn_amt",dAmt);
						iRet = AddDynamicMerchantElement(hTxn,PD_ELEMENT_MPOR_AMT);
					}
					else{
DEBUGLOG(("VoidOrgTxnElements:: [%s]call nothing\n",csTmp));
					}
				}
			}
			hRec = RecordSet_GetNext(rRecordSet);
		}
	}
	else{
		iRet = INT_ERR;
	}

	FREE_ME(hTxn);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("VoidOrgTxnElements:: iRet = [%d]\n",iRet));
	return iRet;
}


int VoidOrgTxnElements(const hash_t  *hContext, const hash_t *hRequest)
{
DEBUGLOG(("VoidOrgTxnElements()\n"));
	int iRet = PD_OK;

        char    *csTmp;
        char    *csCcy;
        char    *csTxnCode;
        char    *csTxnSeq;
        char    *csOrgTxnSeq;
	//double	dTmp=0.0;
	//char	cTmp;
	char	cType;
	double	dAmt = 0.0;
	double	dActualPspFee = 0.0;
	double	dRate = 0.0;
	int	iReturnFee = PD_FALSE;
	int	iTmp;
	int	iAdjTxnCode = PD_FALSE;
	int	iSameDate = PD_FALSE;
	int	iReturnPspFee = PD_FALSE;
	int	iSettlement = PD_FALSE;
	int	iReleased = PD_FALSE;
	int	iOrgPspFeePresent = PD_FALSE;
        char    *csPspCcy= strdup("");
	
	hash_t	*hRec, *hTxn;
        hTxn = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hTxn,0);
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);


        if (GetField_CString(hContext,"txn_seq",&csTxnSeq)) {
DEBUGLOG(("VoidOrgTxnElements:: txn_seq = [%s]\n",csTxnSeq));
        }

        if (GetField_CString(hContext,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("VoidOrgTxnElements:: org_txn_seq = [%s]\n",csOrgTxnSeq));
        }
	
	if (GetField_CString(hRequest,"org_txn_code",&csTxnCode)) {
DEBUGLOG(("VoidOrgTxnElements:: org_txn_code = [%s]\n",csTxnCode));


		if((!strcmp(csTxnCode,PD_OL_PAYOUT_APPROVE))
		   ||(!strcmp(csTxnCode,PD_REQ_OPL_TXN_CODE))
		)
		{
        		//if (GetField_Int(hContext,"VPFEE",&iTmp)) {
//DEBUGLOG(("VoidOrgTxnElements:: return fee (For Payout Only)= [%d]\n",iTmp));
//					iReturnFee = iTmp;
//			}
        		if (GetField_Int(hContext,"same_date_cancel",&iTmp)) {
DEBUGLOG(("VoidOrgTxnElements:: same date cancel = [%d]\n",iTmp));
					iSameDate = iTmp;
			}
        	}

		if (GetField_Int(hContext, "is_adj_txn_code", &iTmp)) {
			if (iTmp == PD_TRUE) {
				iAdjTxnCode = PD_TRUE;
			}
		}

		if(!strcmp(csTxnCode,PD_OL_SETTLEMENT_REQUEST)) {
			iSettlement = PD_TRUE;
		}
	}
/*
        if (GetField_Int(hRequest,"return_pspfee",&iReturnPspFee)) {
DEBUGLOG(("VoidOrgTxnElements:: return_pspfee = [%d]\n",iReturnPspFee));
        }
	if(GetField_Double(hContext,"actual_psp_fee",&dActualPspFee)){
DEBUGLOG(("VoidOrgTxnElements:: actual_psp_fee = [%lf]\n",dActualPspFee));
	}
*/
        if (GetField_Int(hRequest,"return_mfee",&iReturnFee)) {
DEBUGLOG(("VoidOrgTxnElements:: return_merchantfee = [%d]\n",iReturnFee));
        }

        if (GetField_Int(hContext,"reserve_released",&iReleased)) {
DEBUGLOG(("VoidOrgTxnElements::reserve_released = [%d]\n",iReleased));
        }

DEBUGLOG(("VoidOrgTxnElements:: call DBOLTxnElements:GetAllFeeChgDetail\n"));
	DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","GetAllFeeChgDetail");
	if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
		hRec = RecordSet_GetFirst(rRecordSet);
		while(hRec && (iRet == PD_OK)){
			hash_init(hTxn,0);
			if(GetField_CString(hRec,"ccy",&csCcy)){
				PutField_CString(hTxn,"org_txn_ccy",csCcy);
			}
			if(GetField_Double(hRec,"amount",&dAmt)){
				PutField_Double(hTxn,"org_txn_amt",dAmt);
			}
			if(GetField_Double(hRec,"rate",&dRate)){
				PutField_Double(hTxn,"markup_rate",dRate);
			}
			if(GetField_Char(hRec,"party_type",&cType)){
				PutField_Char(hTxn,"party_type",cType);
			}
			if(GetField_CString(hRec,"amt_type",&csTmp)){
				if(!strcmp(csTmp,PD_CR))
					PutField_CString(hTxn,"amount_type",PD_DR);
				else
					PutField_CString(hTxn,"amount_type",PD_CR);
			}

			if((cType == PD_TYPE_PSP) && 
			   ((!strcmp(csTxnCode,PD_INITIAL_TXN_CODE)) || 
			    (!strcmp(csTxnCode,PD_DEPOSIT_TXN_CODE)) ||
			    (!strcmp(csTxnCode,PD_PAYOUT_GENERATE)))){
				if(GetField_CString(hRec,"txn_element_type",&csTmp)){
					PutField_CString(hTxn,"txn_element_type",csTmp);
				}
				if(strcmp(csTmp,PD_ELEMENT_TXN_FEE) || iReturnPspFee==PD_TRUE){
					PutField_CString(hTxn,"txn_seq",csTxnSeq);
					PutField_CString(hTxn,"txn_ccy",csCcy);
					sprintf(csPspCcy,"%s",csCcy);

					if(strcmp(csTmp,PD_ELEMENT_TXN_FEE))
						PutField_Double(hTxn,"txn_amt",dAmt);
					else{
						if(!strcmp(csTxnCode,PD_PAYOUT_GENERATE)){
							dActualPspFee = dAmt;
						}
						PutField_Double(hTxn,"txn_amt",dActualPspFee);
						iOrgPspFeePresent = PD_TRUE;
					}
					iRet = AddPspTxnElement(hTxn);
				}
			}
			else{
DEBUGLOG(("2222222\n"));
				if(GetField_CString(hRec,"txn_element_type",&csTmp)){
					if(!strcmp(csTmp,PD_ELEMENT_TXN_AMT)){
DEBUGLOG(("VoidOrgTxnElements:: call AddTxnAmtElement\n"));
						PutField_CString(hTxn,"from_txn_seq",csTxnSeq);
						if(iSameDate == PD_FALSE)
							iRet = AddTxnAmtElement(hTxn);
						else
							iRet = AddAvaForPOElement(hTxn); 
					}
					else if(!strcmp(csTmp,PD_ELEMENT_TXN_FEE)){
						if((iReturnFee==PD_TRUE) || 
						   (iAdjTxnCode == PD_TRUE)){ //||
						   //(iSettlement == PD_TRUE)){
DEBUGLOG(("VoidOrgTxnElements:: call AddTxnFeeElements\n"));
							if (iAdjTxnCode == PD_FALSE){
								if(cType == PD_TYPE_MERCHANT ||
								   cType == PD_TYPE_PSP){
									PutField_Double(hTxn,"src_txn_fee",dAmt);
									PutField_CString(hTxn,"src_txn_fee_ccy",csCcy);
								}
								else{
									PutField_Double(hTxn,"dst_txn_fee",dAmt);
									PutField_CString(hTxn,"dst_txn_fee_ccy",csCcy);
								}
							}
							else {
                                        			PutField_Double(hTxn,"src_txn_fee",dAmt);
	                                        	        PutField_CString(hTxn,"src_txn_fee_ccy",csCcy);
							}
							PutField_CString(hTxn,"from_txn_seq",csTxnSeq);
							if(iSameDate == PD_FALSE)
								iRet = AddTxnFeeElements(hTxn);
							else
								iRet = AddAvaForPOFeeElement(hTxn);
						}

					}
					else if(!strcmp(csTmp,PD_ELEMENT_MARKUP_AMT)){
DEBUGLOG(("VoidOrgTxnElements:: call AddMarkupAmtElement\n"));
						PutField_Double(hTxn,"markup_amt",dAmt);
						PutField_CString(hTxn,"from_txn_seq",csTxnSeq);
				
						PutField_CString(hTxn,"dst_txn_ccy",csCcy);

						if ((iSettlement == PD_TRUE)
						    || (!strcmp(csTxnCode,PD_OFL_OTH_SYS_2_MERCH_BAL_TRF))
						    || (!strcmp(csTxnCode,PD_OFL_MERCHANT_BAL_TFT))
						)
						{
							PutField_Char(hTxn,"org_party_type",PD_TYPE_MERCHANT);
						}

						iRet = AddMarkupAmtElement(hTxn);
					}
					
					//void deposit change the reserved amt before released;
					//but directly deduct from avai settlement after released;
					else if(!strcmp(csTmp,PD_ELEMENT_RES_AMT)){
DEBUGLOG(("VoidOrgTxnElements:: call AddReserveAmtElement\n"));
						if(iReleased == PD_FALSE){
							PutField_CString(hTxn,"org_txn_seq",csTxnSeq);
							PutField_Double(hTxn,"reserve_amt",dAmt);
							iRet = AddReserveAmtElement(hTxn);
						}
					}
					
					else if(!strcmp(csTmp,PD_ELEMENT_FLOAT_AMT)){
DEBUGLOG(("VoidOrgTxnElements:: call AddMerchantFloatAmtElement\n"));
						PutField_CString(hTxn,"org_txn_seq",csTxnSeq);
						PutField_Double(hTxn,"float_amt",dAmt);
						iRet = AddMerchantFloatAmtElement(hTxn);
					}
/*					
					else if(!strcmp(csTmp,PD_ELEMENT_MFLT_AMT)){
DEBUGLOG(("VoidOrgTxnElements:: call AddDynamicMerchantElement\n"));
						PutField_CString(hTxn,"org_txn_seq",csTxnSeq);
						PutField_Double(hTxn,"txn_amt",dAmt);
						iRet = AddDynamicMerchantElement(hTxn,PD_ELEMENT_MFLT_AMT);
					}
					
					else if(!strcmp(csTmp,PD_ELEMENT_MFIN_AMT)){
DEBUGLOG(("VoidOrgTxnElements:: call AddDynamicMerchantElement\n"));
						PutField_CString(hTxn,"org_txn_seq",csTxnSeq);
						PutField_Double(hTxn,"txn_amt",dAmt);
						iRet = AddDynamicMerchantElement(hTxn,PD_ELEMENT_MFIN_AMT);
					}
					
					else if(!strcmp(csTmp,PD_ELEMENT_MPOR_AMT)){
DEBUGLOG(("VoidOrgTxnElements:: call AddDynamicMerchantElement\n"));
						PutField_CString(hTxn,"org_txn_seq",csTxnSeq);
						PutField_Double(hTxn,"txn_amt",dAmt);
						iRet = AddDynamicMerchantElement(hTxn,PD_ELEMENT_MPOR_AMT);
					}
*/
					else{
DEBUGLOG(("VoidOrgTxnElements:: [%s]call nothing\n",csTmp));
					}
				}
			}
			hRec = RecordSet_GetNext(rRecordSet);
		}
		//
		if(iRet == PD_OK){
			if(iOrgPspFeePresent==PD_FALSE &&
			   iReturnPspFee==PD_TRUE &&
			   dActualPspFee > 0.0 &&
                           ((!strcmp(csTxnCode,PD_INITIAL_TXN_CODE)) ||
                            (!strcmp(csTxnCode,PD_DEPOSIT_TXN_CODE)) ||
                            (!strcmp(csTxnCode,PD_PAYOUT_GENERATE)))){
				PutField_CString(hTxn,"txn_element_type",PD_ELEMENT_TXN_FEE);
				PutField_Double(hTxn,"txn_amt",dActualPspFee);
				PutField_CString(hTxn,"txn_seq",csTxnSeq);
				PutField_CString(hTxn,"txn_ccy",csPspCcy);
				PutField_CString(hTxn,"amount_type",PD_CR);
				PutField_Char(hTxn,"party_type",PD_TYPE_PSP);

				iRet = AddPspTxnElement(hTxn);
			}
		}
	}
	else{
		iRet = INT_ERR;
	}

	FREE_ME(hTxn);
	FREE_ME(csPspCcy);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("VoidOrgTxnElements:: iRet = [%d]\n",iRet));
	return iRet;
}




int     AddHoldAmtElement(hash_t* hContext)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
        double  dTmp;
        char	cHold;
        char	cPoSt;
        char	cTmp;
	char	*csTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddHoldAmt:: txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hContext,"txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddHoldAmt:: txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddHoldAmt:: txn_ccy is missing!!!, skip  AddHoldAmtElement\n"));
		FREE_ME(hRec);
		return iRet;
        }
	if(GetField_Char(hContext,"hold_type",&cHold)){
DEBUGLOG(("AddHoldAmt:: hold_type = [%c]\n",cHold));
	}
        else {
DEBUGLOG((" AddHoldAmt:: hold_type is missing!!!, skip  AddHoldAmtElement\n"));
		FREE_ME(hRec);
		return iRet;
        }
	if(GetField_Char(hContext,"hold_po_st",&cPoSt)){
DEBUGLOG(("AddHoldAmt:: hold_po_st = [%c]\n",cPoSt));
	}
        else {
DEBUGLOG((" AddHoldAmt:: hold_po_st is missing!!!, skip  AddHoldAmtElement\n"));
		FREE_ME(hRec);
		return iRet;
        }

        if (GetField_Double(hContext,"txn_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);
                DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
		if(cHold==PD_HOLD && cPoSt==PD_TYPE_PAYOUT){
			PutField_CString(hRec,"txn_element_type",PD_ELEMENT_HOLD_PO_AMT);
		}else if(cHold==PD_HOLD && cPoSt==PD_TYPE_SETTLEMENT){
			PutField_CString(hRec,"txn_element_type",PD_ELEMENT_HOLD_AMT);
		}else if(cHold==PD_UNHOLD && cPoSt==PD_TYPE_PAYOUT){
			PutField_CString(hRec,"txn_element_type",PD_ELEMENT_UNHOLD_PO_AMT);
		}else if(cHold==PD_UNHOLD && cPoSt==PD_TYPE_SETTLEMENT){
			PutField_CString(hRec,"txn_element_type",PD_ELEMENT_UNHOLD_AMT);
		}
/* party type */
		if(GetField_Char(hContext,"party_type",&cTmp)){
DEBUGLOG(("AddHoldAmt:: party_type= [%c]\n",cTmp));
                	PutField_Char(hRec,"party_type",cTmp);
		}
		else
                	PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);

/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);

/*amount_type */
		if (GetField_CString(hContext, "amount_type", &csTmp)) {
			PutField_CString(hRec,"amount_type",csTmp);
		}

                iRet = (unsigned long)(*DBObjPtr)(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddHoldAmt:: iRet = [%d]\n",iRet));
        return  iRet;
}

int     AddTransferAmtElement(hash_t* hContext)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
        double  dTmp;
	char	cTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"from_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddTransferAmt:: from_txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hContext,"org_txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddTransferAmt:: org_txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddTransferAmt:: org_txn_ccy is missing!!!, skip  AddTxnAmtElement\n"));
		FREE_ME(hRec);
		return iRet;
        }

        if (GetField_Double(hContext,"transfer_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);
                DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                PutField_CString(hRec,"txn_element_type",PD_ELEMENT_TRF_AMT);

/* party type */
		if(GetField_Char(hContext,"party_type",&cTmp)){
			PutField_Char(hRec,"party_type",cTmp);
		}
		else
			PutField_Char(hRec,"party_type",PD_TYPE_PSP);

/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);


                iRet = (unsigned long)(*DBObjPtr)(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddTransferAmt:: iRet = [%d]\n",iRet));
        return  iRet;
}

int     AddAvaForPOElement(hash_t* hContext)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
        double  dTmp;
	char	cTmp;
	char	*csTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"from_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddAvaForPOElement:: from_txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hContext,"org_txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddAvaForPOElement:: org_txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddAvaForPOElement:: org_txn_ccy is missing!!!, skip  AddAvaForPOElement\n"));
		FREE_ME(hRec);
		return iRet;
        }

        if (GetField_Double(hContext,"org_txn_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);
                DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                PutField_CString(hRec,"txn_element_type",PD_ELEMENT_MAPO_AMT);

/* party type */
		if(GetField_Char(hContext,"party_type",&cTmp)){
			PutField_Char(hRec,"party_type",cTmp);
		}
		else
			PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);

/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/* amount type */
		if (GetField_CString(hContext, "amount_type", &csTmp)) {
	                PutField_CString(hRec,"amount_type",csTmp);
		} else {
	                PutField_CString(hRec,"amount_type",PD_CR);
		}

/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);


                iRet = (unsigned long)(*DBObjPtr)(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddAvaForPOElement:: iRet = [%d]\n",iRet));
        return  iRet;
}



int     AddAvaForPOFeeElement(hash_t* hContext)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
        double  dTmp;
	char	cTmp;
	char	*csTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"from_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddAvaForPOFeeElement:: from_txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hContext,"org_txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddAvaForPOFeeElement:: org_txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddAvaForPOFeeElement:: org_txn_ccy is missing!!!, skip  AddAvaForPOFeeElement\n"));
		FREE_ME(hRec);
		return iRet;
        }

        if (GetField_Double(hContext,"org_txn_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);
                DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                PutField_CString(hRec,"txn_element_type",PD_ELEMENT_MAPO_FEE);

/* party type */
		if(GetField_Char(hContext,"party_type",&cTmp)){
			PutField_Char(hRec,"party_type",cTmp);
		}
		else
			PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);

/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/* amount type */
		if (GetField_CString(hContext, "amount_type", &csTmp)) {
	                PutField_CString(hRec,"amount_type",csTmp);
		} else {
	                PutField_CString(hRec,"amount_type",PD_CR);
		}

/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);


                iRet = (unsigned long)(*DBObjPtr)(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddAvaForPOFeeElement:: iRet = [%d]\n",iRet));
        return  iRet;
}


int	AddTransferAvaPOElement(hash_t *hContext) 
{
	int     iRet = PD_OK;

	char    *csOrgTxnSeq;
	char    *csOrgTxnCcy;
	double  dTmp;
	char    cTmp;
	char    *csTmp;
	int	iVoidFlag = PD_FALSE;

	hash_t  *hRec;
	hRec = (hash_t*)  malloc (sizeof(hash_t));

	if (GetField_CString(hContext,"from_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddTransferAvaPOElement:: from_txn_seq = [%s]\n",csOrgTxnSeq));
	}

	if (GetField_CString(hContext,"org_txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddTransferAvaPOElement:: org_txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG(("AddTransferAvaPOElement:: org_txn_ccy is missing!!!, skip  AddTransferAvaPOElement\n"));
		FREE_ME(hRec);
		return iRet;
        }

	if (GetField_Int(hContext,"void_flag",&iVoidFlag)) {
DEBUGLOG(("AddTransferAvaPOElement:: void_flag = [%d]\n",iVoidFlag));
        }

	if (iVoidFlag == PD_FALSE) {

		// Fundin
		if (GetField_Double(hContext,"org_fundin",&dTmp) && iRet == PD_OK) {

			if (dTmp > 0.0) {
				hash_init(hRec,0);
				DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
				PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
				PutField_CString(hRec,"txn_element_type",PD_ELEMENT_MFIN_AMT);

/* party type */	
				if(GetField_Char(hContext,"party_type",&cTmp)){
                        		PutField_Char(hRec,"party_type",cTmp);
                		}
                		else
                        		PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);
/* txn_ccy */	
                		PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                		PutField_Double(hRec,"amount",dTmp);

/* amount type */
                		if (GetField_CString(hContext, "amount_type", &csTmp)) {
                	        	PutField_CString(hRec,"amount_type",csTmp);
                		} else {
                	        	PutField_CString(hRec,"amount_type",PD_CR);
                		}

/* user */      		PutField_CString(hRec,"add_user",PD_UPDATE_USER);

	        	        iRet = (unsigned long)(*DBObjPtr)(hRec);
                		hash_destroy(hRec);
			}
        	}

		// Reserved Payout
		if (GetField_Double(hContext,"org_resv_po",&dTmp) && iRet == PD_OK) {
			if (dTmp > 0.0) {
				hash_init(hRec,0);
				DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                		PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                		PutField_CString(hRec,"txn_element_type",PD_ELEMENT_MPOR_AMT);

/* party type */
                		if(GetField_Char(hContext,"party_type",&cTmp)){
                	        	PutField_Char(hRec,"party_type",cTmp);
                		}
                		else
                	        	PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);
/* txn_ccy */
                		PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                		PutField_Double(hRec,"amount",dTmp);

/* amount type */
                		if (GetField_CString(hContext, "amount_type", &csTmp)) {
                	        	PutField_CString(hRec,"amount_type",csTmp);
                		} else {
                	        	PutField_CString(hRec,"amount_type",PD_CR);
                		}

/* user */      		PutField_CString(hRec,"add_user",PD_UPDATE_USER);

                		iRet = (unsigned long)(*DBObjPtr)(hRec);
                		hash_destroy(hRec);
			}
        	}

		// Float 
		if (GetField_Double(hContext,"org_perv_float",&dTmp) && iRet == PD_OK) {
			if (dTmp > 0.0) {
				hash_init(hRec,0);
				DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                		PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                		PutField_CString(hRec,"txn_element_type",PD_ELEMENT_MFLT_AMT);

/* party type */
                		if(GetField_Char(hContext,"party_type",&cTmp)){
                	        	PutField_Char(hRec,"party_type",cTmp);
                		}
                		else
                	        	PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);
/* txn_ccy */
                		PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                		PutField_Double(hRec,"amount",dTmp);

/* amount type */
                		if (GetField_CString(hContext, "amount_type", &csTmp)) {
                	        	PutField_CString(hRec,"amount_type",csTmp);
                		} else {
                	        	PutField_CString(hRec,"amount_type",PD_CR);
                		}

/* user */      		PutField_CString(hRec,"add_user",PD_UPDATE_USER);
	
		                iRet = (unsigned long)(*DBObjPtr)(hRec);
				hash_destroy(hRec);
			}
		}
	} else {

		// Fundin
                if (GetField_Double(hContext,"org_fundin",&dTmp) && iRet == PD_OK) {

                        if (dTmp > 0.0) {
                                hash_init(hRec,0);
                                DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                                PutField_CString(hRec,"txn_element_type",PD_ELEMENT_MFIN_AMT);

/* party type */
                                if(GetField_Char(hContext,"party_type",&cTmp)){
                                        PutField_Char(hRec,"party_type",cTmp);
                                }
                                else
                                        PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);
/* txn_ccy */
                                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                                PutField_Double(hRec,"amount",dTmp);

/* amount type */
                                if (GetField_CString(hContext, "amount_type", &csTmp)) {
                                        PutField_CString(hRec,"amount_type",csTmp);
                                } else {
                                        PutField_CString(hRec,"amount_type",PD_CR);
                                }

/* user */                      PutField_CString(hRec,"add_user",PD_UPDATE_USER);

                                iRet = (unsigned long)(*DBObjPtr)(hRec);
                                hash_destroy(hRec);
                        }
                }

		// Float
                if (GetField_Double(hContext,"org_perv_float",&dTmp) && iRet == PD_OK) {
                        if (dTmp > 0.0) {
                                hash_init(hRec,0);
                                DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                                PutField_CString(hRec,"txn_element_type",PD_ELEMENT_MFLT_AMT);

/* party type */
                                if(GetField_Char(hContext,"party_type",&cTmp)){
                                        PutField_Char(hRec,"party_type",cTmp);
                                }
                                else
                                        PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);
/* txn_ccy */
                                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                                PutField_Double(hRec,"amount",dTmp);

/* amount type */
                                if (GetField_CString(hContext, "amount_type", &csTmp)) {
                                        PutField_CString(hRec,"amount_type",csTmp);
                                } else {
                                        PutField_CString(hRec,"amount_type",PD_CR);
                                }

/* user */                      PutField_CString(hRec,"add_user",PD_UPDATE_USER);

                                iRet = (unsigned long)(*DBObjPtr)(hRec);
                                hash_destroy(hRec);
                        }
                }

		// Reserved Payout
                if (GetField_Double(hContext,"org_resv_po",&dTmp) && iRet == PD_OK) {
                        if (dTmp > 0.0) {
                                hash_init(hRec,0);
                                DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                                PutField_CString(hRec,"txn_element_type",PD_ELEMENT_MPOR_AMT);

/* party type */
                                if(GetField_Char(hContext,"party_type",&cTmp)){
                                        PutField_Char(hRec,"party_type",cTmp);
                                }
                                else
                                        PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);
/* txn_ccy */
                                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                                PutField_Double(hRec,"amount",dTmp);

/* amount type */
                                if (GetField_CString(hContext, "amount_type", &csTmp)) {
                                        PutField_CString(hRec,"amount_type",csTmp);
                                } else {
                                        PutField_CString(hRec,"amount_type",PD_CR);
                                }

/* user */                      PutField_CString(hRec,"add_user",PD_UPDATE_USER);

                                iRet = (unsigned long)(*DBObjPtr)(hRec);
                                hash_destroy(hRec);
                        }
                }
	}

	FREE_ME(hRec);
DEBUGLOG(("AddTransferAvaPOElement :: iRet = [%d]\n",iRet));
        return  iRet;
}


int     AddPspTxnElement(hash_t* hRequest)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
        double  dTmp;
        char	cTmp;
	char	*csTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hRequest,"txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddPspTxnElement:: txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hRequest,"txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddPspTxnElement:: txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddPspTxnElement:: txn_ccy is missing!!!, skip  AddPspTxnElement\n"));
		FREE_ME(hRec);
		return iRet;
        }

        if (GetField_Double(hRequest,"txn_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);
                DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
		if(GetField_CString(hRequest,"txn_element_type",&csTmp)){
			PutField_CString(hRec,"txn_element_type",csTmp);
		}

/* party type */
		if(GetField_Char(hRequest,"party_type",&cTmp)){
DEBUGLOG(("AddHoldAmt:: party_type= [%c]\n",cTmp));
                	PutField_Char(hRec,"party_type",cTmp);
		}
		else
                	PutField_Char(hRec,"party_type",PD_TYPE_PSP);

/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);

/*amount_type */
		if (GetField_CString(hRequest, "amount_type", &csTmp)) {
			PutField_CString(hRec,"amount_type",csTmp);
		}

                iRet = (unsigned long)(*DBObjPtr)(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddPspTxnElement:: iRet = [%d]\n",iRet));
        return  iRet;
}

