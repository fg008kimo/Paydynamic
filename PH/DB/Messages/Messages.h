#ifndef _MESSAGES_H_
#define _MESSAGES_H_

#include "myhash.h"
#ifdef __cplusplus
extern "C" {
#endif

int i2c(const unsigned char* ChannelCode,long InternalCode,unsigned char* DestCode);
int c2i(const unsigned char* ChannelCode,long *InternalCode,const unsigned char* SrcCode);
int c2i_po(const unsigned char* ChannelCode,long *InternalCode,const unsigned char* SrcCode);
int GetInternalMessage(const int IntCode,unsigned char* IntMsg);
#ifdef __cplusplus
}
#endif

#endif
