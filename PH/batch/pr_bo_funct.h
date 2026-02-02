#ifndef	_PR_BO_FUNCT_H_
#define	_PR_BO_FUNCT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

//////////////////Txn Seq///////////////////////
char* GetNextTxnSeq();
char* GetNextBatchTxnSeq();
char* GetNextMgtTxnSeq();
char* GetNextPayoutTxnSeq();


//////////////////Deposit///////////////////////



//////////////////////Payout/////////////////////
int UpdatePayoutAmount(hash_t* hContext);
int PayoutSuccess(hash_t* hContext,
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

int PayoutVoided(hash_t* hContext,
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
int UpdateSettlementAmount(hash_t *hContext);
int Settlement2InTransit(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                double  dFee,
                char    cDirection,
                const char* csUser);

int UpdateIntransit(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser);



//////////////Merchant Balance/////////////////
int GetCurrentValues(const char* csMerchantID,
                        const char* csCurrencyId,
                        const char* csCountryId,
                        const char* csServiceCode,
                        hash_t *hVal);

int GetOpenBalanceForUpdate(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode);

int UpdateFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dCurrentAmt,
                double  dFloat,
                const char* csUser);

int UpdateAvalBal(hash_t* hContext,
                const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser);

int UpdateReserved(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                const int iDayOfWeek,
                double  dAmt,
                const char* csUser);


////////Psp Balance///////
int CreditBalance(const char* csPsp,
                const char* csCountryId,
                const char* csCcy,
                char  cType,
                double dAmt,
                char* csUpdateUser);

int DebitBalance(const char* csPsp,
                const char* csCountryId,
                const char* csCcy,
                char  cType,
                double dAmt,
                char* csUpdateUser);

int GetBalance(const char* csPspID,
                const char* csCountryId,
                const char* csCurrencyId,
                hash_t *hVal);

int CalPspCosts(hash_t *hContext,
                const hash_t* hRequest);

int GetPspCosts(const char* csPspId,
                const char  cType,
                recordset_t* myRec);

//////////Txn Element//////////
int     AddTxnAmtElement(hash_t* hContext);
int     AddTxnFeeElements(hash_t* hContext);
int     AddMarkupAmtElement(hash_t* hContext);
int	AddElements(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif

