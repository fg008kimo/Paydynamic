#ifndef _OL_PAYOUT_RECON_TRIGGER_LOG_H_
#define _OL_PAYOUT_RECON_TRIGGER_LOG_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C"
{
#endif

int CheckConflict(const hash_t* hRls);
int GetHeaderByFileId(unsigned long lTrigSeq, hash_t *hOut);
int MatchHeaderStatusForUpdate(unsigned long lTrigSeq, const char cStatus);
int UpdateHeader(const hash_t *hIn);


#ifdef __cplusplus
}

#endif
#endif
