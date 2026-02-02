CREATE OR REPLACE FUNCTION sp_channel_txn_map_insert(
	in_channel_code		channel_txn_map.ct_channel_code%type,
	in_txn_code		channel_txn_map.ct_txn_code%type,
	in_disabled		channel_txn_map.ct_disabled%type,
	in_apply_fee		channel_txn_map.ct_apply_fee%type,
	in_apply_limit		channel_txn_map.ct_apply_limit%type,
	in_apply_reserve 	channel_txn_map.ct_apply_reserve%type,
	in_apply_ex_markup 	channel_txn_map.ct_apply_ex_markup%type,
	in_create_user		txn_code.tc_create_user%type)
  RETURN NUMBEr IS
BEGIN

	INSERT INTO channel_txn_map(
		ct_channel_code,
		ct_txn_code,
		ct_disabled,
		ct_apply_fee,
		ct_apply_limit,
		ct_apply_reserve,
		ct_apply_ex_markup,
		ct_create_user,
		ct_update_user,
		ct_create_timestamp,
		ct_update_timestamp
		)
	VALUES (
		in_channel_code,
		in_txn_code,
		in_disabled,
		in_apply_fee,
		in_apply_limit,
		in_apply_reserve,
		in_apply_ex_markup,
		in_create_user,
		in_create_user,
		sysdate,
		sysdate
		);

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_channel_txn_map_insert;
/
