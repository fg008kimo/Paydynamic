#ifndef _YSEXML_H
#define	_YSEXML_H

#include "myhash.h"


#ifdef __cplusplus
extern "C" {
#endif

int FormatXMLMsg(hash_t* hIn);
int BreakDownXMLMsg(hash_t *table,const unsigned char *inMsg,int inLen);

#ifdef __cplusplus
}
#endif
#endif
