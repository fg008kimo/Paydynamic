/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2016/08/24              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "HeeMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "internal.h"
#include "ObjPtr.h"

char	cDebug;
OBJPTR(DB);

void	HeeMsg(char cdebug)
{
	cDebug = cdebug;
}

int FormatMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int	iRet = PD_OK;
	char*   csTmp = NULL;
	char*   csPtr = NULL;
	char*   csBuf;
	double  dTmp;
	char*   csMethod = NULL;
	char    *p;
        char    csIP[PD_TMP_BUF_LEN+1];

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

	memset(outMsg,0,sizeof(outMsg));
	if (GetField_CString(hIn,"redirect_url",&csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char *)outMsg,csPtr);
		strcat((char *)outMsg,"?");
		strcat((char*)outMsg,MY_HEE_TOKEN);

/* 1 version*/
		strcat((char*)outMsg,"version");
		strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
		strcat((char*)outMsg,"1");
		strcat((char*)outMsg,MY_HEE_TOKEN);


/* 2 agent_id*/
		if (GetField_CString(hIn,"psp_merchant_id",&csTmp)) {
			strcat((char*)outMsg,"agent_id");
			strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_HEE_TOKEN);
DEBUGLOG(("FormatMsg:: agent_id = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***psp_merchant_id is missing\n"));
		}

/* 3 agent_bill_id*/

		if (GetField_CString(hIn,"txn_seq",&csTmp)) {
			strcat((char*)outMsg,"agent_bill_id");
			strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_HEE_TOKEN);
DEBUGLOG(("FormatMsg:: agent_bill_id = [%s]\n",csTmp));
		}


/* 4 agent_bill_time*/
                if (GetField_CString(hIn,"local_tm_date",&csTmp)) {
DEBUGLOG(("FormatMsg:: local_tm_date = [%s]\n",csTmp));
                        char*   csPtr2;
                        char    csDateTime[PD_DATETIME_LEN * 2];
                        if (GetField_CString(hIn,"local_tm_time",&csPtr2)) {
DEBUGLOG(("FormatMsg:: local_tm_time = [%s]\n",csPtr2));
                                sprintf(csDateTime,"%s%s",csTmp,csPtr2);
DEBUGLOG(("FormatMsg:: agent_bill_time = [%s]\n",csDateTime));
                                strcat((char*)outMsg,"agent_bill_time");
                                strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
                                strcat((char*)outMsg,csDateTime);
                                strcat((char*)outMsg,MY_HEE_TOKEN);
                        }
                        else {
DEBUGLOG(("FormatMsg:: local_tm_time is missing!!!\n"));
                        }
                }
                else {
DEBUGLOG(("FormatMsg:: local_tm_date is missing!!!\n"));
                }


/* 5 pay_type*/
		strcat((char*)outMsg,"pay_type");
		strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
		strcat((char*)outMsg,"20");
		strcat((char*)outMsg,MY_HEE_TOKEN);


/* 6 pay_amt*/
		if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {

			char    csTmpAmt[PD_TMP_BUF_LEN +1];
			sprintf((char*)csTmpAmt,"%.2f",dTmp);
			strcat((char*)outMsg,"pay_amt");
			strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
			strcat((char*)outMsg,csTmpAmt);
			strcat((char*)outMsg,MY_HEE_TOKEN);
DEBUGLOG(("FormatMsg:: pay_amt = [%s]\n",csTmpAmt));
		}
		else {
DEBUGLOG(("FormatMsg:: psp_txn_amt is missing!!!\n"));
		}


/* 7 notify_url*/
		if (GetField_CString(hIn,"return_url_only",&csTmp)) {
			strcat((char*)outMsg,"notify_url");
			strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_HEE_TOKEN);
DEBUGLOG(("FormatMsg:: notify_url = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** notify_url_only is missing\n"));
		}


/* 8 return_url */
		if (GetField_CString(hIn,"return_url_only",&csTmp)) {
			strcat((char*)outMsg,"return_url");
			strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,"fe/");
			strcat((char*)outMsg,MY_HEE_TOKEN);
DEBUGLOG(("FormatMsg:: return_url = [%sfe/]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** fe_url is missing\n"));
		}


