/*
PDProTech (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/12/9              [MSN]
Modify Function					   2014/12/16		  [WWK]
Add AssignZeroAmt				   2015/06/12		  [MSN]
Reduce log					   2021/04/30		  [MSN]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "dbutility.h"
#include "BOOLTxnEngineSpc.h"
#include "myrecordset.h"
#include "myhash.h"
#include "math.h"
#include <time.h>

static char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);


void BOOLTxnEngineSpc(char cdebug)
{
	cDebug = cdebug;
}


int	RunSpecialAction(const int iAction, hash_t* hTxn);
int	GetBaidAmt(hash_t* hTxn);
int	GetPspAmt(hash_t* hTxn);
int	GetDiffAmt(hash_t* hTxn);
int	OverrideTagValue(hash_t* hTxn);
int	CompareString(const char* csValue1, const char* csValue2, const char* csOperator);
int	CompareInt(const int iValue1, const int iValue2, const char* csOperator);
int	CompareDouble(const double dValue1, const double dValue2, const char* csOperator);
int     AssignZeroAmt(hash_t* hTxn);


int	RunSpecialAction(const int iAction, hash_t* hTxn)
{
	int	iRet = PD_OK;

	int	iTmp;
	char*	csTmp;
	char*	csTmpType;

	char*	csType;
	char*	csTag1;
	char*	csTag2;
	char*	csOperator;
	//char*	csFunct = NULL;

	int	iValue1;
	int	iValue2;
	char*	csValue1;
	char*	csValue2;
	double	dValue1;
	double	dValue2;
	int	iCnt = 0;
	

	hash_t	*hAct;
	hAct = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hAct,0);

	hash_t          *hRec;
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

DEBUGLOG(("RunSpecialAction:: [%d]\n",iAction));
	PutField_Int(hAct,"spc_action_id",iAction);

	DBObjPtr = CreateObj(DBPtr,"DBOLTxnEngineSpcActionMap","GetSpcAction");
	if ((*DBObjPtr)(hAct,rRecordSet) == PD_OK) {
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			if (GetField_CString(hRec,"spc_action_desc",&csTmp))
DEBUGLOG(("####[%s]####\n",csTmp));
			//if(iCnt==0){
				//get default return tag & value and put in hTxn first
				if (GetField_CString(hRec, "def_returned_tag", &csTmp) &&
						GetField_Int(hRec, "def_returned_value", &iTmp))
				{
					PutField_Int(hTxn, csTmp, iTmp);
DEBUGLOG(("Default return [%s] = [%d]\n",csTmp,iTmp));
				} else {
					iRet = INT_ERR;
DEBUGLOG(("default_tag OR def_returned_value NOT FOUND!\n"));
ERRLOG("BOOLTxnEngineSpc RunSpecialAction default_tag OR def_returned_value NOT FOUND!\n");
					break;
				}
			//}

			if (GetField_CString(hRec,"check_type",&csType))
			{
DEBUGLOG(("check_type = [%s]\n",csType));
			} else {
				iRet = INT_ERR;
DEBUGLOG(("check_type NOT FOUND!\n"));
ERRLOG("BOOLTxnEngineSpc RunSpecialAction check_type NOT FOUND!\n");
				break;
			}

			if (GetField_CString(hRec,"compare_operator",&csOperator))
			{
DEBUGLOG(("operator = [%s]\n",csOperator));
			}
/*
 *			else {  //not the mandatory field
 *				iRet = INT_ERR;
 * DEBUGLOG(("RunSpecialAction compare_operator NOT FOUND!\n"));
 * ERRLOG("BOOLTxnEngineSpc RunSpecialAction compare_operator NOT FOUND!\n");
 * 			}
*/

			//reset iTmp use as return check
			iTmp = PD_FALSE;

			if (GetField_CString(hRec,"p2_check_tag",&csTmp))
				PutField_CString(hTxn,"p2_check_tag",csTmp);

			//get check_tag1, check_tag2 and expected_value
			//if check_tag2 exist, compare check_tag1 and check_tag2
			if (GetField_CString(hRec, "p1_check_tag", &csTag1)) {
				PutField_CString(hTxn,"p1_check_tag",csTag1);

				if (GetField_CString(hRec, "p2_check_tag", &csTag2)) {
					if (strcmp(csType,PD_STRING_TYPE) == 0) {
						if (GetField_CString(hTxn,csTag1,&csValue1) &&
						    GetField_CString(hTxn,csTag2,&csValue2)) {
DEBUGLOG(("p1:[%s] = [%s], p2:[%s] = [%s]\n",csTag1,csValue1, csTag2,csValue2));

							iTmp = CompareString(csValue1,csValue2,csOperator);
						}
						else {
							iRet = INT_ERR;
DEBUGLOG(("p1:%s/ p2:%s NOT FOUND!\n",csTag1,csTag2));
						}

					} else if (strcmp(csType,PD_INT_TYPE) == 0) {
						if (GetField_Int(hTxn,csTag1,&iValue1) &&
						    GetField_Int(hTxn,csTag2,&iValue2)) {
DEBUGLOG(("p1:[%s] = [%d], p2:[%s] = [%d]\n",csTag1,iValue1, csTag2,iValue2));

							iTmp = CompareInt(iValue1,iValue2,csOperator);
						}
						else {
							iRet = INT_ERR;
DEBUGLOG(("p1:%s/ p2:%s NOT FOUND!\n",csTag1,csTag2));
						}

					} else if (strcmp(csType,PD_DOUBLE_TYPE) == 0) {
						if (GetField_Double(hTxn,csTag1,&dValue1) &&
						    GetField_Double(hTxn,csTag2,&dValue2)) {
DEBUGLOG(("p1:[%s] = [%lf], p2:[%s] = [%lf]\n",csTag1,dValue1, csTag2,dValue2));

							iTmp = CompareDouble(dValue1,dValue2,csOperator);
						}
						else {
							iRet = INT_ERR;
DEBUGLOG(("p1:%s/ p2:%s NOT FOUND!\n",csTag1,csTag2));
						}
					}
				} else if (GetField_CString(hRec,"expected_value",&csValue2)) {
					PutField_CString(hTxn,"expected_value",csValue2);
					if (strcmp(csType,PD_STRING_TYPE) == 0) {
						if (GetField_CString(hTxn,csTag1,&csValue1)) {
DEBUGLOG(("p1:[%s] = [%s], expected_value = [%s]\n",csTag1,csValue1, csValue2));

							iTmp = CompareString(csValue1,csValue2,csOperator);

						} else {
							iRet = INT_ERR;
DEBUGLOG(("p1:%s NOT FOUND!\n",csTag1));
						}

					} else if (strcmp(csType,PD_INT_TYPE) == 0) {
						iValue2 = atoi(csValue2);
						if (GetField_Int(hTxn,csTag1,&iValue1)) {
DEBUGLOG(("p1:[%s] = [%d], expected_value = [%d]\n",csTag1,iValue1, iValue2));

							iTmp = CompareInt(iValue1,iValue2,csOperator);

						} else {
							iRet = INT_ERR;
DEBUGLOG(("p1:%s NOT FOUND!\n",csTag1));
						}

					} else if (strcmp(csType,PD_DOUBLE_TYPE) == 0) {
						dValue2 = atof(csValue2);
						if (GetField_Double(hTxn,csTag1,&dValue1)) {
DEBUGLOG(("p1:[%s] = [%lf], expected_value = [%lf]\n",csTag1,dValue1, dValue2));

							iTmp = CompareDouble(dValue1,dValue2,csOperator);

						} else {
							iRet = INT_ERR;
DEBUGLOG(("p1:%s NOT FOUND!\n",csTag1));
						}

					}
				}
				else{
					iTmp = PD_TRUE;
DEBUGLOG(("p1_check_tag FOUND but no p2_check_tag and no expected_value\n"));
				}
			}
			else{
DEBUGLOG(("p1_check_tag NOT FOUND\n"));
			}

			//if the compare result is TRUE, put the return value to the return tag in hTxn or call the return function
			if (iTmp == PD_TRUE)
			{
				if (GetField_CString(hRec,"returned_tag",&csTmp)){
					PutField_CString(hTxn,"returned_tag",csTmp);
					if (GetField_Int(hRec,"returned_value",&iTmp)) {
						//PutField_Int(hTxn,"returned_value",iTmp);
						PutField_Int(hTxn,csTmp,iTmp);
DEBUGLOG(("return [%s] = [%d]\n",csTmp, iTmp));
					} 
					else if (GetField_CString(hRec,"returned_funct",&csTmp) &&
						 GetField_CString(hRec,"returned_type",&csTmpType)){
DEBUGLOG(("return function [%s] type [%s]\n",csTmp, csTmpType));
						PutField_CString(hTxn,"returned_type",csTmpType);
						BOObjPtr = CreateObj(TxnPtr,"BOOLTxnEngineSpc",csTmp);

						iRet = (unsigned long)(*BOObjPtr)(hTxn);
					}
				}
			}
			//else, break the loop when terminate_when_error=TRUE or do nothing when terminate_when_error=FALSE
			else //if (iTmp == PD_FALSE)
			{
				if (GetField_Int(hRec,"terminate_when_error",&iTmp)) {
					if (iTmp == PD_TRUE) {
DEBUGLOG(("terminate_when_error = [%d], break!\n",iTmp));
						break;
					}
				}
			}

			if(iRet!=PD_OK){
				break;
			}

			iCnt ++;
			hRec = RecordSet_GetNext(rRecordSet);
		}
	}

	FREE_ME(hAct);
	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
