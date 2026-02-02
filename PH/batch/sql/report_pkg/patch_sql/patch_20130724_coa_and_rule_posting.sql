delete from crr_gl_code
where gl_code = '10129600'
and sl_code in ('CPDIR166(A)','CPDIR166(F)');

delete from crr_rule_posting
where cr_country_id = 'CN'
and cr_product_code = 'HBD'
and (cr_credit_gl_id in (select gl_id from crr_gl_code where gl_code = '10129600' and sl_code in ('CPDIR166(A)','CPDIR166(F)'))
     or
     cr_debit_gl_id in (select gl_id from crr_gl_code where gl_code = '10129600' and sl_code in ('CPDIR166(A)','CPDIR166(F)'))
    );

commit;
