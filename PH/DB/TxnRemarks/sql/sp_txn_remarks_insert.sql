CREATE OR REPLACE function sp_txn_remarks_insert(
        in_txn_id                               txn_remarks.tr_txn_id%type,
        in_txn_code                             txn_remarks.tr_txn_code%type,
        in_status                               txn_remarks.tr_status%type,
        in_ar_ind                               txn_remarks.tr_ar_ind%type,
        in_sub_status                           txn_remarks.tr_sub_status%type,
        in_remark                               txn_remarks.tr_remark%type,
        in_create_user                          txn_remarks.tr_create_user%type)
    RETURN NUMBER IS

        iCnt     INTEGER := 0;
        
        i_status          txn_remarks.tr_status%type := NULL;
        i_ar_ind          txn_remarks.tr_ar_ind%type := NULL;
        i_sub_status      txn_remarks.tr_sub_status%type := NULL;
begin

    SELECT NVL(max(tr_exec_seq),0) + 1
	  INTO iCnt
          FROM txn_remarks
         WHERE tr_txn_id = in_txn_id;

    SELECT th_status, NVL(th_ar_ind, ' '), NVL(th_sub_status, ' ')
    INTO   i_status, i_ar_ind, i_sub_status
    FROM   txn_header
    WHERE  th_txn_id = in_txn_id;
   	
    INSERT into txn_remarks (
            tr_txn_id,
            tr_txn_code,
            tr_status,
            tr_ar_ind,
            tr_sub_status,
            tr_exec_seq,
            tr_remark,
            tr_create_user,
            tr_create_timestamp,
            tr_update_user,
            tr_update_timestamp)
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
end sp_txn_remarks_insert;
/

