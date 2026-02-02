CREATE OR REPLACE FUNCTION sp_mms_txn_code_insert (
        in_txn_code                     mms_txn_code.mtc_code%TYPE,
        in_txn_desc              	mms_txn_code.mtc_desc%TYPE,
        in_process_type                 mms_txn_code.mtc_process_type%TYPE,
        in_process_code                 mms_txn_code.mtc_process_code%TYPE,
        in_fe_display                 	mms_txn_code.mtc_fe_display%TYPE,
        in_user                         mms_txn_code.mtc_create_user%TYPE
        )
  RETURN NUMBER IS

BEGIN
  INSERT INTO MMS_TXN_CODE (
        mtc_code,
        mtc_desc,
        mtc_process_type,
	mtc_process_code,
	mtc_fe_display,
        mtc_create_timestamp,
        mtc_create_user,
	mtc_update_timestamp,
        mtc_update_user
        )

  VALUES (
        in_txn_code,
	in_txn_desc,
        in_process_type,
        in_process_code,
        in_fe_display,
        SYSDATE,
        in_user,
	SYSDATE,
        in_user
        );

  IF SQL%ROWCOUNT = 0
  THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;

END sp_mms_txn_code_insert;
/
