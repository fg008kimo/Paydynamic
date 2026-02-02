#ifndef _OPPMSG_H
#define	_OPPMSG_H

#include "myhash.h"

#define	MY_OPP_TOKEN		"&"
#define	MY_OPP_FIELD_TOKEN	"="
#define	MY_OPP_BANKCARD		"1"
#define	MY_OPP_BANKCARD_CR	"11"
#define	MY_OPP_MOBILE		"39"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int BuildAuthData(hash_t* hIn);
int BuildRspAuthData(hash_t* hIn);

#ifdef __cplusplus
}
#endif
#endif
