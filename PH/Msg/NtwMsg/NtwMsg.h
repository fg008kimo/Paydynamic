#ifndef _NTWMSG_H
#define	_NTWMSG_H

#include "myhash.h"

#define PD_SUCCESS_STATUS	"SUCCESS"
#define PD_FAIL_STATUS		"FAIL"

#define	MY_NTW_TOKEN		"&"
#define	MY_NTW_FIELD_TOKEN	"="
#define MY_NTW_TOKEN_SIGN	"|"
#define MY_NTW_BOUNCE_FIELD_TOKEN  "|"

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
