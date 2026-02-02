#ifndef _TPMMSG_H
#define	_TPMMSG_H

#include "myhash.h"


#define	MY_TPM_TOKEN		"&"
#define	MY_TPM_FIELD_TOKEN	"="
#define MY_TPM_BOUNCE_FIELD_TOKEN  "|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);

int BuildAuthData(hash_t* hIn);
int BuildRspAuthData(hash_t* hIn);


int BuildInqAuthData(hash_t* hIn);
int FormatInqMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);

#ifdef __cplusplus
}
#endif
#endif
