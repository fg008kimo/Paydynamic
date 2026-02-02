#ifndef _SFEMSG_H
#define	_SFEMSG_H

#include "myhash.h"

#define	MY_SFE_TOKEN		"&"
#define	MY_SFE_FIELD_TOKEN	"="
#define MY_SFE_PRODUCT_NAME	"PAY"
#define MY_SFE_TRANS_ID_EC	"15"
#define MY_SFE_TRANS_ID_VNET	"14"

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
