CREATE OR REPLACE FUNCTION sp_ol_get_email_notify_tpl(
        in_txn_id                     ol_txn_header.oth_txn_id%type,
        in_merchant_id                ol_merch_detail.md_merchant_id%type,
        in_funct                      ol_rule_email_notification.ore_funct%type,
        out_template          OUT     ol_def_email_notify_template.oet_template%type)
RETURN NUMBER Is
        v_template                 ol_def_email_notify_template.oet_template%type := NULL;

      	v_brand_name               ol_merch_detail.md_brand_name%type := NULL;
        v_approval_datetime        VARCHAR2(50) := NULL;
        v_request_datetime         VARCHAR2(50) := NULL;
        v_merchant_short_name      ol_merch_detail.md_short_name%type := NULL;
        v_country                  country.country_name%type := NULL;
        v_service_code             def_service_code.sc_desc%type := NULL;
        v_request_ccy              ol_merchant_settlement_detail.osd_request_ccy%type := NULL;
        v_request_amt              VARCHAR2(50) := NULL;
        v_deliver_ccy              ol_merchant_settlement_detail.osd_deliver_ccy%type := NULL;
        v_deliver_amt              VARCHAR2(50) := NULL;
        

Begin

    select oet_template
    into   v_template
    from   ol_def_email_notify_template
    where  oet_funct = in_funct;

    if (in_funct = 'OFL_SETT_A') then

        select NVL(md_brand_name, 'Optimal Payments PH-Offline System'),
               to_char(oth_create_timestamp, 'YYYY-MM-DD HH24:MI:SS'),
               country_name, 
               sc_desc, 
               osd_request_ccy, to_char(NVL(osd_request_amt, 0), 'FM999,999,990.00'),
               osd_deliver_ccy, to_char(NVL(osd_deliver_amt, 0), 'FM999,999,990.00')
        into  v_brand_name,
              v_request_datetime,
              v_country,
              v_service_code,
              v_request_ccy, v_request_amt,
              v_deliver_ccy, v_deliver_amt
        from  def_service_code, country, ol_merch_detail, ol_merchant_settlement_detail , ol_txn_header
        where osd_txn_id = in_txn_id
        and   osd_settlement_type = 'M'
        and   oth_txn_id = osd_txn_id
        and   oth_txn_code = 'OSR'
        and   oth_ar_ind = 'A'
        and   oth_merchant_id = in_merchant_id
        and   osd_merchant_id = md_merchant_id
        and   osd_country_id = country_code
        and   osd_service_code = sc_code;

        v_template := replace (v_template, '[ARGV1]', v_brand_name); 
        v_template := replace (v_template, '[ARGV2]', in_merchant_id);
        v_template := replace (v_template, '[ARGV3]', in_txn_id);
        v_template := replace (v_template, '[ARGV4]', v_request_datetime);
        v_template := replace (v_template, '[ARGV5]', v_country);
        v_template := replace (v_template, '[ARGV6]', v_service_code);
        v_template := replace (v_template, '[ARGV7]', v_request_ccy);
        v_template := replace (v_template, '[ARGV8]', v_request_amt);
        v_template := replace (v_template, '[ARGV9]', v_deliver_ccy);
        v_template := replace (v_template, '[ARGV10]', v_deliver_amt);


        out_template := v_template;

        return 0;

    else 
        return 1;

    end if;


exception
    WHEN OTHERS THEN
        RETURN 9;
END sp_ol_get_email_notify_tpl;
/

