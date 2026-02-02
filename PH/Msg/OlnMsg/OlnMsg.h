#ifndef _OLNMSG_H
#define	_OLNMSG_H

#include "myhash.h"


#define	MY_OLN_TOKEN		"&"
#define	MY_OLN_FIELD_TOKEN	"="
#define	MY_OLN_BOUNCE_FIELD_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

void OlnMsg(char);
int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse);
int BuildAuthData(hash_t* hIn);
int BuildRespAuthData(hash_t* hIn);
int FormatAckMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int BuildAckAuthData(hash_t* hIn);

#ifdef __cplusplus
}
#endif
#endif
