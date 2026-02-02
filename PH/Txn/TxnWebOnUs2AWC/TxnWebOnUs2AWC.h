#ifndef _TXNWEBONUS2AWC_H_
#define _TXNWEBONUS2AWC_H_
#include "myhash.h"
#define	PD_OK_STATUS	"OK"
#define PD_FAIL_STATUS	"FAIL"

#define PD_TXN_SEQ_MISMATCH	"txn_seq_mismatch"
#define PD_TXN_AMT_MISMATCH	"txn_amt_mismatch"
#define PD_SIGN_MISMATCH	"sign_mismatch"
#define PD_MISS_RETURN_CODE	"miss_return_code"
#define PD_MISS_MID		"miss_mid"
#define PD_MISS_TXN_SEQ		"miss_txn_seq"
#define PD_MISS_TXN_AMT		"miss_txn_amt"
#define PD_MISS_CODE_URL	"miss_code_url"
#define PD_MISS_SIGNATURE	"miss_signature"
#define PD_PSP_RETURN_FAIL	"psp_return_fail"
#define PD_GW_TIMEOUT		"gw_timeout"
#define PD_INVALID_FIELD	"invalid_field"

#ifdef __cplusplus
extern "C" {
#endif
int   Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse);
#ifdef __cplusplus
}
#endif

#endif
