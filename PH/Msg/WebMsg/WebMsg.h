#ifndef _WEBMSG_H
#define	_WEBMSG_H

#include "myhash.h"


#define	MY_WEB_TOKEN		"&"
#define	MY_WEB_FIELD_TOKEN	"="
#define	MY_WEB_BOUNCE_FIELD_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

void WebMsg(char);
int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int BreakDownRespMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int FormatFEMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
//int FormatXPAYFEMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int FormatAckMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int FormatBatchMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int DeBlockWebBounceBackData(hash_t *hOut,const char* inMsg, const int inLen);

int BuildAuthData(hash_t* hIn);
int BuildRespAuthData(hash_t* hIn);
int BuildAckAuthData(hash_t* hIn);

int BuildNetworkRespAuthData(hash_t* hIn);

#ifdef __cplusplus
}
#endif
#endif
