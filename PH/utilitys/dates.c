#include <stdio.h>
#include <ctype.h>
#include "dates.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "common.h"
#include "debug.h"


static int vday[] = {
-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 29
};

static char cs_jdate[20];


/* check if year is a leap year */
int isleap(int year)
{
        return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

// Convert CCYYMMDD to Julian Date Format
char *jdate(const char * cs_date)
{
	unsigned int i_mm, i_dd, i_year, i;

    i_year = (cs_date[CC0] - '0') * 1000 +  (cs_date[CC1] - '0') * 100 +
    (cs_date[YY0] - '0') * 10 + (cs_date[YY1] - '0');
    i_mm = (cs_date[MM1] - '0') + (cs_date[MM0] - '0') * 10;
    i_dd = (cs_date[DD1] - '0') + (cs_date[DD0] - '0') * 10;

    for (i = 1; i < i_mm; i++) {
		if (isleap(i_year) && i == 2)
			i_dd += vday[13];
		else
			i_dd += vday[i];
        }
    i_dd -= 1;
    for (i = PD_DATE_SINCE  ; i < i_year; i ++) {
		if (isleap(i))
			i_dd += 366;
		else
			i_dd += 365;
	}
    sprintf(cs_jdate, "%u", i_dd);
    return cs_jdate;
}


// Convert CCYYMMDDHHMISS to Julian time Format
char *jtime(const char * cs_datetime)
{
	int i_mm, i_dd, i_year,i;
	long l_hh,l_min,l_sec;

    i_year = (cs_datetime[CC0] - '0') * 1000 +  (cs_datetime[CC1] - '0') * 100 +
    (cs_datetime[YY0] - '0') * 10 + (cs_datetime[YY1] - '0');
    i_mm = (cs_datetime[MM1] - '0') + (cs_datetime[MM0] - '0') * 10;
    i_dd = (cs_datetime[DD1] - '0') + (cs_datetime[DD0] - '0') * 10;

    for (i = 1; i < i_mm; i++) {
		if (isleap(i_year) && i == 2)
			i_dd += vday[13];
		else
			i_dd += vday[i];
	}
    i_dd -= 1;
    for (i = PD_DATETIME_SINCE  ; i < i_year; i ++) {
		if (isleap(i))
			i_dd += 366;
        else
            i_dd += 365;
    }
    l_hh = (cs_datetime[HH1] - '0') + (cs_datetime[HH0] - '0') * 10;
    l_min = (cs_datetime[MI1] - '0') + (cs_datetime[MI0] - '0') * 10;
    l_sec = (cs_datetime[SS1] - '0') + (cs_datetime[SS0] - '0') * 10;

    l_sec += ((l_hh + i_dd * 24) * 60 + l_min) * 60;
    sprintf(cs_jdate, "%ld", l_sec);
    return cs_jdate;
}

char *getdatetime(void)
{
	        struct tm *ts;
        time_t clock;
        static  char sysdatetime[PD_DATETIME_LEN + 1];

        clock = time((time_t *) NULL);
        do {
                ts = localtime(&clock);
        } while (ts->tm_sec >= 60);
        sprintf(sysdatetime,"%04d%02d%02d%02d%02d%02d",ts->tm_year + 1900,
                                                                   ts->tm_mon + 1,
                                                                   ts->tm_mday,
                                                                   ts->tm_hour,
                                                                   ts->tm_min,
                                                                   ts->tm_sec);
        return sysdatetime;
	
};
void mmdd2ccyymmdd(const unsigned char* mmdd, char* new_pdate)
{

    char    timestamp[PD_DATE_LEN+PD_TIME_LEN+1];
    char    month[3];
    char    year[5];
    int     i_my_year;
    int     i_my_mon;
    int     i_mmdd_year; /* The unknown */
    int     i_mmdd_mon;

    strcpy(timestamp, getdatetime());
    memcpy(month, &timestamp[4], 2);
    month[2] = '\0';
    i_my_mon = atoi(month);
    memcpy(year, timestamp, 4);
    year[4] = '\0';
    i_my_year = atoi(year);
    memcpy(month, mmdd, 2);
    month[2] = '\0';
    i_mmdd_mon = atoi(month);

    if (i_mmdd_mon == 1 && i_my_mon == 12) {
        i_mmdd_year = i_my_year + 1;
    }
    else
    if (i_mmdd_mon == 12 && i_my_mon == 1) {
        i_mmdd_year = i_my_year - 1;
    }
    else
	i_mmdd_year = i_my_year;

    sprintf(year, "%04d", i_mmdd_year);
    memcpy(new_pdate, year, 4);
    memcpy(&new_pdate[4], mmdd, MMDD_LEN);
    new_pdate[PD_DATE_LEN] = '\0';
}

int check_valid_date(const char *date)
{                       
        int i;                  
        int year, month, day;   
                        
        for (i = 0; i < PD_DATE_LEN; i++)
                if (!isdigit(date[i]))
                        return PD_ERR;
                                
        year = (date[CC0] - '0') * 1000 +  (date[CC1] - '0') * 100 +
           (date[YY0] - '0') * 10 + (date[YY1] - '0');
                
        month = (date[MM1] - '0') + (date[MM0] - '0') * 10;
        if (month < 0 || month > 12)
                return PD_ERR;
                
        day = (date[DD1] - '0') + (date[DD0] - '0') * 10;
        if (month == 2 && isleap(year))
                        month = 13;     // Handle the special case of February in leap years
        if (day < 0 || day > vday[month])
                return PD_ERR;
        return PD_OK;
}

int addmonth(const char* csCurrentDate,int numofmonth,char* csNewDate)
{               
        int i_year, i_dd, i_mm;
        char buf[40];   
                
        if (check_valid_date(csCurrentDate) != PD_OK)
                return(PD_ERR);
                
        sprintf(buf,"%c%c%c%c", csCurrentDate[0], csCurrentDate[1], csCurrentDate[2], csCurrentDate[3]);
        i_year = atoi(buf);
        sprintf(buf, "%c%c", csCurrentDate[4], csCurrentDate[5]);
        i_mm = atoi(buf);
        sprintf(buf, "%c%c", csCurrentDate[6], csCurrentDate[7]);
                
        i_mm = i_mm + numofmonth;
        if (i_mm > 12 )
        {
                i_year = i_year + (int)(i_mm / 12);
                i_mm = i_mm % 12;
		
		if (i_mm == 0) {
			i_year--;
			i_mm = 12;
		}
        }


        if (isleap(i_year) && i_mm == 2)
                i_dd = vday[13];
        else
                i_dd = vday[i_mm];
                
        sprintf(csNewDate, "%04d%02d%02d", i_year, i_mm, i_dd);
        return(PD_OK);
}       

int addday(const char* csCurrentDate,int numofdate,char* csNewDate)
{               
        int i_year, i_dd, i_mm, i;
        char buf[40];   
                
        if (check_valid_date(csCurrentDate) != PD_OK)
                return(PD_ERR);
                
        sprintf(buf,"%c%c%c%c", csCurrentDate[0], csCurrentDate[1], csCurrentDate[2], csCurrentDate[3]);
        i_year = atoi(buf);
        sprintf(buf, "%c%c", csCurrentDate[4], csCurrentDate[5]);
        i_mm = atoi(buf);
        sprintf(buf, "%c%c", csCurrentDate[6], csCurrentDate[7]);
	i_dd = atoi(buf);

	i_dd = i_dd + numofdate;
        do
        {
                if(isleap(i_year) && i_mm==2)
                        i = 13;
                else
                        i = i_mm;

                if(i_dd <= vday[i])
                        break;

                i_dd = i_dd - vday[i];

                i_mm = i_mm + 1;
                if (i_mm > 12 )
                {
                        i_year = i_year + (int)(i_mm / 12);
                        i_mm = i_mm % 12;
                }


        }while(PD_TRUE);

        sprintf(csNewDate, "%04d%02d%02d", i_year, i_mm, i_dd);
        return(PD_OK);
}       

int day_of_week (const unsigned char* cs_date)
{
        static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
        int leap_adjuster, dow;
        int i_mm, i_dd, i_year;


        if (check_valid_date((const char*)cs_date) != PD_OK)
                return(PD_ERR);

        i_year = (cs_date[CC0] - '0') * 1000 +  (cs_date[CC1] - '0') * 100 + (cs_date[YY0] - '0') * 10 + (cs_date[YY1] - '0');
        i_mm = (cs_date[MM1] - '0') + (cs_date[MM0] - '0') * 10;
        i_dd = (cs_date[DD1] - '0') + (cs_date[DD0] - '0') * 10;
        i_year = i_year - (i_mm < 3);
        leap_adjuster = i_year/4 - i_year/100 + i_year/400;
        dow = (i_year + leap_adjuster + t[i_mm -1] + i_dd) % 7;
        return dow;
}
int daydiff(const char *ldate,const char *rdate)
{
        int lyear, ryear;
        int lmon, rmon;
        int lday, rday;
        double liday,riday; /* left date in days, right date in days */
        int i;
        
        /* first convert into number of days */
        lyear = (ldate[CC0] - '0') * 1000 +  (ldate[CC1] - '0') * 100 +
           (ldate[YY0] - '0') * 10 + (ldate[YY1] - '0');
        lmon = (ldate[MM1] - '0') + (ldate[MM0] - '0') * 10;
        lday = (ldate[DD1] - '0') + (ldate[DD0] - '0') * 10;
        
        ryear = (rdate[CC0] - '0') * 1000 +  (rdate[CC1] - '0') * 100 +
           (rdate[YY0] - '0') * 10 + (rdate[YY1] - '0');
        rmon = (rdate[MM1] - '0') + (rdate[MM0] - '0') * 10;
        rday = (rdate[DD1] - '0') + (rdate[DD0] - '0') * 10;
        
        /* find no. of days relative to 1900/01/01 */
        liday = 0; 
        for (i = 1900; i < lyear; i++) {
                if (isleap(i)) 
                        liday += 366;
                else    
                        liday += 365;
        }       
        for (i = 1; i < lmon; i++) {
                if (i == 2 && isleap(lyear))
                        liday += vday[13];
                else    
                        liday += vday[i];
        }       
        liday += lday;
        riday = 0;      
        for (i = 1900; i < ryear; i++) { 
                if (isleap(i))
                        riday += 366;
                else
                        riday += 365;
        }       
        for (i = 1; i < rmon; i++) { 
                if (i == 2 && isleap(ryear))
                        riday += vday[13];
                else            
                        riday += vday[i];
        }       
        riday += rday;
        return  (int) (riday > liday ? (riday - liday) : (liday - riday));
}                               
int monthenddate(const char *workdate,char* monthenddate)
{
        int i_year, i_dd, i_mm;
        char buf[40];

        if (check_valid_date(workdate) != PD_OK)
                return(PD_ERR);

        sprintf(buf,"%c%c%c%c", workdate[0], workdate[1], workdate[2], workdate[3]);
        i_year = atoi(buf);
        sprintf(buf, "%c%c", workdate[4], workdate[5]);
        i_mm = atoi(buf);

        if (isleap(i_year) && i_mm == 2)
                i_dd = vday[13];
        else
                i_dd = vday[i_mm];

        sprintf(monthenddate, "%04d%02d%02d", i_year, i_mm, i_dd);
        return(PD_OK);
}

char *getgmtdatetime(void)
{
        static  char sysdatetime[PD_DATETIME_LEN + 1];

        struct tm *ts;
        long ltime;

        time( &ltime );

        /* Obtain coordinated universal time: */
        ts = gmtime( &ltime );

        sprintf(sysdatetime,"%04d%02d%02d%02d%02d%02d",ts->tm_year + 1900,
                                                                   ts->tm_mon + 1,
                                                                   ts->tm_mday,
                                                                   ts->tm_hour,
                                                                   ts->tm_min,
                                                                   ts->tm_sec);
        return sysdatetime;

};


int day_of_year(const char *date)
{                       
        int i;
	int iDayOfYear=0;
        int year, month, day;   
                        
        for (i = 0; i < PD_DATE_LEN; i++)
                if (!isdigit(date[i]))
                        return PD_ERR;
                                
        year = (date[CC0] - '0') * 1000 +  (date[CC1] - '0') * 100 +
           (date[YY0] - '0') * 10 + (date[YY1] - '0');
                
        month = (date[MM1] - '0') + (date[MM0] - '0') * 10;
        if (month < 0 || month > 12)
                return PD_ERR;
                
        day = (date[DD1] - '0') + (date[DD0] - '0') * 10;
        if (month == 2 && isleap(year))
                        month = 13;     // Handle the special case of February in leap years
        if (day < 0 || day > vday[month])
                return PD_ERR;

	for(i = 1; i < month; i++){
		if(month > 1){
			if (i == 2 && isleap(year))
				iDayOfYear +=vday[13];
			else
				iDayOfYear +=vday[i];
		}
	}
	iDayOfYear +=day;

        return iDayOfYear;
}

char* get_RFC_2822_date(void)
{
	static char outstr[200];
        time_t t;
        struct tm *tmp;

        t = time(NULL);
        tmp = localtime(&t);
        if (tmp != NULL) {

        	if (strftime(outstr, sizeof(outstr), "%a, %d %b %Y %T %z", tmp) == 0) {
			fprintf(stderr, "strftime returned 0");
        	}
	}

	return outstr;
}
char* UTC2Local(const char* csDatetime,const char* TIMEZONE)
{
	static char outstr[PD_DATETIME_LEN +1];
	struct tm   i;
    	time_t      stamp;                              // Can be negative, so works before 1970

    	putenv("TZ=UTC");                               // Begin work in Greenwich É

    	char csTmp[PD_DATETIME_LEN +1];
    	memcpy(csTmp, &csDatetime[0], PD_YYYY_LEN);
    	csTmp[PD_YYYY_LEN] = '\0';
    	i.tm_year = atoi(csTmp) - 1900;

    	memcpy(csTmp, &csDatetime[PD_YYYY_LEN], PD_MM_LEN);
    	csTmp[PD_MM_LEN] = '\0';
    	i.tm_mon  = atoi(csTmp)-1;

    	memcpy(csTmp, &csDatetime[PD_YYYYMM_LEN], PD_DD_LEN);
    	csTmp[PD_DD_LEN] = '\0';
    	i.tm_mday = atoi(csTmp);

    	memcpy(csTmp, &csDatetime[PD_DATE_LEN], 2);
    	csTmp[2] = '\0';
    	i.tm_hour = atoi(csTmp);

    	memcpy(csTmp, &csDatetime[10], 2);
    	csTmp[2] = '\0';
    	i.tm_min  = atoi(csTmp);

	memcpy(csTmp, &csDatetime[12], 2);
    	csTmp[2] = '\0';
    	i.tm_sec  = atoi(csTmp);

    	stamp = mktime(&i);                             // Convert the struct to a Unix timestamp

    	putenv((char*)TIMEZONE);                               // Switch to destination time zone

	struct tm *tmp;
        tmp = localtime(&stamp);
	if (tmp != NULL) {
        	if (strftime(outstr, sizeof(outstr), "%Y%m%d%H%M%S", tmp) == 0) {
      			fprintf(stderr, "strftime returned 0");
        	}
	}

	return outstr;
}

int check_valid_datetime(const char *datetime)
{                       
        int i;                  
        int year, month, day, hour, mins, sec;

	if(strlen(datetime)!=PD_DATETIME_LEN)
		return PD_ERR;
               
        for (i = 0; i < PD_DATETIME_LEN; i++)
                if (!isdigit(datetime[i]))
                        return PD_ERR;
                                
        year = (datetime[CC0] - '0') * 1000 +  (datetime[CC1] - '0') * 100 +
           (datetime[YY0] - '0') * 10 + (datetime[YY1] - '0');
                
        month = (datetime[MM1] - '0') + (datetime[MM0] - '0') * 10;
        if (month < 0 || month > 12)
                return PD_ERR;
                
        day = (datetime[DD1] - '0') + (datetime[DD0] - '0') * 10;
        if (month == 2 && isleap(year))
                        month = 13;     // Handle the special case of February in leap years
        if (day < 0 || day > vday[month])
                return PD_ERR;


	hour = (datetime[HH1] - '0') + (datetime[HH0] - '0') * 10;
	if(hour<0 || hour > 23)
		return PD_ERR;

	mins = (datetime[MI1] - '0') + (datetime[MI0] - '0') * 10;
	if(mins<0 || mins > 59)
		return PD_ERR;

	sec = (datetime[SS1] - '0') + (datetime[SS0] - '0') * 10;
	if(sec<0 || sec > 59)
		return PD_ERR;

        return PD_OK;
}

char* write_tpl_timestamp()
{
	static char cTimestamp[20];

	time_t  ct;
	struct  tm *sct;
	ct = time(NULL);
	sct = localtime(&ct);

	sprintf(cTimestamp,"%02d-%02d-%04d %02d:%02d:%02d", sct->tm_mday, sct->tm_mon + 1, sct->tm_year + 1900, sct->tm_hour, sct->tm_min, sct->tm_sec);

	return cTimestamp;
}
