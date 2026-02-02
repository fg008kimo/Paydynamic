#ifndef _PGNMSG_H
#define	_PGNMSG_H

#include "myhash.h"

//#define	MY_TOKEN		"\r\n\0"
#define MY_PGEN_TOKEN      "&"
#define MY_PGEN_FIELD_TOKEN      "="
#define MY_PGEN_BOUNCE_FIELD_TOKEN  "|"

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
