DROP PACKAGE BODY REPORT_PKG;

CREATE OR REPLACE PACKAGE BODY REPORT_PKG is

function F_RPT001(in_approval_date_from  txn_header.th_approval_timestamp%type,
                    in_approval_date_to  txn_header.th_approval_timestamp%type,
        	          in_merchant_id   txn_header.th_merchant_id%type,
                    in_country       txn_detail.td_txn_country%type,
                    in_service_code  txn_header.th_service_code%type,
                    in_ccy           txn_detail.td_txn_ccy%type
               		) return rpt001_tab is
	Result rpt001_tab := rpt001_tab();
  	n integer := 0;
  	dBal number := 0.0;
  	dOpeningBal number := 0.0;
  	lTxnId txn_header.th_txn_id%type;

  	v_txn_id                txn_header.th_txn_id%type;
        v_merchant_ref		txn_header.th_merchant_ref%type;
  	v_txn_code              txn_header.th_txn_code%type;
  	v_txn_code_desc         txn_code.tc_desc%type;
  	v_open_bal              txn_elements.te_amount%type;
  	v_current_bal           txn_elements.te_amount%type;
  	v_txn_element_type      txn_elements.te_txn_element_type%type;
  	v_txn_element_type_desc def_element_type.dt_desc%type;
  	v_exec_seq              txn_elements.te_exec_seq%type;
  	v_amount                txn_elements.te_amount%type;
  	v_ccy                   txn_elements.te_ccy%type;
  	v_amt_type              txn_elements.te_amt_type%type;
    v_approval_date         txn_header.th_approval_timestamp%type;


	CURSOR rpt001_cur is
    	select te_txn_id,
       th_merchant_ref,
       th_txn_code,
       tc_desc,
       nvl(td_open_bal, 0),
       td_current_bal,
       te_txn_element_type,
       dt_desc,
       te_exec_seq,
       te_amount,
       te_ccy,
       te_amt_type,
       th_approval_timestamp
  from txn_detail,
       (select /*+ LEADING (TXN_ELEMENTS) */ te_txn_id,
	       th_merchant_ref,
               te_txn_element_type,
               dt_desc,
               te_exec_seq,
               te_amount,
               te_ccy,
               te_amt_type,
               th_txn_code,
               tc_desc,
               th_approval_timestamp
          from txn_elements,
               (select th_txn_id,
                       th_txn_code,
                       th_approval_timestamp,
		       th_merchant_ref
                  from txn_header
                 where th_approval_timestamp >= in_approval_date_from
                   and th_approval_timestamp < in_approval_date_to
                   and th_merchant_id = in_merchant_id
                   and th_ar_ind = 'A'
                   and th_service_code = in_service_code) txn_header,
               def_element_type,
               txn_code
         where te_txn_element_type in ('TAMT', 'TFEE')
           and te_party_type = 'M'
           and te_ccy = in_ccy
           and te_txn_id = th_txn_id
           and te_txn_element_type = dt_type
           and th_txn_code = tc_code)
 where td_txn_id = te_txn_id
   and td_txn_country = in_country
 order by th_approval_timestamp, te_exec_seq;

	begin

  		OPEN rpt001_cur;
  		loop
    			FETCH rpt001_cur INTO
        		v_txn_id,
                        v_merchant_ref,
        		v_txn_code,
        		v_txn_code_desc,
        		v_open_bal,
        		v_current_bal,
        		v_txn_element_type,
        		v_txn_element_type_desc,
        		v_exec_seq,
        		v_amount,
        		v_ccy,
        		v_amt_type,
            v_approval_date;
    		EXIT WHEN rpt001_cur%NOTFOUND;

    		if (n = 0) then
      			lTxnId := v_txn_id;
      			dBal := v_open_bal;
    		end if;

    		if (lTxnId != v_txn_id) then
    			dBal := v_open_bal;
    		end if;
    		dOpeningBal := dBal;

    		if (v_amt_type = 'DR') then
      			dBal := dBal - v_amount;
    		else
      			dBal := dBal + v_amount;
    		end if;

    		Result.extend;
    		n := n +1;

    		result(n) := RPT001_OBj(v_txn_id,
			 v_merchant_ref,
                         v_txn_code,
                         v_txn_code_desc,
                         dOpeningBal,
                         v_current_bal,
                         v_txn_element_type,
                         v_txn_element_type_desc,
                         v_exec_seq,
                         v_amount,
                         v_ccy,
                         v_amt_type,
                         dBal,
                         v_approval_date);
    		lTxnId := v_txn_id;
  	end loop;
  	CLOSE rpt001_cur;
  	return(Result);
END;

