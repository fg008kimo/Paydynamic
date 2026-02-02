#ifndef _HXVMSG_H
#define	_HXVMSG_H

#include "myhash.h"

#define	MY_HXV_TOKEN		"&"
#define	MY_HXV_FIELD_TOKEN	"="
#define MY_HXV_CUR_CODE		"CNY"
#define MY_HXV_ORDER_SRC	"1"
#define MY_HXV_PAY_CH_TYPE	"1"
#define MY_HXV_SERVICE		"bankPay"
#define MY_HXV_SIGN_TYPE	"2"
#define MY_HXV_VERSION		"V2.0"

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
