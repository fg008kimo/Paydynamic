#ifndef _MIG_TXN_HANDLER_H
#define _MIG_TXN_HANDLER_H
#include "common.h"


#define	IMPORT_MAX_FIELD		50
#define	IMPORT_FIELD_LEN		400


#define MIG_TXN_MERCH_NMB_LEN		50
#define MIG_TXN_NMB_LEN			16

#define	MIG_TXN_TYPE_LEN		50
#define MIG_TXN_STATUS_LEN		50
#define MIG_TXN_STATUS_GRP_LEN		50
#define MIG_PSP_TYPE_CODE_LEN		50
#define MIG_ORDER_ID_LEN		50
#define MIG_GATE_ID_LEN			50
#define MIG_CLIENT_IP_LEN		100
#define MIG_TXN_NOTE_LEN                400
#define MIG_PSP_TXN_ID_LEN              30
#define MIG_PSP_TXN_DATE_LEN            14
#define MIG_FILE_NAME_LEN               50

/*
#define MIG_POST_DATE_CODE		"PAR_POST_DATE"
#define MIG_CUTOFFF_DATE_CODE		"PAR_CUTOFF_DATE"
*/

#define MIG_AUTO_RECON                  "AUTO_RECON"

#define MIG_CAT_DEPOSIT			"DEPOSIT"
#define MIG_CAT_SETTLEMENT		"SETTLEMENT"
#define MIG_CAT_ADJUSTEMENT		"ADJUSTMENT"
#define MIG_CAT_PAYOUT			"PAYOUT"
#define MIG_CAT_PAYOUT_REVERSAL		"PAYOUT REVERSE"
#define MIG_CAT_RESERVE                 "RESERVE"



#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#endif
