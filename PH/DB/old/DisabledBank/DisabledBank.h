#ifndef _DISABLED_BANK_H_
#define _DISABLED_BANK_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);

int MatchDisabledBank(const char *csPspId,
                      const char *csIntBankCode);

#ifdef __cplusplus
}
#endif

#endif
