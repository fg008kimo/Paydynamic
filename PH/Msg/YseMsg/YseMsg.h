#ifndef _YSEMSG_H
#define	_YSEMSG_H

#include "myhash.h"


#define	MY_YSE_TOKEN		"&"
#define	MY_YSE_FIELD_TOKEN	"="
#define MY_YSE_DATA_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int BuildRspAuthData(hash_t* hOut);
int initReplyFromRequest(const hash_t*, hash_t*);
#ifdef __cplusplus
}
#endif
#endif
