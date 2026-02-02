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
#include "TxnMgtByUsJLP.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(BO);

void TxnMgtByUsJLP(char    cdebug)
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

DEBUGLOG(("TxnMgtByUsJLP::Authorize()\n"));

		// tb_year //
	if (GetField_CString(hRequest,"tb_year",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLP::Authorize(): tb_year = [%s]\n",csTmp));
		PutField_CString(hReq,"tb_year",csTmp);
	}

		// tb_month //
	if (GetField_CString(hRequest,"tb_month",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLP::Authorize(): tb_month = [%s]\n",csTmp));
		PutField_CString(hReq,"tb_month",csTmp);
	}
	
		// post_user //
	if (GetField_CString(hRequest,"post_user",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLP::Authorize(): post_user = [%s]\n",csTmp));
		PutField_CString(hReq,"post_user",csTmp);
	}
	
	// Book the journal for closing month
	BOObjPtr = CreateObj(BOPtr,"BOCrrMonthEnd","PostJournal");
	iRet = (unsigned long)(*BOObjPtr)(hContext, hReq);

	if(iRet==PD_OK) {
DEBUGLOG(("TxnMgtByUsJLP::CrrMonthEnd->Post Success\n"));		
	} else {
DEBUGLOG(("TxnMgtByUsJLP::CrrMonthEnd->Post Failed\n"));	
	}

	if (iRet != PD_OK)
		PutField_Int(hContext,"internal_error",INT_JL_INVALID_MSG_FORMAT);

	hash_destroy(hReq);
	FREE_ME(hReq);
DEBUGLOG(("TxnMgtByUsJLP::Authorize() Normal exit iret = [%d]\n",iRet));	
	return iRet;
}
