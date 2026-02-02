LOAD DATA
INFILE 'IP_FILTER_DATA_TABLE.ldr'
APPEND
INTO TABLE "IP_FILTER"
FIELDS TERMINATED BY '|'
OPTIONALLY ENCLOSED BY '"' AND '"'
TRAILING NULLCOLS (
"IP_FILTER_ID" SEQUENCE(MAX,1),
"IP_START",
"IP_END",
"IP_LOCATION",
"IP_COUNT" EXPRESSION "(256*(256*(256*rtrim(rtrim(rtrim(rtrim(rtrim(rtrim(:ip_end,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.')+ltrim(ltrim(rtrim(rtrim(rtrim(rtrim(:ip_end,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.'))+ltrim(ltrim(ltrim(ltrim(rtrim(rtrim(:ip_end,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.'))+ltrim(ltrim(ltrim(ltrim(ltrim(ltrim(:ip_end,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.') - (256*(256*(256*rtrim(rtrim(rtrim(rtrim(rtrim(rtrim(:ip_start,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.')+ltrim(ltrim(rtrim(rtrim(rtrim(rtrim(:ip_start,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.'))+ltrim(ltrim(ltrim(ltrim(rtrim(rtrim(:ip_start,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.'))+ltrim(ltrim(ltrim(ltrim(ltrim(ltrim(:ip_start,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.')) + 1)",
"IP_MASK_BIT_COUNT" EXPRESSION "32 - log(2,(256*(256*(256*rtrim(rtrim(rtrim(rtrim(rtrim(rtrim(:ip_end,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.')+ltrim(ltrim(rtrim(rtrim(rtrim(rtrim(:ip_end,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.'))+ltrim(ltrim(ltrim(ltrim(rtrim(rtrim(:ip_end,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.'))+ltrim(ltrim(ltrim(ltrim(ltrim(ltrim(:ip_end,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.') - (256*(256*(256*rtrim(rtrim(rtrim(rtrim(rtrim(rtrim(:ip_start,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.')+ltrim(ltrim(rtrim(rtrim(rtrim(rtrim(:ip_start,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.'))+ltrim(ltrim(ltrim(ltrim(rtrim(rtrim(:ip_start,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.'))+ltrim(ltrim(ltrim(ltrim(ltrim(ltrim(:ip_start,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.')) + 1))",
"IP_START_HIGH" EXPRESSION "256*rtrim(rtrim(rtrim(rtrim(rtrim(rtrim(:ip_start,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.')+ltrim(ltrim(rtrim(rtrim(rtrim(rtrim(:ip_start,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.')",
"IP_START_LOW" EXPRESSION "256*ltrim(ltrim(ltrim(ltrim(rtrim(rtrim(:ip_start,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.')+ltrim(ltrim(ltrim(ltrim(ltrim(ltrim(:ip_start,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.')",
"IP_END_HIGH" EXPRESSION "256*rtrim(rtrim(rtrim(rtrim(rtrim(rtrim(:ip_end,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.')+ltrim(ltrim(rtrim(rtrim(rtrim(rtrim(:ip_end,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.')",
"IP_END_LOW" EXPRESSION "256*ltrim(ltrim(ltrim(ltrim(rtrim(rtrim(:ip_end,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.')+ltrim(ltrim(ltrim(ltrim(ltrim(ltrim(:ip_end,'0123456789'),'.'),'0123456789'),'.'),'0123456789'),'.')")
