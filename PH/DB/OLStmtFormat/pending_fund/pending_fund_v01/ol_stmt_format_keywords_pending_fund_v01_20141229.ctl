LOAD DATA
 CHARACTERSET UTF8
 INFILE *
 APPEND
 INTO TABLE OL_STMT_FORMAT_KEYWORDS
 WHEN (1:2) <> '--'
 FIELDS TERMINATED BY '|' OPTIONALLY ENCLOSED BY '"'
 TRAILING NULLCOLS
(
 OLFK_INT_BANK_CODE,
 OLFK_FORMAT_TYPE,
 OLFK_FORMAT_VALUE,
 OLFK_FORMAT_TXN_CODE,
 OLFK_FORMAT_TEMPLATE "TRIM(:OLFK_FORMAT_TEMPLATE)",
 OLFK_FORMAT_COL_NAME "TRIM(:OLFK_FORMAT_COL_NAME)",
 OLFK_DISPLAY_ORDER,

 OLFK_DISABLED CONSTANT 0,
 OLFK_CREATE_TIMESTAMP "SYSDATE",
 OLFK_CREATE_USER CONSTANT "SYSTEM",
 OLFK_UPDATE_TIMESTAMP "SYSDATE",
 OLFK_UPDATE_USER CONSTANT "SYSTEM"
)
BEGINDATA
--INT_BANK_CODE|FORMAT_TYPE|FORMAT_VALUE|FORMAT_TXN_CODE|FORMAT_TEMPLATE|FORMAT_COL_NAME|DISPLAY_ORDER
086000|TXN_CODE_PDF|3|SNF|Sweep In to Pending Fund from Payout|Transaction Type*|3
086000|TXN_CODE_PDF|4|SUF|Sweep Out from Pending Fund to Intermediate|Transaction Type*|1
086000|TXN_CODE_PDF|5|SUF|Sweep Out from Pending Fund to Payout|Transaction Type*|2
086000|TXN_CODE_PDF|6|OPT|PSP Settlement|Transaction Type*|1
086000|TXN_CODE_PDF|7|OBP|Payout|Transaction Type*|1
086000|TXN_CODE_PDF|8|OOD|Overpaid Payout|Transaction Type*|1
086000|TXN_CODE_PDF|9|OOD|Over-Settlement|Transaction Type*|2
086000|TXN_CODE_PDF|10|CGP|Paid Provider Charge|Transaction Type*|1
086000|TXN_CODE_PDF|11|OPC|PSP Prepaid from Online|Transaction Type*|1
086000|TXN_CODE_PDF|12|OPD|Prepaid Debit Adjustment|Transaction Type*|1
086000|TXN_CODE_PDF|13|UBC|Unknown credits|Transaction Type*|1
086000|TXN_CODE_PDF|14|UBD|Unknown debits|Transaction Type*|1
886000|TXN_CODE_PDF|1|SNF|Sweep In to Pending Fund from Online Deposit|Transaction Type*|1
886000|TXN_CODE_PDF|2|SNF|Sweep In to Pending Fund from Intermediate|Transaction Type*|2
886000|TXN_CODE_PDF|3|SNF|Sweep In to Pending Fund from Payout|Transaction Type*|3
886000|TXN_CODE_PDF|4|SUF|Sweep Out from Pending Fund to Intermediate|Transaction Type*|1
886000|TXN_CODE_PDF|5|SUF|Sweep Out from Pending Fund to Payout|Transaction Type*|2
886000|TXN_CODE_PDF|6|OPT|PSP Settlement|Transaction Type*|1
886000|TXN_CODE_PDF|7|OBP|Payout|Transaction Type*|1
886000|TXN_CODE_PDF|8|OOD|Overpaid Payout|Transaction Type*|1
886000|TXN_CODE_PDF|9|OOD|Over-Settlement|Transaction Type*|2
886000|TXN_CODE_PDF|10|CGP|Paid Provider Charge|Transaction Type*|1
886000|TXN_CODE_PDF|11|OPC|PSP Prepaid from Online|Transaction Type*|1
886000|TXN_CODE_PDF|12|OPD|Prepaid Debit Adjustment|Transaction Type*|1
086000|TXN_CODE_PDF|1|SNF|Sweep In to Pending Fund from Online Deposit|Transaction Type*|1
086000|TXN_CODE_PDF|2|SNF|Sweep In to Pending Fund from Intermediate|Transaction Type*|2
886000|TXN_CODE_PDF|13|UBC|Unknown credits|Transaction Type*|1
886000|TXN_CODE_PDF|14|UBD|Unknown debits|Transaction Type*|1
086000|TXN_CODE_PDF|15|VUF|Returned Sweep Out from Pending Fund to Intermediate|Transaction Type*|1
086000|TXN_CODE_PDF|16|VUF|Returned Sweep Out from Pending Fund to Payout|Transaction Type*|2