DEBUGLOG(("RunSpecialAction() exit iRet = [%d]\n", iRet));
	return iRet;
}



int	GetBaidAmt(hash_t* hTxn)
{
	int iRet = PD_OK;
	char	*csTag;
	double	dAmt = 0.0;

	if(GetField_Double(hTxn,"baid_txn_amt",&dAmt) &&
	   GetField_CString(hTxn,"returned_tag",&csTag)){
DEBUGLOG(("GetBaidAmt [%s] = [%lf]\n",csTag,dAmt));
		PutField_Double(hTxn,csTag,dAmt);
	}
	else{
		iRet = PD_ERR;
DEBUGLOG(("GetBaidAmt NOT FOUND!!!!\n"));
	}

	return iRet;
}

int	GetPspAmt(hash_t* hTxn)
{
	int iRet = PD_OK;
	char	*csTag;
	double	dAmt = 0.0;

	if(GetField_Double(hTxn,"psp_txn_amt",&dAmt) &&
	   GetField_CString(hTxn,"returned_tag",&csTag)){
DEBUGLOG(("GetPspAmt [%s] = [%lf]\n",csTag,dAmt));
		PutField_Double(hTxn,csTag,dAmt);
	}
	else{
		iRet = PD_ERR;
DEBUGLOG(("GetPspAmt NOT FOUND!!!!\n"));
	}

	return iRet;
}

