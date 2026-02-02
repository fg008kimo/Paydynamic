#ifndef _XPVMSG_H
#define	_XPVMSG_H

#include "myhash.h"

#define	MY_XPV_TOKEN		"&"
#define	MY_XPV_FIELD_TOKEN	"="
#define MY_XPV_SIGN_TOKEN	"|"

#define MY_XPV_ENC_TYPE		"01"
#define MY_XPV_CURRENCY		"100"

#define MY_XPV_VERSION		"2.3.7"
#define MY_XPV_FIRST_NAME	"John"
#define MY_XPV_LAST_NAME	"Sayor"
#define MY_XPV_BILLEMAIL	"john.stuart@gmail.com"
#define MY_XPV_BILLSTREET	"No. 1 Stuart Road"
#define MY_XPV_BILLCITY		"Kuala Lumpur"
#define MY_XPV_BILLCOUNTRY	"MY"
#define MY_XPV_BILLPHONE	"60388887777"

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
