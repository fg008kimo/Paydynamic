CREATE OR REPLACE FUNCTION sp_get_email_notify_template (
        in_txn_id                     txn_header.th_txn_id%type,
        in_merchant_id                merch_detail.merchant_id%type,
        in_funct                      rule_email_notification.re_funct%type,
        out_template          OUT     def_email_notify_template.et_template%type)
RETURN NUMBER Is
        v_template       def_email_notify_template.et_template%type := NULL;

      	v_brand_name               merch_detail.brand_name%type := NULL;
        v_approval_datetime        VARCHAR2(50) := NULL;
        v_request_datetime         VARCHAR2(50) := NULL;
        v_merchant_short_name      merch_detail.short_name%type := NULL;
        v_country                  country.country_name%type := NULL;
        v_service_code             def_service_code.sc_desc%type := NULL;
        v_request_ccy              merchant_settlement_detail.sd_request_ccy%type := NULL;
        v_request_amt              VARCHAR2(50) := NULL;
        v_deliver_ccy              merchant_settlement_detail.sd_deliver_ccy%type := NULL;
        v_deliver_amt              VARCHAR2(50) := NULL;
        

Begin

    select et_template
    into   v_template
    from   def_email_notify_template
    where  et_funct = in_funct;


    if (in_funct = 'AUTO_SETT') then

        select NVL(brand_name, 'NETBANX Asia Bankcard Gateway'),
              /*sd_txn_id, */ to_char(th_approval_timestamp, 'YYYY-MM-DD HH24:MI:SS'),
              /*sd_merchant_id, */ short_name, 
              /*sd_country_id, */ country_name, 
              /*sd_service_code,*/ sc_desc, 
              sd_request_ccy, to_char(NVL(sd_request_amt, 0), 'FM999,999,990.00'), 
              sd_deliver_ccy, to_char(NVL(sd_deliver_amt, 0), 'FM999,999,990.00')
        into  v_brand_name,
              v_approval_datetime,
              v_merchant_short_name,
              v_country,
              v_service_code,
              v_request_ccy, v_request_amt,
              v_deliver_ccy, v_deliver_amt
        from  def_service_code, country, merch_detail, merchant_settlement_detail , txn_header
        where sd_txn_id = in_txn_id
        and   sd_settlement_type = 'S'
        and   th_txn_id = sd_txn_id
        and   th_txn_code = 'STR'
        and   th_ar_ind = 'A'
        and   th_merchant_id = in_merchant_id
        and   sd_merchant_id = merchant_id
        and   sd_country_id = country_code
        and   sd_service_code = sc_code;

        v_template := replace (v_template, '[ARGV1]', v_brand_name); 
        v_template := replace (v_template, '[ARGV2]', in_merchant_id);
        v_template := replace (v_template, '[ARGV3]', in_txn_id);
        v_template := replace (v_template, '[ARGV4]', v_approval_datetime);
        v_template := replace (v_template, '[ARGV5]', v_country);
        v_template := replace (v_template, '[ARGV6]', v_service_code);
        v_template := replace (v_template, '[ARGV7]', v_request_ccy);
        v_template := replace (v_template, '[ARGV8]', v_request_amt);
        v_template := replace (v_template, '[ARGV9]', v_deliver_ccy); 
        v_template := replace (v_template, '[ARGV10]', v_deliver_amt); 


        out_template := v_template;

        return 0;

    elsif (in_funct = 'MNL_SETT_A') then

        select NVL(brand_name, 'NETBANX Asia Bankcard Gateway'),
               to_char(th_create_timestamp, 'YYYY-MM-DD HH24:MI:SS'),
               country_name, 
               sc_desc, 
               sd_request_ccy, to_char(NVL(sd_request_amt, 0), 'FM999,999,990.00'),
               sd_deliver_ccy, to_char(NVL(sd_deliver_amt, 0), 'FM999,999,990.00')
        into  v_brand_name,
              v_request_datetime,
              v_country,
              v_service_code,
              v_request_ccy, v_request_amt,
              v_deliver_ccy, v_deliver_amt
        from  def_service_code, country, merch_detail, merchant_settlement_detail , txn_header
        where sd_txn_id = in_txn_id
        and   sd_settlement_type = 'M'
        and   th_txn_id = sd_txn_id
        and   th_txn_code = 'STR'
        and   th_ar_ind = 'A'
        and   th_merchant_id = in_merchant_id
        and   sd_merchant_id = merchant_id
        and   sd_country_id = country_code
        and   sd_service_code = sc_code;

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

    elsif (in_funct = 'MNL_SETT_M') then

        select NVL(brand_name, 'NETBANX Asia Bankcard Gateway'),
               to_char(th_create_timestamp, 'YYYY-MM-DD HH24:MI:SS'),
               country_name, 
               sc_desc, 
               sd_request_ccy, to_char(NVL(sd_request_amt, 0), 'FM999,999,990.00'),
               sd_deliver_ccy, to_char(NVL(sd_deliver_amt, 0), 'FM999,999,990.00')
        into  v_brand_name,
              v_request_datetime,
              v_country,
              v_service_code,
              v_request_ccy, v_request_amt,
              v_deliver_ccy, v_deliver_amt
        from  def_service_code, country, merch_detail, merchant_settlement_detail , txn_header
        where sd_txn_id = in_txn_id
        and   sd_settlement_type = 'M'
        and   th_txn_id = sd_txn_id
        and   th_txn_code = 'STR'
        and   th_ar_ind = 'A'
        and   th_merchant_id = in_merchant_id
        and   sd_merchant_id = merchant_id
        and   sd_country_id = country_code
        and   sd_service_code = sc_code;

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
END sp_get_email_notify_template;
/

