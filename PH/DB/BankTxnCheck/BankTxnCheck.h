#ifndef _BANK_TXN_CHECK_H_
#define _BANK_TXN_CHECK_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetAllBankCheck(recordset_t *myRec);
int GetAllBankCheckByBank(recordset_t *myRec, char *csBankCode);

#ifdef __cplusplus
}
#endif

#endif
