CREATE OR REPLACE FUNCTION sp_ol_merch_psp_bat_type_ins(
	in_batch_id		ol_merch_psp_batch_type.ompbt_batch_id%type,
	in_type			ol_merch_psp_batch_type.ompbt_type%type,
	in_create_user		ol_merch_psp_batch_type.ompbt_create_user%type)
  RETURN NUMBEr IS
BEGIN

	INSERT INTO ol_merch_psp_batch_type (
		ompbt_batch_id,
		ompbt_type,
		ompbt_create_timestamp,
		ompbt_create_user,
		ompbt_update_timestamp,
		ompbt_update_user
		)
	VALUES (
		in_batch_id,
		in_type,
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

END sp_ol_merch_psp_bat_type_ins;
/
