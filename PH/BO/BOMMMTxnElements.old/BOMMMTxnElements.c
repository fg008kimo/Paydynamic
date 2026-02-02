/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/05/07              Dirk Wong  
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
#include "BOMMMTxnElements.h"

char    cDebug;
OBJPTR(DB);
OBJPTR(BO);

void BOMMMTxnElements(char    cdebug)
{
	cDebug = cdebug;
}

int     AddTxnElement(hash_t* hRequest)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
	int	iTxnDtSeq;
	char	*csNature;
        char    *csOrgTxnCcy;
        double  dTmp;
	char	*csTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hRequest,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddTxnElement:: txn_seq = [%s]\n",csOrgTxnSeq));
        }
/*
        if (GetField_Int(hRequest,"txn_dt_seq",&iTxnDtSeq)) {
DEBUGLOG(("AddTxnElement:: txn_dt_seq = [%d]\n",iTxnDtSeq));
        }
*/
        if (GetField_CString(hRequest,"nature",&csNature)) {
DEBUGLOG(("AddTxnElement:: nature = [%s]\n",csNature));
        }

        if (GetField_CString(hRequest,"txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddTxnElement:: txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddTxnElement:: txn_ccy is missing!!!, skip  AddTxnElement\n"));
		FREE_ME(hRec);
		return iRet;
        }

        if (GetField_Double(hRequest,"txn_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);
                DBObjPtr = CreateObj(DBPtr,"DBMmsTxnElement","Add");

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);
/* txn dt seq */
//		PutField_Int(hRec,"txn_dt_seq",iTxnDtSeq);
/* nature */
		PutField_CString(hRec,"nature",csNature);

/* txn_element_type */
		if(GetField_CString(hRequest,"txn_element_type",&csTmp)){
			PutField_CString(hRec,"txn_element_type",csTmp);
		}

/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);

/* amount_type */
		if (GetField_CString(hRequest, "amount_type", &csTmp)) {
			PutField_CString(hRec,"amount_type",csTmp);
		}

                iRet = (unsigned long)(*DBObjPtr)(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddTxnElement:: iRet = [%d]\n",iRet));
        return  iRet;
}
