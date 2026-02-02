#ifndef _TPEMSG_H
#define	_TPEMSG_H

#include "myhash.h"

#define	MY_TPE_TOKEN		"&"
#define	MY_TPE_FIELD_TOKEN	"="
#define MY_TPE_VERSION		"2.0"
#define MY_TPE_SUBJECT		"PAY"
#define MY_TPE_BODY		"PAY"
#define MY_TPE_PAYTYPE_VNET	"00"
#define MY_TPE_PAYTYPE_EC	"01"
#define MY_TPE_CHANNEL_PC	"01"
#define MY_TPE_CHANNEL_MOB	"02"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t *table, unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table, const unsigned char *inMsg, int inLen);
int initReplyFromRequest(const hash_t *, hash_t *);
int BuildAuthData(hash_t *hIn);
int BuildRspAuthData(hash_t *hIn);

#ifdef __cplusplus
}
#endif

#endif
