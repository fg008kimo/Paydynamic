#ifndef _DEFVOIDTXNCONFIG_H_
#define _DEFVOIDTXNCONFIG_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindCode(const unsigned char* txn_code,
		const unsigned char* code,
		unsigned char* value);

#ifdef __cplusplus
}
#endif

#endif
