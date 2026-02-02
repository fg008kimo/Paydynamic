create or replace function sp_crr_ofl_txn_data_hd_insert(
       in_txn_id                                crr_ofl_txn_data_header.coth_txn_id%type,
       in_txn_code                              crr_ofl_txn_data_header.coth_txn_code%type,
       in_approval_date                         crr_ofl_txn_data_header.coth_approval_date%type,
       in_country                               crr_ofl_txn_data_header.coth_country%type,
       in_ccy                                   crr_ofl_txn_data_header.coth_ccy%type,
       in_txn_amt                               crr_ofl_txn_data_header.coth_txn_amt%type,
       in_fee_ccy                               crr_ofl_txn_data_header.coth_fee_ccy%type,
       in_fee                                   crr_ofl_txn_data_header.coth_fee%type,
       in_net_ccy                               crr_ofl_txn_data_header.coth_net_ccy%type,
       in_net_amt                               crr_ofl_txn_data_header.coth_net_amt%type,
       in_markup_ccy                            crr_ofl_txn_data_header.coth_markup_ccy%type,
       in_markup_amt                            crr_ofl_txn_data_header.coth_markup_amt%type,
       in_deli_ccy                              crr_ofl_txn_data_header.coth_deli_ccy%type,
       in_deli_amt                              crr_ofl_txn_data_header.coth_deli_amt%type,
       in_related_txn_id                        crr_ofl_txn_data_header.coth_related_txn_id%type,
       in_create_user				crr_ofl_txn_data_header.coth_create_user%type)

  RETURN NUMBER IS
begin

  insert into crr_ofl_txn_data_header
              (coth_txn_id,
		coth_txn_code,
		coth_approval_date,
		coth_country,
		coth_ccy,
		coth_txn_amt,
		coth_fee_ccy,
		coth_fee,
		coth_net_ccy,
		coth_net_amt,
		coth_markup_ccy,
		coth_markup_amt,
		coth_deli_ccy,
		coth_deli_amt,
		coth_related_txn_id,
		coth_create_timestamp,
		coth_create_user)
         values(in_txn_id,
		in_txn_code,
		in_approval_date,
		in_country,
		in_ccy,
		in_txn_amt,
		in_fee_ccy,
		in_fee,
		in_net_ccy,
		in_net_amt,
		in_markup_ccy,
		in_markup_amt,
		in_deli_ccy,
		in_deli_amt,
		in_related_txn_id,
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
end  sp_crr_ofl_txn_data_hd_insert;
/