/* 9 user_ip*/
		if (GetField_CString(hIn,"user_ip",&csPtr)) {
DEBUGLOG(("FormatMsg:: user_ip = [%s]\n",csPtr));
			p = mystrtok(csPtr,".");
			if (p){
				sprintf(csIP,"%s",p);
				while ((p = mystrtok(NULL,".")) != NULL) {
					strcat(csIP,"_");
					strcat(csIP,p);
				}
			}
			strcat((char*)outMsg,"user_ip");
			strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
			strcat((char*)outMsg,csIP);
			strcat((char*)outMsg,MY_HEE_TOKEN);
DEBUGLOG(("FormatMsg:: formated user_ip = [%s]\n",csIP));
		}
		else {
DEBUGLOG(("FormatMsg:: user_ip is missing!!!\n"));
		}

/*10 goods_name*/
		strcat((char*)outMsg,"goods_name");
		strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
		strcat((char*)outMsg,"Payment");
		strcat((char*)outMsg,MY_HEE_TOKEN);

/*11 goods_num*/
		strcat((char*)outMsg,"goods_num");
		strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
		strcat((char*)outMsg,MY_HEE_TOKEN);

/*12 goods_note*/
		strcat((char*)outMsg,"goods_note");
		strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
		strcat((char*)outMsg,MY_HEE_TOKEN);


/*13 pay_code */
		if (GetField_CString(hIn,"bank_code",&csTmp)) {
			strcat((char*)outMsg,"pay_code");
			strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
                        strcat((char*)outMsg,MY_HEE_TOKEN);
DEBUGLOG(("FormatMsg:: pay_code = [%s]\n",csTmp));
		}
		else {
DEBUGLOG(("FormatMsg:: bank_code is missing!!!\n"));
		}


/*14 remark*/
		if (GetField_CString(hIn,"txn_seq",&csTmp)) {
			strcat((char*)outMsg,"remark");
			strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_HEE_TOKEN);
DEBUGLOG(("FormatMsg:: remark = [%s]\n",csTmp));
		}


/*15 sign*/
		if (GetField_CString(hIn,"sign",&csTmp)) {
			strcat((char*)outMsg,"sign");
			strcat((char*)outMsg,MY_HEE_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_HEE_TOKEN);
DEBUGLOG(("FormatMsg:: signMsg = [%s]\n",csTmp));
		}

/* url_method */
                if (GetField_CString(hIn,"url_method",&csMethod)) {
DEBUGLOG(("FormatMsg:: url_method = [%s]\n",csMethod));
                }

DEBUGLOG(("FormatMsg:: outmsg = [%s]\n",outMsg));
		base64_encode(outMsg,strlen((char *)outMsg),csBuf,PD_MAX_BUFFER);
DEBUGLOG(("FormatMsg:: after encode\n"));
                outMsg[0] = '\0';
                strcat((char*)outMsg,"redirect_url");
                strcat((char*)outMsg,"=");
                strcat((char*)outMsg,csBuf);
                strcat((char*)outMsg,MY_HEE_TOKEN);
		strcat((char*)outMsg,"url_method");
		strcat((char*)outMsg,"=");
		strcat((char*)outMsg,csMethod);
                strcat((char*)outMsg,MY_HEE_TOKEN);
		strcat((char*)outMsg,"ret_status=0");
DEBUGLOG(("FormatMsg:: outMsg = [%s]\n",outMsg));

		*outLen = strlen((const char*)outMsg);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: Redirct url not found\n"));
	}


DEBUGLOG(("FormatMsg:: normal exit iret =[%d]\n",iRet));
	FREE_ME(csBuf);
	return 	iRet;
}



