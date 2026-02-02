/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/16              Cody Chan
Changed to hash_t*
Break into the nature id			   2015/08/02		   Cody Chan
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
#include "BOMMSTxnElement.h"

char    cDebug;
OBJPTR(DB);
OBJPTR(BO);

void BOMMSTxnElement(char    cdebug)
{
	cDebug = cdebug;
}

int     AddTxnElement(hash_t *hReq)
{
	int 	iRet = PD_OK;
	int	iBalCnt = 0,i;
	hash_t	*hData;
	char	*csTxnSeq;
	char	*csPtr;
	double	dTmp;
	
DEBUGLOG(("BOMMSTxnElement::AddTxnElement ()\n"));
	hData = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hData,0);

/* txn seq */
	if (GetField_CString(hReq,"txn_seq",&csTxnSeq)) {
DEBUGLOG(("BOMMSTxnElement::AddTxnElement txn_seq = [%s]\n",csTxnSeq));
		PutField_CString(hData,"txn_id",csTxnSeq);
	}
	else {
DEBUGLOG(("BOMMSTxnElement::AddTxnElement txn_seq not found\n"));
ERRLOG("BOMMSTxnElement::AddTxnElement txn_seq not found\n");
		iRet = PD_ERR;
	}

/* entity_id */
	if (GetField_CString(hReq,"entity_id",&csPtr)) {
DEBUGLOG(("BOMMSTxnElement::AddTxnElement entity_id = [%s]\n",csPtr));
		PutField_CString(hData,"entity_id",csPtr);
	}
	else {
DEBUGLOG(("BOMMSTxnElement::AddTxnElement entity_id not found\n"));
ERRLOG("BOMMSTxnElement::AddTxnElement entity_id not found\n");
		iRet = PD_ERR;
	}

/* txn_element_type */
	if (GetField_CString(hReq,"txn_element_type",&csPtr)) {
DEBUGLOG(("BOMMSTxnElement::AddTxnElement txn_elelemt_type = [%s]\n",csPtr));
		PutField_CString(hData,"txn_element_type",csPtr);
	}

/* amt */
	if (GetField_Double(hReq,"amount",&dTmp)) {
DEBUGLOG(("BOMMSTxnElement::AddTxnElement amount = [%lf]\n",dTmp));
		if (dTmp >= 0.0)  {
			PutField_CString(hData,"amt_type",PD_CR);
			PutField_Double(hData,"amount",dTmp);
		}
		else {
			PutField_CString(hData,"amt_type",PD_DR);
			PutField_Double(hData,"amount",dTmp *(-1));
		}
	}
		
/* ccy */
	if (GetField_CString(hReq,"ccy",&csPtr)) {
DEBUGLOG(("BOMMSTxnElement::AddTxnElement elelemt_type = [%s]\n",csPtr));
		PutField_CString(hData,"ccy",csPtr);
	}
		

	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(BOPtr,"DBMmsTxnElement","Add");
       		iRet = (unsigned long)((DBObjPtr)(hData));
DEBUGLOG(("BOMMSTxnElement::AddTxnElement return from DBMmsTxnElement:Add iRet = [%d]\n",iRet));
	}

	if (iRet == PD_OK) {
		if (GetField_Int(hReq,"bal_cnt",&iBalCnt)) {
DEBUGLOG(("BOMSTxnElement::AddTxnElement bal_cnt = [%d]\n",iBalCnt));
		}
		else {
DEBUGLOG(("BOMSTxnElement::AddTxnElement bal_cnt not found\n"));
ERRLOG("BOMSTxnElement::AddTxnElement bal_cnt not found\n");
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		char	csTag[PD_TAG_LEN +1];
		for (i = 1; i <= iBalCnt;i++) {
			sprintf(csTag,"bal.%d.nature_id",i);
			if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("BOMSTxnElement::AddTxnElement [%s] = [%s]\n",csTag,csPtr));
				PutField_CString(hData,"nature_id",csPtr);
			}
			else {
DEBUGLOG(("BOMSTxnElement::AddTxnElement [%s] not found\n",csTag));
ERRLOG("BOMSTxnElement::AddTxnElement [%s] not found\n",csTag);
				iRet = PD_ERR;
				break;
			}

			sprintf(csTag,"bal.%d.element_amt",i);
			if (GetField_Double(hReq,csTag,&dTmp)) {
DEBUGLOG(("BOMSTxnElement::AddTxnElement [%s] = [%lf]\n",csTag,dTmp));
				if (dTmp >= 0.0)  {
                		        PutField_CString(hData,"amt_type",PD_CR);
                        		PutField_Double(hData,"amount",dTmp);
                		}
                		else {
                        		PutField_CString(hData,"amt_type",PD_DR);
                        		PutField_Double(hData,"amount",dTmp *(-1));
                		}
			}
			else {
DEBUGLOG(("BOMSTxnElement::AddTxnElement [%s] not found\n",csTag));
ERRLOG("BOMSTxnElement::AddTxnElement [%s] not found\n",csTag);
				iRet = PD_ERR;
				break;
			}
			if (iRet == PD_OK) {
				DBObjPtr = CreateObj(BOPtr,"DBMmsTxnElement","AddDetail");
       				iRet = (unsigned long)((DBObjPtr)(hData));
DEBUGLOG(("BOMMSTxnElement::AddTxnElement return from DBMmsTxnElement:AddDetail iRet = [%d]\n",iRet));
				if (iRet != PD_OK) {
DEBUGLOG(("BOMMSTxnElement::AddTxnElement return from DBMmsTxnElement:AddDetail iRet = [%d]\n",iRet));
ERRLOG("BOMMSTxnElement::AddTxnElement return from DBMmsTxnElement:AddDetail iRet = [%d]\n",iRet);
					break;
				}
			}
		}
	}
	
	FREE_ME(hData);
DEBUGLOG(("BOMMSTxnElement::AddTxnElement () iRet = [%d]\n",iRet));
	return iRet;	
}

