create or replace function sp_crr_ofl_txn_data_pdt_insert(
       in_txn_id                                crr_ofl_txn_data_psp_detail.cotp_txn_id%type,
       in_client_id                             crr_ofl_txn_data_psp_detail.cotp_client_id%type,
       in_psp_id                                crr_ofl_txn_data_psp_detail.cotp_psp_id%type,
       in_baid                                  crr_ofl_txn_data_psp_detail.cotp_baid%type,
       in_baid_category                         crr_ofl_txn_data_psp_detail.cotp_baid_category%type,
       in_psp_ccy                               crr_ofl_txn_data_psp_detail.cotp_psp_ccy%type,
       in_psp_amt                               crr_ofl_txn_data_psp_detail.cotp_psp_amt%type,
       in_create_user				crr_ofl_txn_data_psp_detail.cotp_create_user%type)

  RETURN NUMBER IS
begin

  insert into crr_ofl_txn_data_psp_detail
              (cotp_txn_id,
		cotp_client_id,
		cotp_psp_id,
		cotp_baid,
		cotp_baid_category,
		cotp_psp_ccy,
		cotp_psp_amt,
		cotp_create_timestamp,
		cotp_create_user)
         values(in_txn_id,
		in_client_id,
		in_psp_id,
		in_baid,
		in_baid_category,
		in_psp_ccy,
		in_psp_amt,
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
end  sp_crr_ofl_txn_data_pdt_insert;
/
