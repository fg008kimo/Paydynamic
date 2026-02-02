CREATE OR REPLACE function sp_par_void_po_txn_data (
	out_cursor	out sys_refcursor
)
RETURN NUMBER IS
	iCnt	INTEGER := 0;
BEGIN

	select count(1)
	into iCnt
	from par_txn_data
	where ptd_txn_type = 'PAYOUT_CREDIT_ADJUSTMENT'
        and   ptd_proc_status = 'COMPLETE'
        and   ptd_po_psp_status is null;

	if (iCnt > 0) then
		OPEN out_cursor for
			select	ptd_txn_seq,
                                post_date,
                                txn_date,
                                ptd_txn_merch_nmb,
                                ptd_txn_nmb,
                                ptd_merch_ref,
                                ptd_txn_type,
                                ptd_txn_status,
                                ptd_txn_status_group,
                                to_ccy,
                                ptd_to_amount,
                                ccy,
                                ptd_amount,
                                ptd_fee,
                                ptd_ex_rate,
                                ptd_markup_amt,
                                ptd_psp_type_code,
                                ptd_order_id,
                                ptd_gate_id,
                                ptd_client_ip,
                                ptd_txn_note,
                                ptd_psp_txn_id,
                                ptd_psp_txn_date
			from (
			select  ptd_txn_seq,
				to_char(ptd_post_date, 'YYYYMMDDHH24MISS') post_date,
				to_char(ptd_txn_date, 'YYYYMMDDHH24MISS') txn_date,
				ptd_txn_merch_nmb,
				ptd_txn_nmb,
				ptd_merch_ref,
				ptd_txn_type,
				ptd_txn_status,
				ptd_txn_status_group,
				decode(ptd_to_ccy, 'RMB', 'CNY', ptd_to_ccy) to_ccy,
				ptd_to_amount,
				decode(ptd_ccy, 'RMB', 'CNY', ptd_ccy) ccy,
				ptd_amount,
				ptd_fee,
				ptd_ex_rate,
				ptd_markup_amt,
				--ptd_balance,
				ptd_psp_type_code,
				ptd_order_id,
				ptd_gate_id,
				ptd_client_ip,
                                ptd_txn_note,
                                ptd_psp_txn_id,
                                ptd_psp_txn_date
			from par_txn_data
			where ptd_txn_type = 'PAYOUT_CREDIT_ADJUSTMENT'
                          and ptd_proc_status = 'COMPLETE'
                          and ptd_po_psp_status is null
			order by ptd_txn_seq 
			--,
		        --		decode(ptd_txn_status_group, 'PENDING', 1, 'APPROVED', 2, 'DECLINED', 3, 'CANCELED', 4, 5)
			)
			where rownum <= 10
			;

		return 0;

	else 
		return 1;
	end if;

exception	
	when others then
		return 9;

END;
/
