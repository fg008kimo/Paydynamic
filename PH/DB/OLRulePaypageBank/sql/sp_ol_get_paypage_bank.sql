CREATE OR REPLACE FUNCTION sp_ol_get_paypage_bank (
    in_merchant_id                ol_merch_detail.md_merchant_id%type,
    in_client_id                  clients.client_id%type,
    out_cursor            out     sys_refcursor)

RETURN NUMBER Is
    iCnt         integer := 0;
Begin

    select count(1)
    into   iCnt
    from   ol_rule_paypage_bank
    where  rpb_party_type = 'M'
    and    rpb_party_id = in_merchant_id
    and    rpb_disabled = 0;

    if iCnt > 0 then
        OPEN out_cursor for
            select rpb_int_bank_code, rpb_display_order
            from   ol_rule_paypage_bank
            where  rpb_party_type = 'M'
            and    rpb_party_id = in_merchant_id
            and    rpb_disabled = 0
            order by rpb_display_order;

        return 1;
    else 
        select count(1)
        into   iCnt
        from   ol_rule_paypage_bank
        where  rpb_party_type = 'C'
        and    rpb_party_id = in_client_id
        and    rpb_disabled = 0;

        if iCnt > 0 then
            OPEN out_cursor for
                select rpb_int_bank_code, rpb_display_order
                from   ol_rule_paypage_bank
                where  rpb_party_type = 'C'
                and    rpb_party_id = in_client_id
                and    rpb_disabled = 0
                order by rpb_display_order;
 
            return 1;
        else 
            select count(1)
            into   iCnt
            from   ol_rule_paypage_bank
            where  rpb_party_type = 'G'
            and    rpb_disabled = 0;

            if iCnt > 0 then
                OPEN out_cursor for
                    select rpb_int_bank_code, rpb_display_order
                    from   ol_rule_paypage_bank
                    where  rpb_party_type = 'G'
                    and    rpb_disabled = 0
                    order by rpb_display_order;
 
                return 1;
            else 
                return 0;
            end if;

        end if;
    end if;

    return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_ol_get_paypage_bank;
/
