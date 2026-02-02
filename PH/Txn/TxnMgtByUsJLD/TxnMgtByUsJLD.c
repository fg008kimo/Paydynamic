/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/05/18              Simon Fung
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsJLD.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMgtByUsJLD(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
  int     iRet = PD_OK;
	hash_t	*hJnlHdr;
	char*	csJnlId;
	char* csUpdateUser;

	hJnlHdr = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hJnlHdr,0);

DEBUGLOG(("TxnMgtByUsJLD::Authorize()\n"));

		// jnl_id //
	if (GetField_CString(hRequest,"jnl_id",&csJnlId)) {
DEBUGLOG(("TxnMgtByUsJLD::Authorize(): jnl_id = [%s]\n",csJnlId));
		PutField_CString(hJnlHdr,"jnl_id",csJnlId);
	}
		// update_user //
	if (GetField_CString(hRequest,"update_user",&csUpdateUser)) {
DEBUGLOG(("TxnMgtByUsJLD::Authorize(): update_user = [%s]\n",csUpdateUser));
		PutField_CString(hJnlHdr,"update_user",csUpdateUser);
	}
			
	// Delete Journal Header
	BOObjPtr = CreateObj(DBPtr,"BOCrrJnl","Delete");
	iRet = (unsigned long) ((*BOObjPtr)(hJnlHdr));		

	if(iRet==PD_OK) {		
DEBUGLOG(("TxnMgtByUsJLD::CrrJnlHeader->Delete Success\n"));
	} else {
DEBUGLOG(("TxnMgtByUsJLD::CrrJnlHeader->Delete Failed\n"));	
	}			 	

	if (iRet != PD_OK)
		PutField_Int(hContext,"internal_error",INT_JL_INVALID_MSG_FORMAT);

	hash_destroy(hJnlHdr);
	FREE_ME(hJnlHdr);
DEBUGLOG(("TxnMgtByUsJLD::Authorize() Normal exit iret = [%d]\n",iRet));	
	return iRet;
}
