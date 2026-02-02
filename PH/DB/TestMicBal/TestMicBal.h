#ifndef _TEMP_MIC_BAL_H_
#define _TEMP_MIC_BAL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int UpdateFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
		const char* csServiceCode,
                double  dNetAmt,
                double  dReservedAmt,
		const char* csUser,
		hash_t* hResult);
		
int UpdateFloatR2(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
		const char* csServiceCode,
                double  dNetAmt,
                double  dReservedAmt,
		const char* csUser,
		hash_t* hResult);

#ifdef __cplusplus
}
#endif

#endif
