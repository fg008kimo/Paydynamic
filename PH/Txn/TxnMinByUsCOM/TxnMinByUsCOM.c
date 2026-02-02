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
#include "TxnMinByUsCOM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(Txn);
OBJPTR(DB);

int ValidateAmount(const char* csStringAmt, const char* csTag, hash_t* hContext);

void TxnMinByUsCOM(char    cdebug)
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
	char	*csToEntityId = NULL;
	char	*csToEntityType = NULL;
	char	csTag[PD_TAG_LEN+1];

	hash_t  *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);
DEBUGLOG(("Authorize\n")); 

	//**Add more checking if needed**//
	
	

//**entity_id**// (get entity_type and other info)
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
					if(GetField_CString(hTxn,"base_country",&csTmp)){
                                                PutField_CString(hContext,"bank_base_country",csTmp);
DEBUGLOG(("TxnMinByUsCOM() base_country = [%s]\n",csTmp));
                                        }
					if(GetField_CString(hTxn,"bal_status",&csTmp)){
						PutField_CString(hContext,"entity_bal_acct_status",csTmp);
DEBUGLOG(("TxnMinByUsCOM() balance acct status = [%s]\n",csTmp));
					}
				}
				else{
					iRet = INT_ERR;
DEBUGLOG(("TxnMinByUsCOM() DBMiEntityOpb:GetOPBInfoByEntityId Failed!!!\n"));
ERRLOG("TxnMinByUsCOM() DBMiEntityOpb:GetOPBInfoByEntityId Failed!!!\n");
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
				else{
					iRet = INT_ERR;
DEBUGLOG(("TxnMinByUsCOM() DBMiEntityRsp:GetRSPInfoByEntityId Failed!!!\n"));
ERRLOG("TxnMinByUsCOM() DBMiEntityRsp:GetRSPInfoByEntityId Failed!!!\n");
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
				else{
					iRet = INT_ERR;
DEBUGLOG(("TxnMinByUsCOM() DBMiEntityPit:GetPITInfoByEntityId Failed!!!\n"));
ERRLOG("TxnMinByUsCOM() DBMiEntityPit:GetPITInfoByEntityId Failed!!!\n");
				}
			}
		}
	}



