CREATE OR REPLACE function sp_ol_get_auto_match_rules (
    iv_merchant_id        in      OL_AUTO_MATCH_MAPPING.AMM_MERCHANT_ID%type,
    out_cursor            out     sys_refcursor
)

RETURN NUMBER IS

    v_sql      VARCHAR2(3000);
    v_amr_type VARCHAR2(1000);

begin

    v_sql :=  'select amm_merchant_id, amm_priority, uni_amt, dsp_dtm, be_bk_acct, cust_text 
               from ( select amm_merchant_id, amm_priority, amp_match_rule_type
                      from ol_auto_match_pools, ol_auto_match_mapping 
                      where amm_merchant_id = ''' || iv_merchant_id || '''
                      and amm_disabled = 0   
                      and amm_pool_id = amp_pool_id
               ) 
               pivot
               (
               count(amp_match_rule_type)
               for amp_match_rule_type in (';

    
    select listagg ('''' || amr_type || ''' as ' || amr_tag_name, ',') within group (order by amr_order)
    into v_amr_type
    from (select amr_type, amr_tag_name, amr_order from ol_def_auto_match_rule) ;
    
    v_sql := v_sql || v_amr_type;

    
    v_sql := v_sql || ') ) order by amm_priority desc';
    
    OPEN out_cursor for v_sql;
   
    return 0;


exception
    when others then
        return 9;
end sp_ol_get_auto_match_rules;
/
