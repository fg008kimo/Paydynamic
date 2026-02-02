CREATE OR REPLACE FUNCTION sp_chk_txn_bal_log_prev_cpl(
        in_txn_aprv_date        txn_balance_log.tb_txn_aprv_date%type,
        in_party_type           txn_balance_log.tb_party_type%type
)
RETURN NUMBER Is
	v_cnt			integer := 0;
	v_max_txn_aprv_date 	date;

Begin

	select	count(*)
	into	v_cnt
	from	txn_balance_log
	where	tb_party_type = in_party_type;

	if v_cnt > 0 then

		select  max(to_date(tb_txn_aprv_date, 'YYYYMMDD'))
		into	v_max_txn_aprv_date
		from    txn_balance_log
		where   tb_party_type = in_party_type;

		if (v_max_txn_aprv_date = null) or (v_max_txn_aprv_date < (to_date(in_txn_aprv_date,'YYYYMMDD') - 1)) then
			return 1;
		else	

			select  count(*)
                	into    v_cnt
                	from    txn_balance_log
                	where   tb_party_type = in_party_type
                	and     to_date(tb_txn_aprv_date, 'YYYYMMDD') < to_date(in_txn_aprv_date, 'YYYYMMDD')
                	and     tb_is_completed = 0;

			if v_cnt <= 0 then
				return 0;
			else
				return 1;
			end if;
		end if;
	else
		return 0;
	end if;

exception
  when others then
  return 9;
end sp_chk_txn_bal_log_prev_cpl;
/
