#ifndef _FUNDSIN_HISTORY_H_
#define _FUNDSIN_HISTORY_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int GetFundsInHistory(const hash_t *hRls, recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
