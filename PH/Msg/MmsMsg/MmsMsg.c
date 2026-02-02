/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/03              Cody Chan
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "MmsMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include "internal.h"
#include <zlib.h>
#include "ObjPtr.h"

#define	THIS_VER	"0"

char	cDebug;


OBJPTR(Msg);
void	MmsMsg(char cdebug)
{
	cDebug = cdebug;
}


int FormatMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int iRet = PD_OK;
DEBUGLOG(("FormatMsg()\n"));
	MsgObjPtr = CreateObj(MsgPtr,"MmcMsg","FormatMsg");
        iRet = (unsigned long) (*MsgObjPtr)(hIn,outMsg,outLen);

DEBUGLOG(("FormatMsg() normal exit iRet = [%d]\n",iRet));
	return iRet;
}

int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;

DEBUGLOG(("BreakDownMsg()\n"));

	MsgObjPtr = CreateObj(MsgPtr,"MmcMsg","BreakDownMsg");
        iRet = (unsigned long) (*MsgObjPtr)(hOut,inMsg,inLen);

DEBUGLOG(("BreakDownMsg() ret = [%d]\n",iRet));
	return iRet;
}


int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
        int     iRet = PD_OK;

DEBUGLOG(("initReplyFromRequest()\n"));

	MsgObjPtr = CreateObj(MsgPtr,"MmcMsg","initReplyFromRequest");
        iRet = (unsigned long) (*MsgObjPtr)(hRequest,hResponse);

DEBUGLOG(("initReplyFromRequest() ret = [%d]\n",iRet));
	return iRet;
}

int BuildAuthData(hash_t* hIn)
{
	int	iRet = PD_OK;

DEBUGLOG(("BuildAuthData()\n"));

	MsgObjPtr = CreateObj(MsgPtr,"MmcMsg","BuildAuthData");
        iRet = (unsigned long) (*MsgObjPtr)(hIn);

DEBUGLOG(("BuildAuthData() ret = [%d]\n",iRet));
	return iRet;
}

int BuildNetworkAuthData(hash_t* hIn)
{
	int	iRet = PD_OK;
DEBUGLOG(("BuildNetworkAuthData()\n"));

	MsgObjPtr = CreateObj(MsgPtr,"MmcMsg","BuildNetworkAuthData");
        iRet = (unsigned long) (*MsgObjPtr)(hIn);

DEBUGLOG(("BuildNetworkAuthData() ret = [%d]\n",iRet));
	return iRet;
}
