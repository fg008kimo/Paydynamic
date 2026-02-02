#ifndef _EMLMSG_H
#define	_EMLMSG_H

#include "myhash.h"


#define	MY_EML_TOKEN		"&"
#define	MY_EML_FIELD_TOKEN	"="
#define	MY_EML_DATA_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);

#ifdef __cplusplus
}
#endif
#endif
