#ifndef _RULE_DISABLED_BANK_H_
#define _RULE_DISABLED_BANK_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetDisabledBank(const unsigned char* csChannel,
		    const unsigned char* csTxnCountry,
		    const char cPartyType,		
		    recordset_t*);
	
int GetAllBankByCountry(const unsigned char* csTxnCountry,
			recordset_t*);

int DisabledBankInfo(const unsigned char* csBank,
		    const char cPartyType,		
                    recordset_t* myRec);

int GetAllBankSupported(const unsigned char* csTxnCountry,
                        const unsigned char* csPayMethod,
                        recordset_t* myRec);

int DisableBankSchedulerId(const unsigned char* csBank,
			     const char cPartyType,
			     const unsigned char* csPartyId);

int GetDisableSchedule(const unsigned char* csChannel,
                    const char cPartyType,
                    const unsigned char* csPartyId,
                    const unsigned char* csBankCode,
                    recordset_t* myRec);

int GetCurrDisabledBank(const unsigned char* csChannel,
		    const unsigned char* csTxnCountry,
		    const char cPartyType,		
		    const int iInRunningPeriod,
		    recordset_t*);
	

int CheckCurrDisableByPsp(const unsigned char* csChannel,
                    const unsigned char* csPspId,
                    const unsigned char* csBankCode,
		    const int iInRunningPeriod,
                    hash_t* hDis);

int GetCurrDisabledMobOption(const unsigned char* csChannel,
		    const unsigned char* csTxnCountry,
		    const char cPartyType,		
		    const int iInRunningPeriod,
		    recordset_t*);

int GetCurrDisabledNGOption(const unsigned char* csChannel,
                    const unsigned char* csTxnCountry,
                    const unsigned char* csServiceCode,
                    const char cPartyType,
		    const char cDeviceType,
                    const int iInRunningPeriod,
                    recordset_t*);

int GetCurrDisabledMobNew(const unsigned char* csChannel,
                    const unsigned char* csTxnCountry,
		    const unsigned char* csServiceCode,
                    const char cPartyType,
		    const char cDeviceType,	
                    const int iInRunningPeriod,
                    recordset_t*);
	
#ifdef __cplusplus
}
#endif

#endif
