#ifndef _OLPID_BAL_H_
#define _OLPID_BAL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetBalance(const char* csPspID,
                const char* csCountryId,
                const char* csCurrencyId,
                hash_t *hVal);

int UpdateBalance(const char* csPsp,
                const char* csCountryId,
                const char* csCcy,
		char   cType,
                double dAmt,
                char* csUpdateUser);

int UpdateHoldBalance(const char* csPsp,
                const char* csCountryId,
                const char* csCcy,
                char  cType,
                double dAmt,
                char* csUpdateUser);

int GetAvalPidBal(const char *csPspID,
                  const char *csCurrencyId,
		  const char *csCountryId,
		  double *dBal);

int GetOpenBalanceForUpdate(const char* csPspID,
                const char* csCountryId,
                const char* csCurrencyId,
                hash_t *hVal);

#ifdef __cplusplus
}
#endif

#endif
