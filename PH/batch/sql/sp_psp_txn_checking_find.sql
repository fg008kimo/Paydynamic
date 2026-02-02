CREATE OR REPLACE FUNCTION sp_psp_txn_checking_find (
  in_party_id            	psp_txn_checking.pc_party_id%Type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	select count(*)
	  into iCnt
    	from psp_txn_checking
       where pc_party_type = 'P'
         and pc_party_id = in_party_id
	 and pc_disabled = 0;

	if iCnt > 0 THEN
	      OPEN out_cursor for
	      select pc_check_count,
                     pc_min_success_count,
                     pc_min_total,
                     pc_start_buffer_period,
		     to_char(pc_cutoff_checking_time,'YYYYMMDDHH24MISS')
    		from psp_txn_checking
		where pc_party_type = 'P'
		and pc_party_id = in_party_id
		and pc_disabled = 0;

		RETURN 1;
	else
		select count(*)
		  into iCnt
		from psp_txn_checking
		where pc_party_type = 'G'
		and pc_party_id = '000'
		and pc_disabled = 0;

		if iCnt > 0 THEN
			OPEN out_cursor for
			select pc_check_count,
				pc_min_success_count,
				pc_min_total,
				pc_start_buffer_period,
				to_char(pc_cutoff_checking_time,'YYYYMMDDHH24MISS')
			from psp_txn_checking
			where pc_party_type = 'G'
			and pc_party_id = '000'
			and pc_disabled = 0;

			RETURN 1;

                end if;
	end if;


	RETURN 0;


 exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_psp_txn_checking_find;
/