int	GetDiffAmt(hash_t* hTxn)
{
	int iRet = PD_OK;
	char	*csTag;
	char	*csIn1Tag;
	char	*csIn2Tag;
	double	d1Amt = 0.0;
	double	d2Amt = 0.0;
	double	dDiff = 0.0;

	if(GetField_CString(hTxn,"p1_check_tag",&csIn1Tag) &&
	   GetField_CString(hTxn,"p2_check_tag",&csIn2Tag)){

		if(GetField_Double(hTxn,csIn1Tag,&d1Amt) &&
		   GetField_Double(hTxn,csIn2Tag,&d2Amt) &&
		   GetField_CString(hTxn,"returned_tag",&csTag)){

DEBUGLOG(("GetDiffAmt [%s][%lf] and [%s][%lf]\n",csIn1Tag,d1Amt,csIn2Tag,d2Amt));

			if(d1Amt>d2Amt)
				dDiff = d1Amt - d2Amt;
			else
				dDiff = d2Amt - d1Amt;
			
			PutField_Double(hTxn,csTag,dDiff);
DEBUGLOG(("GetDiffAmt [%s] = [%lf]\n",csTag,dDiff));
		}
		else{
			iRet = PD_ERR;
		}
	}
	else{
		iRet = PD_ERR;
	}

DEBUGLOG(("GetDiffAmt exit iRet = [%d]\n",iRet));
	return iRet;
}


int	OverrideTagValue(hash_t* hTxn)
{
	int iRet = PD_OK;
	char	*csInTag;
	char	*csRetTag;
	char	*csType;
	char	*csTmp;
	int	iTmp = 0;
	double	dTmp = 0.0;

	if(GetField_CString(hTxn,"p1_check_tag",&csInTag) &&
	   GetField_CString(hTxn,"returned_tag",&csRetTag) &&
	   GetField_CString(hTxn,"returned_type",&csType)){

DEBUGLOG(("OverrideTagValue [%s]->[%s][%s]\n",csInTag,csRetTag,csType));
		if(!strcmp(csType,PD_STRING_TYPE)){
			if(GetField_CString(hTxn,csInTag,&csTmp)){
				PutField_CString(hTxn,csRetTag,csTmp);
DEBUGLOG(("OverrideTagValue [%s]->[%s][%s]\n",csInTag,csRetTag,csTmp));
			}
		}
		else if(!strcmp(csType,PD_INT_TYPE)){
			if(GetField_Int(hTxn,csInTag,&iTmp)){
				PutField_Int(hTxn,csRetTag,iTmp);
DEBUGLOG(("OverrideTagValue [%s]->[%s][%d]\n",csInTag,csRetTag,iTmp));
			}
		}
		else if(!strcmp(csType,PD_DOUBLE_TYPE)){
			if(GetField_Double(hTxn,csInTag,&dTmp)){
				PutField_Double(hTxn,csRetTag,dTmp);
DEBUGLOG(("OverrideTagValue [%s]->[%s][%lf]\n",csInTag,csRetTag,dTmp));
			}
		}
	}
	else{
		iRet = PD_ERR;
	}

DEBUGLOG(("OverrideTagValue exit iRet = [%d]\n",iRet));
	return iRet;
}

