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
086000|TXN_CODE_PDF|001|SNF|Sweep In to Pending Fund from Online Deposit|Transaction Type*|1
086000|TXN_CODE_PDF|002|SNF|Sweep In to Pending Fund from Intermediate|Transaction Type*|2
086000|TXN_CODE_PDF|003|SNF|Sweep In to Pending Fund from Payout|Transaction Type*|3
086000|TXN_CODE_PDF|004|SUF|Sweep Out from Pending Fund to Intermediate|Transaction Type*|1
086000|TXN_CODE_PDF|005|SUF|Sweep Out from Pending Fund to Payout|Transaction Type*|2
086000|TXN_CODE_PDF|006|OPT|PSP Settlement|Transaction Type*|1
086000|TXN_CODE_PDF|007|OBP|Payout|Transaction Type*|1
086000|TXN_CODE_PDF|008|OOD|Overpaid Payout|Transaction Type*|1
086000|TXN_CODE_PDF|009|OOD|Over-Settlement|Transaction Type*|2
086000|TXN_CODE_PDF|010|CGP|Paid Provider Charge|Transaction Type*|1
086000|TXN_CODE_PDF|011|OPC|PSP Prepaid from Online|Transaction Type*|1
086000|TXN_CODE_PDF|012|OPD|Prepaid Debit Adjustment|Transaction Type*|1
086000|TXN_CODE_PDF|013|UBC|Unknown credits|Transaction Type*|1
086000|TXN_CODE_PDF|014|UBD|Unknown debits|Transaction Type*|1
086000|TXN_CODE_PDF|015|VUF|Returned Sweep Out from Pending Fund to Intermediate|Transaction Type*|1
086000|TXN_CODE_PDF|016|VUF|Returned Sweep Out from Pending Fund to Payout|Transaction Type*|2
886000|TXN_CODE_PDF|001|SNF|Sweep In to Pending Fund from Online Deposit|Transaction Type*|1
886000|TXN_CODE_PDF|002|SNF|Sweep In to Pending Fund from Intermediate|Transaction Type*|2
886000|TXN_CODE_PDF|003|SNF|Sweep In to Pending Fund from Payout|Transaction Type*|3
886000|TXN_CODE_PDF|004|SUF|Sweep Out from Pending Fund to Intermediate|Transaction Type*|1
886000|TXN_CODE_PDF|005|SUF|Sweep Out from Pending Fund to Payout|Transaction Type*|2
886000|TXN_CODE_PDF|006|OPT|PSP Settlement|Transaction Type*|1
886000|TXN_CODE_PDF|007|OBP|Payout|Transaction Type*|1
886000|TXN_CODE_PDF|008|OOD|Overpaid Payout|Transaction Type*|1
886000|TXN_CODE_PDF|009|OOD|Over-Settlement|Transaction Type*|2
886000|TXN_CODE_PDF|010|CGP|Paid Provider Charge|Transaction Type*|1
886000|TXN_CODE_PDF|011|OPC|PSP Prepaid from Online|Transaction Type*|1
886000|TXN_CODE_PDF|012|OPD|Prepaid Debit Adjustment|Transaction Type*|1
886000|TXN_CODE_PDF|013|UBC|Unknown credits|Transaction Type*|1
886000|TXN_CODE_PDF|014|UBD|Unknown debits|Transaction Type*|1
886000|TXN_CODE_PDF|015|VUF|Returned Sweep Out from Pending Fund to Intermediate|Transaction Type*|1
886000|TXN_CODE_PDF|016|VUF|Returned Sweep Out from Pending Fund to Payout|Transaction Type*|2