procedure open_cur_rpt001(
          in_host_posting_date in     txn_header.th_host_posting_date%type,
          in_merchant_id       in     txn_header.th_merchant_id%type,
          in_country           in     txn_detail.td_txn_country%type,
          in_service_code      in     txn_header.th_service_code%type,
          in_ccy               IN     txn_detail.td_txn_ccy%type,
          cursor_rpt001        IN OUT RPT001_type) is
	BEGIN
  		OPEN cursor_rpt001 For
     		select  * from table(report_pkg.F_rpt001(to_date(in_host_posting_date,'yyyymmdd'),to_date(in_host_posting_date,'yyyymmdd') + 1,in_merchant_id,in_country,in_service_code,in_ccy));

END open_cur_rpt001;

function F_RPT002(in_host_posting_date  txn_header.th_host_posting_date%type
               	  ) return rpt002_tab is
	Result rpt002_tab := rpt002_tab();
	n integer := 0;
	
	v_txn_id             txn_header.th_txn_id%type;
    v_status             txn_header.th_status%type;
    v_ar_ind             txn_header.th_ar_ind%type;
    v_internal_code      txn_header.th_internal_code%type;
    v_response_code      txn_header.th_response_code%type;
    v_merchant_id        txn_header.th_merchant_id%type;
    v_merchant_ref       txn_header.th_merchant_ref%type;
    v_psp_name           psp_detail.psp_name%type;
    v_tid                txn_psp_detail.tp_tid%type;
    v_txn_ccy            txn_psp_detail.tp_txn_ccy%type;
    v_txn_amount         txn_header.th_transaction_amount%type;
    v_service_fee        txn_psp_detail.tp_service_fee%type;
    v_merchant_txn_date  txn_header.th_transmission_datetime%type;
    v_local_txn_date     txn_header.th_local_tm_date%type;
    v_local_txn_time     txn_header.th_local_tm_time%type;
    v_psp_txn_date       txn_psp_detail.tp_txn_date%type;
    v_host_posting_date  txn_header.th_host_posting_date%type;
    v_txn_code_desc      txn_code.tc_desc%type;
    v_txn_code           txn_header.th_txn_code%type;
    v_client_name        clients.client_name%type;
    v_last_updatetime    varchar2(20);
    v_bill_no            txn_psp_detail.tp_bank_bill_no%type;

	
    CURSOR rpt002_cur is
    select  th_txn_id,
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
            to_char(th_update_timestamp,'yyyymmddhh24miss'),
            client_name,
            tp_bank_bill_no
    from  txn_header,
          txn_detail,
          txn_psp_detail,
          txn_code,
          psp_detail,
          clients
    where  txn_header.th_txn_id = txn_detail.td_txn_id
    and txn_header.th_txn_id = txn_psp_detail.tp_txn_id
    and txn_header.th_host_posting_date = in_host_posting_date
    and txn_header.th_txn_code = txn_code.tc_code
    and psp_detail.psp_id = txn_psp_detail.tp_psp_id
    and txn_header.th_client_id = clients.client_id

    order by th_txn_id;
	
begin
    OPEN rpt002_cur;
        loop
		    FETCH rpt002_cur INTO             
                v_txn_id,
                v_status,
                v_ar_ind,
                v_internal_code,
                v_response_code,
                v_merchant_id,
                v_merchant_ref,
                v_psp_name,
                v_tid,
                v_txn_ccy,
                v_txn_amount,
                v_service_fee,
                v_merchant_txn_date,
                v_local_txn_date,
                v_local_txn_time,
                v_psp_txn_date,
                v_host_posting_date,
                v_txn_code_desc,
                v_txn_code,
                v_last_updatetime,
                v_client_name,
                v_bill_no;
            EXIT WHEN rpt002_cur%NOTFOUND;
    		

    		Result.extend;
    		n := n +1;
			
			result(n) := RPT002_OBj(v_txn_id,
                                    v_status,
                                    v_ar_ind,
                                    v_internal_code,
                                    v_response_code,
                                    v_merchant_id,
                                    v_merchant_ref,
                                    v_psp_name,
                                    v_tid,
                                    v_txn_ccy,
                                    v_txn_amount,
                                    v_service_fee,
                                    v_merchant_txn_date,
                                    v_local_txn_date,
                                    v_local_txn_time,
                                    v_psp_txn_date,
                                    v_host_posting_date,
                                    v_txn_code_desc,
                                    v_txn_code,
                                    v_last_updatetime,
                                    v_client_name,
                                    v_bill_no);

        end loop;		
	CLOSE rpt002_cur;
  	return(Result);
END;

procedure open_cur_rpt002(
          in_host_posting_date IN     txn_header.th_host_posting_date%type,
          cursor_rpt002        IN OUT RPT002_type) is
	BEGIN
  		OPEN cursor_rpt002 For
     		select  * from table(report_pkg.F_rpt002(in_host_posting_date));

END open_cur_rpt002;
end REPORT_PKG;
/
