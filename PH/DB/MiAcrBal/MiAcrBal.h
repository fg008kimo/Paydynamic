#ifndef _MI_ACR_BAL_H_
#define _MI_ACR_BAL_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int Add(const hash_t *);
int GetOwnAcrBal(const hash_t *hRec, hash_t *hBal);
int GetOwnAcrBalForUpdate(const hash_t *hRec, hash_t *hBal);
int GetAllAcrBalByCcy(const char* csCcy,recordset_t* myRec);
int FindRateByDate(const char* csDateTime,
                   const char* csFromCcy,
                   const char* csBankCcy,
                   double * dRate);


#ifdef __cplusplus
}
#endif

#endif
