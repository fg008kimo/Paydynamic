/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/25              Dirk Wong
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
#include "BOMMSEntityRSP.h"

char    cDebug;

OBJPTR(DB);

void BOMMSEntityRSP(char    cdebug)
{
        cDebug = cdebug;
}


int AddRecord (hash_t* hData)
{
	int	iRet = PD_OK;
	char*	csTmp;

DEBUGLOG(("Add() Start!\n"));

	if (GetField_CString(hData,"id",&csTmp)) {
		PutField_CString(hData,"rsp_id",csTmp);
	}

	//Add Entity RSP
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize: Call DBMmsEntityRsp::Add\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityRsp","Add");
		iRet = (unsigned long) (*DBObjPtr)(hData);
DEBUGLOG(("Authorize: iRet = [%d] return from MMS Entity RSP Add\n",iRet));
	}


DEBUGLOG(("Add() normal exit iRet = [%d]\n",iRet));
	return iRet;
}


int UpdateRecord (hash_t* hData)
{
	int	iRet = PD_OK;
	char*	csTmp;

DEBUGLOG(("Update() Start!\n"));

	if (GetField_CString(hData,"id",&csTmp)) {
		PutField_CString(hData,"rsp_id",csTmp);
	}

	//Update Entity RSP
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize: Call DBMmsEntityRsp::Update\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityRsp","Update");
		iRet = (unsigned long) (*DBObjPtr)(hData);
DEBUGLOG(("Authorize: iRet = [%d] return from MMS Entity RSP Update\n",iRet));
	}


DEBUGLOG(("Update() normal exit iRet = [%d]\n",iRet));
	return iRet;
}


int FindRecordExists (hash_t* hData)
{
	int	iRet = PD_OK;
	char*	csTmp;

DEBUGLOG(("FindRecordExists() Start!\n"));

	if (GetField_CString(hData,"id",&csTmp)) {
		PutField_CString(hData,"rsp_id",csTmp);
	}

	if (iRet == PD_OK) {
DEBUGLOG(("FindRecordExists: Call DBMmsEntityRsp::FindRecordExists\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityRsp","FindRecordExists");
		if ((unsigned long)(*DBObjPtr)(hData) == PD_FOUND) {
DEBUGLOG(("FindRecordExists: Record found, return ERROR!\n"));
			iRet = INT_MMS_RSP_EXISTS;
		}
	}


DEBUGLOG(("Add() normal exit iRet = [%d]\n",iRet));
	return iRet;
}



