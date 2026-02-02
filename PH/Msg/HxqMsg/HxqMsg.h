#ifndef _HXQMSG_H
#define _HXQMSG_H

#include "myhash.h"

#define MY_HXQ_TOKEN		"&"
#define MY_HXQ_FIELD_TOKEN	"="
#define MY_HXQ_CUR_CODE         "CNY"
#define MY_HXQ_ORDER_SRC        "2"
#define MY_HXQ_SERVICE          "getCodeUrl"
#define MY_HXQ_SIGN_TYPE        "2"
#define MY_HXQ_VERSION          "V2.0"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t *table, unsigned char *outMsg, int *outLen);
int BuildAuthData(hash_t *hIn);
int BreakDownMsg(hash_t *table, const unsigned char *inMsg, int inLen);
int DEBlockUnwData(hash_t *hOut, const unsigned char *inMsg, int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int FormatInitMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen);
int BreakDownInitRspMsg(hash_t *hOut, const unsigned char *inMsg, int inLen);
int BuildRspAuthData(hash_t *hIn);

#ifdef __cplusplus
}
#endif
#endif
