#ifndef _EXCHANGERATEERS_H_
#define _EXCHANGERATEERS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int GetExchangeRateERS(const char* csFromCcyId, const char* csToCcyId, hash_t* hRec);
int GetExchangeRateERSByDate(const char* csQuoteDate, const char* csFromCcyId, const char* csToCcyId, hash_t* hRec);
int GetExchangeRateERSByDateTime(const char* csEffectDateTime, const char* csFromCcyId, const char* csToCcyId, hash_t* hRec);
int GetAllExchangeRateERSByDate(const char* csQuoteDate, recordset_t* rRS);
#ifdef __cplusplus
}
#endif

#endif
