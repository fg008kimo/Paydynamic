#ifndef	_INTERNAL_H_
#define	_INTERNAL_H_

#define		INT_NO_ERR			0	/* NO ERR */
#define		INT_OTHER_ERR			1	/* other Error */
#define		INT_ERR				1000  	/* Internal Error */
#define         INT_BREAKDOWN_ERR               1001    /* BreakDown Message Error */
#define		INT_FORMAT_ERR			1002	/* Format Error */
#define         INT_MAC_ERR                     1003    /* Verify Mac Error */
#define         INT_INVALID_TXN                 1004    /* Invalid Transaction */
#define		INT_TXN_COUNTRY_NOT_FOUND	1005	/* Txn Country not Found */	
#define		INT_MERCHANT_ID_NOT_FOUND	1006	/* merchant id not found */
#define		INT_ACCOUNT_DISABLED		1007	/* account disabled */
#define		INT_DUP_MERCHANT_REF		1008	/* duplicate merchant ref */

#define		INT_INVALID_PAY_AMOUNT		1009	/*invalid pay amount*/
#define		INT_PAY_AMOUNT_NOT_FOUND	1010	/*Pay amount not found*/
#define		INT_INVALID_CURRENCY_CODE	1011	/*invalid currency code*/
#define		INT_CURRENCY_CODE_NOT_FOUND	1012	/*currency code not found*/
#define		INT_REFERENCE_NOT_FOUND		1013	/*reference not found*/
#define		INT_TRASMISSION_TIME_NOT_FOUND	1014	/*transmission time not found*/
#define		INT_PAYMETHOD_NOT_FOUND		1015	/*pay method not found*/
#define		INT_BANK_CODE_NOT_FOUND		1016	/*bank code not found*/
#define		INT_INVALID_SHOW_PAYPAGE	1017	/*invalid show paypage*/
#define		INT_SHOW_PAYPAGE_NOT_FOUND	1018	/*show paypage not found*/
#define		INT_SUCC_URL_NOT_FOUND		1019	/*success url not found*/
#define		INT_SUCC_CB_URL_NOT_FOUND	1020	/*success callback url not found*/
#define		INT_FAIL_URL_NOT_FOUND		1021	/*fail url not found*/
#define		INT_FAIL_CB_URL_NOT_FOUND	1022	/*fail callback url not found*/
#define		INT_MAC_NOT_FOUND		1023	/*mac not found*/
#define		INT_ORG_TXN_NOT_FOUND		1024	/*org txn not found */
#define		INT_TXN_ID_NOT_FOUND		1025	/*txn id not found */
#define		INT_DEBLOCK_DATA_ERROR		1026	/*DEBlock data error */
#define		INT_SIGN_DATA_NOT_FOUND		1027	/*Signature not found */
#define		INT_ACK_NOT_YET_RETURN		1028	/*PSP Ack Not Yet Return */
#define		INT_BRANCH_NAME_NOT_FOUND	1029	/*bank branch name not found */
#define		INT_BANK_AC_ID_NOT_FOUND	1030	/*bank account id not found */
#define		INT_BANK_AC_NAME_NOT_FOUND	1031	/*bank account name not found */
#define		INT_IDENTITY_ID_NOT_FOUND	1032	/*Identity ID not found */
#define		INT_ERROR_CONN_PSP		1033	/*Error Connecting to PSP */
#define		INT_COUNTRY_PSP_NOT_AVABILE	1034	/*Country PSP No Available*/
#define		INT_UNSUPPORTED_PAY_AMOUNT	1035	/*Unsupported pay amount */
#define		INT_RECORD_MISMATCH		1036	/*record mismatch */
#define         INT_NOT_RECORD                  1037    /*not record */
#define         INT_PSP_RETURN_ERROR            1038    /*psp error */
#define		INT_UNSUPPORTED_ENC_TYPE	1039	/*unsupported Encryption type */
#define		INT_EXCEED_LIMIT_PSP_CNT	1040	/*Exceed Txn limit Count */
#define		INT_EXCEED_LIMIT_PSP_AMT	1041	/*Exceed Txn limit Amount*/
#define		INT_EXCEED_LIMIT_MER_CNT	1042	/*Exceed Txn Account limit Count */
#define		INT_EXCEED_LIMIT_MER_AMT	1043	/*Exceed Txn Account limit Amount */
#define		INT_EX_RATE_ERROR		1044	/*Exchange Rate Error */
#define		INT_INVALID_ENCODING		1045	/*invalid encoding */
#define		INT_CUSTOMER_NAME_NOT_FOUND	1046	/*customer name not found */
#define		INT_FAMILY_NAME_NOT_FOUND	1047	/*Customer's Family Name Not found */
#define		INT_PHONE_NOT_FOUND		1048	/*Customer Tel Phone Not Found */
#define		INT_INSUFFICIENT_FUND		1049	/*insufficient fund */
#define		INT_SERVICE_CODE_MISSING	1050	/*service code is missing */
#define		INT_CURRENCY_ID_NOT_MATCH	1051	/*Currency id not match */
#define		INT_NO_PENDING_RECORD		1052    /*No Pending Record*/ //for payout pre-generate
#define		INT_NO_LB_RECORD		1053	/*No Load Balancer rule define for the txn */
#define		INT_PSP_NOT_AVAILABLE		1054	/*no psp available */
#define		INT_UNSUPPORTED_PAY_METHOD	1055 	/*Unsupported pay method */
#define		INT_PENDING_TXN			1056	/*Pending Txn*/ //for deposit callback
#define		INT_NO_PAYOUT_MATCH_RULE	1057	/*No Payout txn match the rule*/ //for payout preview
#define		INT_MERCHANT_RESERVE_NOT_FOUND	1058	/*Reserve rate for Merchant not found*/
#define		INT_MERCHANT_IGNORE_NACK	1059	/*Merchant Ignore NACK*/
#define		INT_MIN_SETTLE_AMT_NOT_FOUND	1060	/*Merchant Bal Acct min settle amount not found*/
#define		INT_INVALID_MAGIC_NUM    	1061	/*invalid magic number */

