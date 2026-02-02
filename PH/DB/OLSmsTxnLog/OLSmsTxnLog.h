#ifndef _OLSMSTXNLOG_H_
#define _OLSMSTXNLOG_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t* hTxn, const hash_t* hText);

int CheckDuplicate(const char* csDedupTimeRange,
			const char* csSender,
			const char* csSmsText);

#ifdef __cplusplus
}
#endif

#endif
