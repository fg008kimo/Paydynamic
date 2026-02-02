#ifndef _TXN_BALANCE_DETAIL_H_
#define _TXN_BALANCE_DETAIL_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C"
{
#endif

int AddBalDetail(const hash_t * hIn);
int GetBalDetails(const char *csAprvDate, const char cStatus, recordset_t * rDetailSet);
int UpdateStatus(const char * csTxnSeq, const char cStatus);

#ifdef __cplusplus
}

#endif
#endif