#define		INT_INVALID_MAX_PAY_AMOUNT_VP   1062	/*invalid Max. pay amount on Voucher Payment*/
#define         INT_EXCEED_LIMIT_MER_CNT_VP     1063    /*Exceed Txn Account limit Count on Voucher Payment*/
#define		INT_INVALID_MIN_PAY_AMOUNT_VP   1064	/*invalid Min. pay amount on Voucher Payment*/
#define		INT_CUSTOMER_ACCT_DISABLED      1065	/*Customer Account Disabled*/
#define		INT_VP_GROUP_CLOSED		1066	/*VP Group Closed*/
#define		INT_NO_BANK_AVAILABLE		1067	/*No Bank Available*/
#define		INT_DEPOSIT_FLOW_MISSING	1068	/* Deposit Flow is missing from request */
#define		INT_CUST_DEPOSIT_DATE_MISSING	1069	/* Customer Deposit Date is missing from Request*/
#define		INT_BANK_ACCT_NUM		1070	/* Bank Acct Num is missing from Request*/
#define		INT_DEPOSIT_BANK_MISSING	1071	/* Deposit Bank is missing from Request*/
#define		INT_RECON_PAYOUT_FOUND		1072	/* Reconciled Payout Found */

#define		INT_HOLD_TYPE_NOT_FOUND		1073	/* Hold Type not found */
#define		INT_TXN_TYPE_NOT_FOUND		1074	/* Txn Type not found */
#define		INT_TXN_ID_IS_LOCKED		1075	/* Txn ID is locked */

#define		INT_CLIENT_R01_MISSING		1076	/* Client R01 missing */
#define		INT_CLIENT_R02_MISSING		1077	/* Client R02 missing */


#define		INT_BANK_NAME_NOT_FOUND   	1078	/* Bank Name Not Found */
#define		INT_BANK_PROV_NOT_FOUND   	1079	/* Province of Bank Not Found */
#define		INT_BANK_CITY_NOT_FOUND   	1080	/* City of Bank Not Found */
#define		INT_PAYOUT_GRP_NOT_FOUND 	1081	/* Payout Group Not Found */
#define		INT_INVALID_PAYOUT_GRP		1082	/* Invalid Payut Group */
#define		INT_INVALID_BANK_AC_NAME	1083	/* Invalid Bank Account Name */
#define		INT_INVALID_MERCHANT_REF	1084	/* Invalid merchant ref */
#define		INT_INVALID_VERSION		1085	/* Invalid Version */
#define		INT_INVALID_CUSTOMER_TAG        1086	/* Invalid Customer Tag*/

#define		INT_TXN_EXPIRED                 1087	/* Transaction Expired */

#define		INT_PAID_AMOUNT_NOT_FOUND	1088	/* Consumer Paid Amount Not Found */
#define		INT_INVALID_PAID_AMOUNT		1089	/* Invalid Consumer Paid Amount */
#define		INT_UNSUPPORTED_PAID_AMOUNT	1090	/* Unsupported Consumer Paid Amount */
#define		INT_AMT_DIFF_NOT_IN_RANGE	1091	/* Amount Difference Not In Range */

#define		INT_INVALID_TRASMISSION_TIME	1092	/* Invalid Transmission Time */
#define		INT_INVALID_URL			1093	/* Invalid URL */
#define		INT_INVALID_IDENTITY_ID		1094	/* Invalid Identity ID */
#define		INT_INVALID_BANK_AC_NUM		1095	/* Invalid Bank Account Num */
#define		INT_INVALID_BANK_NAME		1096	/* Invalid Bank Name */
#define		INT_INVALID_TW_BANK_CODE	1097	/* Invalid TW Bank Code */
#define		INT_INVALID_BRANCH		1098	/* Invalid Branch */
#define		INT_INVALID_BANK_PROV		1099	/* Invalid Province of Bank */
#define		INT_INVALID_BANK_CITY		1100	/* Invalid City of Bank */
#define		INT_INVALID_PHONE_NUM		1101	/* Invalid Phone Num */
#define		INT_INVALID_REMARK		1102	/* Invalid Remark */

//For deposit response
#define		INT_DEPOSIT_PROCESSING		1999	/* Deposit request still processing*/

//For Merchant
#define         INT_OPERATION_AGENT_DECLINED    3000    /* Operation Agent Declined */

//MGT Channel
#define		INT_INVALID_COUNT		5001	/*invalid count*/
#define		INT_TXN_ID_MISSING		5002	/*txn id is missing */
#define		INT_TXN_AMT_MISSING		5003	/*txn amount is missing */
#define		INT_INVALID_SERVICE_CODE	5004	/*invalid service code */
#define		INT_ENC_TXN_ID_MISSING		5005	/*encyrpted txn id is missing */
#define		INT_PHDATE_NOT_FOUND            5006    /*PhDate Not Found */
#define		INT_CUSTOMER_TYPE_NOT_FOUND     5007    /*Customer type Not Found */
#define		INT_STATUS_NOT_FOUND            5008    /*Status Not Found */
#define		INT_CLIENT_ID_NOT_FOUND         5009    /*Client Id Not Found */
#define		INT_PSP_ID_NOT_FOUND            5010    /*Psp Id Not Found */
#define		INT_OPTION_TYPE_NOT_FOUND       5011    /*Option Type Not Found */

#define		INT_PARTY_TYPE_NOT_FOUND	5012	/*Party Type Not Found */
#define		INT_DC_IND_NOT_FOUND		5013	/*DC Ind Not Found */
#define		INT_DESC_NOT_FOUND		5014	/*Desc Not Found */
#define		INT_ACTION_NOT_FOUND		5015	/*Action Not Found */
#define		INT_CODE_ERROR     		5016	/*Get Code Error*/
#define		INT_PROCESS_VALIDATE_ERROR	5017	/*Process Validation Error*/
#define		INT_ADJUSTMENT_PROCESS_ERROR	5018	/*Adjustment Process Error*/
#define		INT_CODE_DISABLED		5019	/*Code Disabled */

#define		INT_MB_ID_NOT_FOUND   		5020	/* MB ID Not Found */
#define		INT_BANK_ID_NOT_FOUND   	5021	/* Bank ID Not Found */
#define		INT_INVALID_PARTY_TYPE		5022	/* invalid Party Type */
#define		INT_PARTY_ID_NOT_FOUND 		5023	/* Party ID Not Found */
#define		INT_BUSINESS_TYPE_NOT_FOUND 	5024	/* Business Type Not Found */ 

