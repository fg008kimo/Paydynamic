#ifndef _RULE_SERVICE_RELEASE_PERIOD_H_
#define _RULE_SERVICE_RELEASE_PERIOD_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindPayoutPeriod(const char* csService,
			int	*iPeriod);

int FindSettlementPeriod(const char* csService,
			int	*iPeriod);

int FindReleasePeriod(const char* csService,
	  	      const char* csReleaseType,
		      int   *iPeriod);

#ifdef __cplusplus
}
#endif

#endif
