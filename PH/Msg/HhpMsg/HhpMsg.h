#ifndef _HHPAYMSG_H
#define	_HHPAYMSG_H

#include "myhash.h"


#define	MY_HHPAY_TOKEN		"&"
#define	MY_HHPAY_FIELD_TOKEN	"="
#define MY_HHPAY_DATA_TOKEN      "|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int BuildData(hash_t* hIn);
int DEBlockHHpayData(hash_t *hOut,const unsigned char *inMsg,int inLen);
#ifdef __cplusplus
}
#endif
#endif
