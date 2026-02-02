#ifndef _BOBANKCHARGE_H_
#define _BOBANKCHARGE_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetTxnBankCharge(hash_t *hRls);
double CalBankCharge(const char* csCcy, char cType, double dTxnAmt, double dValue, double dAddValue, double dMin, double dMax);
int FindBankCharge(hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