int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr;
	hash_t  *hRec;

        hRec = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRec,0);

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

	if (Str2Cls(hRec,(char *)inMsg,MY_HEE_TOKEN, MY_HEE_FIELD_TOKEN) == PD_OK) {

/* 1 result*/
		if (GetField_CString(hRec,"result",&csPtr)) {
			PutField_CString(hOut,"status",csPtr);
DEBUGLOG(("BreakDownMsg:: status = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: status not found\n"));
		}

/* 2 agent_id*/
		if (GetField_CString(hRec,"agent_id",&csPtr)) {
			PutField_CString(hOut,"agent_id",csPtr);
DEBUGLOG(("BreakDownMsg:: agent_id = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: agent_id not found\n"));
		}

/* 3 jnet_bill_no*/
		if (GetField_CString(hRec,"jnet_bill_no",&csPtr)) {
			PutField_CString(hOut,"tid",csPtr);
DEBUGLOG(("BreakDownMsg:: jnet_bill_no = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: jnet_bill_no not found\n"));
		}

/* 4 agent_bill_id*/
		if (GetField_CString(hRec,"agent_bill_id",&csPtr)) {
			PutField_CString(hOut,"txn_seq",csPtr);
DEBUGLOG(("BreakDownMsg:: agent_bill_id = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: agent_bill_id not found\n"));
		}

/* 5 pay_type*/
                if (GetField_CString(hRec,"pay_type",&csPtr)) {
			PutField_CString(hOut,"pay_type",csPtr);
DEBUGLOG(("BreakDownMsg:: pay_type = [%s]\n",csPtr));
                }

/* 6 pay_amt */
		if (GetField_CString(hRec,"pay_amt",&csPtr)) {
			PutField_CString(hOut,"txn_amt",csPtr);
DEBUGLOG(("BreakDownMsg:: pay_amt = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: pay_amt not found\n"));
		}

/* 7 remark */
                if (GetField_CString(hRec,"remark",&csPtr)) {
			PutField_CString(hOut,"remark",csPtr);
DEBUGLOG(("BreakDownMsg:: remark = [%s]\n",csPtr));
                }

/* 8 pay_message*/
                if (GetField_CString(hRec,"pay_message",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: pay_message = [%s]\n",csPtr));
                }

/* 9 sign*/
                if (GetField_CString(hRec,"sign",&csPtr)) {
                        PutField_CString(hOut,"sign",csPtr);
DEBUGLOG(("BreakDownMsg:: sign = [%s]\n",csPtr));
                }
                else{
DEBUGLOG(("BreakDownMsg:: sign not found\n"));
                }

	}
	else {
DEBUGLOG(("BreakDownMsg() Error\n"));
                iRet = PD_ERR;
        }
        
        hash_destroy(hRec);
	FREE_ME(hRec);

DEBUGLOG(("BreakDownMsg Exit\n"));
	return	iRet;
}

int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
	int	iRet = PD_OK;

	return iRet;
}


int BuildAuthData(hash_t* hIn)
{
        int     iRet = PD_OK;
        char*   csPtr = NULL;
        char*   csBuf = NULL;
	char    *p;
        char    csIP[PD_TMP_BUF_LEN+1];
	double	dTmp;
        csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf,0,MAX_MSG_SIZE);
	csBuf[0] = '\0';


/* 1 version*/
	strcat((char*)csBuf,"version");
	strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
	strcat((char*)csBuf,"1");
	strcat((char*)csBuf,MY_HEE_TOKEN);


/* 2 agent_id*/
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
		strcat((char*)csBuf,"agent_id");
		strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_HEE_TOKEN);
DEBUGLOG(("BuildAuthData:: agent_id = [%s]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: ***psp_merchant_id is missing\n"));
	}

/* 3 agent_bill_id*/

	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
		strcat((char*)csBuf,"agent_bill_id");
		strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_HEE_TOKEN);
DEBUGLOG(("BuildAuthData:: agent_bill_id = [%s]\n",csPtr));
	}


/* 4 agent_bill_time*/
	if (GetField_CString(hIn,"local_tm_date",&csPtr)) {
DEBUGLOG(("BuildAuthData:: local_tm_date = [%s]\n",csPtr));
		char*   csPtr2;
		char    csDateTime[PD_DATETIME_LEN * 2];
		if (GetField_CString(hIn,"local_tm_time",&csPtr2)) {
DEBUGLOG(("BuildAuthData:: local_tm_time = [%s]\n",csPtr2));
			sprintf(csDateTime,"%s%s",csPtr,csPtr2);
DEBUGLOG(("BuildAuthData:: agent_bill_time = [%s]\n",csDateTime));
			strcat((char*)csBuf,"agent_bill_time");
			strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
			strcat((char*)csBuf,csDateTime);
			strcat((char*)csBuf,MY_HEE_TOKEN);
		}
		else {
DEBUGLOG(("BuildAuthData:: local_tm_time is missing!!!\n"));
		}
	}
	else {
DEBUGLOG(("BuildAuthData:: local_tm_date is missing!!!\n"));
	}


/* 5 pay_type*/
	strcat((char*)csBuf,"pay_type");
	strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
	strcat((char*)csBuf,"20");
	strcat((char*)csBuf,MY_HEE_TOKEN);


/* 6 pay_amt*/
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {

		char    csPtrAmt[PD_TMP_BUF_LEN +1];
		sprintf((char*)csPtrAmt,"%.2f",dTmp);
		strcat((char*)csBuf,"pay_amt");
		strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
		strcat((char*)csBuf,csPtrAmt);
		strcat((char*)csBuf,MY_HEE_TOKEN);
DEBUGLOG(("BuildAuthData:: pay_amt = [%s]\n",csPtrAmt));
	}
	else {
DEBUGLOG(("BuildAuthData:: psp_txn_amt is missing!!!\n"));
	}


