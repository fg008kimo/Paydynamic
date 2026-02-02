#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
#include <ctype.h>
//#include <sys/types.h>
#include "common.h"

short is_numeric(char* str)
{
        int i_len = strlen(str);
        int i;

        for (i = 0; i < i_len; i++)
                if (!isdigit(str[i]))
                        return PD_FALSE;
        return PD_TRUE;
}

short is_ascii(char* str, int i_len)
{
        int i;

        for (i = 0; i < i_len; i++)
                if (!isascii(str[i]))
                        return PD_FALSE;
        return PD_TRUE;
}
short is_alnum(char* str)
{
        int i_len = strlen(str);
        int i;

        for (i = 0; i < i_len; i++)
                if (!isalnum(str[i]))
                        return PD_FALSE;
        return PD_TRUE;
}


short ascii_range(char* str, int i_len, int iLower, int iUpper)
{
        int i;

        for (i = 0; i < i_len; i++){
                if (!isascii(str[i])){
			return PD_FALSE;
		}
		else{
			if((str[i] < iLower) ||
			   (str[i] > iUpper)){
				return PD_FALSE;
			}
		}
	}
        return PD_TRUE;
}
