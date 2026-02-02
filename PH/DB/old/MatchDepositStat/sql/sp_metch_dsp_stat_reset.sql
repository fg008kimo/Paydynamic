CREATE OR REPLACE FUNCTION sp_metch_dsp_stat_reset(
	in_txn_date		match_deposit_stat.ds_txn_date%type,
	in_party_type		match_deposit_stat.ds_party_type%type
)
return number is
begin
	update match_deposit_stat
	  set ds_from_amt= 0,
	      ds_to_amt= 0,
	      ds_ex_rate= 0
        where ds_txn_date = in_txn_date
          and ds_party_type = in_party_type;

	if SQL%ROWCOUNT = 0 THEN
		return 1;
	else
		return 0;
	end if;

exception
  when others then
  return 9;
end sp_metch_dsp_stat_reset;
/
