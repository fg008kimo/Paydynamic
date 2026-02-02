#ifndef _GPVMSG_H
#define	_GPVMSG_H

#include "myhash.h"

#define	MY_GPV_TOKEN		"&"
#define MY_GPV_SIGN_TOKEN	"#"
#define	MY_GPV_FIELD_TOKEN	"="
#define MY_GPV_CCY		"CNY"
#define MY_GPV_PRODUCT_NAME	"PAY"
#define MY_GPV_PRODUCT_QUANTITY	"1"

#define MY_GPV_VERSION		"1.0"
#define MY_GPV_METHOD		"sandpay.trade.pay"
#define MY_GPV_PRODUCT_ID	"00000007"
#define MY_GPV_ACCESS_TYPE	"1"
#define MY_GPV_CHANNEL_TYPE	"07"
#define MY_GPV_SUBJECT		"PAY"
#define MY_GPV_BODY		"PAY"
#define MY_GPV_PAY_MODE		"bank_pc"
#define MY_GPV_PAY_TYPE		"1"

#define MY_GPV_OPEN_BRACKET	"["
#define MY_GPV_CLOSE_BRACKET	"]"

#define MY_GPV_CHARSET		"utf-8"
#define MY_GPV_SIGNTYPE		"01"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t *table, unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table, const unsigned char *inMsg, int inLen);
int initReplyFromRequest(const hash_t *, hash_t *);
int BuildAuthData(hash_t *hIn);
int BuildRspAuthData(hash_t *hIn);
int FormatInitMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen);

#ifdef __cplusplus
}
#endif

#endif
