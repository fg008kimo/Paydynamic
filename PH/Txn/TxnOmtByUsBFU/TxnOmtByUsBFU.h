#ifndef _TXNOMTBYUSBFU_H_
#define _TXNOMTBYUSBFU_H_

#include "myhash.h"

#ifdef __cplusplus
extern "C"
{
#endif

int Authorize(hash_t *hContext, const hash_t *hRequest, hash_t *hResponse);
int IsValidPath(char *csPath, int isPath);

#ifdef __cplusplus
}

#endif
#endif
