--DROP PACKAGE REPORT_PKG;

CREATE OR REPLACE PACKAGE REPORT_PKG is

	TYPE   RPT001_type is REF cursor return report_rpt001_view%rowtype;
	TYPE   RPT002_type is REF cursor return report_rpt002_view%rowtype;
	TYPE   RPT003_type is REF cursor return report_rpt003_view%rowtype;
	TYPE   RPT004_type is REF cursor return report_rpt004_view%rowtype;
	TYPE   RPT005_type is REF cursor return report_rpt005_view%rowtype;
	TYPE   RPT006_type is REF cursor return report_rpt006_view%rowtype;
	TYPE   RPT007_type is REF cursor return report_rpt007_view%rowtype;
	TYPE   RPT008_type is REF cursor return report_rpt008_view%rowtype;
	TYPE   RPT009_type is REF cursor return report_rpt009_view%rowtype;
	TYPE   RPT010_type is REF cursor return report_rpt010_view%rowtype;
	TYPE   RPT011_type is REF cursor return report_rpt011_view%rowtype;
	TYPE   RPT012_type is REF cursor return report_rpt011_view%rowtype;
	TYPE   RPT013_type is REF cursor return report_rpt013_view%rowtype;

	function F_RPT001(in_approval_date_from  txn_header.th_approval_timestamp%type,
                    in_approval_date_to  txn_header.th_approval_timestamp%type,
                    in_merchant_id   txn_header.th_merchant_id%type,
                    in_country       txn_detail.td_txn_country%type,
                    in_service_code  txn_header.th_service_code%type,
                    in_ccy           txn_detail.td_txn_ccy%type
                  ) return rpt001_tab;

	procedure open_cur_rpt001(
       	    in_host_posting_date in     txn_header.th_host_posting_date%type,
            in_merchant_id       in     txn_header.th_merchant_id%type,
            in_country           in     txn_detail.td_txn_country%type,
            in_service_code      in     txn_header.th_service_code%type,
            in_ccy               IN     txn_detail.td_txn_ccy%type,
            cursor_rpt001        IN OUT RPT001_type);
			

	function F_RPT002(
		in_host_posting_date	in	txn_header.th_host_posting_date%type,
		cursor_rpt002		IN OUT	RPT002_type
		) return number;

	function F_RPT003(
		in_host_posting_date	in	txn_header.th_host_posting_date%type,
		in_report_type		in	varchar2,
		cursor_rpt003		IN OUT	RPT003_type
		) return number;

	function F_RPT004(
		in_fr_host_posting_date	in	txn_header.th_host_posting_date%type,
		in_to_host_posting_date	in	txn_header.th_host_posting_date%type,
		cursor_rpt004		IN OUT	RPT004_type
		) return number;

	function F_RPT005(
		in_fr_host_posting_date	in	txn_header.th_host_posting_date%type,
		in_to_host_posting_date	in	txn_header.th_host_posting_date%type,
		cursor_rpt005		IN OUT	RPT005_type
		) return number;

	function F_RPT006(
		in_fr_host_posting_date	in	txn_header.th_host_posting_date%type,
		in_to_host_posting_date	in	txn_header.th_host_posting_date%type,
		cursor_rpt006		IN OUT	RPT006_type
		) return number;

	function F_RPT007(
		in_fr_host_posting_date	in	txn_header.th_host_posting_date%type,
		in_to_host_posting_date	in	txn_header.th_host_posting_date%type,
		cursor_rpt007		IN OUT	RPT007_type
		) return number;

	function F_RPT008(
		in_fr_host_posting_date	in	txn_header.th_host_posting_date%type,
		in_to_host_posting_date	in	txn_header.th_host_posting_date%type,
		cursor_rpt008		IN OUT	RPT008_type
		) return number;

	function F_RPT009(in_approval_date	txn_header.th_approval_timestamp%type
		) return rpt009_tab;

	procedure open_cur_rpt009(
       	    in_approval_date		in	txn_header.th_approval_date%type,
            cursor_rpt009        IN OUT RPT009_type);

	function F_RPT010(
		in_fr_host_posting_date	in	txn_header.th_host_posting_date%type,
		in_to_host_posting_date	in	txn_header.th_host_posting_date%type,
            	in_dc_ind		in	adjustment_type.at_dc_ind%type,
		cursor_rpt010		IN OUT	RPT010_type
		) return number;

	function F_RPT011(
		in_host_posting_date	in	txn_header.th_host_posting_date%type,
		cursor_rpt011		IN OUT	RPT011_type
		) return number;

	function F_RPT012(
		in_host_posting_date	in	txn_header.th_host_posting_date%type,
		cursor_rpt012		IN OUT	RPT012_type
		) return number;

	function F_RPT013(
		cursor_rpt013		IN OUT	RPT013_type
		) return number;

