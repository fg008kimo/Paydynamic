create or replace function sp_fundsin_insert(
       in_fundin_date                         funds_in.f_fundin_date%type,
       in_fundin_ccy				funds_in.f_fundin_ccy%type,
       in_fundin_amt			 	funds_in.f_fundin_amount%type,
       in_bank_ccy			 	funds_in.f_bank_ccy%type,
       in_bank_amt				funds_in.f_bank_amount%type,
       in_create_user                           funds_in.f_create_user%type,
       out_id			OUT		funds_in.f_id%type)
  RETURN NUMBER IS
	--iNewId	integer :=0;
begin

  select nvl(max(f_id),0) +1
  into out_id
  from funds_in;

  insert into funds_in
              ( f_id,
		f_fundin_date,
                f_fundin_ccy,
		f_fundin_amount,
		f_bank_ccy,
		f_bank_amount,
		f_approval_user,
		f_approval_timestamp,
		f_create_user,
		f_create_timestamp,
		f_update_user,
		f_update_timestamp)
         values(out_id,
		in_fundin_date,
		in_fundin_ccy,
		in_fundin_amt,
		in_bank_ccy,
		in_bank_amt,
                in_create_user,
                sysdate,
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
end sp_fundsin_insert;
/
