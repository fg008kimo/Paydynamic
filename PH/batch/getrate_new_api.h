#ifndef _GENERATE_NEW_API_H
#define _GENERATE_NEW_API_H

//#define REQUEST_URL   "http://fxp.oanda.com:5011/"
#define REQUEST_URL     "http://oandadev.pd.local/oanda/oanda.php"
#define REQUEST_HEADER  "?FXP/1.1"
#define QUOTE_TYPE      "date min_bid bid max_bid min_ask ask max_ask"

#define RESP_FILE       "/tmp/resp.txt"
#define RESP_HEADER     "fxp/1.1 200 ok"
#define BASE_CURR_CODE  "SYS_CCY"

#define ERS_REQ_URL   		"ERS_REQ_URL"
#define ERS_REQ_URL_LEN		1024

#define REQ_STRING_LEN  	1024
//#define REQ_STRING_LEN        165
//#define REQ_STRING_LEN  	180
#define DATE_LEN        30
#define RESP_FILE_LEN   200
#define RESP_HEADER_LEN 14

#define MAX_CYY_NUM     50

#define RET_VALUE_CNT   6
#define RET_VALUE_LEN   128
#define PD_MY_DELIMITOR " "
#define PD_MY_CHAR      0x0D
#define PD_MY_NEWLINE   0x0A


#ifdef __cplusplus
extern "C" {
#endif
typedef struct rData{
  char sFromCCY[4 +1];
  char sToCCY[4 +1];
  char sDate[21 +1];

  char min_bid[RET_VALUE_LEN +1];
  char bid[RET_VALUE_LEN +1];
  char max_bid[RET_VALUE_LEN + 1];
  char min_ask[RET_VALUE_LEN + 1];
  char ask[RET_VALUE_LEN + 1];
  char max_ask[RET_VALUE_LEN + 1];
}rData;

#ifdef __cplusplus
}
#endif


#endif
