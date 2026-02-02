create or replace function sp_mms_txn_detail_insert(
       in_txn_id                                mms_txn_detail.mtd_txn_id%type,
       in_entity_id				mms_txn_detail.mtd_entity_id%type,
       in_related_entity_id			mms_txn_detail.mtd_related_entity_id%type,
       in_open_acct_bal				mms_txn_detail.mtd_open_acct_bal%type,
       in_open_intransit			mms_txn_detail.mtd_open_intransit%type,
       in_open_lien				mms_txn_detail.mtd_open_lien%type,
       in_open_prepaid				mms_txn_detail.mtd_open_prepaid%type,
       in_curr_acct_bal				mms_txn_detail.mtd_curr_acct_bal%type,
       in_curr_intransit			mms_txn_detail.mtd_curr_intransit%type,
       in_curr_lien				mms_txn_detail.mtd_curr_lien%type,
       in_curr_prepaid				mms_txn_detail.mtd_curr_prepaid%type,
       in_provided_fx_rate			mms_txn_detail.mtd_provided_fx_rate%type,
       in_fx_rate				mms_txn_detail.mtd_fx_rate%type,
       in_provided_cost_rate			mms_txn_detail.mtd_provided_cost_rate%type,
       in_provided_fixed_amount			mms_txn_detail.mtd_provided_fixed_amount%type,
       in_provided_cost			        mms_txn_detail.mtd_provided_cost%type,
       in_cost_rate				mms_txn_detail.mtd_cost_rate%type,
       in_fixed_amount				mms_txn_detail.mtd_fixed_amount%type,
       in_cost			        	mms_txn_detail.mtd_cost%type,
       in_allow_prepaid		        	mms_txn_detail.mtd_allow_prepaid%type,
       in_next_action_ccy	        	mms_txn_detail.mtd_next_action_ccy%type,
       in_fx_txn		        	mms_txn_detail.mtd_fx_txn%type,
       in_remark			      	mms_txn_detail.mtd_remark%type,
       in_create_user                           mms_txn_detail.mtd_create_user%type
	
)
  RETURN NUMBER IS
Begin

        insert into mms_txn_detail
                     (mtd_txn_id,
		      mtd_entity_id,
		      mtd_related_entity_id,
		      mtd_open_acct_bal,
		      mtd_open_intransit,
		      mtd_open_lien,
		      mtd_open_prepaid,
		      mtd_curr_acct_bal,
		      mtd_curr_intransit,
		      mtd_curr_lien,
		      mtd_curr_prepaid,
		      mtd_provided_fx_rate,
		      mtd_fx_rate,
		      mtd_provided_cost_rate,
		      mtd_provided_fixed_amount,
		      mtd_provided_cost,
		      mtd_cost_rate,
		      mtd_fixed_amount,
		      mtd_cost,
		      mtd_allow_prepaid,
		      mtd_next_action_ccy,
		      mtd_fx_txn,
		      mtd_remark,
                      mtd_create_user,
                      mtd_create_timestamp,
                      mtd_update_user,
                      mtd_update_timestamp)
          values(in_txn_id,
		in_entity_id,
		in_related_entity_id,
		in_open_acct_bal,
		in_open_intransit,
		in_open_lien,
		in_open_prepaid,
		in_curr_acct_bal,
		in_curr_intransit,
		in_curr_lien,
		in_curr_prepaid,
		in_provided_fx_rate,
		in_fx_rate,
		in_provided_cost_rate,
		in_provided_fixed_amount,
		in_provided_cost,
		in_cost_rate,
		in_fixed_amount,
		in_cost,
		in_allow_prepaid,
		in_next_action_ccy,
		in_fx_txn,
		in_remark,
                in_create_user,
                sysdate,
                in_create_user,
                sysdate);

          IF SQL%ROWCOUNT = 0 THEN
             RETURN 1;
          ELSE
             RETURN 0;
          END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_mms_txn_detail_insert;
/
