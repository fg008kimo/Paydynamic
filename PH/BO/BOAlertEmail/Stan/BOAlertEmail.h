#ifndef _BOALERTEMAIL_H_
#define _BOALERTEMAIL_H_

#ifdef __cplusplus
extern "C" {
#endif

int FunctExclude(hash_t *hRls);

int PrepareTemplate(hash_t *hRls, tpl_t *tpl);

int SendTemplate(hash_t *hRls, tpl_t *tpl);

int SendEmail(hash_t *hRls, char *content);

char* GetTimeNowInFormat(char *csTemplate);

char* escapeshellarg(char* str) {
	char *escStr;
	int i, count = strlen(str), ptr_size = count+3;

	escStr = (char *) calloc(ptr_size, sizeof(char));
	if (escStr == NULL) {
		return NULL;
	}
	sprintf(escStr, "'");

	for(i=0; i<count; i++) {
		if (str[i] == '\'') {
			ptr_size += 3;
			escStr = (char *) realloc(escStr, ptr_size * sizeof(char));
			if (escStr == NULL) {
				return NULL;
			}
			sprintf(escStr, "%s'\\''", escStr);
		} else {
			sprintf(escStr, "%s%c", escStr, str[i]);
		}
	}

	sprintf(escStr, "%s%c", escStr, '\'');
	return escStr;
}

#ifdef __cplusplus
}
#endif

#endif
