#ifndef _DFQMSG_H
#define _DFQMSG_H

#include "myhash.h"

#define MY_DFQ_TOKEN		"&"
#define MY_DFQ_FIELD_TOKEN	"="
#define MY_DFQ_AUTH_TOKEN	"|"

#define MY_DFQ_SUCCESS_STATUS	"00"
#define MY_DFQ_MODEL		"QR_CODE"

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
