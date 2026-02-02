#ifndef _TEST_CREATE_H_
#define _TEST_CREATE_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int     Add(const hash_t *hRls);
int 	Update(const char cKey, const hash_t *hRls);
int	Get(const char cKey, hash_t* myHash);

int	UpdateWithGet(hash_t *hIn,   hash_t *hOut);

#ifdef __cplusplus
}
#endif

#endif

