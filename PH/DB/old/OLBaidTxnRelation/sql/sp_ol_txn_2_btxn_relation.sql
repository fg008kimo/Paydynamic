CREATE OR REPLACE FUNCTION sp_ol_txn_2_btxn_relation(
    in_txn_id           ol_baid_txn_relation.btr_txn_id%type,
    out_cursor          out    sys_refcursor)

RETURN NUMBER Is
    iCnt    integer := 0;
Begin
    select count(*)
    into   iCnt    
    from   ol_baid_txn_relation
    where  btr_txn_id = in_txn_id;

    if iCnt > 0 then
        OPEN out_cursor for
            select btr_baid_txn_id
            from ol_baid_txn_relation
            where btr_txn_id = in_txn_id 
            order by btr_create_timestamp;

        RETURN 1;
    end if;

    RETURN 0;
exception
    WHEN OTHERS THEN
        RETURN 0;
END sp_ol_txn_2_btxn_relation;
/

