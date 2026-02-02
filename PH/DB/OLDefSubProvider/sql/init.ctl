load data
infile 'init.txt'
append
into table ol_def_sub_provider
fields terminated by '|'
(osp_sub_provider_id,
 osp_sub_provider_name,
 osp_disabled,
 osp_create_timestamp SYSDATE,
 osp_update_timestamp SYSDATE,
 osp_create_user,
 osp_update_user
)
