CREATE OR REPLACE FUNCTION sp_tmp_cal_amt_insert(
	in_txn_id		tmp_cal_amount.tc_txn_id%type,
	in_src_ccy		tmp_cal_amount.tc_src_ccy%type,
	in_src_net_amt		tmp_cal_amount.tc_src_net_amt%type,
	in_src_fee		tmp_cal_amount.tc_src_fee%type,
	in_dst_ccy		tmp_cal_amount.tc_dst_ccy%type,
	in_dst_net_amt		tmp_cal_amount.tc_dst_net_amt%type,
	in_dst_fee		tmp_cal_amount.tc_dst_fee%type,
	in_ex_party		tmp_cal_amount.tc_ex_party%type,
	in_ex_rate		tmp_cal_amount.tc_ex_rate%type,
	in_markup_ccy		tmp_cal_amount.tc_markup_ccy%type,
	in_markup_rate		tmp_cal_amount.tc_markup_rate%type,
	in_markup_amt		tmp_cal_amount.tc_markup_amt%type,
	in_inter_ccy		tmp_cal_amount.tc_inter_ccy%type,
	in_inter_rate		tmp_cal_amount.tc_inter_rate%type,
	in_create_user		tmp_cal_amount.tc_create_user%type
)
return number is
begin
	update tmp_cal_amount
	  set tc_src_ccy = in_src_ccy,
	      tc_src_net_amt = in_src_net_amt,
	      tc_src_fee = in_src_fee,
	      tc_dst_ccy = in_dst_ccy,
	      tc_dst_net_amt = in_dst_net_amt,
	      tc_dst_fee = in_dst_fee,
	      tc_ex_party = in_ex_party,
	      tc_ex_rate = in_ex_rate,
	      tc_markup_ccy = in_markup_ccy,
	      tc_markup_rate = in_markup_rate,
	      tc_markup_amt = in_markup_amt,
	      tc_inter_ccy = in_inter_ccy,
	      tc_inter_rate = in_inter_rate,
              tc_update_user = in_create_user,
	      tc_update_timestamp = sysdate
        where tc_txn_id = in_txn_id;

	if SQL%ROWCOUNT = 0 THEN
		insert into tmp_cal_amount
                        (tc_txn_id,
			 tc_src_ccy,
			 tc_src_net_amt,
			 tc_src_fee,
			 tc_dst_ccy,
			 tc_dst_net_amt,
			 tc_dst_fee,
			 tc_ex_party,
			 tc_ex_rate,
			 tc_markup_ccy, 
			 tc_markup_rate,
			 tc_markup_amt,
			 tc_inter_ccy,
			 tc_inter_rate,
                         tc_create_user,
                         tc_update_user,
                         tc_create_timestamp,
                         tc_update_timestamp)
                values(in_txn_id,
		       in_src_ccy,
		       in_src_net_amt,
		       in_src_fee,
		       in_dst_ccy,
		       in_dst_net_amt,
		       in_dst_fee,
		       in_ex_party,
		       in_ex_rate,
		       in_markup_ccy,
		       in_markup_rate,
		       in_markup_amt,
		       in_inter_ccy,
		       in_inter_rate,
                       in_create_user,
                       in_create_user,
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
end sp_tmp_cal_amt_insert;
/
