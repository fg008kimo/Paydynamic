#ifndef _OLCMSG_H
#define	_OLCMSG_H

#include "myhash.h"


#define	MY_OLC_TOKEN		"&"
#define	MY_OLC_FIELD_TOKEN	"="
#define	MY_OLC_BOUNCE_FIELD_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

void OlcMsg(char);
int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse);
int BuildAuthData(hash_t* hIn);
int BuildRespAuthData(hash_t* hIn);
int FormatAckMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);

#ifdef __cplusplus
}
#endif
#endif
