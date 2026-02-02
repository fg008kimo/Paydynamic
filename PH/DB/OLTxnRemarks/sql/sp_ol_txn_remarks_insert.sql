CREATE OR REPLACE function sp_ol_txn_remarks_insert(
        in_txn_id                               ol_txn_remarks.otr_txn_id%type,
        in_txn_code                             ol_txn_remarks.otr_txn_code%type,
        in_remark                               ol_txn_remarks.otr_remark%type,
        in_create_user                          ol_txn_remarks.otr_create_user%type)
    RETURN NUMBER IS

        iCnt     INTEGER := 0;
        
        i_status          ol_txn_remarks.otr_status%type := NULL;
        i_ar_ind          ol_txn_remarks.otr_ar_ind%type := NULL;
        i_sub_status      ol_txn_remarks.otr_sub_status%type := NULL;
begin

    SELECT NVL(max(otr_exec_seq),0) + 1
	  INTO iCnt
          FROM ol_txn_remarks
         WHERE otr_txn_id = in_txn_id;

    SELECT oth_status, NVL(oth_ar_ind, ' '), NVL(oth_sub_status, ' ')
    INTO   i_status, i_ar_ind, i_sub_status
    FROM   ol_txn_header
    WHERE  oth_txn_id = in_txn_id;
   	
    INSERT into ol_txn_remarks (
            otr_txn_id,
            otr_txn_code,
            otr_status,
            otr_ar_ind,
            otr_sub_status,
            otr_exec_seq,
            otr_remark,
            otr_create_user,
            otr_create_timestamp,
            otr_update_user,
            otr_update_timestamp)
    values(in_txn_id,
           in_txn_code,
           i_status,
           i_ar_ind,
           i_sub_status, 
           iCnt,
           in_remark,
           in_create_user,
           sysdate,
           in_create_user,
           sysdate);

    IF SQL%ROWCOUNT = 0 THEN
        RETURN 1;
    ELSE
        RETURN 0;
    END IF;

EXCEPTION
    WHEN OTHERS THEN
        RETURN 9;
end sp_ol_txn_remarks_insert;
/

