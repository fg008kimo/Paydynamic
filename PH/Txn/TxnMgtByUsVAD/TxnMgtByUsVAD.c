/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/01/27              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsVAD.h"
#include "myrecordset.h"
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMgtByUsVAD(char    cdebug)
{
        cDebug = cdebug;
}

int GetTxnInfo(const unsigned char *csTxnSeq,
                hash_t * hTxn);


int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iTmpRet;

	char	*csTmp;
	char	*csOrgTxnSeq;
	char	*csOrgTxnCode;
	char	*csUser;

	double  dTmp = 0.0;
	char	cTmp;

	char	cPartyType;
	int	iTmp;
	char	cDCInd;

        char    csVoidTxnCode[PD_TXN_CODE_LEN + 1];

        hash_t  *hOrgTxn; // for update org txn header
        hOrgTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hOrgTxn,0);

	hash_t  *hVoidTxn; // for this void txn
        hVoidTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hVoidTxn,0);

	memset(csVoidTxnCode, 0, sizeof(csVoidTxnCode));

DEBUGLOG(("TxnMgtByUsVAD: Authroize()\n"));

	if (GetField_CString(hRequest,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("Authorize::org_txn_seq = [%s]\n",csOrgTxnSeq));
		PutField_CString(hOrgTxn, "txn_seq", csOrgTxnSeq);
                PutField_CString(hContext,"org_txn_seq",csOrgTxnSeq);	
	}

        if (GetField_CString(hContext,"txn_seq",&csTmp)) {
DEBUGLOG(("Authorize::txn_seq  = [%s]\n",csTmp));
		PutField_CString(hVoidTxn, "txn_seq", csTmp);
		PutField_CString(hVoidTxn, "from_txn_seq", csTmp);
        }


        if (GetField_CString(hRequest,"org_txn_code",&csOrgTxnCode)) {
DEBUGLOG(("Authorize::org_txn_code  = [%s]\n",csOrgTxnCode));
		PutField_CString(hVoidTxn, "code", csOrgTxnCode);
		PutField_CString(hVoidTxn, "org_txn_code", csOrgTxnCode);

		cPartyType= csOrgTxnCode[0];

DEBUGLOG(("Authorize::OrgTxnCode Prefix  = [%c]\n",cPartyType));
		PutField_Char(hVoidTxn, "party_type", toupper(cPartyType));

		if (toupper(cPartyType) == PD_TYPE_PSP) {
			sprintf(csVoidTxnCode, "%c%s", PD_ADJ_VOID_PSP_PREFIX, csOrgTxnCode + 1);
		} else if (toupper(cPartyType) == PD_TYPE_MERCHANT) {
			sprintf(csVoidTxnCode, "%c%s", PD_ADJ_VOID_MERCH_PREFIX, csOrgTxnCode + 1);
		} else {
			iRet = INT_ERR;
                	PutField_Int(hContext,"internal_error",iRet);
		}

DEBUGLOG(("Authorize::VoidTxnCode = [%s]\n",csVoidTxnCode));

		PutField_CString(hContext,"new_txn_code", csVoidTxnCode);
  
	}

	if (GetField_CString(hRequest, "merchant_id", &csTmp)) {
DEBUGLOG(("Authorize::merchant_id = [%s]\n", csTmp)); 
		PutField_CString(hVoidTxn, "merchant_id", csTmp);
		PutField_CString(hContext, "merchant_id", csTmp);
	}

	if (GetField_CString(hContext, "merchant_client_id", &csTmp)) {
DEBUGLOG(("Authorize::merchant_client_id = [%s]\n", csTmp)); 
		PutField_CString(hVoidTxn, "client_id", csTmp);
	}