end REPORT_PKG;
/
--DROP PACKAGE BODY REPORT_PKG;

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



function F_RPT002(
	in_host_posting_date	in	txn_header.th_host_posting_date%type,
	cursor_rpt002		in out	RPT002_type)
return NUMBER is
begin
	open cursor_rpt002 for
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
			to_char(th_update_timestamp,'yyyymmddhh24miss') as th_update_timestamp,
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
		order by th_txn_id;

	return 0;	
exception
	when others then
		return 9;
END;



function F_RPT003(
	in_host_posting_date	in	txn_header.th_host_posting_date%type,
	in_report_type		in	varchar2,
	cursor_rpt003		in out	RPT003_type)
return NUMBER is

	v_fr_posting_date	txn_header.th_host_posting_date%type;
	v_to_posting_date	txn_header.th_host_posting_date%type;

begin
	if upper(in_report_type) = 'D' then
		v_fr_posting_date:=in_host_posting_date;
		v_to_posting_date:=in_host_posting_date;
	elsif upper(in_report_type) = 'W' then
		v_fr_posting_date:=to_char(to_date(in_host_posting_date,'yyyymmdd')-7+1, 'yyyymmdd');
		v_to_posting_date:=in_host_posting_date;
	elsif upper(in_report_type) = 'M' then
		--v_fr_posting_date:= to_char(trunc(trunc(to_date(in_host_posting_date, 'yyyyMMdd'),'MM')-1,'MM'), 'yyyymmdd');
		--v_to_posting_date:= to_char(trunc(to_date(in_host_posting_date, 'yyyyMMdd'),'MM')-1, 'yyyymmdd');
		v_fr_posting_date:= to_char(Last_Day(ADD_MONTHS(to_date(in_host_posting_date, 'yyyymmdd'),-2)) +1 , 'yyyymmdd');
		v_to_posting_date:= to_char(Last_Day(ADD_MONTHS(to_date(in_host_posting_date, 'yyyymmdd'),-1)) , 'yyyymmdd');
	end if;

	open cursor_rpt003 for
		select th_host_posting_date,
			tc_desc,
			sc_desc,
			psp_name,
			tp_txn_ccy,
			sum(tp_txn_amount) as total_transaction_amount,
			count(*) transaction_count,
			avg(tp_txn_amount) as average_transaction_amount
		from txn_psp_detail, 
			def_service_code,
			txn_code,
			psp_detail,
			(select th_host_posting_date, th_txn_id, th_service_code, th_txn_code
			from txn_header
			where th_host_posting_date >= v_fr_posting_date
			and th_host_posting_date <= v_to_posting_date
			and th_ar_ind= 'A'
			and th_txn_code in ('DSI', 'DSP', 'VDS'))
		where th_txn_id= tp_txn_id 
		and sc_code = th_service_code
		and tc_code = th_txn_code
		and psp_id = tp_psp_id
		group by th_host_posting_date, tc_desc, sc_desc, psp_name, tp_txn_ccy
		order by th_host_posting_date, tc_desc, sc_desc, psp_name, tp_txn_ccy;

	return 0;	
exception
	when others then
		return 9;
END;


function F_RPT004(
	in_fr_host_posting_date	in	txn_header.th_host_posting_date%type,
	in_to_host_posting_date	in	txn_header.th_host_posting_date%type,
	cursor_rpt004		IN OUT	RPT004_type)
return NUMBER is
begin
	open cursor_rpt004 for
		select th_merchant_id,
			name,
			sc_desc,
			te_ccy,
			te_amt_type,
			sum(te_amount) as total_amount
		from def_service_code,
			merch_detail,
			txn_elements,  
			(select th_txn_id, th_merchant_id, th_service_code
			from txn_header
			where th_host_posting_date >= in_fr_host_posting_date
			and th_host_posting_date <= in_to_host_posting_date
			and th_ar_ind = 'A')
		where te_txn_id = th_txn_id 
		and te_txn_element_type = 'TFEE'
		and te_party_type = 'M' 
		and merchant_id = th_merchant_id
		and sc_code = th_service_code  
		group by th_merchant_id, name, sc_desc, te_ccy, te_amt_type
		order by th_merchant_id, name, sc_desc, te_ccy, te_amt_type;

	return 0;	
