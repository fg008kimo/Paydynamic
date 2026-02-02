#ifndef _OL_AUTO_UPLOAD_ACCT_STATUS_H_
#define _OL_AUTO_UPLOAD_ACCT_STATUS_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetBankAcctStatus(const char* csAcctType,
		      recordset_t* myRec);
int ChkBankAcctStatusSetEnable(const char* csAcctType, 
			       const char* csFrStatusType,
			       const char* csToStatusType);
int ChkBankAcctStatusSetDisable(const char* csAcctType,
				const char* csFrStatusType,
				const char* csToStatusType);
	
#ifdef __cplusplus
}
#endif

#endif
