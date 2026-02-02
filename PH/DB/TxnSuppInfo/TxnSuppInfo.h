#ifndef _TXNSUPPINFO_H_
#define _TXNSUPPINFO_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Get(const char *, const char *, hash_t *);

#ifdef __cplusplus
}
#endif

#endif
