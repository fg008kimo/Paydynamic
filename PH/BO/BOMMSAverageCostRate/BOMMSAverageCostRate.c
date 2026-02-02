/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/07/13              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "myrecordset.h"
#include "internal.h"
#include "BOMMSAverageCostRate.h"

char    cDebug;

OBJPTR(DB);
OBJPTR(BO);

int DebitEntityFx(const hash_t* hIn);
int CreditEntityFx(const hash_t* hIn);
int AdjustEntityFx(const hash_t* hIn);
int DebitACR(const hash_t* hIn);
int CreditACR(const hash_t* hIn);
int AdjustACR(const hash_t* hIn);

int VoidRemitEntityFx(const hash_t* hDtl, const hash_t* hHist);
int VoidRecvEntityFx(const hash_t* hDtl, const hash_t* hHist);
int VoidRemitACR(const hash_t* hDtl, const hash_t* hHist);
int VoidRecvACR(const hash_t* hDtl, const hash_t* hHist);

double CreditFormula(const double dNumeratorTop,
		     const double dNumeratorLow1, const double dDenominatorLow1,
		     const double dNumeratorLow2, const double dDenominatorLow2);

double DebitFormula(const double dNumeratorTop,
		    const double dNumeratorLow1, const double dDenominatorLow1,
		    const double dNumeratorLow2, const double dDenominatorLow2,
		    const double dNumeratorLow3, const double dDenominatorLow3);

void BOMMSAverageCostRate(char    cdebug)
{
        cDebug = cdebug;
}