//**to_entity_id**// (get entity_type and other info)
	if(GetField_CString(hRequest,"to_entity_id",&csToEntityId)){
DEBUGLOG(("TxnMinByUsCOM() to_entity_id = [%s]\n",csToEntityId));

		if(!GetField_CString(hContext,"to_entity_type",&csToEntityType)){
			DBObjPtr = CreateObj(DBPtr,"DBMiEntityDetail","GetEntityType");
			if((unsigned long)((DBObjPtr)(csToEntityId,hTxn)) == PD_FOUND){
				if(GetField_CString(hTxn,"entity_type",&csToEntityType)){
					PutField_CString(hContext,"to_entity_type",csToEntityType);
DEBUGLOG(("TxnMinByUsCOM() to_entity_type = [%s]\n",csToEntityType));
				}
			}
			else {
				iRet = INT_MI_ENTITY_TYPE_NOT_FOUND;
DEBUGLOG(("TxnMinByUsCOM() to_entity_type not found\n"));
ERRLOG("TxnMinByUsCOM() to_entity_type not found\n");
			}
		}

		if(iRet == PD_OK){
			if(!strcmp(csToEntityType,PD_MI_ENTITY_OPBANK)){
				DBObjPtr = CreateObj(DBPtr,"DBMiEntityOpb","GetOPBInfoByEntityId");
				iRet = (unsigned long)(*DBObjPtr)(csToEntityId,hTxn);
				if(iRet == PD_OK){
					if(GetField_CString(hTxn,"bank_id",&csTmp)){
						PutField_CString(hContext,"to_bank_id",csTmp);
						PutField_CString(hContext,"to_party_id",csTmp);
DEBUGLOG(("TxnMinByUsCOM() to_bank_id = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"opb_name",&csTmp)){
						PutField_CString(hContext,"to_opb_name",csTmp);
DEBUGLOG(("TxnMinByUsCOM() to_opb_name = [%s]\n",csTmp));
					}
					if(GetField_Int(hTxn,"is_acr_bank",&iIsACRBank)){
						PutField_Int(hContext,"to_is_acr_bank",iIsACRBank);
DEBUGLOG(("TxnMinByUsCOM() to_is_acr_bank = [%d]\n",iIsACRBank));
					}
					if(GetField_CString(hTxn,"status",&csTmp)){
						PutField_CString(hContext,"to_entity_status",csTmp);
DEBUGLOG(("TxnMinByUsCOM() to_status = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"base_ccy",&csTmp)){
						PutField_CString(hContext,"to_bank_base_ccy",csTmp);
DEBUGLOG(("TxnMinByUsCOM() to_base_ccy = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"base_country",&csTmp)){
                                                PutField_CString(hContext,"to_bank_base_country",csTmp);
DEBUGLOG(("TxnMinByUsCOM() to_base_country = [%s]\n",csTmp));
                                        }
					if(GetField_CString(hTxn,"bal_status",&csTmp)){
						PutField_CString(hContext,"to_entity_bal_acct_status",csTmp);
DEBUGLOG(("TxnMinByUsCOM() to_balance acct status = [%s]\n",csTmp));
					}
				}
				else{
					iRet = INT_ERR;
DEBUGLOG(("TxnMinByUsCOM() DBMiEntityOpb:GetOPBInfoByEntityId Failed!!!\n"));
ERRLOG("TxnMinByUsCOM() DBMiEntityOpb:GetOPBInfoByEntityId Failed!!!\n");
				}
			}
			else if(!strcmp(csToEntityType,PD_MI_ENTITY_RSP)){
				DBObjPtr = CreateObj(DBPtr,"DBMiEntityRsp","GetRSPInfoByEntityId");
				iRet = (unsigned long)(*DBObjPtr)(csToEntityId,hTxn);
				if(iRet == PD_OK){
					if(GetField_CString(hTxn,"rsp_id",&csTmp)){
						PutField_CString(hContext,"to_rsp_id",csTmp);
						PutField_CString(hContext,"to_party_id",csTmp);
DEBUGLOG(("TxnMinByUsCOM() to_rsp_id = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"rsp_name",&csTmp)){
						PutField_CString(hContext,"to_rsp_name",csTmp);
DEBUGLOG(("TxnMinByUsCOM() to_rsp_name = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"node_id",&csTmp)){
						PutField_CString(hContext,"to_rsp_node_id",csTmp);
DEBUGLOG(("TxnMinByUsCOM() to_rsp_node_id = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"status",&csTmp)){
						PutField_CString(hContext,"to_entity_status",csTmp);
DEBUGLOG(("TxnMinByUsCOM() to_status = [%s]\n",csTmp));
					}
				}
				else{
					iRet = INT_ERR;
DEBUGLOG(("TxnMinByUsCOM() DBMiEntityRsp:GetRSPInfoByEntityId Failed!!!\n"));
ERRLOG("TxnMinByUsCOM() DBMiEntityRsp:GetRSPInfoByEntityId Failed!!!\n");
				}
			}
			else if(!strcmp(csToEntityType,PD_MI_ENTITY_PSP_INTR)){
				DBObjPtr = CreateObj(DBPtr,"DBMiEntityPit","GetPITInfoByEntityId");
				iRet = (unsigned long)(*DBObjPtr)(csToEntityId,hTxn);
				if(iRet == PD_OK){
					if(GetField_CString(hTxn,"pit_id",&csTmp)){
						PutField_CString(hContext,"to_pit_id",csTmp);
						PutField_CString(hContext,"to_party_id",csTmp);
DEBUGLOG(("TxnMinByUsCOM() to_pit_id = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"pit_name",&csTmp)){
						PutField_CString(hContext,"to_pit_name",csTmp);
DEBUGLOG(("TxnMinByUsCOM() to_pit_name = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"product_code",&csTmp)){
						if(!GetField_CString(hContext,"to_product_code",&csProductCode)){
							PutField_CString(hContext,"to_product_code",csTmp);
						}
DEBUGLOG(("TxnMinByUsCOM() to_product_code = [%s]\n",csTmp));
					}
					if(GetField_CString(hTxn,"status",&csTmp)){
						PutField_CString(hContext,"to_entity_status",csTmp);
DEBUGLOG(("TxnMinByUsCOM() to_status = [%s]\n",csTmp));
					}
				}
				else{
					iRet = INT_ERR;
DEBUGLOG(("TxnMinByUsCOM() DBMiEntityPit:GetPITInfoByEntityId Failed!!!\n"));
ERRLOG("TxnMinByUsCOM() DBMiEntityPit:GetPITInfoByEntityId Failed!!!\n");
				}
			}
		}
	}


//**fr_txnamt**//
	sprintf(csTag,"fr_txnamt");
	if(GetField_CString(hRequest,csTag,&csTmp)){
		iRet = ValidateAmount(csTmp,csTag,hContext);
	}

//**to_txnamt**//
	sprintf(csTag,"to_txnamt");
	if(GetField_CString(hRequest,csTag,&csTmp)){
		iRet = ValidateAmount(csTmp,csTag,hContext);
	}

//**remit_rate**//
	sprintf(csTag,"remit_rate");
	if(GetField_CString(hRequest,csTag,&csTmp)){
		PutField_Int(hContext,"allow_value_zero",PD_TRUE);
		iRet = ValidateAmount(csTmp,csTag,hContext);
	}

//**cost_rate**//
	sprintf(csTag,"cost_rate");
	if(GetField_CString(hRequest,csTag,&csTmp)){
		PutField_Int(hContext,"allow_value_zero",PD_TRUE);
		iRet = ValidateAmount(csTmp,csTag,hContext);
	}

//**cost_amt**//
	sprintf(csTag,"cost_amt");
	if(GetField_CString(hRequest,csTag,&csTmp)){
		PutField_Int(hContext,"allow_value_zero",PD_TRUE);
		iRet = ValidateAmount(csTmp,csTag,hContext);
	}

//**to_cost_amt**//
	sprintf(csTag,"to_cost_amt");
	if(GetField_CString(hRequest,csTag,&csTmp)){
		PutField_Int(hContext,"allow_value_zero",PD_TRUE);
		iRet = ValidateAmount(csTmp,csTag,hContext);
	}
//**cvt_amt**//
	sprintf(csTag,"cvt_amt");
	if(GetField_CString(hRequest,csTag,&csTmp)){
		iRet = ValidateAmount(csTmp,csTag,hContext);
	}


DEBUGLOG(("TxnMinByUsCOM Normal Exit() iRet = [%d]\n",iRet));

	FREE_ME(hTxn);	
        return iRet;
}



int ValidateAmount(const char* csStringAmt, const char* csTag, hash_t* hContext)
{
	int	iRet = PD_OK;
	int	iAllowZero = PD_FALSE;
	double	dAmt = 0.0;

	GetField_Int(hContext,"allow_value_zero",&iAllowZero);

	dAmt = string2double((const unsigned char *)csStringAmt);

	if(dAmt>0.0 || (dAmt == 0.0 && iAllowZero)){
		PutField_Double(hContext,csTag,dAmt);
DEBUGLOG(("ValidateAmount: %s = [%f]\n",csTag,dAmt));
	}
	else{
		iRet =  INT_INVALID_PAY_AMOUNT;
DEBUGLOG(("ValidateAmount() %s Invalid[%s]\n",csTag,csStringAmt));
ERRLOG("TxnMinByUsCOM::ValidateAmount() %s Invalid[%s]\n",csTag,csStringAmt);
	}

	RemoveField_Int(hContext,"allow_value_zero");
	return iRet;
}
