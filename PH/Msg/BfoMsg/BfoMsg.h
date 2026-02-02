#ifndef _BFOMSG_H
#define	_BFOMSG_H

#include "myhash.h"


#define	MY_BFO_TOKEN		"&"
#define	MY_BFO_FIELD_TOKEN	"="
#define	MY_BFO_AUTH_TOKEN	"|"
#define	MY_BFO_RESP_AUTH_TOKEN	"~|~"
#define	MY_BFO_BANKCARD		"1"
#define	MY_BFO_MOBILE		"10"

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
