#ifndef _MMS_BANK_BALANCE_H_
#define _MMS_BANK_BALANCE_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int CreditBalance(const char* csBankId,
                const char* csCcy,
                double dAmt,
                char* csUpdateUser);

int GetBalance(const char* csBankId,
                const char* csCurrencyId,
                hash_t *hVal);

int DebitBalance(const char* csBankId,
                const char* csCcy,
                double dAmt,
                char* csUpdateUser);

int GetAvalBankBalance(const char *csBankId,
                        const char *csCurrencyId,
                        double *dBal);

#ifdef __cplusplus
}
#endif

#endif
