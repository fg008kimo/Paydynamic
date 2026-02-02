#ifndef _ESKYMSG_H
#define	_ESKYMSG_H

#include "myhash.h"


#define	MY_ESKY_TOKEN		"&"
#define	MY_ESKY_FIELD_TOKEN	"="

#define PD_MOB_EC		"9999"

#define PD_OPEN_BRACKET_H	0x7b
#define PD_CLOSE_BRACKET_H	0x7d
#define MY_ESKY_JSON_TOKEN	","
#define MY_ESKY_JSON_FIELD_TOKEN	":"
#define PD_DOUBLE_QUOTE		0x22
#define MY_ESKY_PENDING_STATUS "9"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int BuildAuthData(hash_t* hIn);
int FormatInqMsg(const hash_t* hIn, unsigned char *outMsg, int *outLen);
int BuildInqAuthData(hash_t *hIn);
int BreakDownInqRspMsg(hash_t *hContext, hash_t *hOut, const unsigned char *inMsg, int inLen);
int BuildInqRspAuthData(hash_t *hIn);
int BuildCallbackAuthData(hash_t *hIn);
int FormatCallbackMsg(hash_t *hContext, hash_t *hIn, unsigned char *outMsg, int *outLen);

#ifdef __cplusplus
}
#endif
#endif
