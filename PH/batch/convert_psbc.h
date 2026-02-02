#ifndef _CONVERT_PSBC_H
#define _CONVERT_PSBC_H

#ifdef __cplusplus
extern "C" {
#endif

int SplitLineByhFormat(const char *csLine, const char *csFormatId, const hash_t *hFormat, hash_t *hRls);
int CheckDetail(const hash_t *hContext, hash_t *hRls, char *cs_err_msg_buf);
int determineSignByKeyword(const hash_t *hContext, hash_t *hRls);
int MultiKeywordsSearch(const char *csLine, char *csTemplate, int iFullMatch);

#ifdef __cplusplus
}
#endif


#endif
