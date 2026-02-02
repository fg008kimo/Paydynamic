/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/09/22              Elvis Wong
Add sender_baid_name, 
    recipient_baid_name
    and client name       			   2014/12/29              Elvis Wong
Change mask_skip to skip			   2015/01/27		   Elvis Wong
Change to get edit info from DB                    2015/07/23              David Wong
Change Get Record Data length                      2015/12/15              Elvis Wong
*/

#define		PD_DETAIL_TAG  		"dt"
#define       	PD_ORDER_TAG   		"order"

#define	      	PD_KEY_TAGNAME_HD_FILE_ID		1
#define	      	PD_KEY_TAGNAME_HD_SEQ			2
#define	      	PD_KEY_TAGNAME_HD_VER			3

#define	      	PD_TAGNAME_HD_STATEMENT_DATE		1
#define	      	PD_TAGNAME_HD_STATEMENT_TIME		2
#define	      	PD_TAGNAME_HD_TFR_BANK_NAME		3
#define	      	PD_TAGNAME_HD_TFR_ACCT_NUM		4
#define	      	PD_TAGNAME_HD_TFR_TYPE			5
#define	      	PD_TAGNAME_HD_TFR_CHANNEL		6
#define	      	PD_TAGNAME_HD_TFR_TEXT			7
#define	      	PD_TAGNAME_HD_TFR_CUSTOMER_TEXT		8
#define	      	PD_TAGNAME_HD_TFR_SENDER_NAME		9
#define	      	PD_TAGNAME_HD_TXN_REF_NUM		10
#define	      	PD_TAGNAME_HD_BALANCE			11
#define	      	PD_TAGNAME_HD_AMT_TYPE			12
#define	      	PD_TAGNAME_HD_TXN_AMOUNT		13
#define	      	PD_TAGNAME_HD_BANK_CHARGE		14
#define	      	PD_TAGNAME_HD_SKIP			15
#define	      	PD_TAGNAME_HD_SENDER_BAID_NAME		16
#define	      	PD_TAGNAME_HD_RECIPIENT_BAID_NAME	17
#define	      	PD_TAGNAME_HD_CLIENT_NAME		18

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsBSE.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnOmtByUsBSE(char cdebug)
{
	cDebug = cdebug;
}

int GetKeyTagName(int iHeader, char *csTagName)
{
        int     iRet = PD_OK;

        if (iHeader == PD_KEY_TAGNAME_HD_FILE_ID) {
/* file_id */
		sprintf(csTagName, "file_id");
	} else if (iHeader == PD_KEY_TAGNAME_HD_SEQ) {
/* seq */
		sprintf(csTagName, "seq");
	} else if (iHeader == PD_KEY_TAGNAME_HD_VER) {
/* ver */
		sprintf(csTagName, "ver");
	} else {
                sprintf(csTagName, "%s", "\0");
        }
//DEBUGLOG(("GetKeyTagName() iHeader = [%d], csTagName = [%s]\n",iHeader,csTagName));

        return iRet;
}

int GetSubDataTagName(int iHeader, char *csTagName)
{
	int	iRet = PD_OK;

	if (iHeader == PD_TAGNAME_HD_STATEMENT_DATE) {
/* statement_date */
		sprintf(csTagName, "statement_date");	
	} else if (iHeader == PD_TAGNAME_HD_STATEMENT_TIME) {	
/* statement_time */
		sprintf(csTagName, "statement_time");	
	} else if (iHeader == PD_TAGNAME_HD_TFR_BANK_NAME) {   
/* tfr_bank_name */
                sprintf(csTagName, "tfr_bank_name");
        } else if (iHeader == PD_TAGNAME_HD_TFR_ACCT_NUM) {   
/* tfr_bank_acct_num */
                sprintf(csTagName, "tfr_bank_acct_num");
        } else if (iHeader == PD_TAGNAME_HD_TFR_TYPE) {   
/* tfr_type */
                sprintf(csTagName, "tfr_type");
        } else if (iHeader == PD_TAGNAME_HD_TFR_CHANNEL) {   
/* tfr_channel */
                sprintf(csTagName, "tfr_channel");
        } else if (iHeader == PD_TAGNAME_HD_TFR_TEXT) {   
/* tfr_text */
                sprintf(csTagName, "tfr_text");
        } else if (iHeader == PD_TAGNAME_HD_TFR_CUSTOMER_TEXT) {   
/* tfr_customer_text */
                sprintf(csTagName, "tfr_customer_text");
        } else if (iHeader == PD_TAGNAME_HD_TFR_SENDER_NAME) {   
/* tfr_sender_name */
                sprintf(csTagName, "tfr_sender_name");
        } else if (iHeader == PD_TAGNAME_HD_TXN_REF_NUM) {   
/* txn_ref_num */
                sprintf(csTagName, "txn_ref_num");
        } else if (iHeader == PD_TAGNAME_HD_BALANCE) {  
/* balance */
                sprintf(csTagName, "balance"); 
        } else if (iHeader == PD_TAGNAME_HD_AMT_TYPE) {  
/* amt_type */
                sprintf(csTagName, "amt_type"); 
        } else if (iHeader == PD_TAGNAME_HD_TXN_AMOUNT) {   
/* txn_amount */
                sprintf(csTagName, "txn_amount");
        } else if (iHeader == PD_TAGNAME_HD_BANK_CHARGE) {   
/* bank_charge */
                sprintf(csTagName, "bank_charge");
        } else if (iHeader == PD_TAGNAME_HD_SKIP) {   
/* skip */
                sprintf(csTagName, "skip");
	} else if (iHeader == PD_TAGNAME_HD_SENDER_BAID_NAME) {
/* sender_baid_name */
		sprintf(csTagName, "sender_baid_name");
	} else if (iHeader == PD_TAGNAME_HD_RECIPIENT_BAID_NAME) {
/* recipient_baid_name */
                sprintf(csTagName, "recipient_baid_name");
	} else if (iHeader == PD_TAGNAME_HD_CLIENT_NAME) {
/* client_name */
                sprintf(csTagName, "client_name");
        } else {
		sprintf(csTagName, "%s", "\0");
   	}
//DEBUGLOG(("GetSubDataTagName() iHeader = [%d], csTagName = [%s]\n",iHeader,csTagName));
	
	return iRet;
}

