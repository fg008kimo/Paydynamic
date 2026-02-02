#ifndef _MMS_TXN_CODE_H_
#define _MMS_TXN_CODE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindTxnCode(unsigned char* TxnCode,
                unsigned char* TxnCodeDesc,
                const unsigned char* ProcessType,
                const unsigned char* ProcessCode);
int Find(const hash_t* hRls);
int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int Delete(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
