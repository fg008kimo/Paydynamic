#ifndef _SEC_H_
#define _SEC_H_
#ifdef __cplusplus
extern "C" {
#endif
int unscramble(const char* message,short message_len,char* outmessage);
int scramble(const char* csMsg,short csMsg_len,char* outMsg);
#ifdef __cplusplus
}
#endif
#endif
