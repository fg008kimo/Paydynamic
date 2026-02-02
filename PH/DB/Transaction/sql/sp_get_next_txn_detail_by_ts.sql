CREATE OR REPLACE FUNCTION sp_get_next_txn_detail_by_ts(
  in_merchant_id             	txn_header.th_merchant_id%Type,
  in_country_id            	txn_detail.td_txn_country%Type,
  in_ccy_id            		txn_detail.td_txn_ccy%Type,
  in_service_code            	txn_header.th_service_code%Type,
  in_fr_datetime            	varchar2,
  in_to_datetime              	varchar2,
  out_cursor			out sys_refcursor)

RETURN NUMBER Is
        iCnt 	Integer := 0;
Begin

	if (in_to_datetime is null) then
		
		select 	count(*)
        	into 	iCnt
        	from 	txn_header,
	     		txn_detail
                where   th_txn_id = td_txn_id
                and     th_merchant_id = in_merchant_id
                and     td_txn_country = in_country_id
                and     td_txn_ccy = in_ccy_id
                and     th_service_code = in_service_code
                and     th_approval_timestamp is not null
                and     th_approval_timestamp > to_date(in_fr_datetime, 'YYYYMMDDHH24MISS')
                and     th_status = 'C'
                and     th_ar_ind = 'A';

		if iCnt > 0 then

			OPEN out_cursor FOR
               		select	th_txn_id,
				th_txn_code,
                        	th_transaction_amount,
                        	th_net_amount,
                        	th_reserve_amount,
                        	td_open_bal,
                        	td_current_bal,
                        	td_total_float,
                        	td_total_reserved_amount,
                        	td_total_hold,
                        	td_fundin_payout,
                        	td_reserved_payout,
                        	td_total_float_after_payout,
                        	td_open_bal_settlement,
                        	td_current_bal_settlement,
                        	td_total_float_settlement,
                        	td_total_hold_settlement 
                	from    txn_header,
                        	txn_detail
                	where   th_txn_id = td_txn_id
                	and     th_merchant_id = in_merchant_id
                	and     td_txn_country = in_country_id
                	and     td_txn_ccy = in_ccy_id
                	and     th_service_code = in_service_code
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
                        txn_detail
                where   th_txn_id = td_txn_id
                and     th_merchant_id = in_merchant_id
                and     td_txn_country = in_country_id
                and     td_txn_ccy = in_ccy_id
                and     th_service_code = in_service_code
                and     th_approval_timestamp is not null
		and	th_approval_timestamp > to_date(in_fr_datetime, 'YYYYMMDDHH24MISS')
                and     th_approval_timestamp <= to_date(in_to_datetime, 'YYYYMMDDHH24MISS')
                and     th_status = 'C'
                and     th_ar_ind = 'A';		

		if iCnt > 0 then

                        OPEN out_cursor FOR
                        select  th_txn_id,
				th_txn_code,
                                th_transaction_amount,
                                th_net_amount,
                                th_reserve_amount,
                                td_open_bal,
                                td_current_bal,
                                td_total_float,
                                td_total_reserved_amount,
                                td_total_hold,
                                td_fundin_payout,
                                td_reserved_payout,
                                td_total_float_after_payout,
                                td_open_bal_settlement,
                                td_current_bal_settlement,
                                td_total_float_settlement,
                                td_total_hold_settlement
                        from    txn_header,
                                txn_detail
                        where   th_txn_id = td_txn_id
                        and     th_merchant_id = in_merchant_id
                        and     td_txn_country = in_country_id
                        and     td_txn_ccy = in_ccy_id
                        and     th_service_code = in_service_code
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
END sp_get_next_txn_detail_by_ts;
/