#define		INT_MERCHANT_NAME_NOT_FOUND 	5025	/* Merchant Name Not Found */ 
#define		INT_KEY_TYPE_NOT_FOUND 		5026	/* Key Type Not Found */ 
#define		INT_KEY_VALUE_NOT_FOUND 	5027	/* Key Value Not Found */ 

#define		INT_DUP_HOST_REF		5028	/* Duplicate Host Ref*/

#define		INT_AMT_TYPE_NOT_FOUND          5029	/* Amount Type not found */

#define		INT_NOT_ALLOW_DIFF_COUNTRY	5030	/* Different country not allowed *///for TFF and RTF
#define		INT_NO_RIGHTS_TO_CANCEL		5031	/* No rights to cancel*///for STC

#define         INT_INVALID_MERCH_ID            5032    /* Invalid Merchant ID */
#define		INT_ALREADY_APPROVED		5033	/*Already Approved*/
#define		INT_LARGE_DIFF_NEW_RATE		5034	/*Difference between old rate and new rate is too large*/
#define		INT_SETTLE_AMT_TOO_SMALL	5035	/*settlement amount too small*/

#define		INT_BANK_ACCT_DUPLICATE         5036    /* Bank Acct Number Duplicate */
#define		INT_ALREADY_FROZEN_STATUS       5037    /* Already in Frozen Status */
#define		INT_MOBILE_NUM_DUPLICATE	5038    /* Mobile Number Duplicate*/
#define		INT_CUSTOMER_SEGMENT_NOT_FOUND	5039    /* Cuntomer Segment Not Found*/

//Error Code for Statement/Deposit File Management
#define		INT_FILE_NOT_FOUND		5040    /* File Not Found */
#define		INT_USER_NOT_FOUND		5041    /* User Not Found */
#define		INT_BANK_ACCT_NOT_FOUND		5042	/* Bank Acct Not Found */
#define		INT_BANK_ACCT_NOT_AVAILABLE	5043	/* Bank Acct Not Available */

#define		INT_FILE_ALREADY_EXIST		5044    /* File Duplicated */
#define		INT_BANK_ACCT_NOT_MATCH		5045    /* Bank Acct Not Match with BANK_ACCT_ROW */
#define		INT_FORMAT_TEMPLATE_ERROR	5046    /* File Template Error */
#define		INT_FORMAT_KEYWORDS_ERROR	5047    /* File Keywords Error */

#define		INT_RUNNING_BALANCE_ERROR	5048    /* Running balance Error */
#define		INT_HEADER_FIELD_ERROR		5049	/* Header Field Error */
#define		INT_DETAIL_FIELD_ERROR		5050    /* Detail Field Error */
#define		INT_CHECKSUM_ERROR		5051    /* checksum error */
#define		INT_BANK_ACCT_ID_NOT_FOUND	5053    /* Bank Acct ID Not Found */

#define		INT_MERCHANT_ID_MISMATCH	5054    /* Merchant Id Mismatch */
#define		INT_SERVICE_MISMATCH		5055    /* Service Mismatch */
#define		INT_INVALID_FILE_FORMAT		5056	/* Invalid file format */

#define         INT_INVALID_BAID                5057    /* Invalid BAID */
#define         INT_OTHER_OPEN_BAID_FOUND       5058    /* Other Open BAID Found */
#define         INT_INVALID_BAID_STATUS         5059    /* Invalid BAID Status */

#define         INT_INVALID_BANK_ACCT_TYPE	5060    /* Invalid Bank ACCt Type */
#define         INT_BAID_ALREADY_EXISTS         5061    /* Invalid Bank ACCt Type */

#define         INT_INVALID_FILE_NAME		5062    /* Invalid File Name*/

#define         INT_NATURE_NOT_FOUND		5063	/* Nature Not Found */

#define         INT_PENDING_ALREADY_EXIST	5064	/* File Pending */
#define		INT_EMAIL_ALERT_FAILURE		5065	/* Send Email Alert Error */

#define		INT_MOBILE_NOT_FOUND		5066	/* Mobile number not found */
#define		INT_CARRIERS_NOT_FOUND		5067	/* Sim Carrier not found */
#define		INT_SIM_CREDIT_NOT_FOUND	5068	/* Sim Credit not found */
#define		INT_SIM_PACKAGE_NOT_FOUND	5069	/* Sim Package not found */
#define		INT_LAST_TOPUP_DATE_NOT_FOUND	5070	/* Last Topup Date not found */
#define		INT_NEXT_TOPUP_DATE_NOT_FOUND	5071	/* Next Topup Date not found */
#define         INT_SIM_COUNTRY_NOT_FOUND       5072    /* Sim Country not found */
#define		INT_MOBILE_NOT_SYNC_WITH_ACCT	5073	/* Mobile number not sync with bank acct */
#define		INT_MOBILE_USED_IN_SAME_BANK	5074	/* Mobile number used in same bank */

#define		INT_REC_ALREADY_EXISTS          5075	/* Record Already Exists */

#define		INT_BAID_UNDER_PSP_CAT_EXISTS	5076	/* Baid under same PID and Category Already Exists */
#define		INT_NEXT_PID_CODE_ERROR		5077	/* Next Pid Code Error */

#define 	INT_INVALID_BANK_ID		5078	/* Invalid Bank Id */

#define 	INT_FILE_ID_NOT_FOUND		5079	/* File Id Not Found */
#define 	INT_INVALID_FILE_ID		5080	/* Invalid File Id */
#define 	INT_STATEMENT_SEQ_NOT_FOUND	5081	/* Bank Statement Seq Not Found */
#define 	INT_STATEMENT_VER_NOT_FOUND	5082	/* Bank Statement Ver Not Found */
#define         INT_STATEMENT_INVALID_SEQ       5083    /* Bank Statement Invalid Seq */
#define         INT_STATEMENT_INVALID_VER       5084    /* Bank Statement Invalid Ver */
#define         INT_STATEMENT_RECORD_DELETED    5085    /* Bank Statement Record Deleted */

