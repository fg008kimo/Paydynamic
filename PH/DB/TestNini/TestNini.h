#ifndef _TEST_CREATE_H_
#define _TEST_CREATE_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int     Add(const hash_t *hRls);
int 	Update( const hash_t *hRls);
int	GetDetail(const char* csTxnCode, const char* csServiceCode, hash_t* myHash);
int	GetDetailByTxnCode(const char* csTxnCode, recordset_t* myHash);

#ifdef __cplusplus
}
#endif

#endif

