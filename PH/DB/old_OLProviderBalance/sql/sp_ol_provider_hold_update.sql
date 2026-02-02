CREATE OR REPLACE FUNCTION sp_ol_provider_hold_update(
	in_provider_id		ol_provider_balance.ol_pb_provider_id%type,
	in_country_id		ol_provider_balance.ol_pb_country_id%type,
	in_currency_id		ol_provider_balance.ol_pb_currency_id%type,
	in_bal			ol_provider_balance.ol_pb_total_hold%type,
	in_create_user		ol_provider_balance.ol_pb_create_user%type
)
return number is
begin
	update ol_provider_balance
	  set ol_pb_total_hold = ol_pb_total_hold + in_bal,
              ol_pb_update_user = in_create_user,
	      ol_pb_update_timestamp = sysdate
        where ol_pb_provider_id = in_provider_id
	  and ol_pb_country_id = in_country_id
          and ol_pb_currency_id = in_currency_id;

	if SQL%ROWCOUNT = 0 THEN
		insert into ol_provider_balance
			(ol_pb_provider_id,
			 ol_pb_country_id,
			 ol_pb_currency_id,
			 ol_pb_total_hold,
			 ol_pb_create_user,
			 ol_pb_update_user,
			 ol_pb_create_timestamp,
			 ol_pb_update_timestamp)
		values(in_provider_id,
		       in_country_id,
                       in_currency_id,
		       in_bal,
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
end sp_ol_provider_hold_update;
/
