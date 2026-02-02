#ifndef _MMSMSG_H
#define	_MMSMSG_H

#include "myhash.h"

#define MY_MMS_TOKEN      "&"
#define MY_MMS_FIELD_TOKEN      "="
#define MY_MMS_BOUNCE_FIELD_TOKEN  "|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse);
int BuildAuthData(hash_t* hIn);
int BuildNetworkAuthData(hash_t* hIn);

#ifdef __cplusplus
}
#endif
#endif
