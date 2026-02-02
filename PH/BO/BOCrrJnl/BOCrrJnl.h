#ifndef _BOCRRJNL_H_
#define _BOCRRJNL_H_
#include "myhash.h"

/*
#define	PD_PRODUCT_GATEWAY	"GTY"
#define	PD_PRODUCT_HYBRID	"HBD"
#define	PD_PRODUCT_OFFLINE	"OFF"
#define	PD_PRODUCT_MOBILE	"MBE"

#define PD_FXGL_GL			"91650"
#define	PD_GATEWAY_FXGL_SL	"FX002"
#define	PD_HYBRID_FXGL_SL	"FX001"
#define	PD_OFFLINE_FXGL_SL	"FX003"
#define	PD_MOBILE_FXGL_SL	"FX004"
*/


#ifdef __cplusplus
extern "C" {
#endif

int AddChangeLog(const char* csJnlNo, const char* csChangeAction, const char* csChangeUser);
int IsClosedMonth(const char* csTbYear, const char* csTbMonth, int* closed);
int Approve(hash_t* hJnlHdr);
int Add(hash_t *hRequest, recordset_t* rsJnlDtl);
int Update(hash_t *hJnlHdr, recordset_t* rsJnlDtl);
int Delete(hash_t* hJnlHdr);
int Release(hash_t* hJnlHdr);
int Build(hash_t* hJnlHdr);

int clearJournal(char* csType, recordset_t* rsJnl, const char* csPostUser);
int GetFXConvertAmt(char *csTxnDate, char *csFromCcy, char *csToCcy, double dReqAmt, double* dConvertAmt);
int postSingleJournal(char* csType, recordset_t* rsJnl, const char* csPostUser);
int postMultipleJournal(char* csType, recordset_t* rsJnl, const char* csPostUser);

#ifdef __cplusplus
}
#endif

#endif
