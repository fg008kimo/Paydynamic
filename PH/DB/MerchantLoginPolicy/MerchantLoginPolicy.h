#ifndef _MERCHANTLOGINPOLICY_H_
#define _MERCHANTLOGINPOLICY_H_

#include "myhash.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Delete(const unsigned char* client);
#ifdef __cplusplus
}
#endif

#endif
