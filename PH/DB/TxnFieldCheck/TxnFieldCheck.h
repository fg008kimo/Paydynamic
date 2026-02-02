#ifndef _TXN_FIELD_CHECK_H_
#define _TXN_FIELD_CHECK_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindParam(const char* csChannelCode,
	      const char* csTxnCode,
	      recordset_t* myRec);

int FindParamByFieldTag(const char* csChannelCode,
                        const char* csTxnCode,
                        const char* csFieldTag,
                        hash_t* hRec);

int ChkDefReference(const char* csParam, const char* csRefTable, const char* csRefField);

#ifdef __cplusplus
}
#endif

#endif
