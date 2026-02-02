CREATE OR REPLACE FUNCTION sp_ol_txn_request_ref_insert (
        in_req_txn_id           ol_txn_request_ref.otrr_req_txn_id%type,
        in_channel_code         ol_txn_request_ref.otrr_channel_code%type,
        in_req_txn_code         ol_txn_request_ref.otrr_req_txn_code%type,
        in_req_txn_ref          ol_txn_request_ref.otrr_req_txn_ref%type,
        in_version              ol_txn_request_ref.otrr_version%type,
        in_t1_txn_id            ol_txn_request_ref.otrr_t1_txn_id%type,
        in_t2_txn_id            ol_txn_request_ref.otrr_t2_txn_id%type,
        in_status               ol_txn_request_ref.otrr_status%type,
        in_ret_code             ol_txn_request_ref.otrr_ret_code%type,
        in_add_user             ol_txn_request_ref.otrr_create_user%type)
    RETURN NUMBER IS
BEGIN

    INSERT INTO ol_txn_request_ref (
        otrr_req_txn_id, 
        otrr_channel_code,
        otrr_req_txn_code,
        otrr_req_txn_ref,
        otrr_version,
        otrr_t1_txn_id,
        otrr_t2_txn_id,
        otrr_status,
        otrr_ret_code,
        otrr_create_user,
        otrr_create_timestamp,
        otrr_update_user,
        otrr_update_timestamp
    )
    VALUES (
        in_req_txn_id,
        in_channel_code,
        in_req_txn_code,
        in_req_txn_ref,
        in_version,
        in_t1_txn_id,
        in_t2_txn_id,
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
END sp_ol_txn_request_ref_insert;
/
