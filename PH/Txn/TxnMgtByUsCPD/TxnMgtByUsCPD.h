#ifndef _TXNMGTBYUSCPD_H_
#define _TXNMGTBYUSCPD_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif
int Authorize(hash_t* hContext,
                hash_t* hRequest,
                hash_t* hResponse);
int CheckURLSpecialHandling(const char cCharacter, const char* csChannelCode, const char* csPspUrl);
int IsValid(const char* csParameter, int iType);
void URLCharacterConverter(const char cCharacter, const char* csOPspUrl, char* csCPspUrl);
#ifdef __cplusplus
}
#endif

#endif
