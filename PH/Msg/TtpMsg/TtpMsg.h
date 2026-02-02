#ifndef _TTPMSG_H
#define	_TTPMSG_H

#include "myhash.h"


#define	MY_TTP_TOKEN		"&"
#define	MY_TTP_FIELD_TOKEN	"="
#define MY_TTP_TYPE_EC		"MOBILE"
#define MY_TTP_VERSION		"1.0"
#define MY_TTP_CCY		"CNY"
#define MY_TTP_DR_CARD		"1"
#define MY_TTP_CR_CARD		"2"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int BuildAuthData(hash_t* hIn);
int BuildRspAuthData(hash_t* hIn);
int FormatInqMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen);
int BuildInqAuthData(hash_t *hIn);
int BreakDownInqRspMsg(hash_t *hContext, hash_t *hOut, const unsigned char *inMsg, int inLen);
int BuildInqRspAuthData(hash_t *hIn);
int BuildCallbackAuthData(hash_t *hIn);
int FormatCallbackMsg(hash_t *hContext, hash_t *hIn, unsigned char *outMsg, int *outLen);

#ifdef __cplusplus
}
#endif
#endif
