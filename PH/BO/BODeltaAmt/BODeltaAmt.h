#ifndef _BODELTAAMT_H_
#define _BODELTAAMT_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetMerchantSupportDeltaAmt(const char* csMerchantID,
                                const char* csCountry,
                                const char* csCcy,
                                const char* csServiceCode);

int GetAvailablePspByBank(const char *csBank,
                const char *csCountry,
                double dTxnAmt,
		const char *csIpAddr,
                hash_t *hResponse);

int FilterAvailablePsp( const hash_t *hContext,
			const hash_t *hInList,
			hash_t *hOutList,
			double dTxnAmt);

#ifdef __cplusplus
}
#endif

#endif
