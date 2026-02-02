#ifndef _PAR_TXN_HANDLER_H
#define _PAR_TXN_HANDLER_H
#include "common.h"


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
#define PAR_TXN_NOTE_LEN                400
#define PAR_PSP_TXN_ID_LEN              30
#define PAR_PSP_TXN_DATE_LEN            14
#define PAR_FILE_NAME_LEN               50

#define PAR_POST_DATE_CODE		"PAR_POST_DATE"
#define PAR_CUTOFFF_DATE_CODE		"PAR_CUTOFF_DATE"

#define PAR_AUTO_RECON                  "AUTO_RECON"

#define PAR_CAT_DEPOSIT			"DEPOSIT"
#define PAR_CAT_SETTLEMENT		"SETTLEMENT"
#define PAR_CAT_ADJUSTEMENT		"ADJUSTMENT"
#define PAR_CAT_PAYOUT			"PAYOUT"
#define PAR_CAT_PAYOUT_REVERSAL		"PAYOUT REVERSE"
#define PAR_CAT_RESERVE                 "RESERVE"



#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#endif
