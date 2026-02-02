#ifndef _OL_WAIT_PAYOUT_RECON_CFM_LIST_H_
#define _OL_WAIT_PAYOUT_RECON_CFM_LIST_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C"
{
#endif

int Add(const hash_t *hRls);
int DeleteSingle(const hash_t *hRls);
int DeleteTxn(const hash_t *hRls);
int DeleteBAID(const hash_t *hRls);

#ifdef __cplusplus
}

#endif
#endif
