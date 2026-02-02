CREATE OR REPLACE FUNCTION sp_ol_rule_email_notify_find (
        in_merchant_id                ol_merch_detail.md_merchant_id%type,
        in_funct                      ol_rule_email_notification.ore_funct%type,
        out_cursor            OUT     sys_refcursor)
RETURN NUMBER Is
        iCnt        integer := 0;
Begin
        select count(*)
          into iCnt
          from ol_email_notify_list, ol_rule_email_notification
         where ore_party_type = 'M' 
           and ore_party_id = in_merchant_id
           and ore_funct = in_funct
           and ore_disabled = 0
           and ore_email_id = oel_id;

        if iCnt > 0 then
                OPEN out_cursor for
                    select oel_email
                      from ol_email_notify_list, ol_rule_email_notification
                     where ore_party_type = 'M' 
                       and ore_party_id = in_merchant_id
                       and ore_funct = in_funct
                       and ore_disabled = 0
                       and ore_email_id = oel_id;
                return 1;
        else
                select count(*)
                  into iCnt
                  from ol_email_notify_list, ol_merch_detail, ol_rule_email_notification
                 where ore_party_type = 'C' 
                   and md_merchant_id = in_merchant_id
                   and ore_party_id = md_client_id
                   and ore_funct = in_funct
                   and ore_disabled = 0
                   and ore_email_id = oel_id;

                if iCnt > 0 then
                        OPEN out_cursor for
                            select oel_email
                              from ol_email_notify_list, ol_merch_detail, ol_rule_email_notification
                             where ore_party_type = 'C' 
                               and md_merchant_id = in_merchant_id
                               and ore_party_id = md_client_id
                               and ore_funct = in_funct
                               and ore_disabled = 0
                               and ore_email_id = oel_id;
                        return 1;
                else
                        select count(*)
                          into iCnt 
                          from ol_email_notify_list, ol_rule_email_notification
                         where ore_party_type = 'G' 
                           and ore_funct = in_funct
                           and ore_disabled = 0
                           and ore_email_id = oel_id;
 
                        if iCnt > 0 then
                                OPEN out_cursor for
                                    select oel_email
                                      from ol_email_notify_list, ol_rule_email_notification
                                     where ore_party_type = 'G' 
                                       and ore_funct = in_funct
                                       and ore_disabled = 0
                                       and ore_email_id = oel_id;

                                return 1;
                        else 
                                return 0;

                        end if;  -- end of global
                end if; -- end of client
        end if; -- end of MID

	RETURN 0;

exception
    WHEN OTHERS THEN
        RETURN 9;
END sp_ol_rule_email_notify_find;
/

