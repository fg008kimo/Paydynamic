#ifndef	_PR_BO_FUNCT_H_
#define	_PR_BO_FUNCT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

//////////////////Txn Seq///////////////////////
char* prbo_GetNextTxnSeq();
char* prbo_GetNextBatchTxnSeq();
char* prbo_GetNextMgtTxnSeq();
char* prbo_GetNextPayoutTxnSeq();


//////////////////Deposit///////////////////////



//////////////////////Payout/////////////////////
int prbo_UpdatePayoutAmount(hash_t* hContext);
int prbo_PayoutSuccess(hash_t* hContext,
                        const char* csCountry,
                        const char* csServiceCode,
                        const char* csMerchantCCY,
                        const char* csMerchantID,
                        double dNetAmount,
                        const char* csPspCCY,
                        const char* csPspID,
                        double dPspAmount,
                        char   cParty,
                        const int iDayOfWeek);

int prbo_PayoutVoided(hash_t* hContext,
                const char* csCountry,
                const char* csServiceCode,
                const char* csMerchantCCY,
                const char* csMerchantID,
                double dNetAmount,
                const char* csPspCCY,
                const char* csPspID,
                double dPspAmount,
                char   cParty,
                const int iDayOfWeek);



///////////////Settlement///////////////////////
int prbo_UpdateSettlementAmount(hash_t *hContext);
int prbo_Settlement2InTransit(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                double  dFee,
                char    cDirection,
                const char* csUser);

int prbo_UpdateIntransit(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser);



//////////////Merchant Balance/////////////////
int prbo_GetCurrentValues(const char* csMerchantID,
                        const char* csCurrencyId,
                        const char* csCountryId,
                        const char* csServiceCode,
                        hash_t *hVal);

int prbo_GetOpenBalanceForUpdate(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode);

int prbo_UpdateFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dCurrentAmt,
                double  dFloat,
                const char* csUser);

int prbo_UpdateAvalBal(hash_t* hContext,
                const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser);

int prbo_UpdateReserved(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dFloat,
                const char* csUser);

int prbo_UpdateSettBal(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                double  dFee,
                char    cType,
                const char* csUser);

////////Psp Balance///////
int prbo_CreditBalance(const char* csPsp,
                const char* csCountryId,
                const char* csCcy,
                char  cType,
                double dAmt,
                char* csUpdateUser);

int prbo_DebitBalance(const char* csPsp,
                const char* csCountryId,
                const char* csCcy,
                char  cType,
                double dAmt,
                char* csUpdateUser);

int prbo_GetBalance(const char* csPspID,
                const char* csCountryId,
                const char* csCurrencyId,
                hash_t *hVal);

int prbo_CalPspCosts(hash_t *hContext,
                const hash_t* hRequest);

int prbo_GetPspCosts(const char* csPspId,
                const char  cType,
                recordset_t* myRec);

//////////Txn Element//////////
int     prbo_AddTxnAmtElement(hash_t* hContext);
int     prbo_AddTxnFeeElements(hash_t* hContext);
int     prbo_AddMarkupAmtElement(hash_t* hContext);
int	prbo_AddElements(const hash_t *hRls);
int     prbo_AddReserveAmtElement(hash_t* hContext);


int prbo_ProcessMerchantAdjAmount(hash_t *hContext);

int prbo_GetSettAvalBalance(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode,
                double  *dBal);

int prbo_UpdateAdjBal(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dNetAmt,
                char    cType,
                const char* csUser);

int     prbo_AddPspTxnElement(hash_t* hRequest);
int     prbo_AddPayoutBalTransferElement(hash_t* hContext);

#ifdef __cplusplus
}
#endif

#endif

