#ifndef _OLACCT_STATUS_ACTION_H_
#define _OLACCT_STATUS_ACTION_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetAllowActionFlag(const char* csBankCode,
                        const char* csBankAcctNum,
                        const char* csAction,
                        int* iAllowFlag);

#ifdef __cplusplus
}
#endif

#endif
