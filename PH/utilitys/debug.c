#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <time.h>
#include <sys/time.h>
#include "debug.h"
#include "zlog.h"
#include "freeme.h"

char _debug_filename[256];
int  _debug_line_no;

void TXNLOG(const char *fmt, ...)
{
	char*   csMyConfig;
        int rc;
        zlog_category_t *c;

        csMyConfig = (char*) malloc (128+1);
        sprintf(csMyConfig,"%s",getenv("LOGCONF"));
        rc = zlog_init(csMyConfig);
        free(csMyConfig);
        csMyConfig = NULL;
        if (rc) {
                printf("init [%s]failed\n",csMyConfig);
        }

        c = zlog_get_category("my_info");
        if (!c) {
                printf("get cat fail\n");
                zlog_fini();
        }

        va_list ap;
        va_start(ap, fmt);
        vzlog_info(c,fmt,ap);
        zlog_fini();
        va_end(ap);
}

void ERRLOG(const char *fmt, ...)
{
	char*   csMyConfig;
        int rc;
        zlog_category_t *c;

        csMyConfig = (char*) malloc (128+1);
        sprintf(csMyConfig,"%s",getenv("LOGCONF"));
        rc = zlog_init(csMyConfig);
        free(csMyConfig);
        csMyConfig = NULL;
        if (rc) {
                printf("init [%s]failed\n",csMyConfig);
        }

        c = zlog_get_category("my_error");
        if (!c) {
                printf("get cat fail\n");
                zlog_fini();
        }

        va_list ap;
        va_start(ap, fmt);
        vzlog_info(c,fmt,ap);
        zlog_fini();

}

void errlog(const char *fmt, ...)
{
        FILE    *fp;
        va_list ap;
        char    cs_filename[256];
        struct tm *ts;
        //time_t clock;
      	struct timeval tv; 
	struct timezone tz;

        va_start(ap, fmt);
        //clock = time((time_t *) NULL);
        //ts = localtime(&clock);
        gettimeofday(&tv,&tz);
        ts = localtime(&tv.tv_sec);
        sprintf(cs_filename, "%s/%s.%04d%02d%02d.%ld.log", getenv("LOGPATH"), _debug_filename,ts->tm_year + 1900, ts->tm_mon + 1, ts->tm_mday, (long)getpid());
        fp = fopen(cs_filename, "a");
        if (fp != NULL)  {
                fprintf(fp, "%02d:%02d:%02d:%06ld <line %d>",
                                ts->tm_hour, ts->tm_min, ts->tm_sec,tv.tv_usec,_debug_line_no);
                vfprintf(fp, fmt, ap);
                fclose(fp);
        }
        va_end(ap);
}

void acklog(const char *fmt, ...)
{
        FILE    *fp;
        va_list ap;
        char    cs_filename[256];
        struct tm *ts;
        time_t clock;

        va_start(ap, fmt);

        clock = time((time_t *) NULL);
        ts = localtime(&clock);
        sprintf(cs_filename, "%s%04d%02d%02d.%ld.log", getenv("ACKLOG"),ts->tm_year + 1900, ts->tm_mon + 1 ,ts->tm_mday,(long)getpid());
        fp = fopen(cs_filename, "a");
        if (fp != NULL)  {
                //fprintf(fp, ":%02d:%02d:%02d ", ts->tm_hour, ts->tm_min, ts->tm_sec);
                vfprintf(fp, fmt, ap);
                fclose(fp);
        }
        va_end(ap);
}
