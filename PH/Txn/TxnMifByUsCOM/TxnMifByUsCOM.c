/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/10              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMifByUsCOM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(Txn);
OBJPTR(DB);

void TxnMifByUsCOM(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	int	iIsACRBank = PD_FALSE;
	char	*csTmp = NULL;
	char	*csEntityId = NULL;
	char	*csEntityType = NULL;
	char	*csProductCode = NULL;

	hash_t  *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);
DEBUGLOG(("Authorize\n")); 

	//**Add more checking if needed**//
	
	

//entity_id (get entity_type and other info)
	if(GetField_CString(hRequest,"entity_id",&csEntityId)){
DEBUGLOG(("TxnMinByUsCOM() entity_id = [%s]\n",csEntityId));

		if(!GetField_CString(hContext,"entity_type",&csEntityType)){
			DBObjPtr = CreateObj(DBPtr,"DBMiEntityDetail","GetEntityType");
			if((unsigned long)((DBObjPtr)(csEntityId,hTxn)) == PD_FOUND){
				if(GetField_CString(hTxn,"entity_type",&csEntityType)){
					PutField_CString(hContext,"entity_type",csEntityType);
DEBUGLOG(("TxnMinByUsCOM() entity_type = [%s]\n",csEntityType));
				}
			}
			else {
				iRet = INT_MI_ENTITY_TYPE_NOT_FOUND;
DEBUGLOG(("TxnMinByUsCOM() entity_type not found\n"));
ERRLOG("TxnMinByUsCOM() entity_type not found\n");
			}
		}

		if(iRet == PD_OK){
			if(!strcmp(csEntityType,PD_MI_ENTITY_OPBANK)){
				DBObjPtr = CreateObj(DBPtr,"DBMiEntityOpb","GetOPBInfoByEntityId");
				iRet = (unsigned long)(*DBObjPtr)(csEntityId,hTxn);
				if(iRet == PD_OK){
					if(GetField_CString(hTxn,"bank_id",&csTmp)){
						PutField_CString(hContext,"bank_id",csTmp);
						PutField_CString(hContext,"party_id",csTmp);
DEBUGLOG(("TxnMinByUsCOM() bank_id = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"opb_name",&csTmp)){
						PutField_CString(hContext,"opb_name",csTmp);
DEBUGLOG(("TxnMinByUsCOM() opb_name = [%s]\n",csTmp));
					}
					if(GetField_Int(hTxn,"is_acr_bank",&iIsACRBank)){
						PutField_Int(hContext,"is_acr_bank",iIsACRBank);
DEBUGLOG(("TxnMinByUsCOM() is_acr_bank = [%d]\n",iIsACRBank));
					}
					if(GetField_CString(hTxn,"status",&csTmp)){
						PutField_CString(hContext,"entity_status",csTmp);
DEBUGLOG(("TxnMinByUsCOM() status = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"base_ccy",&csTmp)){
						PutField_CString(hContext,"bank_base_ccy",csTmp);
DEBUGLOG(("TxnMinByUsCOM() base_ccy = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"bal_status",&csTmp)){
						PutField_CString(hContext,"entity_bal_acct_status",csTmp);
DEBUGLOG(("TxnMinByUsCOM() balance acct status = [%s]\n",csTmp));
					}
				}
			}
			else if(!strcmp(csEntityType,PD_MI_ENTITY_RSP)){
				DBObjPtr = CreateObj(DBPtr,"DBMiEntityRsp","GetRSPInfoByEntityId");
				iRet = (unsigned long)(*DBObjPtr)(csEntityId,hTxn);
				if(iRet == PD_OK){
					if(GetField_CString(hTxn,"rsp_id",&csTmp)){
						PutField_CString(hContext,"rsp_id",csTmp);
						PutField_CString(hContext,"party_id",csTmp);
DEBUGLOG(("TxnMinByUsCOM() rsp_id = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"rsp_name",&csTmp)){
						PutField_CString(hContext,"rsp_name",csTmp);
DEBUGLOG(("TxnMinByUsCOM() rsp_name = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"node_id",&csTmp)){
						PutField_CString(hContext,"rsp_node_id",csTmp);
DEBUGLOG(("TxnMinByUsCOM() rsp_node_id = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"status",&csTmp)){
						PutField_CString(hContext,"entity_status",csTmp);
DEBUGLOG(("TxnMinByUsCOM() status = [%s]\n",csTmp));
					}
				}
			}
			else if(!strcmp(csEntityType,PD_MI_ENTITY_PSP_INTR)){
				DBObjPtr = CreateObj(DBPtr,"DBMiEntityPit","GetPITInfoByEntityId");
				iRet = (unsigned long)(*DBObjPtr)(csEntityId,hTxn);
				if(iRet == PD_OK){
					if(GetField_CString(hTxn,"pit_id",&csTmp)){
						PutField_CString(hContext,"pit_id",csTmp);
						PutField_CString(hContext,"party_id",csTmp);
DEBUGLOG(("TxnMinByUsCOM() pit_id = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"pit_name",&csTmp)){
						PutField_CString(hContext,"pit_name",csTmp);
DEBUGLOG(("TxnMinByUsCOM() pit_name = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"product_code",&csTmp)){
						if(!GetField_CString(hContext,"product_code",&csProductCode)){
							PutField_CString(hContext,"product_code",csTmp);
						}
DEBUGLOG(("TxnMinByUsCOM() product_code = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"status",&csTmp)){
						PutField_CString(hContext,"entity_status",csTmp);
DEBUGLOG(("TxnMinByUsCOM() status = [%s]\n",csTmp));
					}
				}
			}
		}
	}



DEBUGLOG(("TxnMifByUsCOM Normal Exit() iRet = [%d]\n",iRet));
	
	FREE_ME(hTxn);	
        return iRet;
}
