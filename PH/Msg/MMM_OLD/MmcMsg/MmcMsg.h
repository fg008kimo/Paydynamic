#ifndef _MMCMSG_H
#define	_MMCMSG_H

#include "myhash.h"


#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse);

#ifdef __cplusplus
}
#endif
#endif
