#ifndef _YPYMSG_H
#define	_YPYMSG_H

#include "myhash.h"


#define	MY_YPY_TOKEN		"&"
#define	MY_YPY_FIELD_TOKEN	"="
#define MY_YPY_DATA_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int BuildReqData(hash_t* hIn);
int BuildRspData(hash_t* hIn);
#ifdef __cplusplus
}
#endif
#endif
