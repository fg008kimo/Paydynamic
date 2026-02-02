load data
infile *
append
into table acr_tolerance
fields terminated by '|'
(AT_COMPARE_WITH,
 AT_BANK_CCY,
 AT_TOLERANCE,
 AT_create_timestamp SYSDATE,
 AT_update_timestamp SYSDATE,
 AT_create_user,
 AT_update_user
)
BEGINDATA
OANDA|HKD|0.4|SYSTEM|SYSTEM
OANDA|GBP|1|SYSTEM|SYSTEM
ORG_ACR|GBP|1|SYSTEM|SYSTEM
ORG_ACR|HKD|1|SYSTEM|SYSTEM
