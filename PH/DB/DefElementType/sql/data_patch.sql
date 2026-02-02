--------------------------------------------
--Add Data into the table "DEF_ELEMENT_TYPE"
--------------------------------------------
--Element Type: Overpaid
insert into def_element_type (
dt_type, dt_desc, 
dt_create_timestamp, dt_update_timestamp, dt_create_user, dt_update_user
)
values (
'OVPA', 'Overpaid', sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

--Element Type: Underpaid
insert into def_element_type (
dt_type, dt_desc,
dt_create_timestamp, dt_update_timestamp, dt_create_user, dt_update_user
)
values (
'UDPA', 'Underpaid', sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);
