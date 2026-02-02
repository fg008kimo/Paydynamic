DROP FUNCTION SP_MERCHANT_LIEN_BUCKET_INSERT;

CREATE OR REPLACE FUNCTION sp_merchant_lien_bucket_insert(
	in_merchant_id		merchant_lien_bucket.mb_merchant_id%type,
	in_country_id		merchant_lien_bucket.mb_country_id%type,
	in_currency_id		merchant_lien_bucket.mb_currency_id%type,
	in_service_code		merchant_lien_bucket.mb_service_code%type,
	in_bal			merchant_lien_bucket.mb_bal%type
)
return number is
begin
	update merchant_lien_bucket
	  set mb_bal = mb_bal + in_bal,
	      mb_update_timestamp = sysdate
        where mb_merchant_id = in_merchant_id
          and mb_country_id = in_country_id
          and mb_service_code = in_service_code
          and mb_currency_id = in_currency_id;

	if SQL%ROWCOUNT = 0 THEN
		insert into merchant_lien_bucket
			(
			 mb_merchant_id,
			 mb_country_id,
			 mb_currency_id,
			 mb_service_code,
			 mb_bal,
			 mb_create_user,
			 mb_update_user,
			 mb_create_timestamp,
			 mb_update_timestamp)
		values(
		       in_merchant_id,
		       in_country_id,
                       in_currency_id,
		       in_service_code,
                       in_bal,
		       'SYSTEM',
                       'SYSTEM',
		       sysdate,
		       sysdate);
		if SQL%ROWCOUNT = 0 THEN
			return 1;

		else
			return 0;
		end if;
	else
		return 0;
	end if;

exception
  when others then
  return 9;
end sp_merchant_lien_bucket_insert;
/
