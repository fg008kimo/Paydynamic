#ifndef _OL_PROVIDER_BALANCE_H_
#define _OL_PROVIDER_BALANCE_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int UpdateBalance(const char* csPsp,
                const char* csCountryId,
                const char* csCcy,
		const char  cType,
                double dAmt,
                char* csUpdateUser);

int GetBalance(const char* csPspID,
                const char* csCountryId,
                const char* csCurrencyId,
                hash_t *hVal);

int UpdateHoldBalance(const char* csPsp,
                const char* csCountryId,
                const char* csCcy,
                char  cType,
                double dAmt,
                char* csUpdateUser);
#ifdef __cplusplus
}
#endif

#endif
