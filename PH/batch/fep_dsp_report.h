#ifndef _FEP_DSP_REPORT_H
#define _FEP_DSP_REPORT_H
#include "common.h"


#define	IMPORT_MAX_FIELD		14
#define	IMPORT_FIELD_LEN		50

/* from original psp provided file */
/*
#define	IDX_TXN_SEQ			0
#define	IDX_TXN_AMOUNT			1
#define	IDX_CUS_NUM			3	
#define	IDX_FUNDIN_DATE			4
#define	IDX_TXN_STATUS			5
#define IDX_TID				6
*/


#define	IDX_TXN_SEQ			1
#define	IDX_TXN_AMOUNT			3
#define	IDX_FUNDIN_DATE			6
#define	IDX_TXN_STATUS			2
#define IDX_TID				0

#define IDX_YEAR                        0
#define IDX_MONTH                       1
#define IDX_DAY                         2


#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#endif
