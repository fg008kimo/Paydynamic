/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/07/18              LokMan Chow
Modify to check status before action		   2016/05/04		   Dirk Wong
Update Response					   2016/07/08		   Elvis Wong 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsVST.h"
#include "myrecordset.h"
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);

void TxnMgtByUsVST(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	char	*csTmp;

DEBUGLOG(("TxnMgtByUsVST: Authroize()\n"));

/* org_txn_seq*/	
	if (GetField_CString(hContext,"org_txn_seq",&csTmp)) {
DEBUGLOG(("org txn seq = [%s]\n",csTmp));
	}

/* remark */
        if (GetField_CString(hRequest, "remark", &csTmp)) {
DEBUGLOG(("Authorize::remark = [%s]\n",csTmp));
        } else {
DEBUGLOG(("Authorize::remark not found!!\n"));
ERRLOG("TxnMgtByUsVST::Authorize::remark not found!!\n");
                iRet = INT_REMARK_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

	// Check sub status for org txn seq 
	if(iRet==PD_OK){

/* org_sub_status */
		if (GetField_CString(hContext,"org_sub_status",&csTmp)) {
			if (!strcmp(csTmp,PD_IN_PROCESS)) {
DEBUGLOG(("Authorize:: org_sub_status = [%s]\n",csTmp));
			} else {
				iRet = INT_ERR;
DEBUGLOG(("Authorize:: INVALID org_sub_status = [%s]\n",csTmp));
ERRLOG("TxnMgtByUsVST::Authorize: INVALID org_sub_status = [%s]\n",csTmp);
			}
		} else {
DEBUGLOG(("Authorize: OrgSubStatus not found!!\n"));
ERRLOG("TxnMgtByUsVST::Authorize: OrgSubStatus not found!!\n");
			iRet = INT_ERR;
		}
	}

	// Process Void Settlement Txn
	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call BOSettlement:ProcessSettlementTxn\n"));
                BOObjPtr = CreateObj(BOPtr,"BOSettlement","ProcessSettlementTxn");
                iRet = (unsigned long) (*BOObjPtr)(hContext,hRequest,hResponse);
        }

	// Update Response
        if(iRet==PD_OK){

/* txn_seq */
                if (GetField_CString(hContext,"txn_seq",&csTmp)){
                        PutField_CString(hResponse,"org_txn_seq",csTmp);
                }
        }

	if(iRet!=PD_OK){
                PutField_Int(hContext,"internal_error",iRet);
        }

DEBUGLOG(("Normal exit iRet = [%d]\n",iRet));	
	return iRet;
}
