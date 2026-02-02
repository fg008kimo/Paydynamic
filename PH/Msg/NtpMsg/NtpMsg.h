#ifndef _NTPMSG_H
#define	_NTPMSG_H

#include "myhash.h"


#define	MY_NTP_TOKEN		"&"
#define	MY_NTP_FIELD_TOKEN	"="
#define	MY_NTP_BANKCARD		"1"
#define	MY_NTP_MOBILE		"10"
#define PD_ORDER_DETAILS	"PAY"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int BuildAuthData(hash_t* hIn);
int BuildRspAuthData(hash_t* hIn);
#ifdef __cplusplus
}
#endif
#endif
