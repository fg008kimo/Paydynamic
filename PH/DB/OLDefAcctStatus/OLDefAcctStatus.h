#ifndef _OLDEF_ACCT_STATUS_H_
#define _OLDEF_ACCT_STATUS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetStatusGroup(const char* csStatus,
                        char* csStatusGroup);

#ifdef __cplusplus
}
#endif

#endif
