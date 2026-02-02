CREATE OR REPLACE FUNCTION sp_dsp_match_stat_reset(
	in_txn_date		deposit_match_stat.ds_txn_date%type,
	in_party_type		deposit_match_stat.ds_party_type%type
)
return number is
begin
	update deposit_match_stat
	  set ds_amt= 0,
	      ds_to_amt= 0,
	      ds_ex_rate= 0,
	      ds_txn_count = 0,
	      ds_to_ccy = NULL
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
end sp_dsp_match_stat_reset;
/