int GetStatementRecordData(const hash_t* hInput, hash_t* hOutput)
{
	int     iRet = PD_OK;

	char 	cAction;

	int     i = 0;
        int     iIdx = 0;
        int     iCnt = 0;

	int	iTmp = 0;
	char    *csTmp;
	
	char    csTag[PD_TAG_LEN + 1];
	char    csTagName[PD_TAG_LEN + 1];

	char    *csData;
        char    *csDataCode;
        int     iDataCodeLen = 0;

	char    *csKey;
        char    *csKeyCode;
        int     iKeyCodeLen = 0;
	
	csData = (char*) malloc (16392);
        csDataCode = (char*) malloc (16392);

	csKey = (char*) malloc (6144);
        csKeyCode = (char*) malloc (6144);

/* total_cnt */
        if (GetField_CString(hInput, "cnt", &csTmp)) {
DEBUGLOG(("GetStatementRecordData() total_cnt = [%s]\n", csTmp));
                iCnt = atoi(csTmp);
        } else {
                iRet = INT_ERR;
DEBUGLOG(("GetStatementRecordData() total_cnt NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsBSE::GetStatementRecordData() total_cnt NOT FOUND!!!\n");
        }

	if (iRet == PD_OK) {

                for (i = 0; i < iCnt; i++) {
DEBUGLOG(("GetStatementRecordData() hInput::cnt = [%d]\n", i));

/*------------------------------------------------------Get Data String------------------------------------------------------*/
			sprintf(csTag, "%s_i_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hInput, csTag, &csData)) {
DEBUGLOG(("GetStatementRecordData() data = [%s]\n", csData));

				iDataCodeLen = 0;
	
/* action */
				sprintf(csDataCode,"%s",&csData[iDataCodeLen]);
                                if (csDataCode[0] == PD_BANK_STATEMENT_DATA_DELIMIT_SYMBOL_CHECK)
                                {
					iDataCodeLen++;

                                        sprintf(csDataCode,"%s","\0");
                                } else {
                                        strtok(csDataCode,PD_BANK_STATEMENT_DATA_DELIMIT_SYMBOL);
                                        iDataCodeLen += (strlen(csDataCode) + 1);
					
					sprintf(csTag, "%s_action_%d", PD_DETAIL_TAG, i+1);
                                        PutField_CString(hOutput,csTag,csDataCode);
				
					cAction = csDataCode[0];	
					PutField_Char(hOutput,"action",cAction);
                                }
DEBUGLOG(("GetStatementRecordData() action = [%s]\n",csDataCode));

/* key (file_id_seq_ver) */
                                sprintf(csDataCode,"%s",&csData[iDataCodeLen]);
                                if (csDataCode[0] == PD_BANK_STATEMENT_DATA_DELIMIT_SYMBOL_CHECK)
                                {
                                        iDataCodeLen++;

					sprintf(csDataCode,"%s","\0");
DEBUGLOG(("GetStatementRecordData() key = [%s]\n",csDataCode));
                                } else {
                                        strtok(csDataCode,PD_BANK_STATEMENT_DATA_DELIMIT_SYMBOL);
					iDataCodeLen += (strlen(csDataCode) + 1);
					
					sprintf(csTag, "%s_key_%d", PD_DETAIL_TAG, i+1);
                                        PutField_CString(hOutput,csTag,csDataCode);
DEBUGLOG(("GetStatementRecordData() key = [%s]\n",csDataCode));

/*--------------------------------------------Get Key String--------------------------------------------*/
                			iIdx = 0;
			
		                        sprintf(csKey,"%s",csDataCode);
                                        iKeyCodeLen = 0;

					do {

                                           	iIdx++;
							
						sprintf(csKeyCode,"%s",&csKey[iKeyCodeLen]);
                                           	if (csKeyCode[0] == PD_BANK_STATEMENT_KEY_DELIMIT_SYMBOL_CHECK) {
                                                	iKeyCodeLen++;

                                                       	sprintf(csKeyCode,"%s","\0");

							GetKeyTagName(iIdx,csTagName);
                                                        sprintf(csTag, "%s_%s_%d", PD_DETAIL_TAG, csTagName, i+1);
                                              	} else {
                                                    	strtok(csKeyCode,PD_BANK_STATEMENT_KEY_DELIMIT_SYMBOL);
                                                      	iKeyCodeLen += (strlen(csKeyCode) + 1);

                                                       	GetKeyTagName(iIdx,csTagName);
                                                       	sprintf(csTag, "%s_%s_%d", PD_DETAIL_TAG, csTagName, i+1);
                                                     	PutField_CString(hOutput,csTag,csKeyCode);
                                              	}
DEBUGLOG(("GetStatementRecordData() %s = [%s]\n",csTagName,csKeyCode));

                                  	} while (iKeyCodeLen < strlen(csKey));
				}
	
/* sub_data */
				sprintf(csDataCode,"%s",&csData[iDataCodeLen]);
				if (iDataCodeLen >= strlen(csData))
                                {
                                        iDataCodeLen++;

                                        sprintf(csDataCode,"%s","\0");
DEBUGLOG(("GetStatementRecordData() sub_data = [%s]\n",csDataCode));
                                } else {
					iIdx = 0;
				
					sprintf(csTag, "%s_sub_data_%d", PD_DETAIL_TAG, i+1);
                                        PutField_CString(hOutput,csTag,csDataCode);
DEBUGLOG(("GetStatementRecordData() sub_data = [%s]\n",csDataCode));

/*--------------------------------------------Get Sub Data String--------------------------------------------*/
					if (cAction == PD_ACTION_ADD) {

						do {

							iIdx++;

							sprintf(csDataCode,"%s",&csData[iDataCodeLen]);
                                                        if (csDataCode[0] == PD_BANK_STATEMENT_DATA_DELIMIT_SYMBOL_CHECK) {
                                                                iDataCodeLen++;

                                                                sprintf(csDataCode,"%s","\0");

                                                                GetSubDataTagName(iIdx,csTagName);
                                                                sprintf(csTag, "%s_%s_%d", PD_DETAIL_TAG, csTagName, i+1);
                                                        } else {
                                                                strtok(csDataCode,PD_BANK_STATEMENT_DATA_DELIMIT_SYMBOL);
                                                                iDataCodeLen += (strlen(csDataCode) + 1);

                                                                GetSubDataTagName(iIdx,csTagName);
                                                                sprintf(csTag, "%s_%s_%d", PD_DETAIL_TAG, csTagName, i+1);
                                                                PutField_CString(hOutput,csTag,csDataCode);
                                                        }
DEBUGLOG(("GetStatementRecordData() %s = [%s]\n",csTagName,csDataCode));
							
						} while (iDataCodeLen < strlen(csData));

					} else if (cAction == PD_ACTION_UPDATE) {
				
						do {						
							
							iIdx++;

                                                        sprintf(csDataCode,"%s",&csData[iDataCodeLen]);
                                                        if (csDataCode[0] == PD_BANK_STATEMENT_DATA_DELIMIT_SYMBOL_CHECK) {
                                                                iDataCodeLen++;

                                                                sprintf(csDataCode,"%s","\0");
                                                        } else {
                                                                strtok(csDataCode,PD_BANK_STATEMENT_DATA_DELIMIT_SYMBOL);
                                                                iDataCodeLen += (strlen(csDataCode) + 1);

                                                                sprintf(csTag, "%s_sub_data_key_%d", PD_DETAIL_TAG, i+1);
                                                                PutField_CString(hOutput,csTag,csDataCode);
DEBUGLOG(("GetStatementRecordData() sub_data_key_%d = [%s]\n",iIdx,csDataCode));

/*----------------------------------Get Sub Data Key String----------------------------------*/
                                                                sprintf(csKey,"%s",csDataCode);
                                                                iKeyCodeLen = 0;

                                                                sprintf(csKeyCode,"%s",&csKey[iKeyCodeLen]);
                                                                if (csKeyCode[0] == PD_BANK_STATEMENT_KEY_DELIMIT_SYMBOL_CHECK)
                                                                {
                                                                        iKeyCodeLen++;

                                                                        sprintf(csKeyCode,"%s","\0");
                                                                } else {
                                                                        strtok(csKeyCode,PD_BANK_STATEMENT_KEY_DELIMIT_SYMBOL);
                                                                        iKeyCodeLen += (strlen(csKeyCode) + 1);

                                                                        iTmp = atoi(csKeyCode);
                                                                        GetSubDataTagName(iTmp,csTagName);
                                                                        sprintf(csKeyCode,"%s",&csKey[iKeyCodeLen]);
                                                                        sprintf(csTag, "%s_%s_%d", PD_DETAIL_TAG, csTagName, i+1);
                                                                        PutField_CString(hOutput,csTag,csKeyCode);
                                                                }
DEBUGLOG(("GetStatementRecordData() %s = [%s]\n",csTagName,csKeyCode));
                                                        }
                                                } while (iDataCodeLen < strlen(csData));						
					}	
				}
			}
		}
	}

	FREE_ME(csData);
        FREE_ME(csDataCode);
        FREE_ME(csKey);
        FREE_ME(csKeyCode);

	return iRet;
}

int GetStatementRecordOrder(const hash_t *hInput, hash_t *hOutput)
{
	int     iRet = PD_OK;

        int     iIdx = 0;
        int     iOrderCnt = 0;

	char    csTag[PD_TAG_LEN + 1];
        char    csTagName[PD_TAG_LEN + 1];

	char    *csData;
        char    *csDataCode;
        int     iDataCodeLen = 0;

        char    *csKey;
        char    *csKeyCode;
        int     iKeyCodeLen = 0;

	csData = (char*) malloc (16392);
        csDataCode = (char*) malloc (16392);

        csKey = (char*) malloc (128);
        csKeyCode = (char*) malloc (128);

/*------------------------------------------------------Get Order String------------------------------------------------------*/
      	if (GetField_CString(hInput, "order", &csData)) {
DEBUGLOG(("GetStatementRecordOrder() order = [%s]\n", csData));

          	iOrderCnt = 0;
              	iDataCodeLen = 0;

              	do {

               		iOrderCnt++;

/* order_key (file_id_seq_ver) */
                     	sprintf(csDataCode,"%s",&csData[iDataCodeLen]);
                      	if (csDataCode[0] == PD_BANK_STATEMENT_DATA_DELIMIT_SYMBOL_CHECK) {
                        	iDataCodeLen++;

                           	sprintf(csDataCode,"%s","\0");
                    	} else {
                              	strtok(csDataCode,PD_BANK_STATEMENT_DATA_DELIMIT_SYMBOL);
                            	iDataCodeLen += (strlen(csDataCode) + 1);

                             	sprintf(csTag, "%s_%d", PD_ORDER_TAG, iOrderCnt);
                            	PutField_CString(hOutput,csTag,csDataCode);
DEBUGLOG(("GetStatementRecordOrder() order_%d = [%s]\n", iOrderCnt,csDataCode));

/*--------------------------------------------Get Key String--------------------------------------------*/
                              	iIdx = 0;

                               	sprintf(csKey,"%s",csDataCode);
                              	iKeyCodeLen = 0;

                              	do {

                                     	iIdx++;

                                     	sprintf(csKeyCode,"%s",&csKey[iKeyCodeLen]);
                                   	if (csKeyCode[0] == PD_BANK_STATEMENT_KEY_DELIMIT_SYMBOL_CHECK) {
                                      		iKeyCodeLen++;

                                              	sprintf(csKeyCode,"%s","\0");

                                              	GetKeyTagName(iIdx,csTagName);
                                              	sprintf(csTag, "%s_%s_%d", PD_ORDER_TAG, csTagName, iOrderCnt);
                                    	} else {
                                               	strtok(csKeyCode,PD_BANK_STATEMENT_KEY_DELIMIT_SYMBOL);
                                              	iKeyCodeLen += (strlen(csKeyCode) + 1);

                                             	GetKeyTagName(iIdx,csTagName);
                                              	sprintf(csTag, "%s_%s_%d", PD_ORDER_TAG, csTagName, iOrderCnt);
                                              	PutField_CString(hOutput,csTag,csKeyCode);
                                     	}
DEBUGLOG(("GetStatementRecordOrder() %s = [%s]\n",csTag,csKeyCode));

                            	} while (iKeyCodeLen < strlen(csKey));

/* order_user_seq */
                              	sprintf(csTag, "%s_user_seq_%d", PD_ORDER_TAG, iOrderCnt);
                             	PutField_Int(hOutput,csTag,iOrderCnt);
DEBUGLOG(("GetStatementRecordOrder() %s = [%d]\n",csTag,iOrderCnt));

                      	}

              	} while (iDataCodeLen < strlen(csData));

DEBUGLOG(("GetStatementRecordOrder() order_cnt = [%d]\n",iOrderCnt));
		PutField_Int(hOutput,"total_order_cnt",iOrderCnt);

       	} else {
DEBUGLOG(("GetStatementRecordOrder() order NOT FOUND!!!\n"));
  	}

	FREE_ME(csData);
        FREE_ME(csDataCode);
        FREE_ME(csKey);
        FREE_ME(csKeyCode);

	return iRet;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;

	char	cAction;
	char	*csUser = NULL;
	char    *csFileId = NULL;

	int	iHeaderVer = 0;

	int	iSeq = 0;
	int	iVer = 0;
	int	iLastVer = 0;
	int	iLatestVer = 0;
	int	iDisabled = 0;
	int	iSysSeq = 0;
	int	iUserSeq = 0;	
	int     iSkip = 0;
        //int     iMaskSkip = 0;

	char    *csOrderSeq = NULL;
        char    *csOrderVer = NULL;

	char	*csTmp;

	char	csTag[PD_TAG_LEN + 1];
	char	csTagName[PD_TAG_LEN + 1];

	char	*csBatchId = NULL;
	
	int	i = 0;
	int	iCnt = 0;
	int	iOrderCnt = 0;

	hash_t *hRecTemp = (hash_t*) malloc (sizeof(hash_t));
	hash_t *hRecOrder = (hash_t*) malloc (sizeof(hash_t));
	hash_t *hEditInfo = (hash_t*) malloc (sizeof(hash_t));

	hash_t *hRecGet = (hash_t*) malloc (sizeof(hash_t));
	hash_t *hRecAdd = (hash_t*) malloc (sizeof(hash_t));
	hash_t *hRecUpdate = (hash_t*) malloc (sizeof(hash_t));

	hash_init(hRecTemp,0);
	hash_init(hRecOrder,0);
	hash_init(hEditInfo,0);

/* user */
        if (GetField_CString(hRequest, "add_user", &csUser)) {
                PutField_CString(hRecTemp,"add_user",csUser);
                PutField_CString(hContext,"create_user",csUser);
                PutField_CString(hContext,"update_user",csUser);
DEBUGLOG(("Authorize() user = [%s]\n", csUser));
        } else {
                iRet = INT_USER_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() user NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsBSE:: Authorize() user NOT FOUND!!!\n");
        }

/* batch_id */
	if (GetField_CString(hRequest, "batch_id", &csBatchId)) {
DEBUGLOG(("Authorize() batch_id = [%s]\n", csBatchId));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("Authorize() batch_id NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() batch_id NOT FOUND!!!\n");
	}

/* get edit cnt */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBOLTmpApi:: GetEditCnt()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTmpApi", "GetEditCnt");
		iRet = (unsigned long)(*DBObjPtr)(csBatchId, hEditInfo);
		if (iRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTmpApi:: GetEditCnt() failed\n"));
ERRLOG(("Authorize() call DBOLTmpApi:: GetEditCnt() failed\n"));
		} else {
			GetField_CString(hEditInfo, "cnt", &csTmp);
			iCnt = atoi(csTmp);
DEBUGLOG(("Authorize() cnt = [%d]\n", iCnt));
		}
	}

/* get edit detail */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBOLTmpApi:: GetEditDetail()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTmpApi", "GetEditDetail");
		iRet = (unsigned long)(*DBObjPtr)(csBatchId, hEditInfo);
		if (iRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTmpApi:: GetEditDetail() failed\n"));
ERRLOG(("Authorize() call DBOLTmpApi:: GetEditDetail() failed\n"));
		} else {
			GetField_CString(hEditInfo, "cnt", &csTmp);
			iCnt = atoi(csTmp);
DEBUGLOG(("Authorize() cnt = [%d]\n", iCnt));
		}
	}

