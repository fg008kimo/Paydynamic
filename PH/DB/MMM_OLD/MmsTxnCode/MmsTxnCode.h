#ifndef _MMS_TXN_CODE_H_
#define _MMS_TXN_CODE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindProcessCode(const unsigned char* TxnCode,
		unsigned char* TxnCodeDesc,
                unsigned char* ProcessType,
                unsigned char* ProcessCode);

int FindTxnCode(unsigned char* TxnCode,
                unsigned char* TxnCodeDesc,
                const unsigned char* ProcessType,
                const unsigned char* ProcessCode);

#ifdef __cplusplus
}
#endif

#endif