#define		INT_OLD_MOBILE_NOT_FOUND	5086	/* Old mobile number not found */
#define		INT_NEW_MOBILE_NOT_FOUND	5087	/* New mobile number not found */

#define		INT_TRIGGER_TYPE_NOT_FOUND	5088	/* OL Stmt match trigger not found */
#define		INT_AC_NATURE_NOT_FOUND		5089	/* OL Stmt match acct nature not found */
#define		INT_BAID_TXN_CODE_NOT_FOUND	5090	/* OL Stmt match BAID txn code not found */

#define 	INT_TXN_SUB_STATUS              5091    /* Invalid Txn Sub-status */

#define		INT_BANK_ACCT_TYPE_NOT_FOUND	5092	/* Psp txn engine Bank Acct Type not found */
#define		INT_TXN_CODE_NOT_FOUND		5093	/* Psp txn engine Txn Code not found */
#define		INT_INPUT_CHANNEL_NOT_FOUND	5094	/* Psp txn engine Input Channel not found */
#define		INT_ACTION_ID_NOT_FOUND		5095	/* Psp txn spc action Action ID not found */

#define		INT_ACK_RETRY_PROCESSING	5096	/* System auto-resend callback still processing*/
#define		INT_LARGE_DIFF_OANDA_NEW_RATE	5097	/* Difference between oanda rate and new rate is too large*/

#define         INT_EML_FUNCT_NOT_FOUND         5098    /* Email Funct not found */
#define         INT_EML_EMAIL_ADDR_NOT_FOUND    5099    /* Email Addr not found */

#define		INT_TXN_ENGINE_CONFIG_MISSING	5100	/* Txn Engine Configuration is missing */

#define		INT_CUST_CNT_EXCEED_LIMIT	5101	/* Customer Count Exceed Limit Already */

#define         INT_EML_EMAIL_ADDR_NOT_REG      5102    /* Email Addr not registered */

#define         INT_REMARK_NOT_FOUND            5103    /* Remark not found */

#define         INT_FILE_NAME_NOT_FOUND         5104    /* File Name Not Found */
#define         INT_FILE_NAME_ALREADY_EXIST     5105    /* File Name Already Existed */

#define         INT_AUTO_UPLOAD_BANK_ACCT_DIS   5106    /* Auto Upload Bank Acct Disabled */
#define         INT_AUTO_UPLOAD_BANK_DIS        5107    /* Auto Upload Bank Disabled */

#define         INT_INVALID_NATURE		5108	/* Invalid Nature */
#define         INT_SMS_CREATE_DATE_NOT_FOUND   5109    /* SMS Create Date Not Found */ 
#define         INT_INVALID_SMS_CREATE_DATE     5110    /* Invalid SMS Create Date */
#define         INT_RECORD_NOT_FOUND		5111	/* Record Not Found */
#define		INT_INSUFFICIENT_BAID_AVAIL_BAL	5112	/* Insufficient BAID Available Balance */	
#define		INT_EXCEED_TXN_AMT_LIMIT	5113	/* Exceed Txn Amount Limit */	
#define         INT_BAID_BALANCE_NOT_FOUND      5114    /* BAID Balance Not Found */
#define         INT_AUTO_UPLOAD_IND_NOT_FOUND   5115    /* Auto Upload Indicator Not Found */
#define         INT_INVALID_BANK_ACCT_STATUS    5116    /* Invalid Bank Acct Status */
#define         INT_INVALID_AUTO_UPLOAD_IND     5117    /* Invalid Auto Upload Indicator */
#define         INT_INVALID_PID_STATUS          5118    /* Invalid PID Status */
#define         INT_INVALID_PROVIDER_STATUS     5119    /* Invalid Provider Status */
#define         INT_INVALID_SYS_SWITCH_ENABLED  5120    /* Invalid Bank Account System Switch Enabled */
#define         INT_AUTO_UPLOAD_PROVIDER_DIS    5121    /* Auto Upload Provider Disabled */
#define         INT_AUTO_UPLOAD_BANK_NOT_FOUND	5122    /* Auto Upload Bank Not Found */
#define         INT_AUTO_UPLOAD_BANK_ACCT_NOT_FOUND	5123    /* Auto Upload Bank Acct Not Found */
#define         INT_AUTO_UPLOAD_PROVIDER_NOT_FOUND 	5124    /* Auto Upload Provider Not Found */
#define         INT_UNSUPPORTED_BANK_CODE     	5125    /* Unsupported Bank Code (SystemAccount) */
#define         INT_BAL_OVER_IND_NOT_FOUND    	5126    /* Balance Override Indicator Not Found */
#define         INT_INVALID_BAL_OVER_IND     	5127    /* Invalid Balance Override Indicator */
#define         INT_EXISTING_ASSOCIATED_BAID_OPEN       5128    /* Existing associated BAID open */
#define         INT_BANK_ACCT_NATURE_NOT_MATCH 	5129    /* Bank Account Nature Not Match to associated BAID Nature */
#define         INT_FAIL_TO_READ_FILE           5130    /* Bank statement upload fail to read converted file */

#define		INT_RECORD_CNT_NOT_FOUND	5131	/* Record Count not Found */
#define		INT_INVALID_INIT_STATUS		5132	/* Invalid Init Status */
#define		INT_SEQ_NOT_FOUND		5133	/* Sequence No. not Found */
#define		INT_RECORD_CNT_INVALID		5134	/* Record Count Invalid */
#define		INT_BANK_ACCT_NAME_NOT_FOUND	5135	/* Bank Acct Name not Found */
#define		INT_BANK_ACCT_SHORT_NAME_NOT_FOUND	5136	/* Bank Acct Short Name not Found */
#define		INT_PARTIAL_RECORD_INVALID	5137	/* Partial Record Invalid */

#define		INT_BAID_NOT_FOUND		5138	/* BAID Not Found */
#define		INT_INVALID_BAID_BALANCE	5139	/* BAID Balance Invalid*/
#define		INT_ADJ_TXN_CODE_NOT_FOUND	5140	/* Adjustment Txn Code Not Found*/
#define		INT_INVALID_IN_TRANSIT		5141	/* Invalid In Transit */
#define		INT_INVALID_TOTAL_HOLD		5142	/* Invalid Total Hold */
#define		INT_IN_TRANSIT_NOT_FOUND	5143	/* IN TRANSIT NOT FOUND */
#define		INT_TOTAL_HOLD_NOT_FOUND	5144	/* TOTAL HOLD NOT FOUND */

