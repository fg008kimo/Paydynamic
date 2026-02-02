#ifndef _OL_RULE_PAYPAGE_BANK_H_
#define _OL_RULE_PAYPAGE_BANK_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetBankList(const char* csMerchantId,
                const char* csClientId,
                recordset_t* myRec);


#ifdef __cplusplus
}
#endif

#endif
