load data
infile *
append
into table ol_stmt_format_keywords
fields terminated by '|'
(OLFK_INT_BANK_CODE,
OLFK_FORMAT_TYPE,
OLFK_FORMAT_VALUE,
OLFK_FORMAT_TXN_CODE,
OLFK_FORMAT_TEMPLATE,
OLFK_FORMAT_COL_NAME,
OLFK_DISPLAY_ORDER,
OLFK_DISABLED,
OLFK_CREATE_TIMESTAMP SYSDATE,
OLFK_CREATE_USER,
OLFK_UPDATE_TIMESTAMP SYSDATE,
OLFK_UPDATE_USER
)
begindata
086000|TXN_CODE_PDF|48|NEF|Void S/I to Pending Fund from Intermediate|Transaction Type*|1|0|SYSTEM|SYSTEM
086000|TXN_CODE_PDF|49|KXF|Void S/I to Pending Fund from Online|Transaction Type*|1|0|SYSTEM|SYSTEM
086000|TXN_CODE_PDF|50|NPF|Void S/I to Pending Fund from Payout|Transaction Type*|1|0|SYSTEM|SYSTEM
086000|TXN_CODE_PDF|51|KFE|Void S/O from Pending Fund to Intermediate|Transaction Type*|1|0|SYSTEM|SYSTEM
086000|TXN_CODE_PDF|52|KFP|Void S/O from Pending Fund to Payout|Transaction Type*|1|0|SYSTEM|SYSTEM
