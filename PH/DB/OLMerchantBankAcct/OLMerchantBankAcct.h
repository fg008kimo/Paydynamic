#ifndef _OLMERCHANT_BANK_ACCT_H_
#define _OLMERCHANT_BANK_ACCT_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int	Add(const hash_t *hOLMerchantBalAcct);
int	Update(const hash_t *hRls);
int	FindDetailByBankAcct(const char* csBankCode,
			     const char* csAcctNum,
			     recordset_t* myRec);
int     FindDetailByAvaMerchBankAcct(const char* csMerchantID,
				const char* csBankCode,
				const char* csAcctNum,
				hash_t* myHash);
/*
int     FindServiceByBankAcct(const char* csMerchantID,
				const char* csBankCode,
				const char* csAcctNum,
				hash_t* myHash);

int	CheckAvaDepositBankAccts(const hash_t *hRec);
*/

int	GetAvaDepositBankAccts(const char* csMerchantId,
				const char* csBankCode,
				const char* csCountry,
				const char* csCcy,
				const char* csServiceCode,
				const char* csAction,
				hash_t *hRec);

int	GetAvaDepositBankAcctsRandom(const char* csMerchantId,
				const char* csCountry,
				const char* csCcy,
				const char* csServiceCode,
				const char* csAction,
				hash_t *hRec);

int GetAllAvaDepositBankAccts(const char* csMerchantId, recordset_t* myRec);

int	GetBeneficiaryBank(const char* csMerchantId,
			const char* csCountry,
			const char* csCcy,
			const char* csAcctNum,
                        const char* csAction,
			hash_t *myHash);

int     GetAvaBeneficiaryBank(const char* csMerchantId,
                        const char* csCcy,
                        const char* csAcctNum,
                        hash_t *myHash);



#ifdef __cplusplus
}
#endif

#endif
