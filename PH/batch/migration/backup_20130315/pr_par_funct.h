#ifndef	_PR_PAR_FUNCT_H_
#define	_PR_PAR_FUNCT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PAR_PD_SEQUENCE_TYPE_NAME       50
#define PAR_PD_CATEGORY                 20

#define PAR_PD_MERCH_ACCOUNT_NMB_LEN        50
#define PAR_PD_USERNAME_LEN                 100
#define PAR_PD_API_MERCH_ID_LEN             30
#define PAR_PD_ACK_URL_LEN                  200

#define PAR_PD_PSP_TYPE_CD      	50
#define PAR_ORDER_ID_LEN		50

//////////Service//////////
int Service_FindCountryByService(const unsigned char* ServiceCode, char* TxnCountry);


//////////ServicePayMethod//////////
int ServicePayMethod_FindPayMethod(const char* csServiceCode,
                  recordset_t* myRec);


//////////ParDefMisc//////////
int ParDefMisc_GetValue(const char *csCode, char *csValue);



//////////ParCategory//////////
int ParCategory_GetCategory(const char* csSeqTypeName,
                hash_t * hRec);

//////////ParMerchProfile//////////
int ParMerchProfile_GetMerchant(const char* csMerchAccNmb,
                recordset_t* myRec);

//////////ParTxnData///////////////
int ParTxnData_ChkExist(const char *csVNCRefNum);
int UpdateProcessResult(hash_t *hMyHash, const char *csStatus);
int UpdateTxnDataStatus(const hash_t *hRls);

int UpdateHeaderVNCRef(const hash_t *hRls);
int UpdateApprovalTimestamp(const hash_t *hRls);

int GetTxnHeaderByVNCRefNum(const char*csVNCRefNum, hash_t *hRec);
int GetOrgTxnID(hash_t * hMyHash, hash_t *hTxnHeader);

//////////ParTxnData///////////////
int ParPspClientMap_GetPspID(hash_t *hRec);
int ParPspClientMap_GetBankCode(hash_t *hRec);


//////////AdjustmentType///////////////
int     GetAdjustmentTypeRec(const char cPartyType,
                                const char *csCode ,
                                recordset_t *myRec);



//////// Payout ////////////////////
int	AddParPayoutUploadHD(const hash_t *hRls);
int	PayoutUpload_Header_ChkExist(hash_t *hRls); 
int	PayoutUpload_Detail_ChkExist(hash_t *hRls);

int 	GetPayoutDetailByVncRefNum(const char *csVNCRefNum,recordset_t* myRec);
int	GetPayoutDetailByAuxVncRefNum(const char *csVNCRefNum,recordset_t* myRec);
int	format_data(hash_t *hMyHash, hash_t *hTxnHeader, hash_t *hContext, hash_t *hRequest);
int     PayoutAddTxnLog(const hash_t *hContext, const hash_t* hRequest);
int	handle_payout_balance(hash_t *hMyHash);
int     prpar_UpdateTxnLog(const hash_t *hContext,
                const hash_t* hRequest,
                const hash_t* hResponse);
int	add_txn_element(hash_t *hMyHash);



/////////////////Payout Void////////////////
int UpdateVoidPOTxnStatus(const hash_t *hRls);
int par_GetPspDetail(const char* csPspId,
                hash_t* hRec);



int     AddTxnSeqMap(const hash_t *hRls);
int     TxnSeqMap_Exists(const char *csOrderId);

int	AddPORevTxnSeqMap(const hash_t *hRls);
int     GetPORevTxnSeqByVNCRefNum(const char *csVNCRefNum, char *csVOATxnSeq);



#ifdef __cplusplus
}
#endif

#endif

