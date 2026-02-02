/*
 * PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
 * of an authorized representative of PDProTech.
 *
 * Change Description                                 Change Date             Change By
 * -------------------------------                    ------------            --------------
 *  Init Version                                      2018/11/22              LokMan Chow
 *  Add checking
 *  	- bank_acct_cnt
 *  	- req_dt				      2019/08/22	      Elvis Wong	
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
#include "BOCommChk.h"
#include "dbutility.h"

 
static char    cDebug;

#define MY_CHAR_LA	0x61
#define MY_CHAR_LZ	0x7A
#define MY_CHAR_UA	0x41
#define MY_CHAR_UZ	0x5A
#define MY_DIGIT_0	0x30
#define MY_DIGIT_1	0x31
#define MY_DIGIT_9	0x39


OBJPTR(DB);

void BOCommChk(char    cdebug)
{
        cDebug = cdebug;
}


int OiaRequest(const hash_t* hIn, hash_t *hContext) 
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	*csTable;
	char	*csField;
	char	*csTag;
	char	*csVal;
	char	*csTxnCcy;
	int	iChkRef = PD_FALSE;
	int	iOnlyDigit = PD_FALSE;
	int	iMinLen = 0;
	int	iMaxLen = 0;
	double	dTxnAmt = 0.0;

DEBUGLOG(("OiaRequest()\n"));

	GetField_Int(hIn, "only_digit", &iOnlyDigit);
	GetField_Int(hIn, "min_len", &iMinLen);
	GetField_Int(hIn, "max_len", &iMaxLen);

	if(GetField_CString(hIn, "ref_def_table", &csTable) &&
	   GetField_CString(hIn, "ref_def_field", &csField)){
		iChkRef = PD_TRUE;
	}

	if(GetField_CString(hIn, "field_tag", &csTag)){

		if(!strcmp(csTag, "baid_cnt")){
DEBUGLOG((" check baid_cnt\n"));
                      	PutField_Int(hContext,"min_baid_cnt",iMinLen);
                      	PutField_Int(hContext,"max_baid_cnt",iMaxLen);
		} else if(!strcmp(csTag, "bank_acct_cnt")){
DEBUGLOG((" check bank_acct_cnt\n"));
                        PutField_Int(hContext,"min_bank_acct_cnt",iMinLen);
                        PutField_Int(hContext,"max_bank_acct_cnt",iMaxLen);
             	} else {

			if(GetField_CString(hIn, csTag, &csVal)){
DEBUGLOG((" check %s[%s]\n", csTag, csVal));

				if(iOnlyDigit){
					if(is_numeric(csVal) != PD_TRUE){
						iRet = INT_ERR; 
DEBUGLOG((" - not numeric\n"));
					}
				}

				if((iMinLen > 0) && (strlen(csVal) < iMinLen)){
						iRet = INT_ERR; 
DEBUGLOG((" - too short\n"));
				}

				if((iMaxLen > 0) && (strlen(csVal) > iMaxLen)){
						iRet = INT_ERR; 
DEBUGLOG((" - too long\n"));
				}

				if(iChkRef){
					DBObjPtr = CreateObj(DBPtr,"DBTxnFieldCheck","ChkDefReference");
					if((unsigned long)(DBObjPtr)(csVal, csTable, csField) != PD_OK) {
						iRet = INT_ERR; 
DEBUGLOG((" - no DEF reference\n"));
					}
				}

				if(iRet == PD_OK && !strcmp(csTag, "txn_amt")){
					if(GetField_CString(hIn, csTag, &csPtr)){

						char	*csTxnAmt;
						csTxnAmt = (char*) malloc (PD_TMP_BUF_LEN + 1);
						memset(csTxnAmt, 0, sizeof(csTxnAmt));
						strcpy(csTxnAmt, csPtr);

						char    *p;
						p = mystrtok(csPtr, ".");
						if (p == NULL){
							iRet = INT_ERR;
						}
						else{
							if(is_numeric(p) != PD_TRUE){
								iRet = INT_ERR;
							}
							else{
								p = mystrtok(NULL, ".");
								if (p == NULL){
									iRet = INT_ERR;
								}
								else if(is_numeric(p) != PD_TRUE || strlen(p) != PD_DECIMAL_LEN){
									iRet = INT_ERR;
								}

								while( (p = mystrtok(NULL, ".")) != NULL) {
									iRet = INT_ERR;
									break;
								}
							}					
						}

						if(iRet == PD_OK){
							dTxnAmt = newround(string2double((const unsigned char *)csTxnAmt), PD_DECIMAL_LEN);
							long	lTmp;

							if(GetField_CString(hIn, "ref_ccy", &csTxnCcy)){
								DBObjPtr = CreateObj(DBPtr,"DBCurrency","FindCurrency");
								if ((unsigned long)(DBObjPtr)(csTxnCcy) == FOUND) {
									DBObjPtr = CreateObj(DBPtr,"DBCurrency","IsSupportDecimal");
									if ((unsigned long)((DBObjPtr)(csTxnCcy)) != PD_TRUE){
										lTmp = (long) dTxnAmt;
										if (dTxnAmt > lTmp) {
											iRet = INT_ERR;
DEBUGLOG((" - reference currency[%s] does not support decimal\n", csTxnCcy));
	
										}
									}
								}
							}
						}

						if(iRet == PD_OK){
							PutField_Double(hContext,"txn_amt",dTxnAmt);
							PutField_Double(hContext,"org_txn_amt",dTxnAmt);
						}
						else{
DEBUGLOG((" - unexpected amount format\n"));
						}

						FREE_ME(csTxnAmt);
					}
				}
				else if(iRet == PD_OK && !strcmp(csTag, "txn_ccy")){
					if(GetField_CString(hIn, csTag, &csPtr)){
						DBObjPtr = CreateObj(DBPtr,"DBCurrency","FindCurrency");
						if ((unsigned long)(DBObjPtr)(csPtr) == FOUND) {
							PutField_CString(hContext,"net_ccy",csPtr);
							PutField_CString(hContext,"org_txn_ccy",csPtr);
						}
						else{
							iRet = INT_ERR;
DEBUGLOG((" - DBCurrency::FindCurrency [%s]failed\n", csPtr));
						}
					}
				}
				else if(iRet == PD_OK && !strcmp(csTag, "req_ref")){
					if(GetField_CString(hIn, csTag, &csPtr)){
						int i;
						for(i = 0; i < strlen(csPtr); i++){
							if(!ascii_range(&csPtr[i], 1, MY_CHAR_UA, MY_CHAR_UZ) &&
							   !ascii_range(&csPtr[i], 1, MY_CHAR_LA, MY_CHAR_LZ) &&
							   !ascii_range(&csPtr[i], 1, MY_DIGIT_0, MY_DIGIT_9)){
DEBUGLOG((" - included unsupport charater(s)\n"));
								iRet = INT_ERR;
								break;
							}
						}
					}
				}
				else if(iRet == PD_OK && !strcmp(csTag, "req_dt")){
                                        if(GetField_CString(hIn, csTag, &csPtr)){
                                                if(check_valid_datetime(csPtr) != PD_OK) {
DEBUGLOG((" - invalid datetime format\n"));
                                                        iRet = INT_ERR;
                                                }
                                        }
                                }
				else if(iRet == PD_OK && !strcmp(csTag, "rec_date")){
					if(GetField_CString(hIn, csTag, &csPtr)){
						if(check_valid_date(csPtr) != PD_OK) {
DEBUGLOG((" - invalid date format\n"));
                                                	iRet = INT_ERR;								
						}
					}
				}
				else if(iRet == PD_OK && (!strcmp(csTag, "auto_upload_ind") || !strcmp(csTag, "bal_over_ind"))){
					if(GetField_CString(hIn, csTag, &csPtr)){
						if(!ascii_range(&csPtr[0], 1, MY_DIGIT_0, MY_DIGIT_1)){	
DEBUGLOG((" - included unsupport numeric(s)\n"));
							iRet = INT_ERR;
						}
                                        }
				}
			}
		}
	}
	
DEBUGLOG(("OiaRequest() iRet = [%d]\n",iRet));
	return iRet;
}
