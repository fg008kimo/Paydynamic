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
086000|TXN_CODE_PDF|001|S/I to Pending Fund from Online|Transaction Type*|1
886000|TXN_CODE_PDF|001|S/I to Pending Fund from Online|Transaction Type*|1
086000|TXN_CODE_PDF|002|S/I to Pending Fund from Intermediate|Transaction Type*|2
886000|TXN_CODE_PDF|002|S/I to Pending Fund from Intermediate|Transaction Type*|2
086000|TXN_CODE_PDF|003|S/I to Pending Fund from Payout|Transaction Type*|3
886000|TXN_CODE_PDF|003|S/I to Pending Fund from Payout|Transaction Type*|3
086000|TXN_CODE_PDF|004|S/O from Pending Fund to Intermediate|Transaction Type*|1
886000|TXN_CODE_PDF|004|S/O from Pending Fund to Intermediate|Transaction Type*|1
086000|TXN_CODE_PDF|005|S/O from Pending Fund to Payout|Transaction Type*|2
886000|TXN_CODE_PDF|005|S/O from Pending Fund to Payout|Transaction Type*|2
086000|TXN_CODE_PDF|006|PSP Settlement|Transaction Type*|1
886000|TXN_CODE_PDF|006|PSP Settlement|Transaction Type*|1
086000|TXN_CODE_PDF|007|Payout (PSP)|Transaction Type*|1
886000|TXN_CODE_PDF|007|Payout (PSP)|Transaction Type*|1
086000|TXN_CODE_PDF|008|Overpaid Payout Cr Adj (PSP)|Transaction Type*|1
886000|TXN_CODE_PDF|008|Overpaid Payout Cr Adj (PSP)|Transaction Type*|1
086000|TXN_CODE_PDF|009|Overpaid Payout Dr Adj (PSP)|Transaction Type*|1
886000|TXN_CODE_PDF|009|Overpaid Payout Dr Adj (PSP)|Transaction Type*|1
086000|TXN_CODE_PDF|010|PSP Over-Settlement Cr Adj|Transaction Type*|2
886000|TXN_CODE_PDF|010|PSP Over-Settlement Cr Adj|Transaction Type*|2
086000|TXN_CODE_PDF|011|Provider Charge|Transaction Type*|1
886000|TXN_CODE_PDF|011|Provider Charge|Transaction Type*|1
086000|TXN_CODE_PDF|012|PSP Prepaid from Online|Transaction Type*|1
886000|TXN_CODE_PDF|012|PSP Prepaid from Online|Transaction Type*|1
086000|TXN_CODE_PDF|013|Prepaid Debit Adjustment|Transaction Type*|1
886000|TXN_CODE_PDF|013|Prepaid Debit Adjustment|Transaction Type*|1
086000|TXN_CODE_PDF|014|Overpaid Provider Charge Cr Adj|Transaction Type*|1
886000|TXN_CODE_PDF|014|Overpaid Provider Charge Cr Adj|Transaction Type*|1
086000|TXN_CODE_PDF|015|Provider Charge Discount|Transaction Type*|1
886000|TXN_CODE_PDF|015|Provider Charge Discount|Transaction Type*|1
086000|TXN_CODE_PDF|016|RTN S/O from Pending Fund to Intermediate|Transaction Type*|1
886000|TXN_CODE_PDF|016|RTN S/O from Pending Fund to Intermediate|Transaction Type*|1
086000|TXN_CODE_PDF|017|RTN S/O from Pending Fund to Payout|Transaction Type*|2
886000|TXN_CODE_PDF|017|RTN S/O from Pending Fund to Payout|Transaction Type*|2
086000|TXN_CODE_PDF|018|Unknown credits|Transaction Type*|1
886000|TXN_CODE_PDF|018|Unknown credits|Transaction Type*|1
086000|TXN_CODE_PDF|019|Unknown debits|Transaction Type*|1
886000|TXN_CODE_PDF|019|Unknown debits|Transaction Type*|1
886000|TXN_CODE_PDF|020|Provider Charge Consolidated|Transaction Type*|1
086000|TXN_CODE_PDF|020|Provider Charge Consolidated|Transaction Type*|1
886000|TXN_CODE_PDF|021|Void PSP Settlement|Transaction Type*|1
086000|TXN_CODE_PDF|021|Void PSP Settlement|Transaction Type*|1
886000|TXN_CODE_PDF|022|Void Payout (PSP)|Transaction Type*|1
086000|TXN_CODE_PDF|022|Void Payout (PSP)|Transaction Type*|1
886000|TXN_CODE_PDF|023|Void Overpaid Payout Cr Adj (PSP)|Transaction Type*|1
086000|TXN_CODE_PDF|023|Void Overpaid Payout Cr Adj (PSP)|Transaction Type*|1
886000|TXN_CODE_PDF|024|Void PSP Over-Settlement Cr Adj|Transaction Type*|1
086000|TXN_CODE_PDF|024|Void PSP Over-Settlement Cr Adj|Transaction Type*|1
886000|TXN_CODE_PDF|025|Void Provider Charge|Transaction Type*|1
086000|TXN_CODE_PDF|025|Void Provider Charge|Transaction Type*|1
886000|TXN_CODE_PDF|025|Void Provider Charge|Transaction Type*|1
086000|TXN_CODE_PDF|025|Void Provider Charge|Transaction Type*|1
886000|TXN_CODE_PDF|026|Void Provider Charge Consolidated|Transaction Type*|1
086000|TXN_CODE_PDF|026|Void Provider Charge Consolidated|Transaction Type*|1
886000|TXN_CODE_PDF|027|Void Overpaid Provider Charge Cr Adj|Transaction Type*|1
086000|TXN_CODE_PDF|027|Void Overpaid Provider Charge Cr Adj|Transaction Type*|1
886000|TXN_CODE_PDF|028|Void Provider Charge Discount|Transaction Type*|1
086000|TXN_CODE_PDF|028|Void Provider Charge Discount|Transaction Type*|1
086000|TXN_CODE_PDF|029|Returned Payout (PSP)|Transaction Type*|1
886000|TXN_CODE_PDF|029|Returned Payout (PSP)|Transaction Type*|1
886000|TXN_CODE_PDF|030|Overtime Service Fee (-)|Transaction Type*|1
086000|TXN_CODE_PDF|030|Overtime Service Fee (-)|Transaction Type*|1
886000|TXN_CODE_PDF|031|New Account Purchase Fee (-)|Transaction Type*|1
086000|TXN_CODE_PDF|031|New Account Purchase Fee (-)|Transaction Type*|1
886000|TXN_CODE_PDF|032|MR Provider Charge|Transaction Type*|1
086000|TXN_CODE_PDF|032|MR Provider Charge|Transaction Type*|1
886000|TXN_CODE_PDF|033|MR Payout (PSP)|Transaction Type*|1
086000|TXN_CODE_PDF|033|MR Payout (PSP)|Transaction Type*|1
886000|TXN_CODE_PDF|034|MR Returned Sweep Out|Transaction Type*|1
086000|TXN_CODE_PDF|034|MR Returned Sweep Out|Transaction Type*|1
886000|TXN_CODE_PDF|035|MR Sweep In|Transaction Type*|1
086000|TXN_CODE_PDF|035|MR Sweep In|Transaction Type*|1
886000|TXN_CODE_PDF|036|MR Sweep In from Online|Transaction Type*|1
086000|TXN_CODE_PDF|036|MR Sweep In from Online|Transaction Type*|1
886000|TXN_CODE_PDF|037|MR Sweep Out|Transaction Type*|1
086000|TXN_CODE_PDF|037|MR Sweep Out|Transaction Type*|1
886000|TXN_CODE_PDF|038|Void Overtime Service Fee (-)|Transaction Type*|1
086000|TXN_CODE_PDF|038|Void Overtime Service Fee (-)|Transaction Type*|1
886000|TXN_CODE_PDF|039|Void New Account Purchase Fee (-)|Transaction Type*|1
086000|TXN_CODE_PDF|039|Void New Account Purchase Fee (-)|Transaction Type*|1
886000|TXN_CODE_PDF|040|Void MR Provider Charge|Transaction Type*|1
086000|TXN_CODE_PDF|040|Void MR Provider Charge|Transaction Type*|1
886000|TXN_CODE_PDF|041|Void MR Payout (PSP)|Transaction Type*|1
086000|TXN_CODE_PDF|041|Void MR Payout (PSP)|Transaction Type*|1
886000|TXN_CODE_PDF|042|Void MR Returned Sweep Out|Transaction Type*|1
086000|TXN_CODE_PDF|042|Void MR Returned Sweep Out|Transaction Type*|1
886000|TXN_CODE_PDF|043|Void MR Sweep In|Transaction Type*|1
086000|TXN_CODE_PDF|043|Void MR Sweep In|Transaction Type*|1
886000|TXN_CODE_PDF|044|Void MR Sweep In from Online|Transaction Type*|1
086000|TXN_CODE_PDF|044|Void MR Sweep In from Online|Transaction Type*|1
886000|TXN_CODE_PDF|045|Void MR Sweep Out|Transaction Type*|1
086000|TXN_CODE_PDF|045|Void MR Sweep Out|Transaction Type*|1
886000|TXN_CODE_PDF|046|PSP Fund-in|Transaction Type*|1
086000|TXN_CODE_PDF|046|PSP Fund-in|Transaction Type*|1
886000|TXN_CODE_PDF|047|Void PSP Fund-in|Transaction Type*|1
086000|TXN_CODE_PDF|047|Void PSP Fund-in|Transaction Type*|1
086000|TXN_CODE_PDF|048|Void S/I to Pending Fund from Intermediate|Transaction Type*|1
886000|TXN_CODE_PDF|048|Void S/I to Pending Fund from Intermediate|Transaction Type*|1
086000|TXN_CODE_PDF|049|Void S/I to Pending Fund from Online|Transaction Type*|1
886000|TXN_CODE_PDF|049|Void S/I to Pending Fund from Online|Transaction Type*|1
086000|TXN_CODE_PDF|050|Void S/I to Pending Fund from Payout|Transaction Type*|1
886000|TXN_CODE_PDF|050|Void S/I to Pending Fund from Payout|Transaction Type*|1
886000|TXN_CODE_PDF|051|Void S/O from Pending Fund to Intermediate|Transaction Type*|1
086000|TXN_CODE_PDF|051|Void S/O from Pending Fund to Intermediate|Transaction Type*|1
886000|TXN_CODE_PDF|052|Void S/O from Pending Fund to Payout|Transaction Type*|1
086000|TXN_CODE_PDF|052|Void S/O from Pending Fund to Payout|Transaction Type*|1
086000|TXN_CODE_PDF|053|Void Overpaid Payout Dr Adj (PSP)|Transaction Type*|1
886000|TXN_CODE_PDF|053|Void Overpaid Payout Dr Adj (PSP)|Transaction Type*|1
086000|TXN_CODE_PDF|054|S/I to Pending Fund from Intermediate(OFST)|Transaction Type*|1
886000|TXN_CODE_PDF|054|S/I to Pending Fund from Intermediate(OFST)|Transaction Type*|1
086000|TXN_CODE_PDF|055|S/I to Pending Fund from Online(OFST)|Transaction Type*|1
886000|TXN_CODE_PDF|055|S/I to Pending Fund from Online(OFST)|Transaction Type*|1
886000|TXN_CODE_PDF|056|S/I to Pending Fund from Payout(OFST)|Transaction Type*|1
086000|TXN_CODE_PDF|056|S/I to Pending Fund from Payout(OFST)|Transaction Type*|1
086000|TXN_CODE_PDF|057|Void Returned Payout (PSP)|Transaction Type*|1
886000|TXN_CODE_PDF|057|Void Returned Payout (PSP)|Transaction Type*|1