/* get edit order */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBOLTmpApi:: GetEditOrder()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTmpApi", "GetEditOrder");
		iRet = (unsigned long)(*DBObjPtr)(csBatchId, hEditInfo);
		if (iRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTmpApi:: GetEditOrder() failed\n"));
ERRLOG(("Authorize() call DBOLTmpApi:: GetEditOrder() failed\n"));
		} else {
			GetField_CString(hEditInfo, "cnt", &csTmp);
			iCnt = atoi(csTmp);
DEBUGLOG(("Authorize() cnt = [%d]\n", iCnt));
		}
	}

/*----------------------------------------------------------------Get Data From hRequest and put into hRecTemp----------------------------------------------------------------*/
	if (iRet == PD_OK) {	
		iRet = GetStatementRecordData(hEditInfo, hRecTemp);
	}

/*----------------------------------------------------------------Get Order From hRequest and put into hRecTemp----------------------------------------------------------------*/
	if (iRet == PD_OK) {
		iRet = GetStatementRecordOrder(hEditInfo, hRecTemp);
	}

/*----------------------------------------------------------------Get Data From hRecTemp----------------------------------------------------------------*/
	if (iRet == PD_OK) {

/*------------------------------------------------------File Header Ver------------------------------------------------------*/
DEBUGLOG(("Authorize() FileHeaderVer()\n"));

/*---------------Get Statement Header---------------*/

		hash_init(hRecGet,0);

/* file_id */
                sprintf(csTag, "%s_file_id_1", PD_DETAIL_TAG);
              	if (GetField_CString(hRecTemp, csTag, &csFileId)) {
DEBUGLOG(("Authorize() file_id = [%s]\n", csFileId));
                } else {
                	iRet = INT_FILE_ID_NOT_FOUND;
                      	PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() file_id not found!!!\n"));
ERRLOG("TxnOmtByUsSCE:: Authorize() file_id not found!!!\n");
              	}

DEBUGLOG(("Authorize() call DBOLStatement(GetHeader)::csFileId = [%s]\n",csFileId));

          	DBObjPtr = CreateObj(DBPtr, "DBOLStatement", "GetHeader");
              	iRet = (unsigned long)(*DBObjPtr)(csFileId,hRecGet);
DEBUGLOG(("Authorize() call DBOLStatement(GetHeader)::iRet = [%d]\n",iRet));

              	if (iRet != PD_OK) {
                        iRet = INT_INVALID_TXN;
                      	PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() call DBOLStatement(GetHeader):: FAILURE\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() call DBOLStatement:: GetHeader() FAILURE!!!\n");
               	} else {

/* header_ver */
                   	if (GetField_Int(hRecGet,"ver",&iHeaderVer)) {
DEBUGLOG(("Authorize() call DBOLStatement(GetHeader)::header_ver = [%d]\n",iHeaderVer));
				iHeaderVer++;
                       	}
              	}
	}

	if (iRet == PD_OK) {

                for (i = 0; i < iCnt; i++) {
DEBUGLOG(("Authorize() cnt = [%d]\n", i));

			hash_init(hRecGet,0);
			hash_init(hRecAdd,0);
			hash_init(hRecUpdate,0);

/* user */
        		if (GetField_CString(hRecTemp, "add_user", &csUser)) {
                		PutField_CString(hRecAdd,"create_user",csUser);
                		PutField_CString(hRecAdd,"update_user",csUser);
                		PutField_CString(hRecUpdate,"create_user",csUser);
                		PutField_CString(hRecUpdate,"update_user",csUser);
DEBUGLOG(("Authorize() user = [%s]\n", csUser));
        		} else {
                		iRet = INT_USER_NOT_FOUND;
                		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() user NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsBSE:: Authorize() user NOT FOUND!!!\n");
        		}

/* action */
			sprintf(csTag, "%s_action_%d", PD_DETAIL_TAG, i+1);
			if (GetField_CString(hRecTemp, csTag, &csTmp)) {
				cAction = csTmp[0];
				PutField_Char(hRecAdd,"action",cAction);
				PutField_Char(hRecUpdate,"action",cAction);
DEBUGLOG(("Authorize() action = [%c]\n", cAction));
			} else {
                		iRet = INT_ACTION_NOT_FOUND;
                		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() action not found!!!\n"));
ERRLOG("TxnOmtByUsSCE:: Authorize() action not found!!!\n");
        		}

/* file_id */
			sprintf(csTag, "%s_file_id_%d", PD_DETAIL_TAG, i+1);
			if (GetField_CString(hRecTemp, csTag, &csFileId)) {
				PutField_CString(hContext,"file_id",csFileId);
				PutField_CString(hRecAdd,"file_id",csFileId);
				PutField_CString(hRecUpdate,"file_id",csFileId);
DEBUGLOG(("Authorize() file_id = [%s]\n", csFileId));
			} else {
              			iRet = INT_FILE_ID_NOT_FOUND;
                		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() file_id not found!!!\n"));
ERRLOG("TxnOmtByUsSCE:: Authorize() file_id not found!!!\n");
        		}

			if ((iRet == PD_OK) && (cAction == PD_ACTION_DELETE)) { 	

/*------------------------------------------------------Delete Record------------------------------------------------------*/
DEBUGLOG(("Authorize() DeleteRecord()\n"));

/*---------------Check File Exist---------------*/
DEBUGLOG(("Authorize() CheckFileIdExist()\n"));

				sprintf(csTag,"%s",csFileId);
DEBUGLOG(("Authorize() file_id = [%s]\n",csTag));

                		DBObjPtr = CreateObj(DBPtr,"DBOLStatement","CheckFileIdExist"); 
				if ((unsigned long)(*DBObjPtr)(csTag) == FOUND) {
DEBUGLOG(("Authorize() call DBOLStatement(CheckFileIdExist)::File Exist()!!!\n"));

/* ver */
                                     	sprintf(csTag, "%s_ver_%d", PD_DETAIL_TAG, i+1);
                                   	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
                                           	iVer = atoi(csTmp);
DEBUGLOG(("Authorize() ver = [%d]\n", iVer));
                                            	PutField_Int(hRecAdd, "ver",iVer);
                                     	} else {
                                           	iRet = INT_STATEMENT_VER_NOT_FOUND;
                                             	PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() ver not found!!!\n"));
ERRLOG("TnOmtByUsBSE:: Authorize() ver not found!!!\n");
                                        }

/*---------------Get Statement Tmp (Last Ver Record) Detail---------------*/

/* seq */
					sprintf(csTag, "%s_seq_%d", PD_DETAIL_TAG, i+1);		
					if (GetField_CString(hRecTemp, csTag, &csTmp)) {
                				iSeq = atoi(csTmp);
DEBUGLOG(("Authorize() seq = [%d]\n", iSeq));
                				PutField_Int(hRecAdd,"seq",iSeq);
       	 				} else {
						iRet = INT_STATEMENT_SEQ_NOT_FOUND;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() seq not found!!!\n"));
ERRLOG("TxnOmtByUsBSE:: Authorize() seq not found!!!\n");
        				}

					if (iRet == PD_OK) {
              					DBObjPtr = CreateObj(DBPtr,"DBOLStatementTmp","GetLastVerRecDetail");
                   				iRet = (unsigned long)(*DBObjPtr)(csFileId,iSeq,hRecGet);
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::iRet = [%d]\n",iRet));

                        			if (iRet == PD_OK) {

/* ver */
                             				if (GetField_Int(hRecGet,"ver",&iLastVer)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::ver = [%d]\n",iLastVer));
                            				}

/* latest_ver */
                             				if (GetField_Int(hRecGet,"latest_ver",&iLatestVer)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::latest_ver = [%d]\n",iLatestVer));
                              				}

/* disabled */
                                                        if (GetField_Int(hRecGet,"disabled",&iDisabled)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::disabled = [%d]\n",iDisabled));
                                                        }

/* sys_seq */
                             				if (GetField_Int(hRecGet,"sys_seq",&iSysSeq)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::sys_seq = [%d]\n",iSysSeq));
								PutField_Int(hRecAdd, "sys_seq",iSysSeq);
                            				}

/* user_seq */
                              				if (GetField_Int(hRecGet,"user_seq",&iUserSeq)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::user_seq = [%d]\n",iUserSeq));
								PutField_Int(hRecAdd, "user_seq",iUserSeq);
                               				}

/* skip */
                                                        if (GetField_Int(hRecGet,"skip",&iSkip)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::skip = [%d]\n",iSkip));
								PutField_Int(hRecAdd, "skip",iSkip);
                                                        }

/* mask_skip */
/*
                                                        if (GetField_Int(hRecGet,"mask_skip",&iMaskSkip)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::mask_skip = [%d]\n",iMaskSkip));
								PutField_Int(hRecAdd, "mask_skip",iMaskSkip);
							}
*/

/* int_bank_code */
                                                        if (GetField_CString(hRecGet,"int_bank_code",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::int_bank_code = [%s]\n",csTmp));
                                                                PutField_CString(hRecAdd, "int_bank_code",csTmp);
                                                        }

/* bank_acct_num */
                                                        if (GetField_CString(hRecGet,"bank_acct_num",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::bank_acct_num = [%s]\n",csTmp));
                                                                PutField_CString(hRecAdd, "bank_acct_num",csTmp);
                                                        }

/* raw_date */
                                                        if (GetField_CString(hRecGet,"raw_date",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::raw_date = [%s]\n",csTmp));
                                                                PutField_CString(hRecAdd, "raw_date",csTmp);
                                                        }

/* raw_time */
                                                        if (GetField_CString(hRecGet,"raw_time",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::raw_time = [%s]\n",csTmp));
                                                                PutField_CString(hRecAdd, "raw_time",csTmp);
                                                        }

/* statement_date */
							if (GetField_CString(hRecGet,"statement_date",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::statement_date = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "statement_date",csTmp);
							}

/* statement_time */
							if (GetField_CString(hRecGet,"statement_time",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::statement_time = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "statement_time",csTmp);
                                                        }

/* tfr_bank_name */
							if (GetField_CString(hRecGet,"tfr_bank_name",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::tfr_bank_name = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "tfr_bank_name",csTmp);
                                                        }

/* tfr_bank_acct_num */
                                                        if (GetField_CString(hRecGet,"tfr_bank_acct_num",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::tfr_bank_acct_num = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "tfr_bank_acct_num",csTmp);
                                                        }

/* tfr_channel */
                                                        if (GetField_CString(hRecGet,"tfr_channel",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::tfr_channel = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "tfr_channel",csTmp);
                                                        }

/* tfr_type */
                                                        if (GetField_CString(hRecGet,"tfr_type",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::tfr_type = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "tfr_type",csTmp);
                                                        }

/* tfr_text */
                                                        if (GetField_CString(hRecGet,"tfr_text",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::tfr_text = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "tfr_text",csTmp);
                                                        }

/* tfr_customer_text */
                                                        if (GetField_CString(hRecGet,"tfr_customer_text",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::tfr_customer_text = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "tfr_customer_text",csTmp);
                                                        }

/* tfr_sender_name */
                                                        if (GetField_CString(hRecGet,"sender_name",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::tfr_sender_name = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "sender_name",csTmp);
                                                        }

/* txn_ref_num */
                                                        if (GetField_CString(hRecGet,"txn_ref_num",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::txn_ref_num = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "txn_ref_num",csTmp);
                                                        }

/* amt_type */
                                                        if (GetField_CString(hRecGet,"amt_type",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::amt_type = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "amt_type",csTmp);
                                                        }

/* txn_amount */
                                                        if (GetField_CString(hRecGet,"txn_amount",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::txn_amount = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "txn_amount",csTmp);
                                                        }						

/* bank_charge */
                                                        if (GetField_CString(hRecGet,"bank_charge",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::bank_charge = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "bank_charge",csTmp);
                                                        }

/* balance */
                                                        if (GetField_CString(hRecGet,"balance",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::balance = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "balance",csTmp);
                                                        }

/* sender_baid_name */
                                                        if (GetField_CString(hRecGet,"sender_baid_name",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::sender_baid_name = [%s]\n",csTmp));
                                                                PutField_CString(hRecAdd, "sender_baid_name",csTmp);
                                                        }

/* recipient_baid_name */
                                                        if (GetField_CString(hRecGet,"recipient_baid_name",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::recipient_baid_name = [%s]\n",csTmp));
                                                                PutField_CString(hRecAdd, "recipient_baid_name",csTmp);
                                                        }

/* client_name */
                                                        if (GetField_CString(hRecGet,"client_name",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::client_name = [%s]\n",csTmp));
                                                                PutField_CString(hRecAdd, "client_name",csTmp);
                                                        }

/* txn_location */
							if (GetField_CString(hRecGet, "txn_location", &csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::txn_location = [%s]\n", csTmp));
								PutField_CString(hRecAdd, "txn_location", csTmp);
							}

/* txn_type */
							if (GetField_CString(hRecGet, "txn_type", &csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::txn_type = [%s]\n", csTmp));
								PutField_CString(hRecAdd, "txn_type", csTmp);
							}

/* txn_reference */
							if (GetField_CString(hRecGet, "txn_reference", &csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::txn_reference = [%s]\n", csTmp));
								PutField_CString(hRecAdd, "txn_reference", csTmp);
							}

                        			}
                        			else {
                                			iRet = INT_ERR;
DEBUGLOG(("Authorize:: call DBOLStatementTmp(GetLastVerRecDetail):: failed\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() call DBOLStatementTmp:: GetLastVerRecDetail:: failed!!!\n");
                        			}
					}

/*---------------Check Disabled---------------*/ 
					if (iRet == PD_OK) {
						if (iDisabled == 1) {
							iRet = INT_STATEMENT_RECORD_DELETED;
DEBUGLOG(("Authorize() CheckRecDisabled:: disabled = [%d]\n", iDisabled));
ERRLOG("TxnOmtByUsBSE::Authorize() CheckRecDisabled failed!!!\n");
						}
					}

/*---------------Update Statement Tmp Detail---------------*/ 
             				if (iRet == PD_OK) {

/* file_id */     
	        				PutField_CString(hRecUpdate,"file_id",csFileId);
DEBUGLOG(("Authorize() UpdateRecDetail::file_id = [%s]\n",csFileId));
             
/* seq */
                       	 			PutField_Int(hRecUpdate, "seq",iSeq);
DEBUGLOG(("Authorize() UpdateRecDetail::seq = [%d]\n",iSeq));

/* ver */
						iVer = iHeaderVer;
		       				PutField_Int(hRecUpdate, "ver",iVer);
DEBUGLOG(("Authorize() UpdateRecDetail::ver = [%d]\n",iVer));

/* latest_ver */
                      				PutField_Int(hRecUpdate, "latest_ver",iLatestVer);
DEBUGLOG(("Authorize() UpdateRecDetail::latest_ver = [%d]\n",iLatestVer));
        
/* update_user */
                               			PutField_CString(hRecUpdate,"update_user",csUser);
DEBUGLOG(("Authorize() UpdateRecDetail::update_user = [%s]\n",csUser));

DEBUGLOG(("Authorize() call DBOLStatementTmp(UpdateRecDetail)::Update()\n"));

                     				DBObjPtr = CreateObj(DBPtr, "DBOLStatementTmp", "UpdateRecDetail");
                     				iRet = (unsigned long)(*DBObjPtr)(hRecUpdate);
                       				if (iRet != PD_OK) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(UpdateRecDetail)::Update() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() call DBOLStatementTmp:: UpdateRecDetail() FAILURE!!!\n");
                     				}
           				}

/*---------------Add Statement Tmp Detail---------------*/
             				if (iRet == PD_OK) {

/* file_id */
                     				PutField_CString(hRecAdd,"file_id",csFileId);
DEBUGLOG(("Authorize() AddDetail::file_id = [%s]\n",csFileId));

/* seq */
                        			PutField_Int(hRecAdd, "seq",iSeq);
DEBUGLOG(("Authorize() AddDetail::seq = [%d]\n",iSeq));
             
/* ver */
		       				PutField_Int(hRecAdd, "ver",iVer);
DEBUGLOG(("Authorize() AddDetail::ver = [%d]\n",iVer));
         
/* disabled */
                                                iDisabled = 1;
                                                PutField_Int(hRecAdd, "disabled",iDisabled);
DEBUGLOG(("Authorize() AddDetail::disabled = [%d]\n", iDisabled));

/* skip */
						sprintf(csTag, "%s_skip_%d", PD_DETAIL_TAG, i+1);
                                                if (GetField_CString(hRecTemp, csTag, &csTmp)) {
                                                        iSkip = atoi(csTmp);
DEBUGLOG(("Authorize() AddDetail::skip = [%d]\n",iSkip));
							PutField_Int(hRecAdd, "skip",iSkip);
                                                }

/*
						PutField_Int(hRecAdd, "skip",iSkip);
DEBUGLOG(("Authorize() AddDetail::skip = [%d]\n",iSkip));
*/

/* mask_skip */
/*
						PutField_Int(hRecAdd, "mask_skip",iMaskSkip);
DEBUGLOG(("Authorize() AddDetail::mask_skip = [%d]\n",iMaskSkip));
*/

DEBUGLOG(("Authorize() call DBOLStatementTmp(AddDetail)::Add()\n"));

                	     			DBObjPtr = CreateObj(DBPtr, "DBOLStatementTmp", "AddDetail");
                     				iRet = (unsigned long)(*DBObjPtr)(hRecAdd);
                       				if (iRet != PD_OK) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(AddDetail)::Add() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() call DBOLStatementTmp:: AddDetail() FAILURE!!!\n");
                     				}
           				}
				}
				else {
                        		iRet = INT_FILE_ID_NOT_FOUND;
DEBUGLOG(("Authorize() call DBOLStatement::File Not Exist()!!! \n"));
ERRLOG("TxnOmtByUsBSE::Authorize() CheckFileIdExist:: failed!!!\n");
                		}
			}
			else if ((iRet == PD_OK) && (cAction == PD_ACTION_UPDATE)) { 

/*------------------------------------------------------Update Record------------------------------------------------------*/
DEBUGLOG(("Authorize() UpdateRecord()\n"));

/*---------------Check File Exist---------------*/
DEBUGLOG(("Authorize() CheckFileIdExist()\n"));

				sprintf(csTag,"%s",csFileId);
DEBUGLOG(("Authorize() file_id = [%s]\n",csTag));

                		DBObjPtr = CreateObj(DBPtr,"DBOLStatement","CheckFileIdExist");
                		if ((unsigned long)(*DBObjPtr)(csTag) == FOUND) {
DEBUGLOG(("Authorize() call DBOLStatement(CheckFileIdExist)::File Exist()!!!\n"));

/* ver */
                                  	sprintf(csTag, "%s_ver_%d", PD_DETAIL_TAG, i+1);
                                   	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
                                           	iVer = atoi(csTmp);
DEBUGLOG(("Authorize() ver = [%d]\n", iVer));
                                               	PutField_Int(hRecAdd, "ver",iVer);
                                  	} else {
                                            	iRet = INT_STATEMENT_VER_NOT_FOUND;
                                           	PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() ver not found!!!\n"));
ERRLOG("TnOmtByUsBSE:: Authorize() ver not found!!!\n");
                                    	}
		
/*---------------Get Statement Tmp (Last Ver Record) Detail---------------*/

/* seq */
					sprintf(csTag, "%s_seq_%d", PD_DETAIL_TAG, i+1);
                        		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
                                		iSeq = atoi(csTmp);
DEBUGLOG(("Authorize() seq = [%d]\n", iSeq));
                                		PutField_Int(hRecAdd,"seq",iSeq);
                                		//PutField_Int(hContext,"seq",iSeq);
                        		} else {

                                		iRet = INT_STATEMENT_SEQ_NOT_FOUND;
                                		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() seq not found!!!\n"));
ERRLOG("TxnOmtByUsBSE:: Authorize() seq not found!!!\n");
                      			}

					if (iRet == PD_OK) {

                                		DBObjPtr = CreateObj(DBPtr,"DBOLStatementTmp","GetLastVerRecDetail");
                                		iRet = (unsigned long)(*DBObjPtr)(csFileId,iSeq,hRecGet);
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::iRet = [%d]\n",iRet));
                                		if (iRet == PD_OK) {

/* ver */
                                        		if (GetField_Int(hRecGet,"ver",&iLastVer)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::ver = [%d]\n",iLastVer));
                                        		}

/* latest_ver */
                                        		if (GetField_Int(hRecGet,"latest_ver",&iLatestVer)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::latest_ver = [%d]\n",iLatestVer));
                                        		}

/* disabled */
                                                        if (GetField_Int(hRecGet,"disabled",&iDisabled)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::disabled = [%d]\n",iDisabled));
                                                        }

/* skip */
                                                        if (GetField_Int(hRecGet,"skip",&iSkip)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::skip = [%d]\n",iSkip));
								PutField_Int(hRecAdd, "skip",iSkip);
                                                        }

/* mask_skip */
/*
                                                        if (GetField_Int(hRecGet,"mask_skip",&iMaskSkip)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::mask_skip = [%d]\n",iMaskSkip));
								PutField_Int(hRecAdd, "mask_skip",iMaskSkip);
							}
*/

/* int_bank_code */
							if (GetField_CString(hRecGet,"int_bank_code",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::int_bank_code = [%s]\n",csTmp));
                                                                PutField_CString(hRecAdd, "int_bank_code",csTmp);
                                                        }

/* bank_acct_num */
							if (GetField_CString(hRecGet,"bank_acct_num",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::bank_acct_num = [%s]\n",csTmp));
                                                                PutField_CString(hRecAdd, "bank_acct_num",csTmp);
                                                        }

/* raw_date */
							if (GetField_CString(hRecGet,"raw_date",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::raw_date = [%s]\n",csTmp));
                                                                PutField_CString(hRecAdd, "raw_date",csTmp);
                                                        }							

/* raw_time */
 							if (GetField_CString(hRecGet,"raw_time",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::raw_time = [%s]\n",csTmp));
                                                                PutField_CString(hRecAdd, "raw_time",csTmp);
                                                        }                 

/* statement_date */
                                                        if (GetField_CString(hRecGet,"statement_date",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::statement_date = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "statement_date",csTmp);
                                                        }

/* statement_time */
                                                        if (GetField_CString(hRecGet,"statement_time",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::statement_time = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "statement_time",csTmp);
                                                        }

/* tfr_bank_name */
                                                        if (GetField_CString(hRecGet,"tfr_bank_name",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::tfr_bank_name = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "tfr_bank_name",csTmp);
                                                        }

/* tfr_bank_acct_num */
                                                        if (GetField_CString(hRecGet,"tfr_bank_acct_num",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::tfr_bank_acct_num = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "tfr_bank_acct_num",csTmp);
                                                        }

/* tfr_channel */
                                                        if (GetField_CString(hRecGet,"tfr_channel",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::tfr_channel = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "tfr_channel",csTmp);
                                                        }

/* tfr_type */
                                                        if (GetField_CString(hRecGet,"tfr_type",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::tfr_type = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "tfr_type",csTmp);
                                                        }

/* tfr_text */
                                                        if (GetField_CString(hRecGet,"tfr_text",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::tfr_text = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "tfr_text",csTmp);
                                                        }

/* tfr_customer_text */
                                                        if (GetField_CString(hRecGet,"tfr_customer_text",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::tfr_customer_text = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "tfr_customer_text",csTmp);
                                                        }

/* tfr_sender_name */
                                                        if (GetField_CString(hRecGet,"sender_name",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::tfr_sender_name = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "sender_name",csTmp);
                                                        }

/* txn_ref_num */
                                                        if (GetField_CString(hRecGet,"txn_ref_num",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::txn_ref_num = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "txn_ref_num",csTmp);
                                                        }

/* amt_type */
                                                        if (GetField_CString(hRecGet,"amt_type",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::amt_type = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "amt_type",csTmp);
                                                        }

/* txn_amount */
                                                        if (GetField_CString(hRecGet,"txn_amount",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::txn_amount = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "txn_amount",csTmp);
                                                        }

/* bank_charge */
                                                        if (GetField_CString(hRecGet,"bank_charge",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::bank_charge = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "bank_charge",csTmp);
                                                        }

/* balance */
                                                        if (GetField_CString(hRecGet,"balance",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::balance = [%s]\n",csTmp));
								PutField_CString(hRecAdd, "balance",csTmp);
                                                        }

/* sender_baid_name */
                                                        if (GetField_CString(hRecGet,"sender_baid_name",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::sender_baid_name = [%s]\n",csTmp));
                                                                PutField_CString(hRecAdd, "sender_baid_name",csTmp);
                                                        }

/* recipient_baid_name */
                                                        if (GetField_CString(hRecGet,"recipient_baid_name",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::recipient_baid_name = [%s]\n",csTmp));
                                                                PutField_CString(hRecAdd, "recipient_baid_name",csTmp);
                                                        }

/* client_name */
                                                        if (GetField_CString(hRecGet,"client_name",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::client_name = [%s]\n",csTmp));
                                                                PutField_CString(hRecAdd, "client_name",csTmp);
                                                        }

/* txn_location */
							if (GetField_CString(hRecGet, "txn_location", &csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::txn_location = [%s]\n", csTmp));
								PutField_CString(hRecAdd, "txn_location", csTmp);
							}

/* txn_type */
							if (GetField_CString(hRecGet, "txn_type", &csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::txn_type = [%s]\n", csTmp));
								PutField_CString(hRecAdd, "txn_type", csTmp);
							}

/* txn_reference */
							if (GetField_CString(hRecGet, "txn_reference", &csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail)::txn_reference = [%s]\n", csTmp));
								PutField_CString(hRecAdd, "txn_reference", csTmp);
							}


                                		} else {
                                        		iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastVerRecDetail):: failed\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() call DBOLStatementTmp:: GetLastVerRecDetail() failed!!!\n");
                                		}
					}

/*---------------Check Disabled---------------*/ 
					if (iRet == PD_OK) {
						if (iDisabled == 1) {
                                                        iRet = INT_STATEMENT_RECORD_DELETED;
DEBUGLOG(("Authorize() CheckRecDisabled:: disabled = [%d]\n", iDisabled));
ERRLOG("TxnOmtByUsBSE::Authorize() CheckRecDisabled failed!!!\n");
                                                }
					}

/*---------------Update Statement Tmp Detail---------------*/
					if (iRet == PD_OK) {

/* file_id */
                                		PutField_CString(hRecUpdate,"file_id",csFileId);
DEBUGLOG(("Authorize() UpdateRecDetail::file_id = [%s]\n",csFileId));

/* seq */
                                		PutField_Int(hRecUpdate, "seq",iSeq);
DEBUGLOG(("Authorize() UpdateRecDetail::seq = [%d]\n",iSeq));

/* ver */
						iVer = iHeaderVer;
                                		PutField_Int(hRecUpdate, "ver",iVer);
DEBUGLOG(("Authorize() UpdateRecDetail::ver = [%d]\n",iVer));

/* latest_ver */
                                		PutField_Int(hRecUpdate, "latest_ver",iLatestVer);
DEBUGLOG(("Authorize() UpdateRecDetail::latest_ver = [%d]\n",iLatestVer));

/* update_user */
                                		PutField_CString(hRecUpdate,"update_user",csUser);
DEBUGLOG(("Authorize() UpdateRecDetail::update_user = [%s]\n",csUser));

DEBUGLOG(("Authorize() call DBOLStatementTmp(UpdateRecDetail)::Update()\n"));

                                		DBObjPtr = CreateObj(DBPtr, "DBOLStatementTmp", "UpdateRecDetail");
                                		iRet = (unsigned long)(*DBObjPtr)(hRecUpdate);
                                		if (iRet != PD_OK) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(UpdateRecDetail)::Update() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() call DBOLStatementTmp:: UpdateRecDetail() FAILURE!!!\n");
                                		}
                        		}

/*---------------Add Statement Tmp Detail---------------*/
                        		if (iRet == PD_OK) {

/* file_id */
                                		PutField_CString(hRecAdd,"file_id",csFileId);
DEBUGLOG(("Authorize() AddDetail::file_id = [%s]\n",csFileId));

/* seq */
                                		PutField_Int(hRecAdd, "seq",iSeq);
DEBUGLOG(("Authorize() AddDetail::seq = [%d]\n",iSeq));

/* ver */
                                		PutField_Int(hRecAdd, "ver",iVer);
DEBUGLOG(("Authorize() AddDetail::ver = [%d]\n",iVer));

/* disabled */
                                                iDisabled = 0;
                                                PutField_Int(hRecAdd, "disabled",iDisabled);
DEBUGLOG(("Authorize() AddDetail::disabled = [%d]\n",iDisabled));

/* skip */
						sprintf(csTag, "%s_skip_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
                                        		iSkip = atoi(csTmp);
DEBUGLOG(("Authorize() AddDetail::skip = [%d]\n", iSkip));
                                        		PutField_Int(hRecAdd, "skip",iSkip);
                                		}

/* mask_skip */
/*
						sprintf(csTag, "%s_mask_skip_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
                                        		iMaskSkip = atoi(csTmp);
DEBUGLOG(("Authorize() AddDetail::mask_skip = [%d]\n", iMaskSkip));
                                        		PutField_Int(hRecAdd, "mask_skip",iMaskSkip);
						}
*/
	
/* int_bank_code */
						sprintf(csTag, "%s_int_bank_code_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::int_bank_code = [%s]\n", csTmp));
                                        		PutField_CString(hRecAdd,"int_bank_code",csTmp);
                                		}

/* bank_acct_num */
						sprintf(csTag, "%s_bank_acct_num_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::bank_acct_num = [%s]\n", csTmp));
                                        		PutField_CString(hRecAdd,"bank_acct_num",csTmp);
                                		}

/* raw_date */
/*
						sprintf(csTag, "%s_statement_date_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::raw_date = [%s]\n", csTmp));
                                        		PutField_CString(hRecAdd,"raw_date",csTmp);
                                		}
*/

/* raw_time */
/*
						sprintf(csTag, "%s_statement_time_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::raw_time = [%s]\n", csTmp));
                                        		PutField_CString(hRecAdd,"raw_time",csTmp);
                                		}
*/

/* statement_date */
						sprintf(csTag, "%s_statement_date_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::statement_date = [%s]\n", csTmp));
                                        		PutField_CString(hRecAdd,"statement_date",csTmp);
						}

/* statement_time */
						sprintf(csTag, "%s_statement_time_%d", PD_DETAIL_TAG, i+1);
   		                             	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::statement_time = [%s]\n", csTmp));
                 		                       PutField_CString(hRecAdd,"statement_time",csTmp);
						}

/* tfr_bank_name */
						sprintf(csTag, "%s_tfr_bank_name_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::tfr_bank_name = [%s]\n", csTmp));
                                        		PutField_CString(hRecAdd,"tfr_bank_name",csTmp);
						}

/* tfr_bank_acct_num */
						sprintf(csTag, "%s_tfr_bank_acct_num_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::tfr_bank_acct_num = [%s]\n", csTmp));
                                        		PutField_CString(hRecAdd,"tfr_bank_acct_num",csTmp);
						}

/* tfr_type */
						sprintf(csTag, "%s_tfr_type_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::tfr_type = [%s]\n", csTmp));
                                        		PutField_CString(hRecAdd,"tfr_type",csTmp);
						}

/* tfr_channel */
						sprintf(csTag, "%s_tfr_channel_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::tfr_channel = [%s]\n", csTmp));
                                        		PutField_CString(hRecAdd,"tfr_channel",csTmp);
						}

/* tft_text */
						sprintf(csTag, "%s_tfr_text_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::tfr_text = [%s]\n", csTmp));
                                        		PutField_CString(hRecAdd,"tfr_text",csTmp);
						}

/* tfr_customer_text */
						sprintf(csTag, "%s_tfr_customer_text_%d", PD_DETAIL_TAG, i+1);
                   		             	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::tfr_customer_text = [%s]\n",csTmp));
                                		        PutField_CString(hRecAdd,"tfr_customer_text",csTmp);
						}

/* sender_name */
						sprintf(csTag, "%s_tfr_sender_name_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::sender_name = [%s]\n",csTmp));
                                        		PutField_CString(hRecAdd,"sender_name",csTmp);
						}

