#ifndef _EOD_OFFEXT_GLPOST_H
#define _EOD_OFFEXT_GLPOST_H
#include "common.h"

#define	IMPORT_MAX_FIELD		20
#define	IMPORT_FIELD_LEN		100

#define	IMPORT_MAX_KEY			100
#define	IMPORT_MAX_KEY_LEN		500

#define DETAIL_ITEM_SIZE		19

#define	IDX_TXN_TYPE			0
#define	IDX_COUNTRY_CODE		1
#define	IDX_TXN_DATE			2
#define	IDX_TXN_ID			3
#define	IDX_MERCHANT			4
#define	IDX_PSP				5
#define	IDX_TXN_AMT_CCY			6
#define	IDX_TXN_AMT			7
#define	IDX_TXN_FEE_CCY			8
#define	IDX_TXN_FEE			9
#define	IDX_NET_AMT_CCY			10
#define	IDX_NET_AMT			11
#define	IDX_MU_AMT_CCY			12
#define	IDX_MU_AMT			13
#define	IDX_PSP_AMT_CCY			14
#define	IDX_PSP_AMT			15
#define	IDX_TXN_STATUS			16
#define	IDX_MERCHANT_REF		17
#define	IDX_DTL_CHECKSUM		18

#define HASHKEY_IDX_SIZE		9
#define HASHKEY_IDX_TXN_TYPE 		0
#define HASHKEY_IDX_AMT_TYPE 		1	
#define HASHKEY_IDX_TXN_DATE 		2
#define HASHKEY_IDX_TXN_STATUS 		3
#define HASHKEY_IDX_COUNTRY_CODE 	4
#define HASHKEY_IDX_PARTY_TYPE		5
#define HASHKEY_IDX_PARTY_ID 		6
#define HASHKEY_IDX_AMT_CCY 		7
#define HASHKEY_IDX_CR_IND 		8
#define HASHKEY_IDX_TXN_CNT 		9

#define CRR_AMT_TYPE_NET_AMT            "NET_AMT"
#define CRR_AMT_TYPE_M_FEE              "M_FEE"
#define CRR_AMT_TYPE_TXN_AMT            "TXN_AMT"
#define CRR_AMT_TYPE_PSP_TEMP           "PSP_TEMP"
#define CRR_AMT_TYPE_D_TXN_AMT          "D_TXN_AMT"


#define DSP_TYPE	"DEPOSIT"
#define WTD_TYPE	"PAYOUT"
#define WTDG_TYPE	"PAYOUT_PSP"

#define MAX_TXN_TYPE_CNT 5
#define MAX_TXN_TYPE_LEN 20

#define DSP_APPROVE_STATUS	"A"
#define DSP_REJFECT_STATUS	"R"

#define OFFLINE_DATA_FOLDE	R	"offline_system"
#define OFFLINE_DATA_FILE_PREFIX	"offline"

#define OFFLINE_PRODUCT_CODE	"OFF"

#define OFFLINE_CHECKSUM_LEN	32

#define	OFFLINE_RMB_CCY		"RMB"

#define OFFLINE_COUNTRY_CODE	"CN"

#define OFFLINE_MY_TOKEN        '"'

#define CRR_OFF_DEPOSIT_TXN_CODE      "ODP"
#define CRR_OFF_PAYOUT_TXN_CODE       "OPO"
#define CRR_OFF_PAYOUT_REJ_TXN_CODE   "OPV"
#define CRR_OFF_PAYOUT_GEN_TXN_CODE       "OPG"
#define CRR_OFF_PAYOUT_GEN_REJ_TXN_CODE   "OGV"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#endif
