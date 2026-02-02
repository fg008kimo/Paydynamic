#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tplutil.h"
#include "common.h"
#include "utilitys.h"

char	cDebug;

int set_tpl_dyn_int(hash_t *hContext,int iDynCnt,const char *csTagName,const char *csType,const char *csVSec,int csValue) {
	
	char csTag[PD_TMP_BUF_LEN+1];

DEBUGLOG(("SetTplDynCString: >>iDynCnt=[%d]\n",iDynCnt));
	sprintf(csTag,"%d_tagname",iDynCnt);
	PutField_CString(hContext,csTag,csTagName);
DEBUGLOG(("SetTplDynCString: TagName = [%s]\n",csTagName));
	sprintf(csTag,"%d_type",iDynCnt);
	PutField_CString(hContext,csTag,csType);
DEBUGLOG(("SetTplDynCString: Type = [%s]\n",csType));
	sprintf(csTag,"%d_vsec",iDynCnt);
	PutField_CString(hContext,csTag,csVSec);
DEBUGLOG(("SetTplDynCString: SECTION = [%s]\n",csVSec));
	sprintf(csTag,"%d_value",iDynCnt);
	PutField_Int(hContext,csTag,csValue);
DEBUGLOG(("SetTplDynCString: Value = [%d]\n",csValue));

	return ++iDynCnt;
}

int set_tpl_dyn_double(hash_t *hContext,int iDynCnt,const char *csTagName,const char *csType,const char *csVSec,double csValue) {
	
	char csTag[PD_TMP_BUF_LEN+1];

DEBUGLOG(("SetTplDynCString: >>iDynCnt=[%d]\n",iDynCnt));
	sprintf(csTag,"%d_tagname",iDynCnt);
	PutField_CString(hContext,csTag,csTagName);
DEBUGLOG(("SetTplDynCString: TagName = [%s]\n",csTagName));
	sprintf(csTag,"%d_type",iDynCnt);
	PutField_CString(hContext,csTag,csType);
DEBUGLOG(("SetTplDynCString: Type = [%s]\n",csType));
	sprintf(csTag,"%d_vsec",iDynCnt);
	PutField_CString(hContext,csTag,csVSec);
DEBUGLOG(("SetTplDynCString: SECTION = [%s]\n",csVSec));
	sprintf(csTag,"%d_value",iDynCnt);
	PutField_Double(hContext,csTag,csValue);
DEBUGLOG(("SetTplDynCString: Value = [%.f]\n",csValue));

	return ++iDynCnt;
}

int set_tpl_dyn_cstring(hash_t *hContext,int iDynCnt,const char *csTagName,const char *csType,const char *csVSec,const char *csValue) {

	char csTag[PD_TMP_BUF_LEN+1];

DEBUGLOG(("SetTplDynCString: >>iDynCnt=[%d]\n",iDynCnt));
	sprintf(csTag,"%d_tagname",iDynCnt);
DEBUGLOG(("TagName = [%s]\n",csTagName));
	PutField_CString(hContext,csTag,csTagName);
DEBUGLOG(("SetTplDynCString: TagName = [%s]\n",csTagName));
	sprintf(csTag,"%d_type",iDynCnt);
	PutField_CString(hContext,csTag,csType);
DEBUGLOG(("SetTplDynCString: Type = [%s]\n",csType));
	sprintf(csTag,"%d_vsec",iDynCnt);
	PutField_CString(hContext,csTag,csVSec);
DEBUGLOG(("SetTplDynCString: SECTION = [%s]\n",csVSec));
	sprintf(csTag,"%d_value",iDynCnt);
	PutField_CString(hContext,csTag,csValue);
DEBUGLOG(("SetTplDynCString: Value = [%s]\n",csValue));

	return ++iDynCnt;
}

