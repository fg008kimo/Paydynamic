/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/02/21              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUs2ALP.h"
#include "myrecordset.h"
#include "mq_db.h"
#include "mydb.h"
#include "queue_utility.h"
#include "dbutility.h"

char cDebug;
OBJPTR(Msg);
OBJPTR(DB);

void TxnWebOnUs2ALP(char    cdebug)
{
        cDebug = cdebug;
}

int     AddALPTxnLog(hash_t *hContext,
                const hash_t* hRequest);

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
	int iRet = PD_OK;
	iRet = AddALPTxnLog(hContext,hRequest);
	return iRet;
}

int     AddALPTxnLog(hash_t *hContext,
                const hash_t* hRequest)
{
        int iRet = PD_OK;
        hash_t  *hPspDetail;
        char*   csTmp;
        double  dTmp;
        
        hPspDetail = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hPspDetail,0);
        
        PutField_CString(hPspDetail,"add_user",PD_UPDATE_USER);
/* txn_seq  */
        if (GetField_CString(hContext,"txn_seq",&csTmp)) { 
DEBUGLOG(("AddALPTxnLog:: txn_seq = [%s]\n",csTmp));
                PutField_CString(hPspDetail,"txn_seq",csTmp);
        }
/* psp id */
        if (GetField_CString(hContext,"psp_id",&csTmp)) {
DEBUGLOG(("AddALPTxnLog:: psp_id = [%s]\n",csTmp));
                PutField_CString(hPspDetail,"psp_id",csTmp);
        }       
                
/* txn amt*/
        if (GetField_Double(hContext,"txn_amt",&dTmp)) {
DEBUGLOG(("AddALPTxnLog:: txn_amt = [%f]\n",dTmp));
                PutField_Double(hPspDetail,"txn_amt",dTmp);
       }
/* txn_ccy*/
       if (GetField_CString(hRequest,"txn_ccy",&csTmp)) {
DEBUGLOG(("AddALPTxnLog:: txn_ccy = [%s]\n",csTmp));
                PutField_CString(hPspDetail,"txn_ccy",csTmp);
       }                
                
/* txn_desc */
       if (GetField_CString(hContext,"txn_desc",&csTmp)) {
DEBUGLOG(("AddALPTxnLog:: txn_desc = [%s]\n",csTmp));
                PutField_CString(hPspDetail,"desc",csTmp);
        }
        DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
        iRet = (unsigned long)(*DBObjPtr)(hPspDetail);

        hash_destroy(hPspDetail);
        FREE_ME(hPspDetail);

        return iRet;
};

