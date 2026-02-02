#ifndef _MMSMSG_H
#define	_MMSMSG_H

#include "myhash.h"


#define	MY_MMS_TOKEN		"&"
#define	MY_MMS_FIELD_TOKEN	"="
#define	MY_MMS_BOUNCE_FIELD_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int DeBlockBounceBackData(hash_t *hOut,const char* inMsg, const int inLen);
int BuildAuthData(hash_t* hIn);

int BreakDownNodeMsg(hash_t *hOut,const unsigned char *inMsg,int inLen);
#ifdef __cplusplus
}
#endif
#endif
