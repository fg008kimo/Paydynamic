#ifndef _SYSTEM_ALERT_H_
#define _SYSTEM_ALERT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetSystemAlertRec(const char *csHandler,
                      const char *csChannel,
		      const char *csScript,
		      const char *csParties,
                      recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
