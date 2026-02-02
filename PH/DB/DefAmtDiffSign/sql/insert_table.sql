


insert all
into def_amt_diff_sign (DS_CODE, DS_SIGN, DS_DESC, DS_CREATE_TIMESTAMP, DS_CREATE_USER, DS_UPDATE_TIMESTAMP, DS_UPDATE_USER)
values ('U', '+', 'Sign for Upper range', sysdate, 'SYSTEM', sysdate, 'SYSTEM')
into def_amt_diff_sign (DS_CODE, DS_SIGN, DS_DESC, DS_CREATE_TIMESTAMP, DS_CREATE_USER, DS_UPDATE_TIMESTAMP, DS_UPDATE_USER)
values ('L', '-', 'Sign for Lower range' sysdate, 'SYSTEM', sysdate, 'SYSTEM')
into def_amt_diff_sign (DS_CODE, DS_SIGN, DS_DESC, DS_CREATE_TIMESTAMP, DS_CREATE_USER, DS_UPDATE_TIMESTAMP, DS_UPDATE_USER)
values ('B', '±', 'Sign for both upper and lower range', sysdate, 'SYSTEM', sysdate, 'SYSTEM')
select * from dual;