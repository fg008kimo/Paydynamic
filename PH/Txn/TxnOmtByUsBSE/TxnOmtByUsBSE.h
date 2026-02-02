#ifndef _TXNOMTBYUSBSE_H_
#define _TXNOMTBYUSBSE_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetKeyTagName(int iHeader, char *csTagName);
int GetSubDataTagName(int iHeader, char *csTagName);
int Authorize(hash_t* hContext, hash_t* hRequest, hash_t* hResponse);

#ifdef __cplusplus
}
#endif

#endif
