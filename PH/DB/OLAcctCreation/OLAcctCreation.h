#ifndef _OL_ACCT_CREATION_H_
#define _OL_ACCT_CREATION_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C"
{
#endif

int AddDetail(const hash_t *hIn);
int AddError(const hash_t *hIn);
int GetHeaderByFileId(unsigned long iFileId, hash_t *hOut);
int MatchHeaderStatusForUpdate(unsigned long iFileId, const char cStatus);
int UpdateHeader(const hash_t *hIn);

#ifdef __cplusplus
}

#endif
#endif
