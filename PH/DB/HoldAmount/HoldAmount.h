#ifndef _HOLD_AMOUNT_H_
#define _HOLD_AMOUNT_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetAllHold(	const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
		recordset_t* myRec);

int GetHoldByType(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
		const char* csType,
                double  *dHoldedAmt,
                double  *dHoldRemain);

int UpdateHoldAmount(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
		const char* csType,
                double  dAmt,
                const char* csUser);

#ifdef __cplusplus
}
#endif

#endif
