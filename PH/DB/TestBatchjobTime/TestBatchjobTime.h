#ifndef _TEST_BATCHJOB_TIME_H_
#define _TEST_BATCHJOB_TIME_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C"
{
	#endif

	int GetJobByTime(const char * csMonth, const char * csDay, const char * csHour, const char * csMin, const char cDow, recordset_t * myRec);

	#ifdef __cplusplus
}

#endif
#endif
