#ifndef _ALP_DOWNLOAD_H
#define _ALP_DOWNLOAD_H

#define	REQ_DOMAIN	"http://116.236.252.102:5015/"
#define REQ_DETAIL	"member/checkfiledown/CheckFileDownLoad/checkfileDownLoad.do"

#define REQUEST_URL	"http://fxp.oanda.com:5011/"
#define REQUEST_HEADER	"?FXP/1.1"
#define QUOTE_TYPE	"date min_bid bid max_bid min_ask ask max_ask"

#define RESP_FILE	"/tmp/resp.txt"
#define RESP_HEADER	"FXP/1.1 200 ok"
#define BASE_CURR_CODE	"SYS_CCY"

#define REQ_STRING_LEN	165
#define DATE_LEN	30
#define RESP_FILE_LEN	200
#define RESP_HEADER_LEN	14

#define MAX_CYY_NUM	50

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#endif
