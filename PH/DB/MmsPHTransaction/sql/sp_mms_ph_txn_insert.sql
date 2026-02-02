create or replace function sp_mms_ph_txn_insert(
       in_node_id				mms_ph_transaction.mt_node_id%type,
       in_ph_txn_id				mms_ph_transaction.mt_ph_txn_id%type,
       in_client_id				mms_ph_transaction.mt_client_id%type,
       in_psp_id				mms_ph_transaction.mt_psp_id%type,
       in_baid					mms_ph_transaction.mt_baid%type,
       in_node_txn_code				mms_ph_transaction.mt_node_txn_code%type,
       in_transmission_datetime			mms_ph_transaction.mt_transmission_datetime%type,
       in_tm_date				mms_ph_transaction.mt_tm_date%type,
       in_tm_time				mms_ph_transaction.mt_tm_time%type,
       in_local_tm_date				mms_ph_transaction.mt_local_tm_date%type,
       in_local_tm_time				mms_ph_transaction.mt_local_tm_time%type,
       in_txn_amount				mms_ph_transaction.mt_txn_amount%type,
       in_txn_ccy				mms_ph_transaction.mt_txn_ccy%type,
       in_txn_country				mms_ph_transaction.mt_txn_country%type,
       in_create_user                           mms_ph_transaction.mt_create_user%type)

  RETURN NUMBER IS
begin

	INSERT into MMS_PH_TRANSACTION(
			mt_node_id,
			mt_ph_txn_id,
			mt_client_id,
			mt_psp_id,
			mt_baid,
			mt_node_txn_code,
			mt_transmission_datetime,
			mt_tm_date,
			mt_tm_time,
			mt_local_tm_date,
			mt_local_tm_time,
			mt_txn_amount,
			mt_txn_ccy,
			mt_txn_country,
			mt_create_user,
			mt_create_datetime)
		VALUES(
			in_node_id,
			in_ph_txn_id,
			in_client_id,
			in_psp_id,
			in_baid,
			in_node_txn_code,
			in_transmission_datetime,
			in_tm_date,
			in_tm_time,
			in_local_tm_date,
			in_local_tm_time,
			in_txn_amount,
			in_txn_ccy,
			in_txn_country,
			in_create_user,
			SYSDATE);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_mms_ph_txn_insert;
/
