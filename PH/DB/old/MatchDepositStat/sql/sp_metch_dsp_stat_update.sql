CREATE OR REPLACE FUNCTION sp_metch_dsp_stat_update(
	in_txn_date		match_deposit_stat.ds_txn_date%type,
	in_party_type		match_deposit_stat.ds_party_type%type,
	in_party_id		match_deposit_stat.ds_party_id%type,
	in_from_ccy		match_deposit_stat.ds_from_ccy%type,
	in_to_ccy		match_deposit_stat.ds_to_ccy%type,
	in_from_amt		match_deposit_stat.ds_from_amt%type,
	in_to_amt		match_deposit_stat.ds_to_amt%type,
	in_ex_rate		match_deposit_stat.ds_ex_rate%type
)
return number is
begin
	update match_deposit_stat
	  set ds_ex_rate = (ds_ex_rate*ds_from_amt + in_ex_rate*in_from_amt)/(ds_from_amt+in_from_amt),
	      ds_from_amt= ds_from_amt + in_from_amt,
	      ds_to_amt= ds_to_amt + in_to_amt,
	      ds_update_timestamp = sysdate
        where ds_txn_date = in_txn_date
          and ds_party_type = in_party_type
	  and ds_party_id = in_party_id
	  and ds_from_ccy = in_from_ccy;

	if SQL%ROWCOUNT = 0 THEN
		insert into match_deposit_stat
                        (ds_txn_date,
                         ds_party_type,
                         ds_party_id,
                         ds_from_ccy,
                         ds_to_ccy,
                         ds_from_amt,
                         ds_to_amt,
                         ds_ex_rate,
                         ds_create_user,
                         ds_update_user,
                         ds_create_timestamp,
                         ds_update_timestamp)
                values(in_txn_date,
                       in_party_type,
                       in_party_id,
                       in_from_ccy,
                       in_to_ccy,
                       in_from_amt,
                       in_to_amt,
                       in_ex_rate,
                       'SYSTEM',
                       'SYSTEM',
                       sysdate,
                       sysdate);
                if SQL%ROWCOUNT = 0 THEN
			return 1;
		else
                        return 0;
                end if;

	else
		return 0;
	end if;

exception
  when others then
  return 9;
end sp_metch_dsp_stat_update;
/
