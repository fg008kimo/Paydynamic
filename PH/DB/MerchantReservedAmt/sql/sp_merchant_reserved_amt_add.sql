CREATE OR REPLACE FUNCTION sp_merchant_res_amt_add(
    in_merchant_id        merchant_reserved_amt.mr_merchant_id%type,
    in_country_id         merchant_reserved_amt.mr_country_id%type,
    in_currency_id        merchant_reserved_amt.mr_currency_id%type,
    in_service_code       merchant_reserved_amt.mr_service_code%type,
    in_day_of_week        merchant_reserved_amt.mr_day_of_week%type,
    in_type               merchant_reserved_amt.mr_type%type,
    in_reserved           merchant_reserved_amt.mr_reserved_amount%type,
    in_remain_reserved    merchant_reserved_amt.mr_remain_reserved_amount%type,
    in_status             merchant_reserved_amt.mr_status%type,
    in_effect_date        VARCHAR2, 
    in_create_user        merchant_reserved_amt.mr_create_user%type
)
return number is

    l_approve_user        merchant_reserved_amt.mr_approve_user%type := NULL;
    l_approve_timestamp   merchant_reserved_amt.mr_approve_timestamp%type := NULL;
begin

    if in_status = 'A' then 
	l_approve_user := in_create_user;
        l_approve_timestamp := sysdate;
    end if;

    insert into merchant_reserved_amt
            (mr_merchant_id,
             mr_currency_id,
             mr_country_id,
             mr_service_code,
             mr_day_of_week,
             mr_type,
             mr_reserved_amount,
	     mr_remain_reserved_amount,
             mr_status,
             mr_effect_date,
             mr_approve_user,
             mr_approve_timestamp,
             mr_create_user,
             mr_update_user,
             mr_create_timestamp,
             mr_update_timestamp)
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
end sp_merchant_res_amt_add;
/
