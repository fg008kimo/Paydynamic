#ifndef _OL_DEF_SUB_PROVIDER_
#define _OL_DEF_SUB_PROVIDER_

#ifdef __cplusplus
extern "C" {
#endif

int GetSubProviderName(const unsigned char* csSubProviderId, hash_t *hRec);
int GetSubProviderId(const unsigned char* csSubProviderName, hash_t *hRec);

#ifdef __cplusplus
}
#endif

#endif
