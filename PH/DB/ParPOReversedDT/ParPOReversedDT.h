#ifndef _PAR_PO_REVERSED_DT_H_
#define _PAR_PO_REVERSED_DT_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int	GetReversedFileDetail(const hash_t *hTxn, recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
