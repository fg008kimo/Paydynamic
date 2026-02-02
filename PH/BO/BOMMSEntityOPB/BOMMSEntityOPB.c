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
#include "BOMMSEntityOPB.h"

char    cDebug;

OBJPTR(DB);

void BOMMSEntityOPB(char    cdebug)
{
        cDebug = cdebug;
}


int AddRecord (hash_t* hData)
{
	int	iRet = PD_OK;
	char*	csTmp;

DEBUGLOG(("Add() Start!\n"));

	if (GetField_CString(hData,"id",&csTmp)) {
		PutField_CString(hData,"opb_id",csTmp);
	}

	//Add Entity OpBank
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize: Call DBMmsEntityOpBank::Add\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityOpb","Add");
		iRet = (unsigned long) (*DBObjPtr)(hData);
DEBUGLOG(("Authorize: iRet = [%d] return from MMS Entity Opb Add\n",iRet));
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
		PutField_CString(hData,"opb_id",csTmp);
	}

	//Update Entity OpBank
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize: Call DBMmsEntityOpb::Update\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityOpb","Update");
		iRet = (unsigned long) (*DBObjPtr)(hData);
DEBUGLOG(("Authorize: iRet = [%d] return from MMS Entity Opb Update\n",iRet));
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
		PutField_CString(hData,"opb_id",csTmp);
	}

	if (iRet == PD_OK) {
DEBUGLOG(("FindRecordExists: Call DBMmsEntityOpb::FindRecordExists\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityOpb","FindRecordExists");
		if ((unsigned long)(*DBObjPtr)(hData) == PD_FOUND) {
DEBUGLOG(("FindRecordExists: Record found, return ERROR!\n"));
			iRet = INT_MMS_OPB_EXISTS;
		}
	}


DEBUGLOG(("Add() normal exit iRet = [%d]\n",iRet));
	return iRet;
}



