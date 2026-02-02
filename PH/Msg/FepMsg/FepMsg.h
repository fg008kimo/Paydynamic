#ifndef _FEPMSG_H
#define	_FEPMSG_H

#include "myhash.h"


#define	MY_FEP_TOKEN		"&"
#define	MY_FEP_FIELD_TOKEN	"="
#define MY_FEP_BOUNCE_FIELD_TOKEN  "|"

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
