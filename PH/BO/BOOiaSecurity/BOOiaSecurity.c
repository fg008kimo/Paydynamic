/*
 * PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
 * of an authorized representative of PDProTech.
 *
 * Change Description                                 Change Date             Change By
 * -------------------------------                    ------------            --------------
 *  Init Version                                      2018/11/19              LokMan Chow
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
#include "BOOiaSecurity.h"
#include "dbutility.h"

 
static char    cDebug;

OBJPTR(BO);
void BOOiaSecurity(char    cdebug)
{
        cDebug = cdebug;
}

int VerifyMac(hash_t *hContext,
                const hash_t* hRequest)
{

	int     iRet = PD_OK;
	char	*csEncTypePtr;

DEBUGLOG(("VerifyMac()\n"));
//enc_type
        if (GetField_CString(hRequest,"enc_type",&csEncTypePtr)) {
DEBUGLOG(("BOSecurity:VerifyMac enc_type = [%s]\n",csEncTypePtr));
        }
        else {
DEBUGLOG(("BOSecurity:VerifyMac enc_type is missing!!!\n"));
ERRLOG("BOSecurity:VerifyMac enc_type is missing!!!\n");
                iRet = INT_ERR;
        }

	if (iRet == PD_OK) {
//PD_ENC_TYPE_AES_CMAC
		if (!strcmp(csEncTypePtr, PD_ENC_TYPE_AES_CMAC))
			BOObjPtr = CreateObj(BOPtr,"BOSecurity","VerifyAESMac");
		else {
ERRLOG("BOOiaSecurity:VerifyMac unsupported encryption type [%s]\n",csEncTypePtr);
			iRet = INT_UNSUPPORTED_ENC_TYPE;
		}

		if (iRet ==  PD_OK) {
			iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
		}

DEBUGLOG(("VerifyMac() return from BOSecurity = [%d]\n",iRet));
	}

	return iRet;
}

int GenerateMac(hash_t *hContext,
                hash_t* hOut)
{

	int	iRet = PD_OK;
	char	*csEncTypePtr;

DEBUGLOG(("GenerateMac()\n"));
//enc_type
        if (GetField_CString(hOut,"enc_type",&csEncTypePtr)) {
DEBUGLOG(("GenerateMac enc_type = [%s]\n",csEncTypePtr));
        }
        else {
DEBUGLOG(("GenerateMac enc_type is missing!!!\n"));
ERRLOG("BOSecurity:GenerateMac enc_type is missing!!!\n");
                iRet = INT_ERR;
        }

	if (iRet == PD_OK) {
//PD_ENC_TYPE_AES_CMAC
		if (!strcmp(csEncTypePtr, PD_ENC_TYPE_AES_CMAC))
			BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateAESMac");
		else {
ERRLOG("BOOiaSecurity:GenerateMac unsupported encryption type [%s]\n",csEncTypePtr);
			iRet = INT_UNSUPPORTED_ENC_TYPE;
		}
		if (iRet == PD_OK) 
			iRet = (unsigned long)(*BOObjPtr)(hContext,hOut);
DEBUGLOG(("GenerateMac() return from BOSecurity = [%d]\n",iRet));
	}

	return iRet;
}
