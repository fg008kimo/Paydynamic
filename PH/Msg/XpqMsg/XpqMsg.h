#ifndef _XPQMSG_H
#define _XPQMSG_H

#include "myhash.h"

#define MY_XPQ_TOKEN		"&"
#define MY_XPQ_FIELD_TOKEN	"="
#define MY_XPQ_AUTH_TOKEN	"|"

#define MY_XPQ_SUCCESS_STATUS	"00"
#define PD_P0_CMD		"Buy"
#define PD_P5_PID		"PAY"
#define PD_P0_CMD_INQ		"QueryOrdDetail"
#define PD_R4_CUR		"CNY"
#define PD_R9_BTYPE		"2"
#define MY_SETTLE_TYPE		"1"

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
