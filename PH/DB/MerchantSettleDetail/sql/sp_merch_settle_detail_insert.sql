CREATE OR REPLACE FUNCTION sp_merch_settle_detail_insert(
	in_txn_id		merchant_settlement_detail.sd_txn_id%type,
	in_merchant_id		merchant_settlement_detail.sd_merchant_id%type,
	in_country_id		merchant_settlement_detail.sd_country_id%type,
	in_service_code		merchant_settlement_detail.sd_service_code%type,
	in_status		merchant_settlement_detail.sd_status%type,
	in_request_ccy		merchant_settlement_detail.sd_request_ccy%type,
	in_inter_ccy		merchant_settlement_detail.sd_inter_ccy%type,
	in_deliver_ccy		merchant_settlement_detail.sd_deliver_ccy%type,
	in_request_amt		merchant_settlement_detail.sd_request_amt%type,
	in_inter_amt		merchant_settlement_detail.sd_inter_amt%type,
	in_deliver_amt		merchant_settlement_detail.sd_deliver_amt%type,
	in_remark		merchant_settlement_detail.sd_remark%type,
	in_type			merchant_settlement_detail.sd_settlement_type%type,
	in_client_sett_bank_id	merchant_settlement_detail.sd_client_sett_bank_id%type,
	in_beneficiary_bank_ac_name	merchant_settlement_detail.sd_beneficiary_bank_ac_name%type,
	in_beneficiary_bank_ac_num	merchant_settlement_detail.sd_beneficiary_bank_ac_num%type,
	in_beneficiary_bank_name	merchant_settlement_detail.sd_beneficiary_bank_name%type,
	in_address		merchant_settlement_detail.sd_address%type,
	in_swift_code		merchant_settlement_detail.sd_swift_code%type,
	in_iban			merchant_settlement_detail.sd_iban%type,
	in_bank_ac_ccy		merchant_settlement_detail.sd_bank_ac_ccy%type,
	in_merchant_notify_email	merchant_settlement_detail.sd_merchant_notify_email%type,
	in_country_subdivision	merchant_settlement_detail.sd_country_subdivision%type,
	in_city			merchant_settlement_detail.sd_city%type,
	in_country		merchant_settlement_detail.sd_country%type,
	in_create_user		merchant_settlement_detail.sd_create_user%type
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
		 sd_inter_ccy,
		 sd_deliver_ccy,
		 sd_request_amt,
		 sd_inter_amt,
		 sd_deliver_amt,
		 sd_remark,
		 sd_settlement_type,
		 sd_client_sett_bank_id,
		 sd_beneficiary_bank_ac_name,
		 sd_beneficiary_bank_ac_num,
		 sd_beneficiary_bank_name,
		 sd_address,
		 sd_swift_code,
		 sd_iban,
		 sd_bank_ac_ccy,
		 sd_merchant_notify_email,
		 sd_country_subdivision,
		 sd_city,
		 sd_country,
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
	       in_inter_ccy,
	       in_deliver_ccy,
	       in_request_amt,
	       in_inter_amt,
	       in_deliver_amt,
	       in_remark,
	       in_type,
	       in_client_sett_bank_id,
	       in_beneficiary_bank_ac_name,
	       in_beneficiary_bank_ac_num,
	       in_beneficiary_bank_name,
	       in_address,
	       in_swift_code,
	       in_iban,
	       in_bank_ac_ccy,
	       in_merchant_notify_email,
	       in_country_subdivision,
	       in_city,
	       in_country,
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
end sp_merch_settle_detail_insert;
/
