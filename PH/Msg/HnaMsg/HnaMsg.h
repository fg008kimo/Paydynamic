#ifndef _HNAMSG_H
#define	_HNAMSG_H

#include "myhash.h"


#define	MY_HNA_TOKEN		"&"
#define	MY_HNA_FIELD_TOKEN	"="
#define	MY_HNA_AUTH_TOKEN	"&"
#define	MY_HNA_SEPERATER	","
#define	MY_HNA_BANKCARD		"1"
#define	MY_HNA_MOBILE		"10"

#define MY_HNA_VERSION		"2.6"
#define MY_HNA_MODE		"1"
#define MY_HNA_TYPE		"1"
#define MY_HNA_ENQ_RANGE_SEC	"1295999"
#define MY_HNA_CHARSET		"1"
#define MY_HNA_SIGNTYPE		"2"
#define MY_HNA_QUERY_DET_COLUMN	7

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table, unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table, const unsigned char *inMsg, int inLen);
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
