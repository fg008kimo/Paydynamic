DROP FUNCTION SP_MERCHANT_BUCKET_INSERT;

CREATE OR REPLACE FUNCTION sp_merchant_bucket_insert(
	in_posting_date		merchant_bucket.mb_posting_date%type,
	in_merchant_id		merchant_bucket.mb_merchant_id%type,
	in_country_id		merchant_bucket.mb_country_id%type,
	in_currency_id		merchant_bucket.mb_currency_id%type,
	in_service_code		merchant_bucket.mb_service_code%type,
	in_psp_id		merchant_bucket.mb_psp_id%type,
	in_bucket_type		merchant_bucket.mb_bucket_type%type,
	in_bal			merchant_bucket.mb_bal%type,
	in_create_user		merchant_bucket.mb_create_user%type
)
return number is
begin
	update merchant_bucket
	  set mb_bal = mb_bal + in_bal,
              mb_update_user = in_create_user,
	      mb_update_timestamp = sysdate
        where mb_posting_date = in_posting_date
          and mb_merchant_id = in_merchant_id
          and mb_country_id = in_country_id
          and mb_service_code = in_service_code
          and mb_currency_id = in_currency_id
          and mb_psp_id = in_psp_id
          and mb_bucket_type = in_bucket_type;

	if SQL%ROWCOUNT = 0 THEN
		insert into merchant_bucket
			(mb_posting_date,
			 mb_merchant_id,
			 mb_country_id,
			 mb_currency_id,
			 mb_service_code,
			 mb_psp_id,
		         mb_bucket_type,
			 mb_bal,
			 mb_create_user,
			 mb_update_user,
			 mb_create_timestamp,
			 mb_update_timestamp)
		values(in_posting_date,
		       in_merchant_id,
		       in_country_id,
                       in_currency_id,
		       in_service_code,
                       in_psp_id,
		       in_bucket_type,
                       in_bal,
		       in_create_user,
                       in_create_user,
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
end sp_merchant_bucket_insert;
/
