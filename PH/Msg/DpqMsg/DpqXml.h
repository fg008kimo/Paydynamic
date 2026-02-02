#ifndef _DPQXML_H
#define	_DPQXML_H

#include "myhash.h"


#ifdef __cplusplus
extern "C" {
#endif

int BreakDownXMLMsg(hash_t *table,const unsigned char *inMsg,int inLen);

#ifdef __cplusplus
}
#endif
#endif
