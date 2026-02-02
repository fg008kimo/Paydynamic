#ifndef _TWVMSG_H
#define	_TWVMSG_H

#include "myhash.h"


#define	MY_TWV_TOKEN		"&"
#define	MY_TWV_FIELD_TOKEN	"="
#define MY_TWV_BOUNCE_FIELD_TOKEN  "|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int FormatBatchMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int BreakDownBatchMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);

#ifdef __cplusplus
}
#endif
#endif
