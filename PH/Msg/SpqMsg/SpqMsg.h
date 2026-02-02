#ifndef _SPQMSG_H
#define _SPQMSG_H

#include "myhash.h"

#define MY_SPQ_TOKEN		"&"
#define MY_SPQ_FIELD_TOKEN	"="
#define MY_SPQ_AUTH_TOKEN	"|"
#define MY_SPQ_VERSION		"2.0"

#define MY_SPQ_SUCCESS_STATUS	"PASS"

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
