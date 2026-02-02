#ifndef _NBXMSG_H
#define	_NBXMSG_H

#include "myhash.h"


#define	MY_NBX_TOKEN		"&"
#define	MY_NBX_FIELD_TOKEN	"="
#define	MY_NBX_BOUNCE_FIELD_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int FormatAckMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int DeBlockWebBounceBackData(hash_t *hOut,const char* inMsg, const int inLen);


int Encrypt(unsigned char* csKey,int iKeyLen,unsigned char* inBuf, int iBuffLen,unsigned char* outBuf);
int Decrypt(const char* csKey,int iKeyLen,const char* inBuf, int iBuffLen,char* outBuf);
unsigned char* calcMsgCheckSum(unsigned char* MsgLen, unsigned char* MsgBody, int seed);
unsigned char* attachMsgLenAndCheckSum(const unsigned char* inBuf);
unsigned char* genChecksum(unsigned char* inBuf, int len);
void DeBlockParam(hash_t *hOut,const unsigned char* inBuf, int iLen);
unsigned char* ParseIt(hash_t *hOut,unsigned char* inBuf);
int     GetResult(const unsigned char* inBuf, int iLen,unsigned char* outBuf,int* oLen);

#ifdef __cplusplus
}
#endif
#endif
