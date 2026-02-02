#ifndef _RULE_LB_H_
#define _RULE_LB_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int MatchCriteria(const hash_t*,		
			recordset_t*);
	
int FindAvalPsp(int     iPoolId,
                const char* csServiceCode,
                const char* csTxnCountry,
                double dTotal);

int FindAvalPspForPool(int iPoolId,
                        hash_t* hRec);

int GetAllPspByMerch(const char* csMerchantId,
			recordset_t* myRec);

int GetAllPspByMerchBank(const char* csMerchantId,
                        const char* csBank,
                        recordset_t* myRec);

int HaveDefineRuleByService(const char* csServiceCode);

int GetBankPspByMerch(const char* csMerchantId,
                        recordset_t* myRec);
/*
int GetDstCcyWithLBRule(const char* csMerchantId,
                        const char* csServiceCode,
                        recordset_t* myRec);

int GetDstCcyWithoutLBRule(const char* csMerchantId,
                        const char* csServiceCode,
                        recordset_t* myRec);
*/
int GetDstCcyWithoutRule(const char* csMerchantId,
                       const char* csServiceCode,
                       hash_t * hTxn);

int GetCustomerGroup(const char* csMerchantId,
                     const char* csServiceCode,
                     const char* csCcy,
                     const char* csBankCode,
                     hash_t * hTxn);

int GetBankPspByMerchNCcy(const char* csMerchantId,
                        const char* csCcy,
                        recordset_t* myRec);

int GetBankPspByMerchNCcyNGrp( const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
                        const char* csCustomerGroup,
			const char* csIpRegionCode,
			const char* csCustId,
			const int   iRestrictedIP,
			const double dAmt,
                        recordset_t* myRec);

int GetPromoteCustomerGroup(const char* csMerchantId,
                     const char* csServiceCode,
                     const char* csCcy,
                     const char* csBankCode,
                     const char* csFromGroup,
                     hash_t * hTxn);
/*
int GetBankPspForNewPhaseNCust(const char* csMerchantId,
                        const char* csCcy,
                        recordset_t* myRec);
*/
int HaveDefineSmallAmtRule(const char* csChannel,
                           const char* csMerchantId,
                           const char* csServiceCode,
                           const char* csCountry,
                           const char* csCcy,
                           char cCardType,
			   const double dAmt);

int GetBankPspForSARIP( const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
			const char* csIpRegionCode,
			const char* csCustId,
			const int   iRestrictedIP,
			const double dAmt,
                        recordset_t* myRec);

int GetBankPspForPromoCustomer( const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
                        const char* csCustomerGroup,
			const char* csIpRegionCode,
			const char* csCustId,
			const int   iRestrictedIP,
                        const double dAmt,
                        recordset_t* myRec);

int GetMobileBankByMerchNCcyNGrp(const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
                        const char* csCustomerGroup,
                        const char* csUnionGroup,
                        const double dAmt,
			int iIsNewCust,
                        recordset_t* myRec);

int GetMobileBankDefault(const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
                        const double dAmt,
                        recordset_t* myRec);
/*
int GetMobileBankByMerchNCcyNGrp(const char* csMerchantId,
                        const char* csCcy,
                        const char* csCustomerGroup,
                        const double dAmt,
                        recordset_t* myRec);
int GetMobileBankDefault(const char* csMerchantId,
                        const char* csCcy,
                        const double dAmt,
                        recordset_t* myRec);
*/

int GetRemainCapForMobSegment(const char* csMerchantId,
			      const char* csGroup, 
			      const double dAmt, 
			      double *dRemain);


int GetBankPspByOtherMerch( const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
			const char* csIpRegionCode,
			const int   iRestrictedIP,
                        const double dAmt,
                        recordset_t* myRec);



int HaveDefineRestrictedIPRule(const char* csChannel,
                           const char* csMerchantId,
                           const char* csServiceCode,
                           const char* csCountry,
                           const char* csCcy,
                           char cCardType);


int FindPotentialPool(hash_t *hIn,
                      recordset_t* myRec);

int FindPoolDetail(hash_t *hIn,
                      hash_t *hOut);

int FindPoolPspDetail(hash_t *hIn,
                      recordset_t* myRec);

int MatchCriteria_Mode(const hash_t *hRec,
                        recordset_t* myRec);


int GetCustomerGroup_CardType(const char* csChannel,
                     const char* csMerchantId,
                     const char* csServiceCode,
                     const char* csCountry,
                     const char* csCcy,
                     char cCardType,
		     const double dAmt,
                     const char* csBankCode,
                     hash_t * hTxn);

int GetPromoteCustomerGroup_CardType(const char* csChannel,
                     const char* csMerchantId,
                     const char* csServiceCode,
                     const char* csCountry,
                     const char* csCcy,
                     const char* csCustomerGroup,
                     char cCardType,
		     const double dAmt,
                     const char* csBankCode,
                     hash_t * hTxn);

int FindRuleWithoutVirtualPID(const char* csChannel,
                     const char* csMerchantId,
                     const char* csServiceCode,
                     const char* csCountry,
                     const char* csCcy,
                     const char* csCustomerGroup,
                     char cCardType,
		     const double dAmt,
                     hash_t * hTxn);

int GetNGBankDefault(const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
                        const char* csIpRegionCode,
                        char cDeviceType,
                        const double dAmt,
                        recordset_t* myRec);

int GetBankPspByOtherMerchDefault(const char* csOptionBank,
                        const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
			const char* csIpRegionCode,
			char cDeviceType,
                        const int   iRestrictedIP,
                        const double dAmt,
                        recordset_t* myRec);

int GetMobileBankByMerchNCcyNGrpNew(const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
                        const char* csCustomerGroup,
			const char* csIpRegionCode,
			const char* csCustId,
                        char cDeviceType,
			const int iSARIP,
		  	const int iRestrictedIP,
                        const double dAmt,
                        recordset_t* myRec);

int GetBankPspByMerchNCcyNGrpNew(const char* csOptionBank, 
			const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
                        const char* csCustomerGroup,
			const char* csIpRegionCode,
			const char* csCustId,
                        const int   iRestrictedIP,
                        const double dAmt,
                        recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
