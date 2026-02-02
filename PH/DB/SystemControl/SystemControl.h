#ifndef _SYSTEM_CONTROL_H_
#define _SYSTEM_CONTROL_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetAllCodes(recordset_t* );
int FindCode(const char* code,
		unsigned char* value);
int Update(const unsigned char* code,
                const unsigned char* value);

#ifdef __cplusplus
}
#endif

#endif
