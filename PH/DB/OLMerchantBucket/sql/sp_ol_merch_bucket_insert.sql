DROP FUNCTION sp_ol_merch_bucket_insert;

CREATE OR REPLACE FUNCTION sp_ol_merch_bucket_insert(
	in_posting_date		ol_merchant_bucket.omb_posting_date%type,
	in_merchant_id		ol_merchant_bucket.omb_merchant_id%type,
	in_country_id		ol_merchant_bucket.omb_country_id%type,
	in_currency_id		ol_merchant_bucket.omb_currency_id%type,
	in_service_code		ol_merchant_bucket.omb_service_code%type,
	in_psp_id		ol_merchant_bucket.omb_psp_id%type,
	in_bucket_type		ol_merchant_bucket.omb_bucket_type%type,
	in_bal			ol_merchant_bucket.omb_bal%type,
	in_create_user		ol_merchant_bucket.omb_create_user%type
)
return number is
begin
	update ol_merchant_bucket
	  set omb_bal = omb_bal + in_bal,
              omb_update_user = in_create_user,
	      omb_update_timestamp = sysdate
        where omb_posting_date = in_posting_date
          and omb_merchant_id = in_merchant_id
          and omb_country_id = in_country_id
          and omb_service_code = in_service_code
          and omb_currency_id = in_currency_id
          and omb_psp_id = in_psp_id
          and omb_bucket_type = in_bucket_type;

	if SQL%ROWCOUNT = 0 THEN
		insert into ol_merchant_bucket
			(omb_posting_date,
			 omb_merchant_id,
			 omb_country_id,
			 omb_currency_id,
			 omb_service_code,
			 omb_psp_id,
		         omb_bucket_type,
			 omb_bal,
			 omb_create_user,
			 omb_update_user,
			 omb_create_timestamp,
			 omb_update_timestamp)
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
end sp_ol_merch_bucket_insert;
/
