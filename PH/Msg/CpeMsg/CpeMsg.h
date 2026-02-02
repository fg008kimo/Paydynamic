#ifndef _CPEMSG_H
#define	_CPEMSG_H

#include "myhash.h"


#define	MY_CPE_TOKEN			"&"
#define	MY_CPE_FIELD_TOKEN		"="
#define MY_CPE_DATA_TOKEN		"|"

#define MY_CPE_OPEN_BRACKET		"{"
#define MY_CPE_CLOSE_BRACKET		"}"
#define MY_CPE_SERVER_NO		"100008"
#define MY_CPE_PAY_MODE			"API_GATEWAY"
#define MY_CPE_AGING			"1"
#define MY_CPE_SIGNATURE_LEN		16

#define MY_CPE_SUCCESS_STATUS		"0000"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t* table,unsigned char *outMsg, int *outLen);
int BuildAuthData(hash_t* hIn);
int BreakDownMsg(hash_t *table,const unsigned char *inMsg,int inLen);
int initReplyFromRequest(const hash_t*, hash_t*);
int FormatInitMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen);
int BreakDownInitRspMsg(hash_t *hOut,const unsigned char *inMsg,int inLen);
int BuildRspAuthData(hash_t* hIn);
void remove_quote(const char *csValue, const int iType, char *csOut);

#ifdef __cplusplus
}
#endif
#endif
