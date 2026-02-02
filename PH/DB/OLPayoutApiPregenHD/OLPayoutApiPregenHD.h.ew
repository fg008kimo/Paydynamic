#ifndef _OL_PAYOUT_API_PREGEN_HD_H_
#define _OL_PAYOUT_API_PREGEN_HD_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRec);
int GetHeader(const hash_t *hRec, recordset_t* myRec);
int GetNextSeq();
int Update(const hash_t *hRec);
int MatchPregenStatus(const hash_t *hRec);
int MatchPregenStatus_ForUpdate(const hash_t *hRec);
#ifdef __cplusplus
}
#endif

#endif
