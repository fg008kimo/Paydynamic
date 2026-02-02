#ifndef _OL_AUTO_UPLOAD_STMT_SETTING_H_
#define _OL_AUTO_UPLOAD_STMT_SETTING_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetDetailByPathName(const char* csProviderPath,
			  const char* csNaturePath,  
			  char* csProviderName, 
			  char* csProviderId,
			  char* csNature);

int GetDetailByNaturePath(const char* csNaturePath,
                          recordset_t* myRec);

int GetProviderJob(const char* csServerId, 
		   const char* csNature, 
		   recordset_t* myRec);

int CheckProviderJobExists(const char* csServerId, 
			   const char* csNature,
			   char* csNaturePath);


int UpdateDisabledByProviderId(const hash_t *hRls);

int CheckDupProvPathname(const char *csProvId,
			const char *csProvPathName);

int UpdateProvPathnameByProvId(const hash_t *hRec);

int Add(const hash_t *hRec);

int GetByProvId(const char* csProvId,
		const char* csNature, hash_t* hRec);

	
#ifdef __cplusplus
}
#endif

#endif
