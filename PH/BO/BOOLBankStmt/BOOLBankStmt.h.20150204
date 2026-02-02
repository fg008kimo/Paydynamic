#ifndef _BOOLBANKSTMT_H_
#define _BOOLBANKSTMT_H_
#include "myrecordset.h"
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int ConvertStmtFile(hash_t *hContext, hash_t *hRequest);

int ProcessStmtFile(hash_t *hContext, hash_t *hRequest, recordset_t *rRecordFormat, recordset_t *myFile);
int ProcessStmtTmp(hash_t *hContext, hash_t *hRequest, recordset_t *rRecordFormat, recordset_t *myFile);

int ProcessStmtDetail(hash_t *hContext, hash_t *hRequest, recordset_t *myFile);

int AddStmtTmp(hash_t *hContext, hash_t *hRequest, recordset_t *myFile);
int UpdateStmtTmp(hash_t *hContext, hash_t *hRequest, recordset_t *myFile);

struct node {
	hash_t *hDtl;
	struct node *next;
};

struct node *list_switch(struct node *l1, struct node *l2)
{
	l1->next = l2->next;
	l2->next = l1;

	return l2;
}

int strlen_utf8(char *s) 
{
	int j = 0;
	while (*s) {
		if ((*s & 0xc0) != 0x80) j++;
		s++;
	}
	return j;
}

int strlen_content(char *s) 
{
	int j = 0;
	while (*s) {
		if ((*s & 0xc0) == 0x00 || (*s & 0xc0) == 0x40) {
			if ((*s >= '0' && *s <= '9') ||
			    (*s >= 'A' && *s <= 'Z') ||
			    (*s >= 'a' && *s <= 'z')) {
				j++;
			}
		} else if ((*s & 0xc0) == 0xc0) {
			j++;
		}
		s++;
	}
	return j;
}

int decimal_places(const char *s)
{
	int j = 0;
	int z = 0, go = 0;
	while (*s) {
		if (*s >= '0' && *s <= '9' && go == 1) {
			if (*s == '0') {
				z++;
			} else {
				j += z + 1;
				z = 0;
			}
		} else if (*s == '.' && go == 0) {
			go = 1;
		} else {
			return j;
		}
		s++;
	}
	return j;
}

char *mystrtok_r(char *string, const char *seps, char **context)
{
	char *head; /* Start of word */
	char *tail; /* End of word */

	/* If we're starting up, initialize context */
	if (string) {
		*context = string;
	}

	/* Get potential start of this next word */
	head = *context;
	if (head == NULL) {
		return NULL;
	}

	/* Skip any leading separators
	while (*head && strchr(seps, *head)) {
		head++;
	}*/

	/* Did we hit the end? */
	if (*head == 0) {
		/* Nothing left */
		*context = NULL;
		return NULL;
	}

	/* Skip over word */
	tail = head;
	while (*tail && !strchr(seps, *tail)) {
		tail++;
	}

	/* Save head for next time in context */
	if (*tail == 0) {
		*context = NULL;
	} else {
		*tail = 0;
		tail++;
		*context = tail;
	}

	/* Return current word */
	return head;
}

char *_deleteCharacters(char *str, char *charSet)
{
	int hash [256];
	int i;
	if(NULL == charSet)
		return str;

	for(i = 0; i < 256; i++) {
		hash[i] = 0;
	}

	for(i = 0; i < strlen(charSet); i++)
		hash[(unsigned char)charSet[i]] = 1;

	int currentIndex = 0;
	for(i = 0; i < strlen(str); i++)
	{
		if(!hash[(unsigned char)str[i]])
		str[currentIndex++] = str[i];
	}
	str[currentIndex] = '\0';
	return str;
}

void _RecordSet_Destroy(recordset_t *r) {
	hash_t *h = RecordSet_GetFirst(r);
	while(h != NULL) {
		hash_destroy(h);
		FREE_ME(h);
		h = RecordSet_GetNext(r);
	}
	recordset_destroy(r);
}

#ifdef __cplusplus
}
#endif

#endif
