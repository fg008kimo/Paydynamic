CREATE OR REPLACE FUNCTION sp_mms_adj_type_insert (
        in_code                     	mms_adjustment_type.mat_code%TYPE,
        in_code_in_num             	mms_adjustment_type.mat_code_in_num%TYPE,
        in_adj_desc                     mms_adjustment_type.mat_desc%TYPE,
        in_amt_type                	mms_adjustment_type.mat_amt_type%TYPE,
        in_bal_type                 	mms_adjustment_type.mat_bal_type%TYPE,
        in_adj_nat                    	mms_adjustment_type.mat_nature%TYPE,
        in_disabled                     mms_adjustment_type.mat_disabled%TYPE,
        in_system_defined              	mms_adjustment_type.mat_system_defined%TYPE,
        in_allow_modify                	mms_adjustment_type.mat_allow_modify%TYPE,
        in_allow_bal_negative          	mms_adjustment_type.mat_allow_bal_negative%TYPE,
        in_adj_rpt_fe_display          	mms_adjustment_type.mat_adj_rpt_fe_display%TYPE,
        in_user                         mms_adjustment_type.mat_create_user%TYPE
        )
  RETURN NUMBER IS

BEGIN
  INSERT INTO MMS_ADJUSTMENT_TYPE (
        mat_code,
        mat_code_in_num,
        mat_desc,
        mat_amt_type,
        mat_bal_type,
        mat_nature,
        mat_disabled,
        mat_system_defined,
        mat_allow_modify,
        mat_allow_bal_negative,
        mat_adj_rpt_fe_display,
        mat_create_timestamp,
        mat_create_user,
	mat_update_timestamp,
        mat_update_user
        )

  VALUES (
        in_code,
        in_code_in_num,
        in_adj_desc,
        in_amt_type,
        in_bal_type,
        in_adj_nat,
        in_disabled,
        in_system_defined,
        in_allow_modify,
        in_allow_bal_negative,
        in_adj_rpt_fe_display,
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

END sp_mms_adj_type_insert;
/
