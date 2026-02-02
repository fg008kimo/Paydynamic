CREATE OR REPLACE FUNCTION sp_customer_psp_cnt_chk (
	in_psp_id	IN	customer_psp_counters.cpc_psp_id%TYPE,
	in_cust_id	IN	customer_psp_counters.cpc_cust_id%TYPE)
RETURN NUMBER IS
	iCnt Integer := 0;
	iCustPspThreshold Integer := 0;
	iCustPspCnt Integer := 0;
BEGIN
	select	count(*)
	into	iCnt
	from	psp_detail
	where	psp_id = in_psp_id
	and	disabled = 0;

	if iCnt > 0 then
		select	pd_daily_succ_txn_threshold
		into	iCustPspThreshold
		from	psp_detail
		where	psp_id = in_psp_id
		and	disabled = 0;
		

		begin
			select	cpc_counter
			into	iCustPspCnt
			from	customer_psp_counters
			where	cpc_psp_id = in_psp_id
			and	cpc_cust_id = in_cust_id
			and	cpc_date = to_char(sysdate, 'YYYYMMDD')
			and	cpc_category = 'CNT';
		exception
			when no_data_found then
				iCustPspCnt := 0;
		end;


		if iCustPspThreshold = 0 or iCustPspCnt < iCustPspThreshold then
			return 0;
		else
			return 1;
		end if;
	else
		return 2;
	end if;

EXCEPTION
	WHEN OTHERS THEN
		return 9;
END sp_customer_psp_cnt_chk;
/
