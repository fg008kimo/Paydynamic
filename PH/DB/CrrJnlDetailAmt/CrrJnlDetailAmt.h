#ifndef _CRR_JNL_DETAIL_AMT_H_
#define _CRR_JNL_DETAIL_AMT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(char* csJnlId,
		int iLineNo,
		char* csCcyId,
		double dFxRate,
		double dConvertAmt,
		int iDisabled,
		char* csCreateUser);

int Update(char* csJnlId,
		int iLineNo,
		char* csCcyId,
		double dFxRate,
		double dConvertAmt,
		int iDisabled,
		char* csUpdateUser);

int UpdateByLine(char* csJnlId,
					int iLineNo,
					int iDisabled,
					char* csUpdateUser);
		
int Delete(char* csJnlId,
		char* csUpdateUser);

#ifdef __cplusplus
}
#endif

#endif
