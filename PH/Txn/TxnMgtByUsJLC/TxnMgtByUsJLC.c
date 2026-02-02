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
#include "TxnMgtByUsJLC.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMgtByUsJLC(char    cdebug)
{
        cDebug = cdebug;
}

int Authorize(hash_t* hContext, const hash_t* hRequest, hash_t* hResponse)
{
  int     iRet = PD_OK;
	char*	csTmp = NULL;
	int	iTmp;
	char	cTmp;
	char cStatus;
	double dTxnAmt;
	hash_t	*hReq;
	hash_t  *hJnlHdr;
	char* csLineCnt = NULL;
	int iLineCnt;
	int iLineTmp;
	char csName[PD_TMP_MSG_BUF_LEN];
	int iDisabled;

	hJnlHdr = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hJnlHdr,0);

	hReq = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hReq,0);
	
	// RS for holding jnl details
	recordset_t *rsJnlDtl;
	rsJnlDtl = (recordset_t*) malloc (sizeof(recordset_t));	
	recordset_init(rsJnlDtl,0);

	recordset_t *rsBaseCcy;
	rsBaseCcy = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rsBaseCcy,0);	
	
	// Get All Base Currencies for conversion
	DBObjPtr = CreateObj(DBPtr,"DBCrrBaseCurrency","GetAllCcy");
	iRet = (unsigned long)((*DBObjPtr)(rsBaseCcy));

