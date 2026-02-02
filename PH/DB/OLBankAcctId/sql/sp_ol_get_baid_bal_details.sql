CREATE OR REPLACE FUNCTION sp_ol_get_baid_bal_details(
	in_baid                 	OL_BANK_ACCT_ID.OBAI_BAID%type,
	out_cursor       		OUT SYS_REFCURSOR)
RETURN NUMBER IS
	iCnt    integer := 0;
BEGIN

	SELECT COUNT (*)
	INTO iCnt
	FROM
	(
		SELECT  PSP_MASTER.PM_CLIENT_NAME AS Provider_Name,
                       	Provider_ID,
                        PSP_ID,
                        PSP_Name,
                        PSP_Bank_Nature_Code,
                        OL_BANK_ACCTS.OB_ACCT_TYPE AS Bank_Nature_Code,
                        OL_DEF_BANK_ACCT_TYPE.OBC_DESC AS Bank_Nature,
                        BAID,
                        BAID_Code_In_Num,
                        BAID_Name,
                        BAID_Category_Code,
                        BAID_Category,
                        BAID_Status_Code,
                        BAID_Status,
                        Bank_Code,
                        BANK_DESC.BANK_NAME AS Bank_Name,
                        BANK_DESC.BANK_ABBREV_NAME AS Bank_Short_Name,
                        OL_BANK_ACCTS.OB_OWNER_NAME AS Bank_Owner_Name,
                        OL_BANK_ACCTS.OB_BRANCH_NAME AS Bank_Branch_Name,
                        Bank_Account_Number,
                        OL_BANK_ACCTS.OB_BANK_ACCT_NAME AS Bank_Account_Name,
                        OL_BANK_ACCTS.OB_BANK_ACCT_SHORT_NAME AS Bank_Account_Short_Name,
                        OL_BANK_ACCTS.OB_STATUS_TYPE AS Bank_Account_Status_Type,
                        OL_DEF_ACCT_STATUS.AS_DESC AS Bank_Account_Status,
                        OL_BANK_ACCTS.OB_SHARED_ACCT AS Bank_Shared_Account,
			OL_MERCHANT_BANK_ACCT.OMB_MERCHANT_ID AS Merchant_ID,
                        Init_Bal,
                        Apply_Deposit_Cost,
                        BAID_Create_User,
                        BAID_Update_User,
                        BAID_Create_Timstamp,
                        BAID_Update_Timstamp,
                        Country_ID,
                        Country_Name,
                        Currency_ID,
                        DEF_CURRENCY.DC_DESC AS Currency_Name,
                        In_Transit,
                        Lien,
                        Balance,
                        Available_Account_Balance,
                        Total_Balance,
                        Current_Balance
                FROM
		(
                         SELECT OL_PSP_DETAIL.OPD_CLIENT_ID AS Provider_ID,
                                OL_PSP_DETAIL.OPD_PSP_ID AS PSP_ID,
                                OL_PSP_DETAIL.OPD_PSP_NAME AS PSP_Name,
                                OL_PSP_DETAIL.OPD_BANK_ACCT_TYPE AS PSP_Bank_Nature_Code,
                                OL_BANK_ACCT_ID.OBAI_BAID AS BAID,
                                OL_BANK_ACCT_ID.OBAI_CODE_IN_NUM AS BAID_Code_In_Num,
                                OL_BANK_ACCT_ID.OBAI_BAID_NAME AS BAID_Name,
                                OL_BANK_ACCT_ID.OBAI_CATEGORY AS BAID_Category_Code,
                                OL_DEF_BAID_CATEGORY.BC_DESC AS BAID_Category,
                                OL_BANK_ACCT_ID.OBAI_STATUS AS BAID_Status_Code,
                                OL_DEF_BAID_STATUS.OBS_DESC AS BAID_Status,
                                OL_BANK_ACCT_ID.OBAI_INT_BANK_CODE AS Bank_Code,
                                OL_BANK_ACCT_ID.OBAI_BANK_ACCT_NUM AS Bank_Account_Number,
                                OL_BANK_ACCT_ID.OBAI_INIT_BAL AS Init_Bal,
                                OL_BANK_ACCT_ID.OBAI_APPLY_DEPOSIT_COST AS Apply_Deposit_Cost,
                                OL_BANK_ACCT_ID.OBAI_CREATE_USER AS BAID_Create_User,
                                OL_BANK_ACCT_ID.OBAI_UPDATE_USER AS BAID_Update_User,
                                OL_BANK_ACCT_ID.OBAI_CREATE_TIMESTAMP AS BAID_Create_Timstamp,
                                OL_BANK_ACCT_ID.OBAI_UPDATE_TIMESTAMP AS BAID_Update_Timstamp,
                                OL_BAID_BAL.OBAB_COUNTRY_ID AS Country_ID,
                                COUNTRY.COUNTRY_NAME AS Country_Name,
                                OL_BAID_BAL.OBAB_CURRENCY_ID AS Currency_ID,
                                OL_BAID_BAL.OBAB_IN_TRANSIT AS In_Transit,
                                OL_BAID_BAL.OBAB_TOTAL_HOLD AS Lien,
                                OL_BAID_BAL.OBAB_BAL AS Balance,
                                (OL_BAID_BAL.OBAB_BAL - OL_BAID_BAL.OBAB_TOTAL_HOLD) AS Available_Account_Balance,
                                (OL_BAID_BAL.OBAB_BAL + OL_BAID_BAL.OBAB_IN_TRANSIT) AS Total_Balance,
                                (OL_BAID_BAL.OBAB_BAL - OL_BAID_BAL.OBAB_TOTAL_HOLD) + (OBAB_IN_TRANSIT) AS Current_Balance
                        FROM    OL_BANK_ACCT_ID,
                                OL_DEF_BAID_CATEGORY,
                                OL_DEF_BAID_STATUS,
                                OL_PSP_DETAIL,
                                OL_BAID_BAL,
                                COUNTRY
                        WHERE   /* OL_BANK_ACCT_ID.OBAI_STATUS = 'O' */
                                OL_DEF_BAID_CATEGORY.BC_TYPE = OL_BANK_ACCT_ID.OBAI_CATEGORY
                        AND     OL_DEF_BAID_STATUS.OBS_TYPE = OL_BANK_ACCT_ID.OBAI_STATUS
                        AND     OL_PSP_DETAIL.OPD_PSP_ID = OL_BANK_ACCT_ID.OBAI_PSP_ID
                        /* AND  OL_PSP_DETAIL.OPD_STATUS = 'O' */
                        AND     OL_PSP_DETAIL.OPD_DISABLED = 0
                        AND     OL_BAID_BAL.OBAB_BAID = OL_BANK_ACCT_ID.OBAI_BAID
                        AND     COUNTRY.COUNTRY_CODE = OL_BAID_BAL.OBAB_COUNTRY_ID
                )
		--
                LEFT JOIN   OL_BANK_ACCTS
                ON          OL_BANK_ACCTS.OB_INT_BANK_CODE = Bank_Code
                AND         OL_BANK_ACCTS.OB_BANK_ACCT_NUM = Bank_Account_Number
                --
                LEFT JOIN   OL_DEF_ACCT_STATUS
                ON          OL_DEF_ACCT_STATUS.AS_TYPE = OL_BANK_ACCTS.OB_STATUS_TYPE
                --
                LEFT JOIN   BANK_DESC
                ON          BANK_DESC.INTERNAL_BANK_CODE = Bank_Code
                /* AND      BANK_DESC.OFFLINE_SUPPORT = 1 */
                --
                LEFT JOIN   PSP_MASTER
                ON          PSP_MASTER.PM_CLIENT_ID = Provider_ID
                /*
                AND         PSP_MASTER.PM_STATUS = 'O'
                AND         PSP_MASTER.PM_MODE_TYPE = 'OFL'
                */
                --
                LEFT JOIN   OL_DEF_BANK_ACCT_TYPE
                ON          OL_DEF_BANK_ACCT_TYPE.OBC_TYPE = PSP_Bank_Nature_Code
                --
                LEFT JOIN   DEF_CURRENCY
                ON          DEF_CURRENCY.DC_CCY_ID = Currency_ID
		--
		LEFT JOIN   OL_MERCHANT_BANK_ACCT
		ON          OL_MERCHANT_BANK_ACCT.OMB_INT_BANK_CODE = Bank_Code
		AND         OL_MERCHANT_BANK_ACCT.OMB_BANK_ACCT_NUM = Bank_Account_Number
		AND         OL_MERCHANT_BANK_ACCT.OMB_STATUS = 'O'
		AND         OL_MERCHANT_BANK_ACCT.OMB_DISABLED = 0
		AND         OL_BANK_ACCTS.OB_SHARED_ACCT = 0
		--
		LEFT JOIN   OL_MERCH_DETAIL
		ON          OL_MERCH_DETAIL.MD_MERCHANT_ID = OL_MERCHANT_BANK_ACCT.OMB_MERCHANT_ID
	)
	WHERE	BAID = in_baid;

	IF iCnt > 0 THEN

		OPEN out_cursor FOR
		SELECT  Provider_ID,
			Provider_Name,
                        BAID_Status_Code,
                        PSP_Bank_Nature_Code,
                        Bank_Code,
                        Bank_Name,
                        Bank_Owner_Name,
                        Bank_Branch_Name,
                        Bank_Account_Number,
			Bank_Account_Short_Name,
                        Bank_Account_Status_Type,
			Merchant_ID,
			Country_ID,
			Currency_ID,
			Total_Balance,
			Available_Account_Balance
		FROM
		(
			SELECT  PSP_MASTER.PM_CLIENT_NAME AS Provider_Name,
                                Provider_ID,
                                PSP_ID,
                                PSP_Name,
                                PSP_Bank_Nature_Code,
                                OL_BANK_ACCTS.OB_ACCT_TYPE AS Bank_Nature_Code,
                                OL_DEF_BANK_ACCT_TYPE.OBC_DESC AS Bank_Nature,
                                BAID,
                                BAID_Code_In_Num,
                                BAID_Name,
                                BAID_Category_Code,
                                BAID_Category,
                                BAID_Status_Code,
                                BAID_Status,
                                Bank_Code,
                                BANK_DESC.BANK_NAME AS Bank_Name,
                                BANK_DESC.BANK_ABBREV_NAME AS Bank_Short_Name,
                                OL_BANK_ACCTS.OB_OWNER_NAME AS Bank_Owner_Name,
                                OL_BANK_ACCTS.OB_BRANCH_NAME AS Bank_Branch_Name,
                                Bank_Account_Number,
                                OL_BANK_ACCTS.OB_BANK_ACCT_NAME AS Bank_Account_Name,
                                OL_BANK_ACCTS.OB_BANK_ACCT_SHORT_NAME AS Bank_Account_Short_Name,
                                OL_BANK_ACCTS.OB_STATUS_TYPE AS Bank_Account_Status_Type,
                                OL_DEF_ACCT_STATUS.AS_DESC AS Bank_Account_Status,
                                OL_BANK_ACCTS.OB_SHARED_ACCT AS Bank_Shared_Account,
                               	OL_MERCHANT_BANK_ACCT.OMB_MERCHANT_ID AS Merchant_ID,
				Init_Bal,
                                Apply_Deposit_Cost,
                                BAID_Create_User,
                                BAID_Update_User,
                                BAID_Create_Timstamp,
                                BAID_Update_Timstamp,
                                Country_ID,
                                Country_Name,
                                Currency_ID,
                                DEF_CURRENCY.DC_DESC AS Currency_Name,
                                In_Transit,
                                Lien,
                                Balance,
                                Available_Account_Balance,
                                Total_Balance,
                                Current_Balance
                        FROM
			(
                                 SELECT OL_PSP_DETAIL.OPD_CLIENT_ID AS Provider_ID,
                                        OL_PSP_DETAIL.OPD_PSP_ID AS PSP_ID,
                                        OL_PSP_DETAIL.OPD_PSP_NAME AS PSP_Name,
                                        OL_PSP_DETAIL.OPD_BANK_ACCT_TYPE AS PSP_Bank_Nature_Code,
                                        OL_BANK_ACCT_ID.OBAI_BAID AS BAID,
                                        OL_BANK_ACCT_ID.OBAI_CODE_IN_NUM AS BAID_Code_In_Num,
                                        OL_BANK_ACCT_ID.OBAI_BAID_NAME AS BAID_Name,
                                        OL_BANK_ACCT_ID.OBAI_CATEGORY AS BAID_Category_Code,
                                        OL_DEF_BAID_CATEGORY.BC_DESC AS BAID_Category,
                                        OL_BANK_ACCT_ID.OBAI_STATUS AS BAID_Status_Code,
                                        OL_DEF_BAID_STATUS.OBS_DESC AS BAID_Status,
                                        OL_BANK_ACCT_ID.OBAI_INT_BANK_CODE AS Bank_Code,
                                        OL_BANK_ACCT_ID.OBAI_BANK_ACCT_NUM AS Bank_Account_Number,
                                        OL_BANK_ACCT_ID.OBAI_INIT_BAL AS Init_Bal,
                                        OL_BANK_ACCT_ID.OBAI_APPLY_DEPOSIT_COST AS Apply_Deposit_Cost,
                                        OL_BANK_ACCT_ID.OBAI_CREATE_USER AS BAID_Create_User,
                                        OL_BANK_ACCT_ID.OBAI_UPDATE_USER AS BAID_Update_User,
                                        OL_BANK_ACCT_ID.OBAI_CREATE_TIMESTAMP AS BAID_Create_Timstamp,
                                        OL_BANK_ACCT_ID.OBAI_UPDATE_TIMESTAMP AS BAID_Update_Timstamp,
                                        OL_BAID_BAL.OBAB_COUNTRY_ID AS Country_ID,
                                        COUNTRY.COUNTRY_NAME AS Country_Name,
                                        OL_BAID_BAL.OBAB_CURRENCY_ID AS Currency_ID,
                                        OL_BAID_BAL.OBAB_IN_TRANSIT AS In_Transit,
                                        OL_BAID_BAL.OBAB_TOTAL_HOLD AS Lien,
                                        OL_BAID_BAL.OBAB_BAL AS Balance,
                                        (OL_BAID_BAL.OBAB_BAL - OL_BAID_BAL.OBAB_TOTAL_HOLD) AS Available_Account_Balance,
                                        (OL_BAID_BAL.OBAB_BAL + OL_BAID_BAL.OBAB_IN_TRANSIT) AS Total_Balance,
                                        (OL_BAID_BAL.OBAB_BAL - OL_BAID_BAL.OBAB_TOTAL_HOLD) + (OBAB_IN_TRANSIT) AS Current_Balance
                                FROM    OL_BANK_ACCT_ID,
                                        OL_DEF_BAID_CATEGORY,
                                        OL_DEF_BAID_STATUS,
                                        OL_PSP_DETAIL,
                                        OL_BAID_BAL,
                                        COUNTRY
                                WHERE   /* OL_BANK_ACCT_ID.OBAI_STATUS = 'O' */
                                        OL_DEF_BAID_CATEGORY.BC_TYPE = OL_BANK_ACCT_ID.OBAI_CATEGORY
                                AND     OL_DEF_BAID_STATUS.OBS_TYPE = OL_BANK_ACCT_ID.OBAI_STATUS
                                AND     OL_PSP_DETAIL.OPD_PSP_ID = OL_BANK_ACCT_ID.OBAI_PSP_ID
                                /* AND  OL_PSP_DETAIL.OPD_STATUS = 'O' */
                                AND     OL_PSP_DETAIL.OPD_DISABLED = 0
                                AND     OL_BAID_BAL.OBAB_BAID = OL_BANK_ACCT_ID.OBAI_BAID
                                AND     COUNTRY.COUNTRY_CODE = OL_BAID_BAL.OBAB_COUNTRY_ID
                        )
			--
                        LEFT JOIN   OL_BANK_ACCTS
                        ON          OL_BANK_ACCTS.OB_INT_BANK_CODE = Bank_Code
                        AND         OL_BANK_ACCTS.OB_BANK_ACCT_NUM = Bank_Account_Number
                        --
                        LEFT JOIN   OL_DEF_ACCT_STATUS
                        ON          OL_DEF_ACCT_STATUS.AS_TYPE = OL_BANK_ACCTS.OB_STATUS_TYPE
                        --
                        LEFT JOIN   BANK_DESC
                        ON          BANK_DESC.INTERNAL_BANK_CODE = Bank_Code
                        /* AND      BANK_DESC.OFFLINE_SUPPORT = 1 */
                        --
                        LEFT JOIN   PSP_MASTER
                        ON          PSP_MASTER.PM_CLIENT_ID = Provider_ID
                        /*
                        AND         PSP_MASTER.PM_STATUS = 'O'
                        AND         PSP_MASTER.PM_MODE_TYPE = 'OFL'
                        */
                        --
                        LEFT JOIN   OL_DEF_BANK_ACCT_TYPE
                        ON          OL_DEF_BANK_ACCT_TYPE.OBC_TYPE = PSP_Bank_Nature_Code
                        --
                        LEFT JOIN   DEF_CURRENCY
                        ON          DEF_CURRENCY.DC_CCY_ID = Currency_ID
			--
                	LEFT JOIN   OL_MERCHANT_BANK_ACCT
                	ON          OL_MERCHANT_BANK_ACCT.OMB_INT_BANK_CODE = Bank_Code
                	AND         OL_MERCHANT_BANK_ACCT.OMB_BANK_ACCT_NUM = Bank_Account_Number
			AND         OL_MERCHANT_BANK_ACCT.OMB_STATUS = 'O'
                	AND         OL_MERCHANT_BANK_ACCT.OMB_DISABLED = 0
                	AND         OL_BANK_ACCTS.OB_SHARED_ACCT = 0
                	--
                	LEFT JOIN   OL_MERCH_DETAIL
                	ON          OL_MERCH_DETAIL.MD_MERCHANT_ID = OL_MERCHANT_BANK_ACCT.OMB_MERCHANT_ID
		)
		WHERE       	BAID = in_baid
		ORDER BY	BAID, Merchant_ID;

		return 0;
	ELSE
		return 2;
  	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;

END sp_ol_get_baid_bal_details;
/
