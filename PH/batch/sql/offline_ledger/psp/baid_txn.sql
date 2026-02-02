CREATE OR REPLACE FUNCTION baid_txn (
     in_approval_date_from    ol_txn_header.oth_approval_timestamp%TYPE,
     in_approval_date_to      ol_txn_header.oth_approval_timestamp%TYPE,
     in_psp_id                ol_txn_psp_detail.otp_psp_id%TYPE,
     in_baid                  OL_BANK_ACCT_ID.OBAI_BAID%type,
     in_ccy                   ol_txn_elements.ote_ccy%TYPE,
     in_ele                   varchar2)
     RETURN sys_refcursor
  IS
  sql_stmt varchar2(4000);
  bal_stmt varchar2(2000);
  in_ele_type varchar2(1000);
  open_bal_str varchar2(100);
  open_bal_chk varchar2(100);
  sql_cur sys_refcursor;
  dbal number;

  begin
  if in_ele='A' then
     in_ele_type :='''TAMT'',''TFEE'',''TRNF'',''RAMT'',''UAMT'',''HAMT''';
     open_bal_str := 'nvl(otp_bal,0) - nvl(otp_total_hold,0) dbal';
     open_bal_chk := ' and otp_bal is not null';
  elsif in_ele='P' then
     in_ele_type :='''PREP''';
     open_bal_str := 'nvl(otp_prepaid,0) dbal';
     open_bal_chk := ' and otp_prepaid is not null';
  elsif in_ele='T' then
     in_ele_type :='''INTR''';
     open_bal_str := 'nvl(otp_in_transit,0) dbal';
     open_bal_chk := ' and otp_in_transit is not null';
  elsif in_ele='L' then
     in_ele_type :='''UAMT'',''HAMT''';
     open_bal_str := 'nvl(otp_total_hold,0) dbal';
     open_bal_chk := ' and otp_total_hold is not null';
  else
     in_ele_type := null;
  end if;

  if in_baid is null  then

   bal_stmt := 'select sum(dbal) from (SELECT '|| open_bal_str || ',otp_psp_id,
                      row_number() over (partition by OBAI_BAID order by oth_approval_timestamp desc) rn
                  FROM ol_txn_psp_detail,ol_txn_header,OL_BANK_ACCT_ID,ol_def_baid_category
                 where oth_txn_id = otp_txn_id
                   AND oth_ar_ind = ''A''
                   and oth_approval_timestamp < :in_approval_date_from
                   and oth_version_no >= 2
                   and NVL(oth_txn_code, ''~'') not in (''PDO'')
                   AND otp_txn_ccy = :in_ccy
                   AND otp_psp_id = :in_psp_id
                   and OTP_BAID   = OBAI_BAID
                   and otp_psp_id = OBAI_PSP_ID ' || open_bal_chk || '
		   and OBAI_CATEGORY = bc_type
            	   and bc_in_balance = 1
                 order by oth_approval_timestamp desc)
                 where rn=1
                 group by otp_psp_id';

    begin
    execute immediate bal_stmt into dbal using IN_APPROVAL_DATE_FROM,in_ccy,in_psp_id;
    exception when others then null;
    end;

  sql_stmt :=
  'select /* opt_param(''_optimizer_use_feedback'',false) */   *
      from ( select obai_baid,
         OBAI_BAID_NAME ,
         OTP_PSP_ID        psp_id,
         oth_txn_id               txn_id,
         otp_tid                tid,
         oth_txn_code        txn_code,
         tc_desc            TXN_CODE_DESC,
         lag(rdbal) over (order by /*OBAI_BAID nulls first,*/oth_approval_timestamp nulls first,ote_exec_seq) OPEN_BAL,
         ote_amt_type        amt_type,
         ote_amount        amount,
         rdbal            bal,
         ote_txn_element_type    txn_element_type,
         dt_desc                TXN_ELEMENT_TYPE_DESC,
         ote_exec_seq        EXEC_SEQ,
         ote_ccy            txn_ccy,
         oth_approval_timestamp    APPROVAL_TIMESTAMP,
         oth_approval_date    approval_date,
         otp_report_date          report_date,
         void_txn_id,
         ote_party_type        party_type
  from
  (
  select obai_baid,
         OBAI_BAID_NAME ,
         OTP_PSP_ID,
         oth_txn_id,otp_tid,oth_txn_code, tc_desc,
         cr_dr,
         sum(cr_dr) over (order by /*OBAI_BAID nulls first,*/oth_approval_timestamp nulls first,ote_exec_seq) rdbal,dt_desc,
         ote_amt_type,ote_amount,ote_txn_element_type,ote_exec_seq,ote_ccy,
         oth_approval_timestamp,oth_approval_date,otp_report_date,void_txn_id,ote_party_type
    from
  (
  select obai_baid,
         OBAI_BAID_NAME ,
         OTP_PSP_ID,
         oth_txn_id,
         NULL otp_tid,
         oth_txn_code,
         tc_desc,
         ote_txn_element_type,
         dt_desc,
         ote_exec_seq,
         ote_amount,
         decode(:in_ele,''L'',decode(ote_amt_type,''DR'', ote_amount,-ote_amount),
                             decode(ote_amt_type,''DR'', -ote_amount,ote_amount)) cr_dr,
         ote_ccy,
         decode(:in_ele,''L'',decode(ote_amt_type,''DR'',''CR'',''DR''),ote_amt_type) ote_amt_type,
         oth_approval_timestamp,
         oth_approval_date,
         otp_txn_date || OTP_TXN_TIME otp_report_date ,
         NULL void_txn_id,
         /*(SELECT oth_txn_id
            FROM oL_txn_header th1
           WHERE th1.oth_ar_ind = ''A''
             AND th1.oth_txn_code not in (''RLR'')
             and th1.oth_org_txn_id=Oth.oth_txn_id) void_txn_id, */
         ote_party_type
    FROM ol_txn_header Oth,ol_txn_elements,ol_txn_psp_detail,OL_BANK_ACCT_ID,def_element_type,txn_code,ol_def_baid_category
   WHERE oth_approval_timestamp >= :in_approval_date_from
     AND oth_approval_timestamp <  :in_approval_date_to
     AND oth_version_no >= 2
     AND ote_ccy = :in_ccy
     AND otp_psp_id = :in_psp_id
     and OTP_BAID   = OBAI_BAID
     and otp_psp_id = OBAI_PSP_ID
     AND oth_ar_ind = ''A''
     AND oth_txn_code = tc_code
     AND oth_txn_id=otp_txn_id
     AND oth_txn_id = ote_txn_id
     and ote_txn_element_type IN ( ' || in_ele_type ||')
     AND ote_party_type = ''P''
     AND ote_txn_element_type = dt_type
     and OBAI_CATEGORY = bc_type
     and bc_in_balance = 1
  union all
  select null,null,'||''''|| in_psp_id ||'''' || ',null,null,null,null,null,null,null,null,'||nvl(dbal,0)||',null,null,null,null,null,null,null
  from dual)
  ORDER BY /*obai_baid nulls first ,*/oth_approval_timestamp nulls first, ote_exec_seq)
  ) where txn_id is not null';
