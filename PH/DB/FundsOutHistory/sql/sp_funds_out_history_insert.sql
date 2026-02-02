create or replace function sp_funds_out_history_insert(
       in_funds_out_id				funds_out_history.fo_funds_out_id%type,
       in_funds_out_date                        funds_out_history.fo_funds_out_date%type,
       in_from_ccy			 	funds_out_history.fo_from_ccy%type,
       in_funds_out_ccy				funds_out_history.fo_funds_out_ccy%type,
       in_funds_out_amt			 	funds_out_history.fo_funds_out_amt%type,
       in_old_bal				funds_out_history.fo_old_bal%type,
       in_new_bal				funds_out_history.fo_new_bal%type,
       in_create_user                           funds_out_history.fo_create_user%type)
  RETURN NUMBER IS
begin

  insert into funds_out_history
              (fo_funds_out_id,
                fo_funds_out_date,
                fo_funds_out_ccy,
		fo_funds_out_amt,
		fo_from_ccy,
		fo_old_bal,
		fo_new_bal,
		fo_create_user,
		fo_create_timestamp,
		fo_update_user,
		fo_update_timestamp)
         values(in_funds_out_id,
		in_funds_out_date,
		in_funds_out_ccy,
		in_funds_out_amt,
		in_from_ccy,
		in_old_bal,
		in_new_bal,
                in_create_user,
                sysdate,
                in_create_user,
                sysdate);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_funds_out_history_insert;
/
