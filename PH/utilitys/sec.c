#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "debug.h"
#define SC_MAP_DATA_LEN			90
#define BUFFER_SIZE			1024

#define CHR2VAL "~`)Ti(nqAy!7P&^gd>/;XZ*8NRHEv6$S-Gt9Co3 K#r1j4k<L%OQh2JUBwx0?fe:=W,Iz\"sl5mpDFMV.'+@aYb\\c_u"
#define VAL2CHR "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz !\"#$%&'()*+,-./:;<=>?@\\^_`~"

int unscramble(const char* message,short message_len,char* outmessage)
{   
    char *csChr2Val = strdup(CHR2VAL);
    char *csVal2Chr = strdup(VAL2CHR);
    unsigned char *csMsg;

    int i_val, i_accum,i;
    char cs_chr2val[SC_MAP_DATA_LEN + 1], cs_val2chr[SC_MAP_DATA_LEN + 1];

    csMsg = (unsigned char*) malloc(BUFFER_SIZE);
    i_accum = 0;

    strcpy(cs_chr2val, csChr2Val);
    strcpy(cs_val2chr, csVal2Chr);


    for (i = 0; i < message_len; i++) {
        for (i_val = 0; i_val < SC_MAP_DATA_LEN; i_val++)
            if (message[i] == cs_val2chr[i_val])
                break;
        i_val = i_val - i_accum;
        if (i_val < 0)
            i_val = (i_val + SC_MAP_DATA_LEN) % SC_MAP_DATA_LEN;
        i_accum += i_val;
        i_accum = i_accum % SC_MAP_DATA_LEN;
        csMsg[i] = cs_chr2val[i_val];
    }
//    printf("%.*s\n",message_len,csMsg);
        strcpy(outmessage,(const char*) csMsg);

    free(csMsg);
    free(csChr2Val);
    free(csVal2Chr);

    return PD_OK;
}

int scramble(const char* csMsg,short csMsg_len,char* outMsg)
{
    char *csChr2Val = strdup(CHR2VAL);
    char *csVal2Chr = strdup(VAL2CHR);
    unsigned char *message;

    int i_val, i_accum, i, i_val_blank, i_res;
    int i_len;
    char cs_chr2val[SC_MAP_DATA_LEN + 1], cs_val2chr[SC_MAP_DATA_LEN + 1];
    message = (unsigned char*) malloc (BUFFER_SIZE);

    strcpy(cs_chr2val, csChr2Val);
    strcpy(cs_val2chr, csVal2Chr);
    if (csMsg_len <= 0) {
        return PD_ERR;
    }

    for (i_val_blank = 0; i_val_blank < SC_MAP_DATA_LEN; i_val_blank++) {
        if (cs_chr2val[i_val_blank] == ' ')
            break;
    }

    i_accum = 0;
    i_len = csMsg_len;
    for (i = 0; i < i_len; i++) {
        for (i_val = 0; i_val < SC_MAP_DATA_LEN; i_val++)
            if (csMsg[i] == cs_chr2val[i_val])
                break;
        if (i_val >= SC_MAP_DATA_LEN)
            i_val = i_val_blank;
        i_accum += i_val;
        i_res = i_accum % SC_MAP_DATA_LEN;
        message[i] = cs_val2chr[i_res];
    }
//  printf("%.*s\n",csMsg_len,message);
    strcpy(outMsg,(const char*)message);

    free(message);
    free(csChr2Val);
    free(csVal2Chr);
    return PD_OK;
}
