


CREATE OR REPLACE FUNCTION sp_ol_nontxn_msg_dt_ins (
        in_txn_id           	ol_nontxn_msg_detail.ontmd_txn_id%type,
        in_direction           	ol_nontxn_msg_detail.ontmd_direction%type,
        in_seq         		ol_nontxn_msg_detail.ontmd_seq%type,
        in_tag         		ol_nontxn_msg_detail.ontmd_tag%type,
        in_value              	ol_nontxn_msg_detail.ontmd_value%type,
        in_add_user             ol_nontxn_msg_detail.ontmd_create_user%type)
    RETURN NUMBER IS
	iCnt integer := 0;
BEGIN

    SELECT nvl(max(ontmd_seq),0)
    INTO iCnt
    FROM ol_nontxn_msg_detail
    WHERE ontmd_txn_id = in_txn_id
    AND	ontmd_direction = in_direction;

    iCnt := iCnt + 1;

    INSERT INTO ol_nontxn_msg_detail (
        ontmd_txn_id, 
     	ontmd_direction,
        ontmd_seq,
        ontmd_tag,
        ontmd_value,
        ontmd_create_user,
        ontmd_create_timestamp,
        ontmd_update_user,
        ontmd_update_timestamp
    )
    VALUES (
        in_txn_id,
	in_direction,
        iCnt,
        in_tag,
        in_value,
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
END sp_ol_nontxn_msg_dt_ins;
/
