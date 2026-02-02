load data
infile "stmt_match_filter_map.txt"
append
into table ol_stmt_match_filter_map
fields terminated by '|'
(OSMM_ACTION_TYPE,
OSMM_PARTY,
OSMM_FILTER,
OSMM_FIELD,
OSMM_ADD_SINGLE_QUOTE,
OSMM_DISABLED,
OSMM_CREATE_TIMESTAMP SYSDATE,
OSMM_CREATE_USER,
OSMM_UPDATE_TIMESTAMP SYSDATE,
OSMM_UPDATE_USER
)