exception
	when others then
		return 9;
END;


function F_RPT005(
	in_fr_host_posting_date	in	txn_header.th_host_posting_date%type,
	in_to_host_posting_date	in	txn_header.th_host_posting_date%type,
	cursor_rpt005		IN OUT	RPT005_type)
return NUMBER is
begin
	open cursor_rpt005 for
		select tc_desc,
			dm_status_desc,
			count(*) as transaction_count,
			te_amt_type,
			te_ccy,
			sum(te_amount) as markup_amount
		from txn_code,
			def_txn_status_map,
			(select te_txn_id,
				te_amt_type,
				te_ccy,
				te_amount,
				th_status,
				th_txn_code
				from txn_elements, 
					(select th_txn_id, th_txn_code, th_status
					from txn_header
					where th_host_posting_date >= in_fr_host_posting_date
					and th_host_posting_date <= in_to_host_posting_date
					and th_ar_ind = 'A')
			where te_txn_element_type = 'MAMT'
			and te_party_type = 'R' 
			and te_txn_id = th_txn_id)
		where tc_code = th_txn_code
		and dm_type = 'A'
		and dm_status = th_status
		and dm_ar_ind = 'A'
		and dm_txn_code= th_txn_code     
		group by tc_desc, dm_status_desc, te_amt_type, te_ccy
		order by tc_desc, dm_status_desc, te_amt_type, te_ccy;

	return 0;	
exception
	when others then
		return 9;
END;


function F_RPT006(
	in_fr_host_posting_date	in	txn_header.th_host_posting_date%type,
	in_to_host_posting_date	in	txn_header.th_host_posting_date%type,
	cursor_rpt006		IN OUT	RPT006_type)
return NUMBER is
begin
	open cursor_rpt006 for
		select count(*),
			memeber_amt_type, member_ccy, sum(member_amount),
			merchant_amt_type, merchant_ccy, sum(merchant_amount)
		from 
			(select txn_header.th_txn_id,
				b.te_amount as merchant_amount,
				b.te_ccy as merchant_ccy,
				b.te_amt_type as merchant_amt_type,
				c.te_amount as member_amount,
				c.te_ccy as member_ccy,
				c.te_amt_type as memeber_amt_type
			from  (select a.th_txn_id
				from txn_header a
				where a.th_host_posting_date >= in_fr_host_posting_date
				and a.th_txn_code = 'POU'
				and a.th_host_posting_date <= in_to_host_posting_date
				and a.th_ar_ind = 'A') txn_header
			left join txn_elements b
			on b.te_txn_id = txn_header.th_txn_id
			and b.te_txn_element_type = 'TFEE'
			and B.TE_PARTY_TYPE = 'M'
			left join txn_elements c
			on c.te_txn_id = txn_header.th_txn_id
			and c.te_txn_element_type = 'TFEE'
			and c.te_party_type = 'R'
			)
		where (merchant_amount is not null or member_amount is not null)
		group by  member_ccy, memeber_amt_type, merchant_ccy, merchant_amt_type
		order by  member_ccy, memeber_amt_type, merchant_ccy, merchant_amt_type;

	return 0;	
exception
	when others then
		return 9;
END;


function F_RPT007(
	in_fr_host_posting_date	in	txn_header.th_host_posting_date%type,
	in_to_host_posting_date	in	txn_header.th_host_posting_date%type,
	cursor_rpt007		IN OUT	RPT007_type)
