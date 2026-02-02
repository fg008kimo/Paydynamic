/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/07/07              Cody Chan
Remove Txn Country				   2015/07/22		   Cody Chan
Remove Nature Detail				   2015/08/02		   Cody Chan
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
#include "common.h"
#include "BOMMSTransaction.h"

char    cDebug;
OBJPTR(DB);

void BOMMSTransaction(char    cdebug)
{
	cDebug = cdebug;
}


int     AddTxnLog(const hash_t *hContext,
                const hash_t* hRequest)
{
        int     iRet = PD_OK;
        int     iTmp;
        hash_t  *hTxn;
        char    *csPtr;
        char    cPtr;

	int	iCommit = PD_TRUE;

DEBUGLOG(("AddTxnLog()\n"));
        if(GetField_Int(hContext,"do_logging",&iTmp)){
                if(iTmp!=PD_ADD_LOG) {
DEBUGLOG(("AddTxnLog iGnore Logging Exit iRet = [%d]\n",iRet));
                        return iRet;
                }
        }


	if (GetField_Int(hContext,"db_commit",&iCommit)) {
DEBUGLOG(("AddTxnLog:db_commit = [%d]\n",iCommit));
        }
	else {
DEBUGLOG(("AddTxnLog:db_commit set to default \n"));
	}


        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);


	PutField_Int(hTxn,"db_commit",iCommit);

	
         if (GetField_CString(hContext,"txn_seq",&csPtr)) {
DEBUGLOG(("AddTxnLog:: txn_seq = [%s]\n",csPtr));
                PutField_CString(hTxn,"txn_seq",csPtr);

                if (GetField_CString(hContext,"action_txn_seq",&csPtr)) {
DEBUGLOG(("AddTxnLog:: action_txn_seq = [%s]\n",csPtr));
                        PutField_CString(hTxn,"action_txn_seq",csPtr);
                }

		if (GetField_CString(hContext,"add_user",&csPtr)) {
DEBUGLOG(("AddTxnLog:: add_user = [%s]\n",csPtr));
                	PutField_CString(hTxn,"add_user",csPtr);
		} else {
DEBUGLOG(("AddTxnLog:: add_user (default) = [%s]\n",PD_UPDATE_USER));
                	PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
		}

                if (GetField_CString(hContext,"org_txn_seq",&csPtr)) {
DEBUGLOG(("AddTxnLog:: org_txn_seq = [%s]\n",csPtr));
                        PutField_CString(hTxn,"org_txn_seq",csPtr);
                }

                if (GetField_CString(hContext,"channel_code",&csPtr)) {
DEBUGLOG(("AddTxnLog:: channel_code = [%s]\n",csPtr));
                        PutField_CString(hTxn,"channel_code",csPtr);
                }

                if (GetField_CString(hContext,"txn_code",&csPtr)) {
DEBUGLOG(("AddTxnLog:: txn_code = [%s]\n",csPtr));
                        PutField_CString(hTxn,"txn_code",csPtr);
                }


if (GetField_CString(hContext,"PHDATE",&csPtr)) {
DEBUGLOG(("AddTxnLog:: host_posting_date = [%s]\n",csPtr));
                        PutField_CString(hTxn,"host_posting_date",csPtr);
                }

                if (GetField_CString(hContext,"local_tm_date",&csPtr)) {
DEBUGLOG(("AddTxnLog:: local_tm_date = [%s]\n",csPtr));
                        PutField_CString(hTxn,"local_tm_date",csPtr);
                }
                if (GetField_CString(hContext,"local_tm_time",&csPtr)) {
DEBUGLOG(("AddTxnLog:: local_tm_time = [%s]\n",csPtr));
                        PutField_CString(hTxn,"local_tm_time",csPtr);
                }

                if (GetField_CString(hContext,"process_type",&csPtr)) {
DEBUGLOG(("AddTxnLog:: process_type = [%s]\n",csPtr));
                        PutField_CString(hTxn,"process_type",csPtr);
                }

                if (GetField_CString(hContext,"process_code",&csPtr)) {
DEBUGLOG(("AddTxnLog:: process_code = [%s]\n",csPtr));
                        PutField_CString(hTxn,"process_code",csPtr);
                }

/* node_id */
                if (GetField_CString(hContext,"req_node_id",&csPtr)) {
DEBUGLOG(("AddTxnLog:: node_id = [%s]\n",csPtr));
                        PutField_CString(hTxn,"node_id",csPtr);
                }
/* node_ref */
                if (GetField_CString(hRequest,"node_ref",&csPtr)) {
DEBUGLOG(("AddTxnLog:: node_ref = [%s]\n",csPtr));
                        PutField_CString(hTxn,"node_ref",csPtr);
                }
                else if (GetField_CString(hContext,"node_ref",&csPtr)) {
DEBUGLOG(("AddTxnLog:: node_ref = [%s]\n",csPtr));
                        PutField_CString(hTxn,"node_ref",csPtr);
                }

                if (GetField_CString(hRequest,"transmission_datetime",&csPtr)) {
DEBUGLOG(("AddTxnLog:: transmission_datetime = [%s]\n",csPtr));
                        PutField_CString(hTxn,"transmission_datetime",csPtr);
                }
                else if (GetField_CString(hContext,"transmission_datetime",&csPtr)) {
DEBUGLOG(("AddTxnLog:: transmission_datetime = [%s]\n",csPtr));
                        PutField_CString(hTxn,"transmission_datetime",csPtr);
                }

                if (GetField_CString(hRequest,"tm_date",&csPtr)) {
DEBUGLOG(("AddTxnLog:: tm_date = [%s]\n",csPtr));
                        PutField_CString(hTxn,"tm_date",csPtr);
                }
                else if (GetField_CString(hContext,"tm_date",&csPtr)) {
DEBUGLOG(("AddTxnLog:: tm_date = [%s]\n",csPtr));
                        PutField_CString(hTxn,"tm_date",csPtr);
                }

                if (GetField_CString(hRequest,"tm_time",&csPtr)) {
DEBUGLOG(("AddTxnLog:: tm_time = [%s]\n",csPtr));
                        PutField_CString(hTxn,"tm_time",csPtr);
                }
                else if (GetField_CString(hContext,"tm_time",&csPtr)) {
DEBUGLOG(("AddTxnLog:: tm_time = [%s]\n",csPtr));
                        PutField_CString(hTxn,"tm_time",csPtr);
                }

/* txn ccy */
                if (GetField_CString(hRequest,"txn_ccy",&csPtr)) {
DEBUGLOG(("AddTxnLog:: txn_ccy = [%s]\n",csPtr));
                        PutField_CString(hTxn,"txn_ccy",csPtr);
                }
/* ip_addr */
                if (GetField_CString(hRequest,"ip_addr",&csPtr)) {
DEBUGLOG(("AddTxnLog:: ip_addr = [%s]\n",csPtr));
                        PutField_CString(hTxn,"ip_addr",csPtr);
                }
/* remark */
                if (GetField_CString(hRequest,"remark",&csPtr)) {
DEBUGLOG(("AddTxnLog:: remark = [%s]\n",csPtr));
                        PutField_CString(hTxn,"remark",csPtr);
                }
/* action */
                if (GetField_Char(hRequest,"action",&cPtr)) {
DEBUGLOG(("AddTxnLog:: action = [%c]\n",cPtr));
                        PutField_Char(hTxn,"action",cPtr);
                }

/* add_user */
                if (GetField_CString(hRequest,"add_user",&csPtr)) {
DEBUGLOG(("AddTxnLog:: add_user = [%s]\n",csPtr));
                        PutField_CString(hTxn,"add_user",csPtr);
                }


                PutField_Char(hTxn,"status",PD_PROCESSING);

                DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","Add");
                iRet = (unsigned long) ((*DBObjPtr)(hTxn));
DEBUGLOG(("AddTxnLog:: iRet = [%d] from MmsTransaction:add\n",iRet));
                if (iRet == PD_OK) {
                        DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","AddDetail");
                        iRet = (unsigned long) ((*DBObjPtr)(hTxn));
DEBUGLOG(("AddTxnLog:: iRet = [%d] from MmsTransaction:AddDetail\n",iRet));
                }
        }


        FREE_ME(hTxn);
