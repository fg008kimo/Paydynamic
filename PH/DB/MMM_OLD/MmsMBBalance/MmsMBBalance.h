#ifndef _MMS_MB_BALANCE_H_
#define _MMS_MB_BALANCE_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int CreditBalance(const char* csMBId,
                const char* csCcy,
                double dAmt,
                char* csUpdateUser);

int GetBalance(const char* csMBId,
                const char* csCurrencyId,
                hash_t *hVal);

int DebitBalance(const char* csMBId,
                const char* csCcy,
                double dAmt,
                char* csUpdateUser);

int GetAvalMBBalance(const char *csMBId,
                        const char *csCurrencyId,
                        double *dBal);
#ifdef __cplusplus
}
#endif

#endif
