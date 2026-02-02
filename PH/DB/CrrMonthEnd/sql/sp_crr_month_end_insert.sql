create or replace function sp_crr_month_end_insert(
	in_tb_year				crr_month_end.tb_year%type,
	in_tb_month				crr_month_end.tb_month%type,
	in_closed				crr_month_end.closed%type,
	in_disabled				crr_month_end.disabled%type,
	in_create_user				crr_month_end.create_user%type
)
			
		RETURN NUMBER IS
		begin
			
		insert into crr_month_end (
				tb_year,
				tb_month,
				closed,
				disabled,
				create_timestamp,
				update_timestamp,
				create_user,
				update_user
 		) values (
				in_tb_year,
				in_tb_month,
				in_closed,
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
end sp_crr_month_end_insert;
/

