#ifndef _VOUCHER_PAYMENT_PARAMETER_H_
#define _VOUCHER_PAYMENT_PARAMETER_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindCode(const unsigned char* code,
	     unsigned char* value);

int GetAllCodes(recordset_t *myRec);

int UpdateValue(const unsigned char* code,
                const unsigned char* value);
#ifdef __cplusplus
}
#endif

#endif
