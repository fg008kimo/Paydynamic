#ifndef _SKQMSG_H
#define _SKQMSG_H

#include "myhash.h"

#define MY_SKQ_TOKEN		"&"
#define MY_SKQ_FIELD_TOKEN	"="
#define MY_SKQ_AUTH_TOKEN	"|"

#define MY_SKQ_SUCCESS_STATUS	"0000"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t *table, unsigned char *outMsg, int *outLen);
int BuildAuthData(hash_t *hIn);
int BreakDownMsg(hash_t *table, const unsigned char *inMsg, int inLen);
int DEBlockUnwData(hash_t *hOut, const unsigned char *inMsg, int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int FormatInitMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen);
int BreakDownInitRspMsg(hash_t *hOut, const unsigned char *inMsg, int inLen);
int BuildRspAuthData(hash_t *hIn);

#ifdef __cplusplus
}
#endif
#endif
