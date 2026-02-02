DROP FUNCTION SP_OL_TXN_RELATION_FIND;

CREATE OR REPLACE FUNCTION sp_ol_txn_relation_find(
    in_get_direction    VARCHAR2,
    in_party_type       ol_txn_relation.otr_fr_txn_party_type%type,
    in_txn_id           ol_txn_relation.otr_fr_txn_id%type,
    out_cursor          out    sys_refcursor)

RETURN NUMBER Is
    iCnt    integer := 0;
Begin
    if in_get_direction = 'PREVIOUS' then
        select count(*)
        into   iCnt
        from   ol_txn_relation
        where  otr_to_txn_party_type = in_party_type
        and    otr_to_txn_id = in_txn_id;

        if iCnt > 0 then
            OPEN out_cursor for
                select otr_fr_txn_party_type,
                       otr_fr_txn_id
                from ol_txn_relation
                where otr_to_txn_party_type = in_party_type
                and otr_to_txn_id = in_txn_id
                order by otr_create_timestamp;

            RETURN 1;
        end if;

    else
        if in_get_direction = 'NEXT' then
            select count(*)
            into   iCnt
            from   ol_txn_relation
            where  otr_fr_txn_party_type = in_party_type
            and    otr_fr_txn_id = in_txn_id;

            if iCnt > 0 then
                OPEN out_cursor for
                select otr_to_txn_party_type,
                       otr_to_txn_id
                from ol_txn_relation
                where otr_fr_txn_party_type = in_party_type
                and otr_fr_txn_id = in_txn_id
                order by otr_create_timestamp;

	        RETURN 1;
            end if;

        end if;

        RETURN 0;
    end if;

    RETURN 0;
exception
    WHEN OTHERS THEN
        RETURN 0;
END sp_ol_txn_relation_find;
/

