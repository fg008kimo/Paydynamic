#ifndef _MMSSTOREFORWARD_H_
#define _MMSSTOREFORWARD_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int GetPendingSF(const char	cMode,
                recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
