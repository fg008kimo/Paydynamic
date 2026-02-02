INSERT ALL
INTO test_create(
        tc_key,
        tc_field,
        tc_amount,
        tc_disabled,
        tc_create_timestamp,
        tc_update_timestamp,
        tc_create_user,
        tc_update_user,
        tc_ccy)
  VALUES( 'A','testing',0.00,0,sysdate,sysdate,'SYSTEM','SYSTEM','EUR')
Select * from dual;
