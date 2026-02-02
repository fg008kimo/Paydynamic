#ifndef _UNQMSG_H
#define	_UNQMSG_H

#include "myhash.h"

#define PD_SUCCESS_STATUS		"00"
#define PD_SUCCESS_MSG			"Success"
#define PD_FAIL_STATUS			"FAIL"

#define	MY_UNQ_TOKEN			"&"
#define	MY_UNQ_FIELD_TOKEN		"="

#define PD_UNQ_CARD_TYPE		"01"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *hOut, const unsigned char *inMsg, int inLen);
int initReplyFromRequest(const hash_t *hRequest, hash_t *hResponse);
int BuildAuthData(hash_t *hIn);
int BuildRspAuthData(hash_t *hIn);
int FormatInitMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen);
int BreakDownInitRspMsg(hash_t *hOut, const unsigned char *inMsg, int inLen);
int BreakDownXMLMsg(hash_t *hOut,const unsigned char *inMsg,int inLen);
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
