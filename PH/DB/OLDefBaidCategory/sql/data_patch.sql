------------------------------------------------
--Add Data into the table "OL_DEF_BAID_CATEGORY"
------------------------------------------------
--Type: BIT
insert into ol_def_baid_category (
bc_type, bc_desc, bc_allow_fe_create, bc_in_balance, 
bc_cat_name, bc_allow_multiple, bc_fe_display, 
bc_create_timestamp, bc_update_timestamp, bc_create_user, bc_update_user
)
values (
'BIT', 'BAID In-transit', 0, 0, 'BIT', 0, 1, 
sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