DEBUGLOG(("TxnMgtByUsJLC::Authorize()\n"));

  //return PD_ERR;

		// jnl_id //
	if (GetField_CString(hContext,"txn_seq",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC:: jnl_id = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"jnl_id",csTmp);	
		
		// Add to response for return
		PutField_CString(hResponse,"jnl_id",csTmp);
	} else {
		iRet = PD_ERR;
DEBUGLOG(("TxnMgtByUsJLC:: missing jnl_id\n"));
		PutField_Int(hContext,"internal_error",INT_JL_INVALID_MSG_FORMAT);
	}		
	
		// jnl_type_id //
	if (GetField_CString(hRequest,"jnl_type_id",&csTmp)) {
		iTmp = atoi(csTmp);
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): jnl_type_id = [%d]\n",iTmp));
		PutField_Int(hJnlHdr,"jnl_type_id",iTmp);
	}
		// description //
	if (GetField_CString(hRequest,"description",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): description = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"description",csTmp);
	}
		// txn_date //
	if (GetField_CString(hRequest,"txn_date",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): txn_date = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"txn_date",csTmp);
	}
		// bank_update_date //
	if (GetField_CString(hRequest,"bank_update_date",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): bank_update_date = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"bank_update_date",csTmp);
	}
	
	/*
		// acc_year //	
	if (GetField_CString(hRequest,"acc_year",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): acc_year = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"acc_year",csTmp);
	}
		// acc_month //
	if (GetField_CString(hRequest,"acc_month",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): acc_month = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"acc_month",csTmp);
	}
	*/
	
		// country_code //
	if (GetField_CString(hRequest,"country_code",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): country_code = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"country_code",csTmp);
	}
	
		// product_code //
	if (GetField_CString(hRequest,"product_code",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): product_code = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"product_code",csTmp);
	}
			
		// ref_no //
	if (GetField_CString(hRequest,"ref_no",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): ref_no = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"ref_no",csTmp);
	}
		// remarks //
	if (GetField_CString(hRequest,"remarks",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): remarks = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"remarks",csTmp);
	}
		// status //
	if (GetField_CString(hRequest,"status",&csTmp)) {
		//cTmp = (char) csTmp;
		cTmp = csTmp[0];
		cStatus = cTmp;		
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): status = [%c]\n",cTmp));
		PutField_Char(hJnlHdr,"status",cTmp);
	}
		// disabled //
	if (GetField_CString(hRequest,"disabled",&csTmp)) {
		iTmp = atoi(csTmp);
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): disabled = [%d]\n",iTmp));
		PutField_Int(hJnlHdr,"disabled",iTmp);
	}
		// create_user //
	if (GetField_CString(hRequest,"create_user",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): create_user = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"create_user",csTmp);
	}
		// update_user //
	if (GetField_CString(hRequest,"update_user",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): update_user = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"update_user",csTmp);
	}
		// approve_user //
	if (GetField_CString(hRequest,"approve_user",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): approve_user = [%s]\n",csTmp));
		PutField_CString(hReq,"approve_user",csTmp);	
	}

		// line_count //
	if (GetField_CString(hRequest,"line_count",&csLineCnt)) {
		iLineCnt = atoi(csLineCnt);
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): line_count = [%d]\n",iLineCnt));
		//PutField_Int(hReq,"line_count",iLineCnt);
	}	else {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): No Journal Detail\n"));
		iRet = PD_ERR;
		PutField_Int(hContext,"internal_error",INT_JL_INVALID_MSG_FORMAT);
	}
		
	if(iRet==PD_OK) {

		csName[0] = '\0';
		
		// Get Journal Details (multiple) //		
		for (iLineTmp=1;iLineTmp<=iLineCnt;iLineTmp++) {
			
			// Convert to string
			sprintf(csLineCnt,"%d",iLineTmp);
						
			// gl_id //
			strcpy(csName, "jd2");
			strcat(csName, "_");
			strcat(csName, csLineCnt);		
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): Getting %s \n",csName));
			if (GetField_CString(hRequest,csName,&csTmp)) {
				iTmp = atoi(csTmp);
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): %s = [%d]\n",csName, iTmp));
				PutField_Int(hReq,"gl_id",iTmp);
			}
			
				// currency_id //
			strcpy(csName, "jd3");
			strcat(csName, "_");
			strcat(csName, csLineCnt);		
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): Getting %s \n",csName));
			if (GetField_CString(hRequest,csName,&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): %s = [%s]\n",csName, csTmp));
				PutField_CString(hReq,"currency_id",csTmp);
			}
				// txn_amt //
			strcpy(csName, "jd4");
			strcat(csName, "_");
			strcat(csName, csLineCnt);		
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): Getting %s \n",csName));
			if (GetField_CString(hRequest,csName,&csTmp)) {
				dTxnAmt = atof(csTmp);
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): %s = [%f]\n",csName, dTxnAmt));
				PutField_Double(hReq,"txn_amt",dTxnAmt);
			}
				// cr_ind //
			strcpy(csName, "jd5");
			strcat(csName, "_");
			strcat(csName, csLineCnt);		
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): Getting %s \n",csName));
			if (GetField_CString(hRequest,csName,&csTmp)) {
				cTmp = csTmp[0];
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): %s = [%c]\n",csName, cTmp));
				PutField_Char(hReq,"cr_ind",cTmp);
			}

				// remarks //
			strcpy(csName, "jd6");
			strcat(csName, "_");
			strcat(csName, csLineCnt);		
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): Getting %s \n",csName));
			if (GetField_CString(hRequest,csName,&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): %s = [%s]\n",csName, csTmp));
				PutField_CString(hReq,"jd_remarks",csTmp);
			}

				// disabled //
			strcpy(csName, "jd7");
			strcat(csName, "_");
			strcat(csName, csLineCnt);		
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): Getting %s \n",csName));
			if (GetField_CString(hRequest,csName,&csTmp)) {
				iDisabled = atoi(csTmp);
DEBUGLOG(("TxnMgtByUsJLC::Authorize(): %s = [%d]\n",csName, iDisabled));
				PutField_Int(hReq,"disabled",iDisabled);
			}			
			
			RecordSet_Add(rsJnlDtl,hReq);

			hReq = (hash_t*) malloc (sizeof(hash_t));							
			hash_init(hReq,0);	
			
		} // for
		
		// Add Journal
		BOObjPtr = CreateObj(DBPtr,"BOCrrJnl","Add");
		iRet = (unsigned long) ((*BOObjPtr)(hJnlHdr, rsJnlDtl));				
		
		if(iRet==PD_OK) {
DEBUGLOG(("TxnMgtByUsJLC::CrrJnlHeader->Add Success\n"));

		} else {
DEBUGLOG(("TxnMgtByUsJLC::CrrJnlHeader->Add Failed\n"));	
		}			 					
	} else {
DEBUGLOG(("TxnMgtByUsJLC::CrrJnlHeader->Missing fields\n"));	
	}			 	

	if (iRet != PD_OK)
		PutField_Int(hContext,"internal_error",INT_JL_INVALID_MSG_FORMAT);

	RecordSet_Destroy(rsBaseCcy);
	RecordSet_Destroy(rsJnlDtl);	
	hash_destroy(hJnlHdr);
	FREE_ME(hJnlHdr);
	hash_destroy(hReq);
	FREE_ME(hReq);
	
DEBUGLOG(("TxnMgtByUsJLC::Authorize() Before exit = [%d]\n",iRet));	
	
DEBUGLOG(("TxnMgtByUsJLC::Authorize() Normal exit iret = [%d]\n",iRet));	
	return iRet;
}
