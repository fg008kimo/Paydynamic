#ifndef _OL_BAID_BAL_H_
#define _OL_BAID_BAL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int UpdateBalance(const char* csBAID,
                const char* csCountryId,
                const char* csCcy,
                char cType,
                double dAmt,
                char* csUpdateUser);

int UpdateHoldBalance(const char* csBAID,
                const char* csCountryId,
                const char* csCcy,
                char cType,
                double dAmt,
                char* csUpdateUser);

int GetBalance(const char* csBAID,
                const char* csCountryId,
                const char* csCurrencyId,
                hash_t *hVal);

int GetBalanceForUpdate(const char* csBAID,
                const char* csCountryId,
                const char* csCurrencyId,
                hash_t *hVal);

int GetAvalBaidBal(const char *csBaid,
                const char *csCurrencyId,
                const char *csCountryId,
                double *dBal);

int DeleteBaidBal(const char *csBaid,
		const char *csCountryId,
		const char *csCurrencyId);


#ifdef __cplusplus
}
#endif

#endif
