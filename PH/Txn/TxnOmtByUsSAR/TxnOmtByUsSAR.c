/*
PDProTech (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/02/04              David Wong
Add keywords checking                              2015/03/30              David Wong
Support "Any" for PID                              2019/03/15              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsSAR.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;

void TxnOmtByUsSAR(char cdebug)
{
	cDebug = cdebug;
}

OBJPTR(Msg);
OBJPTR(DB);
OBJPTR(BO);


int CheckKeywords(hash_t *hContext);


int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;

	int iTmpRet;
	double dTmp = 0.0;
	char csCmd[PD_MAX_BUFFER + 1];
	char *csTmp = NULL;

	int iExecute = 0;
	int iFound = PD_FALSE;

	char *csSenderTsFr, *csSenderTsTo, *csRecipientTsFr, *csRecipientTsTo;
	char *csSenderProviderId, *csRecipientProviderId;
	char *csSenderPid, *csRecipientPid;
	char *csSenderTxnAmt, *csRecipientTxnAmt;
	char *csSenderBaidTxnId, *csRecipientBaidTxnId;
	char *csSenderBankAcctType, *csRecipientBankAcctType;
	char *csBaid;
	char *csTriggerSeq;
	char *csUser;

	hash_t *hSender, *hRecipient, *hPspDetail, *hList;
	hSender = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hSender, 0);
	hRecipient = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRecipient, 0);
	hList = (hash_t*) malloc (sizeof(hash_t));
	//hash_init(hList, 0);
	hPspDetail = (hash_t*) malloc (sizeof(hash_t));
	//hash_init(hPspDetail, 0);

	recordset_t *rSender, *rRecipient;
	rSender = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rSender, 0);
	rRecipient = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecipient, 0);

	hash_t *hTmp;

	hash_t *hCheckKeywords;
	hCheckKeywords = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hCheckKeywords, 0);

DEBUGLOG(("Authorize\n"));
strcpy(csCmd, "semi_auto_recon.exec");

/* sender */

	// s_create_ts / s_stmt_ts
	if (iRet == PD_OK) {
		// get s_create_ts_from / s_create_ts_to
		if (GetField_CString(hRequest, "s_create_ts_from", &csSenderTsFr)) {
DEBUGLOG(("Authorize:: s_create_ts_from = [%s]\n", csSenderTsFr));
			PutField_CString(hSender, "create_ts_from", csSenderTsFr);

			if (!GetField_CString(hRequest, "s_create_ts_to", &csSenderTsTo)) {
DEBUGLOG(("Authorize:: s_create_ts_to not found\n"));
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			} else {
DEBUGLOG(("Authorize:: s_create_ts_to = [%s]\n", csSenderTsTo));
				PutField_CString(hSender, "create_ts_to", csSenderTsTo);
			}

			strcat(csCmd, " -a create");
			sprintf(csCmd, "%s -b %s -c %s", csCmd, csSenderTsFr, csSenderTsTo);
		}
		// get s_stmt_ts_from / s_stmt_ts_to
		else if (GetField_CString(hRequest, "s_stmt_ts_from", &csSenderTsFr)) {
DEBUGLOG(("Authorize:: s_stmt_ts_from = [%s]\n", csSenderTsFr));
			PutField_CString(hSender, "stmt_ts_from", csSenderTsFr);

			if (!GetField_CString(hRequest, "s_stmt_ts_to", &csSenderTsTo)) {
DEBUGLOG(("Authorize:: s_stmt_ts_to not found\n"));
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			} else {
DEBUGLOG(("Authorize:: s_stmt_ts_to = [%s]\n", csSenderTsTo));
				PutField_CString(hSender, "stmt_ts_to", csSenderTsTo);
			}

			strcat(csCmd, " -a stmt");
			sprintf(csCmd, "%s -b %s -c %s", csCmd, csSenderTsFr, csSenderTsTo);
		} else {
DEBUGLOG(("Authorize:: s_create_ts and s_stmt_ts not found\n"));
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// get s_provider_id
	if (iRet == PD_OK) {
		if (!GetField_CString(hRequest, "s_provider_id", &csSenderProviderId)) {
DEBUGLOG(("Authorize:: s_provider_id not found\n"));
		} else {
DEBUGLOG(("Authorize:: s_provider_id = [%s]\n", csSenderProviderId));
			PutField_CString(hSender, "provider_id", csSenderProviderId);
			sprintf(csCmd, "%s -d %s", csCmd, csSenderProviderId);
		}
	}

	// get s_pid
	if (iRet == PD_OK) {
		if (!GetField_CString(hRequest, "s_pid", &csSenderPid)) {
DEBUGLOG(("Authorize:: s_pid not found\n"));
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
DEBUGLOG(("Authorize:: s_pid = [%s]\n", csSenderPid));
			PutField_CString(hSender, "pid", csSenderPid);
			sprintf(csCmd, "%s -e %s", csCmd, csSenderPid);

			if (GetField_Int(hRequest, "execute", &iExecute)) {
				// get psp detail
				hash_init(hPspDetail, 0);
DEBUGLOG(("Authorize:: call DBOLPspDetail::GetPspDetail()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLPspDetail", "GetPspDetail");
				iTmpRet = (unsigned long)(*DBObjPtr)(csSenderPid, hPspDetail);
				if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: call DBOLPspDetail::GetPspDetail() failed\n"));
					iRet = INT_ERR;
					PutField_Int(hContext, "internal_error", iRet);
				} else {
					// get bank_acct_type
					if (!GetField_CString(hPspDetail, "bank_acct_type", &csSenderBankAcctType)) {
DEBUGLOG(("Authorize:: bank_acct_type not found\n"));
						iRet = INT_ERR;
						PutField_Int(hContext, "internal_error", iRet);
					} else {
DEBUGLOG(("Authorize:: bank_acct_type = [%s]\n", csSenderBankAcctType));
						PutField_CString(hSender, "bank_acct_type", csSenderBankAcctType);
					}
				}
				hash_destroy(hPspDetail);
			}
		}
	}

	// get s_txn_amt
	if (iRet == PD_OK) {
		if (!GetField_CString(hRequest, "s_txn_amt", &csSenderTxnAmt)) {
DEBUGLOG(("Authorize:: s_txn_amt not found\n"));
		} else {
DEBUGLOG(("Authorize:: s_txn_amt = [%s]\n", csSenderTxnAmt));
			PutField_CString(hSender, "txn_amt", csSenderTxnAmt);
			sprintf(csCmd, "%s -f %s", csCmd, csSenderTxnAmt);
		}
	}

	// put s_r_ind = sender
	if (iRet == PD_OK) {
		PutField_Char(hSender, "s_r_ind", 'S');
	}

/* recipient */

	// r_create_ts / r_stmt_ts
	if (iRet == PD_OK) {
		// get r_create_ts_from / r_create_ts_to
		if (GetField_CString(hRequest, "r_create_ts_from", &csRecipientTsFr)) {
DEBUGLOG(("Authorize:: r_create_ts_from = [%s]\n", csRecipientTsFr));
			PutField_CString(hRecipient, "create_ts_from", csRecipientTsFr);

			if (!GetField_CString(hRequest, "r_create_ts_to", &csRecipientTsTo)) {
DEBUGLOG(("Authorize:: r_create_ts_to not found\n"));
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			} else {
DEBUGLOG(("Authorize:: r_create_ts_to = [%s]\n", csRecipientTsTo));
				PutField_CString(hRecipient, "create_ts_to", csRecipientTsTo);
			}

			sprintf(csCmd, "%s -g %s -h %s", csCmd, csRecipientTsFr, csRecipientTsTo);
		}
		// get r_stmt_ts_from / r_stmt_ts_to
		else if (GetField_CString(hRequest, "r_stmt_ts_from", &csRecipientTsFr)) {
DEBUGLOG(("Authorize:: r_stmt_ts_from = [%s]\n", csRecipientTsFr));
			PutField_CString(hRecipient, "stmt_ts_from", csRecipientTsFr);

			if (!GetField_CString(hRequest, "r_stmt_ts_to", &csRecipientTsTo)) {
DEBUGLOG(("Authorize:: r_stmt_ts_to not found\n"));
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			} else {
DEBUGLOG(("Authorize:: r_stmt_ts_to = [%s]\n", csRecipientTsTo));
				PutField_CString(hRecipient, "stmt_ts_to", csRecipientTsTo);
			}

			sprintf(csCmd, "%s -g %s -h %s", csCmd, csRecipientTsFr, csRecipientTsTo);
		} else {
DEBUGLOG(("Authorize:: r_create_ts and r_stmt_ts not found\n"));
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// get r_provider_id
	if (iRet == PD_OK) {
		if (!GetField_CString(hRequest, "r_provider_id", &csRecipientProviderId)) {
DEBUGLOG(("Authorize:: r_provider_id not found\n"));
		} else {
DEBUGLOG(("Authorize:: r_provider_id = [%s]\n", csRecipientProviderId));
			PutField_CString(hRecipient, "provider_id", csRecipientProviderId);
			sprintf(csCmd, "%s -i %s", csCmd, csRecipientProviderId);
		}
	}

	// get r_pid
	if (iRet == PD_OK) {
		if (!GetField_CString(hRequest, "r_pid", &csRecipientPid)) {
DEBUGLOG(("Authorize:: r_pid not found\n"));
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
DEBUGLOG(("Authorize:: r_pid = [%s]\n", csRecipientPid));
			PutField_CString(hRecipient, "pid", csRecipientPid);
			sprintf(csCmd, "%s -j %s", csCmd, csRecipientPid);

			if (GetField_Int(hRequest, "execute", &iExecute)) {
				// get psp detail
				hash_init(hPspDetail, 0);
DEBUGLOG(("Authorize:: call DBOLPspDetail::GetPspDetail()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLPspDetail", "GetPspDetail");
				iTmpRet = (unsigned long)(*DBObjPtr)(csRecipientPid, hPspDetail);
				if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: call DBOLPspDetail::GetPspDetail() failed\n"));
					iRet = INT_ERR;
					PutField_Int(hContext, "internal_error", iRet);
				} else {
					// get bank_acct_type
					if (!GetField_CString(hPspDetail, "bank_acct_type", &csRecipientBankAcctType)) {
DEBUGLOG(("Authorize:: bank_acct_type not found\n"));
						iRet = INT_ERR;
						PutField_Int(hContext, "internal_error", iRet);
					} else {
DEBUGLOG(("Authorize:: bank_acct_type = [%s]\n", csRecipientBankAcctType));
						PutField_CString(hRecipient, "bank_acct_type", csRecipientBankAcctType);
					}
				}
				hash_destroy(hPspDetail);
			}
		}
	}

	// get r_txn_amt
	if (iRet == PD_OK) {
		if (!GetField_CString(hRequest, "r_txn_amt", &csRecipientTxnAmt)) {
DEBUGLOG(("Authorize:: r_txn_amt not found\n"));
		} else {
DEBUGLOG(("Authorize:: r_txn_amt = [%s]\n", csRecipientTxnAmt));
			PutField_CString(hRecipient, "txn_amt", csRecipientTxnAmt);
			sprintf(csCmd, "%s -k %s", csCmd, csRecipientTxnAmt);
		}
	}

	// put s_r_ind = recipient
	if (iRet == PD_OK) {
		PutField_Char(hRecipient, "s_r_ind", 'R');
	}

/* other input */
	if (iRet == PD_OK) {
		if (!GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize:: user not found\n"));
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
DEBUGLOG(("Authorize:: user = [%s]\n", csUser));
			sprintf(csCmd, "%s -l %s", csCmd, csUser);
		}
	}

	if (iRet == PD_OK) {
		if (!GetField_Int(hRequest, "execute", &iExecute)) {
			if (!GetField_CString(hRequest, "trigger_seq", &csTriggerSeq)) {
DEBUGLOG(("Authorize:: trigger_seq not found\n"));
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			} else {
DEBUGLOG(("Authorize:: trigger_seq = [%s]\n", csTriggerSeq));
				sprintf(csCmd, "%s -m %s", csCmd, csTriggerSeq);
			}
		}
	}

	if (GetField_Int(hRequest, "execute", &iExecute)) {
		/* start semi-auto recon */

		if (iRet == PD_OK) {
			// get sender
//DEBUGLOG(("Authorize:: call DBOLBAIDTxn::GetSemiAutoReconBaidTxn() -- sender\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "GetSemiAutoReconBaidTxn");
			iTmpRet = (unsigned long)(*DBObjPtr)(hSender, rSender);
			if (iTmpRet == PD_OK) {
				hTmp = RecordSet_GetFirst(rSender);
				while (hTmp) {
					iFound = PD_FALSE;

					if (GetField_CString(hTmp, "txn_id", &csSenderBaidTxnId)) {
DEBUGLOG(("Authorize:: sender_baid_txn_id = [%s]\n", csSenderBaidTxnId));

						// check keywords
						hash_destroy(hCheckKeywords);
						hash_init(hCheckKeywords, 0);
						PutField_CString(hCheckKeywords, "baid_txn_id", csSenderBaidTxnId);
						PutField_CString(hCheckKeywords, "psp_id", csSenderPid);
						PutField_CString(hCheckKeywords, "bank_acct_type", csSenderBankAcctType);
						PutField_Char(hCheckKeywords, "sr_ind", 'S');
						PutField_Char(hCheckKeywords, "nr_ind", 'N');
						if (CheckKeywords(hCheckKeywords) != PD_OK) {
DEBUGLOG(("Authorize:: keywords not match\n"));
DEBUGLOG(("Authorize:: --------------------------------------------------\n"));
							hTmp = RecordSet_GetNext(rSender);
							continue;
						}

						GetField_CString(hTmp, "baid", &csBaid);
DEBUGLOG(("Authorize:: baid = [%s]\n", csBaid));

						GetField_Double(hTmp, "net_amt", &dTmp);
DEBUGLOG(("Authorize:: net_amt = [%lf]\n", dTmp));
						PutField_Double(hRecipient, "net_amt", dTmp);

						// find recipient (normal)
						if (GetField_CString(hRecipient, "same_baid", &csTmp)) {
							RemoveField_CString (hRecipient, "same_baid");
						}
						PutField_CString(hRecipient, "diff_baid", csBaid);

						RecordSet_Destroy(rRecipient);
						recordset_init(rRecipient, 0);
//DEBUGLOG(("Authorize:: call DBOLBAIDTxn::GetSemiAutoReconBaidTxn() -- recipient\n"));
						DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "GetSemiAutoReconBaidTxn");
						iTmpRet = (unsigned long)(*DBObjPtr)(hRecipient, rRecipient);
						if (iTmpRet == PD_OK) {
							hTmp = RecordSet_GetFirst(rRecipient);
							while (hTmp && !iFound) {
								if (GetField_CString(hTmp, "txn_id", &csRecipientBaidTxnId)) {
DEBUGLOG(("Authorize:: recipien_baid_txn_id = [%s]\n", csRecipientBaidTxnId));

									// check keywords
									hash_destroy(hCheckKeywords);
									hash_init(hCheckKeywords, 0);
									PutField_CString(hCheckKeywords, "baid_txn_id", csRecipientBaidTxnId);
									PutField_CString(hCheckKeywords, "psp_id", csRecipientPid);
									PutField_CString(hCheckKeywords, "bank_acct_type", csRecipientBankAcctType);
									PutField_Char(hCheckKeywords, "sr_ind", 'R');
									PutField_Char(hCheckKeywords, "nr_ind", 'N');
									if (CheckKeywords(hCheckKeywords) != PD_OK) {
DEBUGLOG(("Authorize:: keywords not match\n"));
										hTmp = RecordSet_GetNext(rRecipient);
										continue;
									}

									// set hold_recon to true (sender)
									hash_init(hList, 0);
									PutField_CString(hList, "txn_seq", csSenderBaidTxnId);
									PutField_CString(hList, "update_user", csUser);
									PutField_Int(hList, "hold_recon", PD_TRUE);
DEBUGLOG(("Authorize:: call DBOLBAIDTxn::Update()\n"));
									DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "Update");
									iTmpRet = (unsigned long)(*DBObjPtr)(hList);
									if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: Update [%s] hold_recon success\n", csSenderBaidTxnId));
									} else {
DEBUGLOG(("Authorize:: Update [%s] hold_recon failed\n", csSenderBaidTxnId));
									}
									hash_destroy(hList);

									// set hold_recon to true(recipient)
									hash_init(hList, 0);
									PutField_CString(hList, "txn_seq", csRecipientBaidTxnId);
									PutField_CString(hList, "update_user", csUser);
									PutField_Int(hList, "hold_recon", PD_TRUE);
DEBUGLOG(("Authorize:: call DBOLBAIDTxn::Update()\n"));
									DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "Update");
									iTmpRet = (unsigned long)(*DBObjPtr)(hList);
									if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: Update [%s] hold_recon success\n", csRecipientBaidTxnId));
									} else {
DEBUGLOG(("Authorize:: Update [%s] hold_recon failed\n", csRecipientBaidTxnId));
									}
									hash_destroy(hList);

									// add into list
									hash_init(hList, 0);
									PutField_CString(hList, "baid_txn_id_1", csSenderBaidTxnId);
									PutField_CString(hList, "bank_acct_type_1", csSenderBankAcctType);
									PutField_CString(hList, "baid_txn_id_2", csRecipientBaidTxnId);
									PutField_CString(hList, "bank_acct_type_2", csRecipientBankAcctType);
									PutField_Char(hList, "recon_type", 'N');
									PutField_CString(hList, "create_user", csUser);
DEBUGLOG(("Authorize:: call DBOLWaitReconCfmList::Add()\n"));
									DBObjPtr = CreateObj(DBPtr, "DBOLWaitReconCfmList", "Add");
									iTmpRet = (unsigned long)(*DBObjPtr)(hList);
									if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: Add [%s], [%s] to list success\n", csSenderBaidTxnId, csRecipientBaidTxnId));
									} else {
DEBUGLOG(("Authorize:: Add [%s], [%s] to list failed\n", csSenderBaidTxnId, csRecipientBaidTxnId));
									}
									hash_destroy(hList);

									iFound = PD_TRUE;
								}
								hTmp = RecordSet_GetNext(rRecipient);
							}
						}

						if (!strcmp(csSenderPid, csRecipientPid) && !iFound) {
							// find recipient (return)
							RemoveField_CString(hRecipient, "diff_baid");
							PutField_CString(hRecipient, "same_baid", csBaid);

							RecordSet_Destroy(rRecipient);
							recordset_init(rRecipient, 0);
//DEBUGLOG(("Authorize:: call DBOLBAIDTxn::GetSemiAutoReconBaidTxn() -- recipient\n"));
							DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "GetSemiAutoReconBaidTxn");
							iTmpRet = (unsigned long)(*DBObjPtr)(hRecipient, rRecipient);
							if (iTmpRet == PD_OK) {
								hTmp = RecordSet_GetFirst(rRecipient);
								while (hTmp && !iFound) {
									if (GetField_CString(hTmp, "txn_id", &csRecipientBaidTxnId)) {
DEBUGLOG(("Authorize:: recipien_baid_txn_id = [%s]\n", csRecipientBaidTxnId));

										// check keywords
										hash_destroy(hCheckKeywords);
										hash_init(hCheckKeywords, 0);
										PutField_CString(hCheckKeywords, "baid_txn_id", csRecipientBaidTxnId);
										PutField_CString(hCheckKeywords, "psp_id", csRecipientPid);
										PutField_CString(hCheckKeywords, "bank_acct_type", csRecipientBankAcctType);
										PutField_Char(hCheckKeywords, "sr_ind", 'R');
										PutField_Char(hCheckKeywords, "nr_ind", 'R');
										if (CheckKeywords(hCheckKeywords) != PD_OK) {
DEBUGLOG(("Authorize:: keywords not match\n"));
											hTmp = RecordSet_GetNext(rRecipient);
											continue;
										}

										// set hold_recon to true (sender)
										hash_init(hList, 0);
										PutField_CString(hList, "txn_seq", csSenderBaidTxnId);
										PutField_CString(hList, "update_user", csUser);
										PutField_Int(hList, "hold_recon", PD_TRUE);
DEBUGLOG(("Authorize:: call DBOLBAIDTxn::Update()\n"));
										DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "Update");
										iTmpRet = (unsigned long)(*DBObjPtr)(hList);
										if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: Update [%s] hold_recon success\n", csSenderBaidTxnId));
										} else {
DEBUGLOG(("Authorize:: Update [%s] hold_recon failed\n", csSenderBaidTxnId));
										}
										hash_destroy(hList);

										// set hold_recon to true (recipient)
										hash_init(hList, 0);
										PutField_CString(hList, "txn_seq", csRecipientBaidTxnId);
										PutField_CString(hList, "update_user", csUser);
										PutField_Int(hList, "hold_recon", PD_TRUE);
DEBUGLOG(("Authorize:: call DBOLBAIDTxn::Update()\n"));
										DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "Update");
										iTmpRet = (unsigned long)(*DBObjPtr)(hList);
										if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: Update [%s] hold_recon success\n", csRecipientBaidTxnId));
										} else {
DEBUGLOG(("Authorize:: Update [%s] hold_recon failed\n", csRecipientBaidTxnId));
										}
										hash_destroy(hList);

										// add into list
										hash_init(hList, 0);
										PutField_CString(hList, "baid_txn_id_1", csSenderBaidTxnId);
										PutField_CString(hList, "bank_acct_type_1", csSenderBankAcctType);
										PutField_CString(hList, "baid_txn_id_2", csRecipientBaidTxnId);
										PutField_CString(hList, "bank_acct_type_2", csRecipientBankAcctType);
										PutField_Char(hList, "recon_type", 'R');
										PutField_CString(hList, "create_user", csUser);
DEBUGLOG(("Authorize:: call DBOLWaitReconCfmList::Add()\n"));
										DBObjPtr = CreateObj(DBPtr, "DBOLWaitReconCfmList", "Add");
										iTmpRet = (unsigned long)(*DBObjPtr)(hList);
										if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: Add [%s], [%s] to list success\n", csSenderBaidTxnId, csRecipientBaidTxnId));
										} else {
DEBUGLOG(("Authorize:: Add [%s], [%s] to list failed\n", csSenderBaidTxnId, csRecipientBaidTxnId));
										}
										hash_destroy(hList);

										iFound = PD_TRUE;
									}
									hTmp = RecordSet_GetNext(rRecipient);
								}
							}
						}
					}
