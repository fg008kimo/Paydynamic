#ifndef _MITXNLOG_H_
#define _MITXNLOG_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int CheckTxnIdExist(const char* csTxnId);

#ifdef __cplusplus
}
#endif

#endif
