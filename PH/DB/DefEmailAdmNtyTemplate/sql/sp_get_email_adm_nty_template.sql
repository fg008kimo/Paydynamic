CREATE OR REPLACE FUNCTION sp_get_email_adm_nty_template (
    in_txn_id                     txn_header.th_txn_id%type,
    in_merchant_id                merch_detail.merchant_id%type,
    in_country                    merchant_bal_acct.mb_country%type,
    in_service                    merchant_bal_acct.mb_service_code%type,
    in_currency                   merchant_bal_acct.mb_ccy_id%type,
    in_funct                      rule_email_notification.re_funct%type,
    out_template          OUT     def_email_adm_nty_template.at_template%type)
RETURN NUMBER Is
    v_template       def_email_adm_nty_template.at_template%type := NULL;

    v_client_name              clients.client_name%type := NULL;
    v_client_id                clients.client_id%type := NULL;
    v_merchant_short_name      merch_detail.short_name%type := NULL;
    v_mid                      merch_detail.merchant_id%type := NULL;
    v_service_code             def_service_code.sc_desc%type := NULL;
    v_country                  country.country_name%type := NULL;
    v_request_ccy              merchant_bal_acct.mb_ccy_id%type := NULL;
    v_request_amt              VARCHAR2(50) := NULL;

    v_to_merchant_short_name   merch_detail.short_name%type := NULL;
    v_to_mid                   merch_detail.merchant_id%type := NULL;
    v_received_ccy             merchant_bal_acct.mb_ccy_id%type := NULL;

    v_request_date             VARCHAR2(50) := NULL;
    v_request_time             VARCHAR2(50) := NULL;
    v_alert_datetime           VARCHAR2(50) := NULL;

    v_sun_po_reserved          VARCHAR2(50) := NULL;
    v_mon_po_reserved          VARCHAR2(50) := NULL;
    v_tue_po_reserved          VARCHAR2(50) := NULL;
    v_wed_po_reserved          VARCHAR2(50) := NULL;
    v_thu_po_reserved          VARCHAR2(50) := NULL;
    v_fri_po_reserved          VARCHAR2(50) := NULL;
    v_sat_po_reserved          VARCHAR2(50) := NULL;