/*
	if (GetField_Double(hRequest, "adj_txn_amt", &dTmp)) {
DEBUGLOG(("Authorize:: adj_txn_amt = [%lf]\n", dTmp)); 
		PutField_Double(hVoidTxn, "txn_amt", dTmp);
		PutField_Double(hContext, "txn_amt", dTmp);
	}

        if (GetField_Double(hRequest, "adj_net_amt", &dTmp)) {
DEBUGLOG(("Authorize:: adj_net_amt = [%lf]\n", dTmp));
		PutField_Double(hVoidTxn, "net_amt", dTmp);
                PutField_Double(hContext, "net_amt", dTmp);
        }
*/


	if (GetField_CString(hRequest, "service_code", &csTmp)) {
DEBUGLOG(("Authorize::service_code = [%s]\n", csTmp)); 
		PutField_CString(hVoidTxn, "service_code", csTmp);
		PutField_CString(hContext, "service_code", csTmp);
	}


	if (GetField_CString(hContext, "PHDATE", &csTmp)) {
DEBUGLOG(("Authorize::txn_date = [%s]\n", csTmp)); 

		PutField_CString(hContext, "approval_date", csTmp);

		PutField_CString(hVoidTxn, "txn_date", csTmp);
		PutField_CString(hVoidTxn, "approval_date", csTmp);
	}

        if (GetField_CString(hRequest,"add_user",&csUser)) {
                PutField_CString(hContext,"update_user",csUser);
                PutField_CString(hOrgTxn,"update_user",csUser);

                PutField_CString(hVoidTxn,"add_user",csUser);
                PutField_CString(hVoidTxn,"update_user",csUser);
DEBUGLOG(("Authorize::add_user = [%s]\n",csUser));
        }

	PutField_Char(hOrgTxn,"status",PD_REVERSED);
	PutField_Int(hVoidTxn, "void_flag", PD_TRUE);

	iRet = GetTxnInfo((const unsigned char*)csOrgTxnSeq, hVoidTxn);

	if (iRet != PD_OK) {
                PutField_Int(hContext,"internal_error",iRet);
	}

	if (iRet == PD_OK) {
		if (GetField_Double(hVoidTxn, "txn_amt", &dTmp)) {
                	PutField_Double(hContext, "txn_amt", dTmp);
                	PutField_Double(hVoidTxn, "org_txn_amt", dTmp);
		}

		if (GetField_Double(hVoidTxn, "src_txn_fee", &dTmp)) {
	        	PutField_Double(hContext, "src_txn_fee", dTmp);
		}

		if (GetField_CString(hVoidTxn, "txn_ccy", &csTmp)) {
                	PutField_CString(hVoidTxn, "src_txn_fee_ccy", csTmp);
                	PutField_CString(hVoidTxn, "org_txn_ccy", csTmp);
		}

DEBUGLOG(("Authorize::Call BOAdjustment:ProcessPartyBalance\n"));
                BOObjPtr = CreateObj(BOPtr,"BOAdjustment","ProcessPartyBalance");
                iRet = (unsigned long)((*BOObjPtr)(hVoidTxn));

                if (iRet != PD_OK) {
DEBUGLOG(("Authorize::BOAdjustment:ProcessPartyBalance Failed Ret [%d]\n", iRet));
ERRLOG("TxnMgtByUsVAD::BOADjustment::ProcesspartyBalance Failed Ret [%d]\n", iRet);
                }
		else {
DEBUGLOG(("Authorize::BOAdjustment:ProcessPartyBalance SUCC\n"));

			if (GetField_Double(hVoidTxn, "merchant_open_bal", &dTmp)) {
                		PutField_Double(hVoidTxn, "open_bal", dTmp);
			}

			if (GetField_Double(hVoidTxn, "merchant_open_bal_settlement", &dTmp)) {
                		PutField_Double(hVoidTxn, "open_bal_settlement", dTmp);
			}

			if (GetField_Double(hVoidTxn, "net_amt", &dTmp)) {
                		PutField_Double(hContext, "net_amt", dTmp);
			}

			GetField_Char(hVoidTxn, "dc_ind", &cDCInd);

DEBUGLOG(("Authorize::BOAdjustment:ProcessPartyBalance dc_ind [%c] net_amt [%lf]\n", cDCInd, dTmp));

			if (GetField_Double(hVoidTxn, "header_net_amt", &dTmp)) {
				PutField_Double(hContext, "net_amt", dTmp);
			}

			if (GetField_CString(hVoidTxn, "net_ccy", &csTmp)) {
				PutField_CString(hContext, "net_ccy", csTmp);
			}

			if (GetField_Char(hVoidTxn, "ex_supplier", &cTmp)) {
				PutField_Char(hContext, "ex_party", cTmp);
			}

			if (GetField_Double(hVoidTxn, "ex_rate", &dTmp)) {
				PutField_Double(hContext, "ex_rate", dTmp);
			}
		}

		if (GetField_Int(hVoidTxn, "internal_error", &iTmpRet)) {
			PutField_Int(hContext, "internal_error", iTmpRet);
		}
        }

       if(GetField_Int(hContext,"do_logging",&iTmp)){
DEBUGLOG(("Authorize::do_logging [%d]\n", iTmp));
                if(iTmp!=PD_ADD_LOG) {
                        /* nothing */
                }

		if (iRet==PD_OK) {
DEBUGLOG(("Authorize::Call Update Org Transaction\n"));
			PutField_CString(hOrgTxn,"sub_status",PD_VOID);
			DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
			if((unsigned long) ((*DBObjPtr)(hOrgTxn))!=PD_OK) {
				iRet = INT_ERR;
			}


			if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:AddDetail\n"));
                        	DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
	                        if((unsigned long) ((*DBObjPtr)(hVoidTxn))!=PD_OK){
					iRet = INT_ERR;
				}
			}

		        if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:UpdateDetail\n"));
                        	DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
		                if((unsigned long) ((*DBObjPtr)(hVoidTxn))!=PD_OK) {
	               			iRet = INT_ERR;
				}
                	}


			/* for psp txn log - TxnPspDetail */
			if (GetField_CString(hVoidTxn, "psp_id", &csTmp)) {
				if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBTxnPspDetail:Add\n"));
					PutField_CString(hVoidTxn, "desc", "Void Psp Adjustment");

					DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
					if((unsigned long) ((*DBObjPtr)(hVoidTxn))!=PD_OK) {
						iRet = INT_ERR;
					}
				}

				if (iRet==PD_OK) {
DEBUGLOG(("Authorize::Call DBTxnPspDetail:Update\n"));
					DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
					if((unsigned long) ((*DBObjPtr)(hVoidTxn))!=PD_OK) {
						iRet = INT_ERR;
                			}
        			}
			}
		 	
		}
