/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version  					   2011/11/21		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "numutility.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUsCOM.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMmcByUsCOM(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  hash_t* hRequest,
                  hash_t* hResponse)
{
	int	iRet = PD_OK;
	char	*csPtr;
	double	dTmp;
	int	iCheck = 0;
	int	iCnt = 0;


/* txn amt */
	if(GetField_CString(hRequest,"txn_amt",&csPtr) && iRet==PD_OK){
		dTmp = string2double((const unsigned char *)csPtr);
		PutField_Double(hContext,"txn_amt",dTmp);
DEBUGLOG(("Authorize() txn_amt = [%f]\n",dTmp));
	}

/* adjustment */
	if(GetField_CString(hRequest,"adj",&csPtr) && iRet==PD_OK){
		dTmp = string2double((const unsigned char *)csPtr);
		PutField_Double(hContext,"adjustment",dTmp);
DEBUGLOG(("Authorize() adjustment = [%f]\n",dTmp));
	}

/* processing_cost */
	if(GetField_CString(hRequest,"pc",&csPtr) && iRet==PD_OK){
		dTmp = string2double((const unsigned char *)csPtr);
		PutField_Double(hContext,"processing_cost",dTmp);
DEBUGLOG(("Authorize() processing_cost = [%f]\n",dTmp));
	}

/* bank_charge */
	if(GetField_CString(hRequest,"bk_chrg",&csPtr) && iRet==PD_OK){
		dTmp = string2double((const unsigned char *)csPtr);
		PutField_Double(hContext,"bank_charge",dTmp);
DEBUGLOG(("Authorize() bank_charge = [%f]\n",dTmp));
	}

/* bank_charge_refund */
	if(GetField_CString(hRequest,"refund",&csPtr) && iRet==PD_OK){
		dTmp = string2double((const unsigned char *)csPtr);
		PutField_Double(hContext,"bank_charge_refund",dTmp);
DEBUGLOG(("Authorize() bank_charge_refund = [%f]\n",dTmp));
	}

/* exchange_rate */
	if(GetField_CString(hRequest,"rate",&csPtr) && iRet==PD_OK){
		dTmp = string2double((const unsigned char *)csPtr);
		PutField_Double(hContext,"exchange_rate",dTmp);
DEBUGLOG(("Authorize() exchange_rate = [%f]\n",dTmp));
	}

/* total cnt */
        if(GetField_CString(hRequest,"total_cnt",&csPtr) && iRet == PD_OK){
                iCheck = is_numeric(csPtr);
                if(iCheck==PD_FALSE){
                        iRet =  INT_INVALID_COUNT;
                        PutField_Int(hContext,"internal_error",INT_INVALID_PAY_AMOUNT);
                }
                else {
                        iCnt = atoi(csPtr);
DEBUGLOG(("Authorize() total_cnt = [%d]\n",iCnt));
                        PutField_Int(hContext,"total_cnt",iCnt);
                }
        }

/* total src cnt */
        if(GetField_CString(hRequest,"s_total_cnt",&csPtr) && iRet == PD_OK){
                iCheck = is_numeric(csPtr);
                if(iCheck==PD_FALSE){
                        iRet =  INT_INVALID_COUNT;
                        PutField_Int(hContext,"internal_error",INT_INVALID_PAY_AMOUNT);
                }
                else {
                        iCnt = atoi(csPtr);
DEBUGLOG(("Authorize() total_src_cnt = [%d]\n",iCnt));
                        PutField_Int(hContext,"total_src_cnt",iCnt);
                }
        }

/* total dst cnt */
        if(GetField_CString(hRequest,"d_total_cnt",&csPtr) && iRet == PD_OK){
                iCheck = is_numeric(csPtr);
                if(iCheck==PD_FALSE){
                        iRet =  INT_INVALID_COUNT;
                        PutField_Int(hContext,"internal_error",INT_INVALID_PAY_AMOUNT);
                }
                else {
                        iCnt = atoi(csPtr);
DEBUGLOG(("Authorize() total_dst_cnt = [%d]\n",iCnt));
                        PutField_Int(hContext,"total_dst_cnt",iCnt);
                }
        }


DEBUGLOG(("Authorize() iRet = [%d]\n",iRet));
	return iRet;
}