#define         INT_REQ_DATETIME_NOT_FOUND    	5145    /* Request Datetime Not Found */
#define         INT_INVALID_REQ_DATETIME     	5146    /* Invalid Request Datetime */
#define         INT_INVALID_BANK_CODE         	5147    /* Invalid Bank Code */
#define         INT_INVALID_BANK_ACCT          	5148    /* Invalid Bank Acct */
#define         INT_DATA_REQUEST_ERROR          5149    /* Data Request Error */

#define 	INT_PREV_TXN_BAL_UPD_NOT_CPL    5150    /* Previous Update Job Not Completed */
#define         INT_TXN_BAL_LOG_EXISTS     	5151    /* Update Job exists already */
#define 	INT_TXN_BAL_NULL_EXISTS         5152    /* Transaction Balance Information is NULL */
#define     	INT_MERCH_ID_BLKLST_DISABLED    5153    /* Merchant ID Black list disabled*/


#define		INT_BLANK_PROVIDER		5901	/*Bank Account Provider cannot be blank*/
#define		INT_PROVIDER_NOT_FOUND		5902	/*Bank Account Provider is not found*/
#define		INT_BLANK_NATURE		5903	/*Bank Account Nature cannot be blank*/
#define		INT_ACCT_NATURE_NOT_FOUND	5904	/*Bank Account Nature is not found*/
#define		INT_BLANK_BANK_NAME		5905	/*Bank Name cannot be blank*/
#define		INT_BANK_NAME_IS_NOT_FOUND	5906	/*Bank Name is not found*/
#define		INT_BLANK_BANK_ACCT_NUM		5907	/*Bank Account Number cannot be blank*/
#define		INT_BANK_ACCT_NUM_DUPLICATE	5908	/*Bank Account Number Duplicate*/
#define		INT_EXISTING_ASSOCIATED_BAID_NOT_CLOSE	5909	/*Existing associated BAID must be closed first*/
#define		INT_BLANK_OWNER_NAME		5910	/*Owner Name cannot be blank*/
#define		INT_BLANK_PROVINCE		5911	/*Province cannot be blank*/
#define		INT_BLANK_CITY			5912	/*City cannot be blank*/
#define		INT_BLANK_BRANCH_NAME		5913	/*Branch Name cannot be blank*/
#define		INT_BLANK_INIT_BAL		5914	/*Initial Balance cannot be blank*/
#define		INT_INVALID_FORMAT_INIT_BAL	5915	/*Invalid format of Initial Balance*/
#define		INT_ALL_REJECTED		5916	/*All rejected*/
#define		INT_MER_SHORT_NAME_BLANK	5917	/*Merchant Short Name cannot be blank for a deposit account*/
#define		INT_MER_SHORT_NAME_FAIL_ASSOCIATE	5918	/*Failed to associate with Merchant Short Name*/
#define		INT_MER_SHORT_NAME_NOT_EMPTY	5919	/*Merchant Short Name should be empty for a payout or intermediate account*/
#define		INT_INVALID_FILE_FORMAT_ERR	5920	/*Error occurred: Invalid file format*/
#define		INT_FAIL_CREATE_BANK_ACCT	5921	/*Failed to create Bank Account*/
#define		INT_FAIL_CREATE_BAID		5922	/*Failed to create BAID*/
#define		INT_FAIL_ASSOCIATE_MERCHANT	5923	/*Failed to associate Merchant*/
#define		INT_INVALID_FORMAT_PROVIDER	5924	/*Invalid format of Bank Account Provider*/
#define		INT_INVALID_FORMAT_NATURE	5925	/*Invalid format of Bank Account Nature*/
#define		INT_INVALID_FORMAT_BANK_NAME	5926	/*Invalid format of Bank Name*/
#define		INT_INVALID_FORMAT_BANK_ACCT_NUM	5927	/*Invalid format of Bank Account Number*/
#define		INT_INVALID_FORMAT_OWNER_NAME	5928	/*Invalid format of Owner Name*/
#define		INT_INVALID_FORMAT_PROVINCE	5929	/*Invalid format of Province*/
#define		INT_INVALID_FORMAT_CITY		5930	/*Invalid format of City*/
#define		INT_INVALID_FORMAT_BRANCH_NAME	5931	/*Invalid format of Branch Name*/
#define		INT_INVALID_FORMAT_SMS_STMT	5932	/*Invalid format of SMS Statement Enable*/
#define		INT_INVALID_FORMAT_REG_MOB_NUM	5933	/*Invalid format of Registered Mobile Number*/
#define		INT_INVALID_FORMAT_DEP_COST	5934	/*Invalid format of Apply Deposit Cost*/
#define		INT_INVALID_FORMAT_MER_SHORT_NAME	5935	/*Invalid format of Merchant Short Name*/
#define		INT_INVALID_FORMAT_BANK_ACCT_SHORT_NAME	5936	/*Invalid format of Bank Account Short Name*/
#define		INT_BLANK_REG_MOB_NUM		5937	/*Registered Mobile Number cannot be blank*/
#define		INT_DISPOSED_BANK_ACCT_DIFF_PROVIDER		5938	/*Existing Bank Account (Disposed) with different Providers*/
#define		INT_BLANK_SENDER_BANK_NAME	5939	/*Bank Name (Sender) cannot be blank*/
#define		INT_SENDER_BANK_NAME_NOT_FOUND	5940	/*Bank Name (Sender) is not found*/
#define		INT_BLANK_SENDER_BANK_ACCT_NUM	5941	/*Bank Account Number (Sender) cannot be blank*/
#define		INT_SENDER_NOT_BELONG_TO_SELECTED_PROVIDER	5942	/*Bank Account Number (Sender) does not belong to selected provider*/
#define		INT_SENDER_ASSOCIATED_INVALID_BAID	5943	/*Bank Account Number (Sender) has no valid associated BAID*/
#define		INT_SENDER_ASSOCIATED_BAID_NOT_DEPOSIT	5944	/*Bank Account Number (Sender) associated BAID is not deposit nature*/
#define		INT_SENDER_CANNOT_BE_SYSTEM_ACCT	5945	/*Bank Account Number (Sender) cannot be system account*/
#define		INT_BLANK_SWEEP_OUT_AMT		5946	/*Sweep Out Amount cannot be blank*/
#define		INT_INVALID_SWEEP_OUT_AMT	5947	/*Sweep Out Amount is invalid*/
#define		INT_SWEEP_OUT_AMT_EXCEED_TXN_AMT_LIMIT	5948	/*Sweep Out Amount exceeds transaction amount limit*/
#define		INT_BLANK_RECIPIENT_BANK_NAME	5949	/*Bank Name (Recipient) cannot be blank*/
#define		INT_RECIPIENT_BANK_NAME_NOT_FOUND	5950	/*Bank Name (Recipient) is not found*/
#define		INT_BLANK_RECIPIENT_BANK_ACCT_NUM	5951	/*Bank Account Number (Recipient) cannot be blank*/
#define         INT_RECIPIENT_BANK_ACCT_NUM_NOT_FOUND   5952    /*Bank Account Number (Recipient) is not found*/
#define		INT_RECIPIENT_ASSOCIATED_INVALID_BAID	5953	/*Bank Account Number (Recipient) has no valid associated BAID*/
#define		INT_RECIPIENT_ASSOCIATED_BAID_NOT_PAYOUT	5954	/*Bank Account Number (Recipient) associated BAID is not payout nature*/
#define		INT_RECIPIENT_CANNOT_BE_SYSTEM_ACCT	5955	/*Bank Account Number (Recipient) cannot be system account*/
#define		INT_FAIL_CREATE_BAID_BALANCE_INTRA_TXN	5956	/*Failed to create BAID Balance Intra transactions*/
#define		INT_SENDER_BANK_ACCT_NUM_NOT_FOUND	5957	/*Bank Account Number (Sender) is not found*/


