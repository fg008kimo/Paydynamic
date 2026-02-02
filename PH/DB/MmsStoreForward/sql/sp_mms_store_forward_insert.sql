create or replace function sp_mms_store_forward_insert(
       in_txn_id				mms_store_forward.msf_txn_id%type,
       in_node_id				mms_store_forward.msf_node_id%type,
       in_to					mms_store_forward.msf_to%type,
       in_status				mms_store_forward.msf_status%type,
       in_create_user                           mms_store_forward.msf_create_user%type)

  RETURN NUMBER IS
begin

	INSERT into MMS_STORE_FORWARD(
			msf_txn_id,
			msf_node_id,
			msf_to,
			msf_status,
			msf_next_try,
			msf_create_user,
			msf_create_datetime)
		VALUES(
			in_txn_id,
			in_node_id,
			in_to,
			in_status,
			SYSDATE,
			in_create_user,
			SYSDATE);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_mms_store_forward_insert;
/
