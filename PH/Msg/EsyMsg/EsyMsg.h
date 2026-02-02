#ifndef _ESYMSG_H
#define	_ESYMSG_H

#include "myhash.h"


#define	MY_ESY_TOKEN		"&"
#define	MY_ESY_FIELD_TOKEN	"="
#define MY_ESY_DATA_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int BuildAuthData(hash_t* hIn);
int BuildRspAuthData(hash_t* hIn);

int FormatInqMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int BuildInqAuthData(hash_t* hIn);
#ifdef __cplusplus
}
#endif
#endif
