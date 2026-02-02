#ifndef _PAYOUT_PRE_GENEREATE_DT_H_
#define _PAYOUT_PRE_GENEREATE_DT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRec);
int GetDetail(const hash_t* hRec,recordset_t* myRec);
#ifdef __cplusplus
}
#endif

#endif
