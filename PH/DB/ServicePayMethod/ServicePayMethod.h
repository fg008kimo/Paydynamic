#ifndef _SERVICE_PAY_METHOD_H_
#define _SERVICE_PAY_METHOD_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int IsServicePayMethodSupported(const char* csServiceCode,
			const char* csPayMethod);

int FindPayMethod(const char* csServiceCode,
                  recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
