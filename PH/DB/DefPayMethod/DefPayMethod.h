#ifndef _DEF_PAY_METHOD_H_
#define _DEF_PAY_METHOD_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindPayMethodCurrency(const char* csPayMethod,
			  unsigned char* csCcyId);

#ifdef __cplusplus
}
#endif

#endif
