CREATE OR REPLACE FUNCTION sp_psp_txn_check_rpl(
		in_party_type      psp_txn_check.pc_party_type%type
)
RETURN NUMBER IS
	
BEGIN

  
  insert into psp_txn_check (
		pc_party_type, 
		pc_party_id, 
		pc_cutoff_checking_time, 
		pc_check_count, 
		pc_min_success_count, 
		pc_disabled, 
		pc_last_checking_time, 
		pc_start_buffer_period, 
		pc_min_total, 
		pc_create_user, 
		pc_update_user, 
		pc_create_timestamp, 
		pc_update_timestamp
	)
    select  in_party_type, 
			psp_id, 
			pc_cutoff_checking_time, 
            pc_check_count, 
			pc_min_success_count, 
			0, 
            pc_last_checking_time, 
			pc_start_buffer_period, 
			pc_min_total, 
            'SYSTEM', 
			'SYSTEM', 
			sysdate,  
			sysdate
   from (
		  select psp_id as psp_id from psp_detail
		  minus
		  select pc_party_id as psp_id
		  from psp_txn_check
		  where pc_party_type = in_party_type
		), psp_txn_check
	where pc_party_type = 'G'
	and pc_party_id = '000';


	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_psp_txn_check_rpl;
/
