#ifndef _XYEMSG_H
#define	_XYEMSG_H

#include "myhash.h"


#define	MY_XYE_TOKEN		"&"
#define	MY_XYE_FIELD_TOKEN	"="
#define MY_XYE_SUCCESS_STATUS	"0"
#define MY_XYE_VERSION          "02"
#define MY_XYE_COUNTRY		"CN"
#define MY_XYE_CCY_CODE		"CNY"

#define MY_XYE_PAYCODE_WEB	"1"
#define MY_XYE_PAYCODE_EC	"2"


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
