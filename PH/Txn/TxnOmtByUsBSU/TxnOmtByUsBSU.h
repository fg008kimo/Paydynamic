#ifndef _TXNOMTBYUSBSU_H_
#define _TXNOMTBYUSBSU_H_
#include "myrecordset.h"
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int Authorize(hash_t* hContext, hash_t* hRequest, hash_t* hResponse);

void _RecordSet_Destroy(recordset_t *r) {
	hash_t *h = RecordSet_GetFirst(r);
	while(h != NULL) {
		hash_destroy(h);
		FREE_ME(h);
		h = RecordSet_GetNext(r);
	}
	recordset_destroy(r);
}

#ifdef __cplusplus
}
#endif

#endif
