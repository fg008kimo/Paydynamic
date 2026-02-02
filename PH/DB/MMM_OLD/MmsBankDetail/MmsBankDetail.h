#ifndef _MMS_BANK_DETAIL_H_
#define _MMS_BANK_DETAIL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetBankDetail(const char* csBankId,
               hash_t* hRec);

#ifdef __cplusplus
}
#endif

#endif
