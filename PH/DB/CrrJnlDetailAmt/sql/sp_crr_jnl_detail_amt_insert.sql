create or replace function sp_crr_jnl_detail_amt_insert(
	in_jnl_id				crr_jnl_detail_amt.jnl_id%type,
        in_line_no				crr_jnl_detail_amt.line_no%type,
	in_currency_id				crr_jnl_detail_amt.currency_id%type,
	in_fx_rate				crr_jnl_detail_amt.fx_rate%type,
	in_convert_amt				crr_jnl_detail_amt.convert_amt%type,
	in_disabled				crr_jnl_detail_amt.disabled%type,
	in_create_user				crr_jnl_detail_amt.create_user%type
)
			
		RETURN NUMBER IS
		begin

			
		insert into crr_jnl_detail_amt (
				jnl_id,
				line_no,
				currency_id,
				fx_rate,
				convert_amt,
				disabled,
				create_timestamp,
				update_timestamp,
				create_user,
				update_user
 		) values (
				in_jnl_id,
				in_line_no,
				in_currency_id,
				in_fx_rate,
				in_convert_amt,
				in_disabled,
				sysdate,
				sysdate,
				in_create_user,
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
end sp_crr_jnl_detail_amt_insert;
/
