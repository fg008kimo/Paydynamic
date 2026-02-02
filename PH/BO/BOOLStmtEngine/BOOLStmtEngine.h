#ifndef _BOOLSTMTENGINE_H_
#define _BOOLSTMTENGINE_H_
#include "myrecordset.h"
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int ProcessUnknownMatching(hash_t *hContext);
int ProcessMatching(hash_t *hContext);
int DoAction(hash_t *hContext, hash_t *hMatchRule);
int TmpSkip(hash_t *hMatchFilter);
int CheckKeywords(hash_t *hMatchFilter);
int SplitAmount(hash_t *hContext, hash_t *hMatchRule, hash_t *hMatchFilter);

#ifdef __cplusplus
}
#endif

#endif