int GetEntityFxBal(const hash_t* hIn, hash_t* hOut)
{
	int	iRet = PD_OK;
	char	*csTmp = NULL;
	int	iTmp = 0;
	double	dTmp = 0.0;

	if(GetField_CString(hIn,"entity_id",&csTmp)){
DEBUGLOG(("GetEntityFxBal() entity_id = [%s]\n",csTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetEntityFxBal() entity_id is missing\n"));
	}

	if(GetField_CString(hIn,"org_ccy",&csTmp)){
DEBUGLOG(("GetEntityFxBal() org_ccy = [%s]\n",csTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetEntityFxBal() org_ccy is missing\n"));
	}

	if(GetField_CString(hIn,"ccy",&csTmp)){
DEBUGLOG(("GetEntityFxBal() ccy = [%s]\n",csTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetEntityFxBal() ccy is missing\n"));
	}

	if(GetField_Int(hIn,"acr_ind",&iTmp)){
DEBUGLOG(("GetEntityFxBal() acr_ind = [%d]\n",iTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetEntityFxBal() acr_ind is missing\n"));
	}

	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBal","GetFxBal");
		iRet = (unsigned long)(*DBObjPtr)(hIn, hOut);
		if(iRet == PD_FOUND){
			iRet = PD_OK;
			if(GetField_Double(hOut,"bal",&dTmp)){
DEBUGLOG(("GetFxBal() Balance = [%lf]\n",dTmp));
			}
			else{
				iRet = INT_ERR;
DEBUGLOG(("GetFxBal() Balance not found!!!!\n"));
			}
			if(GetField_Double(hOut,"rate",&dTmp)){
DEBUGLOG(("GetFxBal() Rate = [%lf]\n",dTmp));
			}
			else{
				iRet = INT_ERR;
DEBUGLOG(("GetFxBal() Rate not found!!!!\n"));
			}
		}
		else if(iRet == PD_NOT_FOUND){
DEBUGLOG(("DBMmsEntityFXBal: GetFxBal() record not found\n"));
		}
		else{
DEBUGLOG(("DBMmsEntityFXBal: GetFxBal() Failed!!!\n"));
		}
	}

DEBUGLOG(("GetEntityFxBal() iRet = [%d]\n",iRet));
	return iRet;
}


int GetEntityFxBalForUpdate(const hash_t* hIn, hash_t* hOut)
{
	int	iRet = PD_OK;
	char	*csTmp = NULL;
	int	iTmp = 0;
	double	dTmp = 0.0;

	if(GetField_CString(hIn,"entity_id",&csTmp)){
DEBUGLOG(("GetEntityFxBalForUpdate() entity_id = [%s]\n",csTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetEntityFxBalForUpdate() entity_id is missing\n"));
	}

	if(GetField_CString(hIn,"org_ccy",&csTmp)){
DEBUGLOG(("GetEntityFxBalForUpdate() org_ccy = [%s]\n",csTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetEntityFxBalForUpdate() org_ccy is missing\n"));
	}

	if(GetField_CString(hIn,"ccy",&csTmp)){
DEBUGLOG(("GetEntityFxBalForUpdate() ccy = [%s]\n",csTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetEntityFxBalForUpdate() ccy is missing\n"));
	}

	if(GetField_Int(hIn,"acr_ind",&iTmp)){
DEBUGLOG(("GetEntityFxBalForUpdate() = [%d]\n",iTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetEntityFxBalForUpdate() acr_ind is missing\n"));
	}

	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBal","GetFxBalForUpdate");
		iRet = (unsigned long)(*DBObjPtr)(hIn, hOut);
		if(iRet == PD_FOUND){
			iRet = PD_OK;
			if(GetField_Double(hOut,"bal",&dTmp)){
DEBUGLOG(("GetFxBalForUpdate() Balance = [%lf]\n",dTmp));
			}
			else{
				iRet = INT_ERR;
DEBUGLOG(("GetFxBalForUpdate() Balance not found!!!!\n"));
			}
			if(GetField_Double(hOut,"rate",&dTmp)){
DEBUGLOG(("GetFxBalForUpdate() Rate = [%lf]\n",dTmp));
			}
			else{
				iRet = INT_ERR;
DEBUGLOG(("GetFxBalForUpdate() Rate not found!!!!\n"));
			}
		}
		else if(iRet == PD_NOT_FOUND){
DEBUGLOG(("DBMmsEntityFXBal: GetFxBalForUpdate() record not found\n"));
		}
		else{
DEBUGLOG(("DBMmsEntityFXBal: GetFxBalForUpdate() Failed!!!\n"));
		}
	}

DEBUGLOG(("GetEntityFxBalForUpdate() iRet = [%d]\n",iRet));
	return iRet;
}

int GetACRBal(const hash_t* hIn, hash_t* hOut)
{
	int	iRet = PD_OK;
	char	*csTmp = NULL;
	double	dTmp = 0.0;

	if(GetField_CString(hIn,"entity_id",&csTmp)){
DEBUGLOG(("GetACRBal() entity_id = [%s]\n",csTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetACRBal() entity_id is missing\n"));
	}

	if(GetField_CString(hIn,"org_ccy",&csTmp)){
DEBUGLOG(("GetACRBal() org_ccy = [%s]\n",csTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetACRBal() org_ccy is missing\n"));
	}

	if(GetField_CString(hIn,"ccy",&csTmp)){
DEBUGLOG(("GetACRBal() ccy = [%s]\n",csTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetACRBal() ccy is missing\n"));
	}

	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBal","GetOwnAcrBal");
		iRet = (unsigned long)(*DBObjPtr)(hIn, hOut);
		if(iRet == PD_FOUND){
			iRet = PD_OK;
			if(GetField_Double(hOut,"bal",&dTmp)){
DEBUGLOG(("GetOwnAcrBal() Balance = [%lf]\n",dTmp));
			}
			else{
				iRet = INT_ERR;
DEBUGLOG(("GetOwnAcrBal() Balance not found!!!!\n"));
			}
			if(GetField_Double(hOut,"rate",&dTmp)){
DEBUGLOG(("GetOwnAcrBal() Rate = [%lf]\n",dTmp));
			}
			else{
				iRet = INT_ERR;
DEBUGLOG(("GetOwnAcrBal() Rate not found!!!!\n"));
			}
			if(GetField_Double(hOut,"ratio",&dTmp)){
DEBUGLOG(("GetOwnAcrBal() Ratio = [%lf]\n",dTmp));
			}
		}
		else if(iRet == PD_NOT_FOUND){
DEBUGLOG(("DBMmsAcrBal: GetOwnAcrBal() record not found\n"));
		}
		else{
DEBUGLOG(("DBMmsAcrBal: GetOwnAcrBal() Failed!!!\n"));
		}
	}

DEBUGLOG(("GetACRBal() iRet = [%d]\n",iRet));
	return iRet;
}


int GetACRBalForUpdate(const hash_t* hIn, hash_t* hOut)
{
	int	iRet = PD_OK;
	char	*csTmp = NULL;
	double	dTmp = 0.0;

	if(GetField_CString(hIn,"entity_id",&csTmp)){
DEBUGLOG(("GetACRBalForUpdate() entity_id = [%s]\n",csTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetACRBalForUpdate() entity_id is missing\n"));
	}

	if(GetField_CString(hIn,"org_ccy",&csTmp)){
DEBUGLOG(("GetACRBalForUpdate() org_ccy = [%s]\n",csTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetACRBalForUpdate() org_ccy is missing\n"));
	}

	if(GetField_CString(hIn,"ccy",&csTmp)){
DEBUGLOG(("GetACRBalForUpdate() ccy = [%s]\n",csTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetACRBalForUpdate() ccy is missing\n"));
	}

	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBal","GetOwnAcrBalForUpdate");
		iRet = (unsigned long)(*DBObjPtr)(hIn, hOut);
		if(iRet == PD_FOUND){
			iRet = PD_OK;
			if(GetField_Double(hOut,"bal",&dTmp)){
DEBUGLOG(("GetOwnAcrBalForUpdate() Balance = [%lf]\n",dTmp));
			}
			else{
				iRet = INT_ERR;
DEBUGLOG(("GetOwnAcrBalForUpdate() Balance not found!!!!\n"));
			}
			if(GetField_Double(hOut,"rate",&dTmp)){
DEBUGLOG(("GetOwnAcrBalForUpdate() Rate = [%lf]\n",dTmp));
			}
			else{
				iRet = INT_ERR;
DEBUGLOG(("GetOwnAcrBalForUpdate() Rate not found!!!!\n"));
			}
			if(GetField_Double(hOut,"ratio",&dTmp)){
DEBUGLOG(("GetOwnAcrBalForUpdate() Ratio = [%lf]\n",dTmp));
			}
		}
		else if(iRet == PD_NOT_FOUND){
DEBUGLOG(("DBMmsAcrBal: GetOwnAcrBalForUpdate() record not found\n"));
		}
		else{
DEBUGLOG(("DBMmsAcrBal: GetOwnAcrBalForUpdate() Failed!!!\n"));
		}
	}

DEBUGLOG(("GetACRBalForUpdate() iRet = [%d]\n",iRet));
	return iRet;
}


int RecordAffectFXDT(const hash_t* hIn)
{
	int	iRet = PD_OK;
	char    *csTmp = NULL;
	char    *csEntityId = NULL;
	char    *csUser = NULL;
	char	*csFxId;
	char	cDirection = 'x';
	double	dTmp = 0.0;
	int	iTmp = 0;
	int	i = 0;
	int	iCnt = 0;
	char	csTag[PD_TAG_LEN+1];
	int	iUseDefUser = PD_FALSE;

	hash_t	*hData;
	hData = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hData,0);

DEBUGLOG(("RecordAffectFXDT:: ()\n"));

	//Transaction ID (Remit/Receive Txn)
	if(GetField_CString(hIn,"fx_id",&csFxId)){
DEBUGLOG(("RecordAffectFXDT() fx_id = [%s]\n",csFxId));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("RecordAffectFXDT() fx_id not found\n"));
ERRLOG("BOMMSAverageCostRate::RecordAffectFXDT() fx_id not found\n");
	}

	if(GetField_CString(hIn,"entity_id",&csEntityId)){
DEBUGLOG(("RecordAffectFXDT() entity_id = [%s]\n",csEntityId));
	}
	else{
		iRet = INT_MMS_ENTITY_ID_NOT_FOUND;
DEBUGLOG(("RecordAffectFXDT() entity_id not found\n"));
ERRLOG("BOMMSAverageCostRate::RecordAffectFXDT() entity_id not found\n");
	}

	if(GetField_Char(hIn,"direction",&cDirection)){
		//PD_FUNDS_OUT for Remit, PD_FUNDS_IN for Receive
DEBUGLOG(("RecordAffectFXDT() direction = [%c]\n",cDirection));
	}
	if(cDirection!=PD_FUNDS_OUT && cDirection!=PD_FUNDS_IN){
		iRet = INT_ERR;
DEBUGLOG(("RecordAffectFXDT() Invalid direction [%c]!!!!\n",cDirection));
ERRLOG("BOMMSAverageCostRate: RecordAffectFXDT() Invalid direction [%c]!!!!\n",cDirection);
	}

	if(GetField_CString(hIn,"add_user",&csUser)){
DEBUGLOG(("RecordAffectFXDT() add_user = [%s]\n",csUser));
	}
	else{
		iUseDefUser = PD_TRUE;
	}

	if(iRet==PD_OK){
//Record down funds in/out information
		iCnt = 0;
		GetField_Int(hIn,"fx_cnt",&iCnt);
DEBUGLOG(("RecordAffectFXDT() fx_cnt = [%d]\n",iCnt));

		if(iCnt > 0){
			PutField_CString(hData,"fx_id",csFxId);
			PutField_Char(hData,"direction",cDirection);
			PutField_CString(hData,"entity_id",csEntityId);
			PutField_Int(hData,"calculate_ind",PD_FALSE);
			if(!iUseDefUser) PutField_CString(hData,"create_user",csUser);
			else	PutField_CString(hData,"create_user",PD_UPDATE_USER);

			for(i=1; i<=iCnt; i++){
				sprintf(csTag,"fx.%d.occy",i);
				if(GetField_CString(hIn,csTag,&csTmp)){
					PutField_CString(hData,"org_ccy",csTmp);
				}
				sprintf(csTag,"fx.%d.ccy",i);
				if(GetField_CString(hIn,csTag,&csTmp)){
					PutField_CString(hData,"ccy",csTmp);
				}
				sprintf(csTag,"fx.%d.framt",i);
				if(GetField_Double(hIn,csTag,&dTmp)){
					PutField_Double(hData,"org_amount",dTmp);
				}
				sprintf(csTag,"fx.%d.amt",i);
				if(GetField_Double(hIn,csTag,&dTmp)){
					PutField_Double(hData,"amount",dTmp);
				}
				sprintf(csTag,"fx.%d.acr_ind",i);
				if(GetField_Int(hIn,csTag,&iTmp)){
					PutField_Int(hData,"acr_ind",iTmp);
				}

				PutField_Int(hData,"fx_seq",i);
				DBObjPtr = CreateObj(DBPtr,"DBMmsAffectFXDT","Add");
				if((unsigned long)(*DBObjPtr)(hData)!=PD_OK){
					iRet = INT_ERR;
DEBUGLOG(("RecordAffectFXDT() DBMmsAffectFXDT:Add Failed!!!\n"));
ERRLOG("BOMMSAverageCostRate: RecordAffectFXDT() DBMmsAffectFXDT:Add Failed!!!\n");
					break;
				}
			}
		}

	}

	FREE_ME(hData);

DEBUGLOG(("RecordAffectFXDT:: () Noraml Exit iRet = [%d]\n",iRet));
	return iRet;
}



int CalculateAffectFXDT(const hash_t* hIn)
{
	int	iRet = PD_OK;
	int	iTmp = 0;
	int	iCal = 0;
	int	iACR = 0;
	double	dTmp = 0.0;
	char	cDirection = 'x';
	char	*csTmp = NULL;
	char	*csFxId = NULL;
	char	*csOrgFxId = NULL;
	char	*csUser = NULL;
	char	*csEntityId = NULL;
	char	*csACRType;
	csACRType = (char*) malloc (128);

	hash_t	*hRec;
	hash_t	*hDetail;
	hDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hDetail,0);

	hash_t	*hUpd;
	hUpd = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hUpd,0);

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

DEBUGLOG(("CalculateAffectFXDT:: ()\n"));

	//Transaction ID (Remit/Receive Txn)
	if(GetField_CString(hIn,"fx_id",&csFxId)){
DEBUGLOG(("CalculateAffectFXDT() fx_id = [%s]\n",csFxId));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("CalculateAffectFXDT() fx_id not found\n"));
ERRLOG("BOMMSAverageCostRate::CalculateAffectFXDT() fx_id not found\n");
	}

	//For Calculating Receive Txn, org_fx_id is the Remit Transaction ID
	if(GetField_CString(hIn,"org_fx_id",&csOrgFxId)){
		PutField_CString(hDetail,"org_fx_id",csOrgFxId);
DEBUGLOG(("CalculateAffectFXDT() org_fx_id = [%s]\n",csOrgFxId));
	}

	//txn_code, for adjustment use only
	if(GetField_CString(hIn,"code",&csTmp)){
		PutField_CString(hDetail,"code",csTmp);
DEBUGLOG(("CalculateAffectFXDT() txn_code = [%s]\n",csTmp));
	}

	if(GetField_CString(hIn,"update_user",&csUser)){
		PutField_CString(hDetail,"update_user",csUser);
		PutField_CString(hUpd,"update_user",csUser);
DEBUGLOG(("CalculateAffectFXDT() update_user = [%s]\n",csUser));
	}

	if(iRet == PD_OK){
		//get fx detail by fx_id
		PutField_CString(hDetail,"fx_id",csFxId);
		PutField_CString(hUpd,"fx_id",csFxId);
		DBObjPtr = CreateObj(DBPtr,"DBMmsAffectFXDT","GetAffectFXDT");
		iRet = (unsigned long)(*DBObjPtr)(hDetail, rRecordSet);
		if(iRet == PD_OK){
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec && (iRet == PD_OK)) {
				if(GetField_Int(hRec,"fx_seq",&iTmp)){
					PutField_Int(hUpd,"fx_seq",iTmp);
					PutField_Int(hDetail,"fx_seq",iTmp);
DEBUGLOG(("CalculateAffectFXDT() >>> fx_seq = [%d] <<<\n",iTmp));
				}
				if(GetField_Char(hRec,"direction",&cDirection)){
					PutField_Char(hDetail,"direction",cDirection);
DEBUGLOG(("CalculateAffectFXDT() direction = [%c]\n",cDirection));
				}
				if(GetField_Int(hRec,"calculate_ind",&iCal)){
DEBUGLOG(("CalculateAffectFXDT() calculate_ind = [%d]\n",iCal));
				}
				if(iCal){
DEBUGLOG(("CalculateAffectFXDT() Already calculated. Skip...\n"));
					hRec = RecordSet_GetNext(rRecordSet);
					continue;
				}
				if(GetField_CString(hRec,"entity_id",&csEntityId)){
DEBUGLOG(("CalculateAffectFXDT() entity_id = [%s]\n",csEntityId));
					PutField_CString(hDetail,"entity_id",csEntityId);

					memset(csACRType,0,sizeof(csACRType));
					DBObjPtr = CreateObj(DBPtr,"DBMmsEntity","GetACRType");
					if((unsigned long)(*DBObjPtr)(csEntityId,csACRType) == PD_FOUND){
DEBUGLOG(("CalculateAffectFXDT() Affect ACR Type = [%s]\n",csACRType));
					}
				}
				if(GetField_CString(hRec,"org_ccy",&csTmp)){
					PutField_CString(hDetail,"org_ccy",csTmp);
DEBUGLOG(("CalculateAffectFXDT() org_ccy = [%s]\n",csTmp));
				}
				if(GetField_Double(hRec,"org_amount",&dTmp)){
					PutField_Double(hDetail,"org_amount",dTmp);
DEBUGLOG(("CalculateAffectFXDT() org_amount = [%lf]\n",dTmp));
				}
				if(GetField_CString(hRec,"ccy",&csTmp)){
					PutField_CString(hDetail,"ccy",csTmp);
DEBUGLOG(("CalculateAffectFXDT() ccy = [%s]\n",csTmp));
				}
				if(GetField_Double(hRec,"amount",&dTmp)){
					PutField_Double(hDetail,"amount",dTmp);
DEBUGLOG(("CalculateAffectFXDT() amount = [%lf]\n",dTmp));
				}
				if(GetField_Int(hRec,"acr_ind",&iACR)){
					PutField_Int(hDetail,"acr_ind",iACR);
DEBUGLOG(("CalculateAffectFXDT() acr_ind = [%d]\n",iACR));
				}

				if(!strcmp(csACRType,PD_TYPE_ENTITY_FX)){
					if(cDirection == PD_FUNDS_OUT){
						iRet = DebitEntityFx(hDetail);
					}
					else{
						iRet = CreditEntityFx(hDetail);
					}
				}
				else if(!strcmp(csACRType,PD_TYPE_ACR)){
					if(cDirection == PD_FUNDS_OUT){
						iRet = DebitACR(hDetail);
					}
					else{
						iRet = CreditACR(hDetail);
					}
				}
				else{
DEBUGLOG(("CalculateAffectFXDT() Not Affect Any ACR Pool. Do nothing\n"));
				}

				if(iRet == PD_OK){ 
					PutField_Int(hUpd,"calculate_ind",PD_TRUE);
					DBObjPtr = CreateObj(DBPtr,"DBMmsAffectFXDT","Update");
					iRet = (unsigned long)(*DBObjPtr)(hUpd);
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else{
			iRet = INT_ERR;
DEBUGLOG(("CalculateAffectFXDT() GetAffectFXDT Failed!!!!!\n"));
ERRLOG("BOMMSAverageCostRate::CalculateAffectFXDT() GetAffectFXDT Failed!!!!!\n");
		}
		
	}


	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	FREE_ME(hDetail);
	FREE_ME(hUpd);
	FREE_ME(csACRType);

DEBUGLOG(("CalculateAffectFXDT:: () Noraml Exit iRet = [%d]\n",iRet));
	return iRet;
}



int DebitEntityFx(const hash_t* hIn)
{
	int	iRet = PD_OK;
	double	dBalance = 0.0;
	double	dNewBalance = 0.0;
	double	dTmp = 0.0;
	int	iTmp = 0;
	int	iACR = PD_TRUE;
	char	*csTmp = NULL;
	char	cTmp;

	hash_t	*hBal;
	hBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hBal,0);

	hash_t	*hOrgBal;
	hOrgBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgBal,0);

DEBUGLOG(("DebitEntityFx:: ()\n"));

	if(GetField_CString(hIn,"fx_id",&csTmp)){
		PutField_CString(hBal,"fx_id",csTmp);
	}
	if(GetField_Int(hIn,"fx_seq",&iTmp)){
		PutField_Int(hBal,"fx_seq",iTmp);
	}
	if(GetField_CString(hIn,"entity_id",&csTmp)){
		PutField_CString(hBal,"entity_id",csTmp);
	}
	if(GetField_CString(hIn,"org_ccy",&csTmp)){
		PutField_CString(hBal,"org_ccy",csTmp);
	}
	if(GetField_CString(hIn,"ccy",&csTmp)){
		PutField_CString(hBal,"ccy",csTmp);
	}
	if(GetField_Int(hIn,"acr_ind",&iACR)){
		PutField_Int(hBal,"acr_ind",iACR);
	}
	if(GetField_Char(hIn,"direction",&cTmp)){
		PutField_Char(hBal,"direction",cTmp);
	}
	if(GetField_CString(hIn,"update_user",&csTmp)){
		PutField_CString(hBal,"update_user",csTmp);
	}

	iRet = GetEntityFxBalForUpdate(hIn,hOrgBal);
	if(iRet == PD_OK){
		if(GetField_Double(hOrgBal,"bal",&dBalance)){
			PutField_Double(hBal,"old_bal",dBalance);
		}
		if(GetField_Double(hOrgBal,"rate",&dTmp)){
			PutField_Double(hBal,"old_rate",dTmp);
			PutField_Double(hBal,"new_rate",dTmp);
		}

		if(GetField_Double(hIn,"amount",&dTmp)){
			dNewBalance = newround(dBalance - dTmp,PD_DECIMAL_LEN);
			PutField_Double(hBal,"bal",dNewBalance);
			PutField_Double(hBal,"new_bal",dNewBalance);
DEBUGLOG(("New Balance = [%lf]\n",dNewBalance));
		}

		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBal","Update");
		iRet = (unsigned long)(*DBObjPtr)(hBal);
		if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBal: Update() Failed!!!!\n"));
		}

	}
	else if(iRet == PD_NOT_FOUND && !iACR){
		
		if(GetField_Double(hIn,"amount",&dTmp)){
			dNewBalance = newround(dBalance - dTmp,PD_DECIMAL_LEN);
			PutField_Double(hBal,"bal",dNewBalance);
			PutField_Double(hBal,"new_bal",dNewBalance);
DEBUGLOG(("New Balance = [%lf]\n",dNewBalance));
		}

		PutField_Double(hBal,"rate",0.0);
		PutField_Double(hBal,"new_rate",0.0);
		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBal","Add");
		iRet = (unsigned long)(*DBObjPtr)(hBal);
		if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBal: Add() Failed!!!!\n"));
		}
	}
	else{
		iRet = INT_ERR;
	}

	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBalHistory","Add");
		iRet = (unsigned long)(*DBObjPtr)(hBal);
		if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBalHistory: Add() Failed!!!!\n"));
		}
	}

	FREE_ME(hBal);
	FREE_ME(hOrgBal);

DEBUGLOG(("DebitEntityFx:: () Noraml Exit iRet = [%d]\n",iRet));
	return iRet;
}



int CreditEntityFx(const hash_t* hIn)
{
	int	iRet = PD_OK;
	double	dBalance = 0.0;
	double	dNewBalance = 0.0;
	double	dAmt = 0.0;
	double	dFromAmt = 0.0;
	double	dRate= 0.0;
	double	dNewRate= 0.0;
	int	iTmp = 0;
	int	iACR = 0;
	int	iOrgACR = 0;
	char	*csTmp = NULL;
	char	*csOrgFxId = NULL;
	char	*csEntityId = NULL;
	char	*csOrgEntityId = NULL;
	char	*csFromCcy = NULL;
	char	*csOrgFromCcy = NULL;
	char	*csToCcy = NULL;
	char	*csOrgToCcy = NULL;
	char	cTmp;
	char	*csACRType;
	csACRType = (char*) malloc (128);

	hash_t	*hRec;
	hash_t	*hBal;
	hBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hBal,0);

	hash_t	*hOrgBal;
	hOrgBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgBal,0);

	hash_t	*hOrgDetail;
	hOrgDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgDetail,0);

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);
DEBUGLOG(("CreditEntityFx:: ()\n"));

	//For Calculating Receive Txn, both Remit and Receive Txn ID should present
	//For Adjustment, call another function
	//org_fx_id is the Remit Txn ID
	if(!GetField_CString(hIn,"org_fx_id",&csOrgFxId)){
		iRet = AdjustEntityFx(hIn);
		if(iRet!=PD_OK){
DEBUGLOG(("CreditEntityFx:: org_fx_id not found and cannot adjust pool!\n"));
ERRLOG("BOMMSAverageCostRate: CreditEntityFx:: org_fx_id not found and cannot adjust pool!\n");
		}
		else{
			iRet = PD_SKIP_OK;
		}
	}

	if(GetField_CString(hIn,"fx_id",&csTmp)){
		PutField_CString(hBal,"fx_id",csTmp);
	}
	if(GetField_Int(hIn,"fx_seq",&iTmp)){
		PutField_Int(hBal,"fx_seq",iTmp);
	}
	if(GetField_CString(hIn,"entity_id",&csEntityId)){
		PutField_CString(hBal,"entity_id",csEntityId);
	}
	if(GetField_CString(hIn,"org_ccy",&csFromCcy)){
		PutField_CString(hBal,"org_ccy",csFromCcy);
		GetField_Double(hIn,"org_amount",&dFromAmt);
	}
	if(GetField_CString(hIn,"ccy",&csToCcy)){
		PutField_CString(hBal,"ccy",csToCcy);
		GetField_Double(hIn,"amount",&dAmt);
	}
	if(GetField_Int(hIn,"acr_ind",&iACR)){
		PutField_Int(hBal,"acr_ind",iACR);
	}
	if(GetField_Char(hIn,"direction",&cTmp)){
		PutField_Char(hBal,"direction",cTmp);
	}
	if(GetField_CString(hIn,"update_user",&csTmp)){
		PutField_CString(hBal,"update_user",csTmp);
	}

	if(iRet == PD_OK && !iACR){
//adding balance to the **non-affected** pool

		iRet = GetEntityFxBalForUpdate(hIn,hOrgBal);
		if(iRet == PD_OK){
			if(GetField_Double(hOrgBal,"bal",&dBalance)){
				PutField_Double(hBal,"old_bal",dBalance);
			}
			if(GetField_Double(hOrgBal,"rate",&dRate)){
				PutField_Double(hBal,"old_rate",dRate);
				PutField_Double(hBal,"new_rate",dRate);
			}
		}

		//no rate changes
		dNewBalance = newround(dBalance + dAmt,PD_DECIMAL_LEN);
		PutField_Double(hBal,"bal",dNewBalance);
		PutField_Double(hBal,"new_bal",dNewBalance);
DEBUGLOG(("New Balance = [%lf]\n",dNewBalance));

		if(iRet == PD_NOT_FOUND){
		//insert a new record if not exists.
			PutField_Double(hBal,"rate",0.0);
			PutField_Double(hBal,"new_rate",0.0);

			DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBal","Add");
			iRet = (unsigned long)(*DBObjPtr)(hBal);
			if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBal: Add() Failed!!!!\n"));
			}
		}
		else if(iRet == PD_OK){
			DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBal","Update");
			iRet = (unsigned long)(*DBObjPtr)(hBal);
			if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBal: Update() Failed!!!!\n"));
			}
		}

		if(iRet == PD_OK){
			DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBalHistory","Add");
			iRet = (unsigned long)(*DBObjPtr)(hBal);
			if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBalHistory: Add() Failed!!!!\n"));
			}
		}
	}

	else if(iRet == PD_OK && iACR){
//adding balance to the **affected** pool

		int    iChk = 0;
		double dOrgHalfFxRate = 0.0;
		double dOrgFxRate = 0.0;
		double dOrgFxBalance = 0.0;

		hash_t	*hOrgFx;
		hOrgFx = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hOrgFx,0);

		//Find the remit infromation
		PutField_CString(hOrgDetail,"fx_id",csOrgFxId);
		DBObjPtr = CreateObj(DBPtr,"DBMmsAffectFXDT","GetAffectFXDT");
		iRet = (unsigned long)(*DBObjPtr)(hOrgDetail, rRecordSet);
		if(iRet == PD_OK){
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec && (iRet == PD_OK)) {
				dOrgHalfFxRate = 0.0;
				dOrgFxRate = 0.0;
				dOrgFxBalance = 0.0;

				hash_destroy(hOrgFx);
				hash_init(hOrgFx,0);

				if(GetField_CString(hRec,"entity_id",&csOrgEntityId) &&
				   GetField_CString(hRec,"org_ccy",&csOrgFromCcy) &&
				   GetField_CString(hRec,"ccy",&csOrgToCcy) &&
				   GetField_Int(hRec,"acr_ind",&iOrgACR)){

					//csOrgFromCcy -> csOrgToCcy
					//		  csFromCcy -> csToCcy
					//csOrgToCcy should be equal to csFromCcy

					if(iOrgACR &&
					   !strcmp(csOrgToCcy,csFromCcy)){

						//find original half way fx rate [csOrgFromCcy -> csOrgToCcy(csFromCcy)]
						PutField_CString(hOrgFx,"entity_id",csOrgEntityId);
						PutField_CString(hOrgFx,"org_ccy",csOrgFromCcy);
						PutField_CString(hOrgFx,"ccy",csOrgToCcy);
						PutField_Int(hOrgFx,"acr_ind",iOrgACR);

						memset(csACRType,0,sizeof(csACRType));
						DBObjPtr = CreateObj(DBPtr,"DBMmsEntity","GetACRType");
						iRet = (unsigned long)(*DBObjPtr)(csEntityId,csACRType);
						if(iRet == PD_FOUND){
							if(!strcmp(csACRType,PD_TYPE_ENTITY_FX)){
								iRet = GetEntityFxBal(hOrgFx,hOrgDetail);
							}
							else if(!strcmp(csACRType,PD_TYPE_ACR)){
								iRet = GetACRBal(hOrgFx,hOrgDetail);
							}
						}
						if(iRet == PD_OK){
							GetField_Double(hOrgDetail,"rate",&dOrgHalfFxRate);
DEBUGLOG(("The half way fx rate [%s->%s] = [%lf]\n",csOrgFromCcy,csOrgToCcy,dOrgHalfFxRate));

							if((dOrgHalfFxRate==0.0 && strcmp(csOrgFromCcy,csOrgToCcy))
							    || dOrgHalfFxRate<0.0) {
								iRet = INT_ERR;
DEBUGLOG(("The half way fx rate invalid!!!!\n"));
							}
						}
						else if(iRet == PD_NOT_FOUND &&
							!strcmp(csOrgFromCcy,csFromCcy)){

							dOrgHalfFxRate = 1.0;
							iRet = PD_OK;
						}


						//find full way fx rate[csOrgFromCcy -> csToCcy]
						if(iRet == PD_OK){
							PutField_CString(hBal,"entity_id",csEntityId);
							PutField_CString(hBal,"org_ccy",csOrgFromCcy);
							PutField_CString(hBal,"ccy",csToCcy);
							PutField_Int(hBal,"acr_ind",iOrgACR);

							iChk= GetEntityFxBalForUpdate(hBal,hOrgDetail);
							if(iChk == PD_OK){
								GetField_Double(hOrgDetail,"rate",&dOrgFxRate);
								PutField_Double(hBal,"old_rate",dOrgFxRate);

								GetField_Double(hOrgDetail,"bal",&dOrgFxBalance);
								PutField_Double(hBal,"old_bal",dOrgFxBalance);
DEBUGLOG(("The full way fx rate [%s->%s] = [%lf], Balance = [%lf]\n",csOrgFromCcy,csToCcy,dOrgFxRate,dOrgFxBalance));
							}
							else if(iChk == PD_NOT_FOUND){
								dOrgFxRate = 0.0;
								dOrgFxBalance = 0.0;
DEBUGLOG(("The full way fx rate [%s->%s] not yet exists\n",csOrgFromCcy,csOrgToCcy));
							}
							else{
								iRet = iChk;
DEBUGLOG(("Find full way fx rate [%s->%s] Failed!!!!\n",csOrgFromCcy,csOrgToCcy));
							}
						}
						
						//full path [csOrgFromCcy -> csOrgToCcy(csFromCcy) -> csToCcy]
						//calculate overall rate [csOrgFromCcy -> csToCcy]
						if(iRet == PD_OK){
							//half way: csOrgFromCcy -> csOrgToCcy = dOrgHalfFxRate
							//full way: csOrgFromCcy -> csToCcy    = dOrgFxRate with dOrgFxBalance
							//input: csFromCcy [dFromAmt] -> csToCcy [dAmt]
							//
							//new balance
							//= dOrgFxBalance + dAmt;
							//new rate
							//= (dAmt + dOrgFxBalance)/ ((dFromAmt/dOrgHalfFxRate) + (dOrgFxBalance/dOrgFxRate))

							
							dNewBalance = newround(dOrgFxBalance + dAmt,PD_DECIMAL_LEN);
							PutField_Double(hBal,"bal",dNewBalance);
							PutField_Double(hBal,"new_bal",dNewBalance);

							if(dOrgFxRate == 0.0)
								//to prevent calculation error
								dOrgFxRate = 1.0;

							if(dOrgFxBalance < 0.0){
								//only use the input amount to calculate rate
								dNewBalance = dAmt;
								dOrgFxBalance = 0.0;
							}

							dNewRate = CreditFormula(dNewBalance,
										    dFromAmt,dOrgHalfFxRate,
										    dOrgFxBalance,dOrgFxRate);

							PutField_Double(hBal,"rate",dNewRate);
							PutField_Double(hBal,"new_rate",dNewRate);
DEBUGLOG(("[%s->%s] New Balance = [%lf], New Rate = [%lf]\n",csOrgFromCcy,csToCcy,dNewBalance,dNewRate));

							if(dNewRate<=0.0){
								iRet = INT_ERR;
DEBUGLOG(("[%s->%s] New Rate invalid!!!!\n",csOrgFromCcy,csToCcy));
							}
						}

						if(iRet == PD_OK){
							//insert a new record if not exists.
							char csFunction[PD_TAG_LEN];
							if(iChk == PD_NOT_FOUND)
								sprintf(csFunction,"%s","Add");
							else
								sprintf(csFunction,"%s","Update");

							DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBal",csFunction);
							iRet = (unsigned long)(*DBObjPtr)(hBal);
							if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBal: %s() Failed!!!!\n",csFunction));
							}
						}

						if(iRet == PD_OK){
							DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBalHistory","Add");
							iRet = (unsigned long)(*DBObjPtr)(hBal);
							if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBalHistory: Add() Failed!!!!\n"));
							}
						}
					}
				}
				
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}

		FREE_ME(hOrgFx);
	}

	if(iRet == PD_SKIP_OK)
		iRet = PD_OK;


	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	FREE_ME(hBal);
	FREE_ME(hOrgBal);
	FREE_ME(hOrgDetail);
	FREE_ME(csACRType);

DEBUGLOG(("CreditEntityFx:: () Noraml Exit iRet = [%d]\n",iRet));
	return iRet;
}


int AdjustEntityFx(const hash_t* hIn)
{
	int	iRet = INT_ERR;
	double	dBalance = 0.0;
	double	dNewBalance = 0.0;
	double	dAmt = 0.0;
	double	dFromAmt = 0.0;
	double	dRate= 0.0;
	int	iTmp = 0;
	int	iACR = 0;
	char	*csTmp = NULL;
	char	*csEntityId = NULL;
	char	*csFromCcy = NULL;
	char	*csToCcy = NULL;
	char	*csTxnId = NULL;
	char	*csTxnCode = NULL;
	char	cTmp;

	hash_t	*hBal;
	hBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hBal,0);

	hash_t	*hOrgBal;
	hOrgBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgBal,0);

DEBUGLOG(("AdjustEntityFx:: ()\n"));

	if(GetField_CString(hIn,"fx_id",&csTxnId)){
		PutField_CString(hBal,"fx_id",csTxnId);
	}
	if(GetField_Int(hIn,"fx_seq",&iTmp)){
		PutField_Int(hBal,"fx_seq",iTmp);
	}
	if(GetField_CString(hIn,"entity_id",&csEntityId)){
		PutField_CString(hBal,"entity_id",csEntityId);
	}
	if(GetField_CString(hIn,"org_ccy",&csFromCcy)){
		PutField_CString(hBal,"org_ccy",csFromCcy);
		GetField_Double(hIn,"org_amount",&dFromAmt);
	}
	if(GetField_CString(hIn,"ccy",&csToCcy)){
		PutField_CString(hBal,"ccy",csToCcy);
		GetField_Double(hIn,"amount",&dAmt);
	}
	if(GetField_Int(hIn,"acr_ind",&iACR)){
		PutField_Int(hBal,"acr_ind",iACR);
	}
	if(GetField_Char(hIn,"direction",&cTmp)){
		PutField_Char(hBal,"direction",cTmp);
	}
	if(GetField_CString(hIn,"update_user",&csTmp)){
		PutField_CString(hBal,"update_user",csTmp);
	}

	//check txn type, if not adjustment, reject.
	if(GetField_CString(hIn,"code",&csTxnCode)){
DEBUGLOG(("txn_code = [%s]\n",csTxnCode));
		DBObjPtr = CreateObj(DBPtr,"DBMmsAdjustmentType","Find");
		if((unsigned long)(*DBObjPtr)(hIn) == PD_FOUND){
			iRet = PD_OK;
		}
	}

	if(iRet == PD_OK){
//adding balance to the pool
		iRet = GetEntityFxBalForUpdate(hIn,hOrgBal);
		if(iRet == PD_OK){
			if(GetField_Double(hOrgBal,"bal",&dBalance)){
				PutField_Double(hBal,"old_bal",dBalance);
			}
			if(GetField_Double(hOrgBal,"rate",&dRate)){
				PutField_Double(hBal,"old_rate",dRate);
				PutField_Double(hBal,"new_rate",dRate);
			}
		}

		//no rate changes
		dNewBalance = newround(dBalance + dAmt,PD_DECIMAL_LEN);
		PutField_Double(hBal,"bal",dNewBalance);
		PutField_Double(hBal,"new_bal",dNewBalance);
DEBUGLOG(("New Balance = [%lf]\n",dNewBalance));

		if(iRet == PD_NOT_FOUND && !iACR){
		//insert a new record if not exists.
			PutField_Double(hBal,"rate",0.0);
			PutField_Double(hBal,"new_rate",0.0);

			DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBal","Add");
			iRet = (unsigned long)(*DBObjPtr)(hBal);
			if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBal: Add() Failed!!!!\n"));
			}
		}
		else if(iRet == PD_NOT_FOUND && iACR){
			iRet = INT_ERR;
DEBUGLOG(("AdjustEntityFx:: Original pool not found!!!!\n"));
		}
		else if(iRet == PD_OK){
			DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBal","Update");
			iRet = (unsigned long)(*DBObjPtr)(hBal);
			if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBal: Update() Failed!!!!\n"));
			}
		}

		if(iRet == PD_OK){
			DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBalHistory","Add");
			iRet = (unsigned long)(*DBObjPtr)(hBal);
			if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBalHistory: Add() Failed!!!!\n"));
			}
		}
	}

	FREE_ME(hBal);
	FREE_ME(hOrgBal);

DEBUGLOG(("AdjustEntityFx:: () Noraml Exit iRet = [%d]\n",iRet));
	return iRet;
}




