#ifndef	_MYTYPES_H_
#define	_MYTYPES_H_

typedef struct my_bytes_t {
  size_t len;   /**< length of the buffer in bytes */
  void *bytes;  /**< pointer to the beginning of the buffer */
} my_bytes_t;

#define MYBYTES_INIT(X)    X.len = 0; \
                        X.bytes = (char*) malloc (X.len +1); \
                        memset(X.bytes,0,X.len); 
#ifdef __cplusplus
extern "C" { 
#endif  

void my_bytes_cat(char *srcString, my_bytes_t *dst);
void my_bytes_append(my_bytes_t *src,my_bytes_t *dst);
void my_bytes_dup(my_bytes_t src, my_bytes_t dst);
my_bytes_t *my_bytes_malloc_dup(my_bytes_t *src);
void my_bytes_msg_dup(my_bytes_t src, int iHeaderLen,my_bytes_t *dst);
my_bytes_t my_cstring_bytes(char const *cstr);
my_bytes_t* MyBytes_init();

#ifdef __cplusplus
}       
#endif  
#endif

