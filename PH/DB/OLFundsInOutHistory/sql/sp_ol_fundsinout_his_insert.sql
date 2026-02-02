create or replace function sp_ol_fundsinout_his_insert(
       in_txn_id		ol_funds_in_out_history.ofh_txn_id%type)
  RETURN NUMBER IS
	iCnt  INTEGER := 0;
	iRet  INTEGER := 0;
begin

  select count(transaction_id)
  into iCnt
  from funds_inout_history_view_old
  where transaction_id = in_txn_id;

  if iCnt > 0 then

	declare
    		cursor c1 is
		select
        		txn_date,
			from_ccy,
			from_amt,
			bank_ccy,
			bank_amt,
			old_rate,
			new_rate,
			bank_bal,
			transaction_type,
			type,
			transaction_id,
			time
     		from  funds_inout_history_view_old
     		where transaction_id = in_txn_id; 
     
	begin
    	for i in c1 loop
    		insert into
    		ol_funds_in_out_history
        		(ofh_txn_date,
			 ofh_from_ccy,
			 ofh_from_amt,
			 ofh_bank_ccy,
			 ofh_bank_amt,
			 ofh_old_rate,
			 ofh_new_rate,
			 ofh_bank_bal,
			 ofh_txn_type,
			 ofh_fund_type,
			 ofh_txn_id,
			 ofh_time)
         
    		values
		(
		 i.txn_date,
		 i.from_ccy,
		 i.from_amt,
		 i.bank_ccy,
		 i.bank_amt,
		 i.old_rate,
		 i.new_rate,
		 i.bank_bal,
		 i.transaction_type,
		 i.type,
		 i.transaction_id,
		 i.time
		);

		IF SQL%ROWCOUNT > 0 THEN
			iRet := iRet+1;
		end if;
	end loop;
	end;


  	IF iRet > 0 THEN
    	  RETURN 0;
  	ELSE
   	  RETURN 1;
  	END IF;

    else
    return 1;
    end if;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_ol_fundsinout_his_insert;
/