DEBUGLOG(("AddTxnLog Normal Exit iRet = [%d]\n",iRet));
        return iRet;
}


int     UpdateTxnLog(const hash_t *hContext,
                const hash_t* hRequest,
                const hash_t* hResponse)
{
        int     iRet = PD_OK;
        int     iTmp;
        char    *csTxnCode;
        char    *csTxnSeq,*csTmp;
	char	*csPtr;
        char    cTmp;
        char    cArInd;
        double  dTmp;

        hash_t  *hTxn;
DEBUGLOG(("UpdateTxnLog()\n"));

        if(GetField_Int(hContext,"do_logging",&iTmp)){
                if(iTmp!=PD_ADD_LOG) {
DEBUGLOG(("UpdateTxnLog iGnore Logging Exit iRet = [%d]\n",iRet));
                        return iRet;
                }
        }

        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	if (GetField_CString(hContext,"add_user",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: add_user = [%s]\n",csTmp));
	        PutField_CString(hTxn,"add_user",csTmp);
	} else {
DEBUGLOG(("UpdateTxnLog:: add_user (default) = [%s]\n",PD_UPDATE_USER));
	        PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
	}

	if (GetField_CString(hContext,"update_user",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: update_user = [%s]\n",csTmp));
                PutField_CString(hTxn,"update_user",csTmp);
        } else {
DEBUGLOG(("UpdateTxnLog:: update_user (default) = [%s]\n",PD_UPDATE_USER));
                PutField_CString(hTxn,"update_user",PD_UPDATE_USER);
        }

        if (GetField_CString(hContext,"txn_code",&csTxnCode)) {
DEBUGLOG(("UpdateTxnLog:: txn_code = [%s]\n",csTxnCode));
		PutField_CString(hTxn,"txn_code",csTxnCode);
        }
/* req_node_id */
        if (GetField_CString(hContext,"req_node_id",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: req_node_id = [%s]\n",csPtr));
		PutField_CString(hTxn,"req_node_id",csPtr);
        }

/* node_ref */
        if (GetField_CString(hContext,"node_ref",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: node_ref = [%s]\n",csPtr));
		PutField_CString(hTxn,"node_ref",csPtr);
        }

        if (GetField_CString(hContext,"txn_seq",&csTxnSeq)) {
DEBUGLOG(("UpdateTxnLog:: txn_seq = [%s]\n",csTxnSeq));
                PutField_CString(hTxn,"txn_seq",csTxnSeq);

/* Context */
                if (GetField_CString(hContext,"org_txn_seq",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: org_txn_seq = [%s]\n",csTmp));
                        PutField_CString(hTxn,"org_txn_seq",csTmp);
                }

/*entity id */
                if (GetField_CString(hContext,"entity_id",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: entity_id = [%s]\n",csTmp));
                        PutField_CString(hTxn,"entity_id",csTmp);
                }

                if (GetField_Char(hContext,"status",&cTmp)) {
DEBUGLOG(("UpdateTxnLog:: status = [%c]\n",cTmp));
                        PutField_Char(hTxn,"status",cTmp);
                }

                if (GetField_Char(hContext,"ar_ind",&cArInd)) {
DEBUGLOG(("UpdateTxnLog:: ar_ind = [%c]\n",cArInd));
                        PutField_Char(hTxn,"ar_ind",cArInd);
                }

                if (GetField_CString(hContext,"sub_status",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: sub_status = [%s]\n",csTmp));
                        PutField_CString(hTxn,"sub_status",csTmp);
                }

                if (GetField_Int(hContext,"internal_error",&iTmp)) {
DEBUGLOG(("UpdateTxnLog:: internal_error = [%d]\n",iTmp));
                        PutField_Int(hTxn,"internal_code",iTmp);
                }

                if (GetField_Double(hContext,"txn_amt",&dTmp)) {
DEBUGLOG(("UpdateTxnLog:: txn_amt = [%f]\n",dTmp));
                        PutField_Double(hTxn,"txn_amt",dTmp);
                }

/* remaining_amt */
                if (GetField_Double(hContext,"remaining_amt",&dTmp)) {
DEBUGLOG(("UpdateTxnLog:: remaining_amt = [%f]\n",dTmp));
                        PutField_Double(hTxn,"remaining_amt",dTmp);
                }

/* net amount */
                if (GetField_Double(hContext,"net_amt",&dTmp)) {
DEBUGLOG(("UpdateTxnLog:: net_amt = [%f]\n",dTmp));
                        PutField_Double(hTxn,"net_amt",dTmp);
                }

/* txn_cy */
                if (GetField_CString(hContext,"txn_ccy",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: txn_ccy = [%s]\n",csTmp));
                        PutField_CString(hTxn,"txn_ccy",csTmp);
                }

/* net ccy */
                if (GetField_CString(hContext,"net_ccy",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: net_ccy = [%s]\n",csTmp));
                        PutField_CString(hTxn,"net_ccy",csTmp);
                }

                if (GetField_CString(hResponse,"response_code",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: response_code = [%s]\n",csTmp));
                        PutField_CString(hTxn,"response_code",csTmp);
                }

/* related_txn_id */
                if (GetField_CString(hContext,"related_txn_id",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: related_txn_id = [%s]\n",csTmp));
                        PutField_CString(hTxn,"related_txn_id",csTmp);
                }
/* open balance */
                if (GetField_Double(hContext,"open_acct_bal",&dTmp)) {
                        PutField_Double(hTxn,"open_acct_bal",dTmp);
DEBUGLOG(("UpdateTxnLog:: open_acct_bal = [%lf]\n",dTmp));
                }
/* open prepaid */
                if (GetField_Double(hContext,"open_prepaid",&dTmp)) {
                        PutField_Double(hTxn,"open_prepaid",dTmp);
DEBUGLOG(("UpdateTxnLog:: open_prepaid = [%lf]\n",dTmp));
                }
/* open intransit */
                if (GetField_Double(hContext,"open_intransit",&dTmp)) {
                        PutField_Double(hTxn,"open_intransit",dTmp);
DEBUGLOG(("UpdateTxnLog:: open_intransit = [%lf]\n",dTmp));
                }

/* open lien */
                if (GetField_Double(hContext,"open_lien",&dTmp)) {
                        PutField_Double(hTxn,"open_lien",dTmp);
DEBUGLOG(("UpdateTxnLog:: open_lien = [%lf]\n",dTmp));
                }

/* curr balance */
                if (GetField_Double(hContext,"curr_acct_bal",&dTmp)) {
                        PutField_Double(hTxn,"curr_acct_bal",dTmp);
DEBUGLOG(("UpdateTxnLog:: curr_acct_bal = [%lf]\n",dTmp));
                }
/* curr prepaid */
                if (GetField_Double(hContext,"curr_prepaid",&dTmp)) {
                        PutField_Double(hTxn,"curr_prepaid",dTmp);
DEBUGLOG(("UpdateTxnLog:: curr_prepaid = [%lf]\n",dTmp));
                }
/* curr intransit */
                if (GetField_Double(hContext,"curr_intransit",&dTmp)) {
                        PutField_Double(hTxn,"curr_intransit",dTmp);
DEBUGLOG(("UpdateTxnLog:: curr_intransit = [%lf]\n",dTmp));
                }

/* curr lien */
                if (GetField_Double(hContext,"curr_lien",&dTmp)) {
                        PutField_Double(hTxn,"curr_lien",dTmp);
DEBUGLOG(("UpdateTxnLog:: curr_lien = [%lf]\n",dTmp));
                }
/* cost related */

/* provided_cost_rate */
                if (GetField_Double(hContext,"provided_cost_rate",&dTmp)) {
                        PutField_Double(hTxn,"provided_cost_rate",dTmp);
DEBUGLOG(("UpdateTxnLog:: provided_cost_rate = [%lf]\n",dTmp));
                }

/* provided_fixed_amount */
                if (GetField_Double(hContext,"provided_cost_flat_rate",&dTmp)) {
                        PutField_Double(hTxn,"provided_fixed_amount",dTmp);
DEBUGLOG(("UpdateTxnLog:: provided_fixed_amount = [%lf]\n",dTmp));
                }

/* provided_cost */
                if (GetField_Double(hContext,"provided_cost_amt",&dTmp)) {
                        PutField_Double(hTxn,"provided_cost",dTmp);
DEBUGLOG(("UpdateTxnLog:: provided_cost = [%lf]\n",dTmp));
                }

/* cost_rate */
                if (GetField_Double(hContext,"cost_rate",&dTmp)) {
                        PutField_Double(hTxn,"cost_rate",dTmp);
DEBUGLOG(("UpdateTxnLog:: cost_rate = [%lf]\n",dTmp));
                }

/* fixed_amount */
                if (GetField_Double(hContext,"cost_flat_rate",&dTmp)) {
                        PutField_Double(hTxn,"fixed_amount",dTmp);
DEBUGLOG(("UpdateTxnLog:: fixed_amount = [%lf]\n",dTmp));
                }
/* cost */
                if (GetField_Double(hContext,"cost_amt",&dTmp)) {
                        PutField_Double(hTxn,"cost",dTmp);
DEBUGLOG(("UpdateTxnLog:: cost = [%lf]\n",dTmp));
                }
/* provided_fx_rate */
                if (GetField_Double(hContext,"provided_fx_rate",&dTmp)) {
                        PutField_Double(hTxn,"provided_fx_rate",dTmp);
DEBUGLOG(("UpdateTxnLog:: provided_fx_rate = [%lf]\n",dTmp));
                }


/* allow prepaid */
		if  (GetField_Char(hContext,"allow_prepaid",&cTmp)) {
			PutField_Char(hTxn,"allow_prepaid",cTmp);
DEBUGLOG(("UpdateTxnLog:: allow_prepaid = [%c]\n",cTmp));
		}

/* next_action_ccy */
                if (GetField_CString(hContext,"next_action_ccy",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: next_action_ccy = [%s]\n",csTmp));
                        PutField_CString(hTxn,"next_action_ccy",csTmp);
                }
/* fx_txn */
		if  (GetField_Char(hContext,"fx_txn",&cTmp)) {
			PutField_Char(hTxn,"fx_txn",cTmp);
DEBUGLOG(("UpdateTxnLog:: fx_txn = [%c]\n",cTmp));
		}

                if (iRet == PD_OK) {
/* update txn header */
                        DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","Update");
                        iRet = (unsigned long)(*DBObjPtr)(hTxn);
DEBUGLOG(("UpdateTxnLog:: iRet = [%d] from MmsTransaction:Update\n",iRet));
                }

                if (iRet == PD_OK) {
/* update txn detail */
                        DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","UpdateDetail");
                        iRet = (unsigned long)(*DBObjPtr)(hTxn);
DEBUGLOG(("UpdateTxnLog:: iRet = [%d] from MmsTransaction:UpdateDetail\n",iRet));
                }

        }

        hash_destroy(hTxn);
        FREE_ME(hTxn);


DEBUGLOG(("UpdateTxnLog Normal Exit iRet = [%d]\n",iRet));
        return iRet;
}

int     UpdateTxnHd(const hash_t *hContext,
                const hash_t* hRequest,
                const hash_t* hResponse)
{
        int     iRet = PD_OK;
        char    *csTxnSeq,*csTmp;
	char	cTmp;
	int	iTmp;
	double	dTmp;

        hash_t  *hTxn;
DEBUGLOG(("UpdateTxnHd()\n"));

        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	if (GetField_CString(hContext,"add_user",&csTmp)) {
DEBUGLOG(("UpdateTxnHd:: add_user = [%s]\n",csTmp));
	        PutField_CString(hTxn,"add_user",csTmp);
	} else {
DEBUGLOG(("UpdateTxnHd:: add_user (default) = [%s]\n",PD_UPDATE_USER));
	        PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
	}

	if (GetField_CString(hContext,"update_user",&csTmp)) {
DEBUGLOG(("UpdateTxnHd:: update_user = [%s]\n",csTmp));
                PutField_CString(hTxn,"update_user",csTmp);
        } else {
DEBUGLOG(("UpdateTxnHd:: update_user (default) = [%s]\n",PD_UPDATE_USER));
                PutField_CString(hTxn,"update_user",PD_UPDATE_USER);
        }

        if (GetField_CString(hContext,"txn_seq",&csTxnSeq)) {
DEBUGLOG(("UpdateTxnHd:: txn_seq = [%s]\n",csTxnSeq));
                PutField_CString(hTxn,"txn_seq",csTxnSeq);

/* Context */
                if (GetField_CString(hContext,"org_txn_seq",&csTmp)) {
DEBUGLOG(("UpdateTxnHd:: org_txn_seq = [%s]\n",csTmp));
                        PutField_CString(hTxn,"org_txn_seq",csTmp);
                }

/*entity id */
                if (GetField_CString(hContext,"entity_id",&csTmp)) {
DEBUGLOG(("UpdateTxnHd:: entity_id = [%s]\n",csTmp));
                        PutField_CString(hTxn,"entity_id",csTmp);
                }

                if (GetField_Char(hContext,"status",&cTmp)) {
DEBUGLOG(("UpdateTxnHd:: status = [%c]\n",cTmp));
                        PutField_Char(hTxn,"status",cTmp);
                }

                if (GetField_Char(hContext,"ar_ind",&cTmp)) {
DEBUGLOG(("UpdateTxnHd:: ar_ind = [%c]\n",cTmp));
                        PutField_Char(hTxn,"ar_ind",cTmp);
                }

                if (GetField_CString(hContext,"sub_status",&csTmp)) {
DEBUGLOG(("UpdateTxnHd:: sub_status = [%s]\n",csTmp));
                        PutField_CString(hTxn,"sub_status",csTmp);
                }

                if (GetField_Int(hContext,"internal_error",&iTmp)) {
DEBUGLOG(("UpdateTxnHd:: internal_error = [%d]\n",iTmp));
                        PutField_Int(hTxn,"internal_code",iTmp);
                }

                if (GetField_Double(hContext,"txn_amt",&dTmp)) {
DEBUGLOG(("UpdateTxnHd:: txn_amt = [%f]\n",dTmp));
                        PutField_Double(hTxn,"txn_amt",dTmp);
                }

/* remaining_amount */
                if (GetField_Double(hContext,"remaining_amt",&dTmp)) {
DEBUGLOG(("UpdateTxnHd:: remaining_amt = [%f]\n",dTmp));
                        PutField_Double(hTxn,"remaining_amt",dTmp);
                }

/* net amount */
                if (GetField_Double(hContext,"net_amt",&dTmp)) {
DEBUGLOG(("UpdateTxnHd:: net_amt = [%f]\n",dTmp));
                        PutField_Double(hTxn,"net_amt",dTmp);
                }


/* net ccy */
                if (GetField_CString(hContext,"net_ccy",&csTmp)) {
DEBUGLOG(("UpdateTxnHd:: net_ccy = [%s]\n",csTmp));
                        PutField_CString(hTxn,"net_ccy",csTmp);
                }
/* related_txn_id */
                if (GetField_CString(hContext,"related_txn_id",&csTmp)) {
DEBUGLOG(("UpdateTxnHd:: related_txn_id = [%s]\n",csTmp));
                        PutField_CString(hTxn,"related_txn_id",csTmp);
                }

                if (GetField_CString(hResponse,"response_code",&csTmp)) {
DEBUGLOG(("UpdateTxnHd:: response_code = [%s]\n",csTmp));
                        PutField_CString(hTxn,"response_code",csTmp);
                }

/* open balance */
                if (GetField_Double(hContext,"open_acct_bal",&dTmp)) {
                        PutField_Double(hTxn,"open_acct_bal",dTmp);
DEBUGLOG(("UpdateTxnHd:: open_acct_bal = [%lf]\n",dTmp));
                }
/* open prepaid */
                if (GetField_Double(hContext,"open_prepaid",&dTmp)) {
                        PutField_Double(hTxn,"open_prepaid",dTmp);
DEBUGLOG(("UpdateTxnHd:: open_prepaid = [%lf]\n",dTmp));
                }
/* open intransit */
                if (GetField_Double(hContext,"open_intransit",&dTmp)) {
                        PutField_Double(hTxn,"open_intransit",dTmp);
DEBUGLOG(("UpdateTxnHd:: open_intransit = [%lf]\n",dTmp));
                }

/* open lien */
                if (GetField_Double(hContext,"open_lien",&dTmp)) {
                        PutField_Double(hTxn,"open_lien",dTmp);
DEBUGLOG(("UpdateTxnHd:: open_lien = [%lf]\n",dTmp));
                }

/* curr balance */
                if (GetField_Double(hContext,"curr_acct_bal",&dTmp)) {
                        PutField_Double(hTxn,"curr_acct_bal",dTmp);
DEBUGLOG(("UpdateTxnHd:: curr_acct_bal = [%lf]\n",dTmp));
                }
/* curr prepaid */
                if (GetField_Double(hContext,"curr_prepaid",&dTmp)) {
                        PutField_Double(hTxn,"curr_prepaid",dTmp);
DEBUGLOG(("UpdateTxnHd:: curr_prepaid = [%lf]\n",dTmp));
                }
/* curr intransit */
                if (GetField_Double(hContext,"curr_intransit",&dTmp)) {
                        PutField_Double(hTxn,"curr_intransit",dTmp);
DEBUGLOG(("UpdateTxnHd:: curr_intransit = [%lf]\n",dTmp));
                }

/* curr lien */
                if (GetField_Double(hContext,"curr_lien",&dTmp)) {
                        PutField_Double(hTxn,"curr_lien",dTmp);
DEBUGLOG(("UpdateTxnHd:: curr_lien = [%lf]\n",dTmp));
                }

                if (iRet == PD_OK) {
/* update txn header */
                        DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","Update");
                        iRet = (unsigned long)(*DBObjPtr)(hTxn);
DEBUGLOG(("UpdateTxnHd:: iRet = [%d] from MmsTransaction:Update\n",iRet));
                }


        }

        hash_destroy(hTxn);
        FREE_ME(hTxn);


DEBUGLOG(("UpdateTxnHd Normal Exit iRet = [%d]\n",iRet));
        return iRet;
}

int UpdateRelatedTxnSubStatus(char cMode,const char* csTxnId,double dRemainingAmt)
{
	int	iRet = PD_OK;
	char	csSubStatus[PD_SUB_STATUS_LEN +1];
        hash_t  *hTxn;
        hash_t  *hReq;
        hash_t  *hRsp;
	recordset_t     *rRecordSet;

DEBUGLOG(("UpdateRelatedTxnSubStatus Normal()\n"));

        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);
        hReq = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hReq,0);
        hRsp = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRsp,0);
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);
DEBUGLOG(("UpdateRelatedTxnSubStatus mode = [%c]\n",cMode));

	if (cMode  == PD_PARTIAL_RECEIVE) {
		strcpy(csSubStatus,PD_IN_PROCESS);
	}
	else {
		strcpy(csSubStatus,PD_COMPLETED);
	}

	PutField_CString(hTxn,"update_user",PD_UPDATE_USER);
	PutField_CString(hTxn,"txn_seq",csTxnId);
	PutField_CString(hTxn,"sub_status",csSubStatus);
	PutField_Double(hTxn,"remaining_amt",dRemainingAmt);
DEBUGLOG(("UpdateRelatedTxnSubStatus try to update hd\n"));
	
	iRet = UpdateTxnHd(hTxn,hReq,hRsp);
DEBUGLOG(("UpdateRelatedTxnSubStatus:: iRet = [%d] from MmsTransaction:Update\n",iRet));

	RemoveField_Double(hTxn,"remaining_amt");
	RemoveField_CString(hTxn,"txn_seq");
	if (iRet == PD_OK) {
DEBUGLOG(("UpdateRelatedTxnSubStatus:: Try to GetTxnHeader\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","GetTxnHeader");
                iRet = (unsigned long)(*DBObjPtr)(csTxnId,rRecordSet);
DEBUGLOG(("UpdateRelatedTxnSubStatus:: iRet = [%d] from GetTxnHeader\n",iRet));
	}

	if (iRet == PD_OK ) {
		char	cArInd;
		char	cStatus;
		char	*csSubStatus;
		char	*csRelatedTxnId;

		hash_t*	hRec;
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			if (GetField_Char(hRec,"ar_ind",&cArInd)) {
DEBUGLOG(("UpdateRelatedTxnSubStatus:: ar_ind = [%c]\n",cArInd));
			}
			if (GetField_Char(hRec,"status",&cStatus)) {
DEBUGLOG(("UpdateRelatedTxnSubStatus:: Status = [%c]\n",cStatus));
			}
			if (GetField_CString(hRec,"sub_status",&csSubStatus)) {
DEBUGLOG(("UpdateRelatedTxnSubStatus:: sub_status = [%s]\n",csSubStatus));
			}

			if ((cArInd == PD_ACCEPT && cStatus == PD_COMPLETE) && (!strcmp(csSubStatus,PD_PENDING) ||!strcmp(csSubStatus,PD_IN_PROCESS) ||!strcmp(csSubStatus,PD_COMPLETED))) {
				if (GetField_CString(hRec,"related_txn_id",&csRelatedTxnId)) {
DEBUGLOG(("UpdateRelatedTxnSubStatus:: related_txn_id = [%s]\n",csRelatedTxnId));
					PutField_CString(hTxn,"txn_seq",csRelatedTxnId);
					iRet = UpdateTxnHd(hTxn,hReq,hRsp);
DEBUGLOG(("UpdateRelatedTxnSubStatus:: iRet = [%d] from MmsTransaction:Update\n",iRet));
				}
			}
			break;
		}
	}
	FREE_ME(hTxn);
	FREE_ME(hReq);
	FREE_ME(hRsp);
	FREE_ME(rRecordSet);
DEBUGLOG(("UpdateRelatedTxnSubStatus Normal Exit iRet = [%d]\n",iRet));
	return iRet;
}

int GetTxnInfo(const char* csTxnId, hash_t* hRsp)
{
	int	iRet = PD_OK;
	char	*csPtr;
	double	dTmp;
	recordset_t     *rRecordSet;
	hash_t*	hRec;

	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);
DEBUGLOG(("GetTxnInfo: txn_id = [%s]\n",csTxnId));

	DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","GetTxnHeader");
        iRet = (unsigned long)(*DBObjPtr)(csTxnId,rRecordSet);

	if (iRet == PD_OK) {
		hRec = RecordSet_GetFirst(rRecordSet);
		if (hRec) {
			if (GetField_Double(hRec,"remaining_amt",&dTmp)) {
DEBUGLOG(("GetTxnInfo: remaining_amt = [%lf]\n",dTmp));
				PutField_Double(hRsp,"remaining_amt",dTmp);
			}	
/* txn_ccy */
			if (GetField_CString(hRec,"txn_ccy",&csPtr)) {
DEBUGLOG(("GetTxnInfo: txn_ccy = [%s]\n",csPtr));
				PutField_CString(hRsp,"txn_ccy",csPtr);
			}	
/* txn_amt */
			if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("GetTxnInfo: txn_amt = [%lf]\n",dTmp));
				PutField_Double(hRsp,"txn_amt",dTmp);
			}	
/* net_ccy */
			if (GetField_CString(hRec,"net_ccy",&csPtr)) {
DEBUGLOG(("GetTxnInfo: net_ccy = [%s\n",csPtr));
				PutField_CString(hRsp,"net_ccy",csPtr);
			}	
/* net_amt */
			if (GetField_Double(hRec,"net_amt",&dTmp)) {
DEBUGLOG(("GetTxnInfo: net_amt = [%lf]\n",dTmp));
				PutField_Double(hRsp,"net_amt",dTmp);
			}	
/* related_txn_id */
			if (GetField_CString(hRec,"related_txn_id",&csPtr)) {
DEBUGLOG(("GetTxnInfo: related_txn_id = [%s]\n",csPtr));
				PutField_CString(hRsp,"related_txn_id",csPtr);
			}	
/* node_id */
			if (GetField_CString(hRec,"node_id",&csPtr)) {
DEBUGLOG(("GetTxnInfo: node_id = [%s]\n",csPtr));
				PutField_CString(hRsp,"req_node_id",csPtr);
			}	
/* node_ref */
			if (GetField_CString(hRec,"node_ref",&csPtr)) {
DEBUGLOG(("GetTxnInfo: node_ref = [%s]\n",csPtr));
				PutField_CString(hRsp,"node_ref",csPtr);
			}	
		}	
	}
	if (iRet == PD_OK) {
        	recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","GetTxnDetail");
        	iRet = (unsigned long)(*DBObjPtr)(csTxnId,rRecordSet);
		if (iRet == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			if (hRec) {
/* entity_id */
				if (GetField_CString(hRec,"entity_id",&csPtr)) {
DEBUGLOG(("GetTxnInfo: entity_id = [%s]\n",csPtr));
					PutField_CString(hRsp,"entity_id",csPtr);
				}	
/* provided_fx_rate */
				if (GetField_Double(hRec,"provided_fx_rate",&dTmp)) {
DEBUGLOG(("GetTxnInfo: provided_fx_rate = [%lf]\n",dTmp));
					PutField_Double(hRsp,"provided_fx_rate",dTmp);
				}	

/* provided_cost_rate */
				if (GetField_Double(hRec,"provided_cost_rate",&dTmp)) {
DEBUGLOG(("GetTxnInfo: provided_cost_rate = [%lf]\n",dTmp));
					PutField_Double(hRsp,"provided_cost_rate",dTmp);
				}	
/* provided_cost_rate */
				if (GetField_Double(hRec,"provided_cost_rate",&dTmp)) {
DEBUGLOG(("GetTxnInfo: provided_cost_rate = [%lf]\n",dTmp));
					PutField_Double(hRsp,"provided_cost_rate",dTmp);
				}	
/* provided_cost */
				if (GetField_Double(hRec,"provided_cost",&dTmp)) {
DEBUGLOG(("GetTxnInfo: provided_cost = [%lf]\n",dTmp));
					PutField_Double(hRsp,"provided_cost",dTmp);
				}	
/* next_action_ccy */
				if (GetField_CString(hRec,"next_action_ccy",&csPtr)) {
DEBUGLOG(("GetTxnInfo: next_action_ccy = [%s]\n",csPtr));
					PutField_CString(hRsp,"next_action_ccy",csPtr);
				}	
			}	
		}
	}


	FREE_ME(rRecordSet);
DEBUGLOG(("GetTxnInfo: Normal Exit iRet = [%d]\n",iRet));
	return iRet;
}
