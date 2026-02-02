#ifndef _SMSMSG_H
#define	_SMSMSG_H

#include "myhash.h"


#define	MY_SMS_TOKEN		"&"
#define	MY_SMS_FIELD_TOKEN	"="
#define	MY_SMS_BOUNCE_FIELD_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

void SmsMsg(char);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);

#ifdef __cplusplus
}
#endif
#endif
