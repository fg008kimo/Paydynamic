#ifndef _SKVMSG_H
#define	_SKVMSG_H

#include "myhash.h"

#define	MY_SKV_TOKEN		"&"
#define	MY_SKV_FIELD_TOKEN	"="
#define MY_SKV_PAY_BANK_ACCT_NUM "123456789"
#define MY_SKV_PRODUCT_NAME	"PAY"
#define MY_SKV_PRODUCT_TYPE	"50000103"
#define MY_SKV_DEBIT_ACCT	"PRIVATE_DEBIT_ACCOUNT"
#define MY_SKV_CREDIT_ACCT	"PRIVATE_CREDIT_ACCOUNT"

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
