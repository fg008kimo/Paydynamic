create or replace function sp_funds_in_history_insert(
       in_funds_in_id	                        funds_in_history.fi_funds_in_id%type,
       in_funds_in_date                         funds_in_history.fi_funds_in_date%type,
       in_funds_in_ccy				funds_in_history.fi_funds_in_ccy%type,
       in_funds_in_amt			 	funds_in_history.fi_funds_in_amt%type,
       in_bank_ccy			 	funds_in_history.fi_bank_ccy%type,
       in_bank_amt				funds_in_history.fi_bank_amt%type,
       in_bank_bal				funds_in_history.fi_bank_bal%type,
       in_old_rate				funds_in_history.fi_old_rate%type,
       in_new_rate				funds_in_history.fi_new_rate%type,
       in_old_ratio				funds_in_history.fi_old_ratio%type,
       in_new_ratio				funds_in_history.fi_new_ratio%type,
       in_create_user                           funds_in_history.fi_create_user%type)
  RETURN NUMBER IS
begin

  insert into funds_in_history
              (fi_funds_in_id,
                fi_funds_in_date,
                fi_funds_in_ccy,
		fi_funds_in_amt,
		fi_bank_ccy,
		fi_bank_amt,
		fi_bank_bal,
		fi_old_rate,
		fi_new_rate,
		fi_old_ratio,
		fi_new_ratio,
		fi_create_user,
		fi_create_timestamp,
		fi_update_user,
		fi_update_timestamp)
         values(in_funds_in_id,
		in_funds_in_date,
		in_funds_in_ccy,
		in_funds_in_amt,
		in_bank_ccy,
		in_bank_amt,
		in_bank_bal,
		in_old_rate,
		in_new_rate,
		in_old_ratio,
		in_new_ratio,
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
end sp_funds_in_history_insert;
/
