/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/06/22              Cody Chan

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "eod_glutility.h"


void append_node(NODE *NPtr, const char* csTxnCode, const char* csCountry,const char* csId, const char* csService,const char* csTxnType,const char cType,const char* csCcy,double dAmt);
void delete_node(NODE *NPtr, const char* csTxnCode, const char* csCountry,const char* csId, const char* csService,const char* csTxnType,const char cType,const char* csCcy);
NODE* search_value(NODE *NPtr, const char* csTxnCode, const char* csCountry,const char* csId, const char* csService,const char* csTxnType,const char cType,const char* csCcy);

int GenSQL(const char* csTxnDate,
		data_t *data,
		unsigned char* csSQL) 
{
	char*	csBuf;
	int	iRet = PD_OK;

	csBuf = (char*) malloc ( PD_TMP_BUF_LEN  +1);
	if (strlen(csSQL) != 0) {
		sprintf(csBuf,"\nunion\n");
		strcat(csSQL,csBuf);
	}

 	strcat(csSQL,"select th_txn_id,");
 	strcat(csSQL,"\n");
        //strcat(csSQL,"th_txn_code,");
        strcat(csSQL,"decode(th_txn_code,'DSI','DSP',th_txn_code) as th_txn_code,");
 	strcat(csSQL,"\n");
        strcat(csSQL,"td_txn_country,");
 	strcat(csSQL,"\n");
        strcat(csSQL,"th_merchant_id,");
 	strcat(csSQL,"\n");
        strcat(csSQL,"sm_product_code,");
 	strcat(csSQL,"\n");
        strcat(csSQL,"tp_psp_id,");

/* txn type */
	sprintf(csBuf,"'%s' as TXN_TYPE,\n",data->type);
	strcat(csSQL,csBuf);

/* ccy */
	sprintf(csBuf,"%s as ccy,\n",data->ccyname);
	strcat(csSQL,csBuf);

/* amt */
	sprintf(csBuf,"%s as amount\n",data->amtname);
	strcat(csSQL,csBuf);

  	strcat(csSQL,"from txn_header, ");
 	strcat(csSQL,"\n");
        strcat(csSQL,"txn_detail, ");
 	strcat(csSQL,"\n");
        strcat(csSQL,"service_mapping, ");
 	strcat(csSQL,"\n");
        strcat(csSQL,"txn_psp_detail ");
 	strcat(csSQL,"\n");
	if (strlen(data->chargetype) > 0) {
        	strcat(csSQL,",txn_fee_charge ");
 		strcat(csSQL,"\n");
	}
/* approval date */
	sprintf(csBuf,"where th_approval_date ='%s'\n ",csTxnDate);
	strcat(csSQL,csBuf);

        strcat(csSQL,"and th_txn_id = td_txn_id ");
 	strcat(csSQL,"\n");
    	strcat(csSQL,"and th_txn_id = tp_txn_id ");
 	strcat(csSQL,"\n");
    	strcat(csSQL,"and th_txn_code in ('DSI','DSP')");
 	strcat(csSQL,"\n");

	if (strlen(data->chargetype) > 0) {
    		strcat(csSQL,"and th_txn_id = tf_txn_id ");
 		strcat(csSQL,"\n");
    		sprintf(csBuf,"and tf_chg_type = '%s' \n",data->chargetype);
 		strcat(csSQL,csBuf);
    		sprintf(csBuf,"and tf_party_type = '%c' ",data->custtype);
 		strcat(csSQL,csBuf);
	}
    	strcat(csSQL,"and th_service_code = sm_code");
 	strcat(csSQL,"\n");
	
	FREE_ME(csBuf);
	return	iRet;
}

int GroupRecs( NODE *NPtr,
		const char* csTxnCode,
                const char* csCountry,
                const char* csMerchantId,
                const char* csPspId,
		const char* csService,
                const char* csTxnType,
                const char* csCcy,
                double  dAmt)
{
	int	iRet = PD_OK;
	char	*csTxn;


/* DSP */
	if (!strcmp(csTxnCode,PD_DEPOSIT_TXN_CODE) || !strcmp(csTxnCode,PD_INITIAL_TXN_CODE)) {
		csTxn = strdup(PD_INITIAL_TXN_CODE);
	}
	else 
		csTxn = strdup(csTxnCode);

	if (!strcmp(csTxnType,PD_TYPE_PSP_AMT) ||
            !strcmp(csTxnType,PD_TYPE_PSP_FEE)) {
		insert_node(NPtr,csTxnCode,csCountry,csPspId,csService,csTxnType,PD_TYPE_PSP,csCcy,dAmt);
	}
	else if (!strcmp(csTxnType,PD_TYPE_NET_AMT) ||
		 !strcmp(csTxnType,PD_TYPE_TXN_AMT)) {
		insert_node(NPtr,csTxnCode,csCountry,csMerchantId,csService,csTxnType,PD_TYPE_MERCHANT,csCcy,dAmt);
	}	
	else {
		insert_node(NPtr,csTxnCode,csCountry,PD_SYS_PARTY_ID,csService,csTxnType,PD_TYPE_GLOBAL,csCcy,dAmt);
	}
	FREE_ME(csTxn);
	return iRet;
}



