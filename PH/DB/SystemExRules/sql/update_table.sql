update SYSTEM_EX_RULES set sr_none_restricted = 'MINBID', sr_res1_res2_opr = 'LT', SR_FR_TO_REVERSE = 'Y' where sr_txn_code in ('DSI','DSP');
update SYSTEM_EX_RULES set sr_restricted_2 = 'MINBID' where sr_txn_code = 'POA';
commit;
