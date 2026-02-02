DROP FUNCTION SP_MERCHANT_BUCKET_DEBIT;

CREATE OR REPLACE FUNCTION sp_merchant_bucket_debit(
	in_posting_date		merchant_bucket.mb_posting_date%type,
	in_merchant_id		merchant_bucket.mb_merchant_id%type,
	in_country_id		merchant_bucket.mb_country_id%type,
	in_currency_id		merchant_bucket.mb_currency_id%type,
	in_service_code		merchant_bucket.mb_service_code%type,
	in_psp_id		merchant_bucket.mb_psp_id%type,
	in_bucket_type		merchant_bucket.mb_bucket_type%type,
	in_bal			merchant_bucket.mb_transfer_out_bal%type,
	in_create_user		merchant_bucket.mb_create_user%type
)
return number is
begin
	update merchant_bucket
	  set mb_transfer_out_bal = mb_transfer_out_bal + in_bal,
              mb_update_user = in_create_user,
	      mb_update_timestamp = sysdate
        where mb_posting_date = in_posting_date
          and mb_merchant_id = in_merchant_id
          and mb_currency_id = in_currency_id
          and mb_country_id = in_country_id
          and mb_service_code = in_service_code
          and mb_psp_id = in_psp_id
          and mb_bucket_type = in_bucket_type;

	if SQL%ROWCOUNT = 0 THEN
		return 1;
	else
		return 0;
	end if;

exception
  when others then
  return 9;
end sp_merchant_bucket_debit;
/
