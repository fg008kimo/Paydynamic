#ifndef _SYSTEM_TPL_FMT_H_
#define _SYSTEM_TPL_FMT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetAlertTplSection(const char *csTplName,
			  const char *csSectionName,
			  recordset_t *myRec);


#ifdef __cplusplus
}
#endif

#endif
