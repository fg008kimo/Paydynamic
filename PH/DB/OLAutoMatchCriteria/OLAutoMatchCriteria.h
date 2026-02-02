#ifndef _OLAUTOMATCHCRITERIA_H_
#define _OLAUTOMATCHCRITERIA_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetAutoMatchCriteria(const char *csMerchantId,
                                recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
