#ifndef _OL_MERCHANT_UPLOAD_FILE_HEADER_H_
#define _OL_MERCHANT_UPLOAD_FILE_HEADER_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int     Add(const hash_t *hRls);
int Delete(const unsigned char* batch_id);
#ifdef __cplusplus
}
#endif

#endif
