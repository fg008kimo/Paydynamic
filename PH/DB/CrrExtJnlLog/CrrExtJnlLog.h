#ifndef _CRR_EXT_JNL_LOG_H_
#define _CRR_EXT_JNL_LOG_H_

#include "myhash.h"
#include "myrecordset.h"

#define PD_PARTY_TYPE_LEN	1
#define PD_PARTY_ID_LEN		15

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int GetAllPostJnl(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct, const char cPostType);


#ifdef __cplusplus
}
#endif

#endif
