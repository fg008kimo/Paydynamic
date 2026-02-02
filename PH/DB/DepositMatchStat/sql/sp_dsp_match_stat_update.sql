CREATE OR REPLACE FUNCTION sp_dsp_match_stat_update(
	in_txn_date		deposit_match_stat.ds_txn_date%type,
	in_party_type		deposit_match_stat.ds_party_type%type,
	in_party_id		deposit_match_stat.ds_party_id%type,
	in_amt_type		deposit_match_stat.ds_amt_type%type,
	in_from_ccy		deposit_match_stat.ds_ccy%type,
	in_from_amt		deposit_match_stat.ds_amt%type,
	in_to_ccy		deposit_match_stat.ds_to_ccy%type,
	in_to_amt		deposit_match_stat.ds_to_amt%type,
	in_ex_rate		deposit_match_stat.ds_ex_rate%type
)
return number is
begin
	update deposit_match_stat
	  set ds_ex_rate = (ds_ex_rate*ds_amt + in_ex_rate*in_from_amt)/(ds_amt+in_from_amt),
	      ds_amt= ds_amt + in_from_amt,
	      ds_to_amt= ds_to_amt + in_to_amt,
	      ds_txn_count = ds_txn_count + 1,
	      ds_update_timestamp = sysdate
        where ds_txn_date = in_txn_date
          and ds_party_type = in_party_type
	  and ds_party_id = in_party_id
	  and ds_ccy = in_from_ccy
	  and ds_amt_type = in_amt_type;

	if SQL%ROWCOUNT = 0 THEN
		insert into deposit_match_stat
                        (ds_txn_date,
                         ds_party_type,
                         ds_party_id,
                         ds_amt_type,
                         ds_txn_count,
                         ds_ccy,
                         ds_to_ccy,
                         ds_amt,
                         ds_to_amt,
                         ds_ex_rate,
                         ds_create_user,
                         ds_update_user,
                         ds_create_timestamp,
                         ds_update_timestamp)
                values(in_txn_date,
                       in_party_type,
                       in_party_id,
                       in_amt_type,
		       1,
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
end sp_dsp_match_stat_update;
/