return NUMBER is
begin
	open cursor_rpt007 for
		select to_char(th_create_timestamp, 'YYYYMMDD HH24MISS') as create_timestamp,
			to_char(th_update_timestamp, 'YYYYMMDD HH24MISS') as update_timestamp, 
			to_char(th_approval_timestamp, 'YYYYMMDD HH24MISS') as approval_timestamp,
			th_txn_id,
			psp_name,
			th_merchant_ref,
			th_merchant_id,
			name as merchant_name,
			dm_status_desc,
			ds_name as sub_status_desc,
			tp_txn_amount,
			tp_txn_ccy,
			th_net_amount,
			th_ex_rate,
			fee,
			fee_ccy,
			th_transaction_amount,
			td_txn_ccy
		from def_sub_status,
			def_txn_status_map,
			merch_detail,
			psp_detail,
			txn_psp_detail, 
			txn_detail,
			(select th_create_timestamp, th_update_timestamp, th_approval_timestamp,
				th_txn_id,  th_merchant_ref, th_merchant_id, th_status, th_ar_ind,
				th_sub_status, th_transaction_amount, th_net_amount, th_ex_rate,
				NVL(te_amount, 0) as fee, te_ccy as fee_ccy, th_txn_code
			from (select  th_create_timestamp, th_update_timestamp, th_approval_timestamp,
					th_txn_id,  th_merchant_ref, th_merchant_id, th_status, th_ar_ind,
					th_sub_status, th_transaction_amount, th_net_amount, th_ex_rate,
					th_txn_code
				from txn_header
				where th_host_posting_date >= in_fr_host_posting_date
				and th_host_posting_date <= in_to_host_posting_date
				and th_txn_code in ('DSI', 'DSP')) txn_header
			left join txn_elements
			on te_txn_id = th_txn_id
			and TE_TXN_ELEMENT_TYPE = 'TFEE'
			and te_party_type = 'M')
		where tp_txn_id = th_txn_id
		and th_txn_id = td_txn_id
		and tp_psp_id = psp_id
		and th_merchant_id = merchant_id
		and dm_type = 'A'
		and th_txn_code = dm_txn_code
		and th_status = dm_status
		and NVL(th_ar_ind, ' ') = dm_ar_ind
		and th_sub_status = ds_sub_status;

	return 0;	
exception
	when others then
		return 9;
END;


function F_RPT008(
	in_fr_host_posting_date	in	txn_header.th_host_posting_date%type,
	in_to_host_posting_date	in	txn_header.th_host_posting_date%type,
	cursor_rpt008		IN OUT	RPT008_type)
return NUMBER is
begin
	open cursor_rpt008 for
		select to_char(th_create_timestamp, 'YYYYMMDD HH24MISS') as create_timestamp,
			to_char(th_update_timestamp, 'YYYYMMDD HH24MISS') as update_timestamp, 
			to_char(th_approval_timestamp, 'YYYYMMDD HH24MISS') as approval_timestamp,
			th_txn_id,
			th_merchant_ref,
			tc_desc,
			th_merchant_id,
			name as merchant_name,
			dm_status_desc,
			ds_name as sub_status_desc,
			tp_txn_amount,
			tp_txn_ccy,
			th_net_amount,
			th_ex_rate,
			fee,
			fee_ccy,
			th_transaction_amount,
			td_txn_ccy
		from def_sub_status,
			def_txn_status_map,
			merch_detail,
			txn_detail,
			(select th_create_timestamp, th_update_timestamp, th_approval_timestamp,
				th_txn_id,  th_merchant_ref, th_merchant_id, th_status, th_ar_ind,
				th_sub_status, th_transaction_amount, th_net_amount, th_ex_rate,
				NVL(te_amount, 0) as fee, te_ccy as fee_ccy, th_txn_code,
				tp_txn_amount, tp_txn_ccy, tc_desc
			from (select  th_create_timestamp, th_update_timestamp, th_approval_timestamp,
					th_txn_id,  th_merchant_ref, th_merchant_id, th_status, th_ar_ind,
					th_sub_status, th_transaction_amount, th_net_amount, th_ex_rate,
					th_txn_code, tc_desc
				from txn_header, txn_code
				where th_host_posting_date >= in_fr_host_posting_date
				and th_host_posting_date <= in_to_host_posting_date
				and tc_code = th_txn_code
				and tc_fe_display = 1 ) txn_header
			left join txn_elements
			on te_txn_id = th_txn_id
			and TE_TXN_ELEMENT_TYPE = 'TFEE'
			and te_party_type = 'M'
			left join txn_psp_detail
			on tp_txn_id = th_txn_id)
		where th_txn_id = td_txn_id
		and th_merchant_id = merchant_id
		and dm_type = 'A'
		and th_txn_code = dm_txn_code
		and th_status = dm_status
		and NVL(th_ar_ind, ' ') = dm_ar_ind
		and th_sub_status = ds_sub_status;

	return 0;	
exception
	when others then
		return 9;
END;


