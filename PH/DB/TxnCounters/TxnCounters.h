#ifndef _TXN_COUNTERS_H_
#define _TXN_COUNTERS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int CounterCreate(const char* csTxnCode,
                const char* csCountry,
		const char* csChannelCode,
		const char* csServiceCode,
		const char* csPayMethod,
                const char  cPartyType,
                const char* csPartyId,
                const char* csCcy,
                double  dCounter,
                const char* csUser);

int FindCounters(const char* csTxnCode,
                const char* csCountryId,
		const char* csChannelCode,
		const char* csServiceCode,
                const char  cType,
                const char* csCategory,
                const char  cPartyType,
                const char* csPartyId,
		recordset_t* myRec);

int FindCounterForWeb(
                const char* csServiceCode,
                hash_t  *myHash);

int GetMobAmtCount(const char* csMerchantId,
		   const char* csCcy,
                   const char* csGroup,
                   double *dAmt);
#ifdef __cplusplus
}
#endif

#endif