-- dbms_output.put_line(sql_stmt);
  open sql_cur for sql_stmt using in_ele,in_ele,IN_APPROVAL_DATE_FROM,IN_APPROVAL_DATE_to,in_ccy,in_psp_id;

  else

 bal_stmt := 'select nvl(dbal,0) from (SELECT ' || open_bal_str|| '
                FROM ol_txn_psp_detail,ol_txn_header,OL_BANK_ACCT_ID
               where oth_txn_id = otp_txn_id
                 AND oth_ar_ind = ''A''
                 and oth_approval_timestamp < :in_approval_date_from
                 and oth_version_no >= 2
                 and NVL(oth_txn_code, ''~'') not in (''PDO'')
                 AND otp_txn_ccy = :in_ccy
                 and OBAI_BAID  = :in_baid
                 and OTP_BAID   = OBAI_BAID
                 and otp_psp_id = OBAI_PSP_ID ' || open_bal_chk || '
            order by oth_approval_timestamp desc)
           where rownum=1';
  begin
  execute immediate bal_stmt into dbal using IN_APPROVAL_DATE_FROM,in_ccy,in_baid;
  exception when others then null;
  end;

  sql_stmt :=
  'select /* opt_param(''_optimizer_use_feedback'',false) */ * from (
  select obai_baid,
         OBAI_BAID_NAME ,
         OTP_PSP_ID          psp_id,
         oth_txn_id               txn_id,
         otp_tid                tid,
         oth_txn_code        txn_code,
         tc_desc             TXN_CODE_DESC,
         lag(rdbal) over (partition by OBAI_BAID order by oth_approval_timestamp nulls first,ote_exec_seq) OPEN_BAL,
         ote_amt_type        amt_type,
         ote_amount          amount,
         rdbal               bal,
         ote_txn_element_type txn_element_type,
         dt_desc                TXN_ELEMENT_TYPE_DESC,
         ote_exec_seq        EXEC_SEQ,
         ote_ccy             txn_ccy,
         oth_approval_timestamp    APPROVAL_TIMESTAMP,
         oth_approval_date   approval_date,
         otp_report_date          report_date,
         void_txn_id,
         ote_party_type      party_type
  from
  (
  select obai_baid,
         OBAI_BAID_NAME ,
         OTP_PSP_ID,
         oth_txn_id,otp_tid,oth_txn_code, tc_desc,
         cr_dr,
         sum(cr_dr) over (partition by OBAI_BAID order by oth_approval_timestamp nulls first,ote_exec_seq) rdbal,dt_desc,
         ote_amt_type,ote_amount,ote_txn_element_type,ote_exec_seq,ote_ccy,
         oth_approval_timestamp,oth_approval_date,otp_report_date,void_txn_id,ote_party_type
    from
  (
  select obai_baid,
         OBAI_BAID_NAME ,
         OTP_PSP_ID,
         oth_txn_id,
         NULL otp_tid,
         oth_txn_code,
         tc_desc,
         ote_txn_element_type,
         dt_desc,
         ote_exec_seq,
         ote_amount,
         decode(:in_ele,''L'',decode(ote_amt_type,''DR'', ote_amount,-ote_amount),
                             decode(ote_amt_type,''DR'', -ote_amount,ote_amount)) cr_dr,
         ote_ccy,
         decode(:in_ele,''L'',decode(ote_amt_type,''DR'',''CR'',''DR''),ote_amt_type) ote_amt_type,
         oth_approval_timestamp,
         oth_approval_date,
         otp_txn_date || OTP_TXN_TIME otp_report_date,
         NULL void_txn_id,
         /*(SELECT oth_txn_id
            FROM oL_txn_header th1
           WHERE th1.oth_ar_ind = ''A''
             AND th1.oth_txn_code not in (''RLR'')
             and th1.oth_org_txn_id=Oth.oth_txn_id) void_txn_id,*/
         ote_party_type
    FROM ol_txn_header Oth,ol_txn_elements,ol_txn_psp_detail,OL_BANK_ACCT_ID,def_element_type,txn_code
  WHERE oth_approval_timestamp >= :in_approval_date_from
     AND oth_approval_timestamp <  :in_approval_date_to
     AND oth_version_no >= 2
     AND ote_ccy = :in_ccy
     and OBAI_BAID = :in_baid
     and OTP_BAID   = OBAI_BAID
     and otp_psp_id = OBAI_PSP_ID
     AND oth_ar_ind = ''A''
     AND oth_txn_code = tc_code
     AND oth_txn_id=otp_txn_id
     AND oth_txn_id = ote_txn_id
     and ote_txn_element_type IN ( ' || in_ele_type ||')
     AND ote_party_type = ''P''
     AND ote_txn_element_type = dt_type
  union all
  select ' ||''''||in_baid||''''||',null,' ||''''|| in_psp_id||''''||',null,null,null,null,null,null,null,null,' ||nvl(dbal,0) ||',null,null,null,null,null,null,null
  from dual)
  ORDER BY OBAI_BAID,oth_approval_timestamp nulls first, ote_exec_seq)
  ) where txn_id is not null';
--  dbms_output.put_line(sql_stmt);
  open sql_cur for sql_stmt using in_ele,in_ele,IN_APPROVAL_DATE_FROM,IN_APPROVAL_DATE_to,in_ccy,in_baid;
  end if;
  return(sql_cur);
  end baid_txn;
/

