#ifndef _PSPRECONHISTORY_H_
#define _PSPRECONHISTORY_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int GetReconDetail(const char* csReconId,
                   recordset_t* myRec);
int GetReconHistoryByApprovalDate(const char* csPspId,
		   const char* csCcy,
                   const char* csCountry,
                   const char* csDate,
                   recordset_t* myRec);
int Delete(const unsigned char* txn_id);

#ifdef __cplusplus
}
#endif

#endif
