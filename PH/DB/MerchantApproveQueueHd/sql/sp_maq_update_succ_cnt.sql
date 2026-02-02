CREATE OR REPLACE FUNCTION sp_maq_update_succ_cnt(
	in_approve_id		merchant_approve_queue_hd.qh_approve_id%type,
	in_amt			merchant_approve_queue_hd.qh_success_req_amt%type
)
return number is
begin
	update merchant_approve_queue_hd
	  set qh_success_req_amt = qh_success_req_amt + in_amt,
	      qh_success_count = qh_success_count + 1,
	      qh_update_timestamp = sysdate,
	      qh_update_user = 'SYSTEM' 
        where qh_approve_id = in_approve_id;

	if SQL%ROWCOUNT = 0 THEN
		return 1;
	else
		return 0;
	end if;

exception
  when others then
  return 9;
end sp_maq_update_succ_cnt;
/
