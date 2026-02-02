/*
PDProTech (c)2020. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2021/01/18              [WMC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "dbutility.h"
#include "BOIpRegion.h"
#include "myrecordset.h"
#include "myhash.h"
#include "math.h"
#include "IP2Location.h"

static char cDebug;

OBJPTR(DB);
OBJPTR(BO);

void BOIpRegion(char cdebug)
{
	cDebug = cdebug;
}

int ConvertIp(const char* csIpAddr, hash_t* hRec)
{
        int iRet = PD_OK;
	
//DEBUGLOG(("ConvertIp: Start\n"));
	
	char csFileLocation[PD_TMP_BUF_LEN];
       	char csLocation[PD_COUNTRY_LEN + 1];
      	char csIP[PD_IP_LEN + 1];

	sprintf((char *)csIP, csIpAddr);
      	sprintf((char *)csFileLocation, "%s/ip2location/IP-COUNTRY.BIN", getenv("DATA_PATH"));

      	IP2Location *IP2LocationObj = IP2Location_open(csFileLocation);
      	IP2LocationRecord *record = IP2Location_get_country_short(IP2LocationObj, csIP);

       	strcpy(csLocation, record->country_short);
       	PutField_CString(hRec,"ip_region_code",csLocation);
DEBUGLOG(("ConvertIp: IP[%s] is converted to Region Code[%s]\n",csIP, csLocation));

     	IP2Location_free_record(record);
     	IP2Location_close(IP2LocationObj);

//DEBUGLOG(("ConvertIp: iRet = [%d]\n", iRet));
        return iRet;
}

int IsSupportPspIp(const char* csPspId, const char* csIpAddr)
{
	int iRet = PD_OK;

	char *csRegionCode;

	hash_t *hIp;
        hIp = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hIp,0);

//DEBUGLOG(("IsSupportIp: Start\n"));

	iRet = ConvertIp(csIpAddr, hIp);	
	if (iRet == PD_OK) {
		if (GetField_CString(hIp,"ip_region_code",&csRegionCode)) {
	
        		DBObjPtr = CreateObj(DBPtr,"DBPspRestrictIpRegion","IsSupportIpRegion");
        	     	if ((unsigned long)(DBObjPtr)(csPspId,csRegionCode)==PD_OK){
DEBUGLOG(("IsSupportPspIp: IP Region[%s][%s] of PID[%s] is supported or skip checking\n",csIpAddr,csRegionCode,csPspId));
        	     	} else {
				iRet = PD_ERR;
DEBUGLOG(("IsSupportPspIp: IP Region[%s][%s] of PID[%s] is not supported\n",csIpAddr,csRegionCode,csPspId));
        	      	}
		} else {
DEBUGLOG(("IsSupportPspIp: ip_region_code is missing!!\n"));
		}
	}

	hash_destroy(hIp);
        FREE_ME(hIp);

//DEBUGLOG(("IsSupportIp: iRet = [%d]\n", iRet));
        return iRet;
}

