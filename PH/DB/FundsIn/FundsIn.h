#ifndef _FUNDS_IN_H_
#define _FUNDS_IN_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int UpdateCal(const hash_t *hRls);
int Add(hash_t *hRls);
int UpdateApprove(const hash_t *hRls);
int GetFundsInDetail(const char *csId, recordset_t* myRec);

int GetApprovedFundsInById(const int iId, hash_t* myHash);
#ifdef __cplusplus
}
#endif

#endif
