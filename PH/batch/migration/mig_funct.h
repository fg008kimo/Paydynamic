#ifndef	_MIG_FUNCT_H_
#define	_MIG_FUNCT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MIG_PD_SEQUENCE_TYPE_NAME       50
#define MIG_PD_CATEGORY                 20

#define MIG_PD_MERCH_ACCOUNT_NMB_LEN        50
#define MIG_PD_USERNAME_LEN                 100
#define MIG_PD_API_MERCH_ID_LEN             30
#define MIG_PD_ACK_URL_LEN                  200

#define MIG_PD_PSP_TYPE_CD      	50
#define MIG_ORDER_ID_LEN		50



//////////ParDefMisc//////////
int mf_DefMisc_GetValue(const char *csCode, char *csValue);

//////////ParCategory//////////
int mf_Category_GetCategory(const char* csSeqTypeName,
                hash_t * hRec);

//////////Service//////////
int mf_Service_FindCountryByService(const unsigned char* ServiceCode, char* TxnCountry);


//////////ServicePayMethod//////////
int mf_ServicePayMethod_FindPayMethod(const char* csServiceCode,
                  recordset_t* myRec);


//////////Chk Period ////////////////////////
int     mf_ChkValidMigPeriod(const char *csMerchNmb, const char *csTxnDate);




//////////ParMerchProfile//////////
int mf_MerchProfile_GetMerchant(const char* csMerchAccNmb,
                recordset_t* myRec);

//////////ParTxnData///////////////
int mf_ParTxnData_ChkExist(const char *csVNCRefNum);
int mf_UpdateProcessResult(hash_t *hMyHash, const char *csStatus);
int mf_UpdateTxnDataStatus(const hash_t *hRls);

int mf_UpdateHeaderVNCRef(const hash_t *hRls);
int mf_UpdateApprovalTimestamp(const hash_t *hRls);

int mf_GetTxnHeaderByVNCRefNum(const char*csVNCRefNum, hash_t *hRec);
int mf_GetOrgTxnID(hash_t * hMyHash, hash_t *hTxnHeader);

//////////ParTxnData///////////////
int mf_ParPspClientMap_GetPspID(hash_t *hRec);
int mf_ParPspClientMap_GetBankCode(hash_t *hRec);


//////////AdjustmentType///////////////
int     mf_GetAdjustmentTypeRec(const char cPartyType,
                                const char *csCode ,
                                recordset_t *myRec);



//////// Payout ////////////////////
int 	mf_GetPayoutDetailByVncRefNum(const char *csVNCRefNum,recordset_t* myRec);
int	mf_handle_payout_balance(hash_t *hMyHash);
int	mf_format_data(hash_t *hMyHash, hash_t *hTxnHeader, hash_t *hContext, hash_t *hRequest);
int     mf_UpdateTxnLog(const hash_t *hContext,
                const hash_t* hRequest,
                const hash_t* hResponse);


int	AddParPayoutUploadHD(const hash_t *hRls);
int	PayoutUpload_Header_ChkExist(hash_t *hRls); 
int	PayoutUpload_Detail_ChkExist(hash_t *hRls);

int	GetPayoutDetailByAuxVncRefNum(const char *csVNCRefNum,recordset_t* myRec);
int     PayoutAddTxnLog(const hash_t *hContext, const hash_t* hRequest);
int	add_txn_element(hash_t *hMyHash);



/////////////////Payout Void////////////////
int UpdateVoidPOTxnStatus(const hash_t *hRls);
int par_GetPspDetail(const char* csPspId,
                hash_t* hRec);



int     AddTxnSeqMap(const hash_t *hRls);
int     TxnSeqMap_Exists(const char *csOrderId);

int	AddPORevTxnSeqMap(const hash_t *hRls);
int     GetPORevTxnSeqByVNCRefNum(const char *csVNCRefNum, char *csVOATxnSeq);


///////////////MerchTxnInfo //////////////////
int mf_merchant_getmerchanttxninfo(hash_t *hContext, const hash_t *hRequest);

int mf_MerchDetail_GetMerchant(const char* csMerchantID, recordset_t* myRec);

int mf_Clients_GetClients(const char* csClientId, hash_t* hRec);

int mf_MerchBalAcct_CheckMerchantBalAcct(const char* csMerchantID,
                const char* csCountry,
                const char* csCcy,
                const char* csServiceCode,
                hash_t *hRec);

int mf_MerchantPayMethod_FindMerchantPayMethod(const char* csMerchantId,
                        const char* csPayMethod);

int mf_get_merch_txn_info(hash_t *hMyHash);

int mf_GetPSPRelatedInfo(hash_t *hMyHash);


////////////////// Settlement /////////////
int	mf_MerchantSettlementDetail_Add(const hash_t* hRls);
int	mf_MerchantSettlementDetail_Update(const hash_t* hRls);


#ifdef __cplusplus
}
#endif

#endif

