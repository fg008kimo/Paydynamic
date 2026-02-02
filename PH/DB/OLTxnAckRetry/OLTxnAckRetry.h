#ifndef _OLTXNACKRETRY_H_
#define _OLTXNACKRETRY_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Update(const hash_t* hRls);
int GetPendingAck(const int iMaxTry,
                recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