int DebitACR(const hash_t* hIn)
{
	int	iRet = PD_OK;
	double	dAmt = 0.0;
	double	dBalance = 0.0;
	double	dNewBalance = 0.0;
	double	dTmp = 0.0;
	int	iTmp = 0;
	int	iACR = 0;
	char	*csTmp = NULL;
	char	cTmp;

	hash_t	*hBal;
	hBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hBal,0);

	hash_t	*hOrgBal;
	hOrgBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgBal,0);

DEBUGLOG(("DebitACR:: ()\n"));

	if(GetField_CString(hIn,"fx_id",&csTmp)){
		PutField_CString(hBal,"fx_id",csTmp);
	}
	if(GetField_Int(hIn,"fx_seq",&iTmp)){
		PutField_Int(hBal,"fx_seq",iTmp);
	}
	if(GetField_CString(hIn,"entity_id",&csTmp)){
		PutField_CString(hBal,"entity_id",csTmp);
	}
	if(GetField_CString(hIn,"org_ccy",&csTmp)){
		PutField_CString(hBal,"org_ccy",csTmp);
	}
	if(GetField_CString(hIn,"ccy",&csTmp)){
		PutField_CString(hBal,"ccy",csTmp);
		GetField_Double(hIn,"amount",&dAmt);
	}
	if(GetField_Int(hIn,"acr_ind",&iACR)){
		PutField_Int(hBal,"acr_ind",iACR);
	}
	if(GetField_Char(hIn,"direction",&cTmp)){
		PutField_Char(hBal,"direction",cTmp);
	}
	if(GetField_CString(hIn,"update_user",&csTmp)){
		PutField_CString(hBal,"update_user",csTmp);
		PutField_CString(hBal,"create_user",csTmp);
	}

	iRet = GetACRBalForUpdate(hIn,hOrgBal);
	if(iRet == PD_OK){
		if(GetField_Double(hOrgBal,"bal",&dBalance)){
			PutField_Double(hBal,"old_bal",dBalance);
		}
		if(GetField_Double(hOrgBal,"rate",&dTmp)){
			PutField_Double(hBal,"old_rate",dTmp);
			PutField_Double(hBal,"new_rate",dTmp);
			PutField_Double(hBal,"rate",dTmp);
		}
		/*if(GetField_Double(hOrgBal,"ratio",&dTmp)){
			PutField_Double(hBal,"old_ratio",dTmp);
			PutField_Double(hBal,"new_ratio",dTmp);
		}*/

		dNewBalance = newround(dBalance - dAmt,PD_DECIMAL_LEN);
		PutField_Double(hBal,"bal",dNewBalance);
		PutField_Double(hBal,"new_bal",dNewBalance);
DEBUGLOG(("New Balance = [%lf]\n",dNewBalance));

		DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBal","Update");
		iRet = (unsigned long)(*DBObjPtr)(hBal);
		if(iRet != PD_OK){
DEBUGLOG(("DBMmsAcrBal: Update() Failed!!!!\n"));
		}
	}
	else if(iRet == PD_NOT_FOUND && !iACR){
		
		dNewBalance = newround(dBalance - dAmt,PD_DECIMAL_LEN);
		PutField_Double(hBal,"bal",dNewBalance);
		PutField_Double(hBal,"new_bal",dNewBalance);
DEBUGLOG(("New Balance = [%lf]\n",dNewBalance));

		PutField_Double(hBal,"rate",0.0);
		PutField_Double(hBal,"new_rate",0.0);
		DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBal","Update");
		iRet = (unsigned long)(*DBObjPtr)(hBal);
		if(iRet != PD_OK){
DEBUGLOG(("DBMmsAcrBal: Update() Failed!!!!\n"));
		}
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("GetOwnAcrBalForUpdate() Failed!!!!\n"));
	}

	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBalHistory","Add");
		iRet = (unsigned long)(*DBObjPtr)(hBal);
		if(iRet != PD_OK){
DEBUGLOG(("DBMmsAcrBalHistory: Add() Failed!!!!\n"));
		}
	}

	FREE_ME(hBal);
	FREE_ME(hOrgBal);