Begin

    select at_template
    into   v_template
    from   def_email_adm_nty_template
    where  at_funct = in_funct;

    if (in_funct = 'REQ_RTF') then

        select cl.client_id,
               cl.client_name,
               th.th_merchant_id,
               md.short_name,
               to_char(th.th_create_timestamp, 'DD/MM/YYYY'),
               to_char(th.th_create_timestamp, 'HH24:MI:SS'),
               sc.sc_desc,
               th.th_net_ccy,
               to_char(NVL(th.th_transaction_amount, 0), 'FM999,999,990.00')
        into   v_client_id,
               v_client_name,
               v_mid,
               v_merchant_short_name,
               v_request_date,
               v_request_time,
               v_service_code,
               v_request_ccy,
               v_request_amt
        from  def_service_code sc, clients cl, merch_detail md,
              txn_detail td, txn_header th
        where th.th_txn_code = 'RTF'
        and   th.th_txn_id = in_txn_id
        and   th_merchant_id = md.merchant_id
        and   md.client_id = cl.client_id
        and   th.th_txn_id = td.td_txn_id
        and   th.th_service_code = sc.sc_code;

        select th.th_merchant_id,
               md.short_name,
               th.th_net_ccy
        into   v_to_mid,
               v_to_merchant_short_name,
               v_received_ccy
        from   merch_detail md, txn_header th
        where  th.th_org_txn_id = in_txn_id
        and    th.th_txn_code = 'RTT'
        and    th.th_merchant_id = md.merchant_id;

        select to_char(sysdate, 'DD/MM/YYYY HH24:MI:SS')
        into v_alert_datetime
        from dual;

        v_template := replace (v_template, '[ARGV1]', v_client_name);
        v_template := replace (v_template, '[ARGV2]', v_client_id);
        v_template := replace (v_template, '[ARGV3]', v_merchant_short_name);
        v_template := replace (v_template, '[ARGV4]', v_mid);
        v_template := replace (v_template, '[ARGV5]', v_service_code);
        v_template := replace (v_template, '[ARGV6]', v_request_ccy);
        v_template := replace (v_template, '[ARGV7]', v_request_date);
        v_template := replace (v_template, '[ARGV8]', v_request_time);
        v_template := replace (v_template, '[ARGV9]', v_request_amt);

        v_template := replace (v_template, '[ARGV10]', v_to_merchant_short_name);
        v_template := replace (v_template, '[ARGV11]', v_received_ccy);
        v_template := replace (v_template, '[ARGV12]', v_to_mid);
        v_template := replace (v_template, '[ARGV13]', v_alert_datetime);


        out_template := v_template;

        return 0;

    elsif (in_funct = 'REQ_PO_RA') then

        select mr_merchant_id,
               mr_currency_id,
               mr_country_id,
               mr_service_code,
               to_char(max(mr_update_timestamp), 'DD/MM/YYYY'),
               to_char(max(mr_update_timestamp), 'HH24:MI:SS'),
               to_char(NVL(max(sun_amt), 0), 'FM999,999,990.00'),
               to_char(NVL(max(mon_amt), 0), 'FM999,999,990.00'),
               to_char(NVL(max(tue_amt), 0), 'FM999,999,990.00'),
               to_char(NVL(max(wed_amt), 0), 'FM999,999,990.00'),
               to_char(NVL(max(thu_amt), 0), 'FM999,999,990.00'),
               to_char(NVL(max(fri_amt), 0), 'FM999,999,990.00'),
               to_char(NVL(max(sat_amt), 0), 'FM999,999,990.00')
        into  v_mid, v_request_ccy, v_country, v_service_code,
              v_request_date, v_request_time,
              v_sun_po_reserved,
              v_mon_po_reserved,
              v_tue_po_reserved,
              v_wed_po_reserved,
              v_thu_po_reserved,
              v_fri_po_reserved,
              v_sat_po_reserved
        from (select mr_merchant_id, mr_currency_id, mr_country_id, mr_service_code,
                     mr_effect_date, mr_update_timestamp,
                     case when mr_day_of_week = 0 then mr_reserved_amount else 0 end as sun_amt,
                     case when mr_day_of_week = 1 then mr_reserved_amount else 0 end as mon_amt,
                     case when mr_day_of_week = 2 then mr_reserved_amount else 0 end as tue_amt,
                     case when mr_day_of_week = 3 then mr_reserved_amount else 0 end as wed_amt,
                     case when mr_day_of_week = 4 then mr_reserved_amount else 0 end as thu_amt,
                     case when mr_day_of_week = 5 then mr_reserved_amount else 0 end as fri_amt,
                     case when mr_day_of_week = 6 then mr_reserved_amount else 0 end as sat_amt
              from merchant_reserved_amt
              where mr_status = 'P'
              and mr_merchant_id = in_merchant_id
              and mr_type = 'R'
              and mr_currency_id = in_currency
              and mr_service_code = in_service
              )
        group by  mr_merchant_id, mr_currency_id, mr_country_id, mr_service_code;

        select cl.client_id,
               cl.client_name,
               md.short_name
        into v_client_id,
             v_client_name,
             v_merchant_short_name
        from clients cl, merch_detail md
        where md.merchant_id = in_merchant_id
        and md.client_id = cl.client_id;

        select sc_desc
        into v_service_code
        from def_service_code
        where sc_code = in_service;

        select to_char(sysdate, 'DD/MM/YYYY HH24:MI:SS')
        into v_alert_datetime
        from dual;

        v_template := replace (v_template, '[ARGV1]', v_client_name);
        v_template := replace (v_template, '[ARGV2]', v_client_id);
        v_template := replace (v_template, '[ARGV3]', v_merchant_short_name);
        v_template := replace (v_template, '[ARGV4]', v_mid);
        v_template := replace (v_template, '[ARGV5]', v_service_code);
        v_template := replace (v_template, '[ARGV6]', v_request_ccy);
        v_template := replace (v_template, '[ARGV7]', v_request_date);
        v_template := replace (v_template, '[ARGV8]', v_request_time);
        v_template := replace (v_template, '[ARGV13]', v_alert_datetime);

        v_template := replace (v_template, '[ARGV20]', v_sun_po_reserved);
        v_template := replace (v_template, '[ARGV21]', v_mon_po_reserved);
        v_template := replace (v_template, '[ARGV22]', v_tue_po_reserved);
        v_template := replace (v_template, '[ARGV23]', v_wed_po_reserved);
        v_template := replace (v_template, '[ARGV24]', v_thu_po_reserved);
        v_template := replace (v_template, '[ARGV25]', v_fri_po_reserved);
        v_template := replace (v_template, '[ARGV26]', v_sat_po_reserved);

        out_template := v_template;

        return 0;

    else
        return 1;
    end if;


exception
    WHEN OTHERS THEN
        RETURN 9;
END sp_get_email_adm_nty_template;
/

