CREATE OR REPLACE FUNCTION sp_check_hand_shake_init_w_cnt (
  in_merchant_id	MERCH_DETAIL.MERCHANT_ID%TYPE,
  in_txn_cnt		check_hand_shake.ch_check_count%type,
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

		select	count(*)
		into	iCnt
		from	check_hand_shake
		where	ch_party_id = in_merchant_id 
		and	ch_min_total <= in_txn_cnt
		and	ch_disabled = 0;

		if iCnt > 0 THEN
			OPEN out_cursor for
			select	ch_check_count,
				ch_max_handshake_count,
				ch_max_init_count,
				ch_min_total,
				ch_start_buffer_period,
				to_char(ch_cutoff_checking_time,'YYYYMMDDHH24MISS')
			from	check_hand_shake
			where	ch_party_id = in_merchant_id
			and	ch_disabled = 0
			and	ch_min_total = (select max(ch_min_total)
						from check_hand_shake
						where   ch_party_id = in_merchant_id
						and     ch_disabled = 0
						and     ch_min_total <= in_txn_cnt);

                	RETURN 1;

		else
			RETURN 0;
		end if;
	
	else

		select	count(*)
		into	iCnt
		from	check_hand_shake
		where	ch_party_id = '000'
		and	ch_min_total <= in_txn_cnt
		and	ch_disabled = 0;

		if iCnt > 0 THEN
			OPEN out_cursor for
			select	ch_check_count,
				ch_max_handshake_count,
				ch_max_init_count,
				ch_min_total,
				ch_start_buffer_period,
				to_char(ch_cutoff_checking_time,'YYYYMMDDHH24MISS')
			from	check_hand_shake
			where	ch_party_id = '000'
			and	ch_disabled = 0
			and	ch_min_total = (select max(ch_min_total)
						from check_hand_shake
						where   ch_party_id = '000'
						and     ch_disabled = 0
						and     ch_min_total <= in_txn_cnt);

                	RETURN 1;

		else
			RETURN 0;
		end if;

	end if;
	


 exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_check_hand_shake_init_w_cnt;
/

