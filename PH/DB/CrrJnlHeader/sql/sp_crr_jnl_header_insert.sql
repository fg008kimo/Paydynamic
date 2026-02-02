create or replace function sp_crr_jnl_header_insert(
	in_jnl_id				crr_jnl_header.jnl_id%type,
	in_jnl_type_id				crr_jnl_header.jnl_type_id%type,
	in_description				crr_jnl_header.description%type DEFAULT NULL,
	in_txn_date				crr_jnl_header.txn_date%type,
	in_bank_update_date				crr_jnl_header.bank_update_date%type DEFAULT NULL,
	in_acc_year				crr_jnl_header.acc_year%type,
	in_acc_month				crr_jnl_header.acc_month%type,
	in_country_code				crr_jnl_header.country_code%type DEFAULT NULL,
	in_product_code				crr_jnl_header.product_code%type DEFAULT NULL,
	in_ref_no				crr_jnl_header.ref_no%type DEFAULT NULL,	
	in_remarks				crr_jnl_header.remarks%type DEFAULT NULL,
	in_status				crr_jnl_header.status%type,
	in_disabled				crr_jnl_header.disabled%type,
	in_create_user				crr_jnl_header.create_user%type
)
			
		RETURN NUMBER IS
		begin
			
		insert into crr_jnl_header (
				jnl_id,
				jnl_type_id,
				description,
				txn_date,
				bank_update_date,
				acc_year,
				acc_month,
				country_code,
				product_code,
				ref_no,
				remarks,
				status,
				disabled,
				create_timestamp,
				create_user,
				update_timestamp,
				update_user
 		) values (
				in_jnl_id,
				in_jnl_type_id,
				in_description,
				in_txn_date,
				in_bank_update_date,
				in_acc_year,
				in_acc_month,
				in_country_code,
				in_product_code,				
				in_ref_no,
				in_remarks,
				in_status,
				in_disabled,
				sysdate,
				in_create_user,
				sysdate,
				in_create_user
		);
			
		IF SQL%ROWCOUNT = 0 THEN
		   RETURN 1;
		ELSE
		   RETURN 0;
		END IF;

EXCEPTION
WHEN OTHERS THEN
   RETURN 9;
end sp_crr_jnl_header_insert;
/

