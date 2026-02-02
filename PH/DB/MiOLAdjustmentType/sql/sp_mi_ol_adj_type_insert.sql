CREATE OR REPLACE FUNCTION sp_mi_ol_adj_type_insert(
	in_entity_type		mi_ol_adjustment_type.moat_entity_type%type,
	in_code			mi_ol_adjustment_type.moat_code%type,
	in_code_in_num		mi_ol_adjustment_type.moat_code_in_num%type,
	in_desc			mi_ol_adjustment_type.moat_desc%type,
	in_amt_type		mi_ol_adjustment_type.moat_amt_type%type,
	in_bal_type		mi_ol_adjustment_type.moat_bal_type%type,
	in_nature		mi_ol_adjustment_type.moat_nature%type,
	in_is_prorata		mi_ol_adjustment_type.moat_is_prorata%type,
	in_disabled		mi_ol_adjustment_type.moat_disabled%type,
	in_create_user		mi_ol_adjustment_type.moat_create_user%type)
  RETURN NUMBEr IS
BEGIN

	INSERT INTO mi_ol_adjustment_type (
		moat_entity_type,
		moat_code,
		moat_code_in_num,
		moat_desc,
		moat_amt_type,
		moat_bal_type,
		moat_nature,
		moat_is_prorata,
		moat_disabled,
		moat_create_timestamp,
		moat_create_user,
		moat_update_timestamp,
		moat_update_user
		)
	VALUES (	
		in_entity_type,
		in_code,
		in_code_in_num,
		in_desc,
		in_amt_type,
		in_bal_type,
		in_nature,
		in_is_prorata,
		in_disabled,
		sysdate,
		in_create_user,
		sysdate,
		in_create_user
		);

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_mi_ol_adj_type_insert;
/