/* txn_ref_num */
						sprintf(csTag, "%s_txn_ref_num_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::txn_ref_num = [%s]\n",csTmp));
                                 		       PutField_CString(hRecAdd,"txn_ref_num",csTmp);
						}

/* balance */
						sprintf(csTag, "%s_balance_%d", PD_DETAIL_TAG, i+1);
		                                if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::balance = [%s]\n",csTmp));
							PutField_CString(hRecAdd,"balance",csTmp);
						}

/* amt_type */
						sprintf(csTag, "%s_amt_type_%d", PD_DETAIL_TAG, i+1);
		                                if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::amt_type = [%s]\n",csTmp));
                		                        PutField_CString(hRecAdd,"amt_type",csTmp);
						}

/* txn_amount */
						sprintf(csTag, "%s_txn_amount_%d", PD_DETAIL_TAG, i+1);
                                		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::txn_amount = [%s]\n",csTmp));
							PutField_CString(hRecAdd,"txn_amount",csTmp);
						}

/* bank_charge */
						sprintf(csTag, "%s_bank_charge_%d", PD_DETAIL_TAG, i+1);
						if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::bank_charge = [%s]\n",csTmp));
							PutField_CString(hRecAdd,"bank_charge",csTmp);
						}

/* sender_baid_name */
                                                sprintf(csTag, "%s_sender_baid_name_%d", PD_DETAIL_TAG, i+1);
                                                if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::sender_baid_name = [%s]\n", csTmp));
                                                        PutField_CString(hRecAdd,"sender_baid_name",csTmp);
                                                }

