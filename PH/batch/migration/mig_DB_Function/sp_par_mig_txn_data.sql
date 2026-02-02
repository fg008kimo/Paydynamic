CREATE OR REPLACE function sp_par_mig_txn_data (
        v_file_date     in  VARCHAR2,
	i_process_id    in  par_mig_txn_data.mtd_process_id%type,
	out_cursor	out sys_refcursor
)
RETURN NUMBER IS
	iCnt	INTEGER := 0;
BEGIN

	select count(1)
	into iCnt
	from par_mig_txn_data
	where mtd_file_name = 'merchant_txn_' || v_file_date || '.csv'
          and (mtd_process_id = i_process_id or i_process_id = 0)
          and mtd_proc_status is null
          and mtd_po_psp_status is null;

	if (iCnt > 0) then
		OPEN out_cursor for
			select 	MTD_TXN_SEQ,
				POST_DATE,
				TXN_DATE,
				MTD_TXN_MERCH_NMB,
				MTD_TXN_NMB,
				MTD_MERCH_REF,
				MTD_TXN_TYPE,
				MTD_TXN_STATUS,
				MTD_TXN_STATUS_GROUP,
				TO_CCY,
				MTD_TO_AMOUNT ,
				CCY,
				MTD_AMOUNT,
				MTD_FEE,
				MTD_EX_RATE,
				MTD_MARKUP_AMT,
				MTD_PSP_TYPE_CODE,
				MTD_ORDER_ID,
				MTD_GATE_ID,
				MTD_CLIENT_IP,
				MTD_TXN_NOTE,
				MTD_PSP_TXN_ID,
				MTD_PSP_TXN_DATE,
				MTD_MOBILE_NMB,
                                MTD_USER_AGENT
			from (
			select  mtd_txn_seq,
				to_char(mtd_post_date, 'YYYYMMDDHH24MISS') post_date,
				to_char(mtd_txn_date, 'YYYYMMDDHH24MISS.FF6') txn_date,
				mtd_txn_merch_nmb,
				mtd_txn_nmb,
				mtd_merch_ref,
				mtd_txn_type,
				mtd_txn_status,
				mtd_txn_status_group,
				decode(mtd_to_ccy, 'RMB', 'CNY', mtd_to_ccy) to_ccy,
				mtd_to_amount,
				decode(mtd_ccy, 'RMB', 'CNY', mtd_ccy) ccy,
				mtd_amount,
				mtd_fee,
				mtd_ex_rate,
				mtd_markup_amt,
				mtd_psp_type_code,
				mtd_order_id,
				mtd_gate_id,
                                NVL(substr (mtd_client_ip, 0, instr(mtd_client_ip, ',') -1 ), mtd_client_ip)  mtd_client_ip,
                                mtd_txn_note,
                                trim(mtd_psp_txn_id) mtd_psp_txn_id,
                                mtd_psp_txn_date,
                               	mtd_mobile_nmb,
                                mtd_user_agent
			from par_mig_txn_data
			where mtd_proc_status is null
                          and mtd_po_psp_status is null
                          and (mtd_process_id = i_process_id or i_process_id = 0)
                          and mtd_file_name = 'merchant_txn_' || v_file_date || '.csv'
			order by mtd_txn_seq 
			)
			where rownum <= 10000 
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
