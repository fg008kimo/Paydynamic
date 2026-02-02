#ifndef _EEPMSG_H
#define	_EEPMSG_H

#include "myhash.h"


#define	MY_EEP_TOKEN		"&"
#define	MY_EEP_FIELD_TOKEN	"="

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int BuildAuthData(hash_t* hIn);
#ifdef __cplusplus
}
#endif
#endif