function F_RPT009(in_approval_date	txn_header.th_approval_timestamp%type
		) return rpt009_tab is
	Result rpt009_tab := rpt009_tab();
  	n integer := 0;

	v_merchant_id		merch_detail.merchant_id%type;
	v_merchant_name		merch_detail.name%type;
	v_service_desc		def_service_code.sc_desc%type;
	v_status		def_status.ds_desc%type;
	v_ccy			merchant_bal_acct.mb_ccy_id%type;
	v_service_code		merchant_bal_acct.mb_service_code%type; 

	v_current_bal		txn_detail.td_current_bal%type;
	v_total_float		txn_detail.td_total_float%type;
	v_total_reserve_amount	txn_detail.td_total_reserved_amount%type;
	v_total_hold		txn_detail.td_total_hold%type;
	v_settlement_in_transit	txn_detail.td_settlement_in_transit%type;
	v_approval_date         txn_header.th_approval_timestamp%type;

	cursor cur_merch_acc is
		select  merchant_id,
                        name as merchant_name,
                        sc_desc as service_desc,
                        ds_desc as status,
                        mb_service_code,
                        mb_ccy_id as currency
                from    def_service_code,
                        def_status,
                        merch_detail,
                        merchant_bal_acct
                where merchant_id = mb_merchant_id
                and mb_status = ds_type
                and sc_code = mb_service_code
                order by merchant_id, mb_service_code, mb_ccy_id;

begin
	open cur_merch_acc;
	loop
		fetch  cur_merch_acc
			into  v_merchant_id, v_merchant_name, v_service_desc, v_status, v_service_code, v_ccy;  
		exit when cur_merch_acc%NOTFOUND;

		begin
			select  th_approval_timestamp,
                    		td_current_bal,
                        	td_total_float,
                        	td_total_reserved_amount,
                        	td_total_hold,
                        	td_settlement_in_transit
                	into    v_approval_date,
                        	v_current_bal,
                        	v_total_float,
                        	v_total_reserve_amount,
                        	v_total_hold,
                        	v_settlement_in_transit
                	from  txn_detail, txn_header
                	where th_merchant_id = v_merchant_id
                	and   th_ar_ind = 'A'
                	and   th_approval_timestamp = ( select max(th_approval_timestamp)
                       	                        	from txn_detail, txn_header
                                                	where th_merchant_id = v_merchant_id
                                                	and th_txn_id = td_txn_id
                                                	and td_txn_ccy = v_ccy
                                                	and th_ar_ind = 'A'
                                                	and th_service_code = v_service_code
                                                	and th_approval_timestamp < in_approval_date+1)
                	and td_txn_id = th_txn_id;
        	exception
                	when no_data_found then
                        	v_approval_date := null;
                        	v_current_bal := 0;
                        	v_total_float := 0;
                        	v_total_reserve_amount := 0;
                        	v_total_hold  := 0;
                        	v_settlement_in_transit:= 0;
        	end;

		Result.extend;
		n := n +1;

		result(n) := RPT009_OBj(v_merchant_id,
					v_merchant_name,
					v_service_desc,
					v_approval_date,
					v_current_bal,
					v_total_float,
					v_total_reserve_amount,
					v_total_hold,
					v_settlement_in_transit,
					v_ccy,
					v_status);
	end loop;
	close cur_merch_acc;

  	return(Result);
      
END;


procedure open_cur_rpt009(
          in_approval_date in     txn_header.th_approval_date%type,
          cursor_rpt009        IN OUT RPT009_type) is
	BEGIN
  		OPEN cursor_rpt009 For
     		select  * from table(report_pkg.F_rpt009(to_date(in_approval_date,'yyyymmdd')));

END open_cur_rpt009;


function F_RPT010(
	in_fr_host_posting_date	in	txn_header.th_host_posting_date%type,
	in_to_host_posting_date	in	txn_header.th_host_posting_date%type,
       	in_dc_ind		in	adjustment_type.at_dc_ind%type,
	cursor_rpt010		IN OUT	RPT010_type)
