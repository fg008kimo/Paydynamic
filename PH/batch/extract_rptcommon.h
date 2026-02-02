#ifndef	_EXTRACT_RPTCOMMON_H_
#define	_EXTRACT_RPTCOMMON_H_


#ifdef __cplusplus
extern "C" {
#endif

int Extract_RPT001(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT002(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT003(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT004(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT005(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT006(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT007(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT008(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT009(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT010(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT011(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT012(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT013(const char* csFileName, SQL_CURSOR c_input_cursor);

int Extract_RPT_ESKY(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT_YPY(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT_HCP(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT_TWV(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT_ALP(const char* csFileName, SQL_CURSOR c_input_cursor);

int Extract_RPT_DETAIL(const char* csFileName, SQL_CURSOR c_input_cursor);
int Extract_RPT_SUMMARY(const char* csFileName, SQL_CURSOR c_input_cursor);

char *GetFileName(const unsigned char* csPspName, const char* cs_eod_date);
char *GetTxnDetailFileName(const unsigned char* csPspName, const unsigned char* csCountry, const char* cs_eod_date,const char* csType);
#ifdef __cplusplus
}
#endif

#endif

