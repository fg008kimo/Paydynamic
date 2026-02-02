


CREATE OR REPLACE FUNCTION sp_ol_nontxn_msg_hd_ins (
        in_txn_id           	ol_nontxn_msg_header.ontmh_txn_id%type,
        in_channel_code         ol_nontxn_msg_header.ontmh_channel_code%type,
        in_txn_code         	ol_nontxn_msg_header.ontmh_txn_code%type,
        in_version              ol_nontxn_msg_header.ontmh_version%type,
        in_status               ol_nontxn_msg_header.ontmh_status%type,
        in_ret_code             ol_nontxn_msg_header.ontmh_ret_code%type,
        in_add_user             ol_nontxn_msg_header.ontmh_create_user%type)
    RETURN NUMBER IS
BEGIN

    INSERT INTO ol_nontxn_msg_header (
        ontmh_txn_id, 
        ontmh_channel_code,
        ontmh_txn_code,
        ontmh_version,
        ontmh_status,
        ontmh_ret_code,
        ontmh_create_user,
        ontmh_create_timestamp,
        ontmh_update_user,
        ontmh_update_timestamp
    )
    VALUES (
        in_txn_id,
        in_channel_code,
        in_txn_code,
        in_version,
        in_status,
        in_ret_code,
        in_add_user,
        sysdate,
        in_add_user,
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
END sp_ol_nontxn_msg_hd_ins;
/
