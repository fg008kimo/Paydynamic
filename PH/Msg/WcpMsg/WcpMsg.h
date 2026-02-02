#ifndef _WCPMSG_H
#define	_WCPMSG_H

#include "myhash.h"


#define	MY_WCP_TOKEN		"&"
#define	MY_WCP_FIELD_TOKEN	"="
#define MY_WCP_TOKEN_SIGN	"|"
#define MY_WCP_BOUNCE_FIELD_TOKEN  "|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);

int BuildAuthData(hash_t* hIn);
int BuildRspAuthData(hash_t* hIn);


int BuildInqAuthData(hash_t* hIn);
int FormatInqMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);


int BreakDownInitRspMsg(hash_t *hOut,const unsigned char *inMsg,int inLen);

#ifdef __cplusplus
}
#endif
#endif
