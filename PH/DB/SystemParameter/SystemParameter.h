#ifndef _SYSTEM_PARAMETER_H_
#define _SYSTEM_PARAMETER_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindCode(	const unsigned char* code,
		unsigned char* value);

int GetAllCodes(recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