int	CompareString(const char* csValue1, const char* csValue2, const char* csOperator)
{
	int	iRet = PD_FALSE;
	int	iTmp = 0;

DEBUGLOG(("CompareString value1[%s] [%s] value2[%s]\n",csValue1,csOperator,csValue2));
	iTmp = strcmp(csValue1,csValue2);

	if (strcmp(csOperator,PD_OPERATOR_EQ1) == 0)
		if (iTmp == 0)
			iRet = PD_TRUE;
	if (strcmp(csOperator,PD_OPERATOR_NE1) == 0)
		if (iTmp != 0)
			iRet = PD_TRUE;
DEBUGLOG(("CompareString result = [%d]\n",iRet));
	return iRet;
}

int	CompareInt(const int iValue1, const int iValue2, const char* csOperator)
{
	int	iRet = PD_FALSE;

DEBUGLOG(("CompareInt value1[%d] [%s] value2[%d]\n",iValue1,csOperator,iValue2));
	if (strcmp(csOperator,PD_OPERATOR_EQ1) == 0)
		if (iValue1 == iValue2)
			iRet = PD_TRUE;
	if (strcmp(csOperator,PD_OPERATOR_NE1) == 0)
		if (iValue1 != iValue2)
			iRet = PD_TRUE;
	if (strcmp(csOperator,PD_OPERATOR_GE) == 0)
		if (iValue1 >= iValue2)
			iRet = PD_TRUE;
	if (strcmp(csOperator,PD_OPERATOR_GT) == 0)
		if (iValue1 > iValue2)
			iRet = PD_TRUE;
	if (strcmp(csOperator,PD_OPERATOR_LE) == 0)
		if (iValue1 <= iValue2)
			iRet = PD_TRUE;
	if (strcmp(csOperator,PD_OPERATOR_LT) == 0)
		if (iValue1 < iValue2)
			iRet = PD_TRUE;
DEBUGLOG(("CompareInt result = [%d]\n",iRet));
	return iRet;
}

int	CompareDouble(const double dValue1, const double dValue2, const char* csOperator)
{
	int	iRet = PD_FALSE;

DEBUGLOG(("CompareDouble value1=[%lf] [%s] value2=[%lf]\n",dValue1,csOperator,dValue2));
	if (strcmp(csOperator,PD_OPERATOR_EQ1) == 0)
		if (dValue1 == dValue2)
			iRet = PD_TRUE;
	if (strcmp(csOperator,PD_OPERATOR_NE1) == 0)
		if (dValue1 != dValue2)
			iRet = PD_TRUE;
	if (strcmp(csOperator,PD_OPERATOR_GE) == 0)
		if (dValue1 >= dValue2)
			iRet = PD_TRUE;
	if (strcmp(csOperator,PD_OPERATOR_GT) == 0)
		if (dValue1 > dValue2)
			iRet = PD_TRUE;
	if (strcmp(csOperator,PD_OPERATOR_LE) == 0)
		if (dValue1 <= dValue2)
			iRet = PD_TRUE;
	if (strcmp(csOperator,PD_OPERATOR_LT) == 0)
		if (dValue1 < dValue2)
			iRet = PD_TRUE;
DEBUGLOG(("CompareDouble result = [%d]\n",iRet));
	return iRet;
}

int	AssignZeroAmt(hash_t* hTxn)
{
	int iRet = PD_OK;
	char	*csTag;
	double	dAmt = 0.0;

	if(GetField_CString(hTxn,"returned_tag",&csTag)){
		PutField_Double(hTxn,csTag,dAmt);
DEBUGLOG(("AssignZeroAmt [%s][%lf]\n",csTag,dAmt));
	}
	else{
		iRet = PD_ERR;
	}

DEBUGLOG(("AssignZeroAmt exit iRet = [%d]\n",iRet));
	return iRet;
}

int AssignSysBankCode(hash_t* hTxn)
{
	int iRet = PD_OK;
	char *csTag;

	if (GetField_CString(hTxn, "returned_tag", &csTag)) {
		PutField_CString(hTxn, csTag, PD_SYS_BANK_CODE);
DEBUGLOG(("AssignSysBankCode [%s][%s]\n", csTag, PD_SYS_BANK_CODE));
	} else {
		iRet = PD_ERR;
	}

DEBUGLOG(("AssignSysBankCode exit iRet = [%d]\n", iRet));
	return iRet;
}

int AssignSysBankAcctNum(hash_t* hTxn)
{
	int iRet = PD_OK;
	char *csTag;
		
	if (GetField_CString(hTxn, "returned_tag", &csTag)) {
		PutField_CString(hTxn, csTag, PD_SYS_BANK_ACCT_NUM);
DEBUGLOG(("AssignSysBankAcctNum [%s][%s]\n", csTag, PD_SYS_BANK_ACCT_NUM));
	} else {
		iRet = PD_ERR;
	}

DEBUGLOG(("AssignSysBankAcctNum exit iRet = [%d]\n", iRet));
	return iRet;
}

