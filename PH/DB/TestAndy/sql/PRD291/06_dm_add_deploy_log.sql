


set scan off;

insert into deployment_log (l_seq, l_ref_no, l_mode, l_env, l_server, l_function, l_desc, l_create_user)
values (DEPLOY_SEQ.NEXTVAL, '20201030.sd01', 'OFFLINE', 'SD', 'DB', 'DB', '[PRD291] New Deposit Bank CIB', 'SYSTEM');

set scan on;
