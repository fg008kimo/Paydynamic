#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>
#include <time.h>
#include "logmsg.h"
#include "zlog.h"

void logmsg(char *fmt, ...)
{
        FILE    *fp;
        va_list al;

        va_start(al, fmt);

        fp = fopen(getenv("TXNLOG"), "a");
        if (fp != NULL) {
                vfprintf(fp, fmt, al);
                fclose(fp);
        }
        va_end(al);
}

void dumphex(unsigned char *hexdata, long len)
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
                printf("init failed\n");
        }

        c = zlog_get_category("my_hex");
        if (!c) {
                printf("get cat fail\n");
                zlog_fini();
        }

        hzlog_info(c,hexdata,len);
        zlog_fini();
}

/*
void dumphex(unsigned char *hexdata, long len)
{
        long    i;
        long    j;
        long    k;

        for (i = 0; i < len; i++) {
                if (i != 0 && i % 16 == 0) {
                        logmsg("|");
                        for (j = (i-16); j < i; j++) {
                                if (isprint(hexdata[j]))
                                        logmsg("%c", hexdata[j]);
                                else
                                        logmsg(".");
                        }
                        logmsg("|\n");
                }
                logmsg("%02x ", hexdata[i]);
        }

        k = len % 16;
        if (k != 0) {
                k = 16 - k;
                for (;k > 0; k--)
                        logmsg("   ");
        }

        k = len % 16;
        if (k != 0)
                k = len - k;
        else
                k = len - 16;
        logmsg("|");
	for (j = k; j < len; j++) {
                if (isprint(hexdata[j]))
                        logmsg("%c", hexdata[j]);
                else
                        logmsg(".");
        }

        k = len % 16;
        if (k != 0)
                k = 16 - k;
        for (; k > 0; k--)
                logmsg(" ");
        logmsg("|\n");
}
*/
