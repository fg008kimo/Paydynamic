#ifndef _OL_MERCH_BALANCE_H_
#define _OL_MERCH_BALANCE_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const char* csMerchantId,
        const char* csCountryId,
	const char* csCcy,
	const char* csServiceCode,
	const char* csUser);

int GetCurrentValues(const char* csMerchantID,
                        const char* csCurrencyId,
                        const char* csCountryId,
                        const char* csServiceCode,
                        hash_t *hVal);

int UpdateCurrBal(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser);


int UpdateHoldBalance(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
		const char  cMHind,
                const char  cType,
                double  dAmt,
                const char* csUser);


int GetOpenBalanceForUpdate(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode);

int GetCurrBalance(const char* csMerchantID,
                   const char* csCurrencyId,
                   const char* csCountryId,
                   const char* csServiceCode,
                   double  *dBal);

int GetRemainPOBalance(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode,
                double  *dBal);

int UpdatePayoutReserved(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser);

int GetSettAvalBalanceInq(const char* csMerchantID,
                        const char* csCurrencyId,
                        const char* csCountryId,
                        const char* csServiceCode,
                        double  *dBal);

int GetSettTotalAvalBalance(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode,
                double  *dBal);

int UpdateSettInTransit(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                char    cType,
                const char* csUser);

int GetSettInTransit(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode,
                double  *dBal);

int UpdateSettBal(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                double  dFee,
                char    cType,
                const char* csUser);

int GetCurrBalanceInq(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode,
                double  *dBal);

int SetFundInPayout(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser);

int UpdateFundInPayout(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser);

int Rls2AfterPOFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser);

int UpdateAdjBal(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dNetAmt,
                char    cType,
                const char* csUser);

int GetSettAvalBalance(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode,
                double  *dBal);

int GetCurrBalanceForUpdate(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode,
                double  *dBal);

int GetCurrentValuesForUpdate(const char* csMerchantID,
                        const char* csCurrencyId,
                        const char* csCountryId,
                        const char* csServiceCode,
                        hash_t *hVal);


int RlsAfterPOFloat2SettlementFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser);


int ReleaseSettFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dBal,
                const char* csUser);

int TransferAvaPayout(const char* csMerchantId,
                        const char* csCountryId,
                        const char* csCcy,
                        const char* csServiceCode,
                        double  dFundin,
                        double  dResvPO,
                        double  dNetAmt,
                        const char* csUser);
#ifdef __cplusplus
}
#endif

#endif
