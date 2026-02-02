#ifndef _OL_MERCH_RESERVED_AMT_H_
#define _OL_MERCH_RESERVED_AMT_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);

int ChkRecExist(hash_t *hRls);

int Update(const hash_t *hRls);

int GetReservedAmt(const hash_t *hRls,
                        recordset_t *myRec);

int GetDailyCap(const char* csMerchantID,
                        const char* csCountryId,
                        const char* csCcy,
                        const char* csServiceCode,
                        const int iDayOfWeek,
                        double  *dAmt);
int GetReservedAmtForDate(const char* csMerchantID,
                        const char* csCountryId,
                        const char* csCcy,
                        const char* csServiceCode,
                        const char* csDate,
                        double  *dAmt);

int GetDailyCapforUpdate(const char* csMerchantID,
                        const char* csCountryId,
                        const char* csCcy,
                        const char* csServiceCode,
                        const int iDayOfWeek,
                        double  *dAmt,
                        double  *dRemainAmt,
			char	*csEffectDate);

int UpdateAmt(const hash_t *hRls);

int GetSpecificDailyCapforUpdate(const char* csMerchantID,
                               const char* csCountryId,
                               const char* csCcy,
                               const char* csServiceCode,
                               const int iDayOfWeek,
                               const char* csEffectDate,
                               double  *dAmt,
                               double  *dRemainAmt);

#ifdef __cplusplus
}
#endif

#endif
