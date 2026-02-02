#ifndef _PSVMSG_H
#define	_PSVMSG_H

#include "myhash.h"

#define	MY_PSV_TOKEN		"&"
#define	MY_PSV_FIELD_TOKEN	"="
#define MY_PSV_CUR_CODE		"RMB"
#define MY_PSV_SIGN_TYPE	"SHA256withRSA"
#define MY_PSV_VERSION		"4.0"
#define MY_PSV_DEBIT_CARD	"0"
#define MY_PSV_CREDIT_CARD	"1"

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
