#ifndef _GATEWAY_H_
#define _GATEWAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*#include "OiaMsg.h"*/
#include "common.h"
#include "utilitys.h"
#include "internal.h"
#include <zlib.h>
#include "ObjPtr.h"
#include <json-c/json.h>

	


#ifdef __cplusplus
extern "C" {
#endif

int ParseJ(struct json_object * jobj, hash_t* hOut);
int ParseJArray(struct json_object * jobj, hash_t* hOut,const char* ObjName);
void json_parse(json_object * jobj, const char* ObjName);
//int ParseJ2Get(struct json_object * jobj, my_bytes_t *outBytes);

#ifdef __cplusplus
}
#endif

#endif
