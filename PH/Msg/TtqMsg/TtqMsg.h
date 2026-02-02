#ifndef _TTQMSG_H
#define	_TTQMSG_H

#include "myhash.h"

#define	MY_TTQ_TOKEN		"&"
#define MY_TTQ_TOKEN_NEW	"|"
#define	MY_TTQ_FIELD_TOKEN	"="
#define MY_TTQ_VERSION		"1.0"
#define MY_TTQ_CCY		"CNY"
#define MY_TTQ_SUCCESS_STATUS	"0000"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t *table, unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table, const unsigned char *inMsg, int inLen);
int initReplyFromRequest(const hash_t *, hash_t *);
int FormatInitMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen);
int BreakDownInitRspMsg(hash_t *hOut, const unsigned char *inMsg, int inLen);
int BuildAuthData(hash_t *hIn);
int BuildRspAuthData(hash_t *hIn);
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
