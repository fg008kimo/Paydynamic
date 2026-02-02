#ifndef _YPMMSG_H
#define	_YPMMSG_H

#include "myhash.h"


#define	MY_YPM_TOKEN			"&"
#define	MY_YPM_FIELD_TOKEN		"="
#define MY_YPM_DATA_TOKEN		"|"
#define MY_YPM_JSON_TOKEN		","
#define MY_YPM_JSON_FIELD_TOKEN		":"
#define MY_YPM_JSON_START_TOKEN		"{"
#define MY_YPM_JSON_END_TOKEN		"}"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int BuildData(hash_t* hIn);
int DEBlockyeepayData(hash_t *hOut,const unsigned char *inMsg,int inLen, const char* csKey);
#ifdef __cplusplus
}
#endif
#endif