void append_node(NODE *NPtr, const char* csTxnCode, const char* csCountry,const char* csId, const char* csService,const char* csTxnType,const char cType,const char* csCcy,double dAmt)
{
	while(NPtr->next != NULL)
  		NPtr = NPtr->next;

 	NPtr->next = (NODE *)malloc(sizeof(NODE));
 	NPtr->next->txncode = strdup(csTxnCode);
 	NPtr->next->country = strdup(csCountry);
 	NPtr->next->id = strdup(csId);
 	NPtr->next->service = strdup(csService);
 	NPtr->next->txntype = strdup(csTxnType);
 	NPtr->next->type = cType;
 	NPtr->next->ccy = strdup(csCcy);
 	NPtr->next->amt = dAmt;
 	NPtr->next->next = NULL;
}


void delete_node(NODE *NPtr, const char* csTxnCode, const char* csCountry,const char* csId, const char* csService,const char* csTxnType,const char cType,const char* csCcy) {

	NODE *temp;
 	temp = (NODE *)malloc(sizeof(NODE));

 	if(!strcmp(NPtr->txncode,csTxnCode) &&
	   !strcmp(NPtr->country,csCountry) &&
	   !strcmp(NPtr->id,csId) &&
	   !strcmp(NPtr->service,csService) &&
	   !strcmp(NPtr->txntype,csTxnType) &&
           NPtr->type == cType &&
           !strcmp(NPtr->ccy,csCcy)
		) {
  		temp = NPtr->next;
  		free(NPtr);
  		NPtr = temp;
 	} else {
  		while(strcmp(NPtr->next->txncode,csTxnCode) ||
		      strcmp(NPtr->next->country,csCountry) ||
                      strcmp(NPtr->next->id,csId) ||
	   	      strcmp(NPtr->next->service,csService) ||
	   	      strcmp(NPtr->next->txntype,csTxnType) ||
		      NPtr->next->type != cType ||
		      strcmp(NPtr->next->ccy,csCcy)) {
   			NPtr = NPtr->next;
		}

  		temp = NPtr->next->next;
  		free(NPtr->next);
  		NPtr->next = temp;
	 }   
}



NODE* search_value(NODE *NPtr, const char* csTxnCode, const char* csCountry,const char* csId, const char* csService,const char* csTxnType,const char cType,const char* csCcy) {
	NODE *p;

	p = NPtr;
 	while(p->next != NULL) {
  		if(!strcmp(p->next->txncode,csTxnCode) &&
	   		!strcmp(p->next->country,csCountry) &&
           		!strcmp(p->next->id,csId) &&
           		!strcmp(p->next->service,csService) &&
           		!strcmp(p->next->txntype,csTxnType) &&
           		p->next->type == cType &&
           		!strcmp(p->next->ccy,csCcy))  {
   			return p->next;
		}
  		p = p->next;
 	}

	return NULL;
}

void insert_node(NODE *NPtr, const char* csTxnCode, const char* csCountry,const char* csId, const char* csService,const char* csTxnType,const char cType,const char* csCcy,double dAmt)
{
	NODE *p;
	double dTmp = dAmt;
	p = search_value(NPtr, csTxnCode,csCountry,csId,csService,csTxnType,cType,csCcy);
	if (p != NULL) {
		dTmp += p->amt;
		delete_node(NPtr,csTxnCode,csCountry,csId,csService,csTxnType,cType,csCcy);
		append_node(NPtr,csTxnCode,csCountry,csId,csService,csTxnType,cType,csCcy,dTmp);
	}
	else  {
		append_node(NPtr,csTxnCode,csCountry,csId,csService,csTxnType,cType,csCcy,dTmp);
	}
}
