#ifndef _TEST_ZALE_H_
#define _TEST_ZALE_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C"
{
	#endif

	int Add(const hash_t * hRls);
	int IsValid();
	int GetByTxnCode(const char * csTxnCode, hash_t * hRec);
	int GetByGroup(const char cGroup, recordset_t * myRec);
	int Update(const hash_t * hRls);
	int UpdateReturn(const hash_t * hIn, hash_t * hOut);
	int UpdateReturnCursor(const hash_t * hIn, hash_t * hOut);

	#ifdef __cplusplus
}

#endif
#endif
