te or replace function sp_crr_jnl_change_log_insert(
	in_jnl_change_log_id				crr_jnl_change_log.jnl_change_log_id%type,
	in_jnl_id				crr_jnl_change_log.jnl_id%type,
	in_old_value				crr_jnl_change_log.old_value%type,
	in_new_value				crr_jnl_change_log.new_value%type,
	in_change_action				crr_jnl_change_log.change_action%type,
	in_jnl_status				crr_jnl_change_log.jnl_status%type,
	in_change_user				crr_jnl_change_log.change_user%type
)
			
		RETURN NUMBER IS
		begin
			
		insert into crr_jnl_change_log (
				jnl_change_log_id,
				jnl_id,
				old_value,
				new_value,
				change_action,
				jnl_status,
				change_user,
				create_timestamp,
				create_user
 		) values (
				in_jnl_change_log_id,
				in_jnl_id,
				in_old_value,
				in_new_value,
				in_change_action,
				in_jnl_status,
				in_change_user,
				sysdate,
				in_change_user
		);
			
		IF SQL%ROWCOUNT = 0 THEN
		   RETURN 1;
		ELSE
		   RETURN 0;
		END IF;

EXCEPTION
WHEN OTHERS THEN
   RETURN 9;
end sp_crr_jnl_change_log_insert;
/
