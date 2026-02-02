#ifndef _RPYMSG_H
#define	_RPYMSG_H

#include "myhash.h"


#define	MY_RPY_TOKEN		"&"
#define	MY_RPY_FIELD_TOKEN	"="
#define MY_RPY_BOUNCE_FIELD_TOKEN  "|"

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
