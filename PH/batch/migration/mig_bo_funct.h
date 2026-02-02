#ifndef	_MIG_BO_FUNCT_H_
#define	_MIG_BO_FUNCT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

//////////////////Txn Seq///////////////////////
char* migbo_GetNextTxnSeq();
char* migbo_GetNextBatchTxnSeq();
char* migbo_GetNextMgtTxnSeq();
char* migbo_GetNextPayoutTxnSeq();


//////////////////Deposit///////////////////////



//////////////////////Payout/////////////////////
int migbo_UpdatePayoutAmount(hash_t* hContext);
int migbo_PayoutSuccess(hash_t* hContext,
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

int migbo_PayoutVoided(hash_t* hContext,
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
int migbo_UpdateSettlementAmount(hash_t *hContext);
int migbo_Settlement2InTransit(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                double  dFee,
                char    cDirection,
                const char* csUser);

int migbo_UpdateIntransit(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser);



//////////////Merchant Balance/////////////////
int migbo_GetCurrentValues(const char* csMerchantID,
                        const char* csCurrencyId,
                        const char* csCountryId,
                        const char* csServiceCode,
                        hash_t *hVal);

int migbo_GetOpenBalanceForUpdate(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode);

int migbo_UpdateFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dCurrentAmt,
                double  dFloat,
                const char* csUser);

int migbo_UpdateAvalBal(hash_t* hContext,
                const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser);

int migbo_UpdateReserved(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dFloat,
                const char* csUser);

int migbo_UpdateSettBal(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                double  dFee,
                char    cType,
                const char* csUser);

////////Psp Balance///////
int migbo_CreditBalance(const char* csPsp,
                const char* csCountryId,
                const char* csCcy,
                char  cType,
                double dAmt,
                char* csUpdateUser);

int migbo_DebitBalance(const char* csPsp,
                const char* csCountryId,
                const char* csCcy,
                char  cType,
                double dAmt,
                char* csUpdateUser);

int migbo_GetBalance(const char* csPspID,
                const char* csCountryId,
                const char* csCurrencyId,
                hash_t *hVal);

int migbo_CalPspCosts(hash_t *hContext,
                const hash_t* hRequest);

int migbo_GetPspCosts(const char* csPspId,
                const char  cType,
                recordset_t* myRec);

//////////Txn Element//////////
int     migbo_AddTxnAmtElement(hash_t* hContext);
int     migbo_AddTxnFeeElements(hash_t* hContext);
int     migbo_AddMarkupAmtElement(hash_t* hContext);
int     migbo_AddSettMarkupAmtElement(hash_t* hContext);
int	migbo_AddElements(const hash_t *hRls);
int     migbo_AddReserveAmtElement(hash_t* hContext);


int migbo_ProcessMerchantAdjAmount(hash_t *hContext);

int migbo_GetSettAvalBalance(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode,
                double  *dBal);

int migbo_UpdateAdjBal(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dNetAmt,
                char    cType,
                const char* csUser);

int     migbo_AddPspTxnElement(hash_t* hRequest);
int     migbo_AddPayoutBalTransferElement(hash_t* hContext);

#ifdef __cplusplus
}
#endif

#endif

