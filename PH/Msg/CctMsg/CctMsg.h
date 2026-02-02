#ifndef _CCTMSG_H
#define	_CCTMSG_H

#include "myhash.h"


#define	MY_CCT_TOKEN		"&"
#define	MY_CCT_FIELD_TOKEN	"="
#define	MY_CCT_BOUNCE_FIELD_TOKEN	"|"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int FormatEnMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int FormatDeMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int BreakDownAckMsg(hash_t *table);
int BreakDownRespMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int FormatFEMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int FormatAckMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int FormatBatchMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int DeBlockWebBounceBackData(hash_t *hOut,const char* inMsg, const int inLen);

int BuildAuthData(hash_t* hIn);
int BuildRespAuthData(hash_t* hIn);
int BuildAckAuthData(hash_t* hIn);

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
