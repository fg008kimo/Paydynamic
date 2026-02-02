CREATE OR REPLACE FUNCTION sp_ol_get_auto_upl_stmt_sett(
	in_baid                 	OL_BANK_ACCT_ID.OBAI_BAID%type,
	out_cursor       		OUT SYS_REFCURSOR)
RETURN NUMBER IS
	iCnt    integer := 0;
BEGIN

	SELECT COUNT (*)
	INTO iCnt
	FROM
	(
		SELECT  Provider_ID,
			PSP_MASTER.PM_STATUS AS Provider_Status,		
                        PSP_ID,
                        PSP_Bank_Nature_Code,
			PSP_Status,
                        OL_BANK_ACCTS.OB_ACCT_TYPE AS Bank_Nature_Code,
                        OL_DEF_BANK_ACCT_TYPE.OBC_DESC AS Bank_Nature,
                        BAID,
                        BAID_Status_Code,
                        BAID_Status,
                        Bank_Code,
                        Bank_Account_Number,
                        OL_BANK_ACCTS.OB_STATUS_TYPE AS Bank_Account_Status_Type,
                        OL_DEF_ACCT_STATUS.AS_DESC AS Bank_Account_Status,
			OL_BANK_ACCTS.OB_SYS_SWITCH_ENABLED AS Bank_Acct_Sys_Switch_Enabled,
                        OL_BANK_ACCTS.OB_SHARED_ACCT AS Bank_Shared_Account,
			OL_MERCHANT_BANK_ACCT.OMB_MERCHANT_ID AS Merchant_ID,
                        Currency_ID,
			A.OAUBD_DISABLED AS Bank_Disabled,
                      	B.OAUBD_DISABLED AS Bank_Account_Disabled
                FROM
		(
                         SELECT OL_PSP_DETAIL.OPD_CLIENT_ID AS Provider_ID,
                                OL_PSP_DETAIL.OPD_PSP_ID AS PSP_ID,
                                OL_PSP_DETAIL.OPD_BANK_ACCT_TYPE AS PSP_Bank_Nature_Code,
                                OL_PSP_DETAIL.OPD_STATUS AS PSP_Status,
                                OL_BANK_ACCT_ID.OBAI_BAID AS BAID,
                                OL_BANK_ACCT_ID.OBAI_STATUS AS BAID_Status_Code,
                                OL_DEF_BAID_STATUS.OBS_DESC AS BAID_Status,
                                OL_BANK_ACCT_ID.OBAI_INT_BANK_CODE AS Bank_Code,
                                OL_BANK_ACCT_ID.OBAI_BANK_ACCT_NUM AS Bank_Account_Number,
                                OL_BAID_BAL.OBAB_CURRENCY_ID AS Currency_ID
                        FROM    OL_BANK_ACCT_ID,
                                OL_DEF_BAID_CATEGORY,
                                OL_DEF_BAID_STATUS,
                                OL_PSP_DETAIL,
                                OL_BAID_BAL,
                                COUNTRY
                        WHERE   OL_DEF_BAID_CATEGORY.BC_TYPE = OL_BANK_ACCT_ID.OBAI_CATEGORY
                        AND     OL_DEF_BAID_STATUS.OBS_TYPE = OL_BANK_ACCT_ID.OBAI_STATUS
                        AND     OL_PSP_DETAIL.OPD_PSP_ID = OL_BANK_ACCT_ID.OBAI_PSP_ID
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
		--
		LEFT JOIN   OL_AUTO_UPLOAD_STMT_SETTING
                ON          OL_AUTO_UPLOAD_STMT_SETTING.OAUS_NATURE = PSP_Bank_Nature_Code
                AND         OL_AUTO_UPLOAD_STMT_SETTING.OAUS_PROVIDER_ID = Provider_ID
                --
                LEFT JOIN   (OL_AUTO_UPLOAD_BANK_DETAIL) A
                ON          A.OAUBD_ACCT_TYPE = PSP_Bank_Nature_Code
                AND         A.OAUBD_INT_BANK_CODE = Bank_Code
                AND         A.OAUBD_BANK_ACCT_NUM = '000'
                --
               	LEFT JOIN   (OL_AUTO_UPLOAD_BANK_DETAIL) B
             	ON          B.OAUBD_ACCT_TYPE = PSP_Bank_Nature_Code
              	AND         B.OAUBD_INT_BANK_CODE = Bank_Code
              	AND         B.OAUBD_BANK_ACCT_NUM = Bank_Account_Number
		--
	)
	WHERE	BAID = in_baid;

	IF iCnt > 0 THEN

		OPEN out_cursor FOR
		SELECT  Provider_ID,
			Provider_Status,
			PSP_Bank_Nature_Code,
			PSP_ID,
			PSP_Status,
                        BAID_Status_Code,
                        Bank_Code,
                        Bank_Account_Number,
                        Bank_Account_Status_Type,
			Bank_Acct_Sys_Switch_Enabled,
			Merchant_ID,
			Provider_Disabled,
			Bank_Disabled,
			Bank_Account_Disabled
		FROM
		(
			SELECT  Provider_ID,
				PSP_MASTER.PM_STATUS AS Provider_Status,
                                PSP_ID,
                                PSP_Bank_Nature_Code,
				PSP_Status,
                                OL_BANK_ACCTS.OB_ACCT_TYPE AS Bank_Nature_Code,
                                OL_DEF_BANK_ACCT_TYPE.OBC_DESC AS Bank_Nature,
                                BAID,
                                BAID_Status_Code,
                                BAID_Status,
                                Bank_Code,
                                Bank_Account_Number,
                                OL_BANK_ACCTS.OB_STATUS_TYPE AS Bank_Account_Status_Type,
                                OL_DEF_ACCT_STATUS.AS_DESC AS Bank_Account_Status,
				OL_BANK_ACCTS.OB_SYS_SWITCH_ENABLED AS Bank_Acct_Sys_Switch_Enabled,
                                OL_BANK_ACCTS.OB_SHARED_ACCT AS Bank_Shared_Account,
                               	OL_MERCHANT_BANK_ACCT.OMB_MERCHANT_ID AS Merchant_ID,
				Currency_ID,
				OL_AUTO_UPLOAD_STMT_SETTING.OAUS_DISABLED AS Provider_Disabled,
				A.OAUBD_DISABLED AS Bank_Disabled,
				B.OAUBD_DISABLED AS Bank_Account_Disabled
                        FROM
			(
                                SELECT  OL_PSP_DETAIL.OPD_CLIENT_ID AS Provider_ID,
                                        OL_PSP_DETAIL.OPD_PSP_ID AS PSP_ID,
                                        OL_PSP_DETAIL.OPD_BANK_ACCT_TYPE AS PSP_Bank_Nature_Code,
					OL_PSP_DETAIL.OPD_STATUS AS PSP_Status,
                                        OL_BANK_ACCT_ID.OBAI_BAID AS BAID,
                                        OL_BANK_ACCT_ID.OBAI_STATUS AS BAID_Status_Code,
                                        OL_DEF_BAID_STATUS.OBS_DESC AS BAID_Status,
                                        OL_BANK_ACCT_ID.OBAI_INT_BANK_CODE AS Bank_Code,
                                        OL_BANK_ACCT_ID.OBAI_BANK_ACCT_NUM AS Bank_Account_Number,
					OL_BAID_BAL.OBAB_CURRENCY_ID AS Currency_ID
                                FROM    OL_BANK_ACCT_ID,
                                        OL_DEF_BAID_CATEGORY,
                                        OL_DEF_BAID_STATUS,
                                        OL_PSP_DETAIL,
                                        OL_BAID_BAL,
                                        COUNTRY
                                WHERE   OL_DEF_BAID_CATEGORY.BC_TYPE = OL_BANK_ACCT_ID.OBAI_CATEGORY
                                AND     OL_DEF_BAID_STATUS.OBS_TYPE = OL_BANK_ACCT_ID.OBAI_STATUS
                                AND     OL_PSP_DETAIL.OPD_PSP_ID = OL_BANK_ACCT_ID.OBAI_PSP_ID
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
			--
			LEFT JOIN   OL_AUTO_UPLOAD_STMT_SETTING
			ON          OL_AUTO_UPLOAD_STMT_SETTING.OAUS_NATURE = PSP_Bank_Nature_Code
			AND         OL_AUTO_UPLOAD_STMT_SETTING.OAUS_PROVIDER_ID = Provider_ID
			--
			LEFT JOIN   (OL_AUTO_UPLOAD_BANK_DETAIL) A
			ON          A.OAUBD_ACCT_TYPE = PSP_Bank_Nature_Code
			AND         A.OAUBD_INT_BANK_CODE = Bank_Code
			AND         A.OAUBD_BANK_ACCT_NUM = '000'
			--
			LEFT JOIN   (OL_AUTO_UPLOAD_BANK_DETAIL) B
			ON          B.OAUBD_ACCT_TYPE = PSP_Bank_Nature_Code
			AND         B.OAUBD_INT_BANK_CODE = Bank_Code
			AND         B.OAUBD_BANK_ACCT_NUM = Bank_Account_Number
			--
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

END sp_ol_get_auto_upl_stmt_sett;
/
