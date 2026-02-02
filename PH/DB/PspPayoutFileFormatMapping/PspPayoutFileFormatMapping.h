#ifndef _OL_PSP_PAYOUT_FILE_FORMAT_MAPPING_H_
#define _OL_PSP_PAYOUT_FILE_FORMAT_MAPPING_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Replicate(const hash_t *hRec);
int GetPspPayoutFileFormat(const char* csPspId, char* csFormatCode);

#ifdef __cplusplus
}
#endif

#endif
