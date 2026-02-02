#ifndef _XJPMSG_H
#define	_XJPMSG_H

#include "myhash.h"


#define	MY_XJP_TOKEN			"&"
#define	MY_XJP_FIELD_TOKEN		"="
#define MY_XJP_DATA_TOKEN		"|"
#define MY_XJP_JSON_TOKEN		","
#define MY_XJP_JSON_FIELD_TOKEN		":"
#define MY_XJP_JSON_START_TOKEN		"{"
#define MY_XJP_JSON_END_TOKEN		"}"
#define MY_XJP_JSON_START_TOKEN_2	"["
#define MY_XJP_JSON_END_TOKEN_2		"]"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BuildData(hash_t* hIn);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int DEBlockXjpData(hash_t *hOut,const unsigned char *inMsg,int inLen);
int DEBlockXjpInitData(hash_t *hOut,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
void remove_quote(const char* csValue, const int iType, char* csOut);
int FormatInitMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int BreakDownInitRspMsg(hash_t *hOut,const unsigned char *inMsg,int inLen);
int BuildRspAuthData(hash_t* hIn);

#ifdef __cplusplus
}
#endif
#endif
