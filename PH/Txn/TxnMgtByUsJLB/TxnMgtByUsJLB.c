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
#include "TxnMgtByUsJLB.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(BO);

void TxnMgtByUsJLB(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
  int     iRet = PD_OK;
	char*	csTmp = NULL;
	hash_t	*hReq;

	hReq = (hash_t*) malloc (sizeof(hash_t));

	hash_init(hReq,0);

DEBUGLOG(("TxnMgtByUsJLB::Authorize()\n"));

	// txn_date //
	if (GetField_CString(hRequest,"txn_date",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLB::Authorize(): txn_date = [%s]\n",csTmp));
		PutField_CString(hReq,"txn_date",csTmp);
	}
	
	// country_code //
	if (GetField_CString(hRequest,"country_code",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLB::Authorize(): country_code = [%s]\n",csTmp));
		PutField_CString(hReq,"country_code",csTmp);
	}
	
	// product_code //
	if (GetField_CString(hRequest,"product_code",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLB::Authorize(): product_code = [%s]\n",csTmp));
		PutField_CString(hReq,"product_code",csTmp);
	}

	// jnl_type_id //
	if (GetField_CString(hRequest,"jnl_type_id",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLB::Authorize(): jnl_type_id = [%s]\n",csTmp));
		PutField_CString(hReq,"jnl_type_id",csTmp);
	}

	// post_user //
	if (GetField_CString(hRequest,"post_user",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLB::Authorize(): post_user = [%s]\n",csTmp));
		PutField_CString(hReq,"post_user",csTmp);
	}
	
	// Build the journal
	BOObjPtr = CreateObj(BOPtr,"BOCrrJnl","Build");
	iRet = (unsigned long)(*BOObjPtr)(hReq);
	
	if(iRet==PD_OK) {
DEBUGLOG(("TxnMgtByUsJLB::Authorize(): Build Success\n"));		
	} else {
DEBUGLOG(("TxnMgtByUsJLB::Authorize(): Build Failed\n"));	
	}

	if (iRet != PD_OK)
		PutField_Int(hContext,"internal_error",INT_JL_INVALID_MSG_FORMAT);

	hash_destroy(hReq);
	FREE_ME(hReq);
DEBUGLOG(("TxnMgtByUsJLB::Authorize() Normal exit iret = [%d]\n",iRet));	
	return iRet;
}
