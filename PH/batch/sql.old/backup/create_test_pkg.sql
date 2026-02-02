CREATE OR REPLACE PACKAGE TEST_PKG is

	TYPE   RPT_TXN_Detail_type is REF cursor return report_rpt_TXN_Detail_view%rowtype;


	function F_RPT_TXN_Detail(in_host_posting_date  in txn_header.th_host_posting_date%type,
				in_merchant_id          in txn_header.th_merchant_id%type,
				in_psp_id               in txn_psp_detail.tp_psp_id%type,
				in_client_id            in clients.client_id%type,
				out_cursor_txn_detail   in out RPT_TXN_DETAIL_TYPE
				
			) return NUMBER;


end TEST_PKG;
/


CREATE OR REPLACE PACKAGE BODY TEST_PKG is


function F_RPT_TXN_Detail(in_host_posting_date   in txn_header.th_host_posting_date%type,
			in_merchant_id           in txn_header.th_merchant_id%type,
			in_psp_id                in txn_psp_detail.tp_psp_id%type,
			in_client_id             in clients.client_id%type,
			out_cursor_txn_detail	 in out RPT_TXN_Detail_type
			) 
return NUMBER is
begin
	OPEN out_cursor_txn_detail FOR
		select th_txn_id,
			th_status,
			th_ar_ind,
			th_internal_code,
			th_response_code,
			th_merchant_id,
			th_merchant_ref,
			psp_name,
			tp_tid,
			tp_txn_ccy,
			th_transaction_amount,
			tp_service_fee,
			th_transmission_datetime,
			th_local_tm_date,
			th_local_tm_time,
			tp_txn_date,
			th_host_posting_date,
			tc_desc,
			th_txn_code,
			th_update_timestamp,
			client_name,
			tp_bank_bill_no
		from  txn_code,
			psp_detail,
			clients,
			txn_psp_detail,
			txn_detail,
			(select th_txn_id,
				th_status,
				th_ar_ind,
				th_internal_code,
				th_response_code,
				th_merchant_id,
				th_merchant_ref,
				th_transmission_datetime,
				th_local_tm_date,
				th_local_tm_time,
				th_host_posting_date,
				th_txn_code,
				th_update_timestamp,
				th_client_id,
				th_transaction_amount
			from txn_header
			where txn_header.th_host_posting_date = in_host_posting_date
			and TXN_HEADER.TH_AR_IND = 'A') txn_header
		where txn_header.th_txn_id = txn_detail.td_txn_id
		and   txn_header.th_txn_id = txn_psp_detail.tp_txn_id
		and   txn_header.th_txn_code = txn_code.tc_code
		and   psp_detail.psp_id = txn_psp_detail.tp_psp_id
		and   txn_header.th_client_id = clients.client_id
		and   TXN_HEADER.TH_MERCHANT_ID = NVL(in_merchant_id, TXN_HEADER.TH_MERCHANT_ID)
		and   TXN_PSP_DETAIL.TP_PSP_ID = NVL(in_psp_id, TXN_PSP_DETAIL.TP_PSP_ID)
		and   CLIENTS.CLIENT_ID = NVL(in_client_id, CLIENTS.CLIENT_ID)
		order by th_txn_id;

	return 0;
exception
	when others then
		return 9;

END;

end TEST_PKG;
/

