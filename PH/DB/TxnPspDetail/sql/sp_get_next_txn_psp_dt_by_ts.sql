CREATE OR REPLACE FUNCTION sp_get_next_txn_psp_dt_by_ts(
  in_psp_id             	txn_psp_detail.tp_psp_id%Type,
  in_ccy_id            		txn_psp_detail.tp_txn_ccy%Type,
  in_fr_datetime            	varchar2,
  in_to_datetime              	varchar2,
  out_cursor			out sys_refcursor)

RETURN NUMBER Is
        iCnt 	Integer := 0;
Begin

	if (in_to_datetime is null) then
		
		select 	count(*)
        	into 	iCnt
                from    txn_header,
                        txn_psp_detail
                where   th_txn_id = tp_txn_id
                and     tp_psp_id = in_psp_id
                and     tp_txn_ccy = in_ccy_id
                and     th_approval_timestamp is not null
                and     th_approval_timestamp > to_date(in_fr_datetime, 'YYYYMMDDHH24MISS')
                and     th_status = 'C'
                and     th_ar_ind = 'A';

		if iCnt > 0 then

			OPEN out_cursor FOR
			select  th_txn_id,
				th_txn_code,
                        	tp_bal,
                        	tp_total_float,
                        	tp_total_hold
                	from    txn_header,
                        	txn_psp_detail
                	where   th_txn_id = tp_txn_id
                	and     tp_psp_id = in_psp_id
                	and     tp_txn_ccy = in_ccy_id
                	and     th_approval_timestamp is not null
                	and     th_approval_timestamp > to_date(in_fr_datetime, 'YYYYMMDDHH24MISS')
                	and     th_status = 'C'
                	and     th_ar_ind = 'A'
                	order by th_approval_timestamp,
                         	 th_txn_id;
	
			RETURN 0;
			
		else
			
			RETURN 2;
		end if;

	else

		select  count(*)
                into    iCnt
                from    txn_header,
                        txn_psp_detail
                where   th_txn_id = tp_txn_id
                and     tp_psp_id = in_psp_id
                and     tp_txn_ccy = in_ccy_id
                and     th_approval_timestamp is not null
                and     th_approval_timestamp > to_date(in_fr_datetime, 'YYYYMMDDHH24MISS')
                and     th_approval_timestamp <= to_date(in_to_datetime, 'YYYYMMDDHH24MISS')
                and     th_status = 'C'
                and     th_ar_ind = 'A';

		if iCnt > 0 then

                        OPEN out_cursor FOR
			select  th_txn_id,
				th_txn_code,
                                tp_bal,
                                tp_total_float,
                                tp_total_hold
                        from    txn_header,
                                txn_psp_detail
                        where   th_txn_id = tp_txn_id
                        and     tp_psp_id = in_psp_id
                        and     tp_txn_ccy = in_ccy_id
                        and     th_approval_timestamp is not null
                	and     th_approval_timestamp > to_date(in_fr_datetime, 'YYYYMMDDHH24MISS')
                        and     th_approval_timestamp <= to_date(in_to_datetime, 'YYYYMMDDHH24MISS')
                        and     th_status = 'C'
                        and     th_ar_ind = 'A'
                        order by th_approval_timestamp,
                                 th_txn_id;

                        RETURN 0;

		else

			RETURN 2;
		end if;

	end if;	

exception
   WHEN OTHERS 
   THEN
     RETURN 9;
END sp_get_next_txn_psp_dt_by_ts;
/

