#ifndef _BOOLBANKSTMT_H_
#define _BOOLBANKSTMT_H_
#include "myrecordset.h"
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int ProcessAuxStmtFile(hash_t *hContext, hash_t *hRequest, recordset_t* rRecordFormat);

int ConvertStmtFile(hash_t* hContext);
int ProcessStmtFile(hash_t *hContext, hash_t *hRequest, recordset_t* rRecordFormat);

#ifdef __cplusplus
}
#endif

#endif
