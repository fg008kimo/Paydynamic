#ifndef _PAYPAGE_QR_TIME_PARAM_H_
#define _PAYPAGE_QR_TIME_PARAM_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetByPspId (const char* csServiceCode,
		const char* PspId,
                hash_t* myHash);

#ifdef __cplusplus
}
#endif

#endif
