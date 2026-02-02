#ifndef _DPYMSG_H
#define	_DPYMSG_H

#include "myhash.h"

#define	MY_DPY_TOKEN		"&"
#define	MY_DPY_FIELD_TOKEN	"="
#define PD_INPUT_CHARSET	"UTF-8"
#define PD_SERVICE_TYPE		"direct_pay"
#define PD_INTERFACE_VERSION	"V3.0"
#define PD_SIGN_TYPE		"RSA-S"
#define PD_PAY_TYPE		"b2c"
#define PD_PAY_TYPE_EC		"b2cwap"
#define PD_BANK_CODE_EC		"WAP_UNION"
#define PD_PRODUCT_NAME		"PAY"
#define PD_REDO_FLAG		"1"

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
