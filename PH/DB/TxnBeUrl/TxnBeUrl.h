#ifndef _TXN_BE_URL_H_
#define _TXN_BE_URL_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Replicate(const hash_t *hRec);

int FindURL(const unsigned char* TxnCode,
		const unsigned char* ServiceCode,
                const unsigned char* PspId,
		unsigned char* URL);

int GetBeUrl(const unsigned char* csTxnCode,
                const unsigned char* csServiceCode,
                const unsigned char* csPspId,
                recordset_t* myRec);

int GetServiceCode(const char* csPspId, const char* csTxnCode, recordset_t* rRec);
#ifdef __cplusplus
}
#endif

#endif
