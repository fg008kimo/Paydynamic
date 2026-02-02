#ifndef _SKEMSG_H
#define	_SKEMSG_H

#include "myhash.h"

#define	MY_SKE_TOKEN		"&"
#define	MY_SKE_FIELD_TOKEN	"="
#define MY_SKE_PAY_BANK_ACCT_NUM "123456789"
#define MY_SKE_PRODUCT_NAME	"PAY"
#define MY_SKE_PRODUCT_TYPE	"40000503"

#define PD_SIGN_TYPE		"1"
#define PD_CCY_TYPE		"156"
#define PD_MOB_EC		"99"
#define PD_REMARK		"PAY"

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
