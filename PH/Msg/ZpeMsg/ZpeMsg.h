#ifndef _ZPEMSG_H
#define	_ZPEMSG_H

#include "myhash.h"


#define	MY_ZPE_TOKEN		"&"
#define	MY_ZPE_FIELD_TOKEN	"="
#define MY_ZPE_SUCCESS_STATUS	"0"
#define MY_ZPE_VERSION          "02"
#define MY_ZPE_COUNTRY		"CN"
#define MY_ZPE_CCY_CODE		"CNY"

#define MY_ZPE_PAYCODE_WEB	"1"
#define MY_ZPE_PAYCODE_EC	"2"


#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BuildAuthData(hash_t* hIn);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
//int FormatInitMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
//int BreakDownInitRspMsg(hash_t *hOut,const unsigned char *inMsg,int inLen);
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
