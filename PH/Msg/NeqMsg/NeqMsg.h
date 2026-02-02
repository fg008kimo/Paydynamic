#ifndef _NEQMSG_H
#define	_NEQMSG_H

#include "myhash.h"

#define PD_SUCCESS_STATUS		"SUCCESS"
#define PD_FAIL_STATUS			"FAIL"

#define	MY_NEQ_TOKEN			"&"
#define	MY_NEQ_FIELD_TOKEN		"="
#define MY_NEQ_TOKEN_SIGN		"|"
#define MY_NEQ_BOUNCE_FIELD_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t *table, unsigned char *outMsg, int *outLen);
int BuildAuthData(hash_t *hIn);
int BreakDownMsg(hash_t *table, const unsigned char *inMsg, int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int FormatInqMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen);
int BreakDownInitRspMsg(hash_t *hOut, const unsigned char *inMsg, int inLen);
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
