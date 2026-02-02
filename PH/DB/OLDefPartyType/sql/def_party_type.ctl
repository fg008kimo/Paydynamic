load data
infile *
append
into table ol_def_party_type
fields terminated by '|'
(opt_type,
 opt_group,
 opt_order_in_group,
 opt_desc,
 opt_create_timestamp SYSDATE,
 opt_update_timestamp SYSDATE,
 opt_create_user,
 opt_update_user
)
BEGINDATA
GLOBAL|||Global|SYSTEM|SYSTEM|
CLIENT|M|1|Client|SYSTEM|SYSTEM|
MERCH|M|2|Merchant|SYSTEM|SYSTEM|
PROV|P|1|Provider|SYSTEM|SYSTEM|
PID|P|2|PID|SYSTEM|SYSTEM|
BAID|P|3|BAID|SYSTEM|SYSTEM|
