CREATE OR REPLACE FUNCTION sp_ol_txn_request_matchreq (
    in_channel_code    ol_txn_request_ref.otrr_channel_code%type,
    in_request_ref     ol_txn_request_ref.otrr_req_txn_ref%type,
    in_txn_id          ol_txn_request_ref.otrr_req_txn_id%type
)
    RETURN NUMBER
IS
    iret   INTEGER := 0;
BEGIN
    SELECT COUNT (*)
      INTO iret
      FROM ol_txn_request_ref
     WHERE otrr_req_txn_ref = in_request_ref
       AND otrr_channel_code = in_channel_code
       AND (in_txn_id IS NULL or otrr_req_txn_id != in_txn_id);

    RETURN iret;
EXCEPTION
    WHEN OTHERS THEN
        RETURN 1;
END sp_ol_txn_request_matchreq;
/
