#ifndef _MMCMSG_H
#define	_MMCMSG_H

#include "myhash.h"

#define MY_MMC_TOKEN      "&"
#define MY_MMC_FIELD_TOKEN      "="
#define MY_MMC_BOUNCE_FIELD_TOKEN  "|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int FormatNetworkMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse);
int BuildAuthData(hash_t* hIn);
int BuildNetworkAuthData(hash_t* hIn);

#ifdef __cplusplus
}
#endif
#endif
