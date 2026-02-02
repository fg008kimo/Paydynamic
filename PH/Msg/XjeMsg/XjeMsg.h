#ifndef _XJEMSG_H
#define	_XJEMSG_H

#include "myhash.h"

#define	MY_XJE_TOKEN		"&"
#define MY_XJE_SIGN_TOKEN	"#"
#define	MY_XJE_FIELD_TOKEN	"="
#define MY_XJE_CCY		"CNY"
#define MY_XJE_PRODUCT_NAME	"PAY"
#define MY_XJE_PRODUCT_QUANTITY	"1"
#define MY_XJE_VERSION		"2.0"

#define MY_XJE_OPEN_BRACKET	"["
#define MY_XJE_CLOSE_BRACKET	"]"

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
