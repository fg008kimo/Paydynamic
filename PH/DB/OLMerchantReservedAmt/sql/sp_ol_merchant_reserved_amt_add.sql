CREATE OR REPLACE FUNCTION sp_ol_merchant_res_amt_add(
    in_merchant_id        ol_merchant_reserved_amt.omr_merchant_id%type,
    in_country_id         ol_merchant_reserved_amt.omr_country_id%type,
    in_currency_id        ol_merchant_reserved_amt.omr_currency_id%type,
    in_service_code       ol_merchant_reserved_amt.omr_service_code%type,
    in_day_of_week        ol_merchant_reserved_amt.omr_day_of_week%type,
    in_type               ol_merchant_reserved_amt.omr_type%type,
    in_reserved           ol_merchant_reserved_amt.omr_reserved_amount%type,
    in_remain_reserved    ol_merchant_reserved_amt.omr_remain_reserved_amount%type,
    in_status             ol_merchant_reserved_amt.omr_status%type,
    in_effect_date        VARCHAR2, 
    in_create_user        ol_merchant_reserved_amt.omr_create_user%type
)
return number is

    l_approve_user        ol_merchant_reserved_amt.omr_approve_user%type := NULL;
    l_approve_timestamp   ol_merchant_reserved_amt.omr_approve_timestamp%type := NULL;
begin

    if in_status = 'A' then 
	l_approve_user := in_create_user;
        l_approve_timestamp := sysdate;
    end if;

    insert into ol_merchant_reserved_amt
            (omr_merchant_id,
             omr_currency_id,
             omr_country_id,
             omr_service_code,
             omr_day_of_week,
             omr_type,
             omr_reserved_amount,
	     omr_remain_reserved_amount,
             omr_status,
             omr_effect_date,
             omr_approve_user,
             omr_approve_timestamp,
             omr_create_user,
             omr_update_user,
             omr_create_timestamp,
             omr_update_timestamp)
        values(in_merchant_id,
               in_currency_id,
               in_country_id,
               in_service_code,
               in_day_of_week,
               in_type,
               in_reserved,
	       in_remain_reserved,
               in_status,
               NVL(to_date(in_effect_date, 'YYYYMMDDHH24MISS'), sysdate),
               l_approve_user,
               l_approve_timestamp,
               in_create_user,
               in_create_user,
               sysdate,
               sysdate);


    if SQL%ROWCOUNT = 0 THEN
        return 1;
    else
        return 0;
    end if;

exception
  when others then
  return 9;
end sp_ol_merchant_res_amt_add;
/
