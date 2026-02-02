load data
infile "par_psp_client_map.prd.txt"
append
into table par_psp_client_map
fields terminated by ','
trailing nullcols
(ppm_psp_client_grp,
 ppm_psp_client_grp_name,
 ppm_psp_type_cd,
 ppm_psp_type_name,
 ppm_psp_code,
 ppm_psp_name,
 ppm_txn_type "decode(:ppm_txn_type, '1', 'A', '3', 'P', :ppm_txn_type)",
 ppm_country,
 ppm_ccy_id,
 ppm_preset_pid,
 ppm_preset_psp_name,
 ppm_psp_type TERMINATED BY WHITESPACE,
 ppm_create_timestamp SYSDATE,
 ppm_create_user constant 'SYSTEM',
 ppm_update_timestamp SYSDATE,
 ppm_update_user constant 'SYSTEM'
)
