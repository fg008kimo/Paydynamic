#ifndef _PSP_TXN_CHECK_REPORT_LOG_H_
#define _PSP_TXN_CHECK_REPORT_LOG_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int GetPspTxnCheckReportLog(hash_t *myHash, recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