/*

		if (iRet == PD_OK) {
			if (GetField_Double(hVoidTxn, "src_txn_fee", &dTmp)) {
				PutField_Double(hVoidTxn, "amount", dTmp);
			}

			PutField_CString(hVoidTxn,"amount_type",PD_CR);

DEBUGLOG(("Authorize::Call BOTxnElements:AddTxnFeeElements\n"));
                	BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnFeeElements");
			if ((unsigned long)((*BOObjPtr)(hVoidTxn)) != PD_OK) {
                        	iRet = INT_ERR;
                	}
        	}

        	if (iRet == PD_OK) {
			if (GetField_Double(hVoidTxn, "txn_amt", &dTmp)) {
				PutField_Double(hVoidTxn, "amount", dTmp);
			}
		
			if (cDCInd == PD_ADJ_TYPE_CREDIT) {
				PutField_CString(hVoidTxn,"amount_type", PD_DR);
		        } else {
				PutField_CString(hVoidTxn,"amount_type", PD_CR);
			} 

DEBUGLOG(("Authorize::Call BOTxnElements:AddTxnAmtElement\n"));
	                BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnAmtElement");
			if ((unsigned long)((*BOObjPtr)(hVoidTxn)) != PD_OK) {
				iRet = INT_ERR;
                	}
        	}
*/



	}


	hash_destroy(hOrgTxn);
	hash_destroy(hVoidTxn);

	FREE_ME(hOrgTxn);
	FREE_ME(hVoidTxn);

