#ifndef _RFQMSG_H
#define	_RFQMSG_H

#include "myhash.h"


#define	MY_RFQ_TOKEN			"&"
#define	MY_RFQ_FIELD_TOKEN		"="
#define MY_RFQ_DATA_TOKEN		"|"
#define MY_RFQ_SUCCESS_STATUS		"1"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BuildAuthData(hash_t* hIn);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int DEBlockRfqData(hash_t *hOut,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int FormatInitMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int BreakDownInitRspMsg(hash_t *hOut,const unsigned char *inMsg,int inLen);
int BuildRspAuthData(hash_t* hIn);

#ifdef __cplusplus
}
#endif
#endif
