#ifndef _MI_ENTITY_BAL_MAP_H_
#define _MI_ENTITY_BAL_MAP_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindMapping(const char* csEntityType,
                char cBalanceType);

int isAllowBalNegative(const char* csEntityType,
                char cBalanceType);

#ifdef __cplusplus
}
#endif

#endif
