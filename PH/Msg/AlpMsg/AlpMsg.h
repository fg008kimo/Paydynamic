#ifndef _ALPMSG_H
#define	_ALPMSG_H

#include "myhash.h"


#define	MY_ALP_TOKEN		"&"
#define	MY_ALP_FIELD_TOKEN	"="
#define	MY_ALP_BANKCARD		"1"
#define	MY_ALP_BANKCARD_CR	"11"
#define	MY_ALP_MOBILE		"10"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int BuildAuthData(hash_t* hIn);
int BuildInqAuthData(hash_t* hIn);
int BuildRspAuthData(hash_t* hIn);
#ifdef __cplusplus
}
#endif
#endif
