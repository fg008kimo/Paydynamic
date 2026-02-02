#ifndef _SEB_BALANCE_H_
#define _SEB_BALANCE_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int Add(const hash_t *);
int FindBalanceByCcy(const char* csFromCcy,const char* csBankCcy,
		hash_t* hRec);
int FindAllBalance(recordset_t* myRec);

int FindBankBalanceInfo(const char* csBankCcy,recordset_t* myRec);

int UpdateBankBalance(const char* csFromCcy,const char* csBankCcy,double dAmt);


int FindRateByDate(const char* csDateTime,
                   const char* csFromCcy,
                   const char* csBankCcy,
                   double * dRate);
#ifdef __cplusplus
}
#endif

#endif
