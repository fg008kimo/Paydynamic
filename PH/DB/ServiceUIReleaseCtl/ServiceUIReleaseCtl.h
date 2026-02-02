#ifndef _SERVICE_UI_RELEASE_H_
#define _SERVICE_UI_RELEASE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetCtlTag(hash_t* hTag);


int MatchCtlValue(const char* csTag,
                  const char* csInputValue);
#ifdef __cplusplus
}
#endif

#endif
