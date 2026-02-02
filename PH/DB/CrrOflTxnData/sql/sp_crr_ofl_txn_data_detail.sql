create or replace function sp_crr_ofl_txn_data_dt_insert(
       in_txn_id                                crr_ofl_txn_data_detail.cotd_txn_id%type,
       in_merchant_ref				crr_ofl_txn_data_detail.cotd_merchant_ref%type,
       in_client_id				crr_ofl_txn_data_detail.cotd_client_id%type,
       in_merchant_id				crr_ofl_txn_data_detail.cotd_merchant_id%type,
       in_service_code				crr_ofl_txn_data_detail.cotd_service_code%type,
       in_create_user				crr_ofl_txn_data_detail.cotd_create_user%type)

  RETURN NUMBER IS
begin

  insert into crr_ofl_txn_data_detail
              (cotd_txn_id,
		cotd_merchant_ref,
		cotd_client_id,
		cotd_merchant_id,
		cotd_service_code,
		cotd_create_timestamp,
		cotd_create_user)
         values(in_txn_id,
		in_merchant_ref,
		in_client_id,
		in_merchant_id,
		in_service_code,
		sysdate,
		in_create_user);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end  sp_crr_ofl_txn_data_dt_insert;
/
