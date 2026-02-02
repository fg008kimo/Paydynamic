create or replace function sp_crr_ext_jnl_log_insert(
	in_jnl_id				crr_ext_jnl_log.ejl_jnl_id%type,
	in_jnl_type_id				crr_ext_jnl_log.ejl_jnl_type_id%type,
	in_txn_date				crr_ext_jnl_log.ejl_txn_date%type,
	in_disabled				crr_ext_jnl_log.ejl_jnl_disabled%type,
	in_create_user				crr_ext_jnl_log.ejl_create_user%type
)
RETURN NUMBER IS
begin

	insert into crr_ext_jnl_log (
                                ejl_jnl_id, 
                                ejl_jnl_type_id, 
                                ejl_txn_date, 
                                ejl_jnl_disabled, 
                                ejl_create_timestamp, 
                                ejl_create_user, 
                                ejl_update_timestamp, 
                                ejl_update_user)
        values (in_jnl_id, 
                in_jnl_type_id,
                in_txn_date,
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
end sp_crr_ext_jnl_log_insert;
/

