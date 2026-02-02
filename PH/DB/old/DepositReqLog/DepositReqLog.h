#ifndef _DEPOSIT_REQUEST_LOG_H_
#define _DEPOSIT_REQUEST_LOG_H_

#include "myhash.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Update(const hash_t *);
int Delete(const int iReqLogId);

#ifdef __cplusplus
}
#endif

#endif
