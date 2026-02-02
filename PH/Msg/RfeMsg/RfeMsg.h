#ifndef _RFEMSG_H
#define	_RFEMSG_H

#include "myhash.h"

#define	MY_RFE_TOKEN		"&"
#define	MY_RFE_FIELD_TOKEN	"="
#define MY_RFE_PRODUCT_NAME	"PAY"
#define MY_RFE_PRODUCT_TYPE	"40000503"

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
