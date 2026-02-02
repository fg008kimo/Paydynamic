#ifndef _TLGMSG_H
#define	_TLGMSG_H

#include "myhash.h"


#define	MY_TLG_TOKEN		"&"
#define	MY_TLG_FIELD_TOKEN	"="
#define	MY_TLG_BOUNCE_FIELD_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

void TlgMsg(char);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);

#ifdef __cplusplus
}
#endif
#endif