#define         INT_UNKNOWN_TXN_EXISTS          6000    /* Unknown Baid Transaction Found */
#define         INT_UNRECON_TXN_EXISTS          6001    /* Unreconciled Transaction Found */

#define		INT_GEN_UNIQUE_AMT_NOT_FOUND	6002	/* Gen Unique Amt not found */
#define		INT_BAID_COUNTRY_NOT_FOUND	6003	/* Baid Country not found */
#define		INT_TXN_CODE_NOT_AVAILABLE	6004	/* Txn Code not available */

#define		INT_EXPIRED_DATE_NOT_FOUND	6005	/* Expired Date not found */

#define		INT_LAST_BANK_STMT_BAL_ERROR	6006    /* Last Bank Statement Balance Error */
#define         INT_BANK_STMT_DATETIME_ERROR    6007    /* Bank Statement Date Time Error */
 
#define 	INT_DISABLED_NOT_FOUND		6008	/* Disabled not found */

#define         INT_ADJ_TYPE_MAX_CODE_INVALID   6009    /* Adj Type Max Code invalid */

#define         INT_RECON_IN_ANOTHER_PROCESS    6010    /* Record is in reconcile progress in another process */

#define         INT_BANK_STMT_RECORD_DUPLICATE  6011    /* Bank Statement Record Duplicate */

#define         INT_BAID_MANUAL_HOLD_RECON  	6012    /* Baid Manual Hold Recon */

#define         INT_OTHER_PAYOUT_PROCESSING  	6013    /* Other payout generation is processing*/

#define         INT_OTHER_VOID_PROCESSING       6014    /* Other void transaction is processing*/

#define		INT_BATCH_ID_NOT_FOUND		6015	/* Batch ID not found */
#define		INT_NEW_PAYOUT_GRP_NOT_FOUND	6016	/* New Payout Group not found */
#define		INT_NEW_PAYOUT_GRP_NOT_SUPPORT	6017	/* New Payout Group not support */
#define		INT_ORG_PAYOUT_GRP_NOT_SUPPORT	6018	/* Original Payout Group not support */
#define		INT_PAYOUT_STATUS_NOT_SUPPORT	6019	/* Payout Status not support */

#define         INT_TXN_CODE_NOT_MATCH          6020    /* Txn Code Not Match */
#define         INT_TXN_STATUS_NOT_MATCH        6021    /* Txn Status Not Match */

#define		INT_BAID_NOT_OPEN		6022	/* BAID status is not open */
#define		INT_PID_NOT_OPEN		6023	/* PID status is not open */
#define		INT_PID_PRODUCT_CODE_EMPTY	6024	/* PID Product Code Mapping not found */
#define		INT_STMT_RECON_ALREADY		6025	/* Statement already reconciled */

// Added by Simon Fung on 2011/06/29 for Journal Mgt Error
#define		INT_JL_INVALID_MSG_FORMAT	2001	/*Invalid Message Format Error */

#define		INT_SPECIAL_CODE		99999999
#define		INT_SKIP_BUT_OK			90000000

#define		INT_LEVEL_NOT_FOUND		6026	/* Level Not Found */
#define		INT_LEVEL_INVALID		6027	/* Input Level Invalid */
#define		INT_DISABLED_INVALID		6028	/* Input Disabled Invalid */ 	

#define		INT_ENGINE_CONFIG_CODE_NOT_FOUND	6029	/* Engine Config Code not found */
#define		INT_STMT_MATCH_CONFIG_VAL_NOT_FOUND	6030	/* Statement Match Config Value not found */		 

#define		INT_DEPOSIT_TRACE_OFF		6031	/* Deposit Trace is OFF */
/* PRD171 Add reason for edit */
#define		INT_REASON_EDIT_NOT_FOUND	6032	/* Reason edit not found */

