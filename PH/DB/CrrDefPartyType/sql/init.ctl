load data
infile 'init.txt'
append
into table crr_def_party_type
fields terminated by '|'
(cpt_type_id,
 cpt_desc,
 cpt_create_timestamp SYSDATE,
 cpt_update_timestamp SYSDATE,
 cpt_create_user,
 cpt_update_user
)