/*
	if(iRet!=PD_OK){
                PutField_Int(hContext,"internal_error",iRet);
        }
*/

DEBUGLOG(("Normal exit iRet = [%d]\n",iRet));	
	return iRet;
}

int GetTxnInfo(const unsigned char *csTxnSeq, hash_t *hTxn)
{
	int     iRet = PD_OK;

	char    *csTmp;
//	double  dTmp = 0.0;
	char	cTmp;

        hash_t  *hRec;

	double  dTmp = 0.0;
	double  dTxnAmt = 0.0;
	double  dTxnFee = 0.0;


        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);


	if (iRet == PD_OK) {
        	RecordSet_Destroy(rRecordSet);
                recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo::Call DBTransaction:GetTxnHeader\n"));

		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
		if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnHeader::found record = [%s]\n",csTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
                                if (GetField_Double(hRec,"net_amt",&dTmp)) {
                                        PutField_Double(hTxn,"header_net_amt",dTmp);
DEBUGLOG(("GetTxnHeader::net_amt = [%lf]\n",dTmp));
                                }

                                if (GetField_CString(hRec,"net_ccy",&csTmp)) {
                                        PutField_CString(hTxn,"net_ccy",csTmp);
DEBUGLOG(("GetTxnHeader::net_ccy = [%s]\n",csTmp));
                                }
                                if (GetField_Char(hRec, "ex_supplier", &cTmp)) {
                                        PutField_Char(hTxn,"ex_supplier",cTmp);
DEBUGLOG(("GetTxnHeader::ex_supplier = [%c]\n",cTmp));
                                }
                                if (GetField_Double(hRec, "ex_rate", &dTmp)) {
                                        PutField_Double(hTxn,"ex_rate",dTmp);
DEBUGLOG(("GetTxnHeader::ex_rate = [%lf]\n",dTmp));
                                }

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
                else{
DEBUGLOG(("GetTxnHeader:: not found record for [%s]\n",csTxnSeq));
ERRLOG("TxnMgtByUsVAD:Authorize::GetTxnHeader::not found record!!\n");
                        iRet=INT_NOT_RECORD;
                }
	}


	if (iRet == PD_OK) {
        	RecordSet_Destroy(rRecordSet);
                recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo::Call DBTransaction:GetTxnDetail\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
                if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnInfo::GetTxnDetail::found record = [%s]\n",csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                if (GetField_CString(hRec,"txn_ccy",&csTmp)) {
                                        PutField_CString(hTxn,"txn_ccy",csTmp);
DEBUGLOG(("GetTxnInfo::GetTxnDetail::txn_ccy = [%s]\n",csTmp));
                                }

                                if (GetField_CString(hRec,"txn_country",&csTmp)) {
                                        PutField_CString(hTxn,"txn_country",csTmp);
DEBUGLOG(("GetTxnInfo::GetTxnDetail::txn_country = [%s]\n",csTmp));
                                }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                else{
DEBUGLOG(("GetTxnInfo::GetTxnDetail:: not found record for [%s]\n",csTxnSeq));
ERRLOG("TxnMgtByUsVAD::GetTxnInfo::GetTxnDetail::not found record!!\n");
                        iRet=INT_NOT_RECORD;
                }
	}
	
	if (iRet == PD_OK) {
		if (GetField_CString(hTxn, "org_txn_code", &csTmp)) {
			cTmp = toupper(csTmp[0]);

			if (cTmp == PD_TYPE_PSP) {
                		RecordSet_Destroy(rRecordSet);
		                recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo::Call DBTxnPspDetail:GetTxnPspDetail\n"));
                		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
                		if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnInfo::GetTxnPspDetail::found record = [%s]\n",csTxnSeq));
       	                 		hRec = RecordSet_GetFirst(rRecordSet);
		                        while (hRec) {
						if (GetField_CString(hRec, "psp_id", &csTmp)) {
                                        		PutField_CString(hTxn,"psp_id",csTmp);
DEBUGLOG(("GetTxnInfo::GetTxnPspDetail::psp_id = [%s]\n",csTmp));
						}
	
                                		hRec = RecordSet_GetNext(rRecordSet);
					}
				}
			}
		}
                else{
DEBUGLOG(("GetTxnInfo::GetTxnPspDetail:: not found record for [%s]\n",csTxnSeq));
ERRLOG("TxnMgtByUsVAD::GetTxnInfo::GetTxnPspDetail::not found record!!\n");
                        iRet=INT_NOT_RECORD;
                }
	}	

	if (iRet == PD_OK) {

		if (GetField_CString(hTxn, "org_txn_code", &csTmp)) {
			cTmp = toupper(csTmp[0]);

                	RecordSet_Destroy(rRecordSet);
	                recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo::Call DBTxnElements:GetFeeChgDetailByType [%s]\n", PD_ELEMENT_TXN_AMT));

			DBObjPtr = CreateObj(DBPtr,"DBTxnElements","GetFeeChgDetailByType");
			if ((*DBObjPtr)(csTxnSeq, PD_ELEMENT_TXN_AMT, cTmp, rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnInfo::GetFeeChgDetailByType::[%s] found record = [%s]\n",PD_ELEMENT_TXN_AMT, csTxnSeq));
                                        hRec = RecordSet_GetFirst(rRecordSet);
                                        while (hRec) {
                                                if (GetField_Double(hRec, "amount", &dTmp)) {
							dTxnAmt += dTmp;
						}
                                                hRec = RecordSet_GetNext(rRecordSet);
                                        }
DEBUGLOG(("GetTxnInfo::GetFeeChgDetailByType::[%s] dTxnAmt = [%lf]\n",PD_ELEMENT_TXN_AMT, dTxnAmt));

					PutField_Double(hTxn, "txn_amt", dTxnAmt);
			}
                	else{
DEBUGLOG(("GetTxnInfo::GetFeeChgDetailByType:: [%s] not found record for [%s]\n",PD_ELEMENT_TXN_AMT, csTxnSeq));
ERRLOG("TxnMgtByUsVAD::GetTxnInfo::GetFeeChgDetailByType:: [%s] not found record for [%s]!!\n", PD_ELEMENT_TXN_AMT, csTxnSeq);
	                        iRet=INT_NOT_RECORD;
			}
		}

		if (iRet == PD_OK) {
			RecordSet_Destroy(rRecordSet);
                        recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo::Call DBTxnElements:GetFeeChgDetailByType [%s]\n",  PD_ELEMENT_TXN_FEE ));
                        DBObjPtr = CreateObj(DBPtr,"DBTxnElements","GetFeeChgDetailByType");
                        if ((*DBObjPtr)(csTxnSeq,  PD_ELEMENT_TXN_FEE , cTmp, rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnInfo::GetFeeChgDetailByType::[%s] found record = [%s]\n", PD_ELEMENT_TXN_FEE, csTxnSeq));
                        	hRec = RecordSet_GetFirst(rRecordSet);
                                while (hRec) {
                                	if (GetField_Double(hRec, "amount", &dTmp)) {
                                        	dTxnFee += dTmp;
                                        }
                                        hRec = RecordSet_GetNext(rRecordSet);
                                }
DEBUGLOG(("GetTxnInfo::GetFeeChgDetailByType::[%s] dTxnFee = [%lf]\n", PD_ELEMENT_TXN_FEE , dTxnFee));
				PutField_Double(hTxn, "src_txn_fee", dTxnFee);
                        }
                        else{
DEBUGLOG(("GetTxnInfo::GetFeeChgDetailByType:: [%s] not found record for [%s]\n", PD_ELEMENT_TXN_FEE , csTxnSeq));
ERRLOG("TxnMgtByUsVAD::GetTxnInfo::GetFeeChgDetailByType:: [%s] not found record for [%s]!!\n",  PD_ELEMENT_TXN_FEE , csTxnSeq);
	                        iRet=INT_NOT_RECORD;
                        }

		}


	}

        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

	return iRet;

}
