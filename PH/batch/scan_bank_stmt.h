#ifndef _SCAN_BANK_STMT_H
#define _SCAN_BANK_STMT_H
#include "common.h"


#define IMPORT_MAX_FILE_LEN		100
#define IMPORT_FIELD_LEN          	50
#define IMPORT_MAX_FIELD           	4

#define	MAX_NUM_OF_ACCT_TYPE		3
#define IDX_ACCT_TYPE_DEPOSIT		0
#define IDX_ACCT_TYPE_PAYOUT		1
#define IDX_ACCT_TYPE_INTERMEDIATE	2

#define IDX_BANK_INIT                   0
#define IDX_BANK_ACCT_INIT            	1
#define IDX_BANK_ACCT_NUM               2
#define IDX_TXN_DATE           	 	3

#define PD_RAW_DELIMITOR                "_"
#define PD_OUT_DELIMITOR                "_"
#define PD_EXT_DELIMITOR                "."
#define PD_SQL_DELIMITOR                ","
#define PD_BANK_DELIMITOR              	"_"

#define PD_BANK_NAME_ALL_BANK        	"ALL"

#define PD_CHAR         		0x0D


#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#endif
