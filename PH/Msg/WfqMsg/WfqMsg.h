#ifndef _WFQMSG_H
#define	_WFQMSG_H

#include "myhash.h"

#define PD_SUCCESS_STATUS		"0000"

#define	MY_WFQ_TOKEN			"&"
#define	MY_WFQ_FIELD_TOKEN		"="
#define MY_WFQ_DATA_TOKEN		"|"

#define PD_SERVICE_CODE			"2001"
#define PD_SUBJECT			"PAY"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t *table, unsigned char *outMsg, int *outLen);
int BuildAuthData(hash_t *hIn);
int BreakDownMsg(hash_t *table, const unsigned char *inMsg,int inLen);
int DEBlockWfqData(hash_t *hOut, const unsigned char *inMsg, int inLen);
int initReplyFromRequest(const hash_t *, hash_t *);
int FormatInitMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen);
int BreakDownInitRspMsg(hash_t *hOut, const unsigned char *inMsg, int inLen);
int BuildRspAuthData(hash_t *hIn);

#ifdef __cplusplus
}
#endif
#endif
