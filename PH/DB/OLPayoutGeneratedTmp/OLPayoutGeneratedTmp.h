#ifndef _OL_PAYOUT_GENEREATED_TMP_H_
#define _OL_PAYOUT_GENEREATED_TMP_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRec);
int GetNextId(int *iId);
int GetExistingPsp(const int iGenId, recordset_t* myRec);
int GetExistingPspOnlineMode(const int iGenId, recordset_t* myRec);
int HoldPreGenId(const int iGenId);
int GetPreGenIdForUpdate(const int iGenId, const int iDisabled);
#ifdef __cplusplus
}
#endif

#endif