return NUMBER is
begin
	open cursor_rpt010 for
		select  to_char(th_approval_timestamp, 'YYYYMMDD HH24MISS') as approval_timestamp,
			th_txn_id,
			th_merchant_id,
			name as merchant_name,
			at_desc as transaction_type,
			dm_status_desc,
			ds_name as sub_status_desc,
			th_transaction_amount,
			td_txn_ccy,
			te_amount,
			te_ccy
		from 
			def_sub_status,
			def_txn_status_map,
			merch_detail,
			txn_detail,
			(select th_txn_id, th_merchant_id, th_txn_code, th_status,
				th_ar_ind, th_sub_status, th_transaction_amount,
				th_approval_timestamp, at_desc,  te_ccy, te_amount
			from ( select  th_txn_id, th_merchant_id, th_txn_code, th_status,
					th_ar_ind, th_sub_status, th_transaction_amount,
					th_approval_timestamp, at_desc
				from adjustment_type, txn_header
				where th_host_posting_date >= in_fr_host_posting_date
				and th_host_posting_date <= in_to_host_posting_date
				and th_ar_ind = 'A'
				and th_txn_code = at_code
				and at_party_type = 'M'
				and at_dc_ind = in_dc_ind )
			left join txn_elements
			on te_txn_id = th_txn_id
			and te_txn_element_type = 'TFEE'
			and te_party_type = 'M')                                               
		where dm_type ='A'
		and  dm_status = th_status
		and dm_ar_ind = NVL(th_ar_ind, ' ')
		and dm_txn_code = th_txn_code
		and ds_sub_status =  th_sub_status
		and td_txn_id = th_txn_id
		and merchant_id = th_merchant_id;

	return 0;	
exception
	when others then
		return 9;
END;


function F_RPT011(
	in_host_posting_date	in	txn_header.th_host_posting_date%type,
	cursor_rpt011		IN OUT	RPT011_type)
return NUMBER is
begin
	open cursor_rpt011 for
		select  th_txn_id,
			th_txn_code,
			tc_desc,
			tp_txn_date,
			tp_psp_id,
			psp_name,
			tp_txn_ccy,
			tp_txn_amount,
			tp_service_fee
		from txn_code, psp_detail,
			(select th_txn_id, th_txn_code,
				tp_txn_date, tp_psp_id,
				tp_txn_ccy, tp_txn_amount,
				tp_service_fee
			from txn_psp_detail, txn_header
			where th_txn_code in ('DSI', 'DSP')
			and th_ar_ind = 'A'
			and th_txn_id = tp_txn_id
			and tp_txn_date = in_host_posting_date
			and nvl(tp_service_fee, 0 ) > 0 )
		where psp_id = tp_psp_id
		and tc_code = th_txn_code;

	return 0;	
exception
	when others then
		return 9;
END;


function F_RPT012(
	in_host_posting_date	in	txn_header.th_host_posting_date%type,
	cursor_rpt012		IN OUT	RPT012_type)
return NUMBER is
begin
	open cursor_rpt012 for
		select  th_txn_id,
			th_txn_code,
			tc_desc,
			tp_txn_date,
			tp_psp_id,
			psp_name,
			tp_txn_ccy,
			tp_txn_amount,
			tp_service_fee
		from txn_code, psp_detail,
			(select th_txn_id, th_txn_code,
				tp_txn_date, tp_psp_id,
				tp_txn_ccy, tp_txn_amount,
				tp_service_fee
			from txn_psp_detail, txn_header
			where th_txn_code in ('POG')
			and th_ar_ind = 'A'
			and th_txn_id = tp_txn_id
			and tp_txn_date = in_host_posting_date
			and nvl(tp_service_fee, 0 ) > 0 )
		where psp_id = tp_psp_id
		and tc_code = th_txn_code;

	return 0;	
exception
	when others then
		return 9;
END;


function F_RPT013(
	cursor_rpt013		IN OUT	RPT013_type)
return NUMBER is
begin
	open cursor_rpt013 for
		select  tc_desc,
			th_service_code,
			sc_desc,
			dm_status_desc,
			sum(txn_count) as transaction_count
		from   def_service_code,
			def_txn_status_map,
			(select tc_desc, th_txn_code, th_service_code,
				th_status, th_ar_ind, th_sub_status,
				count(*) as txn_count
			from txn_code, txn_header
			where th_update_timestamp > sysdate -1
			and th_update_timestamp <= sysdate
			and th_txn_code = tc_code
			and tc_fe_display = 1
			group by tc_desc,  th_txn_code, th_service_code,
				th_status, th_ar_ind, th_sub_status)
		where dm_type = 'A'
		and dm_status = th_status
		and dm_ar_ind = NVL(th_ar_ind, ' ')
		and dm_txn_code = th_txn_code
		and sc_code = th_service_code
		group by tc_desc, th_service_code,sc_desc,  dm_status_desc
		order by tc_desc, th_service_code,sc_desc,  dm_status_desc;

	return 0;	
exception
	when others then
		return 9;
END;


end REPORT_PKG;
/
