#ifndef _OL_STMT_CONVERT_ERROR_H_
#define _OL_STMT_CONVERT_ERROR_H_

#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int AddError(const hash_t *hRls);
int GetError(hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
