-------------------------------------------------
--Add Data into the table "OL_RULE_BAID_AUTO_GEN"
-------------------------------------------------
--Bank Acct Type: ITM
--BAID Category Type: BIT
insert into ol_rule_baid_auto_gen (
rag_bank_acct_type, rag_baid_cat_type, rag_disabled, 
rag_create_timestamp, rag_update_timestamp, rag_create_user, rag_update_user
)
values (
'ITM', 'BIT', 0,
sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

--Bank Acct Type: PDF
--BAID Category Type: BIT
insert into ol_rule_baid_auto_gen (
rag_bank_acct_type, rag_baid_cat_type, rag_disabled, 
rag_create_timestamp, rag_update_timestamp, rag_create_user, rag_update_user
)
values (
'PDF', 'BIT', 0,
sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