DEBUGLOG(("DebitACR:: () Noraml Exit iRet = [%d]\n",iRet));
	return iRet;
}



int CreditACR(const hash_t* hIn)
{
	int	iRet = PD_OK;
	double	dFromAmt = 0.0;
	double	dAmt = 0.0;
	double	dBalance = 0.0;
	double	dNewBalance = 0.0;
	//double	dTmp = 0.0;
	int	iTmp = 0;
	int	iACR = 0;
	int	iOrgACR = 0;
	char	*csTmp = NULL;
	char	cTmp;
	double	dRate= 0.0;
	double	dNewRate= 0.0;
	char	*csOrgFxId = NULL;
	char	*csEntityId = NULL;
	char	*csOrgEntityId = NULL;
	char	*csFromCcy = NULL;
	char	*csOrgFromCcy = NULL;
	char	*csToCcy = NULL;
	char	*csOrgToCcy = NULL;

	int    iChk = 0;
	double dOrgHalfFxRate = 0.0;
	double dOrgFxRate = 0.0;
	double dOrgFxBalance = 0.0;

	char	*csACRType;
	csACRType = (char*) malloc (128);

	hash_t	*hRec;
	hash_t	*hBal;
	hBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hBal,0);

	hash_t	*hOrgBal;
	hOrgBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgBal,0);

	hash_t	*hOrgDetail;
	hOrgDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgDetail,0);

	hash_t	*hOrgFx;
	hOrgFx = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgFx,0);

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);
DEBUGLOG(("CreditACR:: ()\n"));

	//For Calculating Receive Txn, both Remit and Receive Txn ID should present
	//org_fx_id is the Remit Txn ID
	if(!GetField_CString(hIn,"org_fx_id",&csOrgFxId)){
		iRet = AdjustACR(hIn);
		if(iRet != PD_OK){
DEBUGLOG(("CreditACR:: org_fx_id not found and cannot adjust pool!\n"));
ERRLOG("BOMMSAverageCostRate: CreditACR:: org_fx_id not found and cannot adjust pool!\n");
		}
		else{
			iRet = PD_SKIP_OK;
		}
	}
	if(GetField_CString(hIn,"fx_id",&csTmp)){
		PutField_CString(hBal,"fx_id",csTmp);
	}
	if(GetField_Int(hIn,"fx_seq",&iTmp)){
		PutField_Int(hBal,"fx_seq",iTmp);
	}
	if(GetField_CString(hIn,"entity_id",&csEntityId)){
		PutField_CString(hBal,"entity_id",csEntityId);
	}
	if(GetField_CString(hIn,"org_ccy",&csFromCcy)){
		PutField_CString(hBal,"org_ccy",csFromCcy);
		GetField_Double(hIn,"org_amount",&dFromAmt);
	}
	if(GetField_CString(hIn,"ccy",&csToCcy)){
		PutField_CString(hBal,"ccy",csToCcy);
		GetField_Double(hIn,"amount",&dAmt);
	}
	if(GetField_Int(hIn,"acr_ind",&iACR)){
		PutField_Int(hBal,"acr_ind",iACR);
	}
	if(GetField_Char(hIn,"direction",&cTmp)){
		PutField_Char(hBal,"direction",cTmp);
	}
	if(GetField_CString(hIn,"update_user",&csTmp)){
		PutField_CString(hBal,"update_user",csTmp);
		PutField_CString(hBal,"create_user",csTmp);
	}

	if(iRet == PD_OK && !iACR){
//adding balance to the **non-affected** pool

		iRet = GetACRBalForUpdate(hIn,hOrgBal);
		if(iRet == PD_OK){
			if(GetField_Double(hOrgBal,"bal",&dBalance)){
				PutField_Double(hBal,"old_bal",dBalance);
			}
			if(GetField_Double(hOrgBal,"rate",&dRate)){
				PutField_Double(hBal,"old_rate",dRate);
				PutField_Double(hBal,"new_rate",dRate);
				PutField_Double(hBal,"rate",dRate);
			}
		}

		//no rate changes
		dNewBalance = newround(dBalance + dAmt,PD_DECIMAL_LEN);
		PutField_Double(hBal,"bal",dNewBalance);
		PutField_Double(hBal,"new_bal",dNewBalance);
DEBUGLOG(("New Balance = [%lf]\n",dNewBalance));

		if(iRet == PD_NOT_FOUND){
		//insert a new record if not exists.
			PutField_Double(hBal,"rate",0.0);
			PutField_Double(hBal,"new_rate",0.0);
			iRet = PD_OK;
		}

		if(iRet == PD_OK){
			DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBal","Update");
			iRet = (unsigned long)(*DBObjPtr)(hBal);
			if(iRet != PD_OK){
DEBUGLOG(("DBMmsAcrBal: Update() Failed!!!!\n"));
			}
		}

		if(iRet == PD_OK){
			DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBalHistory","Add");
			iRet = (unsigned long)(*DBObjPtr)(hBal);
			if(iRet != PD_OK){
DEBUGLOG(("DBMmsAcrBalHistory: Add() Failed!!!!\n"));
			}
		}
	}
	else if(iRet == PD_OK && iACR){
//adding balance to the **affected** pool

		//Find the remit infromation
		PutField_CString(hOrgDetail,"fx_id",csOrgFxId);
		DBObjPtr = CreateObj(DBPtr,"DBMmsAffectFXDT","GetAffectFXDT");
		iRet = (unsigned long)(*DBObjPtr)(hOrgDetail, rRecordSet);
		if(iRet == PD_OK){
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec && (iRet == PD_OK)) {
				dOrgHalfFxRate = 0.0;
				dOrgFxRate = 0.0;
				dOrgFxBalance = 0.0;

				hash_destroy(hOrgFx);
				hash_init(hOrgFx,0);

				if(GetField_CString(hRec,"entity_id",&csOrgEntityId) &&
				   GetField_CString(hRec,"org_ccy",&csOrgFromCcy) &&
				   GetField_CString(hRec,"ccy",&csOrgToCcy) &&
				   GetField_Int(hRec,"acr_ind",&iOrgACR)){

					if(iOrgACR &&
					   !strcmp(csOrgToCcy,csFromCcy)){

						//find original half way fx rate [csOrgFromCcy -> csOrgToCcy(csFromCcy)]
						PutField_CString(hOrgFx,"entity_id",csOrgEntityId);
						PutField_CString(hOrgFx,"org_ccy",csOrgFromCcy);
						PutField_CString(hOrgFx,"ccy",csOrgToCcy);
						PutField_Int(hOrgFx,"acr_ind",iOrgACR);

						memset(csACRType,0,sizeof(csACRType));
						DBObjPtr = CreateObj(DBPtr,"DBMmsEntity","GetACRType");
						iRet = (unsigned long)(*DBObjPtr)(csOrgEntityId,csACRType);
						if(iRet == PD_FOUND){
							if(!strcmp(csACRType,PD_TYPE_ENTITY_FX)){
								iRet = GetEntityFxBal(hOrgFx,hOrgDetail);
							}
							else if(!strcmp(csACRType,PD_TYPE_ACR)){
								iRet = GetACRBal(hOrgFx,hOrgDetail);
							}
						}

						if(iRet == PD_OK){
							GetField_Double(hOrgDetail,"rate",&dOrgHalfFxRate);
DEBUGLOG(("The half way fx rate [%s->%s] = [%lf]\n",csOrgFromCcy,csOrgToCcy,dOrgHalfFxRate));

							if((dOrgHalfFxRate==0.0 && strcmp(csOrgFromCcy,csOrgToCcy))
							    || dOrgHalfFxRate<0.0) {
								iRet = INT_ERR;
DEBUGLOG(("The half way fx rate invalid!!!!\n"));
							}
						}
						else if(iRet == PD_NOT_FOUND &&
							!strcmp(csOrgFromCcy,csFromCcy)){

							dOrgHalfFxRate = 1.0;
							iRet = PD_OK;
						}


						//find full way fx rate[csOrgFromCcy -> csToCcy]
						if(iRet == PD_OK){
							PutField_CString(hBal,"entity_id",csEntityId);
							PutField_CString(hBal,"org_ccy",csOrgFromCcy);
							PutField_CString(hBal,"ccy",csToCcy);

							iChk = GetACRBalForUpdate(hBal,hOrgDetail);
							if(iChk == PD_OK){
								GetField_Double(hOrgDetail,"rate",&dOrgFxRate);
								PutField_Double(hBal,"old_rate",dOrgFxRate);

								GetField_Double(hOrgDetail,"bal",&dOrgFxBalance);
								PutField_Double(hBal,"old_bal",dOrgFxBalance);
DEBUGLOG(("The full way fx rate [%s->%s] = [%lf], Balance = [%lf]\n",csOrgFromCcy,csToCcy,dOrgFxRate,dOrgFxBalance));
							}
							else if(iChk == PD_NOT_FOUND){
								dOrgFxRate = 0.0;
								dOrgFxBalance = 0.0;
DEBUGLOG(("The full way fx rate [%s->%s] not yet exists\n",csOrgFromCcy,csOrgToCcy));
							}
							else{
								iRet = iChk;
DEBUGLOG(("Find full way fx rate [%s->%s] Failed!!!!\n",csOrgFromCcy,csOrgToCcy));
							}
						}
						
						//full path [csOrgFromCcy -> csOrgToCcy(csFromCcy) -> csToCcy]
						//calculate overall rate [csOrgFromCcy -> csToCcy]
						if(iRet == PD_OK){
							//half way: csOrgFromCcy -> csOrgToCcy = dOrgHalfFxRate
							//full way: csOrgFromCcy -> csToCcy    = dOrgFxRate with dOrgFxBalance
							//input: csFromCcy [dFromAmt] -> csToCcy [dAmt]
							//
							//new balance
							//= dOrgFxBalance + dAmt;
							//new rate
							//= (dAmt + dOrgFxBalance)/ ((dFromAmt/dOrgHalfFxRate) + (dOrgFxBalance/dOrgFxRate))

							
							dNewBalance = newround(dOrgFxBalance + dAmt,PD_DECIMAL_LEN);
							PutField_Double(hBal,"bal",dNewBalance);
							PutField_Double(hBal,"new_bal",dNewBalance);

							if(dOrgFxRate == 0.0)
								//to prevent calculation error
								dOrgFxRate = 1.0;

							if(dOrgFxBalance < 0.0){
								//only use the input amount to calculate rate
								dNewBalance = dAmt;
								dOrgFxBalance = 0.0;
							}

							dNewRate = CreditFormula(dNewBalance,
										    dFromAmt,dOrgHalfFxRate,
										    dOrgFxBalance,dOrgFxRate);

							PutField_Double(hBal,"rate",dNewRate);
							PutField_Double(hBal,"new_rate",dNewRate);
DEBUGLOG(("[%s->%s] New Balance = [%lf], New Rate = [%lf]\n",csOrgFromCcy,csToCcy,dNewBalance,dNewRate));

							if(dNewRate<=0.0){
								iRet = INT_ERR;
DEBUGLOG(("[%s->%s] New Rate invalid!!!!\n",csOrgFromCcy,csToCcy));
							}
						}

						if(iRet == PD_OK){
							DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBal","Update");
							iRet = (unsigned long)(*DBObjPtr)(hBal);
							if(iRet != PD_OK){
DEBUGLOG(("DBMmsAcrBal: Update() Failed!!!!\n"));
							}
						}

						if(iRet == PD_OK){
							DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBalHistory","Add");
							iRet = (unsigned long)(*DBObjPtr)(hBal);
							if(iRet != PD_OK){
DEBUGLOG(("DBMmsAcrBalHistory: Add() Failed!!!!\n"));
							}
						}
					}
				}
				
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}

	}

	if(iRet == PD_SKIP_OK)
		iRet = PD_OK;

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	FREE_ME(hBal);
	FREE_ME(hOrgBal);
	FREE_ME(hOrgDetail);
	FREE_ME(hOrgFx);
	FREE_ME(csACRType);

