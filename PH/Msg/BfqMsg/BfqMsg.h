#ifndef _BFQMSG_H
#define	_BFQMSG_H

#include "myhash.h"

#define	MY_BFQ_TOKEN		"&"
#define	MY_BFQ_FIELD_TOKEN	"="

#define MY_BFQ_VERSION		"1"
#define MY_BFQ_SUCCESS_STATUS	"SUCCESS"
#define PD_REMARK		"ITEM"

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
