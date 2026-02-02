create or replace function sp_txn_fee_chg_insert(
       	in_txn_id                               txn_fee_charge.tf_txn_id%type,
       	in_chg_type			        txn_fee_charge.tf_chg_type%type,
	in_party_type				txn_fee_charge.tf_party_type%type,	
	in_ccy					txn_fee_charge.tf_ccy%type,
	in_fee					txn_fee_charge.tf_fee%type,
       	in_create_user                          txn_fee_charge.tf_create_user%type)
  RETURN NUMBER IS
begin
  		insert into txn_fee_charge
              		(tf_txn_id,
			tf_chg_type,
			tf_party_type,
			tf_ccy,
			tf_fee,
			tf_create_user,
			tf_create_timestamp)
       	         values(in_txn_id,
			in_chg_type,
			in_party_type,
			in_ccy,
			in_fee,
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
end sp_txn_fee_chg_insert;
/