DEBUGLOG(("Authorize:: --------------------------------------------------\n"));

					hTmp = RecordSet_GetNext(rSender);
				}
			}
		}
	} else {
		// check conflict
DEBUGLOG(("Authorize:: call DBOLSemiAutoReconTriggerLog::CheckConflict()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLSemiAutoReconTriggerLog", "CheckConflict");
		iTmpRet = (unsigned long)(*DBObjPtr)(hRequest);
		if (iTmpRet == PD_FOUND) {
DEBUGLOG(("Authorize:: conflict found\n"));
		} else {
DEBUGLOG(("Authorize:: conflict not found\n"));
			// call background job
DEBUGLOG(("Authorize:: call semi_auto_recon\n"));
			sprintf(csCmd, "%s &", csCmd);
DEBUGLOG(("Authorize:: csCmd = [%s]\n", csCmd));
			system(csCmd);
		}
	}

	hash_destroy(hSender);
	FREE_ME(hSender);
	hash_destroy(hRecipient);
	FREE_ME(hRecipient);
	//hash_destroy(hList);
	FREE_ME(hList);
	//hash_destroy(hPspDetail);
	FREE_ME(hPspDetail);
	hash_destroy(hCheckKeywords);
	FREE_ME(hCheckKeywords);

	RecordSet_Destroy(rSender);
	FREE_ME(rSender);
	RecordSet_Destroy(rRecipient);
	FREE_ME(rRecipient);

DEBUGLOG(("Authorize:: Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}

int CheckKeywords(hash_t *hContext) {
	int iRet = PD_OK;
	int iTmpRet;

	char *csTmp;
	char *csBaidTxnId, *csPspId, *csBankAcctType;
	char cSRInd; // sender_recipient_indicator
	char cNRInd; // normal_return_indicator
	char *csBaidTxnCode;

	hash_t *hTmp;
	hTmp = (hash_t*) malloc (sizeof(hash_t));

	hash_t *hStmtDtl;
	hStmtDtl = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hStmtDtl, 0);

	recordset_t *rKeywords;
	rKeywords = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rKeywords, 0);

	// baid_txn_id
	if (iRet == PD_OK) {
		if (!GetField_CString(hContext, "baid_txn_id", &csBaidTxnId)) {
DEBUGLOG(("CheckKeywords:: baid_txn_id not found\n"));
			iRet = PD_ERR;
		} else {
DEBUGLOG(("CheckKeywords:: baid_txn_id = [%s]\n", csBaidTxnId));
		}
	}

	// psp_id
	if (iRet == PD_OK) {
		if (!GetField_CString(hContext, "psp_id", &csPspId)) {
DEBUGLOG(("CheckKeywords:: psp_id not found\n"));
			iRet = PD_ERR;
		} else {
DEBUGLOG(("CheckKeywords:: psp_id = [%s]\n", csPspId));
		}
	}

	// bank_acct_type
	if (iRet == PD_OK) {
		if (!GetField_CString(hContext, "bank_acct_type", &csBankAcctType)) {
DEBUGLOG(("CheckKeywords:: bank_acct_type not found\n"));
			iRet = PD_ERR;
		} else {
DEBUGLOG(("CheckKeywords:: bank_acct_type = [%s]\n", csBankAcctType));
		}
	}

	// sender_recipient_indicator
	if (iRet == PD_OK) {
		if (!GetField_Char(hContext, "sr_ind", &cSRInd)) {
DEBUGLOG(("CheckKeywords:: sr_ind not found\n"));
			iRet = PD_ERR;
		} else {
DEBUGLOG(("CheckKeywords:: sr_ind = [%c]\n", cSRInd));
		}
	}

	// normal_return_indicator
	if (iRet == PD_OK) {
		if (!GetField_Char(hContext, "nr_ind", &cNRInd)) {
DEBUGLOG(("CheckKeywords:: nr_ind not found\n"));
			iRet = PD_ERR;
		} else {
DEBUGLOG(("CheckKeywords:: nr_ind = [%c]\n", cNRInd));
		}
	}

	// get expected baid_txn_code
	if (iRet == PD_OK) {
		hash_init(hTmp, 0);
DEBUGLOG(("CheckKeywords() call DBOLSemiAutoReconTxncodeMap::GetBaidTxnCode()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLSemiAutoReconTxncodeMap", "GetBaidTxnCode");
		iTmpRet = (unsigned long)(*DBObjPtr)(csBankAcctType, cSRInd, cNRInd, hTmp);
		if (iTmpRet != PD_OK) {
DEBUGLOG(("CheckKeywords() call DBOLSemiAutoReconTxncodeMap::GetBaidTxnCode() failed\n"));
			iRet = PD_ERR;
		} else {
			// get baid_txn_code
			if (!GetField_CString(hTmp, "baid_txn_code", &csBaidTxnCode)) {
DEBUGLOG(("CheckKeywords() baid_txn_code not found\n"));
				iRet = PD_ERR;
			} else {
DEBUGLOG(("CheckKeywords() baid_txn_code = [%s]\n", csBaidTxnCode));
			}
		}
		hash_destroy(hTmp);
	}

	// get statement details by baid txn id
	if (iRet == PD_OK) {
DEBUGLOG(("CheckKeywords() call DBOLStatement::GetStmtDtlByBAIDTxnId()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLStatement", "GetStmtDtlByBAIDTxnId");
		iTmpRet = (unsigned long)(*DBObjPtr)(csBaidTxnId, hStmtDtl);
		if (iTmpRet != PD_OK) {
DEBUGLOG(("CheckKeywords() call DBOLStatement::GetStmtDtlByBAIDTxnId() failed\n"));
			iRet = PD_ERR;
		} else {
			// format_id
			if (!GetField_CString(hStmtDtl, "format_id", &csTmp)) {
DEBUGLOG(("CheckKeywords:: format_id not found\n"));
				iRet = PD_ERR;
			} else {
DEBUGLOG(("CheckKeywords:: format_id = [%s]\n", csTmp));
			}

			// int_bank_code
			if (iRet == PD_OK) {
				if (!GetField_CString(hStmtDtl, "int_bank_code", &csTmp)) {
DEBUGLOG(("CheckKeywords:: int_bank_code not found\n"));
					iRet = PD_ERR;
				} else {
DEBUGLOG(("CheckKeywords:: int_bank_code = [%s]\n", csTmp));
					}
				}

			// acct_ccy
			if (iRet == PD_OK) {
				if (!GetField_CString(hStmtDtl, "txn_ccy", &csTmp)) {
DEBUGLOG(("CheckKeywords:: txn_ccy not found\n"));
					iRet = PD_ERR;
				} else {
DEBUGLOG(("CheckKeywords:: txn_ccy = [%s]\n", csTmp));
					PutField_CString(hStmtDtl, "acct_ccy", csTmp);
				}
			}

			if (iRet == PD_OK) {
				PutField_CString(hStmtDtl, "bank_acct_type", csBankAcctType);
				PutField_CString(hStmtDtl, "baid_txn_code", csBaidTxnCode);
			}
		}
	}

	// get keywords
	if (iRet == PD_OK) {
DEBUGLOG(("CheckKeywords() call DBOLStmtFormat::GetTxnCodeKeywordsSingle()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLStmtFormat", "GetTxnCodeKeywordsSingle");
		iTmpRet = (unsigned long)(*DBObjPtr)(hStmtDtl, rKeywords);
		if (iTmpRet != PD_FOUND) {
DEBUGLOG(("CheckKeywords() call DBOLStmtFormat::GetTxnCodeKeywordsSingle() failed\n"));
			iRet = PD_ERR;
		}
	}

	// check keywords
	if (iRet == PD_OK) {
DEBUGLOG(("CheckKeywords() call BOOLBankStmt::CheckKeywords()\n"));
		BOObjPtr = CreateObj(BOPtr, "BOOLBankStmt", "CheckKeywords");
		iTmpRet = (unsigned long)(*BOObjPtr)(hStmtDtl, rKeywords);
		if (iTmpRet != PD_OK) {
DEBUGLOG(("CheckKeywords() call BOOLBankStmt::CheckKeywords() failed\n"));
			iRet = PD_ERR;
		}
	}

	// hash destroy
	FREE_ME(hTmp);
	hash_destroy(hStmtDtl);
	FREE_ME(hStmtDtl);
	// recordset destroy
	RecordSet_Destroy(rKeywords);
	FREE_ME(rKeywords);

DEBUGLOG(("CheckKeywords() exit iRet = [%d]\n", iRet));
	return iRet;
}
