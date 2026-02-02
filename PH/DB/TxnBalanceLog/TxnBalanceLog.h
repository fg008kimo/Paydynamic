#ifndef _TXN_BALANCE_LOG_H_
#define _TXN_BALANCE_LOG_H_

#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int	UpdateBalLog(hash_t* myHash);

int	IsCompleted(const char *csDate, const char cParty);

int     IsPrevCompleted(hash_t* hRec);

int     IsExisted(hash_t* hRec);

#ifdef __cplusplus
}
#endif

#endif

