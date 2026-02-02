CREATE OR REPLACE FUNCTION sp_ol_stmt_match_config_update(
	in_int_bank_code		OL_STMT_MATCH_CONFIG.OSMC_INT_BANK_CODE%type,
	in_bank_acct_type		OL_STMT_MATCH_CONFIG.OSMC_BANK_ACCT_TYPE%type,
	in_txn_code		        OL_STMT_MATCH_CONFIG.OSMC_TXN_CODE%type,
	in_code			        OL_STMT_MATCH_CONFIG.OSMC_CODE%type,
	in_val			        OL_STMT_MATCH_CONFIG.OSMC_VAL%type,
	in_update_user			OL_STMT_MATCH_CONFIG.OSMC_UPDATE_USER%type
)
RETURN NUMBER IS

BEGIN

	UPDATE	OL_STMT_MATCH_CONFIG
	SET	OSMC_VAL = in_val,
		OSMC_DISABLED = 0,
		OSMC_UPDATE_TIMESTAMP = SYSDATE,
		OSMC_UPDATE_USER = in_update_user
	WHERE	OSMC_INT_BANK_CODE = in_int_bank_code
		AND OSMC_BANK_ACCT_TYPE = in_bank_acct_type
		AND OSMC_TXN_CODE = in_txn_code
		AND OSMC_CODE = in_code;

	IF SQL%ROWCOUNT = 0 THEN

		INSERT INTO OL_STMT_MATCH_CONFIG(
			OSMC_INT_BANK_CODE,
			OSMC_BANK_ACCT_TYPE,
			OSMC_TXN_CODE,
			OSMC_CODE,
			OSMC_VAL,
			OSMC_CREATE_TIMESTAMP,
			OSMC_CREATE_USER,
			OSMC_UPDATE_TIMESTAMP,
			OSMC_UPDATE_USER
		)
		VALUES(
			in_int_bank_code,
			in_bank_acct_type,
			in_txn_code,
			in_code,
			in_val,
			SYSDATE,
			in_update_user,
			SYSDATE,
			in_update_user
		);

		IF SQL%ROWCOUNT = 0 THEN
			RETURN 1;
		ELSE
			RETURN 0;
		END IF;

  	ELSE
     		return 0;
  	END IF;

EXCEPTION
	WHEN OTHERS THEN
     		RETURN 9;

END sp_ol_stmt_match_config_update;
/
