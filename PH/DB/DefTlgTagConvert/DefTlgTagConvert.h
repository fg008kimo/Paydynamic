#ifndef _DEF_TLG_TAG_CONVERT_H_
#define _DEF_TLG_TAG_CONVERT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetRandomTag(const unsigned char* csOrgTag,
		   unsigned char* csNewTag);

#ifdef __cplusplus
}
#endif

#endif
