-----------------------------------------
--Add Data into the table "MI_DEF_AR_BAL"
-----------------------------------------
--Code: Overpaid
insert into mi_def_ar_bal (
ad_code, ad_desc, ad_txn_code_map, ad_element_code, ad_amt_type,  
ad_create_timestamp, ad_update_timestamp, ad_create_user, ad_update_user
)
values (
'OVERPAID', 'Overpaid', '', 'OVPA', 'DR', sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

--Code: Underpaid
insert into mi_def_ar_bal (
ad_code, ad_desc, ad_txn_code_map, ad_element_code, ad_amt_type,
ad_create_timestamp, ad_update_timestamp, ad_create_user, ad_update_user
)
values (
'UNDERPAID', 'Underpaid', '', 'UDPA', 'CR', sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);