DEBUGLOG(("CreditACR:: () Noraml Exit iRet = [%d]\n",iRet));
	return iRet;
}


int AdjustACR(const hash_t* hIn)
{
	int	iRet = INT_ERR;
	double	dBalance = 0.0;
	double	dNewBalance = 0.0;
	double	dAmt = 0.0;
	double	dFromAmt = 0.0;
	double	dRate= 0.0;
	int	iTmp = 0;
	int	iACR = 0;
	char	*csTmp = NULL;
	char	*csEntityId = NULL;
	char	*csFromCcy = NULL;
	char	*csToCcy = NULL;
	char	*csTxnId = NULL;
	char	*csTxnCode = NULL;
	char	cTmp;

	hash_t	*hBal;
	hBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hBal,0);

	hash_t	*hOrgBal;
	hOrgBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgBal,0);

DEBUGLOG(("AdjustACR:: ()\n"));

	if(GetField_CString(hIn,"fx_id",&csTxnId)){
		PutField_CString(hBal,"fx_id",csTxnId);
	}
	if(GetField_Int(hIn,"fx_seq",&iTmp)){
		PutField_Int(hBal,"fx_seq",iTmp);
	}
	if(GetField_CString(hIn,"entity_id",&csEntityId)){
		PutField_CString(hBal,"entity_id",csEntityId);
	}
	if(GetField_CString(hIn,"org_ccy",&csFromCcy)){
		PutField_CString(hBal,"org_ccy",csFromCcy);
		GetField_Double(hIn,"org_amount",&dFromAmt);
	}
	if(GetField_CString(hIn,"ccy",&csToCcy)){
		PutField_CString(hBal,"ccy",csToCcy);
		GetField_Double(hIn,"amount",&dAmt);
	}
	if(GetField_Int(hIn,"acr_ind",&iACR)){
		PutField_Int(hBal,"acr_ind",iACR);
	}
	if(GetField_Char(hIn,"direction",&cTmp)){
		PutField_Char(hBal,"direction",cTmp);
	}
	if(GetField_CString(hIn,"update_user",&csTmp)){
		PutField_CString(hBal,"update_user",csTmp);
		PutField_CString(hBal,"create_user",csTmp);
	}

	//check txn type, if not adjustment, reject.
	if(GetField_CString(hIn,"code",&csTxnCode)){
		DBObjPtr = CreateObj(DBPtr,"DBMmsAdjustmentType","Find");
		if((unsigned long)(*DBObjPtr)(hIn) == PD_FOUND){
			iRet = PD_OK;
		}
	}

	if(iRet == PD_OK){
//adding balance to the pool
		iRet = GetACRBalForUpdate(hIn,hOrgBal);
		if(iRet == PD_OK){
			if(GetField_Double(hOrgBal,"bal",&dBalance)){
				PutField_Double(hBal,"old_bal",dBalance);
			}
			if(GetField_Double(hOrgBal,"rate",&dRate)){
				PutField_Double(hBal,"old_rate",dRate);
				PutField_Double(hBal,"new_rate",dRate);
				PutField_Double(hBal,"rate",dRate);
			}
		}

		//no rate changes
		dNewBalance = newround(dBalance + dAmt,PD_DECIMAL_LEN);
		PutField_Double(hBal,"bal",dNewBalance);
		PutField_Double(hBal,"new_bal",dNewBalance);
DEBUGLOG(("New Balance = [%lf]\n",dNewBalance));

		if(iRet == PD_NOT_FOUND && !iACR){
		//insert a new record if not exists.
			PutField_Double(hBal,"rate",0.0);
			PutField_Double(hBal,"new_rate",0.0);
			iRet = PD_OK;
		}
		else if(iRet == PD_NOT_FOUND && iACR){
			iRet = INT_ERR;
DEBUGLOG(("AdjustACR:: Original pool not found!!!!\n"));
		}

		if(iRet == PD_OK){
			DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBal","Update");
			iRet = (unsigned long)(*DBObjPtr)(hBal);
			if(iRet != PD_OK){
DEBUGLOG(("DBMmsAcrBal: Update() Failed!!!!\n"));
			}
		}

		if(iRet == PD_OK){
			DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBalHistory","Add");
			iRet = (unsigned long)(*DBObjPtr)(hBal);
			if(iRet != PD_OK){
DEBUGLOG(("DBMmsAcrBalHistory: Add() Failed!!!!\n"));
			}
		}
	}

	FREE_ME(hBal);
	FREE_ME(hOrgBal);

