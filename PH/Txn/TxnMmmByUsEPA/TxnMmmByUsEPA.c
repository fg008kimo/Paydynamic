/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/18              Elvis Wong
Speical Handling for nature grp                    2015/07/29              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmmByUsEPA.h"
#include "myrecordset.h"

char cDebug;

OBJPTR(BO);

void TxnMmmByUsEPA(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                  hash_t* hResponse)
{
        int     iRet = PD_OK;
	
	int	iBalCnt = 0, iNatureCnt = 0;
	int	i = 0, j = 0;

	char*	csTmp = NULL;

	char    csTag[PD_TAG_LEN + 1];
	
	hash_t 	*hData = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hData,0);

DEBUGLOG(("Authorize()\n"));

/* eid (entity_id) */
	if (GetField_CString(hContext,"entity_id",&csTmp)) {
		PutField_CString(hData,"entity_id",csTmp);
DEBUGLOG(("Authorize: eid = [%s]\n",csTmp));
	} else {
DEBUGLOG(("Authorize:: eid missing!!\n"));
ERRLOG("TxnMmsByUsEPA:: Authorize:: eid missing!!\n");
		iRet = INT_MMS_ENTITY_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* bal_cnt (bal_count) */
        if (GetField_CString(hRequest,"txn_data.bal_cnt",&csTmp)) {
                //iBalCnt = atoi(csTmp);
		iBalCnt = ctos((const unsigned char*)csTmp,(strlen(csTmp)));
DEBUGLOG(("Authorize: bal_cnt = [%d]\n",iBalCnt));
        } else {
DEBUGLOG(("Authorize:: bal_cnt missing!!\n"));
ERRLOG("TxnMmsByUsEPA:: Authorize:: bal_cnt missing!!\n");
                iRet = INT_MMS_BAL_CNT_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* user */
	if (GetField_CString(hRequest,"user",&csTmp)) {
		PutField_CString(hData,"user",csTmp);
DEBUGLOG(("Authorize: user = [%s]\n",csTmp));
	} else {
DEBUGLOG(("Authorize:: user missing!!\n"));
ERRLOG("TxnMmsByUsEPA:: Authorize:: user missing!!\n");
		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* special handling for nature group */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize: Special Handling to get nature ID\n"));

		for (i=0; i < iBalCnt; i++) {
			sprintf(csTag,"txn_data.bal.%d.nat_cnt",i+1);
                        if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("Authorize: [%s] = [%s]\n",csTag,csTmp));
                                if (!is_numeric(csTmp)) {
                                        iRet = INT_INVALID_COUNT;
					PutField_Int(hContext,"internal_error",iRet);
				}
                                else {
                                        iNatureCnt = ctos((const unsigned char*)csTmp,strlen(csTmp));
                                        sprintf(csTag,"bal.%d.nat_cnt",i+1);
DEBUGLOG(("Authorize: [%s] = [%d]\n",csTag,iNatureCnt));
                                        PutField_Int(hContext,csTag,iNatureCnt);
                                }
                        }

                        if  (iRet == PD_OK) {
				for (j= 0; j < iNatureCnt; j++ ) {
/* grp */
					sprintf(csTag,"txn_data.bal.%d.nat.%d.grp",i+1,j+1);
					if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("Authorize: [%s] = [%s]\n",csTag,csTmp));
						sprintf(csTag,"bal.%d.nat.%d.grp",i+1,j+1);
DEBUGLOG(("Authorize: [%s] = [%s]\n",csTag,csTmp));
						PutField_CString(hContext,csTag,csTmp);
					}
/* val */
					sprintf(csTag,"txn_data.bal.%d.nat.%d.val",i+1,j+1);
					if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("Authorize: [%s] = [%s]\n",csTag,csTmp));
						sprintf(csTag,"bal.%d.nat.%d.val",i+1,j+1);
DEBUGLOG(("Authorize: [%s] = [%s]\n",csTag,csTmp));
						PutField_CString(hContext,csTag,csTmp);
					}
				}
/* this call will return an new nature id if not found */
				BOObjPtr = CreateObj(BOPtr,"BOMMSEntityNature","FindEntityNatureId");
				iRet =  (unsigned long)(*BOObjPtr)(hContext);
				if (iRet != PD_OK) {
DEBUGLOG(("Authorize: return from BOMMSEntityNature iRet = [%d] \n",iRet));
					PutField_Int(hContext,"internal_error",iRet);
					break;
				}
			}
		}
	}

/* Update PSP Default Nature Id */
	if (iRet == PD_OK) {

                for (i=1; i<=iBalCnt; i++) {

			sprintf(csTag,"bal.%d.nature_id",i);
                        if (GetField_CString(hContext,csTag,&csTmp)) {
				PutField_CString(hData,"nature_id",csTmp);
DEBUGLOG(("Authorize: nature_id_%d = [%s]\n",i,csTmp));
			} else {
DEBUGLOG(("Authorize:: nature_id missing!!\n"));
ERRLOG("TxnMmsByUsEPA:: Authorize:: nature_id missing!!\n");
         		       	iRet = INT_MMS_NATURE_ID_NOT_FOUND;
                		PutField_Int(hContext,"internal_error",iRet);
        		}
			
			// Update Default Nature Id
			if (iRet == PD_OK) {

DEBUGLOG(("Authorize:: Call BOMMSEntityPSP UpdateNatureIdByEntityId\n"));
            			BOObjPtr = CreateObj(BOPtr, "BOMMSEntityPSP","UpdateNatureIdByEntityId");
             			iRet = (unsigned long)(*BOObjPtr)(hContext,hData);
              			if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call BOMMSEntityPSP:: Success!!!\n"));
				} else {
                       			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Call BOMMSEntityPSP:: Failure!!!\n"));
ERRLOG("TxnOmtByUsEPA::Authorize::Call BOMMSEntityPSP:: Failure!!!\n");
				}
			}
		}
	}

	// Response
	PutField_CString(hResponse,"reply_txn_code",PD_TXN_CODE_MMS_DEFAULT_NID);
        PutField_Int(hResponse,"ret",iRet);

	hash_destroy(hData);
	FREE_ME(hData);

DEBUGLOG(("TxnMmsByUsEPA Normal Exit() reply_txn_code = [%s], iRet = [%d]\n",PD_TXN_CODE_MMS_DEFAULT_NID,iRet));
	return iRet;
}
