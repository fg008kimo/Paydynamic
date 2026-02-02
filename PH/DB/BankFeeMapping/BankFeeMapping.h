#ifndef _BANK_FEE_MAPPING_H_
#define _BANK_FEE_MAPPING_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetFeeTypeByBankCode(const char* csInputBankCode, char* csOutputFeeType);

#ifdef __cplusplus
}
#endif

#endif