/* recipient_baid_name */
                                                sprintf(csTag, "%s_recipient_baid_name_%d", PD_DETAIL_TAG, i+1);
                                                if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::recipient_baid_name = [%s]\n", csTmp));
                                                        PutField_CString(hRecAdd,"recipient_baid_name",csTmp);
                                                }

/* client_name */
                                                sprintf(csTag, "%s_client_name_%d", PD_DETAIL_TAG, i+1);
                                                if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::client_name = [%s]\n", csTmp));
                                                        PutField_CString(hRecAdd,"client_name",csTmp);
                                                }

/* txn_location */
						sprintf(csTag, "%s_txn_location_%d", PD_DETAIL_TAG, i+1);
						if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::txn_location = [%s]\n", csTmp));
							PutField_CString(hRecAdd,"txn_location",csTmp);
						}

/* txn_type */
						sprintf(csTag, "%s_txn_type_%d", PD_DETAIL_TAG, i+1);
						if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::txn_type = [%s]\n", csTmp));
							PutField_CString(hRecAdd,"txn_type",csTmp);
						}

/* txn_reference */
						sprintf(csTag, "%s_txn_reference_%d", PD_DETAIL_TAG, i+1);
						if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::txn_reference = [%s]\n", csTmp));
							PutField_CString(hRecAdd,"txn_reference",csTmp);
						}

