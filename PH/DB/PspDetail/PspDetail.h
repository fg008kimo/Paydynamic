#ifndef _PSP_DETAIL_H_
#define _PSP_DETAIL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Replicate(const hash_t *hPspDetail);

int Add(const hash_t *);

int Delete(const unsigned char* psp_id,const unsigned char* client_id);

int GetPspDetail(const char* csPspId,
               hash_t* hRec);

int Update(const hash_t *hRls);

int GetPspDetailByType(const char cType,
                       recordset_t *myRec);

int GetDepositPspList(const char *csTxnCountry,
			const char *csBank,
                       recordset_t *myRec);

int GetPspPayoutSplitAmt(const char* csPspId,
                hash_t* hRec);

int UpdateRemark2NULL(const hash_t *hRls);

int GetPspDetailByChannelMerchId(const char* csPspChannelCode,
                const char* csPspMerchantId,
                hash_t* hRec);

int UpdateNBXAPIDGroup2NULL(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
