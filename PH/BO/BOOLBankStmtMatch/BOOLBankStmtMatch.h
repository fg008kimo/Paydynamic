#ifndef _BOOLBANKSTMTMATCH_H_
#define _BOOLBANKSTMTMATCH_H_
#include "myrecordset.h"
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int MatchStmtWithSms(hash_t *hContext, hash_t *hRequest, hash_t *hFile);

#ifdef __cplusplus
}
#endif

#endif
