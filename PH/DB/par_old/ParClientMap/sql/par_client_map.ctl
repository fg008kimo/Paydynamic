load data
infile "par_client_map.txt.prd"
append
into table par_client_map
fields terminated by '|'
(pcm_client_group,
 pcm_client_group_name,
 pcm_merch_acct_nmb,
 pcm_username,
 pcm_prefer_client_id,
 pcm_prefer_mid,
 pcm_mid_name,
 pcm_create_timestamp SYSDATE,
 pcm_create_user constant 'SYSTEM',
 pcm_update_timestamp SYSDATE,
 pcm_update_user constant 'SYSTEM'
)