DEBUGLOG(("AdjustACR:: () Noraml Exit iRet = [%d]\n",iRet));
	return iRet;
}

int VoidAffectFx(const hash_t* hIn)
{
	int	iRet = PD_OK;
	int	iTmp = 0;
	int	iCal = 0;
	int	iACR = 0;
	double	dTmp = 0.0;
	char	cDirection = 'x';
	char	*csTmp = NULL;
	char	*csTxnSeq = NULL;
	char	*csFxId = NULL;
	char	*csUser = NULL;
	char	*csEntityId = NULL;
	char	*csACRType;
	csACRType = (char*) malloc (128);

	hash_t	*hRec;
	hash_t	*hHist;
	hash_t	*hDetail;
	hDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hDetail,0);

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

	recordset_t     *rHistSet;
	rHistSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rHistSet,0);

DEBUGLOG(("VoidAffectFx:: ()\n"));

	//Void Transaction ID
	if(GetField_CString(hIn,"txn_seq",&csTxnSeq)){
		PutField_CString(hDetail,"txn_seq",csTxnSeq);
DEBUGLOG(("VoidAffectFx() txn_seq = [%s]\n",csTxnSeq));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("VoidAffectFx() txn_seq not found\n"));
ERRLOG("BOMMSAverageCostRate::VoidAffectFx() txn_seq not found\n");
	}

	//Transaction ID (Remit/Receive Txn)
	if(GetField_CString(hIn,"fx_id",&csFxId)){
DEBUGLOG(("VoidAffectFx() fx_id = [%s]\n",csFxId));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("VoidAffectFx() fx_id not found\n"));
ERRLOG("BOMMSAverageCostRate::VoidAffectFx() fx_id not found\n");
	}

	if(GetField_CString(hIn,"update_user",&csUser)){
		PutField_CString(hDetail,"update_user",csUser);
DEBUGLOG(("VoidAffectFx() update_user = [%s]\n",csUser));
	}

	if(iRet == PD_OK){
		//get fx detail by fx_id
		PutField_CString(hDetail,"fx_id",csFxId);
		DBObjPtr = CreateObj(DBPtr,"DBMmsAffectFXDT","GetAffectFXDT");
		iRet = (unsigned long)(*DBObjPtr)(hDetail, rRecordSet);
		if(iRet == PD_OK){
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec && (iRet == PD_OK)) {
				if(GetField_Int(hRec,"fx_seq",&iTmp)){
					PutField_Int(hDetail,"fx_seq",iTmp);
DEBUGLOG(("VoidAffectFx() >>> fx_seq = [%d] <<<\n",iTmp));
				}
				if(GetField_Char(hRec,"direction",&cDirection)){
					PutField_Char(hDetail,"direction",cDirection);
DEBUGLOG(("VoidAffectFx() direction = [%c]\n",cDirection));
				}
				if(GetField_Int(hRec,"calculate_ind",&iCal)){
DEBUGLOG(("VoidAffectFx() calculate_ind = [%d]\n",iCal));
				}
				if(!iCal){
DEBUGLOG(("VoidAffectFx() Not yet calculate. Skip...\n"));
					hRec = RecordSet_GetNext(rRecordSet);
					continue;
				}
				if(GetField_CString(hRec,"entity_id",&csEntityId)){
DEBUGLOG(("VoidAffectFx() entity_id = [%s]\n",csEntityId));
					PutField_CString(hDetail,"entity_id",csEntityId);

					memset(csACRType,0,sizeof(csACRType));
					DBObjPtr = CreateObj(DBPtr,"DBMmsEntity","GetACRType");
					if((unsigned long)(*DBObjPtr)(csEntityId,csACRType) == PD_FOUND){
DEBUGLOG(("VoidAffectFx() Affect ACR Type = [%s]\n",csACRType));
					}
				}
				if(GetField_CString(hRec,"org_ccy",&csTmp)){
					PutField_CString(hDetail,"org_ccy",csTmp);
DEBUGLOG(("VoidAffectFx() org_ccy = [%s]\n",csTmp));
				}
				if(GetField_Double(hRec,"org_amount",&dTmp)){
					PutField_Double(hDetail,"org_amount",dTmp);
DEBUGLOG(("VoidAffectFx() org_amount = [%lf]\n",dTmp));
				}
				if(GetField_CString(hRec,"ccy",&csTmp)){
					PutField_CString(hDetail,"ccy",csTmp);
DEBUGLOG(("VoidAffectFx() ccy = [%s]\n",csTmp));
				}
				if(GetField_Double(hRec,"amount",&dTmp)){
					PutField_Double(hDetail,"amount",dTmp);
DEBUGLOG(("VoidAffectFx() amount = [%lf]\n",dTmp));
				}
				if(GetField_Int(hRec,"acr_ind",&iACR)){
					PutField_Int(hDetail,"acr_ind",iACR);
DEBUGLOG(("VoidAffectFx() acr_ind = [%d]\n",iACR));
				}

				if(!strcmp(csACRType,PD_TYPE_ENTITY_FX)){
					//get entity fx change history
					DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBalHistory","GetFXBalHistory");
					iRet = (unsigned long)(*DBObjPtr)(hDetail, rHistSet);
					if(iRet == PD_OK){
						hHist = RecordSet_GetFirst(rHistSet);
						while (hHist && (iRet == PD_OK)) {
							if(cDirection == PD_FUNDS_OUT){
								iRet = VoidRemitEntityFx(hDetail,hHist);
							}
							else{
								iRet = VoidRecvEntityFx(hDetail,hHist);
							}

							hHist = RecordSet_GetNext(rHistSet);
						}
					}
				}
				else if(!strcmp(csACRType,PD_TYPE_ACR)){
					//get acr fx change history
					DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBalHistory","GetAcrBalHistory");
					iRet = (unsigned long)(*DBObjPtr)(hDetail, rHistSet);
					if(iRet == PD_OK){
						hHist = RecordSet_GetFirst(rHistSet);
						while (hHist && (iRet == PD_OK)) {
							if(cDirection == PD_FUNDS_OUT){
								iRet = VoidRemitACR(hDetail,hHist);
							}
							else{
								iRet = VoidRecvACR(hDetail,hHist);
							}

							hHist = RecordSet_GetNext(rHistSet);
						}
					}
				}
				else{
DEBUGLOG(("VoidAffectFx() Not Affect Any ACR Pool. Do nothing\n"));
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else{
			iRet = INT_ERR;
DEBUGLOG(("VoidAffectFx() GetAffectFXDT Failed!!!!!\n"));
ERRLOG("BOMMSAverageCostRate::VoidAffectFx() GetAffectFXDT Failed!!!!!\n");
		}
		
	}


	RecordSet_Destroy(rRecordSet);
	RecordSet_Destroy(rHistSet);
	FREE_ME(rRecordSet);
	FREE_ME(rHistSet);
	FREE_ME(hDetail);
	FREE_ME(csACRType);

DEBUGLOG(("VoidAffectFx:: () Noraml Exit iRet = [%d]\n",iRet));
	return iRet;
}



int VoidRemitEntityFx(const hash_t* hDtl, const hash_t* hHist)
{
	int	iRet = PD_OK;
	char	*csFxId;
	char	*csEntityId;
	char	*csFromCcy;
	char	*csToCcy;
	char	*csHistFromCcy;
	char	*csHistToCcy;
	char	*csTmp;
	int	iTmp = 0;
	int	iACR = 0;
	double	dFromAmt = 0.0;
	double	dAmt = 0.0;
	char	cTmp;
	double	dHistOldRate = 0.0;
	//double	dHistNewRate = 0.0;
	//double	dHistNewBal = 0.0;
	double	dHistOldBal = 0.0;
	double	dNowRate = 0.0;
	double	dNowBalance = 0.0;
	double	dNewRate = 0.0;
	double	dNewBalance = 0.0;

	hash_t	*hBal;
	hBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hBal,0);

	hash_t	*hOrgDetail;
	hOrgDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgDetail,0);

	if(GetField_CString(hDtl,"txn_seq",&csFxId)){
		PutField_CString(hBal,"fx_id",csFxId);
	}
	if(GetField_Int(hDtl,"fx_seq",&iTmp)){
		PutField_Int(hBal,"fx_seq",iTmp);
	}
	if(GetField_CString(hDtl,"entity_id",&csEntityId)){
		PutField_CString(hBal,"entity_id",csEntityId);
	}
	if(GetField_CString(hDtl,"org_ccy",&csFromCcy)){
		PutField_CString(hBal,"org_ccy",csFromCcy);
		GetField_Double(hDtl,"org_amount",&dFromAmt);
		PutField_Double(hBal,"org_amount",dFromAmt);
	}
	if(GetField_CString(hDtl,"ccy",&csToCcy)){
		PutField_CString(hBal,"ccy",csToCcy);
		GetField_Double(hDtl,"amount",&dAmt);
		PutField_Double(hBal,"amount",dAmt);
	}
	if(GetField_Int(hDtl,"acr_ind",&iACR)){
		PutField_Int(hBal,"acr_ind",iACR);
	}
	if(GetField_Char(hDtl,"direction",&cTmp)){
		if(cTmp == PD_FUNDS_OUT)
			PutField_Char(hBal,"direction", PD_FUNDS_IN);
		else
			PutField_Char(hBal,"direction", PD_FUNDS_OUT);
	}
	if(GetField_CString(hDtl,"update_user",&csTmp)){
		PutField_CString(hBal,"create_user",csTmp);
		PutField_CString(hBal,"update_user",csTmp);
	}

	if(GetField_CString(hHist,"org_ccy",&csHistFromCcy) &&
	   GetField_CString(hHist,"ccy",&csHistToCcy)){
		//get rate and balance 
		PutField_CString(hBal,"org_ccy",csHistFromCcy);
		PutField_CString(hBal,"ccy",csHistToCcy);

		iRet = GetEntityFxBalForUpdate(hBal,hOrgDetail);
		if(iRet == PD_OK){
			GetField_Double(hOrgDetail,"rate",&dNowRate);
			PutField_Double(hBal,"old_rate",dNowRate);

			GetField_Double(hOrgDetail,"bal",&dNowBalance);
			PutField_Double(hBal,"old_bal",dNowBalance);
DEBUGLOG(("Current fx rate [%s->%s] = [%lf], Balance = [%lf]\n",csHistFromCcy,csHistToCcy,dNowRate,dNowBalance));
		}
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("VoidRemitEntityFx() history currency is missing!!!\n"));
	}

	if(iRet==PD_OK){
		GetField_Double(hHist,"old_bal",&dHistOldBal);
		//GetField_Double(hHist,"new_bal",&dHistNewBal);
		//GetField_Double(hHist,"new_rate",&dHistNewRate);
		if(!GetField_Double(hHist,"old_rate",&dHistOldRate)){
			if(dHistOldBal != 0.0){
				iRet = INT_ERR;
DEBUGLOG(("VoidRemitEntityFx() old_rate is missing!!!\n"));
			}
		}
	}

	if(iRet==PD_OK){
		PutField_Int(hBal,"calculate_ind",PD_TRUE);
		DBObjPtr = CreateObj(DBPtr,"DBMmsAffectFXDT","Add");
		if((unsigned long)(*DBObjPtr)(hBal)!=PD_OK){
			iRet = INT_ERR;
DEBUGLOG(("VoidRemitEntityFx() DBMmsAffectFXDT:Add Failed!!!\n"));
ERRLOG("BOMMSAverageCostRate: VoidRemitEntityFx() DBMmsAffectFXDT:Add Failed!!!\n");
		}
	}

	if(iRet==PD_OK){
		dNewBalance = newround(dNowBalance + dAmt,PD_DECIMAL_LEN);

		if(iACR){
			if(dHistOldRate==0.0){
				dHistOldRate = 1.0;
				dAmt = 0.0;
				dNewBalance = dNowBalance;
			}
			dNewRate = CreditFormula(dNewBalance,
					    	    dNowBalance,dNowRate,
						    dAmt,dHistOldRate);
		}
		else{
			dNewRate = dNowRate;
		}
DEBUGLOG(("[%s->%s] New Balance = [%lf], New Rate = [%lf]\n",csHistFromCcy,csHistToCcy,dNewBalance,dNewRate));

		PutField_Double(hBal,"bal",dNewBalance);
		PutField_Double(hBal,"new_bal",dNewBalance);
		PutField_Double(hBal,"rate",dNewRate);
		PutField_Double(hBal,"new_rate",dNewRate);

		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBal","Update");
		iRet = (unsigned long)(*DBObjPtr)(hBal);
		if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBal: Update() Failed!!!!\n"));
		}
		else{
			DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBalHistory","Add");
			iRet = (unsigned long)(*DBObjPtr)(hBal);
			if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBalHistory: Add() Failed!!!!\n"));
			}
		}
	}

	FREE_ME(hBal);
	FREE_ME(hOrgDetail);
