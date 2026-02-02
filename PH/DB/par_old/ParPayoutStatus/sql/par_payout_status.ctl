load data
infile "par_payout_status.txt"
append
into table par_payout_status
fields terminated by '|'
(ps_type,
 ps_status,
 ps_status_id,
 ps_create_timestamp SYSDATE,
 ps_create_user constant 'SYSTEM',
 ps_update_timestamp SYSDATE,
 ps_update_user constant 'SYSTEM'
)
