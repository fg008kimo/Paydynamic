#ifndef _B64_H_
#define _B64_H_


#ifdef __cplusplus
extern "C" {
#endif

int base64_encode(unsigned char *source, size_t sourcelen, char *target, size_t targetlen);
size_t base64_decode(char *source, unsigned char *target, size_t targetlen);

#ifdef __cplusplus
}
#endif
#endif 
