#ifndef _OL_DEF_BANK_ACCT_TYPE_
#define _OL_DEF_BANK_ACCT_TYPE_

#ifdef __cplusplus
extern "C" {
#endif

#include "myrecordset.h"

int GetBaidNameCode(const unsigned char* csType, hash_t *hRec);
int GetAllFEDisplay(recordset_t* rRecordSet);

#ifdef __cplusplus
}
#endif

#endif
