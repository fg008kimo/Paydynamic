load data
infile "par_def_misc.txt.prd"
append
into table par_def_misc
fields terminated by '|'
(pdm_code,
 pdm_desc,
 pdm_value,
 pdm_create_timestamp SYSDATE,
 pdm_create_user constant 'SYSTEM',
 pdm_update_timestamp SYSDATE,
 pdm_update_user constant 'SYSTEM'
)
