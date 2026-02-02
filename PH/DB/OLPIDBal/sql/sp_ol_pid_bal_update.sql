CREATE OR REPLACE FUNCTION sp_ol_pid_bal_update(
	in_psp_id		ol_pid_bal.opb_pid%type,
	in_country_id		ol_pid_bal.opb_country_id%type,
	in_currency_id		ol_pid_bal.opb_currency_id%type,
	in_bal			ol_pid_bal.opb_bal%type,
	in_create_user		ol_pid_bal.opb_create_user%type
)
return number is
begin
	update ol_pid_bal
	  set opb_bal = opb_bal + in_bal,
              opb_update_user = in_create_user,
	      opb_update_timestamp = sysdate
        where opb_pid = in_psp_id
	  and opb_country_id = in_country_id
          and opb_currency_id = in_currency_id;

	if SQL%ROWCOUNT = 0 THEN
		insert into ol_pid_bal
			(opb_pid,
			 opb_country_id,
			 opb_currency_id,
			 opb_bal,
			 opb_create_user,
			 opb_update_user,
			 opb_create_timestamp,
			 opb_update_timestamp)
		values(in_psp_id,
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
end sp_ol_pid_bal_update;
/
