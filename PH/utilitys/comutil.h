#ifndef	_COMUTIL_H_
#define	_COMUTIL_H_


#ifdef __cplusplus
extern "C" { 
#endif  
short is_numeric(char* str);
short is_ascii(char* str,int i_len);
short is_alnum(char* str);

short ascii_range(char* str, int i_len, int iLower, int iUpper);
#ifdef __cplusplus
}       
#endif  
#endif