DEBUGLOG(("VoidRemitEntityFx:: () Noraml Exit iRet = [%d]\n",iRet));
	return iRet;
}



int VoidRecvEntityFx(const hash_t* hDtl, const hash_t* hHist)
{
	int	iRet = PD_OK;
	char	*csFxId;
	char	*csEntityId;
	char	*csFromCcy;
	char	*csToCcy;
	char	*csHistFromCcy;
	char	*csHistToCcy;
	char	*csTmp;
	int	iTmp = 0;
	int	iACR = 0;
	double	dFromAmt = 0.0;
	double	dAmt = 0.0;
	char	cTmp;
	double	dHistOldRate = 0.0;
	double	dHistNewRate = 0.0;
	double	dHistOldBal = 0.0;
	double	dHistNewBal = 0.0;
	double	dNowRate = 0.0;
	double	dNowBalance = 0.0;
	double	dNewRate = 0.0;
	double	dNewBalance = 0.0;

	hash_t	*hBal;
	hBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hBal,0);

	hash_t	*hOrgDetail;
	hOrgDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgDetail,0);

	if(GetField_CString(hDtl,"txn_seq",&csFxId)){
		PutField_CString(hBal,"fx_id",csFxId);
	}
	if(GetField_Int(hDtl,"fx_seq",&iTmp)){
		PutField_Int(hBal,"fx_seq",iTmp);
	}
	if(GetField_CString(hDtl,"entity_id",&csEntityId)){
		PutField_CString(hBal,"entity_id",csEntityId);
	}
	if(GetField_CString(hDtl,"org_ccy",&csFromCcy)){
		PutField_CString(hBal,"org_ccy",csFromCcy);
		GetField_Double(hDtl,"org_amount",&dFromAmt);
		PutField_Double(hBal,"org_amount",dFromAmt);
	}
	if(GetField_CString(hDtl,"ccy",&csToCcy)){
		PutField_CString(hBal,"ccy",csToCcy);
		GetField_Double(hDtl,"amount",&dAmt);
		PutField_Double(hBal,"amount",dAmt);
	}
	if(GetField_Int(hDtl,"acr_ind",&iACR)){
		PutField_Int(hBal,"acr_ind",iACR);
	}
	if(GetField_Char(hDtl,"direction",&cTmp)){
		if(cTmp == PD_FUNDS_OUT)
			PutField_Char(hBal,"direction", PD_FUNDS_IN);
		else
			PutField_Char(hBal,"direction", PD_FUNDS_OUT);
	}
	if(GetField_CString(hDtl,"update_user",&csTmp)){
		PutField_CString(hBal,"create_user",csTmp);
		PutField_CString(hBal,"update_user",csTmp);
	}

	if(GetField_CString(hHist,"org_ccy",&csHistFromCcy) &&
	   GetField_CString(hHist,"ccy",&csHistToCcy)){
		//get rate and balance 
		PutField_CString(hBal,"org_ccy",csHistFromCcy);
		PutField_CString(hBal,"ccy",csHistToCcy);

		iRet = GetEntityFxBalForUpdate(hBal,hOrgDetail);
		if(iRet == PD_OK){
			GetField_Double(hOrgDetail,"rate",&dNowRate);
			PutField_Double(hBal,"old_rate",dNowRate);

			GetField_Double(hOrgDetail,"bal",&dNowBalance);
			PutField_Double(hBal,"old_bal",dNowBalance);
DEBUGLOG(("Current fx rate [%s->%s] = [%lf], Balance = [%lf]\n",csHistFromCcy,csHistToCcy,dNowRate,dNowBalance));
		}
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("VoidRecvEntityFx() history currency is missing!!!\n"));
	}

	if(dNowBalance < dAmt){
		iRet = INT_MMS_INSUFFICIENT_TXN_AMT;
DEBUGLOG(("VoidRecvEntityFx() Not enough balance to void!!!\n"));
	}

	if(iRet==PD_OK){
		GetField_Double(hHist,"old_bal",&dHistOldBal);
		GetField_Double(hHist,"new_bal",&dHistNewBal);
		GetField_Double(hHist,"new_rate",&dHistNewRate);
		if(!GetField_Double(hHist,"old_rate",&dHistOldRate)){
			if(dHistOldBal != 0.0){
				iRet = INT_ERR;
DEBUGLOG(("VoidRecvEntityFx() old_rate is missing!!!\n"));
			}
		}
	}

	if(iRet==PD_OK){
		PutField_Int(hBal,"calculate_ind",PD_TRUE);
		DBObjPtr = CreateObj(DBPtr,"DBMmsAffectFXDT","Add");
		if((unsigned long)(*DBObjPtr)(hBal)!=PD_OK){
			iRet = INT_ERR;
DEBUGLOG(("VoidRecvEntityFx() DBMmsAffectFXDT:Add Failed!!!\n"));
ERRLOG("BOMMSAverageCostRate: VoidRecvEntityFx() DBMmsAffectFXDT:Add Failed!!!\n");
		}
	}

	if(iRet==PD_OK){
		dNewBalance = newround(dNowBalance - dAmt,PD_DECIMAL_LEN);

		if(iACR){
			if(dHistOldRate==0.0){
				dHistOldRate = 1.0;
				dHistOldBal = 0.0;
			}

			if(dNowBalance==dHistNewBal &&
			   dNowRate==dHistNewRate &&
			   (dHistOldBal/dHistOldRate)==0.0){
				dNewRate = 1.0;
				dNewBalance = 0.0;
			}
			else{
				dNewRate = DebitFormula(dNewBalance,
							dNowBalance,dNowRate,
							dHistNewBal,dHistNewRate,
							dHistOldBal,dHistOldRate);
			}
		}
		else{
			dNewRate = dNowRate;
		}
DEBUGLOG(("[%s->%s] New Balance = [%lf], New Rate = [%lf]\n",csHistFromCcy,csHistToCcy,dNewBalance,dNewRate));

		PutField_Double(hBal,"bal",dNewBalance);
		PutField_Double(hBal,"new_bal",dNewBalance);
		PutField_Double(hBal,"rate",dNewRate);
		PutField_Double(hBal,"new_rate",dNewRate);

		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBal","Update");
		iRet = (unsigned long)(*DBObjPtr)(hBal);
		if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBal: Update() Failed!!!!\n"));
		}
		else{
			DBObjPtr = CreateObj(DBPtr,"DBMmsEntityFXBalHistory","Add");
			iRet = (unsigned long)(*DBObjPtr)(hBal);
			if(iRet != PD_OK){
DEBUGLOG(("DBMmsEntityFXBalHistory: Add() Failed!!!!\n"));
			}
		}
	}

	FREE_ME(hBal);
	FREE_ME(hOrgDetail);
DEBUGLOG(("VoidRecvEntityFx:: () Noraml Exit iRet = [%d]\n",iRet));
	return iRet;
}


