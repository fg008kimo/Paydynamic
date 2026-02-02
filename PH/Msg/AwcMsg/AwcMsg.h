#ifndef _AWCMSG_H
#define	_AWCMSG_H

#include "myhash.h"


#define	MY_AWC_TOKEN		"&"
#define	MY_AWC_FIELD_TOKEN	"="
#define MY_AWC_TOKEN_SIGN	"|"
#define MY_AWC_BOUNCE_FIELD_TOKEN  "|"
#define MY_AWC_BODY		"#81660031"

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

#ifdef __cplusplus
}
#endif
#endif
