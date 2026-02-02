#ifndef _DEF_TXN_CODE_MAP_H_
#define _DEF_TXN_CODE_MAP_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetTxnCodeMap(const unsigned char* csFromTxnCode,
		   unsigned char* csToTxnCode,
		   unsigned char* csToTxnDesc);

#ifdef __cplusplus
}
#endif

#endif
