#ifndef _XPYMSG_H
#define	_XPYMSG_H

#include "myhash.h"


#define	MY_XPAY_TOKEN		"&"
#define	MY_XPAY_FIELD_TOKEN	"="
#define	MY_XPAY_DATA_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int FormatAckMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int BuildData(hash_t* hIn);
int BreakDownAckMsg(hash_t *hOut,const unsigned char *inMsg,int inLen);


#ifdef __cplusplus
}
#endif
#endif
