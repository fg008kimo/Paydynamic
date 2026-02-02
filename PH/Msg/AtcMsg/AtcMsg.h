#ifndef _ATCMSG_H
#define	_ATCMSG_H

#include "myhash.h"

#define	MY_ATC_TOKEN			"&"
#define	MY_ATC_FIELD_TOKEN		"="
#define	MY_ATC_BOUNCE_FIELD_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

void AtmMsg(char);
int FormatMsg(const hash_t* hIn, unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *hOut, const unsigned char *inMsg, int inLen);

#ifdef __cplusplus
}
#endif

#endif