int VoidRemitACR(const hash_t* hDtl, const hash_t* hHist)
{
	int	iRet = PD_OK;
	char	*csFxId;
	char	*csEntityId;
	char	*csFromCcy;
	char	*csToCcy;
	char	*csHistFromCcy;
	char	*csHistToCcy;
	char	*csTmp;
	int	iTmp = 0;
	int	iACR = 0;
	double	dFromAmt = 0.0;
	double	dAmt = 0.0;
	char	cTmp;
	double	dHistOldRate = 0.0;
	//double	dHistNewRate = 0.0;
	//double	dHistNewBal = 0.0;
	double	dHistOldBal = 0.0;
	double	dNowRate = 0.0;
	double	dNowBalance = 0.0;
	double	dNewRate = 0.0;
	double	dNewBalance = 0.0;

	hash_t	*hBal;
	hBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hBal,0);

	hash_t	*hOrgDetail;
	hOrgDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgDetail,0);

	if(GetField_CString(hDtl,"txn_seq",&csFxId)){
		PutField_CString(hBal,"fx_id",csFxId);
	}
	if(GetField_Int(hDtl,"fx_seq",&iTmp)){
		PutField_Int(hBal,"fx_seq",iTmp);
	}
	if(GetField_CString(hDtl,"entity_id",&csEntityId)){
		PutField_CString(hBal,"entity_id",csEntityId);
	}
	if(GetField_CString(hDtl,"org_ccy",&csFromCcy)){
		PutField_CString(hBal,"org_ccy",csFromCcy);
		GetField_Double(hDtl,"org_amount",&dFromAmt);
		PutField_Double(hBal,"org_amount",dFromAmt);
	}
	if(GetField_CString(hDtl,"ccy",&csToCcy)){
		PutField_CString(hBal,"ccy",csToCcy);
		GetField_Double(hDtl,"amount",&dAmt);
		PutField_Double(hBal,"amount",dAmt);
	}
	if(GetField_Int(hDtl,"acr_ind",&iACR)){
		PutField_Int(hBal,"acr_ind",iACR);
	}
	if(GetField_Char(hDtl,"direction",&cTmp)){
		if(cTmp == PD_FUNDS_OUT)
			PutField_Char(hBal,"direction", PD_FUNDS_IN);
		else
			PutField_Char(hBal,"direction", PD_FUNDS_OUT);
	}
	if(GetField_CString(hDtl,"update_user",&csTmp)){
		PutField_CString(hBal,"create_user",csTmp);
		PutField_CString(hBal,"update_user",csTmp);
	}

	if(GetField_CString(hHist,"org_ccy",&csHistFromCcy) &&
	   GetField_CString(hHist,"ccy",&csHistToCcy)){
		//get rate and balance 
		PutField_CString(hBal,"org_ccy",csHistFromCcy);
		PutField_CString(hBal,"ccy",csHistToCcy);

		iRet = GetACRBalForUpdate(hBal,hOrgDetail);
		if(iRet == PD_OK){
			GetField_Double(hOrgDetail,"rate",&dNowRate);
			PutField_Double(hBal,"old_rate",dNowRate);

			GetField_Double(hOrgDetail,"bal",&dNowBalance);
			PutField_Double(hBal,"old_bal",dNowBalance);
DEBUGLOG(("Current fx rate [%s->%s] = [%lf], Balance = [%lf]\n",csHistFromCcy,csHistToCcy,dNowRate,dNowBalance));
		}
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("VoidRemitEntityFx() history currency is missing!!!\n"));
	}

	if(iRet==PD_OK){
		GetField_Double(hHist,"old_bal",&dHistOldBal);
		//GetField_Double(hHist,"new_bal",&dHistNewBal);
		//GetField_Double(hHist,"new_rate",&dHistNewRate);
		if(!GetField_Double(hHist,"old_rate",&dHistOldRate)){
			if(dHistOldBal != 0.0){
				iRet = INT_ERR;
DEBUGLOG(("VoidRemitEntityFx() old_rate is missing!!!\n"));
			}
		}
	}

	if(iRet==PD_OK){
		PutField_Int(hBal,"calculate_ind",PD_TRUE);
		DBObjPtr = CreateObj(DBPtr,"DBMmsAffectFXDT","Add");
		if((unsigned long)(*DBObjPtr)(hBal)!=PD_OK){
			iRet = INT_ERR;
DEBUGLOG(("VoidRemitEntityFx() DBMmsAffectFXDT:Add Failed!!!\n"));
ERRLOG("BOMMSAverageCostRate: VoidRemitEntityFx() DBMmsAffectFXDT:Add Failed!!!\n");
		}
	}

	if(iRet==PD_OK){
		dNewBalance = newround(dNowBalance + dAmt,PD_DECIMAL_LEN);

		if(iACR){
			if(dHistOldRate==0.0){
				dHistOldRate = 1.0;
				dAmt = 0.0;
				dNewBalance = dNowBalance;
			}
			dNewRate = CreditFormula(dNewBalance,
					    	    dNowBalance,dNowRate,
						    dAmt,dHistOldRate);
		}
		else{
			dNewRate = dNowRate;
		}
DEBUGLOG(("[%s->%s] New Balance = [%lf], New Rate = [%lf]\n",csHistFromCcy,csHistToCcy,dNewBalance,dNewRate));

		PutField_Double(hBal,"bal",dNewBalance);
		PutField_Double(hBal,"new_bal",dNewBalance);
		PutField_Double(hBal,"rate",dNewRate);
		PutField_Double(hBal,"new_rate",dNewRate);

		DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBal","Update");
		iRet = (unsigned long)(*DBObjPtr)(hBal);
		if(iRet != PD_OK){
DEBUGLOG(("DBMmsAcrBal: Update() Failed!!!!\n"));
		}
		else{
			DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBalHistory","Add");
			iRet = (unsigned long)(*DBObjPtr)(hBal);
			if(iRet != PD_OK){
DEBUGLOG(("DBMmsAcrBalHistory: Add() Failed!!!!\n"));
			}
		}
	}

	FREE_ME(hBal);
	FREE_ME(hOrgDetail);
DEBUGLOG(("VoidRemitACR:: () Noraml Exit iRet = [%d]\n",iRet));
	return iRet;
}


int VoidRecvACR(const hash_t* hDtl, const hash_t* hHist)
{
	int	iRet = PD_OK;
	char	*csFxId;
	char	*csEntityId;
	char	*csFromCcy;
	char	*csToCcy;
	char	*csHistFromCcy;
	char	*csHistToCcy;
	char	*csTmp;
	int	iTmp = 0;
	int	iACR = 0;
	double	dFromAmt = 0.0;
	double	dAmt = 0.0;
	char	cTmp;
	double	dHistOldRate = 0.0;
	double	dHistNewRate = 0.0;
	double	dHistOldBal = 0.0;
	double	dHistNewBal = 0.0;
	double	dNowRate = 0.0;
	double	dNowBalance = 0.0;
	double	dNewRate = 0.0;
	double	dNewBalance = 0.0;

	hash_t	*hBal;
	hBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hBal,0);

	hash_t	*hOrgDetail;
	hOrgDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgDetail,0);

	if(GetField_CString(hDtl,"txn_seq",&csFxId)){
		PutField_CString(hBal,"fx_id",csFxId);
	}
	if(GetField_Int(hDtl,"fx_seq",&iTmp)){
		PutField_Int(hBal,"fx_seq",iTmp);
	}
	if(GetField_CString(hDtl,"entity_id",&csEntityId)){
		PutField_CString(hBal,"entity_id",csEntityId);
	}
	if(GetField_CString(hDtl,"org_ccy",&csFromCcy)){
		PutField_CString(hBal,"org_ccy",csFromCcy);
		GetField_Double(hDtl,"org_amount",&dFromAmt);
		PutField_Double(hBal,"org_amount",dFromAmt);
	}
	if(GetField_CString(hDtl,"ccy",&csToCcy)){
		PutField_CString(hBal,"ccy",csToCcy);
		GetField_Double(hDtl,"amount",&dAmt);
		PutField_Double(hBal,"amount",dAmt);
	}
	if(GetField_Int(hDtl,"acr_ind",&iACR)){
		PutField_Int(hBal,"acr_ind",iACR);
	}
	if(GetField_Char(hDtl,"direction",&cTmp)){
		if(cTmp == PD_FUNDS_OUT)
			PutField_Char(hBal,"direction", PD_FUNDS_IN);
		else
			PutField_Char(hBal,"direction", PD_FUNDS_OUT);
	}
	if(GetField_CString(hDtl,"update_user",&csTmp)){
		PutField_CString(hBal,"create_user",csTmp);
		PutField_CString(hBal,"update_user",csTmp);
	}

	if(GetField_CString(hHist,"org_ccy",&csHistFromCcy) &&
	   GetField_CString(hHist,"ccy",&csHistToCcy)){
		//get rate and balance 
		PutField_CString(hBal,"org_ccy",csHistFromCcy);
		PutField_CString(hBal,"ccy",csHistToCcy);

		iRet = GetACRBalForUpdate(hBal,hOrgDetail);
		if(iRet == PD_OK){
			GetField_Double(hOrgDetail,"rate",&dNowRate);
			PutField_Double(hBal,"old_rate",dNowRate);

			GetField_Double(hOrgDetail,"bal",&dNowBalance);
			PutField_Double(hBal,"old_bal",dNowBalance);
DEBUGLOG(("Current fx rate [%s->%s] = [%lf], Balance = [%lf]\n",csHistFromCcy,csHistToCcy,dNowRate,dNowBalance));
		}
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("VoidRecvACR() history currency is missing!!!\n"));
	}

	if(dNowBalance < dAmt){
		iRet = INT_MMS_INSUFFICIENT_TXN_AMT;
DEBUGLOG(("VoidRecvACR() Not enough balance to void!!!\n"));
	}

	if(iRet==PD_OK){
		GetField_Double(hHist,"old_bal",&dHistOldBal);
		GetField_Double(hHist,"new_bal",&dHistNewBal);
		GetField_Double(hHist,"new_rate",&dHistNewRate);
		if(!GetField_Double(hHist,"old_rate",&dHistOldRate)){
			if(dHistOldBal != 0.0){
				iRet = INT_ERR;
DEBUGLOG(("VoidRecvACR() old_rate is missing!!!\n"));
			}
		}
	}

	if(iRet==PD_OK){
		PutField_Int(hBal,"calculate_ind",PD_TRUE);
		DBObjPtr = CreateObj(DBPtr,"DBMmsAffectFXDT","Add");
		if((unsigned long)(*DBObjPtr)(hBal)!=PD_OK){
			iRet = INT_ERR;
DEBUGLOG(("VoidRecvACR() DBMmsAffectFXDT:Add Failed!!!\n"));
ERRLOG("BOMMSAverageCostRate: VoidRecvACR() DBMmsAffectFXDT:Add Failed!!!\n");
		}
	}

	if(iRet==PD_OK){
		dNewBalance = newround(dNowBalance - dAmt,PD_DECIMAL_LEN);

		if(iACR){
			if(dHistOldRate==0.0){
				dHistOldRate = 1.0;
				dHistOldBal = 0.0;
			}

			if(dNowBalance==dHistNewBal &&
			   dNowRate==dHistNewRate &&
			   (dHistOldBal/dHistOldRate)==0.0){
				dNewRate = 1.0;
				dNewBalance = 0.0;
			}
			else{
				dNewRate = DebitFormula(dNewBalance,
							dNowBalance,dNowRate,
							dHistNewBal,dHistNewRate,
							dHistOldBal,dHistOldRate);
			}
		}
		else{
			dNewRate = dNowRate;
		}
DEBUGLOG(("[%s->%s] New Balance = [%lf], New Rate = [%lf]\n",csHistFromCcy,csHistToCcy,dNewBalance,dNewRate));

		PutField_Double(hBal,"bal",dNewBalance);
		PutField_Double(hBal,"new_bal",dNewBalance);
		PutField_Double(hBal,"rate",dNewRate);
		PutField_Double(hBal,"new_rate",dNewRate);

		DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBal","Update");
		iRet = (unsigned long)(*DBObjPtr)(hBal);
		if(iRet != PD_OK){
DEBUGLOG(("DBMmsAcrBal: Update() Failed!!!!\n"));
		}
		else{
			DBObjPtr = CreateObj(DBPtr,"DBMmsAcrBalHistory","Add");
			iRet = (unsigned long)(*DBObjPtr)(hBal);
			if(iRet != PD_OK){
DEBUGLOG(("DBMmsAcrBalHistory: Add() Failed!!!!\n"));
			}
		}
	}

	FREE_ME(hBal);
	FREE_ME(hOrgDetail);
DEBUGLOG(("VoidRecvACR:: () Noraml Exit iRet = [%d]\n",iRet));
	return iRet;
}


double CreditFormula(const double dNumeratorTop,
		     const double dNumeratorLow1, const double dDenominatorLow1,
		     const double dNumeratorLow2, const double dDenominatorLow2)
{
	double dNewValue = 0.0;

	dNewValue = newround(dNumeratorTop/((dNumeratorLow1/dDenominatorLow1) + (dNumeratorLow2/dDenominatorLow2)),PD_ROUND_UP_DEC);
DEBUGLOG(("CreditFormula(): [%lf/((%lf/%lf) + (%lf/%lf))] = [%lf]\n",dNewValue));

	return dNewValue;
}


double DebitFormula(const double dNumeratorTop,
		    const double dNumeratorLow1, const double dDenominatorLow1,
		    const double dNumeratorLow2, const double dDenominatorLow2,
		    const double dNumeratorLow3, const double dDenominatorLow3)
{
	double dNewValue = 0.0;

	dNewValue = newround(dNumeratorTop/((dNumeratorLow1/dDenominatorLow1) - ((dNumeratorLow2/dDenominatorLow2) - (dNumeratorLow3/dDenominatorLow3))),PD_ROUND_UP_DEC);
DEBUGLOG(("CreditFormula(): [%lf/((%lf/%lf) - ((%lf/%lf) - (%lf/%lf)))] = [%lf]\n",dNewValue));

	return dNewValue;
}