//MMS
#define		INT_MMS_NODE_ID_NOT_FOUND	7001	/* MMS Node ID not Found */
#define		INT_MMS_ENTITY_ID_NOT_FOUND	7002	/* MMS entity ID not found */
#define		INT_MMS_ENTITY_BAL_ACCT_NOT_FOUND	7003	/* MMS entity bal acct not found */
#define		INT_MMS_ENTITY_BAL_ACCT_DISABLED	7004	/* MMS entity bal acct disabled  */
#define		INT_MMS_DEFAULT_NATURE_ID_NOT_FOUND	7005	/* Default Nature Id not found */
#define		INT_MMS_CLIENT_ID_NOT_FOUND	7006	/* MMS client ID not found */
#define		INT_MMS_ENTITY_NAME_NOT_FOUND	7007	/* MMS entity name not found */
#define		INT_MMS_ENTITY_TYPE_NOT_FOUND	7008	/* MMS entity type not found */
#define		INT_MMS_ACCT_TYPE_NOT_FOUND	7010	/* MMS acct type not found */
#define		INT_MMS_RELATE_GRP_NOT_FOUND	7011	/* MMS relate grp not found */
#define		INT_MMS_ACCT_NAME_NOT_FOUND	7012	/* MMS acct name not found */
#define		INT_MMS_ACCT_NUM_NOT_FOUND	7013	/* MMS acct num not found */
#define		INT_MMS_ACCT_HOLDER_NOT_FOUND	7014	/* MMS acct holder not found */
#define		INT_MMS_BASE_CCY_NOT_FOUND	7015	/* MMS base ccy not found */
#define		INT_MMS_BAL_CNT_NOT_FOUND       7016    /* MMS bal cnt not found */
#define		INT_MMS_COUNTRY_NOT_FOUND       7017    /* MMS country not found */
#define		INT_MMS_NATURE_ID_NOT_FOUND     7018    /* Nature Id not found */
#define		INT_MMS_ID_NOT_FOUND		7019	/* MMS rsp/opb id not found */
#define         INT_MMS_ENTITY_TYPE_NOT_MATCH   7020    /* MMS entity type not match */
#define         INT_MMS_NATURE_CNT_NOT_FOUND            7021    /* MMS nature cnt not found */
#define         INT_MMS_NATURE_GRP_NOT_FOUND            7022    /* MMS nature grp not found */
#define         INT_MMS_NATURE_GRP_VAL_NOT_FOUND        7023    /* MMS nature grp val not found */
#define         INT_MMS_INVALID_ACTION        	7024    /* MMS Invalid action  */
#define         INT_MMS_TXN_CODE_NOT_FOUND     	7025    /* MMS txn code not found */
#define         INT_MMS_TXN_CODE_DESC_NOT_FOUND     	7026    /* MMS txn code desc not found */
#define         INT_MMS_ADJ_ETYPE_CNT_NOT_FOUND     	7027    /* MMS adj etype cnt not found */
#define         INT_MMS_ADJ_ETYPE_NOT_FOUND     	7028    /* MMS adj etype not found */
#define         INT_MMS_BAL_TYPE_NOT_FOUND     	7029    /* MMS bal type not found */
#define         INT_MMS_ADJ_NAT_NOT_FOUND     	7030    /* MMS adj nat not found */
#define         INT_MMS_CCY_NOT_FOUND           7031    /* MMS ccy not found */
#define         INT_MMS_AMT_NOT_FOUND       	7032    /* MMS amt not found */
#define         INT_MMS_FX_CNT_NOT_FOUND        7033    /* MMS fx cnt not found */
#define         INT_MMS_FX_ORG_CCY_NOT_FOUND    7034    /* MMS fx org ccy not found */
#define         INT_MMS_FX_CCY_NOT_FOUND        7035    /* MMS fx ccy not found */
#define         INT_MMS_FX_AMT_NOT_FOUND        7036    /* MMS fx amt not found */
#define         INT_MMS_NATURE_AMT_NOT_FOUND    7037    /* MMS Nature Amount Not Found */
#define         INT_MMS_NATURE_BAL_NOT_FOUND    7038    /* MMS Nature Balance Not Found */
#define         INT_MMS_SELECTE_TYPE_NOT_FOUND  7039    /* MMS Select Type Not Found */
#define         INT_MMS_INVALID_SELECT_TYPE	7040    /* MMS Invalid Select Type */
#define		INT_MMS_RSP_EXISTS		7041	/* MMS Rsp exists */
#define		INT_MMS_OPB_EXISTS		7042	/* MMS Opb exists */
#define		INT_MMS_ENTITY_BAL_ACCT_EXISTS	7043	/* MMS Entity BalAcct Already Exists */
#define         INT_MMS_ADJ_TYPE_NOT_ALLOW_MODIFY       7044    /* MMS adj type not allow modify */
#define         INT_MMS_ADJ_ETYPE_ACTION_NOT_FOUND      7045    /* MMS adj etype action not found */
#define		INT_MMS_INVALID_AMT		7046	/* MMS Invalid Amt */
#define         INT_MMS_AFF_FX_AMT_NOT_FOUND   	7047    /* MMS affected fx amt not found */
#define         INT_MMS_NON_AFF_FX_AMT_NOT_FOUND        7048    /* MMS non affected fx amt not found */
#define         INT_MMS_FX_ACR_IND_NOT_FOUND   	7049    /* MMS fx acr ind not found */
#define         INT_MMS_INSUFFICIENT_TXN_AMT   	7050    /* MMS insufficient txn amt */


