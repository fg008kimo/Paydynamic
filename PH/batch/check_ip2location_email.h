#ifndef _CHECK_IP2LOCATION_EMAIL_H_
#define _CHECK_IP2LOCATION_EMAIL_H_
#include "common.h"


#define PD_EML_FUNCT_DL_IP2LOC_SUCC	"DL_IP2LOC_SUCC"
#define PD_EML_FUNCT_DL_IP2LOC_FAIL	"DL_IP2LOC_FAIL"
#define PD_EML_FUNCT_UPD_IP2LOCATION	"UPD_IP2LOCATION"

#define PD_ALERT_DATETIME_FORMAT        "%d-%b-%Y %H:%M:%S"

#define PD_RET_STATUS_FAILURE           "Failure"
#define PD_RET_STATUS_SUCCESS           "Success"

#define	PD_RET_CODE_SUCCESS			0
#define	PD_RET_CODE_DOWNLOAD_FILE_FAILURE	1
#define	PD_RET_CODE_ZIP_FILE_NOT_FOUND		2
#define	PD_RET_CODE_UNZIP_FILE_FAILURE		3
#define	PD_RET_CODE_BIN_FILE_NOT_FOUND		4
#define	PD_RET_CODE_BIN_FILE_NOT_SYNC		5

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#endif
