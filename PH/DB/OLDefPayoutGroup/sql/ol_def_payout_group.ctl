load data
infile *
append
into table ol_def_payout_group
fields terminated by '|'
(opg_group,
 opg_desc,
 opg_create_timestamp SYSDATE,
 opg_update_timestamp SYSDATE,
 opg_create_user,
 opg_update_user
)
BEGINDATA
A|A|SYSTEM|SYSTEM|
B|Suspicious|SYSTEM|SYSTEM|
C|C|SYSTEM|SYSTEM|
D|Suspect|SYSTEM|SYSTEM|
