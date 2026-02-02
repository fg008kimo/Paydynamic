#ifndef _SPYMSG_H
#define	_SPYMSG_H

#include "myhash.h"


#define	MY_SPY_TOKEN		"&"
#define	MY_SPY_FIELD_TOKEN	"="
#define	MY_SPY_VERSION		"V4.1.1.1.1"

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
