#ifndef _PAR_DEPOSIT_HANDLER_H
#define _PAR_DEPOSIT_HANDLER_H
#include "common.h"

/*

#define	IMPORT_MAX_FIELD		50
#define	IMPORT_FIELD_LEN		400


#define PAR_TXN_MERCH_NMB_LEN		50
#define PAR_TXN_NMB_LEN			16

#define	PAR_TXN_TYPE_LEN		50
#define PAR_TXN_STATUS_LEN		50
#define PAR_TXN_STATUS_GRP_LEN		50
#define PAR_PSP_TYPE_CODE_LEN		50
#define PAR_ORDER_ID_LEN		50
#define PAR_GATE_ID_LEN			50
#define PAR_CLIENT_IP_LEN		15

#define PAR_POST_DATE_CODE		"PAR_POST_DATE"

#define PAR_CAT_DEPOSIT			"DEPOSIT"
#define PAR_CAT_SETTLEMENT		"SETTLEMENT"
#define PAR_CAT_ADJUSTEMENT		"ADJUSTMENT"
#define PAR_CAT_PAYOUT			"PAYOUT"
#define PAR_CAT_PAYOUT_REVERSAL		"PAYOUT REVERSE"
*/



#ifdef __cplusplus
extern "C" {
#endif

int deposit_handler(hash_t *hMyHash);
//int settlement_handler(hash_t *hMyHash);
//int adjustment_handler(hash_t *hMyHash);
//int payout_handler(hash_t *hMyHash);
//int payout_reversal_handler(hash_t *hMyHash);
/*int format_data(hash_t *hMyHash, hash_t *hTxnHeader, hash_t *hContext, hash_t *hRequest);
int handle_deposit_balance(hash_t *hMyHash);*/



#ifdef __cplusplus
}
#endif


#endif
