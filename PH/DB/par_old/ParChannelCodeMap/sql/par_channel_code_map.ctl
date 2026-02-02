load data
infile "par_channel_code_map.txt"
append
into table par_channel_code_map
fields terminated by '|'
(ccm_psp_vnc_code,
 ccm_psp_vnc_name,
 ccm_channel_code,
 ccm_create_timestamp SYSDATE,
 ccm_create_user constant 'SYSTEM',
 ccm_update_timestamp SYSDATE,
 ccm_update_user constant 'SYSTEM'
)
