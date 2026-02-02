/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/07/29              Simon Fung
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsJLR.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMgtByUsJLR(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
  int     iRet = PD_OK;
	char*	csTmp = NULL;
	hash_t	*hJnlHdr;

	hJnlHdr = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hJnlHdr,0);

DEBUGLOG(("TxnMgtByUsJLR::Authorize()\n"));

		// jnl_id //
	if (GetField_CString(hRequest,"jnl_id",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLR::Authorize(): jnl_id = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"jnl_id",csTmp);
	}
	
		// update_user //
	if (GetField_CString(hRequest,"update_user",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLR::Authorize(): update_user = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"update_user",csTmp);
	}
	
	// Release Journal
	BOObjPtr = CreateObj(DBPtr,"BOCrrJnl","Release");
	iRet = (unsigned long) ((*BOObjPtr)(hJnlHdr));		

	if(iRet==PD_OK) {
DEBUGLOG(("TxnMgtByUsJLA::Authorize->Release Success\n"));		
	} else {
DEBUGLOG(("TxnMgtByUsJLA::Authorize->Release Failed\n"));	
	}
	
	if (iRet != PD_OK)
		PutField_Int(hContext,"internal_error",INT_JL_INVALID_MSG_FORMAT);	

	hash_destroy(hJnlHdr);
	FREE_ME(hJnlHdr);
DEBUGLOG(("TxnMgtByUsJLR::Authorize() Normal exit iret = [%d]\n",iRet));	
	return iRet;
}
