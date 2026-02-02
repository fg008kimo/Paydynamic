/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/25              Elvis Wong
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
#include "BOMMSEntityPSP.h"

char    cDebug;

OBJPTR(DB);
OBJPTR(BO);

void BOMMSEntityPSP(char    cdebug)
{
        cDebug = cdebug;
}

int UpdateNatureIdByEntityId (hash_t* hContext, const hash_t* hData)
{
	int	iRet = PD_OK;

DEBUGLOG(("UpdateNatureIdByEntityId() Start!\n"));

DEBUGLOG(("UpdateNatureIdByEntityId:: Call DBMmsEntityPsp UpdateNatureIdByEntityId\n"));
       	DBObjPtr = CreateObj(DBPtr, "DBMmsEntityPsp","UpdateNatureIdByEntityId");
        iRet = (unsigned long)(*DBObjPtr)(hData);
    	if (iRet == PD_OK) {
DEBUGLOG(("UpdateNatureIdByEntityId:: Call DBMmsEntityPsp:: Success!!!\n"));
      	} else {
            	iRet = INT_ERR;
            	PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("UpdateNatureIdByEntityId:: Call DBMmsEntityPsp:: Failure!!!\n"));
ERRLOG("BOMMSEntityPSP::UpdateNatureIdByEntityId::Call DBMmsEntityPsp:: Failure!!!\n");
      	}

DEBUGLOG(("UpdateNatureIdByEntityId() normal exit iRet = [%d]\n",iRet));
	return iRet;
}

