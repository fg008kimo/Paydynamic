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
#include "TxnMgtByUsJLU.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMgtByUsJLU(char    cdebug)
{
        cDebug = cdebug;
}

int Authorize(hash_t* hContext, const hash_t* hRequest, hash_t* hResponse)
{
  int     iRet = PD_OK;
	char*	csTmp = NULL;
	int	iTmp;
	char	cTmp;
	double dTxnAmt;
	hash_t	*hReq;
	hash_t  *hJnlHdr;
	char* csLineCnt = NULL;
	int iLineCnt;
	int iLineTmp;
	char csName[PD_TMP_MSG_BUF_LEN];
	char	cDBAction;
	char*	csJnlNo = NULL;
	int iLineNo;
	char* csTxnCcy;
	int iDisabled;
	char* csUpdateUser;

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

DEBUGLOG(("TxnMgtByUsJLU::Authorize()\n"));

		// jnl_id //
	if (GetField_CString(hRequest,"jnl_id",&csJnlNo)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): jnl_id = [%s]\n",csJnlNo));
		PutField_CString(hJnlHdr,"jnl_id",csJnlNo);
	}
		// jnl_type_id //
	if (GetField_CString(hRequest,"jnl_type_id",&csTmp)) {
		iTmp = atoi(csTmp);
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): jnl_type_id = [%d]\n",iTmp));
		PutField_Int(hJnlHdr,"jnl_type_id",iTmp);
	}
		// description //
	if (GetField_CString(hRequest,"description",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): description = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"description",csTmp);
	}
		// txn_date //
	if (GetField_CString(hRequest,"txn_date",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): txn_date = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"txn_date",csTmp);
	}
		// bank_update_date //
	if (GetField_CString(hRequest,"bank_update_date",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): bank_update_date = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"bank_update_date",csTmp);
	}
	/*
		// acc_year //
	if (GetField_CString(hRequest,"acc_year",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): acc_year = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"acc_year",csTmp);
	}
	
		// acc_month //
	if (GetField_CString(hRequest,"acc_month",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): acc_month = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"acc_month",csTmp);
	}
	*/
	
		// country_code //
	if (GetField_CString(hRequest,"country_code",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): country_code = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"country_code",csTmp);
	}
	
		// product_code //
	if (GetField_CString(hRequest,"product_code",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): product_code = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"product_code",csTmp);
	}
	
		// ref_no //
	if (GetField_CString(hRequest,"ref_no",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): ref_no = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"ref_no",csTmp);
	}
		// remarks //
	if (GetField_CString(hRequest,"remarks",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): remarks = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"remarks",csTmp);
	}
		// status //
	if (GetField_CString(hRequest,"status",&csTmp)) {
		//cTmp = (char) csTmp;
		cTmp = csTmp[0];
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): status = [%c]\n",cTmp));
		PutField_Char(hJnlHdr,"status",cTmp);
	}
		// disabled //
	if (GetField_CString(hRequest,"disabled",&csTmp)) {
		iTmp = atoi(csTmp);
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): disabled = [%d]\n",iTmp));
		PutField_Int(hJnlHdr,"disabled",iTmp);
	}
		// create_user //
	if (GetField_CString(hRequest,"create_user",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): create_user = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"create_user",csTmp);
	}
		// update_user //
	if (GetField_CString(hRequest,"update_user",&csUpdateUser)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): update_user = [%s]\n",csUpdateUser));
		PutField_CString(hJnlHdr,"update_user",csUpdateUser);
	}
		// approve_user //
	if (GetField_CString(hRequest,"approve_user",&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): approve_user = [%s]\n",csTmp));
		PutField_CString(hJnlHdr,"approve_user",csTmp);
	}

		// line_count //
	if (GetField_CString(hRequest,"line_count",&csLineCnt)) {
		iLineCnt = atoi(csLineCnt);
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): line_count = [%d]\n",iLineCnt));
		//PutField_Int(hReq,"line_count",iLineCnt);
	}	else {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): No Journal Detail\n"));
		iRet = PD_ERR;
	}
	
		
	if(iRet==PD_OK) {
		
		strcpy(csName,""); 
					
		// Get Journal Details (multiple) //		
		for (iLineTmp=1;iLineTmp<=iLineCnt;iLineTmp++) {
			
			// Convert to string
			sprintf(csLineCnt,"%d",iLineTmp);
			
			// Concat the parameter name
			// line_no //
			strcpy(csName, "jd1");
			strcat(csName, "_");
			strcat(csName, csLineCnt);
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): Getting %s \n",csName));
			if (GetField_CString(hRequest,csName,&csTmp)) {
				iLineNo = atoi(csTmp);
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): %s = [%d]\n",csName, iLineNo));
				PutField_Int(hReq,"line_no",iLineNo);
			} else {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): Line No not found\n"));
				iRet = PD_ERR;		
				break;			
			}					

			// Get Remaining details
			// gl_id //
			strcpy(csName, "jd2");
			strcat(csName, "_");
			strcat(csName, csLineCnt);		
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): Getting %s \n",csName));
			if (GetField_CString(hRequest,csName,&csTmp)) {
				iTmp = atoi(csTmp);
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): %s = [%d]\n",csName, iTmp));
				PutField_Int(hReq,"gl_id",iTmp);
			}
			
				// currency_id //
			strcpy(csName, "jd3");
			strcat(csName, "_");
			strcat(csName, csLineCnt);		
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): Getting %s \n",csName));
			if (GetField_CString(hRequest,csName,&csTxnCcy)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): %s = [%s]\n",csName, csTxnCcy));
				PutField_CString(hReq,"currency_id",csTxnCcy);
			}
				// txn_amt //
			strcpy(csName, "jd4");
			strcat(csName, "_");
			strcat(csName, csLineCnt);		
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): Getting %s \n",csName));
			if (GetField_CString(hRequest,csName,&csTmp)) {
				dTxnAmt = atof(csTmp);
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): %s = [%f]\n",csName, dTxnAmt));
				PutField_Double(hReq,"txn_amt",dTxnAmt);
			}
				// cr_ind //
			strcpy(csName, "jd5");
			strcat(csName, "_");
			strcat(csName, csLineCnt);		
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): Getting %s \n",csName));
			if (GetField_CString(hRequest,csName,&csTmp)) {
				cTmp = csTmp[0];
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): %s = [%c]\n",csName, cTmp));
				PutField_Char(hReq,"cr_ind",cTmp);
			}

				// remarks //
			strcpy(csName, "jd6");
			strcat(csName, "_");
			strcat(csName, csLineCnt);		
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): Getting %s \n",csName));
			if (GetField_CString(hRequest,csName,&csTmp)) {
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): %s = [%s]\n",csName, csTmp));
				PutField_CString(hReq,"jd_remarks",csTmp);
			}

				// disabled //
			strcpy(csName, "jd7");
			strcat(csName, "_");
			strcat(csName, csLineCnt);		
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): Getting %s \n",csName));
			if (GetField_CString(hRequest,csName,&csTmp)) {
				iDisabled = atoi(csTmp);
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): %s = [%d]\n",csName, iDisabled));
				PutField_Int(hReq,"disabled",iDisabled);
			}			

				// dbaction //
			strcpy(csName, "jd8");
			strcat(csName, "_");
			strcat(csName, csLineCnt);		
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): Getting %s \n",csName));					
			if (GetField_CString(hRequest,csName,&csTmp)) {
				cDBAction = csTmp[0];
DEBUGLOG(("TxnMgtByUsJLU::Authorize(): %s = [%c]\n",csName, cDBAction));
				PutField_Char(hReq,"dbaction",cDBAction);
			}
										
			RecordSet_Add(rsJnlDtl,hReq);

			hReq = (hash_t*) malloc (sizeof(hash_t));							
			hash_init(hReq,0);	
			
			if(iRet!=PD_OK) {
DEBUGLOG(("TxnMgtByUsJLU::CrrJnlDetail->Update Failed\n"));
				break;
			}
			
DEBUGLOG(("TxnMgtByUsJLU::CrrJnlDetail->Update Success\n"));
	
		} // for

		// Update Journal
		BOObjPtr = CreateObj(DBPtr,"BOCrrJnl","Update");
		iRet = (unsigned long) ((*BOObjPtr)(hJnlHdr, rsJnlDtl));					

		if(iRet==PD_OK) {
DEBUGLOG(("TxnMgtByUsJLC::CrrJnlHeader->Update Success\n"));

		} else {
DEBUGLOG(("TxnMgtByUsJLC::CrrJnlHeader->Update Failed\n"));	
		}	
			
	} else {
DEBUGLOG(("TxnMgtByUsJLU::CrrJnlHeader->Update Failed\n"));	
	}	


	if (iRet != PD_OK)
		PutField_Int(hContext,"internal_error",INT_JL_INVALID_MSG_FORMAT);

	hash_destroy(hReq);
	FREE_ME(hReq);
	RecordSet_Destroy(rsBaseCcy);
	
DEBUGLOG(("TxnMgtByUsJLU::Authorize() Normal exit iret = [%d]\n",iRet));	
	return iRet;
}
