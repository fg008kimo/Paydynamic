create or replace function sp_crr_mi_txn_data_insert(
       in_txn_id                                crr_mi_txn_data.cmtd_txn_id%type,
       in_txn_code                              crr_mi_txn_data.cmtd_txn_code%type,
       in_approval_date                         crr_mi_txn_data.cmtd_approval_date%type,
       in_entity_id                             crr_mi_txn_data.cmtd_entity_id%type,
       in_party_type                            crr_mi_txn_data.cmtd_party_type%type,
       in_party_id                              crr_mi_txn_data.cmtd_party_id%type,
       in_txn_product                           crr_mi_txn_data.cmtd_txn_product%type,
       in_country                               crr_mi_txn_data.cmtd_country%type,
       in_ccy                                   crr_mi_txn_data.cmtd_ccy%type,
       in_txn_amt                               crr_mi_txn_data.cmtd_txn_amt%type,
       in_net_ccy                               crr_mi_txn_data.cmtd_net_ccy%type,
       in_net_amt                               crr_mi_txn_data.cmtd_net_amt%type,
       in_intr_amt                              crr_mi_txn_data.cmtd_intr_amt%type,
       in_ovpa_amt                              crr_mi_txn_data.cmtd_ovpa_amt%type,
       in_udpa_amt                              crr_mi_txn_data.cmtd_udpa_amt%type,
       in_fee_ccy                               crr_mi_txn_data.cmtd_fee_ccy%type,
       in_fee_amt                               crr_mi_txn_data.cmtd_fee_amt%type,
       in_create_user				crr_mi_txn_data.cmtd_create_user%type)

  RETURN NUMBER IS
begin

  insert into crr_mi_txn_data
               (cmtd_txn_id,
		cmtd_txn_code,
		cmtd_approval_date,
		cmtd_entity_id,
		cmtd_party_type,
		cmtd_party_id,
		cmtd_txn_product,
		cmtd_country,
		cmtd_ccy,
		cmtd_txn_amt,
		cmtd_net_ccy,
		cmtd_net_amt,
		cmtd_intr_amt,
		cmtd_ovpa_amt,
		cmtd_udpa_amt,
		cmtd_fee_ccy,
		cmtd_fee_amt,
		cmtd_create_timestamp,
		cmtd_create_user)
         values(in_txn_id,
		in_txn_code,
		in_approval_date,
		in_entity_id,
		in_party_type,
		in_party_id,
		in_txn_product,
		in_country,
		in_ccy,
		in_txn_amt,
		in_net_ccy,
		in_net_amt,
		in_intr_amt,
		in_ovpa_amt,
		in_udpa_amt,
		in_fee_ccy,
		in_fee_amt,
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
end  sp_crr_mi_txn_data_insert;
/
