CREATE OR REPLACE FUNCTION sp_check_handshake_init_cftime (
  in_merchant_id	MERCH_DETAIL.MERCHANT_ID%TYPE,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt		integer := 0;

Begin
	select	count(*)
	into	iCnt
    	from	check_hand_shake
	where	ch_party_id = in_merchant_id
	and	ch_disabled = 0;

	if iCnt > 0 THEN

		OPEN out_cursor for
		select	ch_start_buffer_period,
			cf_time
		from(	select	ch_start_buffer_period,
				to_char(ch_cutoff_checking_time,'YYYYMMDDHH24MISS') cf_time
			from	check_hand_shake
			where	ch_party_id = in_merchant_id
			and	ch_disabled = 0
			and	ch_cutoff_checking_time = (select max(ch_cutoff_checking_time)
						from check_hand_shake
						where   ch_party_id = in_merchant_id
						and     ch_disabled = 0)
		)
		GROUP BY ch_start_buffer_period, cf_time;

		return 1;
	
	else

		OPEN out_cursor for
		select	ch_start_buffer_period,
			cf_time
		from(	select	ch_start_buffer_period,
				to_char(ch_cutoff_checking_time,'YYYYMMDDHH24MISS') cf_time
			from	check_hand_shake
			where	ch_party_id ='000' 
			and	ch_disabled = 0
			and	ch_cutoff_checking_time = (select max(ch_cutoff_checking_time)
						from check_hand_shake
						where   ch_party_id = '000'
						and     ch_disabled = 0)
		)
		GROUP BY ch_start_buffer_period, cf_time;


		return 1;
	end if;
	


 exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_check_handshake_init_cftime;
/

