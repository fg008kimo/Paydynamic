#ifndef _MMS_STLBANK_DETAIL_H_
#define _MMS_STLBANK_DETAIL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetStlBankDetail(const char* csStlBankId,
               hash_t* hRec);

#ifdef __cplusplus
}
#endif

#endif
