/*
PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/11/23              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOiaByUsEBB.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define  MAXIMUM_BAID_COUNT	20

static char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnOiaByUsEBB(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	i = 0;
	int	iCnt = 0;
	int	iMaxBAIDCnt = 0;
	int	iPtr = 0;
	int	iSkip = PD_FALSE;
	char	*csBAID = NULL;
	char    *csTmp = NULL;
	char	csTag[PD_TAG_LEN + 1];

	hash_t  *hBAIDBalDetails = NULL;
      	hBAIDBalDetails = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hBAIDBalDetails,0);

DEBUGLOG(("TxnOiaByUsEBB::Authorize\n"));

/* max_baid_cnt */
    	if (GetField_Int(hContext,"max_baid_cnt",&iMaxBAIDCnt)) {
DEBUGLOG(("maximum baid count [%d]\n",iMaxBAIDCnt));
     	} else {
               	iMaxBAIDCnt = MAXIMUM_BAID_COUNT;
DEBUGLOG(("maximum baid count [%d][default]\n",iMaxBAIDCnt));
      	}

/* p_list */
	if(GetField_Int(hRequest,"p_list", &iCnt)){
DEBUGLOG(("baid count [%d]\n", iCnt));

		// Check Maximum BAID Count
		if (iCnt > iMaxBAIDCnt) {
DEBUGLOG(("baid count > maximum baid count!!\n"));
                	iRet=INT_FORMAT_ERR;
                	PutField_Int(hContext,"internal_error",iRet);
		}
	} else {
DEBUGLOG(("p_list not found\n"));
ERRLOG("TxnOiaByUsEBB::Authorize::p_list not found!!\n");
	}

	if (iRet == PD_OK) {

		for(i = 0; i < iCnt; i++){
		
			if (iRet == PD_OK) {
	
				iSkip = PD_FALSE;

/* baid */
				sprintf(csTag, "p_list.%d.baid", i);
                      		if (GetField_CString(hRequest, csTag , &csBAID)) {

					//if (csBAID != NULL) {
					if (strlen(csBAID) != 0) {
                              			sprintf(csTag, "r_list.%d.baid", i);
                             			PutField_CString(hResponse, csTag, csBAID);

/* dt_err_code */
						sprintf(csTag, "r_list.%d.dt_err_code", i);
                                		if (GetField_Int(hResponse, csTag , &iPtr)) {
			        		         iSkip = PD_TRUE;
                                		}
					} else {

/* dt_err_code */
						sprintf(csTag, "r_list.%d.dt_err_code", i);
                                        	PutField_Int(hResponse, csTag, INT_BANK_ACCT_ID_NOT_FOUND);
                                		iSkip = PD_TRUE;
					}
                     		} else {

/* dt_err_code */
                                	sprintf(csTag, "r_list.%d.dt_err_code", i);
                                	if (!GetField_Int(hResponse, csTag , &iPtr)) {
						PutField_Int(hResponse, csTag, INT_BANK_ACCT_ID_NOT_FOUND);
                                	}				
			
					iSkip = PD_TRUE;
                   		}

				if(!iSkip){
DEBUGLOG(("[%d] Get Balance of baid [%s]\n", i, csBAID));

					int iTmpRet = PD_OK;
	
					hash_destroy(hBAIDBalDetails);
					hash_init(hBAIDBalDetails,0);

					BOObjPtr = CreateObj(BOPtr,"BOOLBaid","GetBAIDBalDetails");
                			iTmpRet = (unsigned long)(BOObjPtr)(csBAID,hBAIDBalDetails);
                			if (iTmpRet == PD_OK) {
DEBUGLOG(("[%d] Call BOOLBaid::GetBAIDBalDetails Success!!\n", i));

/* country */
                		      		if (GetField_CString(hBAIDBalDetails,"country_id",&csTmp)) {
DEBUGLOG(("[%d] country = [%s]\n", i, csTmp));
							sprintf(csTag, "r_list.%d.country", i);
                	        	       		PutField_CString(hResponse,csTag,csTmp);
                	        	       	}
	
/* currency */	
              		        	        if (GetField_CString(hBAIDBalDetails,"currency_id",&csTmp)) {
DEBUGLOG(("[%d] currency = [%s]\n", i, csTmp));
							sprintf(csTag, "r_list.%d.currency", i);
        	                        		PutField_CString(hResponse,csTag,csTmp);
        	                       		}

/* baid_status */
        		            		if (GetField_CString(hBAIDBalDetails,"baid_status",&csTmp)) {
DEBUGLOG(("[%d] baid_status = [%s]\n", i, csTmp));
							sprintf(csTag, "r_list.%d.baid_status", i);
                		        	     	PutField_CString(hResponse,csTag,csTmp);
                		      		}

/* baid_bal */
              	  	                	if (GetField_CString(hBAIDBalDetails,"baid_bal",&csTmp)) {
DEBUGLOG(("[%d] baid_bal = [%s]\n", i, csTmp));
							sprintf(csTag, "r_list.%d.baid_bal", i);
        	                		       	PutField_CString(hResponse,csTag,csTmp);
        	                		}

/* acct_status */
        	         	     		if (GetField_CString(hBAIDBalDetails,"bank_acct_status",&csTmp)) {
DEBUGLOG(("[%d] bank_acct_status = [%s]\n", i, csTmp));
							sprintf(csTag, "r_list.%d.acct_status", i);
        	        	        	        PutField_CString(hResponse,csTag,csTmp);
        	        	       		}

/* acct_bal */
        	        	      		if (GetField_CString(hBAIDBalDetails,"acct_bal",&csTmp)) {
DEBUGLOG(("[%d] acct_bal = [%s]\n", i, csTmp));
							sprintf(csTag, "r_list.%d.acct_bal", i);
        	        	        	        PutField_CString(hResponse,csTag,csTmp);
        	        	      		}

                			} else {
DEBUGLOG(("[%d] Call BOOLBaid::GetBAIDBalDetails Failure!!\n", i));
ERRLOG("TxnOiaByUsEBB::Authorize::Call BOOLBaid::GetBAIDBalDetails Failure!!\n");
                			} 

					if (iTmpRet == INT_ERR) {
						iRet = iTmpRet;
                	        		PutField_Int(hContext,"internal_error",iRet);
					} else {
/* dt_err_code */
DEBUGLOG(("[%d] dt_err_code = [%d]\n", i, iTmpRet));
						sprintf(csTag, "r_list.%d.dt_err_code", i);
						PutField_Int(hResponse, csTag, iTmpRet);
					}
				}
				else{
DEBUGLOG(("[%d] Skip baid [%s]\n", i, csBAID));
				}
			}
		}

	} else if (iRet == INT_FORMAT_ERR) {
	
		for(i = 0; i < iCnt; i++){	
			sprintf(csTag, "r_list.%d.dt_err_code", i);
			RemoveField_Int(hResponse,csTag);
		}
	}

	// Not Update TxnReqRef
        PutField_Int(hContext,"not_update_log",PD_TRUE);

	hash_destroy(hBAIDBalDetails);
        FREE_ME(hBAIDBalDetails);

DEBUGLOG(("TxnOiaByUsEBB Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

