update par_txn_data
set ptd_proc_status = 'NEW-SKIP'
where ptd_txn_status = 'NEW'
and ptd_proc_status is null ;

/*
declare
	cursor c1 is    
		select ptd_txn_seq
		from par_txn_data
		where ptd_txn_status = 'NEW'
		and ptd_proc_status is null ;     
    
begin
	for i in c1 loop
    
		update par_txn_data
		set ptd_proc_status = 'NEW-SKIP'
		where ptd_txn_seq = i.ptd_txn_seq;
	end loop;
end;
/

*/
