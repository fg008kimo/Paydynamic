/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2020/08/13              [ANC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsAXX.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug = 'Y';
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsAXX(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
	hash_t* hRequest,
	hash_t* hResponse)
{
	int iRet = PD_OK;

	char	*csTmp;
	char	*csBankCode;
	char	cTmp;
	int	iTmp;
	double 	dTmp;
	//long	lTmp;
	//int	iRemarkNull = PD_FALSE;
	//char	cAction;

	hash_t  *hTestAndy = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTestAndy, 0);

	hash_t  *hTestAndy_ori = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTestAndy_ori, 0);

DEBUGLOG(("Authorize\n"));

	/*bank_code*/
	if (GetField_CString(hRequest,"bank_code",&csBankCode)) {
DEBUGLOG(("Authorize::bank_code = [%s]\n", csBankCode));
		PutField_CString(hTestAndy,"bank_code",csBankCode);
	} 
	else {
DEBUGLOG(("Authorize::bank_code not found!!\n"));
ERRLOG("TxnMgtByUsAXX::Authorize::bank_code not found!!\n");
		iRet=INT_BANK_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	/*type*/
	if(GetField_CString(hRequest,"type",&csTmp)){
		if(strlen(csTmp)!=1){
DEBUGLOG(("Authorize::input type is out of length\n"));
			iRet = INT_ERR; 
			PutField_Int(hContext,"internal_error",iRet);
		}else{
			cTmp = csTmp[0];
			if((cTmp >= 97 && cTmp <= 122) || (cTmp >= 65 && cTmp <= 90)){ /*check the ASCII value*/
DEBUGLOG(("Authorize::type= [%c]\n",cTmp));
				PutField_Char(hTestAndy,"type",cTmp);
			}else{
DEBUGLOG(("Authorize::type is not a alphabet\n"));
				iRet = INT_ERR; 
				PutField_Int(hContext,"internal_error",iRet);
			}			
		}
	}else{
DEBUGLOG(("Authorize::input type can not be null\n"));
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);		
	}

	/*support_po*/ 
	if(GetField_CString(hRequest,"support_po",&csTmp)){
		iTmp = atoi(csTmp);
DEBUGLOG(("Authorize::support_po = [%d]\n",iTmp));
		PutField_Int(hTestAndy,"support_po",iTmp);
	}else{ /*default value*/
		iTmp = 0;
DEBUGLOG(("Authorize::support_po = [%d]\n",iTmp));
		PutField_Int(hTestAndy,"support_po",iTmp);
	}

	/*min_amt*/
	if(GetField_CString(hRequest,"min_amt",&csTmp)){
		dTmp = string2double((const unsigned char *)csTmp);
DEBUGLOG(("Authorize::min_amt = [%lf]\n", dTmp));
		PutField_Double(hTestAndy, "min_amt", dTmp);
	}else{ /*default value*/
		dTmp = 0.0;
DEBUGLOG(("Authorize::min_amt = [%lf]\n", dTmp));
		PutField_Double(hTestAndy, "min_amt", dTmp);
	}

	/*remark*/
	if(GetField_CString(hRequest,"remark",&csTmp)){
DEBUGLOG(("Authorize::remark = [%s]\n",csTmp));
		PutField_CString(hTestAndy,"remark",csTmp);
	}

	/*create_user*/
	if(GetField_CString(hRequest,"create_user",&csTmp)){
DEBUGLOG(("Authorize::create_user = [%s]\n",csTmp));
		PutField_CString(hTestAndy,"create_user",csTmp);
	}else{ /*default value*/
		sprintf(csTmp,"SYSTEM");
DEBUGLOG(("Authorize::create_user = [%s]\n",csTmp));
		PutField_CString(hTestAndy,"create_user",csTmp);		
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBTestAndy:GetByBankCode\n"));		
		DBObjPtr = CreateObj(DBPtr,"DBTestAndy","GetByBankCode");
		if((unsigned long)((*DBObjPtr)(csBankCode, hTestAndy_ori) != PD_OK)){		
DEBUGLOG(("Authorize::Call DBTestAndy:Add\n"));
            		DBObjPtr = CreateObj(DBPtr,"DBTestAndy","Add");
	        	if((unsigned long)((*DBObjPtr)(hTestAndy) != PD_OK)){
DEBUGLOG(("Authorize::DBTestAndy:Add Failed\n"));
ERRLOG("TxnMgtByUsAXX::Authorize::DBTestAndy:Add Failed\n");
       	        		iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
			}else
DEBUGLOG(("Authorize::DBTestAndy:Add Success\n"));				
		}else{
DEBUGLOG(("Authorize::Call DBTestAndy:Update\n"));
			DBObjPtr = CreateObj(DBPtr,"DBTestAndy","Update");
			if((unsigned long)((*DBObjPtr)(hTestAndy) != PD_OK)){
DEBUGLOG(("Authorize::DBTestAndy:Update Failed\n"));
ERRLOG("TxnMgtByUsAXX::Authorize::DBTestAndy:Update Failed\n");
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
			}else
DEBUGLOG(("Authorize::DBTestAndy:Update Success\n"));
		}
	}

	hash_destroy(hTestAndy);
	FREE_ME(hTestAndy);

	hash_destroy(hTestAndy_ori);
	FREE_ME(hTestAndy_ori);

DEBUGLOG(("TxnMgtByUsAXX Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