DEBUGLOG(("Authorize() call DBOLStatementTmp(AddDetail)::Add()\n"));

                                		DBObjPtr = CreateObj(DBPtr, "DBOLStatementTmp", "AddDetail");
                                		iRet = (unsigned long)(*DBObjPtr)(hRecAdd);
                                		if (iRet != PD_OK) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(AddDetail)::Add() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() call DBOLStatementTmp:: AddDetail() FAILURE!!!\n");
                                		}
                        		}
				}
                		else {
                        		iRet = INT_FILE_ID_NOT_FOUND;
DEBUGLOG(("Authorize() call DBOLStatement::File Not Exist()!!! \n"));
ERRLOG("TxnOmtByUsBSE::Authorize::ValidateProcess::CheckFileIdExist:: failed!!!\n");
                		}
			}
			else if ((iRet == PD_OK) && (cAction == PD_ACTION_ADD)) {	

/*------------------------------------------------------Add Record------------------------------------------------------*/
DEBUGLOG(("Authorize() AddRecord()\n"));

/* file_id */
				snprintf(csTag,sizeof(csTag),"%s",csFileId);
DEBUGLOG(("Authorize() file_id = [%s]\n",csTag));

/*---------------Get Statement Tmp (Laat Seq Record) Detail---------------*/
				DBObjPtr = CreateObj(DBPtr,"DBOLStatementTmp","GetLastSeqRecDetail");
                		iRet = (unsigned long)(*DBObjPtr)(csFileId,hRecGet);
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastSeqRecDetail)::iRet = [%d]\n",iRet));

                		if (iRet == PD_OK) {		

/* seq */
					if (GetField_Int(hRecGet,"seq",&iSeq)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastSeqRecDetail)::seq = [%d]\n",iSeq));
        	                	}

/* int_bank_code */
                                       	if (GetField_CString(hRecGet,"int_bank_code",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastSeqRecDetail)::int_bank_code = [%s]\n",csTmp));
                                              	PutField_CString(hRecAdd, "int_bank_code",csTmp);
                                       	}

