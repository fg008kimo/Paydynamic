#ifndef _BOREPORT_H_
#define _BOREPORT_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetPspDepositTxn(const unsigned char* csPspId,
		     const unsigned char* csTxnDate,
		     recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
