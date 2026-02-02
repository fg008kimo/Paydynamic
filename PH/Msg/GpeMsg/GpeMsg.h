#ifndef _GPEMSG_H
#define	_GPEMSG_H

#include "myhash.h"

#define	MY_GPE_TOKEN		"&"
#define MY_GPE_SIGN_TOKEN	"#"
#define	MY_GPE_FIELD_TOKEN	"="
#define MY_GPE_CCY		"CNY"
#define MY_GPE_PRODUCT_NAME	"PAY"
#define MY_GPE_PRODUCT_QUANTITY	"1"

#define MY_GPE_VERSION		"1.0"
#define MY_GPE_METHOD		"sandPay.fastPay.quickPay.index"
#define MY_GPE_PRODUCT_ID	"00000016"
#define MY_GPE_ACCESS_TYPE	"1"
#define MY_GPE_CHANNEL_TYPE	"07"
#define MY_GPE_SUBJECT		"PAY"
#define MY_GPE_BODY		"PAY"
#define MY_GPE_CCY_CODE		"156"
#define MY_GPE_CLEAR_CYCLE	"0"

#define MY_GPE_OPEN_BRACKET	"["
#define MY_GPE_CLOSE_BRACKET	"]"

#define MY_GPE_CHARSET		"utf-8"
#define MY_GPE_SIGNTYPE		"01"
#define MY_GPE_USER_ID		"24581191"

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