/* bank_acct_num */
                                      	if (GetField_CString(hRecGet,"bank_acct_num",&csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetLastSeqRecDetail)::bank_acct_num = [%s]\n",csTmp));
                                               	PutField_CString(hRecAdd, "bank_acct_num",csTmp);
                                       	}

				} else {
					iRet = INT_ERR;
DEBUGLOG(("Authorize:: call DBOLStatementTmp(GetLastSeqRecDetail):: failed\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() DBOLStatementTmp:: GetLastSeqRecDetail() failed!!!\n");
				}

/*---------------Add Statement Tmp Detail---------------*/
				if (iRet == PD_OK) {

/* file_id */
					PutField_CString(hRecAdd,"file_id",csFileId);
DEBUGLOG(("Authorize() AddDetail::file_id = [%s]\n",csFileId));

/* seq */
					iSeq++;												
					PutField_Int(hRecAdd, "seq",iSeq);
DEBUGLOG(("Authorize() AddDetail::seq = [%d]\n", iSeq));

/* ver */
					iVer = iHeaderVer;
					PutField_Int(hRecAdd, "ver",iVer);		
DEBUGLOG(("Authorize() AddDetail::ver = [%d]\n",iVer));

/* disabled */
                                     	iDisabled = 0;
                                        PutField_Int(hRecAdd, "disabled",iDisabled);
DEBUGLOG(("Authorize() AddDetail::disabled = [%d]\n",iDisabled));

/* skip */
					iSkip = 0;
                                        PutField_Int(hRecAdd, "skip",iSkip);
DEBUGLOG(("Authorize() AddDetail::skip = [%d]\n", iSkip));

/* mask_skip */
/*
					sprintf(csTag, "%s_mask_skip_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
                                        	iTmp = atoi(csTmp);
DEBUGLOG(("Authorize() AddDetail::mask_skip = [%d]\n", iTmp));
                                        	PutField_Int(hRecAdd, "mask_skip",iTmp);
                                	}
*/

/* raw_date */
/*
					sprintf(csTag, "%s_statement_date_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::raw_date = [%s]\n", csTmp));
                                        	PutField_CString(hRecAdd,"raw_date",csTmp);
                                	}
*/

/* raw_time */
/*
					sprintf(csTag, "%s_statement_time_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::raw_time = [%s]\n", csTmp));
                                       	 	PutField_CString(hRecAdd,"raw_time",csTmp);
					}
*/

/* statement_date */
					sprintf(csTag, "%s_statement_date_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::statement_date = [%s]\n", csTmp));
                                       		PutField_CString(hRecAdd,"statement_date",csTmp);
                                	}

/* statement_time */
					sprintf(csTag, "%s_statement_time_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::statement_time = [%s]\n", csTmp));
                                        	PutField_CString(hRecAdd,"statement_time",csTmp);
                                	}

/* tfr_bank_name */
					sprintf(csTag, "%s_tfr_bank_name_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::tfr_bank_name = [%s]\n", csTmp));
                                        	PutField_CString(hRecAdd,"tfr_bank_name",csTmp);
                                	}

/* tfr_bank_acct_num */
					sprintf(csTag, "%s_tfr_bank_acct_num_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::tfr_bank_acct_num = [%s]\n", csTmp));
                                        	PutField_CString(hRecAdd,"tfr_bank_acct_num",csTmp);
                                	}

/* tfr_type */
					sprintf(csTag, "%s_tfr_type_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::tfr_type = [%s]\n", csTmp));
                                        	PutField_CString(hRecAdd,"tfr_type",csTmp);
                                	}

/* tfr_channel */
					sprintf(csTag, "%s_tfr_channel_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::tfr_channel = [%s]\n", csTmp));
                                        	PutField_CString(hRecAdd,"tfr_channel",csTmp);
                                	}

/* tft_text */
					sprintf(csTag, "%s_tfr_text_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::tfr_text = [%s]\n", csTmp));
                                        	PutField_CString(hRecAdd,"tfr_text",csTmp);
                                	}

/* tfr_customer_text */
					sprintf(csTag, "%s_tfr_customer_text_%d", PD_DETAIL_TAG, i+1);
                   		       	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::tfr_customer_text = [%s]\n",csTmp));
                        		      	PutField_CString(hRecAdd,"tfr_customer_text",csTmp);
                                	}

/* tfr_sender_name */
					sprintf(csTag, "%s_tfr_sender_name_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::sender_name = [%s]\n",csTmp));
                                        	PutField_CString(hRecAdd,"sender_name",csTmp);
                                	}

/* txn_ref_num */
					sprintf(csTag, "%s_txn_ref_num_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::txn_ref_num = [%s]\n",csTmp));
                                        	PutField_CString(hRecAdd,"txn_ref_num",csTmp);
                                	}

/* balance */	
					sprintf(csTag, "%s_balance_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::balance = [%s]\n",csTmp));
                                        	PutField_CString(hRecAdd,"balance",csTmp);
                                	}

/* amt_type */
					sprintf(csTag, "%s_amt_type_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::amt_type = [%s]\n",csTmp));
                                		PutField_CString(hRecAdd,"amt_type",csTmp);
                                	}

/* txn_amount */
					sprintf(csTag, "%s_txn_amount_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::txn_amount = [%s]\n",csTmp));
						PutField_CString(hRecAdd,"txn_amount",csTmp);
					}

/* bank_charge */
					sprintf(csTag, "%s_bank_charge_%d", PD_DETAIL_TAG, i+1);
                                	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::bank_charge = [%s]\n",csTmp));
                                        	PutField_CString(hRecAdd,"bank_charge",csTmp);
                                	}

/* sender_baid_name */
                                       	sprintf(csTag, "%s_sender_baid_name_%d", PD_DETAIL_TAG, i+1);
                                      	if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::sender_baid_name = [%s]\n", csTmp));
                                             	PutField_CString(hRecAdd,"sender_baid_name",csTmp);
                                      	}

/* recipient_baid_name */
                                      	sprintf(csTag, "%s_recipient_baid_name_%d", PD_DETAIL_TAG, i+1);
                                        if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::recipient_baid_name = [%s]\n", csTmp));
                                           	PutField_CString(hRecAdd,"recipient_baid_name",csTmp);
                                      	}

/* client_name */
                                        sprintf(csTag, "%s_client_name_%d", PD_DETAIL_TAG, i+1);
                                        if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::client_name = [%s]\n", csTmp));
                                                PutField_CString(hRecAdd,"client_name",csTmp);
                                        }

/* txn_location */
					sprintf(csTag, "%s_txn_location_%d", PD_DETAIL_TAG, i+1);
					if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::txn_location = [%s]\n", csTmp));
						PutField_CString(hRecAdd,"txn_location",csTmp);
					}

/* txn_type */
					sprintf(csTag, "%s_txn_type_%d", PD_DETAIL_TAG, i+1);
					if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::txn_type = [%s]\n", csTmp));
						PutField_CString(hRecAdd,"txn_type",csTmp);
					}

/* txn_reference */
					sprintf(csTag, "%s_txn_reference_%d", PD_DETAIL_TAG, i+1);
					if (GetField_CString(hRecTemp, csTag, &csTmp)) {
DEBUGLOG(("Authorize() AddDetail::txn_reference = [%s]\n", csTmp));
						PutField_CString(hRecAdd,"txn_reference",csTmp);
					}

DEBUGLOG(("Authorize() call DBOLStatementTmp(AddDetail)::Add()\n"));

                        		DBObjPtr = CreateObj(DBPtr, "DBOLStatementTmp", "AddDetail");
                        		iRet = (unsigned long)(*DBObjPtr)(hRecAdd);
                        		if (iRet != PD_OK) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(AddDetail)::Add() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() call DBOLStatementTmp:: AddDetail() FAILURE!!!\n");
					}
				}
			
/*---------------Get Statement Tmp (First Seq Record) Detail---------------*/
                        	if (iRet == PD_OK) {

                                	DBObjPtr = CreateObj(DBPtr,"DBOLStatementTmp","GetFirstSeqRecDetail");
                                	iRet = (unsigned long)(*DBObjPtr)(csFileId,hRecGet);
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetFirstSeqRecDetail)::iRet = [%d]\n",iRet));

                               		if (iRet == PD_OK) {

/* create_user */
                                        	if (GetField_CString(hRecGet, "create_user", &csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetFirstSeqRecDetail)::create_user = [%s]\n", csTmp));
                                			PutField_CString(hRecUpdate,"create_user",csTmp);
                                        	}

/* create_timestamp */
                                        	if (GetField_CString(hRecGet, "create_timestamp", &csTmp)) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetFirstSeqRecDetail)::create_timestamp = [%s]\n", csTmp));
                                			PutField_CString(hRecUpdate,"create_timestamp",csTmp);
                                        	}

                                	} else {
                                        	iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLStatementTmp(GetFirstSeqRecDetail):: failed\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() call DBOLStatementTmp:: GetFirstSeqRecDetail() failed!!!\n");
                                	}
                        	}

/*---------------Update Statement Tmp Detail---------------*/
                        	if (iRet == PD_OK) {

/* file_id */
                                	PutField_CString(hRecUpdate,"file_id",csFileId);
DEBUGLOG(("Authorize() UpdateUserTimestampDetail::file_id = [%s]\n",csFileId));

/* seq */
                                	PutField_Int(hRecUpdate, "seq",iSeq);
DEBUGLOG(("Authorize() UpdateUserTimestampDetail::seq = [%d]\n",iSeq));

/* ver */
                                	PutField_Int(hRecUpdate, "ver",iVer);
DEBUGLOG(("Authorize() UpdateUserTimestampDetail::ver = [%d]\n",iVer));

DEBUGLOG(("Authorize() call DBOLStatementTmp(UpdateUserTimestampDetail)::Update()\n"));

                                	DBObjPtr = CreateObj(DBPtr, "DBOLStatementTmp", "UpdateUserTimestampDetail");
                                	iRet = (unsigned long)(*DBObjPtr)(hRecUpdate);
                                	if (iRet != PD_OK) {
DEBUGLOG(("Authorize() call DBOLStatementTmp(UpdateUserTimestampDetail)::Update() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() call DBOLStatementTmp:: UpdateUserTimestampDetail() FAILURE!!!\n");
                                	}

                        	}

/*---------------Add Order Detail---------------*/
                              	if (iRet == PD_OK) {

					sprintf(csTag, "%s_seq_%d", PD_DETAIL_TAG, i+1);
                                      	if (GetField_CString(hRecTemp, csTag, &csOrderSeq)) {
DEBUGLOG(("Authorize() AddOrderDetail::order_seq = [%s]\n", csOrderSeq));
                                   	}
						
					sprintf(csTag, "%s_ver_%d", PD_DETAIL_TAG, i+1);
                                      	if (GetField_CString(hRecTemp, csTag, &csOrderVer)) {
DEBUGLOG(("Authorize() AddOrderDetail::order_ver = [%s]\n", csOrderVer));
                                     	}
	
					sprintf(csTag, "%s_%s_%s", csFileId, csOrderSeq, csOrderVer);
					sprintf(csTmp, "%s_%d_%d", csFileId, iSeq, iVer);
					PutField_CString(hRecOrder,csTag,csTmp);  
DEBUGLOG(("Authorize() AddOrderDetail::%s = [%s]\n", csTag,csTmp));
	
					sprintf(csTag, "%s_%s_%s_file_id", csFileId, csOrderSeq, csOrderVer);
                                      	sprintf(csTmp, "%s", csFileId);
					PutField_CString(hRecOrder,csTag,csTmp);
DEBUGLOG(("Authorize() AddOrderDetail::%s = [%s]\n", csTag,csTmp));

					sprintf(csTag, "%s_%s_%s_seq", csFileId, csOrderSeq, csOrderVer);
					sprintf(csTmp, "%d", iSeq);
					PutField_CString(hRecOrder,csTag,csTmp);
DEBUGLOG(("Authorize() AddOrderDetail::%s = [%s]\n", csTag,csTmp));

					sprintf(csTag, "%s_%s_%s_ver", csFileId, csOrderSeq, csOrderVer);
                                       	sprintf(csTmp, "%d", iVer);
					PutField_CString(hRecOrder,csTag,csTmp);
DEBUGLOG(("Authorize() AddOrderDetail::%s = [%s]\n", csTag,csTmp));

				}
			}
		}
	}

