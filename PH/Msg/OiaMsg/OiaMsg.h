#ifndef _OIAMSG_H
#define	_OIAMSG_H

#include "myhash.h"

#define MY_API_INFO_OBJ		"info"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t* hIn, hash_t* hOut);
int BuildAuthData(hash_t* hIn);
int BuildRespAuthData(hash_t* hIn);

#ifdef __cplusplus
}
#endif
#endif
