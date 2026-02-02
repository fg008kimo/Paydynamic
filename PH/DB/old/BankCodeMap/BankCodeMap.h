#ifndef _BANK_CODE_MAP_H_
#define _BANK_CODE_MAP_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int BankCodeMapping(const unsigned char* csInputBankCode,
		recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
