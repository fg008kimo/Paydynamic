#ifndef _COQMSG_H
#define	_COQMSG_H

#include "myhash.h"


#define	MY_COQ_TOKEN		"&"
#define	MY_COQ_FIELD_TOKEN	"="
#define MY_COQ_SUCCESS_STATUS	"1"
#define MY_COQ_OPEN_BRACKET     "["
#define MY_COQ_CLOSE_BRACKET    "]"
#define MY_COQ_RET_CODE_LEN	4
#define MY_COQ_SIGN_TYPE_LEN	1
#define PD_SIGN_TYPE            "1"
#define PD_CCY_TYPE             "156"
#define PD_REMARK               "PAY"

#define	MY_ZERO			'0'

#define PD_OPEN_BRACKET_H	0x7b
#define PD_CLOSE_BRACKET_H	0x7d
#define MY_COP_JSON_TOKEN	","
#define MY_COP_JSON_FIELD_TOKEN	":"
#define PD_DOUBLE_QUOTE		0x22



#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BuildAuthData(hash_t* hIn);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int FormatInitMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int BreakDownInitRspMsg(hash_t *hOut,const unsigned char *inMsg,int inLen);
int BuildRspAuthData(hash_t* hIn);
int FormatInqMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen);
int BuildInqAuthData(hash_t *hIn);
int BreakDownInqRspMsg(hash_t *hContext, hash_t *hOut, const unsigned char *inMsg, int inLen);
int BuildInqRspAuthData(hash_t *hIn);
int BuildCallbackAuthData(hash_t *hIn);
int FormatCallbackMsg(hash_t *hContext, hash_t *hIn, unsigned char *outMsg, int *outLen);

#ifdef __cplusplus
}
#endif
#endif