#define         INT_MI_ENTITY_TYPE_NOT_FOUND   	8001    /* MiniMMM entity type not found */
#define         INT_MI_BAL_TYPE_NOT_FOUND   	8002    /* MiniMMM bal type not found */
#define		INT_MI_PRODUCT_CODE_NOT_FOUND	8003	/* MiniMMM product code not found */
#define         INT_MI_ENTITY_ID_NOT_FOUND   	8004    /* MiniMMM entity id not found */
#define		INT_MINI_MMM_MODE_DISABLED	8005	/* Mini-MMM Mode disabled*/
#define         INT_MI_RSP_ID_NOT_FOUND         8006    /* MiniMMM rsp id not found */
#define		INT_MI_COST_RATE_NOT_FOUND	8007	/* MiniMMM cost rate not found */
#define		INT_MI_COST_AMT_NOT_FOUND	8008	/* MiniMMM cost amt not found */
#define		INT_MI_REMIT_SLIP_DATE_NOT_FOUND	8009	/* MiniMMM remit slip date not found */
#define		INT_MI_REMIT_RATE_NOT_FOUND	8010	/* MiniMMM remit rate not found */
#define		INT_MI_CVT_CCY_NOT_FOUND	8011	/* MiniMMM cvt ccy not found */
#define		INT_MI_CVT_AMT_NOT_FOUND	8012	/* MiniMMM cvt amt not found */
#define         INT_MI_SEB_CNT_NOT_FOUND        8013    /* MiniMMM seb cnt not found */
#define         INT_MI_TOTAL_CNT_NOT_FOUND      8014    /* MiniMMM total cnt not found */
#define         INT_MI_REMARK_NOT_FOUND         8015    /* MiniMMM remark not found */
#define         INT_MI_PIT_ID_NOT_FOUND         8016    /* PSP In-transit ID Not Found */
#define         INT_NOT_MI_TRANSACTION          8017    /* Not Mini-MMM transaction*/
#define         INT_MI_BATCH_ID_NOT_FOUND       8018    /* MiniMMM batch id not found */
#define         INT_MI_PROCESS_TYPE_NOT_FOUND   8019    /* MiniMMM process type not found */
#define         INT_MI_TXN_CODE_INVALID         8020    /* MiniMMM txn code invalid */
#define         INT_MI_BATCH_INOPERATIVE        8021    /* MiniMMM batch inoperative */
#define         INT_MI_TOTAL_CNT_MISMATCH       8022    /* MiniMMM total cnt mismatch */


//Error Code for IT Tools
#define		INT_ITT_PROVIDER_NAME_NOT_FOUND		9001	/* Provider Name not found */
#define		INT_ITT_PO_SPLIT_LIMIT_NOT_FOUND	9002	/* Payout split limit not found */
#define		INT_ITT_VIRTUAL_BANK_AC_NOT_FOUND	9003	/* Virtual Bank Accout for selected currency not found */
#define		INT_ITT_NOT_NEW_MERCHANT		9004	/* Not a new merchant */
#define		INT_ITT_TXN_EXISTS_FOR_BANK_AC		9005	/* Transaction exists for selected BAID's bank account */
#define		INT_ITT_BANK_STATEMENT_FOUND		9006	/* Bank Statement found for selected BAID's bank account */
#define		INT_ITT_BAID_TXN_FOUND			9007	/* BAID Transactions found */
#define		INT_ITT_NEW_PROVIDER_ID_NOT_FOUND	9008	/* New provider id not found */
#define		INT_ITT_BANK_ACCT_STATUS_NOT_SUPPORT	9009	/* Bank Account status not support */
#define		INT_ITT_BAID_LINKED			9010	/* BAID Linked with bank account */
#define		INT_ITT_URL_NOT_FOUND			9011	/* URL not found */
#define		INT_ITT_NEED_AT_LEAST_ONE_ACTIVE_URL	9012	/* Need to have at least one URL active on [Service][Country][Merchant] */


//Error Code for AllInPay
#define		INT_P_CONTACT_CS		11000  	/* */
#define         INT_P_SIGN_ERR			11001    /**/
#define		INT_P_PARAM_CONF_ERR		11002	/* */
#define         INT_P_ENCODE_FORMAT_ERR		11003    /* */
#define         INT_P_INV_DELIVER_ADDR		11004    /* */
#define		INT_P_INV_CONTACT_ADDR		11005	/* */	
#define		INT_P_INV_SIGN_TYPE		11006	/* */
#define		INT_P_INV_LANG			11007	/* */
#define		INT_P_INV_PAY_METHOD		11008	/* */
#define		INT_P_INV_EXT_PARAM_1		11009	/**/
#define		INT_P_INV_EXT_PARAM_2		11010	/**/
#define		INT_P_INV_DESC			11011	/**/
#define		INT_P_INV_PRODUCT_CODE		11012	/**/
#define		INT_P_INV_PRODUCT_AMT		11013	/**/
#define		INT_P_INV_PRODUCT_NAME		11014	/**/
#define		INT_P_INV_REQ_TIME		11015	/**/
#define		INT_P_INV_AMT			11016	/**/
#define		INT_P_INV_ORDER_NUM		11017	/**/
#define		INT_P_INV_CUSTOMER_EMAIL	11018	/**/
#define		INT_P_INV_CUSTOMER_MOBILE	11019	/**/
#define		INT_P_INV_CUSTOMER_NAME		11020	/**/
#define		INT_P_INV_VERSION		11021	/**/
#define		INT_P_INV_SIGN_MSG		11022	/**/
#define		INT_P_INV_CARD_ISSUER		11023	/**/
#define		INT_P_INV_PAY_PARAM		11024	/**/
#define		INT_P_INV_INQ_TIME		11025	/**/
#define		INT_P_INV_INQ_START_TIME	11026	/**/
#define		INT_P_INV_INQ_END_TIME		11027	/**/
#define		INT_P_INV_INQ_URL		11028	/**/
#define		INT_P_ORDER_NOT_EXIST		11029	/**/
#define		INT_P_CANNOT_REFUND		11030	/**/
#define		INT_P_FORMAT_ERR		11031	/**/
#define		INT_P_SYS_PARAM_CONF_ERR	11032	/**/
#define		INT_P_ALREADY_SUCC		11033	/**/
#define		INT_P_REPEATED_ORDER		11034	/**/
#define		INT_P_ORG_ORDER_NOT_EXIST	11035	/**/
#define		INT_P_UNAUTHORIZED_USER		11036	/**/
#define         INT_P_SERVER_BUSY		11037    /**/
#define         INT_P_INV_PASSWORD		11038    /**/
#define		INT_P_INV_CARD			11039	/**/
#define		INT_P_INV_USER			11040	/**/
#define		INT_P_INV_CARD_NUM		11041	/**/
#define		INT_P_TOO_MANY_RETRY		11042	/**/


//Error Code for SengPay
#define		INT_WAITING_PROCESS		12000	/**/
#define		INT_EXPIRED			12001	/**/
#define		INT_CXL_SUCC			12002	/**/
#define		INT_REFUNDING			12003	/**/
#define		INT_REFUND_SUCC 		12004	/**/
#define		INT_REFUND_FAIL 		12005	/**/
#define		INT_PARTICAL_REFUND_SUCC	12006	/**/




#endif
