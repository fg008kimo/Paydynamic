CREATE OR REPLACE FUNCTION sp_par_merch_settle_dt_insert (
	in_txn_id		merchant_settlement_detail.sd_txn_id%type,
	in_merchant_id		merchant_settlement_detail.sd_merchant_id%type,
	in_country_id		merchant_settlement_detail.sd_country_id%type,
	in_service_code		merchant_settlement_detail.sd_service_code%type,
	in_status		merchant_settlement_detail.sd_status%type,
	in_request_ccy		merchant_settlement_detail.sd_request_ccy%type,
	in_deliver_ccy		merchant_settlement_detail.sd_deliver_ccy%type,
	in_request_amt		merchant_settlement_detail.sd_request_amt%type,
	in_deliver_amt		merchant_settlement_detail.sd_deliver_amt%type,
	in_remark		merchant_settlement_detail.sd_remark%type,
	in_type			merchant_settlement_detail.sd_settlement_type%type,
	in_create_user		merchant_settlement_detail.sd_create_user%type,
        in_create_datetime      VARCHAR2, --merchant_settlement_detail.sd_create_timestamp%type,
        in_update_datetime      VARCHAR2 --merchant_settlement_detail.sd_update_timestamp%type
)
return number is
begin
	insert into merchant_settlement_detail
		(sd_txn_id,
		 sd_merchant_id,
		 sd_country_id,
		 sd_service_code,
		 sd_status,
		 sd_request_ccy,
		 sd_deliver_ccy,
		 sd_request_amt,
		 sd_deliver_amt,
		 sd_remark,
		 sd_settlement_type,
		 sd_create_user,
		 sd_update_user,
		 sd_create_timestamp,
		 sd_update_timestamp)
	values(in_txn_id,
               in_merchant_id,
               in_country_id,
	       in_service_code,
	       in_status,
	       in_request_ccy,
	       in_deliver_ccy,
	       in_request_amt,
	       in_deliver_amt,
	       in_remark,
	       in_type,
	       in_create_user,
	       in_create_user,
	       --sysdate,
	       --sysdate
               to_date(in_create_datetime, 'YYYYMMDDHH24MISS'),
               to_date(in_update_datetime, 'YYYYMMDDHH24MISS'));

	if SQL%ROWCOUNT = 0 THEN
		return 1;

	else
		return 0;
	end if;

exception
  when others then
  return 9;
end sp_par_merch_settle_dt_insert;
/
