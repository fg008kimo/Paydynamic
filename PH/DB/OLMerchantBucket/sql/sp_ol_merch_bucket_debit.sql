DROP FUNCTION sp_ol_merch_bucket_debit;

CREATE OR REPLACE FUNCTION sp_ol_merch_bucket_debit(
	in_posting_date		ol_merchant_bucket.omb_posting_date%type,
	in_merchant_id		ol_merchant_bucket.omb_merchant_id%type,
	in_country_id		ol_merchant_bucket.omb_country_id%type,
	in_currency_id		ol_merchant_bucket.omb_currency_id%type,
	in_service_code		ol_merchant_bucket.omb_service_code%type,
	in_psp_id		ol_merchant_bucket.omb_psp_id%type,
	in_bucket_type		ol_merchant_bucket.omb_bucket_type%type,
	in_bal			ol_merchant_bucket.omb_transfer_out_bal%type,
	in_create_user		ol_merchant_bucket.omb_create_user%type
)
return number is
begin
	update ol_merchant_bucket
	  set omb_transfer_out_bal = omb_transfer_out_bal + in_bal,
              omb_update_user = in_create_user,
	      omb_update_timestamp = sysdate
        where omb_posting_date = in_posting_date
          and omb_merchant_id = in_merchant_id
          and omb_currency_id = in_currency_id
          and omb_country_id = in_country_id
          and omb_service_code = in_service_code
          and omb_psp_id = in_psp_id
          and omb_bucket_type = in_bucket_type;

	if SQL%ROWCOUNT = 0 THEN
		return 1;
	else
		return 0;
	end if;

exception
  when others then
  return 9;
end sp_ol_merch_bucket_debit;
/
