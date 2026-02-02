create or replace function sp_fundsout_insert(
       in_fundout_date                         funds_out.fo_fundout_date%type,
       in_fundout_ccy			 	funds_out.fo_fundout_ccy%type,
       in_fundout_amt				funds_out.fo_fundout_amount%type,
       in_bank_bal				funds_out.fo_bank_bal%type,
       in_create_user                           funds_out.fo_create_user%type,
       out_id			OUT		funds_out.fo_id%type)
  RETURN NUMBER IS
	--iNewId	integer :=0;
begin

  select nvl(max(fo_id),0) +1
  into out_id
  from funds_out;

  insert into funds_out
              ( fo_id,
		fo_fundout_date,
                fo_fundout_ccy,
		fo_fundout_amount,
		fo_bank_bal,
		fo_create_user,
		fo_create_timestamp,
		fo_update_user,
		fo_update_timestamp)
         values(out_id,
		in_fundout_date,
		in_fundout_ccy,
		in_fundout_amt,
		in_bank_bal,
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
end sp_fundsout_insert;
/
