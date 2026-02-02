/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/13              Cody Chan
AddNewNature					   2015/06/24		   Cody Chan
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
#include "BOMMSEntityNature.h"

char    cDebug;

OBJPTR(DB);

void BOMMSEntityNature(char    cdebug)
{
        cDebug = cdebug;
}

int FindEntityNatureId(hash_t* hContext)
{
	int	iRet = PD_ERR;

	int     i= 0,j = 0,iBalCnt = 0,iNatureCnt = 0;
	char    csTag[PD_TAG_LEN +1];
        char    csNatureId[PD_NATURE_ID_LEN +1];
        char    *csGroup,*csGroupValue;
        recordset_t     *rRec;
        hash_t          *hData;

DEBUGLOG(("FindEntityNatureId ()\n"));

        rRec = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRec,0);


        if (GetField_Int(hContext,"bal_cnt",&iBalCnt)) {
DEBUGLOG(("FindEntityNatureId() bal_cnt = [%d]\n",iBalCnt));
        }

        for (i = 0 ;i < iBalCnt; i++){
		sprintf(csTag,"bal.%d.nat_cnt",i+1);
        	if (GetField_Int(hContext,csTag,&iNatureCnt)) {
DEBUGLOG(("FindEntityNatureId() [%s] = [%d]\n",csTag,iNatureCnt));

        		recordset_init(rRec,0);

			for (j = 0 ; j < iNatureCnt; j++ ) {
				sprintf(csTag,"bal.%d.nat.%d.grp",i+1,j+1);
        			GetField_CString(hContext,csTag,&csGroup);
//DEBUGLOG(("FindEntityNatureId() [%s] = [%s]\n",csTag,csGroup));
				sprintf(csTag,"nat.%d.grp",j+1);
DEBUGLOG(("FindEntityNatureId() [%s] = [%s]\n",csTag,csGroup));

				sprintf(csTag,"bal.%d.nat.%d.val",i+1,j+1);
        			GetField_CString(hContext,csTag,&csGroupValue);
//DEBUGLOG(("FindEntityNatureId() [%s] = [%s]\n",csTag,csGroupValue));
				sprintf(csTag,"nat.%d.val",j+1);
DEBUGLOG(("FindEntityNatureId() [%s] = [%s]\n",csTag,csGroupValue));

		                hData = (hash_t*) malloc (sizeof(hash_t));
                		hash_init(hData,0);
                		PutField_CString(hData,"group",csGroup);
                		PutField_CString(hData,"group_val",csGroupValue);

                		RecordSet_Add(rRec,hData);
			}

			DBObjPtr = CreateObj(DBPtr,"DBMmsEntityNatureMap","Find");
                	if ((unsigned long)(*DBObjPtr)(rRec,csNatureId) == FOUND) {
//DEBUGLOG(("FindEntityNatureId Nature ID = [%s]\n",csNatureId));
				sprintf(csTag,"bal.%d.nature_id",i+1);
DEBUGLOG(("FindEntityNatureId [%s] = [%s]\n",csTag,csNatureId));
                		PutField_CString(hContext,csTag,csNatureId);
				iRet = PD_OK;
			}
			else  {
DEBUGLOG(("FindEntityNatureId Nature ID not found,try to create new\n"));
				iRet = NewEntityNatureId(rRec,csNatureId);
				if (iRet != PD_OK) {
DEBUGLOG(("FindEntityNatureId Create New Nature ID Error\n"));
ERRLOG("BOMMSEntityNature:FindEntityNatureId Create New Nature ID Error\n");
					break;
				}
				sprintf(csTag,"bal.%d.nature_id",i+1);
                		PutField_CString(hContext,csTag,csNatureId);
DEBUGLOG(("FindEntityNatureId Create New Nature ID %s =  [%s]\n",csTag,csNatureId));
			}
		}
        }

        RecordSet_Destroy(rRec);
        FREE_ME(rRec);
DEBUGLOG(("FindEntityNatureId Normal exit iRet = [%d]\n",iRet));
	return iRet;
}
int NewEntityNatureId(recordset_t* rRec, char* csNatureId)
{
	int	iRet = PD_OK;
	char	csDesc[PD_DESC_LEN +1];
	char	*csPtr;
	hash_t	*hRec;
	hash_t	*hData;
	recordset_t* myRec;
DEBUGLOG(("NewEntityNatureId \n"));


	myRec = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(myRec,0);

        hData = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hData,0);
	csDesc[0] = '\0';
	hRec = RecordSet_GetFirst((recordset_t*) rRec);
        while (hRec) {
		if (GetField_CString(hRec,"group_val",&csPtr)) {
DEBUGLOG(("NewEntityNatureId  = [%s]\n",csPtr));
			strcat(csDesc,csPtr);
		}	
		hRec = RecordSet_GetNext((recordset_t*)rRec);
	}

	PutField_CString(hData,"desc",csDesc);
	PutField_CString(hData,"add_user",PD_UPDATE_USER);


 	DBObjPtr = CreateObj(DBPtr,"DBMmsEntityNature","NewNatureId");
	strcpy(csNatureId,(*DBObjPtr)(hData));
DEBUGLOG(("NewEntityNatureId Nature Id = [%s]\n",csNatureId));

	FREE_ME(hData);

	hRec = RecordSet_GetFirst((recordset_t*) rRec);
        while (hRec) {
		hData = (hash_t*) malloc (sizeof(hash_t));
        	hash_init(hData,0);

/* nature id */
		PutField_CString(hData,"nature_id",csNatureId);
/* group */
		if (GetField_CString(hRec,"group",&csPtr)) {
			PutField_CString(hData,"nature_grp",csPtr);
		}
/* group val */
		if (GetField_CString(hRec,"group_val",&csPtr)) {
			PutField_CString(hData,"nature_grp_val",csPtr);
		}
		PutField_CString(hData,"add_user",PD_UPDATE_USER);

		RecordSet_Add(myRec,hData);

		hRec = RecordSet_GetNext((recordset_t*)rRec);
	}

 	DBObjPtr = CreateObj(DBPtr,"DBMmsEntityNatureMap","Add");
	iRet = (unsigned long)(*DBObjPtr)(myRec);

	FREE_ME(myRec);
DEBUGLOG(("NewEntityNatureId Normal exit iRet = [%d]\n",iRet));
	return iRet;
}
