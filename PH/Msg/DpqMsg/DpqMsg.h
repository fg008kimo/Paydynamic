#ifndef _DPQMSG_H
#define	_DPQMSG_H

#include "myhash.h"

#define PD_SUCCESS_STATUS       "SUCCESS"
#define PD_FAIL_STATUS          "FAIL"

#define MY_DPQ_TOKEN            "&"
#define MY_DPQ_FIELD_TOKEN      "="
#define MY_DPQ_AUTH_TOKEN       "&"
#define MY_DPQ_BANKCARD         "1"
#define MY_DPQ_MOBILE           "10"

#define PD_INTERFACE_VERSION    "V3.1"
#define PD_SIGN_TYPE            "RSA-S"
#define PD_PRODUCT_NAME         "PAY"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BuildAuthData(hash_t* hIn);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int DEBlockDpqData(hash_t *hOut,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int FormatInitMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int BreakDownInitRspMsg(hash_t *hOut,const unsigned char *inMsg,int inLen);
int BuildRspAuthData(hash_t* hIn);

#ifdef __cplusplus
}
#endif
#endif
