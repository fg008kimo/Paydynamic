#ifndef _BOOLBANKACCTS_H_
#define _BOOLBANKACCTS_H_
#include "myrecordset.h"
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetLastUpdBankAcctsDetails(const char* csReqDatetime, 
			       const char* csBankCode, 
			       const char* csBankAcctNum, 
			       int iMaxBankAcctCnt,
			       recordset_t* rBankAcctsDetails);

int GetBankAcctLatestDetails(const char* csBankCode, 
			     const char* csBankAcctNum, 
			     hash_t* hBankAcctDetails);

#ifdef __cplusplus
}
#endif

#endif