/* 7 notify_url*/
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
		strcat((char*)csBuf,"notify_url");
		strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_HEE_TOKEN);
DEBUGLOG(("BuildAuthData:: notify_url = [%s]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: *** notify_url_only is missing\n"));
	}


/* 8 return_url */
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
		strcat((char*)csBuf,"return_url");
		strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,"fe/");
		strcat((char*)csBuf,MY_HEE_TOKEN);
DEBUGLOG(("BuildAuthData:: return_url = [%sfe/]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: *** fe_url is missing\n"));
	}


/* 9 user_ip*/
	if (GetField_CString(hIn,"user_ip",&csPtr)) {
DEBUGLOG(("BuildAuthData:: user_ip = [%s]\n",csPtr));
		p = mystrtok(csPtr,".");
		if (p){
			sprintf(csIP,"%s",p);
			while ((p = mystrtok(NULL,".")) != NULL) {
				strcat(csIP,"_");
				strcat(csIP,p);
			}
		}
		strcat((char*)csBuf,"user_ip");
		strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
		strcat((char*)csBuf,csIP);
		strcat((char*)csBuf,MY_HEE_TOKEN);
DEBUGLOG(("BuildAuthData:: formated user_ip = [%s]\n",csIP));
	}
	else {
DEBUGLOG(("BuildAuthData:: user_ip is missing!!!\n"));
	}

/*10 pay_code 
	if (GetField_CString(hIn,"bank_code",&csPtr)) {
		strcat((char*)csBuf,"pay_code");
		strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_HEE_TOKEN);
DEBUGLOG(("BuildAuthData:: pay_code = [%s]\n",csPtr));
	}
	else {
DEBUGLOG(("BuildAuthData:: bank_code is missing!!!\n"));
	}
*/

	PutField_CString(hIn,"auth_data",csBuf);
DEBUGLOG(("BuildAuthData:: auth_data = [%s]\n",csBuf));
	FREE_ME(csBuf);
        
DEBUGLOG(("BuildAuthData() Exit iRet = [%d]\n",iRet));
        return  iRet;
}




int BuildRspAuthData(hash_t* hIn)
{
        int     iRet = PD_OK;
        char*   csPtr;
        char*   csBuf;
        csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf,0,MAX_MSG_SIZE);
	csBuf[0] = '\0';
	

/* 1 result*/
	if (GetField_CString(hIn,"status",&csPtr)) {
		strcat((char*)csBuf,"result");
		strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_HEE_TOKEN);
DEBUGLOG(("BuildRspAuthData:: result = [%s]\n",csPtr));
	}

/* 2 agent_id*/
	if (GetField_CString(hIn,"agent_id",&csPtr)) {
		strcat((char*)csBuf,"agent_id");
		strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_HEE_TOKEN);
DEBUGLOG(("BuildRspAuthData:: agent_id = [%s]\n",csPtr));
	}

/* 3 jnet_bill_no*/
	if (GetField_CString(hIn,"tid",&csPtr)) {
		strcat((char*)csBuf,"jnet_bill_no");
		strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_HEE_TOKEN);
DEBUGLOG(("BuildRspAuthData:: jnet_bill_no = [%s]\n",csPtr));
	}

/* 4 agent_bill_id*/
	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
		strcat((char*)csBuf,"agent_bill_id");
		strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_HEE_TOKEN);
DEBUGLOG(("BuildRspAuthData:: agent_bill_id = [%s]\n",csPtr));
	}

/* 5 pay_type*/
	if (GetField_CString(hIn,"pay_type",&csPtr)) {
		strcat((char*)csBuf,"pay_type");
		strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_HEE_TOKEN);
DEBUGLOG(("BuildRspAuthData:: pay_type = [%s]\n",csPtr));
	}

/* 6 pay_amt */
	if (GetField_CString(hIn,"txn_amt",&csPtr)) {
		strcat((char*)csBuf,"pay_amt");
		strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_HEE_TOKEN);
DEBUGLOG(("BuildRspAuthData:: pay_amt = [%s]\n",csPtr));
	}

/* 7 remark */
	if (GetField_CString(hIn,"remark",&csPtr)) {
		strcat((char*)csBuf,"remark");
		strcat((char*)csBuf,MY_HEE_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_HEE_TOKEN);
DEBUGLOG(("BuildRspAuthData:: remark = [%s]\n",csPtr));
	}


	PutField_CString(hIn,"auth_data",csBuf);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n",csBuf));
	FREE_ME(csBuf);
        
DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n",iRet));
        return  iRet;
}