/*------------------------------------------------------Order Record------------------------------------------------------*/
DEBUGLOG(("Authorize() OrderRecord()\n"));
	
 	if (iRet == PD_OK) {

/* total_order_cnt */
		if (GetField_Int(hRecTemp,"total_order_cnt",&iOrderCnt)) {
DEBUGLOG(("Authorize() order() total_order_cnt = [%d]\n",iOrderCnt));
                }

                for (i = 0; i < iOrderCnt; i++) {
DEBUGLOG(("Authorize() order() order_cnt = [%d]\n", i));

			hash_init(hRecGet,0);
        		hash_init(hRecUpdate,0);

			sprintf(csTag, "%s_%d", PD_ORDER_TAG, i+1);
                        if (GetField_CString(hRecTemp, csTag, &csTmp)) {				
				sprintf(csTag, "%s", csTmp);
				if (GetField_CString(hRecOrder, csTag, &csTmp)) {
DEBUGLOG(("Authorize() order() %s = [%s]\n", csTag,csTmp));					

/*---------------Get file_id and seq from hRecOrder---------------*/
/* file_id */
                        		sprintf(csTagName, "%s_file_id", csTag);
                        		if (GetField_CString(hRecOrder, csTagName, &csFileId)) {
DEBUGLOG(("Authorize() order() file_id = [%s]\n", csFileId));
                                		PutField_CString(hRecUpdate,"file_id",csFileId);
                        		} else {
                                		iRet = INT_FILE_ID_NOT_FOUND;
                                		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() order() file_id not found!!!\n"));
ERRLOG("TxnOmtByUsBSE:: Authorize() order() file_id not found!!!\n");
                       			}

/* seq */
					sprintf(csTagName, "%s_seq", csTag);
                                        if (GetField_CString(hRecOrder, csTagName, &csTmp)) {
                                		iSeq = atoi(csTmp);
DEBUGLOG(("Authorize() order() seq = [%d]\n", iSeq));
                                		PutField_Int(hRecUpdate,"seq",iSeq);
                        		} else {
                                		iRet = INT_STATEMENT_SEQ_NOT_FOUND;
                                		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() order() seq not found!!!\n"));
ERRLOG("TxnOmtByUsBSE:: Authorize() order() seq not found!!!\n");
                        		}
				} else {
/*---------------Get file_id and seq from hRecTemp---------------*/
/* file_id */
                        		sprintf(csTag, "%s_file_id_%d", PD_ORDER_TAG, i+1);
                        		if (GetField_CString(hRecTemp, csTag, &csFileId)) {
DEBUGLOG(("Authorize() order() file_id = [%s]\n", csFileId));
                                		PutField_CString(hRecUpdate,"file_id",csFileId);
                        		} else {
                                		iRet = INT_FILE_ID_NOT_FOUND;
                                		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() order() file_id not found!!!\n"));
ERRLOG("TxnOmtByUsBSE:: Authorize() order() file_id not found!!!\n");
                        		}

/* seq */
                        		sprintf(csTag, "%s_seq_%d", PD_ORDER_TAG, i+1);
                        		if (GetField_CString(hRecTemp, csTag, &csTmp)) {
                                		iSeq = atoi(csTmp);
DEBUGLOG(("Authorize() order() seq = [%d]\n", iSeq));
                                		PutField_Int(hRecUpdate,"seq",iSeq);
                        		} else {
                                		iRet = INT_STATEMENT_SEQ_NOT_FOUND;
                                		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() order() seq not found!!!\n"));
ERRLOG("TxnOmtByUsBSE:: Authorize() order() seq not found!!!\n");
                        		}
				}
			}

/*---------------Get user_seq from hRecTemp---------------*/
			if (iRet == PD_OK) {
/* user_seq */
                        	sprintf(csTag, "%s_user_seq_%d", PD_ORDER_TAG, i+1);
                        	if (GetField_Int(hRecTemp, csTag, &iUserSeq)) {
DEBUGLOG(("Authorize() order() user_seq = [%d]\n", iUserSeq));
                                	PutField_Int(hRecUpdate,"user_seq",iUserSeq);
                        	}
			}

/*---------------Get ver from DB GetLastVerRecDetail---------------*/
			if (iRet == PD_OK) {
                        	DBObjPtr = CreateObj(DBPtr,"DBOLStatementTmp","GetLastVerRecDetail");
                            	iRet = (unsigned long)(*DBObjPtr)(csFileId,iSeq,hRecGet);
DEBUGLOG(("Authorize() order() call DBOLStatementTmp(GetLastVerRecDetail)::iRet = [%d]\n",iRet));

                           	if (iRet == PD_OK) {
/* ver */
                              		if (GetField_Int(hRecGet,"ver",&iLastVer)) {
DEBUGLOG(("Authorize() order() call DBOLStatementTmp(GetLastVerRecDetail)::ver = [%d]\n",iLastVer));
                                       	}

				} else {
                                 	iRet = INT_ERR;
DEBUGLOG(("Authorize() order() call DBOLStatementTmp(GetLastVerRecDetail):: failed\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() order() call DBOLStatementTmp:: GetLastVerRecDetail() failed!!!\n");
                           	}
			}

/*---------------Update Statement Tmp Seq Detail---------------*/
		  	if (iRet == PD_OK) {

/* file_id */
                           	PutField_CString(hRecUpdate,"file_id",csFileId);
DEBUGLOG(("Authorize() order() UpdateSeqDetail::file_id = [%s]\n",csFileId));

/* seq */
                           	PutField_Int(hRecUpdate, "seq",iSeq);
DEBUGLOG(("Authorize() order() UpdateSeqDetail::seq = [%d]\n",iSeq));

/* ver */
                           	PutField_Int(hRecUpdate, "ver",iLastVer);
DEBUGLOG(("Authorize() order() UpdateSeqDetail::ver = [%d]\n",iLastVer));

/* sys_seq */
                                iSysSeq = iUserSeq;
                                PutField_Int(hRecUpdate,"sys_seq",iSysSeq);
DEBUGLOG(("Authorize() order() UpdateSeqDetail::sys_seq = [%d]\n",iSysSeq));

/* user_seq */
                            	PutField_Int(hRecUpdate,"user_seq",iUserSeq);
DEBUGLOG(("Authorize() order() UpdateSeqDetail::user_seq = [%d]\n",iUserSeq));

DEBUGLOG(("Authorize() order() call DBOLStatementTmp(UpdateSeqDetail)::Update()\n"));

                          	DBObjPtr = CreateObj(DBPtr, "DBOLStatementTmp", "UpdateSeqDetail");
                            	iRet = (unsigned long)(*DBObjPtr)(hRecUpdate);
                             	if (iRet != PD_OK) {
DEBUGLOG(("Authorize() order() call DBOLStatementTmp(UpdateSeqDetail)::Update() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() order() call DBOLStatementTmp:: UpdateSeqDetail() FAILURE!!!\n");
                             	}

                      	}
		}
	}	

/*----------------------------------------------------------------Update Statement Header----------------------------------------------------------------*/
        if (iRet == PD_OK) {

/* file_id */
                PutField_CString(hRecUpdate, "file_id",csFileId);
DEBUGLOG(("Authorize() UpdateHeader::file_id = [%s]\n",csFileId));

/* header_ver */
		PutField_Int(hRecUpdate, "ver",iHeaderVer);
DEBUGLOG(("Authorize() UpdateHeader::header_ver = [%d]\n",iHeaderVer));

/* update_user */
                PutField_CString(hRecUpdate,"update_user",csUser);
DEBUGLOG(("Authorize() UpdateHeader::update_user = [%s]\n",csUser));

DEBUGLOG(("Authorize() call DBOLStatement(DBOLStatement)::UpdateHeader()\n"));

                DBObjPtr = CreateObj(DBPtr, "DBOLStatement", "UpdateHeader");
                iRet = (unsigned long)(*DBObjPtr)(hRecUpdate);
                if (iRet != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLStatement(DBOLStatement)::UpdateHeader() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsBSE::Authorize() call DBOLStatement:: UpdateHeader() FAILURE!!!\n");
                }
        }

/*----------------------------------------------------------------Results----------------------------------------------------------------*/
	if (iRet != PD_OK) {
		PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() internal_error! iRet = [%d]\n", iRet));
	}

	PutField_Int(hResponse,"ret",iRet);
	
	hash_destroy(hRecTemp);
        FREE_ME(hRecTemp);
	hash_destroy(hRecOrder);
	FREE_ME(hRecOrder);
	hash_destroy(hEditInfo);
	FREE_ME(hEditInfo);

	hash_destroy(hRecGet);
	FREE_ME(hRecGet);
	hash_destroy(hRecAdd);
        FREE_ME(hRecAdd);
	hash_destroy(hRecUpdate);
        FREE_ME(hRecUpdate);

DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}
