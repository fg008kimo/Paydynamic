#ifndef _OOEMSG_H
#define	_OOEMSG_H

#include "myhash.h"

#define	MY_OOE_TOKEN		"&"
#define	MY_OOE_FIELD_TOKEN	"="

#define MY_OOE_INPUT_CHARSET	"1"
#define MY_OOE_VERSION		"1.0"
#define MY_OOE_LANGUAGE		"1"
#define MY_OOE_SIGN_TYPE	"0"
#define MY_OOE_ORDER_CCY	"156"
#define MY_OOE_PRODUCT_NAME	"PAY"
#define MY_OOE_PRODUCT_NUM	"1"
#define MY_OOE_PAYTYPE_EC       "12"

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
