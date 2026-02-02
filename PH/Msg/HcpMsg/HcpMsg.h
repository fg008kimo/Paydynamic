#ifndef _HCPMSG_H
#define	_HCPMSG_H

#include "myhash.h"


#define	MY_HCP_TOKEN		"&"
#define	MY_HCP_FIELD_TOKEN	"="
#define MY_HCP_DATA_TOKEN      "|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int BuildData(hash_t* hIn);
int DEBlockHcpData(hash_t *hOut,const unsigned char *inMsg,int inLen);
#ifdef __cplusplus
}
#endif
#endif
