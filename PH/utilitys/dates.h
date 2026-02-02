#ifndef _DATES_H_
#define _DATES_H_

#define CC0             0
#define CC1             1
#define YY0             2
#define YY1             3
#define MM0             4
#define MM1             5
#define DD0             6
#define DD1             7
#define HH0	        8	
#define HH1		9
#define MI0            	10
#define MI1            	11
#define SS0		12
#define SS1		13
#define MMDD_LEN        4

#ifdef __cplusplus
extern "C" { 
#endif  

char *jdate(const char * cs_date);
char *jtime(const char * cs_date);
int isleap(int year);
char *getdatetime(void);
void mmdd2ccyymmdd(const unsigned char* mmdd, char* new_pdate);
int check_valid_date(const char *date);
int addmonth(const char* csCurrentDate,int numofmonth,char* csNewDate);
int day_of_week (const unsigned char* cs_date);
int daydiff(const char *ldate,const char *rdate);
int monthenddate(const char *workdate,char* monthenddate);
char *getgmtdatetime(void);
int addday(const char* csCurrentDate,int numofdate,char* csNewDate);
int day_of_year(const char *date);
char* get_RFC_2822_date(void);
char* UTC2Local(const char* csDatetime,const char* TIMEZONE);
int check_valid_datetime(const char *datetime);
char* write_tpl_timestamp();
#ifdef __cplusplus
}       
#endif 
#endif

