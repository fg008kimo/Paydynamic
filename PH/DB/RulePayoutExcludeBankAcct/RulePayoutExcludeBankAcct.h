#ifndef _RULE_PAYOUT_EXCLUDE_BANK_ACCT_H
#define _RULE_PAYOUT_EXCLUDE_BANK_ACCT_H

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Delete(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
