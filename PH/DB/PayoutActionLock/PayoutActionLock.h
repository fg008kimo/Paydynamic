#ifndef _PO_ACTION_LOCK_H_
#define _PO_ACTION_LOCK_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int CheckTheActionCtl(const char cPlatform);
int CheckTheActionCtl_ReadOnly(const char cPlatform);
int TakeTheActionCtl(const char cPlatform);
int ReleaseTheActionCtl(const char cPlatform);


#ifdef __cplusplus
}
#endif

#endif
