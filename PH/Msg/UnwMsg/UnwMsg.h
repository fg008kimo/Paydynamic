#ifndef _UNWMSG_H
#define	_UNWMSG_H

#include "myhash.h"


#define MY_UNW_TOKEN            "&"
#define MY_UNW_FIELD_TOKEN      "="
#define MY_UNW_AUTH_TOKEN       "&"
#define MY_UNW_BANKCARD         "1"
#define MY_UNW_MOBILE           "10"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BuildAuthData(hash_t* hIn);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int DEBlockUnwData(hash_t *hOut,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int FormatInitMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int BreakDownInitRspMsg(hash_t *hOut,const unsigned char *inMsg,int inLen);
int BuildRspAuthData(hash_t* hIn);

#ifdef __cplusplus
}
#endif
#endif
