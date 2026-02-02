#ifndef _EXCHANGERATE_H_
#define _EXCHANGERATE_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int GetExchangeRate(const char* csFromCcyId, const char* csToCcyId, hash_t* hRec);
int GetExchangeRateByDate(const char* csQuoteDate, const char* csFromCcyId, const char* csToCcyId, hash_t* hRec);
int GetExchangeRateByDateTime(const char* csEffectDateTime, const char* csFromCcyId, const char* csToCcyId, hash_t* hRec);
int GetAllExchangeRateByDate(const char* csQuoteDate, recordset_t* rRS);
int GetAllExchangeRateByExactDate(const char* csEffectDate, recordset_t* rRS);
int DeleteDuplicateExchangeRateByExactDate(const char* csEffectDate, const char* csFromCcyId, const char* csToCcyId);
#ifdef __cplusplus
}
#endif

#endif
