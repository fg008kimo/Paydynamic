#ifndef _MMS_TXN_CODE_MAP_H_
#define _MMS_TXN_CODE_MAP_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindTxnCode(unsigned char* ExtTxnCode,
                unsigned char* IntTxnCode);

#ifdef __cplusplus
}
#endif

#endif
