#ifndef _EOD_GLPOSTTXN_H_
#define _EOD_GLPOSTTXN_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int PostTxn(hash_t *hContext,NODE *Nptr);
#ifdef __cplusplus
}
#endif

#endif
