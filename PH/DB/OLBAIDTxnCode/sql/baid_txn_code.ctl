load data
infile *
append
into table ol_baid_txn_code
fields terminated by '|'
(OBTC_CODE,
OBTC_DESC,
OBTC_VOIDABLE,
OBTC_AMT_TYPE,
OBTC_VOID_CODE,
OBTC_DEFAULT_CODE,
OBTC_CREATE_TIMESTAMP SYSDATE,
OBTC_CREATE_USER,
OBTC_UPDATE_TIMESTAMP SYSDATE,
OBTC_UPDATE_USER
)
begindata
XVD|Void Overpaid Payout Dr Adj (PSP)|0|CR|||SYSTEM|SYSTEM
QEF|S/I to Pending Fund from Intermediate(OFST)|0|DR|||SYSTEM|SYSTEM
QXF|S/I to Pending Fund from Online(OFST)|0|DR|||SYSTEM|SYSTEM
QPF|S/I to Pending Fund from Payout(OFST)|0|DR|||SYSTEM|SYSTEM
